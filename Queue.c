#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct queue
{
    int arr[MAX];
    int rear;
    int front;
};

int isFull(struct queue a)
{
    return (a.front == MAX-1);
}

int isEmpty(struct queue a)
{
    return (a.rear>a.front);
}

void push(struct queue *a)
{
    int i;
    if(isFull(*a))
    {
        printf("Queue is full\n");
        return;
    }   
    printf("Enter the element to be pushed:- ");
    scanf("%d",&i);
    a->front++;
    a->arr[a->front]=i;
}

void pop(struct queue *a)
{
    int i;
    if(isEmpty(*a))
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("Popped Element is %d\n",a->arr[a->rear]);
    a->rear++;
}

void display(struct queue a)
{
    int i;
    if(isEmpty(a))
    {
        printf("Queue is Empty\n");
        return;
    }
    for(i=a.rear;i<=a.front;i++)
        printf("%d\t",a.arr[i]);
}

int main()
{
    int choice;
    struct queue a;
    a.rear = 0;
    a.front = -1;
    do
    {
        printf("Enter ypur choice\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: push(&a);
                    break;
            case 2: pop(&a);
                    break;
            case 3: display(a);
                    break;
            case 4: break;
            default: printf("Invalid choice\n");
                    break;
        }
    } while (choice!=4);
    printf("Thank you\n");
    return 0;
}
