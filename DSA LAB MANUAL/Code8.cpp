// Implement Circular Linked List ADT.

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

class CircularLinkedList
{
private:
    Node *head; 
public:
    CircularLinkedList()
    {
        head = nullptr;
    }

    ~CircularLinkedList()
    {
        if (head == nullptr)
            return;
        Node *current = head->next;
        while (current != head)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        delete head;
        head = nullptr;
    }

    bool is_empty()
    {
        return head == nullptr;
    }

    void insert_at_beginning(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            newNode->next = newNode; 
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != head)
            {
                current = current->next;
            }
            newNode->next = head; 
            head = newNode;       
            current->next = head; 
        }
        cout << "Inserted " << value << " at the beginning of the list." << endl;
    }

    void insert_at_end(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            newNode->next = newNode; 
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != head)
            {
                current = current->next;
            }
            current->next = newNode; 
            newNode->next = head;    
        }
        cout << "Inserted " << value << " at the end of the list." << endl;
    }

    void delete_node(int value)
    {
        if (head == nullptr)
        {
            cout << "Circular linked list is empty. Cannot delete." << endl;
            return;
        }

        Node *current = head;
        Node *prev = nullptr;

        do
        {
            if (current->data == value)
            {
                if (current == head)
                {
                    Node *lastNode = head;
                    while (lastNode->next != head)
                    {
                        lastNode = lastNode->next;
                    }
                    if (head == head->next)
                    { 
                        delete head;
                        head = nullptr;
                    }
                    else
                    {
                        lastNode->next = head->next;
                        delete head;
                        head = lastNode->next;
                    }
                    cout << "Deleted " << value << " from the list." << endl;
                    return;
                }
                else
                {

                    prev->next = current->next;
                    delete current;
                    cout << "Deleted " << value << " from the list." << endl;
                    return;
                }
            }
            prev = current;
            current = current->next;
        } while (current != head);

        cout << "Value " << value << " not found in the list. Cannot delete." << endl;
    }

    void display()
    {
        if (is_empty())
        {
            cout << "Circular linked list is empty." << endl;
            return;
        }
        cout << "Circular linked list elements: ";
        Node *current = head;
        do
        {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
};

int main()
{
    CircularLinkedList list;
    int choice, value;

    do
    {
        cout << "\nCircular Linked List Operations Menu:" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at the beginning: ";
            cin >> value;
            list.insert_at_beginning(value);
            break;
        case 2:
            cout << "Enter value to insert at the end: ";
            cin >> value;
            list.insert_at_end(value);
            break;
        case 3:
            cout << "Enter value to delete from the list: ";
            cin >> value;
            list.delete_node(value);
            break;
        case 4:
            list.display();
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
