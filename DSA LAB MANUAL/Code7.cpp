// Implement Singly Linked List ADT.

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

class LinkedList
{
private:
    Node *head; 

public:
    LinkedList()
    {
        head = nullptr;
    }

    ~LinkedList()
    {
        Node *current = head;
        Node *next;
        while (current != nullptr)
        {
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    bool is_empty()
    {
        return head == nullptr;
    }

    void insert_at_beginning(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << value << " at the beginning of the list." << endl;
    }

    void insert_at_end(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
        cout << "Inserted " << value << " at the end of the list." << endl;
    }

    void delete_node(int value)
    {
        if (head == nullptr)
        {
            cout << "Linked list is empty. Cannot delete." << endl;
            return;
        }

        Node *temp = head;
        Node *prev = nullptr;

        if (temp != nullptr && temp->data == value)
        {
            head = temp->next;
            delete temp;
            cout << "Deleted " << value << " from the list." << endl;
            return;
        }

        while (temp != nullptr && temp->data != value)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Value " << value << " not found in the list. Cannot delete." << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Deleted " << value << " from the list." << endl;
    }

    void display()
    {
        if (is_empty())
        {
            cout << "Linked list is empty." << endl;
            return;
        }
        cout << "Linked list elements: ";
        Node *current = head;
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
    LinkedList list;
    int choice, value;

    do
    {
        cout << "\nLinked List Operations Menu:" << endl;
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
