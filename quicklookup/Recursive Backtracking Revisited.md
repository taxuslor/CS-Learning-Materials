# CS106B: Recursive Backtracking Revisited

## BFS vs. DFS comparison

- BFS is typically iterative while DFS is naturally expressed recursively. 
- BFS looks at all paths of a particular length before moving on to longer paths, so it’s guaranteed to find the shortest path (e.g. word ladder)! 
- DFS doesn’t need to store all partial paths along the way, so it has a smaller memory footprint than BFS does.

## Example

````C++
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 定义迷宫的大小
const int ROWS = 5;
const int COLS = 5;

// 定义迷宫中的单元格状态
enum CellState {
    WALL,
    EMPTY,
    START,
    GOAL,
    PATH
};

// 定义坐标结构体
struct Coordinate {
    int x, y;
    
    Coordinate(int _x, int _y) : x(_x), y(_y) {}
};

// 使用BFS方法解决迷宫问题
bool solveMazeBFS(vector<vector<CellState>>& maze, Coordinate start, Coordinate goal) {
    // 设置方向矢量：上、下、左、右
    vector<Coordinate> directions {
        Coordinate(-1, 0), // 上
        Coordinate(1, 0),  // 下
        Coordinate(0, -1), // 左
        Coordinate(0, 1)   // 右
    };
    
    // 创建一个队列来保存待访问的单元格
    queue<Coordinate> q;
    
    // 将起始单元格加入队列
    q.push(start);
    
    while (!q.empty()) {
        // 获取队列中的下一个单元格
        Coordinate curr = q.front();
        q.pop();
        
        // 如果当前单元格是目标单元格，说明已找到路径，结束搜索
        if (curr.x == goal.x && curr.y == goal.y) {
            return true;
        }
        
        // 标记当前单元格为已访问
        maze[curr.x][curr.y] = PATH;
        
        // 遍历四个方向
        for (const auto& dir : directions) {
            int nextX = curr.x + dir.x;
            int nextY = curr.y + dir.y;
            
            // 如果下一个单元格在迷宫范围内且为空，则加入队列
            if (nextX >= 0 && nextX < ROWS && nextY >= 0 && nextY < COLS 
                && maze[nextX][nextY] == EMPTY) {
                q.push(Coordinate(nextX, nextY));
            }
        }
    }
    
    // 搜索完整个迷宫后仍未找到路径，返回false
    return false;
}

// 使用DFS方法解决迷宫问题
bool solveMazeDFS(vector<vector<CellState>>& maze, Coordinate curr, Coordinate goal) {
    // 判断当前单元格是否是目标单元格，如果是则返回true
    if (curr.x == goal.x && curr.y == goal.y) {
        return true;
    }
    
    // 设置方向矢量：上、下、左、右
    vector<Coordinate> directions {
        Coordinate(-1, 0), // 上
        Coordinate(1, 0),  // 下
        Coordinate(0, -1), // 左
        Coordinate(0, 1)   // 右
    };
    
    // 标记当前单元格为已访问
    maze[curr.x][curr.y] = PATH;
    
    // 遍历所有方向
    for (const auto& dir : directions) {
        int nextX = curr.x + dir.x;
        int nextY = curr.y + dir.y;
        
        // 如果下一个单元格在迷宫范围内且为空，则递归调用DFS方法
        if (nextX >= 0 && nextX < ROWS && nextY >= 0 && nextY < COLS 
            && maze[nextX][nextY] == EMPTY) {
            if (solveMazeDFS(maze, Coordinate(nextX, nextY), goal)) {
                return true;
            }
        }
    }
    
    // 所有方向都尝试过后仍未找到路径，将当前单元格重置为未访问状态
    maze[curr.x][curr.y] = EMPTY;
    
    // 搜索完整个迷宫后仍未找到路径，返回false
    return false;
}

// 打印迷宫的函数
void printMaze(vector<vector<CellState>>& maze) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            switch (maze[i][j]) {
                case WALL:
                    cout << "#";
                    break;
                case EMPTY:
                    cout << ".";
                    break;
                case START:
                    cout << "S";
                    break;
                case GOAL:
                    cout << "G";
                    break;
                case PATH:
                    cout << "*";
                    break;
            }
        }
        cout << endl;
    }
}

int main() {
    // 创建迷宫并初始化
    vector<vector<CellState>> maze(ROWS, vector<CellState>(COLS, EMPTY));
    
    // 设置起始和目标位置
    Coordinate start(0, 0);
    Coordinate goal(ROWS - 1, COLS - 1);
    
    // 设置迷宫的墙壁
    maze[3][1] = WALL;
    maze[3][2] = WALL;
    maze[3][3] = WALL;
    
    // 输出初始迷宫
    cout << "迷宫：" << endl;
    printMaze(maze);
    cout << endl;
    
    // 使用BFS方法解决迷宫问题
    if (solveMazeBFS(maze, start, goal)) {
        cout << "使用BFS方法找到路径。" << endl;
    } else {
        cout << "未找到路径。" << endl;
    }
    
    // 输出BFS解决后的迷宫
    cout << "BFS解决后的迷宫：" << endl;
    printMaze(maze);
    cout << endl;
    
    // 重新初始化迷宫
    maze = vector<vector<CellState>>(ROWS, vector<CellState>(COLS, EMPTY));
    maze[3][1] = WALL;
    maze[3][2] = WALL;
    maze[3][3] = WALL;
    
    // 使用DFS方法解决迷宫问题
    if (solveMazeDFS(maze, start, goal)) {
        cout << "使用DFS方法找到路径。" << endl;
    } else {
        cout << "未找到路径。" << endl;
    }
    
    // 输出DFS解决后的迷宫
    cout << "DFS解决后的迷宫：" << endl;
    printMaze(maze);
    
    return 0;
}

````

