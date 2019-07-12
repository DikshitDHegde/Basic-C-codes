#include<stdio.h>
#include<stdlib.h>

struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
};

typedef struct BST bst;

bst* getNode()
{
    bst* nw;
    nw = (bst*)malloc(sizeof(bst));
    nw->left = NULL;
    nw->right = NULL;
    return nw;
}

bst * Insertion(bst *root, int data)
{
    bst *nw;
    if(root==NULL)
    {
        nw = getNode();
        nw->data = data;
        return nw;
    }
    if(root->data > data)
        root->left = Insertion(root->left,data);
    else if(root->data < data)
        root->right = Insertion(root->right,data);
    else
        printf("Data is already present\n");
    return root;
}
void Search(bst *root,int data)
{
    if(root == NULL)
    {
        printf("Tree is Empty");
        return;
    }
    if(((root->data)>data) && (root->left!=NULL))
        Search(root->left,data);
    else if(((root->data)<data) && (root->right!=NULL))
        Search(root->right,data);
    else if(root->data == data)
    {
        printf("Element found\n");
        return;
    }
    else 
    {
        printf("Element Not found \n");
        return;
    }
}

bst* findMin(bst* root)
{
    if(root->left == NULL && root->right == NULL)
        return root;
    if(root->left == NULL)
        root = findMin(root->right);
    else
        root = findMin(root->left);
    
    return root;
}

bst * Delete(bst *root,int data)
{
    bst* temp;
    if(root == NULL)
    {
        printf("Tree is empty\n");
        return NULL;
    }
    else if(root->data < data && root->right != NULL)
        root->right = Delete(root->right,data);
    else if(root->data > data && root->left != NULL)
        root->left = Delete(root->left,data);
    else if(root->data == data)
    {
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        else if(root->left == NULL)
        {
            temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL)
        {
            temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
             temp = findMin(root->right);
             root->data = temp->data;
             root->right = Delete(root->right,temp->data);
        }
        printf("Data is deleted\n");
    }else
        printf("Data Not found\n");
        
    return root;
}

void Inorder(bst *root)
{
    if (root == NULL)
    {
        printf("Tree is empty");
        return;
    }
    if(root->left!=NULL)
        Inorder(root->left);
    printf("%d\t",root->data);
    if(root->right != NULL)
        Inorder(root->right);
}

void preorder(bst *root)
{
    if(root == NULL)
    {
        printf("Tree is Empty");
        return;
    }
    printf("%d\t",root->data);
    if(root->left!=NULL)
        preorder(root->left);
    if(root->right!=NULL)
        preorder(root->right);
}

void postorder(bst *root)
{
    if(root == NULL)
    {
        printf("Tree is Empty");
        return;
    }
    if(root->left!=NULL)
        postorder(root->left);
    if(root->right!=NULL)
        postorder(root->right);
    printf("%d\t",root->data);
}

int main()
{
    int choice,data;
    bst *root;
    root = NULL;
    do
    {
        printf("Enter your choice\n1.Insert\n2.Inorder Display\n3Preorder Display\n4.Postoreder Display\n5.Search\n6.Delete\n7.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the data to be Inserted:- ");
                    scanf("%d",&data);
                    root = Insertion(root , data);
                    break;
            case 2: Inorder(root);
                    printf("\n");
                    break;
            case 3: preorder(root);
                    printf("\n");
                    break;
            case 4: postorder(root);
                    printf("\n");
                    break;
            case 5: printf("Enter the data to be Searched :- ");
                    scanf("%d",&data);
                    Search(root,data);
                    break;
            case 6: printf("Enter the data to be deleted :- ");
                    scanf("%d",&data);
                    root = Delete(root, data);
                    break;
            case 7: printf("Thank You\n");
                    break;
            default: printf("Invalid Choice\n");
                    break;
        }
    } while (choice!=7);
}