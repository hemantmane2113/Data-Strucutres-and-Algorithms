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


void Push(PPNODE first,int no)// Insert first
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    newn->next = *first;
    *first = newn;

}
int Pop(PPNODE first)//delete first
{   
    PNODE temp = NULL;
    int iValue = 0;

    if(*first == NULL)
    {
        printf("Stack is empty");
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
        printf("Unable to display elements as stack is empty\n");
        return;
    }
    while(first != NULL)
    {
        printf("| %d |\n",first->data);
        first  =  first->next;
    }


}
int Count(PNODE first)
{
    int iCount = 0;

    if(first == NULL)
    {
        printf("Unable to count elements as stack is empty\n");
        return -1;
    }
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

    Push(&head,10);
    Push(&head,20);
    Push(&head,30);
    Push(&head,40);
    Push(&head,50);

    Display(head);

    iRet = Count(head);

    printf("Number of elements in the stack are : %d\n",iRet);

    
    iRet = Pop(&head);
    printf("Popping element: %d\n",iRet);
    Display(head);

    iRet = Pop(&head);
    printf("Popping element: %d\n",iRet);
    Display(head);

    iRet = Pop(&head);
    printf("Popping element: %d\n",iRet);
    Display(head);

    Display(head);

    iRet = Count(head);

    printf("Number of elements in the stack are : %d\n",iRet);

    return 0;
}
