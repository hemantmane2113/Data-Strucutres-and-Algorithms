#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class SinglyLinearLL
{
    private:
    PNODE first;
    int iCount;

    public:
    SinglyLinearLL()
    {
        cout<<"Inside Constructor of SinglyLinearLL\n";
        this->first = NULL;
        this->iCount = 0;
    }
    void InsertFirst(int no)
    {
        PNODE newn = NULL;
        newn = new NODE;
        newn->data = no;
        newn->next = NULL;

        if(first == NULL)// LL is empty
        {
            first = newn;
        }
        else// LL contains atleast one node
        {
            newn->next = first;
            first = newn;
        }
        iCount++;

    }
    void InsertLast(int no)
    {
        PNODE newn = NULL;
        newn = new NODE;
        newn->data = no;
        newn->next = NULL;

        if(first == NULL)// LL is empty
        {
            first = newn;
        }
        else// LL contains atleast one node
        {
           PNODE temp = NULL;
           temp = first;

           while(temp->next != NULL)
           {
                temp = temp->next;
           }
           temp->next = newn;
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
        if (first->next == NULL)// LL has only one node
        {
            delete first;
            first = NULL;
        }
        else
        {   
            PNODE temp = NULL;
            temp = first;
            first = first->next;
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
        if (first->next == NULL)// LL has only one node
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
            cout<<"Linked List is empty\n";
            return;
        }

        PNODE temp = NULL;
        temp = first;
        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<" |->";
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
        iCount = Count();

        if(pos < 1 || pos > iCount + 1)
        {
            cout<<"Invalid Position\n";
            return;
        }

        if(pos == 1)
        {
            InsertFirst(no);
        }
        else if(pos == iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            PNODE newn = new NODE;
            newn->data = no;
            newn->next = NULL;

            PNODE temp = NULL;
            temp = first;
            int iCnt = 0;

            for(iCnt = 1;iCnt < pos - 1;iCnt++)
            {
                temp = temp->next;
            }
            newn->next = temp->next;
            temp->next = newn;

            iCount++;
        }

    }
    void DeleteAtPos(int pos)
    {
        iCount = Count();

        if(pos < 1 || pos > iCount)
        {
            cout<<"Invalid Position\n";
            return;
        }

        if(pos == 1)
        {
            DeleteFirst();
        }
        else if(pos == iCount)
        {
            DeleteLast();
        }
        else
        {
            PNODE temp = NULL;
            temp = first;
            PNODE target = NULL;
            int iCnt = 0;

            for(iCnt = 1;iCnt < pos - 1;iCnt++)
            {
                temp = temp->next;
            }
            target = temp->next;
            temp->next = target->next;
            delete target;

            iCount--;
        }
    }
};

int main()
{
    SinglyLinearLL sobj;
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