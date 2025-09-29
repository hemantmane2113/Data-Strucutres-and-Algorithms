class node
{
    public int data;
    public node next;
    public node prev;
}

class DoublyLinearLL
{
    private node first;
    private int iCount;

    public DoublyLinearLL()
    {
        first = null;
        iCount = 0;
    }

    public void InsertFirst(int no)
    {   
        node newn = null;
        newn = new node();

        newn.data = no;
        newn.prev = null;
        newn.next = null;

        if(first == null)//LL is empty
        {
            first = newn;
            first.prev = null;
            first.next = null;
        }
        else//LL has atleast one node
        {
            newn.next = first;
            first.prev = newn;
            first = newn;
        }
        iCount++;
    }

    public void InsertLast(int no)
    {
        node newn = null;
        newn = new node();

        newn.data = no;
        newn.prev = null;
        newn.next = null;

        node temp = null;

        if(first == null)//LL is empty
        {
            first = newn;
            first.prev = null;
            first.next = null;
        }
        else
        {
           temp = first;
           while(temp.next != null)
           {
            temp = temp.next;
           } 
           temp.next = newn;
           newn.prev = temp;
        }
        iCount++;
    }

    public void Display()
    {   
        node temp = first;
        System.out.print("NULL <=>");
        while(temp != null)
        {
            System.out.print("| " +temp.data + " | <=>");
            temp = temp.next;
        }
        System.out.println("NULL");

    }

    public int Count()
    {
        return iCount;
    }

    public void InsertAtPos(int no,int pos)
    {   
        int iCnt = 0;
        if(pos < 1 || pos > iCount + 1)
        {
            System.out.println("Invalid position.");
        }
        else if(pos == 1)
        {
            InsertFirst(no);
        }
        else if(pos == iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            node newn = null;
            newn = new node();
            
            newn.data = no;
            newn.next = null;
            newn.prev = null;

            node temp = first;
            for(iCnt = 1;iCnt < pos - 1;iCnt++)
            {
                temp = temp.next;
            }
            newn.prev = temp;
            newn.next = temp.next;
            temp.next.prev = newn;
            temp.next = newn;
            
            iCount++;
        }
    }

    public void DeleteFirst()
    {
        if(first == null)
        {
            return;
        }
        else if(first.next == null)
        {
            first = null;
        }
        else
        { 
            first = first.next;
            first.prev = null;
        }
        iCount--;
    }

    public void DeleteLast()
    {
        if(first == null)
        {
            return;
        }
        else if(first.next == null)
        {
            first = null;
        }
        else
        {
            node temp = first;
            while(temp.next.next != null)
            {
                temp = temp.next;
            }
            temp.next.prev = null;
            temp.next = null;
        }
        iCount--;
        
    }

    public void DeleteAtPos(int pos)
    {
        int iCnt = 0;
        if(pos < 1 || pos > iCount)
        {
            System.out.println("Invalid position.");
        }
        else if(pos == 1)
        {
            DeleteFirst();
        }
        else if(pos == iCount)
        {
            DeleteLast();
        }
        else
        {   
            node temp = first;
            node target = null;

            for(iCnt = 1;iCnt < pos - 1;iCnt++)
            {
                temp = temp.next;
            }
            target = temp.next;
            temp.next = target.next;
            target.next.prev = temp;
            iCount--;
        }
    }



}

class program379
{
 public static void main(String A[])
    {
        DoublyLinearLL sobj = new DoublyLinearLL();

        int iRet = 0;

        sobj.InsertFirst(51);
        sobj.InsertFirst(21);
        sobj.InsertFirst(11);

        sobj.InsertLast(101);
        sobj.InsertLast(111);
        sobj.InsertLast(121);

        sobj.Display();

        iRet = sobj.Count();

        System.out.println("Number of elements in the linked-list are: "+iRet);


        sobj.InsertAtPos(105,5);

        sobj.Display();

        iRet = sobj.Count();

        System.out.println("Number of elements in the linked-list are: "+iRet);

        sobj.DeleteAtPos(5);

        sobj.Display();

        iRet = sobj.Count();

        System.out.println("Number of elements in the linked-list are: "+iRet);
    }
}
