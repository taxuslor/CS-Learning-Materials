/* CS106B Assign2: Fun with collections
 * Part1: Maze
 *
 * This project focuses on a particular type of maze known as a perfect maze.
 * A perfect, or simply-connected, maze has no loops and no inaccessible areas.
 * Any two locations within a perfect maze are connected by exactly one path.
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <set>
#include <queue>

using namespace std;

// Step1: Using Grids to Represent Mazes
vector<vector<bool>> readMazeFile(const string &filepath) {
    fstream file(filepath);
    vector<vector<bool>> maze = {};
    if (file.is_open()) {
        string line;
        int row = 0;
        while (getline(file, line)) {
            maze.push_back({});
            for (char ch: line) {
                if (ch == '-') {
                    maze[row].push_back(false);
                } else if (ch == '@') {
                    maze[row].push_back(true);
                }
            }
            row++;
        }
    } else {
        cout << "Fail to open the file." << endl;
    }
    return maze;
}

void testReadMaze() {
    vector<vector<bool>> maze = readMazeFile("../testmaze");
    for (int i = 0; i < maze.size(); ++i) {
        for (int j = 0; j < maze[i].size(); ++j) {
            if (maze[i][j]) {
                cout << "█";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

// Step2: Using Stacks and GridLocation to Represent Maze Solutions
struct GridLocation {
    int row;
    int column;
};

// The set container requires that its element types support comparison operations for sorting and uniqueness.
bool operator<(const GridLocation &a, const GridLocation &b) {
    if (a.row < b.row) {
        return true;
    } else if (a.row == b.row) {
        return a.column < b.column;
    } else {
        return false;
    }
}

stack<GridLocation> readSolutionFile(const string &filepath) {
    fstream file(filepath);
    stack<GridLocation> solution;
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            GridLocation temp = {0, 0};
            for (int i = 0; i < line.size(); ++i) {
                if (line.at(i) == 'r') {
                    temp.row = static_cast<int>(line.at(i + 1)) - 48;
                } else if (line.at(i) == 'c') {
                    temp.column = static_cast<int> (line.at(i + 1)) - 48;
                }
            }
            solution.push(temp);
        }
    } else {
        cout << "Fail to open the file." << endl;
    }
    return solution;
}

// Step3: Warmup: Write a generateValidMoves() helper
/* Valid moves are defined as follows:
 * Either directly north, south, east, or west (N, S, E, W) of cur
 * Only one "step" away from cur in the grid
 * Not a wall
 * Not out-of-bounds of the provided maze
 */
set<GridLocation> generateValidMoves(vector<vector<bool>> &maze, GridLocation cur) {
    set<GridLocation> canGo;
    GridLocation temp = cur;
    if (temp.row + 1 < maze.size() && !maze[temp.row + 1].at(temp.column)) {
        canGo.insert({temp.row + 1, temp.column});
    }
    if (temp.row - 1 >= 0 && !maze[temp.row - 1].at(temp.column)) {
        canGo.insert({temp.row - 1, temp.column});
    }
    if (temp.column + 1 < maze[temp.row].size() && !maze[temp.row].at(temp.column + 1)) {
        canGo.insert({temp.row, temp.column + 1});
    }
    if (temp.column - 1 >= 0 && !maze[temp.row].at(temp.column - 1)) {
        canGo.insert({temp.row, temp.column - 1});
    }
    return canGo;
}

// Step4: Verify paths with checkSolution()
/* A path represents a valid solution through the maze if it meets the following criteria:
 * The path must start at the entry (upper left corner) of the maze.
 * The path must end at the exit (lower right corner) of the maze.
 * Each location in the path is within the maze bounds.
 * Each location in the path is an open corridor (not wall).
 * Each location is one cardinal step (N,S,E,W) from the next in path.
 * The path contains no loops, i.e. a location appears at most once in the path.
 */
