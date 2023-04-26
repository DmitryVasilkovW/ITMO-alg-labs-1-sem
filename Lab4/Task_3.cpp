# include <iostream>
# include <string>
using namespace std;
int array_of_commands[100000000];
int count_of_element = 0;
int index_for_commands = 0;

void siftup(int array[], int i) 
{
    while (array[i] < array[(i - 1) / 2])
    {
        swap(array[i], array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}


void siftdown(int array[],  int i) 
{
    int j = i;
    if(2 * i + 1 < count_of_element && array[j] > array[2 * i + 1])
    {
        j = 2 * i  + 1;
    }
    if (2 * i  + 2 < count_of_element && array[j] > array[2 * i + 2])
    {
        j = 2 * i + 2;
    }
    if (i != j)
    {
        swap(array[i], array[j]);
        siftdown(array, j);
    }
}

void down(int array[])
{
    for (int i = count_of_element / 2 - 1; i >= 0; i --)
    {
        siftdown(array, i);
    }
}

void decrease(int array[], int x, int y)
{
    int tmp = array_of_commands[x - 1];
    for (int i = 0; i < count_of_element; i ++)
    {
        if (array[i] == tmp)
        {
            array[i] = y;
            siftup(array, i);
            index_for_commands ++;
            array_of_commands[x - 1] = y;
            array_of_commands[index_for_commands] = 1000002;
            break;
        }
    }
}

void push(int array[], int key)
{
    int count = count_of_element + 1;
    array[count - 1] = key;
    siftup(array, count - 1);
    count_of_element ++;
    array_of_commands[index_for_commands] = key;
    index_for_commands ++;
}

void extractmin(int array[])
{
    if (count_of_element == 0)
    {
        cout << '*' <<"\n";
        index_for_commands ++;
    }
    else
    {
        int min = array[0];
        cout << min << "\n";
        array[0] = array[count_of_element - 1];
        count_of_element --;
        siftdown(array, 0);
        array_of_commands[index_for_commands] = 1000002;
        index_for_commands ++;
    }
}

int main()
{
    string command;
    int element, key;
    int array[1000000];
    while (cin >> command)
    {
        if (command.empty())
            break;
        if (command == "extract-min")
        {
            extractmin(array);
        }
        if (command == "push")
        {
            cin >> element;
            push(array, element);
        }
        else if (command == "decrease-key")
        {
            cin >> key >> element;
            decrease(array, key, element);
        }
    }
    return 0;
}
