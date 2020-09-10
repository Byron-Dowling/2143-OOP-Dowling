Program #1
Stacks
Byron Dowling

Files:
Main.cpp
ssfile.txt

Description: 
I was having trouble getting the program to work in Visual Studio, it did not want to find and open my input file, however I was able to get the program to work correctly in both repl.it and in VS Code. I normally prefer Visual Studio which is why I didn't try the others until I was stumped on why my code wasn't working when it should have.
The program is set to read in a file of 20 numbers which will trigger the stack to double in size and then several pops will be called until the mempry dips below halfway and then the memory is reduced.

Original Assignment
Overview
In Lecture 2 we wrote an array based stack, but didn't implement any checks for popping an empty stack, or overflowing our array data structure. If we wrote a list based implementation we wouldn't have to worry about it getting full, but we chose array so that's an issue.

This is a pretty simple assignment in which you need to fix the existing Stack class and add the following functionality:

Empty Stack
If a Pop method is called when the stack is empty, simply print: "Error: Stack empty!" and return a -1.
We have to return some integer because our method is defined as such, so lets use -1 for now. I will show you a better technique for achieving this in a much cleaner manner.
Full Stack
This one is a little tougher to implement. Because we are not simply going to print "Error: Stack full!". We are going to resize the stack!

When a user (you) try's to push onto a full stack, you will do the following:

Allocate new memory double the size of the original array.
Copy each stack value over to the new array.
Point the array pointer S to the new array.
Delete the old array.
Likewise, when the user starts popping items off the stack, and the stack gets below half full, we need to reduce the size of the stack by half.

Be careful since a brand new stack is already below half full! So you only want to reduce a stacks size after it has been doubled at least once.

Input File
Still working on it.

Deliverables
Rename the original file from H02 to main.cpp
Create a folder in your Assignments folder called p01.
Place your commented main.cpp file into this p01 folder.
Place the input you used to test your program in there as well.
Create a banner with P01 as part of the title (see HERE)
