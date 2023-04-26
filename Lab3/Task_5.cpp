#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

struct StackNode
{
    int value;
    int maximum;
    StackNode* next;
};

StackNode* newNode(int value, int maximum)
{
    StackNode* stackNode = new StackNode();
    stackNode->value = value;
    stackNode->maximum = maximum;
    stackNode->next = NULL;
    return stackNode;
}


bool is_not_Empty(StackNode* pointer)
{
    return pointer;
}

void push(StackNode** pointer, int new_data, int new_max)
{
   StackNode* stackNode = newNode(new_data, new_max);
   stackNode->next = *pointer;
   *pointer = stackNode;
}
  
void pop(StackNode** pointer)
{
   StackNode* temp = *pointer;
   *pointer = (*pointer)->next;
   delete temp;
}

int top_max(StackNode* pointer)
{
    int max = pointer->maximum;
    return max;
}


int main()
{
    int number_of_commands;
    int digit, i = 0;
    string command;
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    StackNode* stack = NULL;
    cin >> number_of_commands;
    while (i < number_of_commands)
    {
        cin >> command;
        i ++;
        if (command == "+")
            {
                cin >> digit;
                if (!is_not_Empty(stack))
                {
                    push(&stack, digit, digit);
                }
                if (digit > top_max(stack))
                {
                    push(&stack, digit, digit);
                }
                else 
                {
                    push(&stack, digit, top_max(stack));
                }
            }
            else if (command == "-")
            {
                pop(&stack);
            }
            else if (command == "max")
            {
                cout << top_max(stack) << "\n";
            }
    }
    return 0;
}
