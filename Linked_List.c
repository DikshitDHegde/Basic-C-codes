#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* getNode()
{
    struct Node* nw;
    nw = (struct Node *)malloc(1*sizeof(struct Node));
    nw->next = NULL;
    return nw;
}

struct Node * Insert(struct Node *head)
{
    struct Node  *nw, *prev;
    int data;
    nw = getNode();

    if(nw == NULL)
    {
        printf("Memory is Full\n");
        return head;
    }

    if(head == NULL)
    {
        printf("Enter Data :- ");
        scanf("%d",&data);
        nw->data = data;
        head = nw;
        return head;
    }

    prev = head;

    while(prev->next != NULL)
    {   
        prev = prev->next;
    }

    prev->next = nw;
    printf("Enter Data :- ");
    scanf("%d",&data);
    nw->data = data;

    return head;    

}

struct Node * Insertion_point(struct Node *head)
{
    struct Node  *nw, *prev;
    int data,count,index;
    nw = getNode();
    count = 1;
    if(nw == NULL)
    {
        printf("Memory is Full\n");
        return head;
    }

    if(head == NULL)
    {
        printf("Enter Data :- ");
        scanf("%d",&data);
        nw->data = data;
        head = nw;
        return head;
    }
    
    printf("Enter the index :- ");
    scanf("%d",&index);
    prev = head;
    while((count+1)!=index && prev->next!=NULL)
    {
        prev = prev->next;
        count++;
    }
    printf("Enter Data :- ");
    scanf("%d",&data);
    nw->data = data;
    nw->next = prev->next;
    prev->next = nw;
    return head;
}

void display(struct Node *head)
{
    struct Node *curr;
    curr = head;

    if(head==NULL)
    {
        printf("List is Empty\n");
        return;
    }

    while(curr!=NULL)
    {
        printf("%d\t",curr->data);
        curr = curr->next;
    }

    printf("\n");
}

struct Node * Delete_data(struct Node *head)
{
    struct Node *prev, *curr;
    int data;
    if(head == NULL)
    {
        printf("List is Empty\n");
        return head;
    }

    printf("Enter the data to be deleted:- ");
    scanf("%d",&data);

    if(head->next == NULL)
    {
        if(head->data == data);
        {
            free(head);
            return NULL;
        }    
        printf("Data Not found\n");
        return head;
    }

    prev = NULL;
    curr = head;
    while(curr->next!=NULL)
    {
        if (curr->data==data)
        {
            prev->next = curr->next;
            printf("Data is Deleted\n");
            free(curr);
            return head;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Data not found\n");
    return head;
}

struct Node * Delete(struct Node *head)
{
    struct Node *prev,*curr;
    if(head == NULL)
    {
        printf("List is Empty\n");
        return head;
    }

    if(head->next == NULL)
    {
        printf("deleted element is %d\n",head->data);
        head = head->next;
        return head;
    }

    curr = head;
    prev = NULL;

    while(curr->next!=NULL)
    {
        prev = curr;
        curr = curr->next;
    }

    printf("deleted element is %d\n",curr->data);
    free(curr);
    prev->next = NULL;

    return head;
}


int main()
{
    int choice;
    struct Node *head;
    head = NULL;
    do
    {
        printf("Enter your choice\n1.Insert\n2.Insertion at a particular index\n3.Delete\n4.Delete Particular data\n5.Display\n6.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: head = Insert(head);
                    break;
            case 2: head = Insertion_point(head);
                    break;
            case 3: head = Delete(head);
                    break;
            case 4: head = Delete_data(head);
                    break;            
            case 5: display(head);
                    break;
            case 6: printf("THANK YOU\n");
                    break;
            default: printf("Invalid Choice\n");
                    break;
        }
    } while (choice!=6);
    
}