# CS106B: Implementation ADTs

## Acquiring and Using Storage Space

- Low-level storage space in C++ is acquired using **dynamic memory** **allocation**.

- Dynamic memory allocation normally has three steps:
  - You can, at runtime, ask for extra storage space, which C++ will give to you.
  - You can use that storage space however you’d like.
  - You have to explicitly tell the language when you’re done using the memory.

## Arrays

- Storage space on computers, which we often refer to as memory, is allocated

  in organized chunks called **arrays**

- An array is a contiguous chunk of space in the computer's memory, split into

  slots, each of which can contain one piece of information

  - Contiguous means that each slot is located directly next to the others. There are no "gaps".
  - All arrays have a specific type. Their type dictates what information can be held in each slot.
  - Each slot has an "index" by which we can refer to it.

## Dynamically Allocating Arrays

- First, declare a variable that will point at the newly-allocated array. If

  the array elements have type **T**, the pointer will have type **T\***. ○ e.g. **int\*, string\*, Vector<double>\***

- Then, create a new array with the **new** keyword and assign the pointer to point to it.

- In two separate steps:

  ````C++
  T* arr;
  arr = new T[size];
  ````

- Or, in the same line:

  ```c++
  T* arr = new T[size];
  ```

## Pointers

- A pointer is a brand new data type that becomes very prominent when working with dynamically allocated memory.
- Just like all other data types, pointers take up space in memory and can store specific values.
- The meaning of these values is what's important. **A pointer always stores a memory address**, which is like the specific coordinates of where a piece of memory exists on the computer.
- Thus, they quite literally "point" to another location on your computer.

## Properties of Dynamically Allocating Arrays

- The array you get from **new[]** is **fixed-size**: it can neither grow nor shrink once it’s created.
  - The programmer’s version of “conservation of mass.”
- The array you get from **new[]** has **no bounds-checking.** Walking off the beginning or end of an array triggers *undefined behavior*.
  - Literally anything can happen: you read back garbage, you crash your program, you let a hacker take over your computer, etc...

- The array you get from the **new[]** keyword comes from an area of memory called the heap 