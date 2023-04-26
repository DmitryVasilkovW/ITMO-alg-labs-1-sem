#include <iostream>
#include <vector>

bool flag = true;
std::vector<std::vector<int>> array(200900, std::vector <int> (3));

void check(int i, int min, int max)
{
	if(array[i][0] <= min || array[i][0] >= max)
	{
		flag = false;
		return;
	}
	if(array[i][1] != 0)
	{
		check(array[i][1] - 1, min, array[i][0]);
	}
	if(array[i][2] != 0)
	{
		check(array[i][2] - 1, array[i][0], max);
	}
}

int main()
{
	int number_of_elements, K, L, R;
	std::cin >> number_of_elements;
	if (number_of_elements == 0 || number_of_elements == 1)
	{
		std::cout << "YES"  << "\n";
	}
	else if (number_of_elements > 1)
	{
		for (int i = 0; i < number_of_elements; i ++)
		{
			std::cin >> K >> L >> R;
			array[i][0] = K;
			array[i][1] = L;
			array[i][2] = R;
		}
		check(0, INT_MIN, INT_MAX);
		if (flag)
			std::cout << "YES" << "\n";
		else
			std::cout << "NO" << "\n";
	}
	return 0;
}
