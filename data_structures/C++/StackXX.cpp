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

class StackXX
{
    private:
    PNODE first;
    int iCount;

    public:
    StackXX()
    {
        cout<<"Inside constructor of StackXX\n";
        this->first = NULL;
        this->iCount = 0;
    }

    void Push(int no)//Insert First
    {
        PNODE newn = NULL;
        newn = new NODE;
        newn->data = no;
        newn->next = NULL;

        newn->next = first;
        first = newn;
        
        iCount++;
    }

    int Pop()//Delete First
    {
        PNODE temp = NULL;
        int iValue = 0;

        if(first == NULL)//stack is empty
        {
            cout<<"Unable to pop as stack is empty.\n";
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
            cout<<"Unable to display elements as Stack is empty\n";
            return;
        }
        
        
        temp = first;
        while(temp != NULL)
        {
            cout<<"| "<<temp->data<< " |\n";
            temp = temp->next;
        }
    }
    
    int Count()
    {
        return iCount;
    }
    
};

int main()
{
    StackXX sobj;
    int iRet = 0;

    sobj.Push(10);
    sobj.Push(20);
    sobj.Push(30);
    sobj.Push(40);
    sobj.Push(50);

    sobj.Display();

    iRet = sobj.Count();

    cout<<"Total number of elements in the stack are: "<<iRet<<"\n";

    iRet = sobj.Pop();
    cout<<"Popping element : "<<iRet<<"\n";
    sobj.Display();

    iRet = sobj.Pop();
    cout<<"Popping element : "<<iRet<<"\n";
    sobj.Display();

    iRet = sobj.Pop();
    cout<<"Popping element : "<<iRet<<"\n";


    sobj.Display();

    iRet = sobj.Count();

    cout<<"Total number of elements in the stack are: "<<iRet<<"\n";
}
/*
Important note:
1. we dont check the conditions like:
                    // whether the stack is empty (in case of push or display) or
                    // whether the stack contains just one element(in case of pop)
Because:
        In Push: Always insert in the beginning -doesn't matter if its empty or not.
        In Pop:  Always removes the first node-doesn't matter if there's one or many.


eg.

If the stack has just one node say | 11 | NULL |
so when we do first = first->next (in push and pop),first becomes NULL automatically
Therefore we dont need to write first = NULL separately in case of Push pop Pop

*/
