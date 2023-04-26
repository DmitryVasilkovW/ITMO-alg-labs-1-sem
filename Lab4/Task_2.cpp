#include <iostream>
using namespace std;


void heapify(int array[], int i, int size) 
{
    int left = (2 * i + 1);
    int right = (2 * i + 2);
    int largest = i;
    if (left < size && array[left] > array[largest])
    {
        largest = left;
    }
    if (right < size && array[right] > array[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(array[i], array[largest]);
        heapify(array, largest, size);
    }
}

int pop(int array[], int size) 
{
    int top = array[0];
    array[0] = array[size - 1];
    heapify(array, 0, size - 1);
    return top;
}

void Heap(int array[], int size)  
{
    int i = (size - 2) / 2;
    while (i >= 0)
    {
        heapify(array, i --, size);
    }
}

void heapsort(int array[], int size) 
{
    Heap(array, size);
    while (size > 0)
    {
        array[size - 1] = pop(array, size);
        size --;
    }
}


int main()
{
    int number_of_elements, element;
    cin >> number_of_elements;
    int array[number_of_elements];
    for (int i = 0; i < number_of_elements; i ++)
    {
        cin >> element;
        array[i] = element;
    }
    heapsort(array, number_of_elements);

    for (int i = 0; i < number_of_elements; i ++)
    {
        if (i == number_of_elements -  1)
        {
            cout << array[i] << "\n";
            break;
        }
        cout << array[i] << " ";
    }

    return 0;
}
