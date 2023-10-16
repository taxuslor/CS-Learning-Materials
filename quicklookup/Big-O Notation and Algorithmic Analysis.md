# CS106B: Big-O Notation and Algorithmic Analysis

## Big-O Notation

### Why we care about efficiency 

- Implementing inefficient algorithms may make solving certain tasks impossible, even with unlimited resources
-  Implementing efficient algorithms allows us to solve important problems, often with limited resources available
- If we can quantify the efficiency of an algorithm, we can understand and predict its behavior when we apply it to unseen problems

### What is Big-O Notation

- Big-O notation is a way of quantifying the rate at which some quantity grows

- The "O" stands for "on the order of", which is a growth prediction, not an exact formula

- Example:

  - A square of side length r has area O(r<sup>2</sup>)

  - A circle of radius r has area O(r<sup>2</sup> )

  - Metcalfe’s Law: The value of a communications network with n users is O(n<sup>2</sup>)

  - Cell Size: 
    A cell absorbs nutrients from its environment through its surface area

    - Surface area of the cell: O(r<sup>2</sup> )

    A cell needs to provide nutrients all throughout its volume 

    - Volume of the cell: O(r<sup>3</sup> )

    As a cell gets bigger, its resource intake grows slower than its resource consumption, so each part of the cell gets less energy



### Nuances of Big-O

- Big-O notation is designed to capture the rate at which a quantity grows. It does not capture information about
  - leading coefficients: the area of a square and a circle are both O(r<sup>2</sup> )
  - lower-order terms: there may be other factors contributing to growth that get glossed over


### Why runtime isn’t enough

- What is runtime?
  - Runtime is simply the amount of real time it takes for a program to run
- Measuring wall-clock runtime is less than ideal, since
  - It depends on what computer you’re using,
  - What else is running on that computer,
  - Whether that computer is conserving power,
  - Etc.
