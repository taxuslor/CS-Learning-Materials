# CS106B: Two Types of Recursion

## Recursive Backtracking

- recursive backtracking + decision trees
  - Unlike our previous recursion paradigm in which a solution gets built up as recursive calls return, in backtracking our final outputs occur at our base cases (leaves) and get built up as we go down the decision tree.
  - The height of the tree corresponds to the number of decisions we have to make. The width at each decision point corresponds to the number of options. 
  - To exhaustively explore the entire search space, we must try every possible option for every possible decision. That can be a lot of paths to walk!

- Backtracking recursion 
  - Build up many possible solutions through multiple recursive calls at each step 
  - Seed the initial recursive call with an “empty” solution 
  - At each base case, you have a potential solution

## Using backtracking recursion

- There are 3 main categories of problems that we can solve by using backtracking recursion:

  - We can generate all possible solutions to a problem or count the total number of possible solutions to a problem
  - We can find one specific solution to a problem or prove that one exists
  - We can find the best possible solution to a given problem

## Subset Model

```C++
#include <iostream>
#include <vector>

const std::vector<std::string> coin_sides = {"正面", "反面"};

void generateCoinResults(int n, std::vector<std::string> &current_result) {
    if (n == 0) {
        for (const auto &result: current_result) {
            std::cout << result << " ";
        }
        std::cout << std::endl;
        return;
    }
    for (auto side: coin_sides) {
        current_result.push_back(side);
        generateCoinResults(n - 1, current_result);
        current_result.pop_back();
    }
}

int main() {
    std::vector<std::string> result;
    generateCoinResults(3, result);
    return 0;
}
```

## Permutation Model

```C++
#include "iostream"

using namespace std;

void listPermutationsHelper(string remaining, string soFar) {
    if (remaining.empty()) {
        cout << soFar << endl;
        return;
    }
    for (int i = 0; i < remaining.length(); ++i) {
        char nextLetter = remaining[i];
        string rest = remaining.substr(0, i) + remaining.substr(i + 1);
        listPermutationsHelper(rest, soFar + nextLetter);
    }
}

void listPermutations(string s) {
    listPermutationsHelper(s, "");
}

int main(void) {
    listPermutations("cat");
    return 0;
}
```

## Subset Model

```C++
#include <iostream>
#include <vector>

using namespace std;

void getSubsetHelper(vector<string> &remaining, vector<string> &soFar) {
    if (remaining.empty()) {
        for (auto element: soFar)
            cout << element << " ";
        cout << endl;
        return;
    }
    string element = remaining.back();
    remaining.pop_back();
    getSubsetHelper(remaining, soFar);
    soFar.push_back(element);
    getSubsetHelper(remaining, soFar);
    soFar.pop_back();
    remaining.push_back(element);
}

void getSubset(vector<string> set) {
    vector<string> soFar = {};
    getSubsetHelper(set, soFar);
}

int main() {
    vector<string> set = {"Nick", "Kylie", "Trip"};
    getSubset(set);
    return 0;
}
```

## Combination Model

```c++
void findAllUnbiasedJuriesHelper(vector<juror> &allCandidates, vector<juror> &currentJury, int currentBias, int index) {
    if (index == allCandidates.size()) {
        if (currentBias == 0) {
            displayJury(currentJury);
        }
    } else {
        juror currentCandidate = allCandidates[index];
        findAllUnbiasedJuriesHelper(allCandidates, currentJury, currentBias, index + 1);
        currentJury.push_back(currentCandidate);
        findAllUnbiasedJuriesHelper(allCandidates, currentJury, currentBias + currentCandidate.bias, index + 1);
        currentJury.pop_back();
    }
}

void findAllUnbiasedJuries(vector<juror> &allCandidates) {
    vector<juror> jury;
    findAllUnbiasedJuriesHelper(allCandidates, jury, 0, 0);
}
```

