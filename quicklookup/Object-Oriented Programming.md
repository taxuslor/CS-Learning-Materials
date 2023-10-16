# CS106B: Object-Oriented Programming

## What is a class?

- Every class has two parts:
  - an interface specifying what operations can be performed on instances of the class (this defines the abstraction boundary)
  - an implementation specifying how those operations are to be performed.

- The only difference between structs + classes are the encapsulation defaults. 
  - A struct defaults to public members (accessible outside the class itself). 
  - A class defaults to private members (accessible only inside the class implementation).

## Encapsulation

- The process of grouping related information and relevant functions into one unit and defining where that information is accessible

## Instance

- When we create an object that is our new type, we call this creating an instance of our class.

## Three Main Parts

- Member variables 
  - These are the variables stored within the class 
  - Usually not accessible outside the class implementation
- Member functions (methods) 
  - Functions you can call on the object 
  - E.g. vec.add(), vec.size(), vec.remove(), etc.
- Constructor
  - Gets called when you create the object 
  - E.g. Vector vec;

## Object-Oriented Programming 

- We create our own abstractions for defining data types using classes. Classes allow us to encapsulate information in a structured way. 
- Classes have three main parts to keep in mind when designing them: 
  - Member variables → these are always private 
  -  Member functions (methods) 
  - Constructor → this is created by default if you don’t define one 
- Writing classes requires the creation of a header (.h) file for the interface and an implementation (.cpp) file.