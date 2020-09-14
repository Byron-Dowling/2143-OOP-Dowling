///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Byron Dowling
// Email:            byrondowling7@gmail.com
// Label:            P01
// Title:            Array Based Stack
// Course:           2143
// Semester:         Fall 2020
//
// Description:
//       Example implementation of an array based stack that holds integers.
//       Further adding on to it by allowing the stack to grow or shrink in
//       size depending on how much is pushed or popped to or from the stack.
//
// Usage:
//       Nothing special right now. Getting familiar with stacks, etc.
//
// Files:           
//       main.cpp
//       input.txt
//       stackdata.txt
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/**
 * Stack
 *
 * Description:
 *      Integer array based stack implementation
 *
 * Public Methods:
 *      - Stack()
 *      - Stack(int)
 *      - void Push()
 *      - int Pop()
 *      - void Print()
 *
 * Private Methods:
 *      - None
 *
 * Usage:
 *
 *  Reads set of push and pop commands
 *  from an input file provided. 
 *
 */
class Stack {
private:
    int* S;                     // array pointer
    int capacity;               // max stack size
    int top;                    // current top (index)
    int size;                   // current num items
    unsigned long int Max_Size; // Max stack size variable
    bool MD;                    // Variable to track if memory was doubled, MD = Memory Doubled
public:
    /**
     * Stack:
     *    Constructor.
     * Params:
     *    void
     *
     * Returns:
     *     Void
     */
    Stack() {
        capacity = 10;          // set array size
        S = new int[capacity];  // allocate new memory
        top = -1;               // initialize top of stack
        size = 0;               // set stack to empty
        Max_Size = 0;
        MD = false;             // memory double is false
    }

    /**
     * Push:
     *    Push item onto stack.
     * Params:
     *    int : data
     *
     * Returns:
     *     Void
     */
    void Push(int data) {

        
        if (size == capacity)
        {
            top++;
            size++;
            cout << "Stack is full. Let's make some more room!" << endl;
            cout << " +  :  " << capacity << " --> ";
            capacity = capacity * 2;
            cout << capacity << endl;
            int* NS;                                    // Creating a new dynamic array with double the memory
            NS = new int[capacity];
            MD = true;                                  // Changing our bool value of Memory Doubled to True
                                                        // Lets us know if the memory has been doubled before

            for (int i = 0; i < (capacity / 2); i++)    // Assigning the values of the old array into the new one
            {
                NS[i] = S[i];
            }

            delete[] S;                                 // Releasing the memory of previous array

            cout << "Memory Deleted!" << endl;
            S = NS;                                     // Pointing to the new array

            S[top] = data;

            if (Max_Size <= capacity)                   // Updating our Max Size variable
            {
                Max_Size = capacity;
            }
        }
        else
        {
            top++;                                      // move top of stack up
            size++;                                     // increment size
            S[top] = data;                              // add item to array
        }

    }

    /**
     * Pop:
     *    remove item from stack.
     * Params:
     *    void
     *
     * Returns:
     *     int
     */
    int Pop() {

        if (top == -1)                                  // If stack is empty
        {
            cout << "Error: Stack Empty!" << endl;      // User is notified
            return -1;                                  // -1 value returned instead
        }                                               // If top is not empty, value pops

        if (MD == true && top < (capacity / 2))         // If stack size dips below half
        {
            cout << "Stack is at less than 50% capacity, let's trim our memory!" << endl; 
            cout << " -  :  " << capacity << " --> ";
            capacity = capacity / 2;                    // Trimming capacity in half
            cout << capacity << endl;
            int* NNS;
            NNS = new int[capacity];


            for (int i = 0; i < capacity; i++)
            {
                NNS[i] = S[i];                          // Copying contents of the previous bigger stack
            }                                           // into the new array with smaller capacity

            delete[] S;                                 // Releasing the memory of previous array
            S = NNS;
            int data = S[top];
            top--;
            size--;
            return data;

        }
        else
        {
            int data = S[top];  // pull item from stack
            top--;              // shrink the stack
            size--;             // update our size
            return data;        // send item back
        }
    }

    /**
     * Print:
     *    Used so we can inspect our stack.
     * Params:
     *    void
     *
     * Returns:
     *     void
     */
    void Print() 
    {
        // Output File Print formatting 

        ofstream OF("stackdata.txt");
        OF << "Name: Byron Dowling" << endl;
        OF << "Program: P01" << endl;
        OF << "Date: 15 September 2020" << endl << endl << endl;
        OF << "Starting Size: 10" << endl;
        OF << "Max Size: " << Max_Size << endl;
        OF << "Ending Size: " << size << endl;
    }
};


int main() {
    int num;                            // Int variable read from input file
    string command;                     // Command read from input file

    Stack S1;                           // Stack Object dedclared

    ifstream infile;

    // Visual Studio would only accept the full path, filename.txt wouldn't open
    infile.open("C:\\Users\\byron\\OneDrive\\Documents\\input.txt");

    if (!infile)                        // If file isn't opened successfully
    {
        cout << "file not found\n";
        system("pause");
        exit(1);
    }

    while (!infile.eof())               // While file is still open
    {
        infile >> command;

        if (command == "push")          // If the command is Push, a number is read afterwards before new line
        {
            infile >> num;
            S1.Push(num);
        }
        else
        {
            S1.Pop();
        }
    }
    infile.close();


    S1.Print();
     
    system("pause");
    return 0;
}