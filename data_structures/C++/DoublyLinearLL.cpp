#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node **PPNODE;

class DoublyLinearLL
{
    private:
    PNODE first;
    int iCount;

    public:
    DoublyLinearLL()
    {
        cout<<"Inside Constructor of DoublyLinearLL\n";
        this->first = NULL;
        this->iCount = 0;
    }
    void InsertFirst(int no)
    {   
        PNODE newn = NULL;
        newn = new NODE;
        newn->data = no;
        newn->prev = NULL;
        newn->next = NULL;

        if(first == NULL)// LL is empty
        {
            first = newn;
            first->prev = NULL;
            first->next = NULL;
        }
        else// LL has atleast one node
        {
            newn->next = first;
            first->prev = newn;
            first = newn;
        }
        iCount++;
    }
    void InsertLast(int no)
    {
        PNODE newn = NULL;
        newn = new NODE;
        newn->data = no;
        newn->prev = NULL;
        newn->next = NULL;

        if(first == NULL)// LL is empty
        {
            first = newn;
            first->prev = NULL;
            first->next = NULL;
        }
        else// LL has atleast one node
        {
            PNODE temp = NULL;
            temp = first;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
            newn->prev = temp;
        }
        iCount++;
    }
    void DeleteFirst()
    {
        if(first == NULL)// LL is empty
        {
            cout<<"Linked List is empty\n";
            return;
        }
        if(first->next != NULL)// LL has only one node
        {   
            delete first;
            first = NULL;
        }
        else
        {
            PNODE temp = NULL;
            temp = first;
            first = first->next;
            first->prev = NULL;
            delete temp;

        }
        iCount--;


    }
    void DeleteLast()
    {
        if(first == NULL)// LL is empty
        {
            cout<<"Linked List is empty\n";
            return;
        }
        if(first->next != NULL)// LL has only one node
        {   
            delete first;
            first = NULL;
        }
        else
        {
            PNODE temp = NULL;
            temp = first;
            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
            
        }
        iCount--;
    }
    void Display()
    {
        if(first == NULL)
        {
            cout<<"Linekd list is empty\n";
            return;
        }
        PNODE temp = NULL;
        temp = first;
        cout<<"NULL<=>";
        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<" |<=>";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
    int Count()
    {
        return iCount;
    }
    void InsertAtPos(int no,int pos)
    {   
        PNODE newn = NULL;
        newn = new NODE;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        PNODE temp = NULL;
        int iCnt = 0;

        if(pos < 1 || pos > iCount + 1)
        {
            cout<<"Invalid Position\n";
            return;
        }
        if(pos == 1)
        {
            InsertFirst(no);
        }
        else if(pos  == iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            temp = first;
            for(iCnt = 1;iCnt < pos - 1; iCnt++)
            {
                temp = temp->next;
            }
            temp->next->prev = newn;
            newn->next = temp->next;

            temp->next = newn;
            newn->prev = temp;

            iCount++;
        }
    }
    void DeleteAtPos(int pos)
    {   
        PNODE temp = NULL;
        PNODE target = NULL;
        int iCnt = 0;

        if(pos < 1 || pos > iCount)
        {
            cout<<"Invalid Position\n";
            return;
        }
        if(pos == 1)
        {
            DeleteFirst();
        }
        else if(pos  == iCount)
        {
            DeleteLast();
        }
        else
        {
            temp = first;

            for(iCnt = 1;iCnt < pos - 1;iCnt++)
            {
                temp = temp->next;
            }
            target = temp->next;
            target->next->prev = temp;
            temp->next = target->next;
            delete target;

            iCount--;
        }
    }
    

};

int main()
{
    DoublyLinearLL sobj;
    int iRet = 0;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);
    
    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);

    sobj.Display();
    
    iRet = sobj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";
    
    sobj.InsertAtPos(105,5);

    sobj.Display();
    
    iRet = sobj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    sobj.DeleteAtPos(5);

    sobj.Display();
    
    iRet = sobj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    return 0;
}