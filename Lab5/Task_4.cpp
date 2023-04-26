# include <iostream>
# include <string>
struct Node
{
    int key;
    Node *parent;
    Node* left;
    Node* right;
};

bool Search(Node *root, int val)
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

Node *add(Node *root, int val)
{
    if(root == NULL)
    {
        root = new Node;
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
        root -> right = add(root -> right, val);
    }
    else if(root -> key > val)
    {
        root -> left = add(root -> left, val);
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

Node *max(Node* root)
{
    if(root -> right == NULL)
    {
        return root;
    }
    return max(root -> left);
}

Node *del(Node* root, int val_for_delete)
{
    if(root == NULL)
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

Node *next(Node *root, int val)
{
    Node *cur = root, *tmp = NULL;
    while(cur != NULL)
    {
        if (cur->key > val)
        {
            tmp = cur;
            cur = cur->left;
        }
        else
        {
            cur = cur->right;
        }
    }
    return tmp;
}

int main()
{
    Node *root = NULL;
    int element;
    bool trash = true;
    std::string command;
    while (std::cin >> command)
    {
        if (command == "insert") {
            std::cin >> element;
            if (Search(root, element))
            {
                trash = false;
                add(root, element);
            }
            else if (!Search(root, element))
            {
                root = add(root, element);
            }
        }
        if (command == "delete")
        {
            std::cin >> element;
            root = del(root, element);
        }
        if (command == "exists")
        {
            std::cin >> element;
            if(Search(root, element))
            {
                std::cout << "true" << "\n";
            }
            else
            {
                std::cout << "false" << "\n";
            }
        }
        if (command == "next")
        {
            std::cin >> element;
            Node *tmp = next(root, element);
            if (tmp != NULL)
            {
                std::cout << tmp -> key << "\n";
            }
            else
            {
                std::cout << "none" << "\n";
            }
        }
        if (command == "prev")
        {
            std::cin >> element;
            Node *tmp = prev(root, element);
            if (tmp != NULL)
            {
                std::cout << tmp -> key << "\n";
            }
            else
            {
                std::cout << "none" << "\n";
            }
        }
    }
    return 0;
}
