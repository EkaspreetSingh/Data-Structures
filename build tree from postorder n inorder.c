#include <stdio.h>
#include <stdlib.h>

int index =4;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void display(struct node *ptr)
{
    if(ptr != NULL)
    {
        display(ptr->left);
        printf("%d ",ptr->data);
        display(ptr->right);
    }
}

int findPos(int inorder[], int start, int finish, int val)
{
    for(int i=start; i<finish; i++)
    {
        if(inorder[i]==val)
            return i;
    }
}
struct node *createNewNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
};

struct node *buildTree(int inorder[], int postorder[], int begin, int end)
{
    if(begin>end)
    {
        return NULL;
    }
    int val = postorder[index];
    index--;
    struct node *newNode = createNewNode(val);

    if(begin == end)
    {
        return newNode;
    }

    int pos = findPos(inorder, begin, end, val);

    newNode->right = buildTree(inorder, postorder, pos+1, end);
    newNode->left = buildTree(inorder, postorder, begin, pos-1);
};
int main()
{
    int inorder[] ={4,2,1,5,3};
    int postorder[] ={4, 2, 5, 3, 1};
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head = buildTree(inorder, postorder, 0, 4);
    display(head);
    return 0;
}
