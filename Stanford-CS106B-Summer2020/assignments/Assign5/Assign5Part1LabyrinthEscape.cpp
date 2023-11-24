/* CS106B Assign5: Linked Lists
 * Part1: Labyrinth Escape
 */

#include <iostream>
#include <set>

using namespace std;

/* Each MazeCell has a field named contents that indicates the item at that location.
 * If the cell contains no item, then its contents field will hold the empty string.
 * A cell that holds the Spellbook, Potion, or Wand item would
 * contain the string "Spellbook","Potion", or "Wand", respectively.
 */
struct MazeCell {
    string contents;   /* Value is either "", "Spellbook", "Potion", or "Wand" */
    MazeCell *north;   /* The cell to the north, or nullptr if no cell to the north. */
    MazeCell *south;   /* The cell to the north, or nullptr if no cell to the south. */
    MazeCell *east;    /* The cell to the north, or nullptr if no cell to the east. */
    MazeCell *west;    /* The cell to the north, or nullptr if no cell to the west. */
};

MazeCell maze[4][4] = {{{"",        nullptr,     &maze[1][0], nullptr,     nullptr},
                               {"", nullptr,     &maze[1][1], &maze[0][2], nullptr},
                               {"Potion", nullptr,     nullptr,     nullptr,     &maze[0][1]},
                               {"",   nullptr,     &maze[1][3], nullptr, nullptr}},
                       {{"",        &maze[0][0], nullptr,     &maze[1][1], nullptr},
                               {"", &maze[0][1], &maze[2][1], nullptr,     &maze[1][0]},
                               {"",     nullptr,     &maze[2][2], nullptr,     nullptr},
                               {"",   &maze[0][3], &maze[2][3], nullptr, nullptr}},
                       {{"Spellbook", nullptr,     &maze[3][0], nullptr,     nullptr},
                               {"", &maze[1][1], nullptr,     &maze[2][2], nullptr},
                               {"",     &maze[1][2], &maze[3][2], &maze[2][3], &maze[2][1]},
                               {"",   &maze[1][3], &maze[3][3], nullptr, &maze[2][2]}},
                       {{"",        &maze[2][0], nullptr,     &maze[3][1], nullptr},
                               {"", nullptr,     nullptr,     &maze[3][2], &maze[3][0]},
                               {"",     &maze[2][2], nullptr,     nullptr,     &maze[3][1]},
                               {"Wand", &maze[2][3], nullptr,     nullptr, nullptr}},

};

/* This function takes as input a pointer to a MazeCell representing the entry point into the labyrinth,
 * a string made purely from the characters 'N', 'S', 'E', and 'W' representing a path through the maze,
 * and a Set of necessary items to collect, expressed as strings.
 * If the path traces a valid sequence of steps through the labyrinth that gathers all of the necessary items,
 * the function returns true. Otherwise, the function should return false.
 * A path is considered to successfuly escape the labyrinth if:
 * The path is legal. Each step is a valid direction to travel from the current cell.
 * Each item of the necessary items set is picked up by visiting a cell that contains that item.
 * The order in which items are picked up is irrelevant. After picking up all items, any remaining steps in the path are ignored.
 */
bool isPathToFreedom(MazeCell *start, string path, set<string> needed) {
    set<string> get;
    for (char i: path) {
        if (!start->contents.empty()) {
            cout << "Found One " << start->contents << "." << endl;
            get.insert(start->contents);
        }
        switch (i) {
            case 'N':
                if (start->north) {
                    start = start->north;
                }
                break;
            case 'S':
                if (start->south) {
                    start = start->south;
                }
                break;
            case 'E':
                if (start->east) {
                    start = start->east;
                }
                break;
            case 'W':
                if (start->west) {
                    start = start->west;
                }
                break;
            default:
                cout << "Found invalid character" << endl;
                return false;
        }
    }
    if (!start->contents.empty()) {
        cout << "Found One " << start->contents << "." << endl;
        get.insert(start->contents);
    }
    if (get == needed) {
        return true;
    } else {
        return false;
    }
}

void test(string path) {
    MazeCell *start = &maze[2][2];
    set<string> needed = {"Potion", "Spellbook", "Wand"};
    if (isPathToFreedom(start, path, needed)) {
        cout << "Valid Path." << endl;
    } else {
        cout << "Invalid Path." << endl;
    }
}

int main() {
    //test("ESNWWNNEWSSESWWN");
    test("SWWNSEENWNNEWSSEES");
    return 0;
}
