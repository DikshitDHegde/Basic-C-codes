#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct Cqueue
{
    int arr[MAX];
    int front,rear;
};

typedef struct Cqueue cq; 
int isFull(cq *a)
{
    return (((a->front)+1)%MAX == a->rear);
}

int isEmpty(cq *a)
{
    return (a->front == a->rear);
}

void enqueue(cq *a)
{
    int i;
    if (isFull(a))
    {
        printf("Circular Queue is Full\n");
        return;
    }
    a->front = ((a->front)+1)%MAX;
    printf("Enter the element to be enqueued :- ");
    scanf("%d",&i);
    a->arr[a->front]=i;
}

void dequeue(cq *a)
{
    if (isEmpty(a))
    {
        printf("Circular Queue is empty\n");
        return;
    }
    a->rear = (a->rear+1)%MAX;
    printf("Dequeued element is %d\n",a->arr[a->rear]);
}

void display(cq a)
{
    int i;
    if (isEmpty(&a))
    {
        printf("Circular Queue is empty\n");
        return;
    }
    if (a.front < a.rear)
    {
        i = a.rear;
        i++;
        while(i<MAX)
        {
            printf("%d\t",a.arr[i]);
            i++;
        }
        i = 0;
        while(i<=a.front)
        {
            printf("%d\t",a.arr[i]);
            i++;
        }
    }
    else
    {
        i = a.rear;
        i++;
        while(i<=a.front)
        {
            printf("%d\t",a.arr[i]);
            i++;
        }
    }
    
}

int main()
{
    int choice;
    cq a;
    a.front= 0;
    a.rear= 0;
    do
    {
        printf("Enter Your Choice\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: enqueue(&a);
                    break;
            case 2: dequeue(&a);
                    break;
            case 3: display(a);
                    printf("\n");
                    break;
            case 4: printf("THANK YOU\n");
                    break;
            default: printf("Entered Invaild choice\n");
                    break;
        }
    }while(choice!=4);
}