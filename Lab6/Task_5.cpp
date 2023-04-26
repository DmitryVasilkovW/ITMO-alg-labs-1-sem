#include <iostream>


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



Node *Bigrotatright(Node *root)
{
	rotateleft(root -> left);
	rotateright(root);
}

Node *Bigrotatleft(Node *root)
{
	rotateright(root -> right);
	rotateleft(root);
}



Node *add(Node *root, int val)
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
	return newbalance(root);
}

Node* del(Node* root, int val)
{
	if (root == NULL) // если пусто вернуть NULL
	{
		return root;
	}
	if (val < root -> key)
	{
		root -> left = del(root -> left, val);
	}
	else if (val > root -> key)
	{
		root -> right = del(root -> right, val);
	}

	else if (root -> left != NULL && root -> right != NULL)
	{
		root -> key = prev(root -> left, val) ->key;
		root -> left = del(root -> left, root -> key);
	}
	else if (root -> left != NULL || root -> right != NULL)
	{
		if (root -> right != NULL)
		{
			root = root -> right;
			return newbalance(root);
		}
		else if (root->left != NULL)
		{
			root = root -> left;
			return newbalance(root);
		}
	}
	else if (root -> right == NULL || root -> left == NULL)
	{
		root = NULL;
		return NULL;
	}
	return newbalance(root);
}



bool Search(Node *root, int val) // поиск
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
	Node *tree = NULL;
	char command;
	int element, number_of_elements;
	std::cin >> number_of_elements;
	for (int i = 0; i < number_of_elements; i ++)
	{
		std::cin >> command;
		if (command == 'A')
		{
			std::cin >> element;
			if(!Search(tree, element))
			{
				tree = add(tree, element);
				std::cout << Balance2(tree) << "\n";
			}
			else
			{
				std::cout << Balance2(tree) << "\n";
			}
		}
		else if (command == 'D')
		{
			std::cin >> element;
			if (Search(tree, element))
			{
				tree = del(tree, element);
			}
			if(tree == NULL)
			{
				std::cout << 0 << "\n";
			}
			if (tree != NULL)
			{
				std::cout << Balance2(tree) << "\n";
			}
		}
		else if (command == 'C')
		{
			std::cin >> element;
			if (Search(tree, element))
			{
				std::cout << 'Y' << "\n";
			}
			else
			{
				std::cout << 'N' << "\n";
			}
		}
	}
	return 0;
}
