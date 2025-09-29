#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node* lchild;
    struct node* rchild;
} NODE, * PNODE;

class BinarySearchTree
{
private:
    PNODE root;
    int iCount;

public:
    BinarySearchTree()
    {
        cout << "Inside constructor of Binary Search Tree\n";
        root = NULL;
        iCount = 0;
    }

    void Insert(int no)
    {
        PNODE newn = new NODE;
        newn->data = no;
        newn->lchild = NULL;
        newn->rchild = NULL;

        if (root == NULL)
        {
            root = newn;
            iCount++;
            return;
        }

        PNODE temp = root;

        while (true)
        {
            if (no == temp->data)
            {
                delete newn;
                return;
            }
            else if (no < temp->data)
            {
                if (temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
            else
            {
                if (temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
        }
        iCount++;
    }

    bool Search(int no)
    {
        int iSteps = 0;
        PNODE temp = root;

        while (temp != NULL)
        {
            iSteps++;
            if (temp->data == no)
            {
                cout << "Time complexity of search is: " << iSteps << "\n";
                return true;
            }
            else if (no < temp->data)
            {
                temp = temp->lchild;
            }
            else
            {
                temp = temp->rchild;
            }
        }
        return false;
    }

    int Count()
    {
        return iCount;
    }

    PNODE GetRoot()
    {
        return root;
    }

    int CountLeafNodes(PNODE head)
    {
        if (head == NULL)
        {
            return 0;
        }
        if (head->lchild == NULL && head->rchild == NULL)
        {
            return 1;
        }
        int leftLeaf = CountLeafNodes(head->lchild);
        int rightLeaf = CountLeafNodes(head->rchild);
        return leftLeaf + rightLeaf;

    }

    int CountParentNodes(PNODE head)
    {
        if (head == NULL)
        {
            return 0;
        }
        if (head->lchild != NULL || head->rchild != NULL)
        {
            int leftParent = CountParentNodes(head->lchild);
            int rightParent = CountParentNodes(head->rchild);
            return 1 + leftParent + rightParent;
        }
        int leftParent = CountParentNodes(head->lchild);
        int rightParent = CountParentNodes(head->rchild);
        return leftParent + rightParent;

    }

    void Inorder(PNODE head)
    {
        if (head != NULL)
        {
            Inorder(head->lchild);
            cout << head->data << "\t";
            Inorder(head->rchild);
        }
    }

    void Preorder(PNODE head)
    {
        if (head != NULL)
        {
            cout << head->data << "\t";
            Preorder(head->lchild);
            Preorder(head->rchild);
        }
    }

    void Postorder(PNODE head)
    {
        if (head != NULL)
        {
            Postorder(head->lchild);
            Postorder(head->rchild);
            cout << head->data << "\t";
        }
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

    if (bRet == true)
    {
        cout << "Element is present\n";
    }
    else
    {
        cout << "There is no such element in the tree\n";
    }

    iRet = sobj.Count();
    cout << "Number/density of node is/are: " << iRet << "\n";

    iRet = sobj.CountLeafNodes(sobj.GetRoot());
    cout << "Number/density of leaf node is/are: " << iRet << "\n";

    iRet = sobj.CountParentNodes(sobj.GetRoot());
    cout << "Number/density of parent node is/are: " << iRet << "\n";

    cout << "\n\nInorder traversal:\n";
    sobj.Inorder(sobj.GetRoot());

    cout << "\n\nPreorder traversal:\n";
    sobj.Preorder(sobj.GetRoot());

    cout << "\n\nPostorder traversal:\n";
    sobj.Postorder(sobj.GetRoot());

    return 0;
}
