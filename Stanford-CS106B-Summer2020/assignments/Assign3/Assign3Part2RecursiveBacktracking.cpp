/* CS106B Assign3: Recursive Problem Solving
 * Part2: Recursive Backtracking
 */
#include <iostream>

using namespace std;

// Segment1: Boggle Score
/* The Boggle game board is a square grid onto which you randomly distribute a set of letter cubes.
 * You find a word on the board by tracing by a path through adjoining letter cubes,
 * using each cube at most once in word.
 * A word is valid for a given board if it meets all of the following conditions:
 * It is at least 4 letters long.
 * It is contained in a list of valid English words.
 * It can be formed by tracing a path through adjoining letter cubes, using any given cube at most once.
 * It has not already been formed by another path on the board
 */
class Lexicon {
private:
    vector<string> dic;
public:
    bool containPrefix(string str);

    bool wordFound(string str);
};

bool Lexicon::wordFound(string str) {
    if (find(dic.begin(), dic.end(), str) != dic.end()) {
        return true;
    }
    return false;
}

bool Lexicon::containPrefix(string str) {
    //...
    return false;
}

const int directions[][2] = {{-1, 0},
                             {1,  0},
                             {0,  -1},
                             {0,  1}};

void search(vector<vector<char>> &board, vector<vector<bool>> &visited, int row, int col, string &word,
            vector<string> &results, Lexicon &lex) {
    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || visited[row][col])
        return;
    visited[row][col] = true;
    word += board[row][col];
    if (lex.wordFound(word)) {
        results.push_back(word);
    }
    if (!lex.containPrefix(word)) {
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nextRow = row + directions[i][0];
        int nextCol = col + directions[i][1];
        search(board, visited, nextRow, nextCol, word, results, lex);
    }
    visited[row][col] = false;
    word.pop_back();
}

/* A word with 3 or fewer characters is invalid by the above criteria and is thus worth zero points.
 * A 4-letter word earns 1 point, a 5-letter word is 2 points; 6-letter words earn 3 points; and so on.
 */
int scoreBoard(vector<vector<char>> &board, Lexicon &lex) {
    vector<string> results;
    int rows = board.size();
    int cols = board[0].size();
    int score = 0;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            string word = "";
            search(board, visited, row, col, word, results, lex);
        }
    }
    for (auto &result: results) {
        cout << result << endl;
        if (result.size() > 3) {
            score += result.size() - 3;
        }
    }
    return score;
}

void test1() {
    Lexicon lex;
    vector<vector<char>> board =
            {
                    {'a', 'b', 'c', 'd'},
                    {'h', 'g', 'f', 'e'},
                    {'i', 'j', 'k', 'l'},
                    {'p', 'o', 'n', 'm'}
            };
    cout << scoreBoard(board, lex) << endl;
}

// Segment2: Examining Voting Systems
/* The Banzhaf Power Index expresses a block's voting power as the percentage of critical votes
 * that the block has out of all total critical votes.
 * To convert from the count of critical votes to the Power Index,
 * total all critical votes in the system, and compute the percentage of each block's critical votes.
 */
/* Set aside the target block and recursively explore all the subsets (coalitions) that do not include the target.
 * As you form a coalition, you do not need to store a collection of the participating blocks,
 * just tally the amassed vote total for each coalition.
 * Once a coalition is formed and its votes are summed, consider the impact of the target block's vote.
 * Without the target block does the coalition lose, and with the target block, does the coalition win?
 * If the answer to both of these questions is yes, then the block is a critical voter for that coalition.
 * Repeat the exploration for every block in the system to count each block's critical votes.
 * Once you have the counts of critical votes for all blocks, the conversion to percentage is simple looping and arithmetic.
 */
void calculate(int i, int cur_vote, int total_vote, vector<int> &blocks, vector<int> &powerIndexes) {
    if (i == blocks.size()) {
        if (cur_vote > total_vote / 2) {
            for (int j = 0; j < blocks.size(); ++j) {
                if (cur_vote - blocks[j] <= total_vote / 2) {
                    powerIndexes[j]++;
                }
            }
        }
        return;
    }
    calculate(i + 1, cur_vote + blocks[i], total_vote, blocks, powerIndexes);
    calculate(i + 1, cur_vote, total_vote, blocks, powerIndexes);
}

vector<int> computePowerIndexes(vector<int> &blocks) {
    vector<int> powerIndexes(blocks.size(), 0);
    int total_vote = 0;
    for (int vote: blocks) {
        total_vote += vote;
    }
    calculate(0, 0, total_vote, blocks, powerIndexes);
    return powerIndexes;
}

void test2() {
    vector<int> testcase = {50, 49, 1};
    vector<int> powerIndex = computePowerIndexes(testcase);
    for (int index: powerIndex) {
        cout << index << " ";
    }
}

int main() {
    //test1();
    //test2();
    return 0;
}