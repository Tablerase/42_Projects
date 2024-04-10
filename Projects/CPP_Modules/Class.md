# Class

## Object-Oriented Programming (OOP)

In object-oriented programming (often abbreviated as OOP), the focus is on creating program-defined data types that contain both properties and a set of well-defined behaviors. The term “object” in OOP refers to the objects that we can instantiate from such types.

Help to manage complexity in large programs by grouping related data and functions together.

Modularity is achieved by creating classes that can be reused in other programs. This eliminates the need to rewrite the same code over and over again.

OOP concepts:
  - Encapsulation 
  - Inheritance 
  - Abstraction 
  - Polymorphism

## Class components

### Data Members

Data members are the data variables that are used to store the data. These data members can be of any data type.

### Member Functions

Member functions are the functions that are used to manipulate the data stored in the data members. These functions can be of any type.

### Access Specifiers

Access specifiers are used to define the access control for the members of the class. There are three types of access specifiers in C++:
  - Public: Members are accessible from outside the class.
  - Private: Members cannot be accessed (or viewed) from outside the class.
  - Protected: Members cannot be accessed from outside the class, however, they can be accessed in inherited classes.

### Constructors

Constructors are special member functions of a class that are used to initialize the objects of that class. Constructors are called when an object is created.

### Destructors

Destructors are special member functions of a class that are used to free the resources that have been allocated during the lifetime of the object.

### Operator Overloading

Operator overloading is a feature in C++ where an operator can be redefined to provide custom implementation.

### Inheritance

Inheritance is a feature in C++ where a class can inherit

### Polymorphism

Polymorphism is a feature in C++ where a function can have different forms.

### Abstraction

Abstraction is a feature in C++ where only the necessary details are shown to the user and the rest of the details are hidden.

### Others informations

#### Invariants

Invariants are conditions that are always true for a class. They are the rules that must be followed by the class.

#### This Pointer

The `this` pointer is a pointer that points to the object that invokes the member function.

## Defining a Class

A class is a blueprint for creating objects (a particular data structure), providing initial values for state (member variables or attributes), and implementations of behavior (member functions or methods).
  
```cpp
class NameOfClass {
  // constructor
  NameOfClass() {
    // code
  }
  // destructor
  ~NameOfClass() {
    // code
  }
  // access specifier
  public:
    // data members
    int dataMember1;
    int dataMember2;
    // member functions
    void memberFunction1() {
      // code
    }
    void memberFunction2() {
      // code
    }
};
```

Members variables and functions can be *defined in any order*.

If you don't use an access specifier, the members of the class are **private** by default.

## Member Functions

Member functions are the functions that are used to manipulate the data stored in the data members. These functions can be of any type.

```cpp
class MyClass {
  public:
    void myMethod() { // method
      cout << "Hello World!";
    }
};
```

Note:
- Prefer using `namespace` when you don't have data members in the class.

## Non-Member Functions or data

You can define with keyword `static` to make a member function or data a class member, not an object member.

You cant use `this` pointer in static / non member functions.

```cpp
class MyClass {
  public:
    static int my_static_variable; // static data member
    static void myStaticMethod() { // static member function
      cout << "Hello World!";
    }
};

int MyClass::my_static_variable = 0; // initialize static data member
```

## Pointers to Classes/Objects/Members

### Pointers to Members

#### Pointers to data members

Pointers to members are pointers that point to the members of a class.

```cpp
class MyClass {
  public:
    int x;
    void myMethod() {
      cout << "Hello World!";
    }
};

int main() {
  int MyClass::*ptr = &MyClass::x; // pointer to data member

  MyClass obj;
  obj.*ptr = 10; // access data member using pointer
}
```

- `int MyClass::*ptr` is a pointer to a data member of the class `MyClass`.
- `&MyClass::x` is the address of the data member `x` of the class `MyClass`.
- `obj.*ptr` is used to access the data member `x` of the object `obj` using the pointer `ptr`.
  - `obj.*ptr` is equivalent to `obj.x`.

#### Pointers to member functions

```cpp
class MyClass {
  public:
    void myMethod() {
      cout << "Hello World!";
    }
};

int main() {
  void (MyClass::*ptr)() = &MyClass::myMethod; // pointer to member function

  MyClass obj;
  (obj.*ptr)(); // access member function using pointer
}
```

- `void (MyClass::*ptr)()` is a pointer to a member function of the class `MyClass`.
- `&MyClass::myMethod` is the address of the member function `myMethod` of the class `MyClass`.
- `(obj.*ptr)()` is used to access the member function `myMethod` of the object `obj` using the pointer `ptr`.
  - `(obj.*ptr)()` is equivalent to `obj.myMethod()`.

## Access Specifiers / Visibility Modes

By default, all members of a class are private.

Access specifiers are used to define the access control for the members of the class. There are three types of access specifiers in C++:
  - Public: Members are accessible from outside the class.
  - Private: Members cannot be accessed (or viewed) from outside the class.
  - Protected: Members cannot be accessed from outside the class, however, they can be accessed in inherited classes.

