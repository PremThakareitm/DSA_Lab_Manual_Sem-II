// Convert an Infix expression to Postfix expression using stack ADT.

#include<iostream> 
using namespace std;


bool is_operator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return -1;
}

int string_length(char *str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

void string_copy(char *dest, char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void infix_to_postfix(char *infix, char *postfix)
{
    int i = 0, j = 0;
    int length = string_length(infix);

    while (i < length)
    {
        char c = infix[i];

        if (isalnum(c))
        {
            postfix[j++] = c;
            i++;
        }

        else if (c == '(')
        {
            infix[i++];
        }

        else if (c == ')')
        {
            while (infix[i] != '(')
            {
                postfix[j++] = infix[i++];
            }
            i++; 
        }

        else if (is_operator(c))
        {

            while (precedence(c) <= precedence(infix[i]))
            {
                postfix[j++] = infix[i++];
            }
            infix[i++];
        }
    }

    while (infix[i] != '\0')
    {
        postfix[j++] = infix[i++];
    }


    postfix[j] = '\0';
}

int main()
{
    char infix[100], postfix[100];
    cout << "Enter the infix expression: ";
    cin.getline(infix, 100);

    infix_to_postfix(infix, postfix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
