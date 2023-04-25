#include <stdio.h>

int partition(int *arr, int start, int end)
{
    int pivot = arr[end];
    int key1, key2, key3, key4;
    int i = start;
    i --;
 
    for (int j = start; j <= end - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i ++;
            key1 = arr[i];
            key2 = arr[j];
            arr[i] = key2;
            arr[j] = key1;
        }
    }
    key3 = arr[i + 1];
    key4 = arr[end];
    arr[i + 1] = key4;
    arr[end] = key3;
    return (i + 1);
}


void quickSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int pi = partition(arr, start, end);
        quickSort(arr, start, pi - 1);
        quickSort(arr, pi + 1, end);
    }
}

int main()
{
    int number_of_elements, element;
    scanf("%d", &number_of_elements);
    int aray[number_of_elements];
    for (int i = 0; i < number_of_elements; i ++)
    {
        scanf("%d", &element);
        aray[i] = element;
    }
    quickSort(aray, 0, number_of_elements - 1);
    for (int i = 0; i < number_of_elements; i ++)
    {
        if (i == number_of_elements - 1)
        {
            printf("%d\n", aray[i]);
        }
        else
        {
            printf("%d ", aray[i]);
        }
    }
}
