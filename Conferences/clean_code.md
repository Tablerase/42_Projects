# Clean Code

Example used during conference: https://github.com/ffoissey/meetup42_cleancode

## Side info

### Git

Ensential in future

### Ego in programming

https://blog.octo.com/egoless-programming

## Code part

### Principe de moindre responsabilité

Retirer les responsabilités inutiles

- static: 
  - pour non utiliser en dehors de la classe
- const:
  - pour ne pas modifier la valeur
  - permet optimisation du compilateur

### Pseudo code before code

### Notes

- pseudo code before code

- wrapper
  - encapsulation

### Good practices

## KISS

- Keep It Simple Stupid

## DRY

- Don't Repeat Yourself

- In software engineering, don't repeat yourself (DRY) is a principle of software development aimed at reducing repetition of software patterns, replacing it with abstractions or using data normalization to avoid redundancy.

- In case of error, it's easier to fix it in one place than in multiple places.

## YAGNI

- You Ain't Gonna Need It

- In software development, you should not add functionality until it is necessary.

Some people think that YAGNI is a subset of KISS, but it's not. KISS is about simplicity, while YAGNI is about functionality.


## IMMUTABILITY

Immutability is a core principle of functional programming. It means that once a variable has been assigned a value, it cannot be changed.

## Architecture

### SOLID

SOLID is an acronym for the first five object-oriented design (OOD) principles by Robert C. Martin. These principles are the foundation of building maintainable and scalable software.

#### SRP

- Single Responsibility Principle

#### OCP

- Open/Closed Principle

Open for extension, closed for modification

OCP states that the design of a module should allow for its behavior to be extended without modifying its source code.

#### LSP

- Liskov Substitution Principle

LSP states that objects of a superclass shall be replaceable with objects of its subclass without affecting the functionality of the program.

#### ISP

- Interface Segregation Principle

Interface Segregation Principle states that a function should not be forced to depend on interfaces that it does not use.

Separate interfaces for different functionalities.

Sort things correctly.

#### DIP

- Dependency Inversion Principle

  - High-level modules should not depend on low-level modules. Both should depend on abstractions.
  - Abstractions should not depend on details. Details should depend on abstractions.

In simpler terms, this means that your code should depend on abstract interfaces, not on concrete implementations. This makes your system more flexible, better suited for future changes, and easier to test because concrete implementations can be easily swapped with mock objects.
