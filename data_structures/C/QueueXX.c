#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;


void Enqueue(PPNODE first,int no)// Insert last
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    PNODE temp = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = * first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }

}
int Dequeue(PPNODE first)//delete first
{   
    PNODE temp = NULL;
    int iValue = 0;

    if(*first == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        temp = *first;
        iValue = temp->data;

        *first = (*first)->next; 
        free(temp);

        return iValue;
    }
}
void Display(PNODE first)
{   
    if(first == NULL)
    {
        printf("Unable to display elements as queue is empty\n");
        return;
    }
    while(first != NULL)
    {
        printf("| %d |",first->data);
        first  =  first->next;
    }
    printf("\n");


}
int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first  =  first->next;
    }
    return iCount;
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    Enqueue(&head,10);
    Enqueue(&head,20);
    Enqueue(&head,30);
    Enqueue(&head,40);
    Enqueue(&head,50);

    Display(head);

    iRet = Count(head);

    printf("Number of elements in the queue are : %d\n",iRet);

    
    iRet = Dequeue(&head);
    printf("Dequeuing element: %d\n",iRet);
    Display(head);

    iRet = Dequeue(&head);
    printf("Dequeuing element: %d\n",iRet);
    Display(head);

    iRet = Dequeue(&head);
    printf("Dequeuing element: %d\n",iRet);

    Display(head);

    iRet = Count(head);

    printf("Number of elements in the queue are : %d\n",iRet);

    return 0;
}
