#include <iostream>
#include <string>
using namespace std;
int phases;
int counterr = 0;
int number_of_elements;
void countSort(string arr[], int exp)
{
    string output[number_of_elements];
    int i, count[1000] = {0};

    for (i = 0; i < number_of_elements; i++)
    {
        count[arr[i][exp]]++;
    }
    for (i = 1; i < 1000; i++)
    {
        count[i] += count[i - 1];
    }
    for (i = number_of_elements - 1; i >= 0; i --)
    {
        output[count[arr[i][exp]] - 1] = arr[i];
        count[arr[i][exp]]--;
    }

    for (i = 0; i < number_of_elements; i++)
    {
        arr[i] = output[i];
    }
}


void radixsort(string arr[], int length)
{
    for (int exp = length - 1; exp >= 0; exp --)
    {
        if (counterr == phases)                                 
            break;
        counterr ++;
        countSort(arr, exp);
    }
}

int main()
{
    int length;
    cin >> number_of_elements;
    cin >> length;
    cin >> phases;
    string arr[number_of_elements];
    for (int i = 0; i < number_of_elements; i ++)
    {
        cin >> arr[i];
    }
    radixsort(arr, length);
    for (int i = 0; i < number_of_elements; i ++)
    {
        cout << arr[i] << "\n";
    }
    return 0;
}
