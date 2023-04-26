# include <iostream>
# include <vector>
std::vector<std::vector<int>> array(200900, std::vector <int> (3));
int number_of_elements = 1;
int number_of_elements1;
void tree(int j)
{
    if (number_of_elements == 0)
    {
        return;
    }
    if (array[j][2] == 0) 
    {
        if(array[j][1] == 0)
        {
            array[j][0] = number_of_elements;
            number_of_elements --;
        }
        else
        {
            array[j][0] = number_of_elements;
            number_of_elements --;
        }
    }
    if(array[j][2] != 0) 
    {
        tree(array[j][2] - 1);
        array[j][0] = number_of_elements;
        number_of_elements --;
    }
    if(array[j][1] != 0)
    {
        tree(array[j][1] - 1);
    }
}

int main()
{
    int L, R;
    std::cin >> number_of_elements1;
    number_of_elements = number_of_elements1;
    for (int i = 0; i < number_of_elements1; i ++)
    {
        std::cin >> L >> R;
        array[i][0] = 0;
        array[i][1] = L;
        array[i][2] = R;
    }
    tree(0);
    for (int i = 0; i < number_of_elements1; i ++)
    {
        std::cout << array[i][0] << " ";
    }
    return 0;
}
