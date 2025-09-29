#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *lchild;
    struct node * rchild;
};

typedef struct node NODE;
typedef struct node * PNODE;
//typedef struct node ** PPNODE;

class BinarySearchTree
{
    private:
        PNODE first;
        int iCount;

    public:
    BinarySearchTree()
    {
        cout<<"Inside constructor of Binary Search Tree\n";
        this->first = NULL;
        this->iCount = 0;
    }
    PNODE GetRoot()
    {
        return first;
    }
    
    void Insert(int no)
    {
        PNODE newn = NULL;
        PNODE temp = NULL;

        newn = new NODE;
        newn->data = no;
        newn->lchild = NULL;
        newn->rchild = NULL;

        if(first == NULL)
        {
            first = newn;
            iCount++;
            return;
        }
        else
        {
            PNODE temp = first;

            while(true)
            {
                if(no == temp->data)
                {
                    cout<<"Duplicate element: unable to insert\n";
                    delete newn;
                    break;
                }
                else if (no > temp->data)
                {
                    if(temp->rchild == NULL)
                    {
                        temp->rchild = newn;
                        iCount++;
                        break;
                    }
                    temp = temp->rchild;
                }
                else if(no < temp->data)
                {
                    if(temp->lchild == NULL)
                    {
                        temp->lchild = newn;
                        iCount++;
                        break;
                    }
                    temp = temp->lchild;
                }
            }     
        }
    }
    void Inorder(PNODE head)
    {
        if(head != NULL)
        {
            Inorder(head->lchild);
            cout<<head->data<<"\t";
            Inorder(head->rchild);

        }
    }

    void Preorder(PNODE head)
    {
        if(head != NULL)
        {   
            cout<<head->data<<"\t";
            Preorder(head->lchild); 
            Preorder(head->rchild);

        }
    }

    void Postorder(PNODE head)
    {
        if(head != NULL)
        {   
            
            Postorder(head->lchild);    
            Postorder(head->rchild);
            cout<<head->data<<"\t";

        }
    }

    bool Search(int no)
    {
        bool bFlag = false;
        int TimeComplexity = 0;

        while(first != NULL)
        {
            if(no == first->data)
            {
                bFlag = true;
                break;
            }
            else if(no > first->data)
            {
                first = first->rchild;
            }
            else if(no < first->data)
            {
                first = first->lchild;
            }
            TimeComplexity++;
        }
        cout<<"Time complexity of search is: "<<TimeComplexity<<"\n";
        return bFlag;

    }

    int Count()
    {
        return iCount;
    }

    int CountLeafNodes(PNODE head)
    {
        static int iCount = 0;

        if(head != NULL)
        {
            if((head->lchild==NULL) && (head->rchild)==NULL)
            {
                iCount++;
            }

            CountLeafNodes(head->rchild);
            CountLeafNodes(head->lchild);
        }
        return iCount;
    }

    int CountParentNodes(PNODE head)
    {
        static int iCount = 0;

        if(head != NULL)
        {
            if((head->lchild != NULL) || (head->rchild) != NULL)
            {
                iCount++;
            }

            CountParentNodes(head->rchild);
            CountParentNodes(head->lchild);
        }
        return iCount;
    }


};

int main()
{
    BinarySearchTree sobj;
    bool bRet = false;
    
    int iRet = 0;

    sobj.Insert(11);
    sobj.Insert(9);
    sobj.Insert(17);
    sobj.Insert(25);
    sobj.Insert(7);
    sobj.Insert(35);
    sobj.Insert(10);
    sobj.Insert(15);
    sobj.Insert(21);
    sobj.Insert(26);
    sobj.Insert(37);
    sobj.Insert(89);
    sobj.Insert(91);
    sobj.Insert(65);
    sobj.Insert(12);
    sobj.Insert(20);
    sobj.Insert(44);
    sobj.Insert(66);
    sobj.Insert(90);
    sobj.Insert(88);

    bRet = sobj.Search(89);

    if(bRet == true)
    {
        cout<<"Element is present\n";
    }
    else
    {
        cout<<"There is no such element in the tree\n";
    }

    iRet = sobj.Count();
    cout<<"Number/density of node is/are: "<<iRet<<"\n";

    iRet = sobj.CountLeafNodes(sobj.GetRoot());
    cout<<"Number/density of leaf node is/are: "<<iRet<<"\n";

    iRet = sobj.CountParentNodes(sobj.GetRoot());
    cout<<"Number/ density of parent node is/are: "<<iRet<<"\n";

    cout<<"\n\nInorder traversal: \n";
    sobj.Inorder(sobj.GetRoot());

    cout<<"\n\nPreorder traversal: \n";
    sobj.Preorder(sobj.GetRoot());

    cout<<"\n\nPostorder traversal: \n";
    sobj.Postorder(sobj.GetRoot());

    return 0;
}