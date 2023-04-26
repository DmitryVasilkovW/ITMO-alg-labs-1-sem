#include <stdio.h>

int main()
{
    int number_of_elements, key, before, elemtnts;
    scanf("%d", &number_of_elements);
    int arry[number_of_elements];
    for (int i = 0; i < number_of_elements; i ++)
    {
        scanf("%d", &elemtnts);
        arry[i] = elemtnts;
    }
    for (int i = 1; i < number_of_elements; i ++)
    {
        key = arry[i];
        before = i - 1;
        while (arry[before] > key && before + 1 > 0)
        {
            arry[before + 1] = arry[before];
            before  --;
        }
        arry[before + 1] = key;
    }
    for (int i = 0; i < number_of_elements; i ++)
    {
        if (i == number_of_elements - 1)
        {
            printf("%d\n", arry[i]);
        }
        else
        {
            printf("%d ", arry[i]);
        }
    }
    return 0;
}
