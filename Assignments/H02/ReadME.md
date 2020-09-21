## H02

- Name: Byron Dowling
- Date: 22 September 2020
- Class: 2413 OOP

## Definitions


#### Abstraction
> Abstraction refers to displaying only essential information and hiding the details and or implementation. For example:
> 
> https://qph.fs.quoracdn.net/main-qimg-d416d714184b5665ff5ae3f231e854f4


#### Attributes / Properties
> Attributes and or Properties are data stored inside a class or instance and represent the state or quality of the class or instance. 
> Essentially, they store information about the instance.


#### Class
> A class is a programmer defined data structure blueprint for creating the content of object.
> However, a class constructor doesn't utilize any memory until an object is created.


#### Class Variable
> Class variables also known as static variables are declared with the static keyword in a class, but outside a method, constructor or a block. 
> There would only be one copy of each class variable per class, regardless of how many objects are created from it


#### Composition
> Fundamental OOP concept that describes a class that references one or more objects of other classes in instance variables.
> "Has-a" relationship between two objects.

#### Encapsulation
> Describes the idea of bundling data and methods that work on that data into a single unit.
> A class is an example of combining data members and functions into a single unit as it prevents direct access to the data but instead access through the methods.

#### Friends
> A friend function, a friend of a given class, is a function that is given the same access as class methods to private and protected data.
>
> https://image.slidesharecdn.com/oop03objectsclasses-140410040223-phpapp02/95/oop-objectsclasses-26-638.jpg?cb=1397102633

#### Inheritance
> A mechanism in which one class acquires the property of another class such as reusing the fields and methods of the existing class.
> Similar concept to the idea of children inheriting traits from their parents.
>
> https://media.geeksforgeeks.org/wp-content/uploads/inheritance2.png

#### Instance Variable
> Instance variables are declared in a class, but outside a method. When space is allocated for an object in the heap, a slot for each instance variable value is created. 
> Instance variables hold values that must be referenced by more than one method, constructor or block, or essential parts of an object's state present throughout the class.


#### Member Variable
> A member variable is a variable that is associated with a specific object and is accessible for all its methods.
> Found within the Private or Protected section of a class.

#### Method
> A method is the equivalent of a function but within a class.
> A method defines the behavior of the objects that are created from the class.
>
> https://upload.wikimedia.org/wikipedia/commons/thumb/8/82/CPT-OOP-interfaces.svg/300px-CPT-OOP-interfaces.svg.png

#### Multiple Inheritance
> An OOP feature in which an object or class can inherit characteristics and features from more than one parent object or parent class
> When this occurs, the constructors of inherited classes are called in the same order in which they are inherited.

#### Object
> An object is an element or instance of a class, the actual creation utilizing the class blueprint.


#### Overloading
> Overloading lets you define the same method multiple times so that you can call them with different argument lists.
> This is common when defining class instructors where you have a default constructor and a programmer-defined constructor
> Can also be done in terms of overloading operators such as "+, -, %, *" to allow us to perform arithmetic on two objects such as adding two objects together

#### Polymorphism
> Polymorphism is the ability of an object to take on many forms.
> Describes the concept that different classes can be used with the same interface and each of these classes can provide its own implementation of the interface.
>
> https://i.ytimg.com/vi/A5sp7i8NXWg/maxresdefault.jpg

#### Public / Private / Protected
> These are access modifers within a class than help us encapsulate data.
- "Public" - Any class can refer to the field or call the method.
- "Private" - Indicates that only the current class or friends will have access to the field or method.
- "Protected" - Only the current class and subclasses of the class will have access to the field or method. Can be access in child classes or derived classes.
>
> https://i.stack.imgur.com/SFysv.jpg

#### Virtual
> Refers to inheritable and overridable functions or methods for which "dynamic dispatch" is facilitated.
> Virtual functions allow a program to call methods that don't necessarily even exist at the moment the code is compiled.
>
