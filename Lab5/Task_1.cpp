# include<iostream>
int max = 0;
void h(int array[][3], int j, int count)
{
    if(j == -1)
    {
        return;
    }
    count ++;
    if (count > max) max = count;
    h(array, array[j][1] - 1, count);
    h(array, array[j][2] - 1, count);
}

int main()
{
    int K, L, R, number_of_elements;
    std::cin >> number_of_elements;
    int array[number_of_elements][3];
    if (number_of_elements == 1)
    {
        std::cout << 1;
    }
    else if(number_of_elements == 0)
    {
        std::cout << 0;
    }
    else
    {
        for(int i = 0; i < number_of_elements; i ++)
        {
            std::cin >> K >> L >> R;
            array[i][0] = K;
            array[i][1] = L;
            array[i][2] = R;
        }
        h(array, 0, 0);
        std::cout << max;
    }
    return 0;
}
