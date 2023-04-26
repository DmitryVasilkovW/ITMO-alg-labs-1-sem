#include <iostream>
#include <vector>
std::vector<std::vector<int>> arr(200900, std::vector <int> (3));
int counter = 2;
int counter1;

struct Node
{
	int key;
	Node *left;
	Node *right;
	int height;
};

Node *prev(Node *root, int val)
{
	Node *cur = root, *tmp = NULL;
	while(cur != NULL)
	{
		if(cur -> key < val)
		{
			tmp = cur;
			cur = cur -> right;
		}
		else
		{
			cur = cur -> left;
		}
	}
	return tmp;
}

int height(Node *h)
{
	if (h == NULL)
	{
		return 0;
	}
	return h -> height;
}

Node *min(Node* root)
{
	if(root -> left == NULL)
	{
		return root;
	}
	return min(root -> left);
}

Node *max(Node* root)
{
	if(root -> right == NULL)
	{
		return root;
	}
	return max(root -> left);
}

Node *rotateright(Node *root)
{
	Node *root2 = root -> left;
	Node *tmp = root2 -> right;
	root2 -> right = root;
	root -> left = tmp;
	root -> height = std::max(height(root -> left), height(root -> right)) + 1;
	root2 -> height = std::max(height(root2 -> left), height(root2 -> right)) + 1;
	return root2;
}

Node *rotateleft(Node *root)
{
	Node *root2 = root -> right;
	Node *tmp = root2 -> left;
	root2 -> left = root;
	root -> right = tmp;
	root -> height = std::max(height(root->left), height(root->right)) + 1;
	root2 -> height = std::max(height(root2->left), height(root2->right)) + 1;
	return root2;
}


int Balance2(Node *h)
{
	if (h == NULL)
	{
		return 0;
	}
	else if (h -> right != NULL && h -> left == NULL)
	{
		return height(h->right);
	}
	else if (h -> right == NULL && h -> left != NULL)
	{
		return 0 - height(h->left);
	}
	else
	{
		return height(h->right) - height(h->left);
	}
}

void fixheight(Node* root)
{
	int hl = height(root -> left);
	int hr = height(root -> right);
	root -> height = std::max(hl, hr) + 1;
}

Node* newbalance(Node* root)
{
	fixheight(root);
	if( Balance2(root) > 1 )
	{
		if(Balance2(root -> right) < 0 )
			root -> right = rotateright(root -> right);
		return rotateleft(root);
	}
	if( Balance2(root) < -1 )
	{
		if( Balance2(root -> left) > 0  )
			root -> left = rotateleft(root -> left);
		return rotateright(root);
	}
	return root;
}

Node *add(Node *root, int j)
{
	root = new Node;
	root -> key = arr[j][0];
	root -> left = NULL;
	root -> right = NULL;
	root -> height = 1;
	if (arr[j][1] - 1 != -1)
	{
		root -> left = add(root -> left, arr[j][1] - 1);
	}
	if (arr[j][2] - 1 != -1)
	{
		root -> right = add(root -> right, arr[j][2] - 1);
	}
	return newbalance(root);
}


void cout(Node *root, int h)
{
	if (root == NULL)
	{
		return;
	}
	if (h == 1)
	{
		if ((root -> left == NULL) && (root -> right == NULL))
		{
			std::cout << root -> key << " " << 0 << " " << 0 << "\n";
		}
		else if ((root -> left != NULL) && (root -> right != NULL))
		{
			std::cout << root -> key << " " << counter << " " << counter + 1 << "\n";
			counter += 2;
		}
		else if ((root -> left == NULL) && (root -> right != NULL))
		{
			std::cout << root -> key << " " << 0 << " " << counter << "\n";
			counter++;
		}
		else if ((root -> left != NULL) && (root -> right == NULL))
		{
			std::cout << root -> key << " " << counter << " " << 0 << "\n";
			counter++;
		}
	}
	else
	{
		cout(root -> left, h - 1);
		cout(root -> right, h - 1);
	}
}


int main()
{
	int number_of_element, key, left, right, h;
	std::cin >> number_of_element;
	Node *tree = NULL;
	for (int i = 0; i < number_of_element; i++)
	{
		std::cin >> key >> left >> right;
		arr[i][0] = key;
		arr[i][1] = left;
		arr[i][2] = right;
	}
	tree = add(tree, 0);
	h = height(tree) + 1;
	std::cout << number_of_element << "\n";
	for (int i = 0; i < h; i ++)
	{
		cout(tree, i);
	}
	return 0;
}
