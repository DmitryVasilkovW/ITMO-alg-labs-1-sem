#include <stdio.h>

int main()
{
    int lines, columns, people, number_of_people, element1, apnd =  -1, key, before, load_capacity = 0, weight = 0, key1, before1;
    scanf("%d %d", &columns, &lines);
    int arry_elements[lines * columns];
    for (int i = 0; i < columns; i ++)
    {
        for (int j = 0; j < lines; j ++)
        {
            apnd ++;
            scanf("%d ", &element1);
            arry_elements[apnd] = element1;
        }
    }
    scanf("%d", &number_of_people);
    int arry_of_people[number_of_people];
    for (int i = 0; i < number_of_people; i ++)
    {
        scanf("%d", &people);
        arry_of_people[i] = people;
    }
    for (int i = 1; i < lines * columns; i ++)
        {
            key = arry_elements[i];
            before = i - 1;
            while (arry_elements[before] > key && before + 1 > 0)
            {
                arry_elements[before + 1] = arry_elements[before];
                before  --;
            }
            arry_elements[before + 1] = key;
        }
    for (int i = 1; i < number_of_people; i ++)
        {
            key1 = arry_of_people[i];
            before1 = i - 1;
            while (arry_of_people[before1] > key1 && before1 + 1 > 0)
            {
                arry_of_people[before1 + 1] = arry_of_people[before1];
                before1  --;
            }
            arry_of_people[before1 + 1] = key1;
        }
    while (load_capacity < (lines * columns) && weight < number_of_people)
    {
        if(arry_elements[load_capacity] >= arry_of_people[weight])
        {
            load_capacity ++;
            weight ++;
        }
        else
        {
            load_capacity ++;
        }
    }
    printf("%d\n", weight);
    return 0;
    }

