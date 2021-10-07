#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};


struct node *createNode(struct node *ptr, int data)
{
    ptr->data=data;
    ptr->left=NULL;
    ptr->right=NULL;

    return ptr;
}

void postorderTraversal(struct node *ptr)
{
    if(ptr != NULL)
    {
        postorderTraversal(ptr->left);
        postorderTraversal(ptr->right);
        printf("%d ",ptr->data);
    }
}
int main()
{
    struct node *root, *ptr2, *ptr3, *ptr4, *ptr5,*ptr6, *ptr7;
    root = (struct node *)malloc(sizeof(struct node));
    ptr2 = (struct node *)malloc(sizeof(struct node));
    ptr3 = (struct node *)malloc(sizeof(struct node));
    ptr4 = (struct node *)malloc(sizeof(struct node));
    ptr5 = (struct node *)malloc(sizeof(struct node));
    ptr6 = (struct node *)malloc(sizeof(struct node));
    ptr7 = (struct node *)malloc(sizeof(struct node));

    root = createNode(root, 1);
    ptr2 = createNode(ptr2, 2);
    ptr3 = createNode(ptr3, 3);
    ptr4 = createNode(ptr4, 4);
    ptr5 = createNode(ptr5, 5);
    ptr6 = createNode(ptr6, 6);
    ptr7 = createNode(ptr7, 7);

    root->left=ptr2;
    root->right=ptr3;
    ptr2->left=ptr4;
    ptr2->right=ptr5;
    ptr3->left=ptr6;
    ptr3->right=ptr7;

    postorderTraversal(root);
    return 0;
}

