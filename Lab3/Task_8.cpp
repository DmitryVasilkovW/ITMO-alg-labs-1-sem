# include <iostream>
using namespace std;

long  SUM(long  array[], long  number_of_elements)
{
    long  sum = 0;
    for (int i = 0; i < number_of_elements; i ++)
    {
        sum += array[i];
    }
    return sum;
}

long  Max(long  array[], long  number_of_elements)
{
    long  max = -56;
    for (int i = 0; i < number_of_elements; i ++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

bool Mid(long array[], long  number_of_elements, long  number_of_delimiters, long mid) // проверка мида
{
    long count = 0;
    long sum = 0;
    for (int i = 0; i < number_of_elements; i ++)
    {
        sum += array[i];
        if (sum > mid)
        {
            count ++;
            sum = array[i];
        }
    }
    if (count < number_of_delimiters)
    {
        return true;
    }
    else
    {
        return false;
    }
}

long bin(long array[], long number_of_delimiters, long number_of_elements) // поиск мида
{
    long left = Max(array, number_of_elements);
    long  right = SUM(array, number_of_elements);
    long answer = 0;
    while (left <= right)
    {
        long mid = (left + right) / 2;
        if (Mid(array, number_of_elements, number_of_delimiters, mid) == true)
        {
            answer = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return answer;
}
int main()
{
    long number_of_elements, number_of_delimiters, element, sum = 0, counter = 0, j = 1;
    cin >> number_of_elements >> number_of_delimiters;
    long array[number_of_elements];
    for (int i = 0; i < number_of_elements; i ++)
    {
        cin >> element;
        array[i] = element;
    }
    long summ = bin(array, number_of_delimiters, number_of_elements);
    bool arr[number_of_elements];
    for (int i = 0; i < number_of_elements; i ++)
    {
        arr[i] = false;
    }
    counter = 0;
    for (int i = 0; i < number_of_elements; i ++)  // дробление 1
    {
        sum += array[i];
        if (sum > summ) {
            arr[i] = true;
            counter++;
            sum = array[i];
        }
    }
    sum = 0;
    while (counter != number_of_delimiters - 1) // дробление 2, если нужно
    {
        if (!arr[j])
        {
            arr[j] = true;
            counter ++;
        }
        j ++;
    }
    for (int i = 0; i < number_of_elements; i ++)
    {
        if (arr[i])
        {
            cout << i << " ";
        }
    }
    return 0;
}


