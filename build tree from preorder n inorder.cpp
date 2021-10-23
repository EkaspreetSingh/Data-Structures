#include <iostream>

using namespace std;

//int index =0;
struct node
{
    int c;
    struct node *left;
    struct node *right;
};

struct node *createNewNode(int data)
{
    struct node *newNode;
    newNode= (struct node *)malloc(sizeof(struct node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->c = data;

    return newNode;
}

int search(int inorder[], int start, int end, int curr)
{
    for(int i=start; i<end; i++)
    {
        if(inorder[i] == curr)
            return i;
    }
}

void display(struct node *root)
{
    if(root != NULL)
    {
        display(root->left);
        printf(" %d", root->c);
        display(root->right);

    }
}
struct node *buildTree(int inorder[], int preorder[], int start, int end)
{
    static int index=0;

    if(start>end)
        return NULL;

    int current = preorder[index];
    index++;

    struct node *newNode = createNewNode(current);

    if(start==end)
        return newNode;

    int pos= search(inorder, start, end, current);

    newNode->left = buildTree(inorder, preorder, start, pos-1);
    newNode->right = buildTree(inorder, preorder, pos+1, end);
    return newNode;
}
int main()
{
    int inorder[] ={4,2,1,5,3};
    int preorder[] ={1,2,4,3,5};
    struct node *root;
    root = (struct node *)malloc(sizeof(struct node));
    root = buildTree(inorder, preorder, 0, 4);
    display(root);
    return 0;
}
