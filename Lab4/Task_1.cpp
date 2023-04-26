# include <iostream>

using namespace std;

bool flag = false;

int main()
{
    int number_of_elements, element;
    cin >> number_of_elements;
    int array[number_of_elements];
    for (int i = 1; i < number_of_elements + 1; i ++)
    {
        cin >> element;
        array[i] = element;
    }
    for (int i = 1; i < number_of_elements + 1; i ++)
    {
        if (2 * i < number_of_elements && array[i] > array[2 * i] || (2 * i) + 1 < number_of_elements && array[i] > array[(2 * i) + 1])
        {
            flag = true;
            break;
        }
    }
    if (!flag)
    {
        cout << "YES" << "\n";
    }
    else
    {
        cout << "NO" << "\n";
    }
    return 0;
}
