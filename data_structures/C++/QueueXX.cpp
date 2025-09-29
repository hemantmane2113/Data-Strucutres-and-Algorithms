#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
//typedef struct node ** PPNODE;

class QueueXX
{
    private:
    PNODE first;
    int iCount;

    public:
    QueueXX()
    {
        cout<<"Inside constructor of QueueXX\n";
        this->first = NULL;
        this->iCount = 0;
    }

    void Enqueue(int no)//Insert Last
    { 
        PNODE newn = NULL;
        newn = new NODE;

        newn->data = no;
        newn->next = NULL;

        PNODE temp = NULL;

        if(first == NULL)
        {
            cout<<"Queue is empty\n";
            first = newn;
        }
        else
        {
            temp = first;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
        }
        iCount++;
    
    }

    int Dequeue()//Delete First
    {
        PNODE temp = NULL;
        int iValue = 0;

        if(first == NULL)//queue is empty
        {
            cout<<"Unable to dequeue as queue is empty.\n";
            return -1;
        }
        
          
        temp = first;
        iValue = temp->data;

        first = first->next;
        delete temp;
            
        iCount--;

        return iValue;
    
           
    }
    void Display()
    {
        PNODE temp = NULL;

        if(first == NULL)
        {
            cout<<"Unable to display elements as queue is empty\n";
            return;
        }
        
        
        temp = first;
        while(temp != NULL)
        {
            cout<<"| "<<temp->data<< " |";
            temp = temp->next;
        }
        cout<<"\n";
    }
    
    int Count()
    {
        return iCount;
    }
    
};

int main()
{
    QueueXX sobj;
    int iRet = 0;

    sobj.Enqueue(10);
    sobj.Enqueue(20);
    sobj.Enqueue(30);
    sobj.Enqueue(40);
    sobj.Enqueue(50);

    sobj.Display();

    iRet = sobj.Count();

    cout<<"Total number of elements in the queue are: "<<iRet<<"\n";

    iRet = sobj.Dequeue();
    cout<<"Dequeuing element : "<<iRet<<"\n";
    sobj.Display();

    iRet = sobj.Dequeue();
    cout<<"Dequeuing element : "<<iRet<<"\n";
    sobj.Display();

    iRet = sobj.Dequeue();
    cout<<"Dequeuing element : "<<iRet<<"\n";


    sobj.Display();

    iRet = sobj.Count();

    cout<<"Total number of elements in the queue are: "<<iRet<<"\n";
}

