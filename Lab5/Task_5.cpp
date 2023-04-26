# include <iostream>
# include <string>
# include <vector>
std::vector<std::vector<std::string>> array(3, std::vector <std::string> (200900));
struct Node
{
    std::string key;
    Node* left;
    Node* right;
};

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

Node *add(Node *root, std::string val)
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

Node *del(Node* root, std::string val_for_delete) 
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
