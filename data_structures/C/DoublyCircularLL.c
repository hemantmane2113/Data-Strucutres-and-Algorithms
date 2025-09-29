#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;



void InsertFirst(PPNODE first,PPNODE last,int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL && *last == NULL)//LL is empty
    {
        *first = newn;
        *last = newn;

    }
    else
    {
        newn->next = *first;
        (*first)->prev = newn;
        *first = newn;
    }
    (*last)->next = *first;
    (*first)->prev  = *last; 
    
}

void InsertLast(PPNODE first,PPNODE last,int no)
{   
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;

    }
    else
    {
        (*last)->next = newn;
        newn->prev = *last;
        *last = newn;    
    }
    (*last)->next = *first;
    (*first)->prev = *last;

    
}
void Display(PNODE first,PNODE last)
{
    PNODE temp = first;

    if(first == NULL && last == NULL)
    {
        printf("The linked list is empty");
        return;
    }
    do
    {
        printf("| %d |<=>",temp->data);
        temp = temp->next;
    } while (temp != first);
    
}

int Count(PNODE first,PNODE last)
{
        PNODE temp = first;
        int iCount = 0;

    if(first == NULL && last == NULL)
    {   
        printf("The linked list is empty");
        return 0;
    }
    do
    {
        iCount++;
        temp = temp->next;
    } while (temp != first);
    return iCount;
    
}
void InsertAtPos(PPNODE first,PPNODE last,int no,int pos)
{
    
    int iCount = Count(*first,*last);
    int iCnt = 0;

    PNODE temp = NULL;
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(pos < 1 || pos > iCount + 1)
    {
        printf("Invalid postion\n");
        return;
    }
    if(pos == 1)
    {
        InsertFirst(first,last,no);
    }
    else
    {   
        temp = *first;
        for(iCnt = 1;iCnt < pos -1 ;iCnt++)
        {
            temp = temp->next;
    
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;

        (*last)->next = *first;
        (*first)->prev = *last;
    }


}

void DeleteFirst(PPNODE first,PPNODE last)
{
    
    if(*first == NULL && *last == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    else if(*first == *last)
    {   
        free(*first);
        *first = NULL;
        *last = NULL;
        
    }
    else
    {
        *first = (*first)->next;
        free((*first)->prev);
    }
    (*last)->next = *first;
    (*first)->prev = *last;

}
void DeleteLast(PPNODE first,PPNODE last)
{
    if(*first == NULL && *last == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    else if(*first == *last)
    {   
        free(*first);
        *first = NULL;
        *last = NULL;
        
    }
    else
    {
        (*last) = (*last)->prev;
        free((*last)->next); 
    }
    (*last)->next = *first;
    (*first)->prev = *last;
  
}
void DeleteAtPos(PPNODE first,PPNODE last,int pos)
{
    
    int iCount = Count(*first,*last);
    int iCnt = 0;

    PNODE temp = NULL;
    PNODE target = NULL;
    
    if(pos < 1 || pos > iCount)
    {
        printf("Invalid postion\n");
        return;
    }
    if(pos == 1)
    {
        DeleteFirst(first,last);
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
    (*last)->next = *first;
    (*first)->prev = *last;
    
}


int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;
    int iRet = 0;

    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);

    InsertLast(&head,&tail,101);
    InsertLast(&head,&tail,111);
    InsertLast(&head,&tail,121);

    Display(head,tail);
    iRet = Count(head,tail);

    printf("\nThe total nodes in linked-list are: %d\n",iRet);

    InsertAtPos(&head,&tail,105,5);

    Display(head,tail);
    iRet = Count(head,tail);

    printf("\nThe total nodes in linked-list are: %d\n",iRet);

    DeleteAtPos(&head,&tail,5);

    Display(head,tail);
    iRet = Count(head,tail);

    printf("\nThe total nodes in linked-list are: %d\n",iRet);

    return 0;
}