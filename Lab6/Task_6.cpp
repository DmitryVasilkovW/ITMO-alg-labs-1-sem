#include <iostream>
#include <vector>
std::vector<std::vector<std::string>> array(2, std::vector <std::string> (200900));
int count = 0;
struct node
{
	char key;
	node* left;
	node* right;
};


node *addch(node *root, char val)
{
	if(root == NULL) 
	{
		root = new node;
		root -> key = val;
		root -> left  = NULL;
		root -> right = NULL;
	}
	else if(val == root -> key) 
	{
		return root;
	}
	else if(root -> key < val)
	{
		root -> right = addch(root -> right, val);
	}
	else if(root -> key > val)
	{
		root -> left = addch(root -> left, val);
	}
	return root;
}




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
	root -> height = (hl > hr ? hl : hr) + 1;
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
	if(root == NULL) 
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

Node *del(Node *root, std::string val)
{
	if (root == NULL)
	{
		return root;
	}
	if (val < root -> key)
	{
		root->left = del(root->left, val);
	}
	else if (val > root -> key)
	{
		root -> right = del(root -> right, val);
	}
	else
	{
		if ((root -> left == NULL) || (root -> right == NULL))
		{
			Node *temp = root -> left ? root->left : root->right;
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else
				*root = *temp;
		}
		else
		{
			Node *temp = min(root -> right);
			root -> key = temp -> key;
			root -> right = del(root -> right, temp -> key);
		}
	}

	if (root == NULL)
	{
		return root;
	}

	root -> height = 1 + std::max(height(root -> left), height(root -> right));
	if (Balance(root) > 1)
	{
		if (Balance(root -> left) >= 0)
		{
			return rotateright(root);
		} else {
			root -> left = rotateleft(root -> left);
			return rotateright(root);
		}
	}
	if (Balance(root) < -1)
	{
		if (Balance(root->right) <= 0)
		{
			return rotateleft(root);
		}
		else
		{
			root -> right = rotateright(root -> right);
			return rotateleft(root);
		}
	}
	return root;
}

bool Search(Node *root, std::string val) 
{
	if (root == NULL)  
	{
		return false;
	}
	if (val == root -> key)
	{
		return true;
	}
	if (root -> key < val)
	{
		return Search(root -> right, val); 
	}
	else if(root -> key > val)
	{
		return Search(root -> left, val);
	}
}

bool Search_ch(node *root, char val) 
{
	if (root == NULL) 
	{
		return false;
	}
	if (val == root -> key)
	{
		return true;
	}
	if (root -> key < val)
	{
		return Search_ch(root -> right, val); 
	}
	else if(root -> key > val)
	{
		return Search_ch(root -> left, val);
	}
}

void number(int j)
{
	node *root = NULL;
	std::string element = array[1][j];
	if (array[1][j].length() == 1)
	{
		count ++;
	}
	else
	{
		for (int i = 0; i < array[1][j].length(); i ++)
		{
			if (!Search_ch(root, element[i]))
			{
				root = addch(root, element[i]);
				count ++;
			}
		}
	}
}


int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	Node *root = NULL;
	std::string element;
	int number_of_elements;
	std::cin >> number_of_elements;
	for (int i = 0; i < number_of_elements; i ++)
	{
		std::cin >> element;
		array[0][i] = element;
	}
	for (int i = 0; i < number_of_elements; i ++)
	{
		if (!Search(root, array[0][i]))
		{
			root = add(root, array[0][i]);
		}
		else
		{
			array[1][i] = array[0][i];
		}
	}
	for (int i = 0; i < number_of_elements; i ++)
	{
		number(i);
	}
	std::cout << count;
	return 0;
}