```cpp
class MyClass {
  public: // public access specifier
    int x; // public data member
  private: // private access specifier
    int y; // private data member
  protected: // protected access specifier
    int z; // protected data member
};
```

### Getters and Setters

Getters and setters are used to access and modify the private data members of a class.

```cpp
class MyClass {
  private:
    int x;
  public:
    int getX() const { // getter
      return x;
    }
    void setX(int y) { // setter
      if (y > 0)
        x = y;
    }
};
```

## Constructors

Constructors are special member functions of a class that are used to initialize the objects of that class. Constructors are called when an object is created.

```cpp
class MyClass {
  public:
    MyClass() { // constructor
      cout << "Constructor called";
    }
};
```

### Default Constructor

A constructor that doesn't have any parameters is called a default constructor.

```cpp
class MyClass {
  public:
    MyClass() { // default constructor
      cout << "Constructor called";
    }
};
```

### Parameterized Constructor

A constructor that has parameters is called a parameterized constructor.

```cpp
class MyClass {
  public:
    int x;
    MyClass(int y) { // parameterized constructor
      x = y;
    }
};
```

### Copy Constructor

A copy constructor is a member function that initializes an object using another object of the same class.

```cpp
class MyClass {
  public:
    int x;
    MyClass(int y) { // parameterized constructor
      x = y;
    }
    MyClass(const MyClass &obj) { // copy constructor
      x = obj.x;
    }
};
```

### Constructor Overloading

Constructor overloading is a concept in C++ where there can be more than one constructor in a class with the same name but different parameters.

```cpp
class MyClass
{
  public:
    int x;
    MyClass()
    { // default constructor
      x = 0;
    }
    MyClass(int y)
    { // parameterized constructor
      x = y;
    }
};

int main()
{
  MyClass obj1; // default constructor
  MyClass obj2(10); // parameterized constructor
}
```

### Constructor Initialization Lists

Constructor initialization lists are used to initialize the data members of a class.

```cpp
class MyClass
{
  public:
    int x;
    int y;
    MyClass(int a, int b) : x(a), y(b) // constructor initialization list
    { 
      // code
    }
};
```

other way to initialize data members:

```cpp
class MyClass
{
  public:
    int x;
    int y;
    MyClass(int a, int b) // constructor
    {
      x = a;
      y = b;
    }
};
```

## Const Members

### Const Objects

A const object is an object that cannot be modified.

```cpp
class MyClass
{
  public:
    int x;
    MyClass(int y)
    {
      x = y;
    }
};

int main()
{
  const MyClass obj(10); // const object
  obj.x = 20; // error: cannot modify const object
}
```

### Const Member Functions

A **const member function** is a member function that guarantees it **will not modify the object or call any non-const member** functions (unless the member function is also declared as const).

```cpp
#include <iostream>

struct Date
{
    int year {};
    int month {};
    int day {};

    void print() const // now a const member function
    {
        std::cout << year << '/' << month << '/' << day;
    }
};

int main()
{
    const Date today { 2024, 04, 04 }; // const

    today.print();  // ok: const object can call const member function

    return 0;
}
```

A member function that does not (and will not ever) modify the state of the object **should be made const**, so that it can be called on both const and non-const objects.

## Compare Objects

To compare two objects of a class, you can overload the `==` operator.

```cpp
class MyClass
{
  public:
    int x;
    MyClass(int y)
    {
      x = y;
    }
    bool operator==(MyClass obj) // operator overloading
    {
      return x == obj.x;
    }
};

int main()
{
  MyClass obj1(10);
  MyClass obj2(10);
  if (obj1 == obj2) // compare objects
    cout << "Equal";
  else
    cout << "Not equal";
}
```

## Files Organization

Prefer to put your class definitions in a header file with the same name as the class. Trivial member functions (such as access functions, constructors with empty bodies, etc…) can be defined inside the class definition.

Prefer to define non-trivial member functions in a source file with the same name as the class

### Header Files

Header files contain the class declaration
  
```cpp
// MyClass.h
#ifndef MYCLASS_H
  #define MYCLASS_H

class MyClass {
  public:
    int x;
    MyClass(int y);
};

#endif
```

### Source Files

Source files contain the class definition

```cpp
// MyClass.cpp
#include "MyClass.h"

MyClass::MyClass(int y) {
  x = y;
}
```

### Main File

Main file contains the main function

```cpp
// main.cpp
#include <iostream>

#include "MyClass.h"

int main() {
  MyClass obj(10);
  std::cout << obj.x;
  return 0;
}
```

## Canonic Form (Copley)

The canonic form of a class is a set of functions that are commonly defined for a class. These functions are:
  - Default constructor
  - Copy constructor
  - Copy assignment operator
  - Destructor

```cpp
class MyClass {
  public:
    MyClass(); // default constructor
    MyClass(const MyClass &obj); // copy constructor
    MyClass& operator=(const MyClass &obj); // copy assignment operator
    ~MyClass(); // destructor
};
```
