#include <iostream>
#include <vector>

std::vector<std::vector<std::string>> array(3, std::vector <std::string> (200900));

struct Node
{
	std::string key;
	Node *left;
	Node *right;
	int height;
};


int height(Node *h)
{
	if (h == NULL)
	{
		return 0;
	}
	return h -> height;
}

void fixheight(Node* root)
{
	int hl = height(root -> left);
	int hr = height(root -> right);
	root -> height = std::max(hl, hr) + 1;
}

Node* rotateright(Node* root)
{
	Node* root1 = root -> left;
	root -> left = root1 -> right;
	root1 -> right = root;
	fixheight(root);
	fixheight(root1);
	return root1;
}

Node* rotateleft(Node* root)
{
	Node* root1 = root -> right;
	root -> right = root1 -> left;
	root1 -> left = root;
	fixheight(root);
	fixheight(root);
	return root1;
}

int Balance(Node *h)
{
	if (h == NULL)
	{
		return 0;
	}
	return height(h -> left) - height(h -> right);
}

Node *add(Node *root, std::string val)
{
	if(root == NULL) // если такого нет, то делаю новый узел в дереве
	{
		root = new Node;
		root -> key = val;
		root -> left  = NULL;
		root -> right = NULL;
		root -> height = 1;
	}
	if (val < root -> key)
	{
		root -> left = add(root -> left, val);
	}
	else if (val > root -> key)
	{
		root -> right = add(root -> right, val);
	}
	else
		return root;
	root -> height = 1 + std::max(height(root -> left), height(root -> right));
	if (Balance(root) > 1)
	{
		if (val < root -> left -> key)
		{
			return rotateright(root);
		}
		else if (val > root -> left -> key)
		{
			root -> left = rotateleft(root -> left);
			return rotateright(root);
		}
	}
	if (Balance(root) < -1)
	{
		if (val > root -> right -> key)
		{
			return rotateleft(root);
		} else if (val < root -> right -> key)
		{
			root -> right = rotateright(root -> right);
			return rotateleft(root);
		}
	}
	return root;
}

Node *min(Node* root)
{
	if(root -> left == NULL)
	{
		return root;
	}
	return min(root -> left);
}

Node *del(Node* root, std::string val_for_delete) // удаление
{
	if(root == NULL) // если пусто, то вернууть корень
	{
		return root;
	}
	if(root -> key < val_for_delete)
	{
		root -> right = del(root -> right, val_for_delete);
	}
	else if(root -> key > val_for_delete)
	{
		root -> left = del(root -> left, val_for_delete);
	}
	else if(root -> left != NULL && root -> right != NULL)
	{
		root -> key = min(root -> right) -> key;
		root -> right = del(root -> right, root -> key);
	}
	else if (root != NULL)
	{
		if (root -> left == NULL)
		{
			root = root -> right;
		}
		else if(root -> left != NULL)
		{
			root = root -> left;
		}
	}
	return root;
}

bool Search(Node *root, std::string val) // поиск
{
	if (root == NULL)  // если
	{
		return false;
	}
	if (val == root -> key)
	{
		return true;
	}
	if (root -> key < val)
	{
		return Search(root -> right, val); // иду в правое дерево
	}
	else if(root -> key > val)
	{
		return Search(root -> left, val);
	}
}

int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	Node *root = NULL;
	Node *tree = NULL;
	std::string  element;
	int count1 = 0, count2 = 0, count3 = 0, number_of_elements;
	std::cin >> number_of_elements;
	for (int i = 0; i < 3; i ++)
	{
		for (int j = 0; j < number_of_elements; j ++)
		{
			std::cin >> element;
			array[i][j] = element;
		}
	}
	for (int i = 0; i < number_of_elements; i ++)
	{
		root = add(root, array[0][i]);
		tree = add(tree, array[1][i]);
	}
	for (int i = 0; i < number_of_elements; i ++)
	{
		if(!Search(tree, array[2][i]) && !Search(root, array[2][i]))
		{
			count3 += 3;
		}
		else if(!Search(tree, array[2][i]) || !Search(root, array[2][i]))
		{
			if(!Search(tree, array[2][i]) && Search(root, array[2][i]))
			{
				count3 ++;
			}
			else if(Search(tree, array[2][i]) && !Search(root, array[2][i]))
			{
				count3 ++;
			}
		}
		else if(Search(tree, array[2][i]) && Search(root, array[2][i]))
		{
			count3 += 0;
		}
	}
	for (int i = 0; i < number_of_elements; i ++)
	{
		tree = del(tree, array[1][i]);
	}


	for (int i = 0; i < number_of_elements; i ++)
	{
		tree = add(tree, array[2][i]);
	}
	for (int i = 0; i < number_of_elements; i ++)
	{
		if(!Search(tree, array[1][i]) && !Search(root, array[1][i]))
		{
			count2 += 3;
		}
		else if(!Search(tree, array[1][i]) || !Search(root, array[1][i]))
		{
			if(!Search(tree, array[1][i]) && Search(root, array[1][i]))
			{
				count2 ++;
			}
			else if(Search(tree, array[1][i]) && !Search(root, array[1][i]))
			{
				count2 ++;
			}
		}
		else if(Search(tree, array[1][i]) && Search(root, array[1][i]))
		{
			count2 += 0;
		}
	}
	for (int i = 0; i < number_of_elements; i ++)
	{
		tree = del(tree, array[2][i]);
		root = del(root, array[0][i]);
	}


	for (int i = 0; i < number_of_elements; i ++)
	{
		root = add(root, array[1][i]);
		tree = add(tree, array[2][i]);
	}
	for (int i = 0; i < number_of_elements; i ++)
	{
		if(!Search(tree, array[0][i]) && !Search(root, array[0][i]))
		{
			count1 += 3;
		}
		else if(!Search(tree, array[0][i]) || !Search(root, array[0][i]))
		{
			if(!Search(tree, array[0][i]) && Search(root, array[0][i]))
			{
				count1 ++;
			}
			else if(Search(tree, array[0][i]) && !Search(root, array[0][i]))
			{
				count1 ++;
			}
		}
		else if(Search(tree, array[0][i]) && Search(root, array[0][i]))
		{
			count1 += 0;
		}
	}
	std::cout << count1 << " " << count2 << " " << count3;
	return 0;
}
