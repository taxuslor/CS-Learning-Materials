# CS106B: Recursive Optimization and Review

## Backtracking recursion

### Two ways of doing it

- Choose explore undo:
  - Uses pass by reference; usually with large data structures 
  - Explicit unchoose step by "undoing" prior modifications to structure 
  - E.g. Generating subsets (one set passed around by reference to track subsets)

- Copy edit explore: 
  - Pass by value; usually when memory constraints aren’t an issue 
  - Implicit unchoose step by virtue of making edits to copy 
  - E.g. Building up a string over time

### Three use cases for backtracking

- Generate/count all solutions(enumeration)
- Find one solution(or prove existence)
- Pick one best solution



- Permutations
- Subsets
- Combinations
- Etc.

