// Implement Array and write a menu driven program to perform all the operation on array elements.

#include <iostream>
using namespace std;

class Menu
{
public:
    int array[100];
    int n;

    void insertatbeg()
    {
        int num;

        cout << "\nEnter the element to insert at [0] index:";
        cin >> num;

        for (int i = n; i > 0; i--)
        {
            array[i] = array[i - 1];
        }

        array[0] = num;
        n++;

        cout << "\nElements after Insertion:" << endl;
        display();
    }

    void insertatend()
    {
        int num;

        cout << "\nEnter the element to insert at [" << n << "] index:";
        cin >> num;

        array[n] = num;
        n++;

        cout << "\nElements after Insertion:" << endl;
        display();
    }

    void insertatindex()
    {
        int pos, num;

        cout << "\nEnter the index: ";
        cin >> pos;

        if (pos < 0 || pos > n)
        {
            cout << "Invalid index. Cannot insert element." << endl;
            return;
        }

        cout << "\nEnter the element to insert at index " << pos << ": ";
        cin >> num;

        for (int i = n; i > pos; i--)
        {
            array[i] = array[i - 1];
        }

        array[pos] = num;
        n++;

        cout << "\nElements after Insertion:" << endl;
        display();
    }

    void insertbeforeval()
    {
        int val, num;

        cout << "\nEnter the Value before which to insert: ";
        cin >> val;

        int pos = -1;

        for (int i = 0; i < n; i++)
        {
            if (array[i] == val)
            {
                pos = i;
                break;
            }
        }

        if (pos == -1)
        {
            cout << "Value not found. Cannot insert before." << endl;
            return;
        }

        cout << "\nEnter the element to insert before " << val << ": ";
        cin >> num;

        for (int i = n; i > pos; i--)
        {
            array[i] = array[i - 1];
        }

        array[pos] = num;
        n++;

        cout << "\nElements after Insertion:" << endl;
        display();
    }

    void insertafterval()
    {
        int val, num;

        cout << "\nEnter the Value after which to insert: ";
        cin >> val;

        int pos = -1;

        for (int i = 0; i < n; i++)
        {
            if (array[i] == val)
            {
                pos = i;
                break;
            }
        }

        if (pos == -1)
        {
            cout << "Value not found. Cannot insert after." << endl;
            return;
        }

        cout << "\nEnter the element to insert after " << val << ": ";
        cin >> num;

        for (int i = n; i > pos + 1; i--)
        {
            array[i] = array[i - 1];
        }

        array[pos + 1] = num;
        n++;

        cout << "\nElements after Insertion:" << endl;
        display();
    }

    void deletebyval()
    {
        int val;

        cout << "\nEnter the Value to delete: ";
        cin >> val;

        int pos = -1;

        for (int i = 0; i < n; i++)
        {
            if (array[i] == val)
            {
                pos = i;
                break;
            }
        }

        if (pos == -1)
        {
            cout << "Value not found. Cannot delete." << endl;
            return;
        }

        for (int i = pos; i < n - 1; i++)
        {
            array[i] = array[i + 1];
        }

        n--;

        cout << "\nElements after Deletion:" << endl;
        display();
    }

    void deletebeforeval()
    {
        int val;

        cout << "\nEnter the Value before which to delete: ";
        cin >> val;

        int pos = -1;

        for (int i = 0; i < n; i++)
        {
            if (array[i] == val)
            {
                pos = i;
                break;
            }
        }

        if (pos <= 0)
        {
            cout << "Value not found or it's the first element. Cannot delete before." << endl;
            return;
        }

        for (int i = pos - 1; i < n - 1; i++)
        {
            array[i] = array[i + 1];
        }

        n--;

        cout << "\nElements after Deletion:" << endl;
        display();
    }

    void deleteafterval()
    {
        int val;

        cout << "\nEnter the Value after which to delete: ";
        cin >> val;

        int pos = -1;

        for (int i = 0; i < n; i++)
        {
            if (array[i] == val)
            {
                pos = i;
                break;
            }
        }

        if (pos == -1 || pos == n - 1)
        {
            cout << "Value not found or it's the last element. Cannot delete after." << endl;
            return;
        }

        for (int i = pos + 1; i < n - 1; i++)
        {
            array[i] = array[i + 1];
        }

        n--;

        cout << "\nElements after Deletion:" << endl;
        display();
    }

    void display()
    {
        cout << "\nElements:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cout << "\nEnter the number of elements:";
    cin >> n;

    Menu oprs;
    oprs.n = n;

    cout << "\nEnter the elements:";

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the " << i << "th element:";
        cin >> oprs.array[i];
    }

    cout << "\nElements:";
    oprs.display();

    int cho;
    char choo;

    do
    {
        cout << "\nEnter the CHOICE: ";
        cout << "\n1. Insert at index";
        cout << "\n2. Insert at beginning";
        cout << "\n3. Insert at end";
        cout << "\n4. Insert before value";
        cout << "\n5. Insert after value";
        cout << "\n6. Delete by value";
        cout << "\n7. Delete before value";
        cout << "\n8. Delete after value";
        cout << "\n9. Display";
        cout << "\n10. Exit" << endl;
        cin >> cho;

        switch (cho)
        {
        case 1:
            oprs.insertatindex();
            break;
        case 2:
            oprs.insertatbeg();
            break;
        case 3:
            oprs.insertatend();
            break;
        case 4:
            oprs.insertbeforeval();
            break;
        case 5:
            oprs.insertafterval();
            break;
        case 6:
            oprs.deletebyval();
            break;
        case 7:
            oprs.deletebeforeval();
            break;
        case 8:
            oprs.deleteafterval();
            break;
        case 9:
            oprs.display();
            break;
        case 10:
            cout << "\nExiting...";
            return 0;
        default:
            cout << "\nInvalid choice. Please enter a valid choice.";
            break;
        }

        cout << "\nPerform the Operations Again(y/n):";
        cin >> choo;
    } while (choo == 'y' || choo == 'Y');

    return 0;
}
