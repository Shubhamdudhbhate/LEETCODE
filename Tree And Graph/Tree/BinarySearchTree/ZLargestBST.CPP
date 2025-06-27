#include <iostream>
#include <climits>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

class info
{
public:
    bool BST;
    int size;

    int min, max;

    info(int data)
    {

        BST = 1;
        size = 1;
        min = data;
        max = data;
    }
};

class Solution
{
public:
    info *Find(Node *root, int &Total_size)
    {

        if (!root->left && !root->right)
        { // leafNode

            return new info(root->data);
        }
        else if (!root->left && root->right)
        {

            info *head = Find(root->right, Total_size);

            if (head->BST && head->min > root->data)
            {

                head->size++;
                head->min = root->data;
                Total_size = max(Total_size, head->size);

                return head;
            }
            else
            {

                head->BST = 0;
                return head;
            }
        }
        else if (root->left && root->right)
        {

            info *head = Find(root->left, Total_size);

            if (head->BST && head->max < root->data)
            {
                head->size++;
                head->max = root->data;
                Total_size = max(Total_size, head->size);

                return head;
            }
            else
            {

                head->BST = 0;
                return head;
            }
        }
        else
        {

            info *Lefthead = Find(root->left, Total_size);
            info *Righthead = Find(root->right, Total_size);

            if (Lefthead->BST && Righthead->BST && Lefthead->max < root->data && Righthead->min > root->data)
            {
                info *head = new info(root->data);

                head->size += Lefthead->size + Righthead->size;
                head->min = Lefthead->min;
                head->max = Righthead->max;
            }
            else
            {

                Lefthead->BST = 0;
                return Lefthead;
            }
        }
    }



    int LargestBST(Node*root)
    {

        int Total_size = 0;
        Find(root, Total_size);
        return Total_size;
    }


};