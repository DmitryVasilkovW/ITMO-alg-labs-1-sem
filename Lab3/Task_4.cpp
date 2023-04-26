#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

struct StackNode
{
    int value;
    StackNode* next;
};

StackNode* newNode(int value)
{
    StackNode* stackNode = new StackNode();
    stackNode->value = value;
    stackNode->next = NULL;
    return stackNode;
}


bool is_not_Empty(StackNode* pointer)
{
    return pointer;
}

void push(StackNode** pointer, int new_data)
{
   StackNode* stackNode = newNode(new_data);
   stackNode->next = *pointer;
   *pointer = stackNode;
}
  
int pop(StackNode** stack)
{
    StackNode* temp = *stack;
   *stack = (*stack) -> next;
   int popped = temp -> value;
   delete (temp);
   return popped;
}

char top(StackNode* pointer) {
    return pointer->value;
}


int main()
{
    string str;
    StackNode* stack = NULL;
    int digit1, digit2, digit;
    getline(cin, str);
    for (int i = 0; i < str.size(); i ++)
    {
        if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != ' ')
        {
            push(&stack, (int)str[i] - '0');
        }
        else if (str[i] == '+')
        {
            digit2 = pop(&stack);
            digit1 = pop(&stack);
            push(&stack, digit1 + digit2);
        }
        else if (str[i] == '-')
        {
            digit2 = pop(&stack);
            digit1 = pop(&stack);
            push(&stack, digit1 - digit2);
        }
        else if (str[i] == '*')
        {
            digit2 = pop(&stack);
            digit1 = pop(&stack);
            push(&stack, digit1 * digit2);
        }
    }
    digit = pop(&stack);
    cout << digit << endl;
    return 0;
}

