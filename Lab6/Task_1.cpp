# include <iostream>
# include <vector>
std::vector<std::vector<int>> array(200900, std::vector <int> (4));
void h(int j)
{
	if(j == -1)
	{
		return;
	}
	int tmp_left = 0;
	int tmp_right = 0;
	if (array[j][1] != 0)
	{
		h(array[j][1] - 1);
		tmp_left = array[array[j][1] - 1][3];
	}
	if (array[j][2] != 0)
	{
		h(array[j][2] - 1);
		tmp_right = array[array[j][2] - 1][3];
	}
	if (tmp_left > tmp_right) array[j][3] = 1 + tmp_left;
	else array[j][3] = 1 + tmp_right;
}

int Balancing(int left, int right)
{
	int tmp;
	if (left == 0 && right == 0)
	{
		tmp = 0;
	}
	else if (right != 0 && left == 0)
	{
		tmp = array[right - 1][3];
	}
	else if (left != 0 && right == 0)
	{
		tmp = 0 - array[left - 1][3];
	}
	else if (left != 0 && right != 0)
	{
		tmp = array[right - 1][3] - array[left - 1][3];
	}
	return tmp;
}

int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int K, L, R, number_of_elements;
	std::cin >> number_of_elements;
	for(int i = 0; i < number_of_elements; i ++)
	{
		std::cin >> K >> L >> R;
		array[i][0] = K;
		array[i][1] = L;
		array[i][2] = R;
	}
	h(0);
	for (int i = 0; i < number_of_elements; i ++)
	{
		std::cout << Balancing(array[i][1], array[i][2]) << "\n";
	}
	return 0;
}
