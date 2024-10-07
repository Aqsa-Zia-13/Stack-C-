//#include<iostream>               //array implementation
//using namespace std;
//class stack
//{
//    int* arr;         // dynamic array
//    int top;
//public:
//    int n = 100;
//    stack() 
//    {
//        arr = new int[n];
//        top = -1;
//    }
//                                     // PUSH FUNCTION
//    void push(int x) 
//    {
//        if (top == n - 1) 
//        {
//            cout << "stack overflow" << endl;
//            return;
//        }
//        top++;
//        arr[top] = x;
//    }
//                                     // POP FUNCTION
//    void pop() 
//    {
//        if (top == -1) 
//        {  // corrected comparison from = to ==
//            cout << "no element to pop(kick out)" << endl;
//            return;
//        }
//        top--;
//    }
//                                         // TOP FUNCTION
//    int Top() 
//    {
//        if (top == -1) 
//        {  // corrected comparison from = to ==
//            cout << "no element at top to print" << endl;
//            return -1;
//        }
//        return arr[top];
//    }
//                                         // Empty function
//    bool empty() 
//    {
//        return top == -1;
//    }
//    void size()
//    {
//        cout << "size:";
//        cout << top + 1 << endl;
//    }
//};
//                                          //MAIN FUNCTION
//int main() 
//{
//    stack st;
//    st.push(2);
//    st.push(4);
//    st.push(6);
//    st.push(8);
//    st.size();
//
//    cout << st.Top() << endl;  // Should print 8
//    cout << endl;
//
//    st.pop();
//    cout << st.Top() << endl;  // Should print 6
//    cout << endl;
//
//    /*st.pop();
//    st.pop();
//    st.pop();
//    st.pop();*/
//    cout << st.empty();  // Should print 1 (true) since the stack is now empty
//    st.size();
//}
//                                   //linked list implemenatation:




#include <iostream>
using namespace std;

class stack {
private:
    int val;
    stack* next;
    stack* head;

public:
    int stack_size;

    // Default constructor
    stack() {
        head = nullptr;
        stack_size = 0;
    }

    // Parameterized constructor
    stack(int v) {
        val = v;
        next = nullptr;
    }

    // Push function to add an element to the stack
    void push(int t) {
        stack* temp = new stack(t);  // Create a new node with value 't'
        temp->next = head;           // Point new node's next to current head
        head = temp;                 // Update head to point to the new node
        cout << "Element " << t << " pushed into the stack." << endl;
        stack_size++;                // Increment the stack size
    }

    // Pop function to remove the top element from the stack
    void pop() {
        if (head == nullptr) {
            cout << "Stack is empty." << endl;
            return;
        }
        stack* temp = head;
        head = head->next;           // Move head to the next element
        delete temp;                 // Delete the old head
        cout << "Element popped." << endl;
        stack_size--;                // Decrement the stack size
    }

    // Function to get the top element of the stack
    int top() {
        if (head == nullptr) {
            cout << "Stack is empty, no top element." << endl;
            return -1;
        }
        cout << "Top element is: " << head->val << endl;
        return head->val;
    }

    // Function to get the size of the stack
    int size() {
        cout << "Size of stack is: " << stack_size << endl;
        return stack_size;
    }

    // Function to check if the stack is empty
    int empty() {
        if (head == nullptr) {
            cout << "Stack is empty." << endl;
            return 1;
        }
        cout << "Stack is not empty." << endl;
        return 0;
    }
};

int main() {
    stack st;
    st.empty();            // Should return 1 (true, stack is empty)
    st.push(2);
    st.push(3);
    st.push(4);
    st.pop();              // Should print 4 (element popped)
    st.top();              // Should print 3 (top element)
    st.size();             // Should print 2 (size of stack)
    st.empty();            // Should return 0 (false, stack is not empty)
}
