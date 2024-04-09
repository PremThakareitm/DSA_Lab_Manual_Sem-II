// Implement Stack ADT using Linked List

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class Stack
{
private:
    Node *top; 

public:
    Stack()
    {
        top = nullptr;
    }

    ~Stack()
    {
        Node *current = top;
        Node *next;
        while (current != nullptr)
        {
            next = current->next;
            delete current;
            current = next;
        }
        top = nullptr;
    }

    bool is_empty()
    {
        return top == nullptr;
    }

    void push(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << "Pushed " << value << " onto the stack." << endl;
    }

    int pop()
    {
        if (is_empty())
        {
            cout << "Stack underflow. Cannot pop element." << endl;
            return -1; 
        }
        int popped_element = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        cout << "Popped " << popped_element << " from the stack." << endl;
        return popped_element;
    }

    int peek()
    {
        if (is_empty())
        {
            cout << "Stack is empty. No top element to peek." << endl;
            return -1;
        }
        return top->data;
    }
};

int main()
{
    Stack stack;
    int choice, value;

    do
    {
        cout << "\nStack Operations Menu:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push onto the stack: ";
            cin >> value;
            stack.push(value);
            break;
        case 2:
            value = stack.pop();
            if (value != -1)
            {
                cout << "Popped value: " << value << endl;
            }
            break;
        case 3:
            value = stack.peek();
            if (value != -1)
            {
                cout << "Top element of the stack: " << value << endl;
            }
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid choice." << endl;
        }
    } while (choice != 4);

    return 0;
}
