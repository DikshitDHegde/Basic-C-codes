#include<stdio.h>
#include<stdlib.h>

struct Doqueue
{
    int data;
    struct Doqueue *right;
    struct Doqueue *left;
};

typedef struct Doqueue dq;

dq* getNode()
{
    dq *nw;
    nw = (dq *)malloc(1*sizeof(dq));
    nw->left = NULL;
    nw->right = NULL;
    return nw;
}

dq * Insert_right(dq *head)
{
    dq *curr,*nw;
    int data;
    nw = getNode();
    if (nw == NULL)
    {
        printf("Memory is full\n");
        return head;
    }
    printf("Enter the data to be entered :- ");
    scanf("%d",&data);
    nw->data = data;
    if(head == NULL)
    {
        head = nw;
        return head;
    }
    curr = head;
    while(curr->right!=NULL)
    {
        curr = curr->right;
    }
    curr->right = nw;
    nw->left = curr;

    return head;
}

dq * Insert_left(dq *head)
{
    dq *nw;
    int data;
    nw = getNode();
    if (nw == NULL)
    {
        printf("Memory is full\n");
        return head;
    }
    printf("Enter the data to be entered :- ");
    scanf("%d",&data);
    nw->data = data;
    if(head == NULL)
    {
        head = nw;
        return head;
    }
    nw->right = head;
    head->left = nw;
    return nw;
}

dq* Delete_Right(dq *head)
{
    dq *prev,*curr;
    if(head==NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    if(head->right==NULL)
    {
        printf("Deleted data is %d\n",head->data);
        free(head);
        return NULL;
    }
    prev = NULL;
    curr = head;
    while(curr->right!=NULL)
    {
        prev= curr;
        curr = curr->right;
    }
    printf("Deleted data is %d\n",curr->data);
    free(curr);
    prev->right=NULL;
    return head;
}

dq* Delete_Left(dq *head)
{
    dq *curr;
    if(head==NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    if(head->right==NULL)
    {
        printf("Deleted data is %d\n",head->data);
        free(head);
        return NULL;
    }
    curr = head;
    head = head->right;
    printf("Deleted data is %d\n",curr->data);
    free(curr);
    return head;
}

void display(dq *head)
{
    dq *curr;
    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    curr = head;
    while(curr!=NULL)
    {
        printf("%d\t",curr->data);
        curr = curr->right;
    }
    printf("\n");
}

int main()
{
    int choice;
    dq *head;
    head = NULL;
    do
    {
        printf("Enter your choice\n1.Insert Right\n2.Insert Left\n3.Delete right\n4.Delete Left\n5.Display\n6.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: head = Insert_right(head);
                    break;
            case 2: head = Insert_left(head);
                    break;            
            case 3: head = Delete_Right(head);
                    break;
            case 4: head = Delete_Left(head);
                    break;
            case 5: display(head);
                    break;
            case 6: printf("Thank You\n");
                    break;
            default: printf("Invalid choice\n");
                    break;
        }
    } while (choice!=6);
}