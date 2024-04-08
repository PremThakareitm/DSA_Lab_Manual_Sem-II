// Implement Linear Queue ADT using array.

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Queue
{
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool is_empty()
    {
        return (front == -1 && rear == -1);
    }

    bool is_full()
    {
        return (rear == MAX_SIZE - 1);
    }

    void enqueue(int value)
    {
        if (is_full())
        {
            cout << "Queue overflow. Cannot enqueue element." << endl;
            return;
        }
        if (is_empty())
        {
            front = 0;
        }
        arr[++rear] = value;
        cout << "Enqueued " << value << " into the queue." << endl;
    }

    int dequeue()
    {
        if (is_empty())
        {
            cout << "Queue underflow. Cannot dequeue element." << endl;
            return -1;
        }
        int dequeued_element = arr[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
        cout << "Dequeued " << dequeued_element << " from the queue." << endl;
        return dequeued_element;
    }

    int peek()
    {
        if (is_empty())
        {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return arr[front];
    }

    void display()
    {
        if (is_empty())
        {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
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
            cout << "Enter value to enqueue: ";
            cin >> value;
            queue.enqueue(value);
            break;
        case 2:
            queue.dequeue();
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
