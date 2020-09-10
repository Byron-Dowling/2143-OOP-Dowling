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
//       Nothing special right now.
//
// Files:            
//       ssfile.txt
/////////////////////////////////////////////////////////////////////////////////
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
 *      - bool empty()
 *      - bool full()
 *      - void Print()
 *
 * Private Methods:
 *      - None
 *
 * Usage:
 *
 *  Stack S;
 *  S.Push(80);
 *  S.Push(90);
 *  S.Print();
 *  int x = S.Pop();
 *
 */
class Stack {
private:
    int* S;       //array pointer
    int capacity; //max stack size
    int top;      //current top (index)
    int size;     //current num items
    bool MD;
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
        MD = false;             // memory double is false
    }

    /**
     * Stack:
     *    Constructor.
     * Params:
     *    int : capacity
     *
     * Returns:
     *     Void
     */
    Stack(int cap) {
        capacity = cap;         // set array size      
        S = new int[capacity];  // allocate new memory
        top = -1;               // initialize top of stack
        size = 0;               // set stack to empty
        MD = false;             // memory doubled is false
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
            capacity = capacity * 2;
            int* NS;
            NS = new int[capacity];
            MD = true;

            for (int i = 0; i < (capacity / 2); i++)
            {
                NS[i] = S[i];
            }

            delete[] S;                   // Releasing the memory of 1st array

            cout << "Memory Deleted!" << endl;
            S = NS;


            S[top] = data;
        }
        else
        {
            top++;              // move top of stack up
            size++;             // increment size
            S[top] = data;      // add item to array
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

        while (top == -1)                                  // If stack is empty
        {
            cout << "Error: Stack Empty!" << endl;      // User is notified
            return top;                                 // -1 value returned instead
        }                                               // If top is not empty, value pops

        if (MD == true && top < (capacity / 2))           // If stack size dips below half
        {
            cout << "Lets trim our memory bank" << endl;
            capacity = capacity / 2;
            int* NNS;
            NNS = new int[capacity];


            for (int i = 0; i < capacity; i++)
            {
                NNS[i] = S[i];
            }

            delete[] S;                                 // Releasing the memory of 1st array
            cout << "Memory Deleted!" << endl;
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
     * Empty:
     *    is the stack empty?
     * Params:
     *    void
     *
     * Returns:
     *     bool : true == stack is empty
     */
    bool Empty() {
        //return size == 0;
        return top == -1;
    }

    /**
     * Full:
     *    is the stack full?
     * Params:
     *    void
     *
     * Returns:
     *     bool : true == stack is full
     */
    bool Full() {
        return top == capacity - 1;
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
    void Print() {
        for (int i = top; i >= 0; i--)
        {
            cout << S[i] << endl;
        }
        cout << "current stack size is " << size << " and current stack capacity is " << capacity << endl;
    }

    /**
     * Overloaded ostream <<
     *    Lets us print a stack using cout
     * Params:
     *    ostream &os   : instance of ostream passed in by reference
     *    const Stack   : instance of stack passed in using const so
     *                    it cannot be changed
     *
     * Returns:
     *     ostream
     */
    friend ostream& operator<<(ostream& os, const Stack s) {
        os << "Overloaded!!" << endl;
        for (int i = s.top; i >= 0; i--) {
            os << s.S[i] << endl;
        }
        return os;
    }
};

/**
 * Person
 *
 * Description:
 *      Example struct that represents a person.
 *
 * Usage:
 *
 *  Person P1;
 *
 *  P1.fname = "firstName";
 *  P1.lname = "lastName";
 *  P1.age = 99
 *  cout<<P1<<endl;
 *
 *  Person P2("billy","bob",11);
 *  cout<<P2<<endl;
 */
struct Person {
    string fname;
    string lname;
    int age;

    Person();
    Person(string, string, int);

    friend ostream& operator<<(ostream& os, const Person p) {
        os << p.fname << "," << p.lname << " : " << p.age << endl;
        return os;
    }
};

/**
 * Constructor:
 *    Constructs the person structure
 * Params:
 *    void
 *
 * Returns:
 *     void
 */
Person::Person() {
    fname = "";
    lname = "";
    age = 0;
}

/**
 * Constructor:
 *    Constructs the person structure
 * Params:
 *    string    : first name
 *    string    : last name
 *    int       : persons age
 *
 * Returns:
 *     void
 */
Person::Person(string f, string l, int a) {
    fname = f;
    lname = l;
    age = a;
}

int main() {
    int num;

    Stack S1;           // calls default constructor

    ifstream in;
    in.open("ssfile.txt");

    if (!in)
    {
        cout << "file not found\n";
        system("pause");
        exit(-1);
    }

    while (in)
    {
        in >> num;
        S1.Push(num);
    }
    in.close();

    S1.Print();

    cout << "Popped a: " << S1.Pop() << endl;
    cout << "Popped a: " << S1.Pop() << endl;
    cout << "Popped a: " << S1.Pop() << endl;
    cout << "Popped a: " << S1.Pop() << endl;
    cout << "Popped a: " << S1.Pop() << endl;
    cout << "Popped a: " << S1.Pop() << endl;
    cout << "Popped a: " << S1.Pop() << endl;
    cout << "Popped a: " << S1.Pop() << endl;
    cout << "Popped a: " << S1.Pop() << endl;
    cout << "Popped a: " << S1.Pop() << endl;
    cout << "Popped a: " << S1.Pop() << endl;
    cout << "Popped a: " << S1.Pop() << endl;

    S1.Print();


    system("pause");
    return 0;
}