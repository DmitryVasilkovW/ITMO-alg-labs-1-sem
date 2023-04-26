# include <iostream>
# include <vector>
std::vector<int> array(200900);
std::vector<int> array_for_cout(200900);
int it = 0;
int j = 0;
int number_of_elements;

void detour(int min, int max)
{
    int tmp;
    if (array[j] > max || array[j] < min || j == number_of_elements)
    {
        return;
    }
    tmp = array[j];
    j ++;
    detour(min, tmp);
    detour(tmp, max);
    array_for_cout[it] = tmp;
    it ++;
}

int main()
{
    int element;
    std::cin >> number_of_elements;
    for (int i = 0; i < number_of_elements; i ++)
    {
        std::cin >> element;
        array[i] = element;
    }
    detour(INT_MIN, INT_MAX);
    for (int i = 0; i < number_of_elements; i ++)
    {
        std::cout << array_for_cout[i] << " ";
    }
    return 0;
}
