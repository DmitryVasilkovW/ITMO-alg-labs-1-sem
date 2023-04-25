#include <stdio.h>
#include <mm_malloc.h>
void merge(int *array, int left, int mid, int right)
{
    int it1 = 0, it2 = 0;

    int *tmp = (int*) malloc((right - left) * sizeof(int));

    while ((left + it1 < mid) && (mid + it2 < right))
    {
        if (array[left + it1] < array[mid + it2])
        {
            tmp[it1 + it2] = array[left + it1];
            it1++;
        } else {
            tmp[it1 + it2] = array[mid + it2];
            it2++;
        }
    }

    while (left + it1 < mid) {
        tmp[it1 + it2] = array[left + it1];
        it1++;
    }

    while (mid + it2 < right) {
        tmp[it1 + it2] = array[mid + it2];
        it2++;
    }

    for(int i = 0; i < it1 + it2; i++) {
        array[left + i] = tmp[i];
    }

    free(tmp);
}

void mergeSortRecursive(int *array, int left, int right)
{
    if (left + 1 >= right) return;

    int mid = (left + right) / 2;

    mergeSortRecursive(array, left, mid);
    mergeSortRecursive(array, mid, right);
    merge(array, left, mid, right);
}


int dif (int *array, int size)
{
    int count = 0;
    for (int i = 1; i < size; i ++)
    {
        if (array[i] == array[i - 1])
        {
            count += 0;
        }
        else
        {
            count ++;
        }
    }
    return count;
}


int main()
{
    int number_of_elements, element, number_of_elements2, count, count1, count2;
    scanf("%d", &number_of_elements);
    int array1[number_of_elements];
    for (int i = 0; i < number_of_elements; i ++)
    {
        scanf("%d", &element);
        array1[i] = element;
    }
    scanf("%d", &number_of_elements2);
    int array2[number_of_elements2];
    for (int i = 0; i < number_of_elements2; i ++)
    {
        scanf("%d", &element);
        array2[i] = element;
    }
    mergeSortRecursive(array1, 0, number_of_elements);
    count = dif(array1, number_of_elements);
    mergeSortRecursive(array2, 0, number_of_elements2);
    count2 = dif(array2, number_of_elements2);
    int array3[number_of_elements + number_of_elements2];
    for (int i = 0; i < number_of_elements; i ++)
    {
        array3[i] = array1[i];
    }
    for (int i = 0; i < number_of_elements2; i ++)
    {
        array3[i + number_of_elements] = array2[i];
    }
    mergeSortRecursive(array3, 0, (number_of_elements + number_of_elements2));
    count1 = dif(array3, number_of_elements + number_of_elements2);
    if (count == count1 && count == count2)
    {
        printf("%s\n", "YES");
    }
    else
    {
        printf("%s\n", "NO");
    }
    return 0;
}
