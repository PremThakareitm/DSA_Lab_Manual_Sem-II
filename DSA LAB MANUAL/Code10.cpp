// Implement Linear Queue ADT using Linked List

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

class Queue
{
private:
    Node *front; 
    Node *rear;  

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    ~Queue()
    {
        Node *current = front;
        Node *next;
        while (current != nullptr)
        {
            next = current->next;
            delete current;
            current = next;
        }
        front = nullptr;
        rear = nullptr;
    }

    bool is_empty()
    {
        return front == nullptr;
    }

    void enqueue(int value)
    {
        Node *newNode = new Node(value);
        if (is_empty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued " << value << " into the queue." << endl;
    }

    int dequeue()
    {
        if (is_empty())
        {
            cout << "Queue underflow. Cannot dequeue element." << endl;
            return -1; 
        }
        int dequeued_element = front->data;
        Node *temp = front;
        front = front->next;
        delete temp;
        cout << "Dequeued " << dequeued_element << " from the queue." << endl;
        return dequeued_element;
    }

    int peek()
    {
        if (is_empty())
        {
            cout << "Queue is empty. No front element to peek." << endl;
            return -1; 
        }
        return front->data;
    }

    void display()
    {
        if (is_empty())
        {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        Node *current = front;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue queue;
    int choice, value;

    do
    {
        cout << "\nQueue Operations Menu:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue into the queue: ";
            cin >> value;
            queue.enqueue(value);
            break;
        case 2:
            value = queue.dequeue();
            if (value != -1)
            {
                cout << "Dequeued value: " << value << endl;
            }
            break;
        case 3:
            value = queue.peek();
            if (value != -1)
            {
                cout << "Front element of the queue: " << value << endl;
            }
            break;
        case 4:
            queue.display();
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid choice." << endl;
        }
    } while (choice != 5);

    return 0;
}
