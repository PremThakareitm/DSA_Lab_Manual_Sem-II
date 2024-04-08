// Evaluate Postfix Expression using Stack ADT.

#include <iostream>
using namespace std;

class Stack
{
private:
    int top;
    int *arr;
    int capacity;

public:
    Stack(int size)
    {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~Stack()
    {
        delete[] arr;
    }

    bool is_empty()
    {
        return top == -1;
    }

    bool is_full()
    {
        return top == capacity - 1;
    }

    void push(int value)
    {
        if (is_full())
        {
            cout << "Stack overflow. Cannot push element." << endl;
            return;
        }
        arr[++top] = value;
    }

    int pop()
    {
        if (is_empty())
        {
            cout << "Stack underflow. Cannot pop element." << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek()
    {
        if (is_empty())
        {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return arr[top];
    }
};

bool is_operator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int perform_operation(int operand1, int operand2, char op)
{
    switch (op)
    {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        if (operand2 != 0)
            return operand1 / operand2;
        else
        {
            cout << "Error: Division by zero!" << endl;
            exit(1);
        }
    }
    return 0;
}

int evaluate_postfix(char *postfix)
{
    int length = 0;
    while (postfix[length] != '\0')
    {
        length++;
    }

    Stack operands(length);

    for (int i = 0; i < length; i++)
    {
        if (postfix[i] == ' ')
            continue;

        if (isdigit(postfix[i]))
        {
            int operand = 0;
            while (i < length && isdigit(postfix[i]))
            {
                operand = operand * 10 + (postfix[i] - '0');
                i++;
            }
            i--;
            operands.push(operand);
        }
        else if (is_operator(postfix[i]))
        {
            int operand2 = operands.pop();
            int operand1 = operands.pop();

            int result = perform_operation(operand1, operand2, postfix[i]);
            operands.push(result);
        }
    }

    return operands.pop();
}

int main()
{
    char postfix[100];
    cout << "Enter the postfix expression: ";
    cin.getline(postfix, 100);

    int result = evaluate_postfix(postfix);
    cout << "Result of the postfix expression: " << result << endl;

    return 0;
}
