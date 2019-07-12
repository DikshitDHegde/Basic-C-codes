#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct stack
{
    int arr[MAX];
    int top;
};

int isFull(struct stack *a)
{
    return(a->top==MAX-1);
}

int isEmpty(struct stack *a)
{
    return(a->top==-1);
}

void push(struct stack *a)
{
    int i;
    if (isFull(a))
    {
        printf("Stack is full\n");
        return;
    }
    printf("Enter the number to be pushed:- ");
    scanf("%d",&i);
    a->top++;
    a->arr[a->top]=i;
}

void pop(struct stack *a)
{
    int i;
    if (isEmpty(a))
    {
        printf("Stack is Empty\n");
        return;
    }
    printf("Popped element is :-  %d\n",a->arr[a->top]);
    a->top--;
}

void display(struct stack a)
{
    int i;
    if (isEmpty(&a))
    {
        printf("Stack is Empty\n");
        return;
    }
    for(i=0;i<=a.top;i++)
        printf("%d\t",a.arr[i]);
    
    printf("\n");
}

int main()
{
    struct stack a;
    int choice=0;
    a.top = -1;
    while(choice != 4)
    {
        printf("Enter ur choice\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:push(&a);
                   break;
            case 2:pop(&a);
                    break;
            case 3:display(a);
                    break;
            case 4:printf("THANK YOU\n");
                    break;
            default: printf("MC Choosed invalid choice\n");
                    break;
        }
    }
    return 0;
}