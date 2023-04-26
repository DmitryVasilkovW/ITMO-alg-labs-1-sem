#include <stdio.h>

void merge(int mass_first[], int left, int mid, int right)
{
    int it1 = 0;
    int it2 = 0;
    int tmp1[right - left];
    while ((mid + it2 < right) && (left + it1 < mid))
    {
        if (mass_first[left + it1] < mass_first[mid + it2])
        {
            tmp1[it1 + it2] = mass_first[left + it1];
            it1++;
        }
        else
        {
            tmp1[it1 + it2] = mass_first[mid + it2];
            it2++;
        }
    }
    while (mid + it2 < right)
    {
        tmp1[it1 + it2] = mass_first[mid + it2];
        it2++;
    }
    while (left + it1 < mid)
    {
        tmp1[it1 + it2] = mass_first[left + it1];
        it1++;
    }

    for(int i = 0; i < it1 + it2; i++)
    {
        mass_first[left + i] = tmp1[i];
    }
}

void mergeRecursive(int mass_first[], int left, int right)
{
    
    if(left + 1 >= right) return;

    int mid = (left + right) / 2;

    mergeRecursive(mass_first, left, mid);
    mergeRecursive(mass_first, mid, right);
    merge(mass_first, left, mid, right);
}

int main()
{
    int number_of_elements, element;
    scanf("%d", &number_of_elements);
    int array[number_of_elements];
    for (int i = 0; i <= number_of_elements - 1; i ++)
    {
        scanf("%d", &element);
        array[i] = element;
    }
    mergeRecursive(array, 0, number_of_elements);
    for (int i = 0; i < number_of_elements; i ++)
                {
                    if (i == number_of_elements - 1)
                    {
                        printf("%d\n", array[i]);
                    }
                    else
                    {
                        printf("%d ", array[i]);
                    }
                }
    return 0;
}

