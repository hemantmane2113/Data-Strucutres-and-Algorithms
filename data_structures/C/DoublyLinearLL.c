#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node  NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE first,int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        (*first)->prev = newn;

        *first = newn;
    }
}
void InsertLast(PPNODE first,int no)
{   
    
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    PNODE temp = NULL;

    if(*first == NULL)//LL is empty
    {
        *first = newn;
    }
    else if ((*first)->next ==  NULL)//LL has only one node
    {
        (*first)->next = newn;
        newn->prev = *first;
    }
    else//LL  has more than 1 node
    {
        temp = *first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
}

int Count(PNODE first)
{   
    
    int iCnt = 0;
    while(first != NULL)
    {
        iCnt++;
        first = first->next;
    }
    return iCnt;
}

void Display(PNODE first)
{   
    printf("NULL <=> ");
    while(first != NULL)
    {
        printf("| %d | <=> ",first->data);
        first = first->next;
    }
    printf("NULL <=> ");
    printf("\n");
}

void InsertAtPos(PPNODE first,int no,int pos)
{   
    int iCount = 0;
    int iCnt = 0;
    iCount = Count(*first);

    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    PNODE temp = NULL;

    if(pos < 1 || pos > iCount + 1)
    {
        printf("Invalid position.\n");
        return;
    }
    else if(pos == 1)
    {
        InsertFirst(first,no);
    }
    else
    {   
        temp = *first;
        for(iCnt = 1;iCnt < pos - 1;iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;
    }

}

void DeleteFirst(PPNODE first)
{   
    PNODE temp = NULL;
    if(*first == NULL)
    {
        return;
    }
    else if ((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    { 
        temp = (*first)->next;
        free(*first);
        *first = temp;
        temp->prev = NULL;
    }  
}
void DeleteLast(PPNODE first)
{   
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }   
}
void DeleteAtPos(PPNODE first,int pos)
{
    int iCount = 0;
    int iCnt = 0;
    iCount = Count(*first);

    PNODE temp = NULL;
    PNODE target = NULL;

    if(pos < 1 || pos > iCount)
    {
        printf("Invalid position.\n");
        return;
    }
    else if(pos == 1)
    {
        DeleteFirst(first);
    }
    else
    {   
        temp = *first;
        for(iCnt = 1;iCnt < pos -1;iCnt++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = temp->next->next;
        target->next->prev = temp;
        free(target);
    }
}

int main()
{
    int iNo = 0;
    int iRet = 0;
    PNODE head = NULL;

    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    InsertLast(&head,101);
    InsertLast(&head,111);
    InsertLast(&head,121);

    Display(head);

    iRet = Count(head);
    printf("The total number of nodes in the linked-list are: %d\n",iRet);

    InsertAtPos(&head,105,5);

    Display(head);

    iRet = Count(head);
    printf("The total number of nodes in the linked-list are: %d\n",iRet);

    DeleteAtPos(&head,5);

    Display(head);

    iRet = Count(head);
    printf("The total number of nodes in the linked-list are: %d\n",iRet);

    return 0;
}