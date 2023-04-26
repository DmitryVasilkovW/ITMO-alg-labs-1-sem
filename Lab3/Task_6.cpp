# include <iostream>
using namespace std;

void bin_SearchL(int array[], int size_of_array, int value)
{
    int it = 0, left, right;
    right = size_of_array;
    left = -1;
    while (right > left + 1)
    {
        it = (left + right) / 2;
        if (array[it] < value)
        {
            left = it;
        }
        else
        {
            right = it;
        }
    }
    if (right < size_of_array && array[right] == value)
    {
        cout << right + 1 << " ";
    }
    else
    {
        cout << - 1 << " ";
    }
}

void bin_SearchR(int array[], int size_of_array, int value)
{
    int it = 0, left, right;
    right = size_of_array;
    left = -1;
    while (right > left + 1)
    {
        it = (left + right) / 2;
        if (array[it] <= value)
        {
            left = it;
        }
        else
        {
            right = it;
        }
    }
    if (left > 0 && array[left] == value)
    {
        cout << left + 1 << "\n";
    }
    else
    {
        cout << - 1 << "\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int  number_of_elements, element, command, number_of_commands, i = 0, j = 0;
    cin >> number_of_elements;
    int array[number_of_elements];
    while (i < number_of_elements)
    {
        cin >> element;
        array[i] = element;
        i = i + 1;
    }
    cin >> number_of_commands;
    while (j < number_of_commands)
    {
        cin >> command;
        bin_SearchL(array, number_of_elements, command);
        bin_SearchR(array, number_of_elements, command);
        j = j + 1;
    }
    return 0;
}