void printSolution(stack<GridLocation> path) {
    vector<GridLocation> vec;
    int size = path.size();
    for (int i = 0; i < size; ++i) {
        vec.push_back(path.top());
        path.pop();
    }
    for (int i = size - 1; i >= 0; --i) {
        cout << "r" << vec[i].row << "c" << vec[i].column;
        if (i != 0) {
            cout << " -> ";
        }
    }
    cout << endl;
}

void checkSolution(vector<vector<bool>> &maze, stack<GridLocation> path) {
    printSolution(path);
    bool arrive[maze.size()][maze[0].size()];
    for (int i = 0; i < maze.size(); i++) {
        for (int j = 0; j < maze[0].size(); j++) {
            arrive[i][j] = false;
        }
    }
    // check the end location
    if (path.top().row != maze.size() - 1 || path.top().column != maze[0].size() - 1) {
        cout << "Invalid Solution." << endl;
        return;
    }
    for (int i = 0; i < path.size(); ++i) {
        GridLocation pre = path.top();
        path.pop();
        GridLocation cur = path.top();
        // check no loops
        arrive[pre.row][pre.column] = true;
        if (arrive[cur.row][cur.column]) {
            cout << "Invalid Solution." << endl;
            return;
        }
        // check one step long
        if (abs(pre.row - cur.row) + abs(pre.column - cur.column) != 1) {
            cout << "Invalid Solution." << endl;
            return;
        }
        // check within bounds
        if (pre.row >= maze.size() || pre.row < 0 || pre.column >= maze[0].size() || pre.column < 0) {
            cout << "Invalid Solution." << endl;
            return;
        }
        // check not wall
        if (maze[pre.row].at(pre.column)) {
            cout << "Invalid Solution." << endl;
            return;
        }
        // check the start location
        if (i == path.size() - 1) {
            if (path.top().row != 0 || path.top().column != 0) {
                cout << "Invalid Solution." << endl;
                return;
            }
        }
    }
    cout << "Valid Solution." << endl;
}

// Step5: Find solutions with solveMaze()
/* Breadth-first search (BFS) is a classic and elegant algorithm for finding a shortest path.
 * A breadth-first search reaches outward from the entry location in a radial fashion until it finds the exit.
 * The first paths examined take one hop from the entry.
 * If any of these reach the exit location, you’re done.
 * If not, the search expands to those paths that are two hops long.
 * At each subsequent step, the search expands radially,
 * examining all paths of length three, then of length four, etc.),
 * stopping at the first path that reaches the exit.
 */
stack<GridLocation> solveMaze(vector<vector<bool>> &maze) {
    stack<GridLocation> path;
    set<GridLocation> arrived = {};
    set<GridLocation> validMoves;
    queue<stack<GridLocation>> possiblePaths;
    GridLocation begin = {0, 0};
    path.push(begin);
    possiblePaths.push(path);
    while (!possiblePaths.empty()) {
        int size = possiblePaths.size();
        for (int i = 0; i < size; ++i) {
            stack<GridLocation> curPath = possiblePaths.front();
            stack<GridLocation> prePath = curPath;
            for (int j = 0; j < prePath.size() - 1; ++j) {
                arrived.insert(prePath.top());
                prePath.pop();
            }
            possiblePaths.pop();
            validMoves = generateValidMoves(maze, curPath.top());
            for (GridLocation move: validMoves) {
                if (arrived.find(move) == arrived.end()) {
                    stack<GridLocation> newPath = curPath;
                    newPath.push(move);
                    possiblePaths.push(newPath);
                    if (move.row == maze.size() - 1 && move.column == maze[0].size() - 1) {
                        return newPath;
                    }
                }
            }
            arrived = {};
        }
    }
    cout << "Maze can't be solved." << endl;
    return {};
}

int main() {
    testReadMaze();
    vector<vector<bool>> maze = readMazeFile("../testmaze");
    stack<GridLocation> path = solveMaze(maze);
    if (!path.empty()) {
        checkSolution(maze, path);
    }
    return 0;
}
