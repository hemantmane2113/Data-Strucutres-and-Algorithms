class node
{
    public int data;
    public node next;
    public node prev;
}

class DoublyCircularLL
{
    private node first;
    private node last;
    private int iCount;

    public DoublyCircularLL()
    {
        first = null;
        last = null;
        iCount = 0;
    }

    public void InsertFirst(int no)
    {   
        node newn = null;
        newn = new node();

        newn.data = no;
        newn.next = null;
        newn.prev = null;

        if(first == null && last == null)
        {
            first = newn;
            last = newn;

            last.next = first;
            first.prev = last;
        }
        else
        {
            newn.next = first;
            first.prev = newn;

            first = newn;

            first.prev = last;
            last.next = first;
        }
        iCount++;
    }

    public void InsertLast(int no)
    {
        node newn = null;
        newn = new node();

        newn.data = no;
        newn.next = null;
        newn.prev = null;
        
        if(first == null && last == null)
        {
            first = newn;
            last = newn;

            last.next = first;
            first.prev = last;
        }
        else
        {
            newn.prev = last;
            last.next = newn;
            last = newn;

            last.next = first;
            first.prev = last;
        }
        iCount++;
    }

    public void Display()
    {
        if(first == null && last == null)
        {
            System.out.println("Empty Linked list");
            return;
        }
        node temp = first;
        System.out.print(" <=> ");
        do
        {
            System.out.print("| "+ temp.data + " | <=> ");
            temp = temp.next;
        }
        while(temp != first);
        System.out.println();
    }

    public int Count()
    {
        return iCount;
    }


    public void InsertAtPos(int no,int pos)
    {
        if(pos < 1 || pos > iCount + 1)
        {
            System.out.println("Invalid position.");
        }
        else if( pos == 1)
        {
            InsertFirst(no);
        }
        else if(pos == iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            int iCnt = 0;

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

            newn.next = temp.next;
            temp.next.prev = newn;

            temp.next = newn;
            newn.prev = temp;

            iCount++;

        }
    }

    public void DeleteFirst()
    {
        if(first == null && last == null)
        {
            System.out.println("Empty linked list");
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            first = first.next;

            first.prev = last;
            last.next = first;
        }
        iCount--;
    }

    public void DeleteLast()
    {
        if(first == null && last == null)
        {
            System.out.println("Empty linked list");
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            last = last.prev;

            last.next = first;
            first.prev = last;
        }
        iCount--;
    }

    public void DeleteAtPos(int pos)
    {
        if(pos < 1 || pos > iCount)
        {
            System.out.println("Invalid position.");
        }
        else if( pos == 1)
        {
            DeleteFirst();
        }
        else if(pos == iCount )
        {
            DeleteLast();
        }
        else
        {   
            int iCnt = 0;
            node temp = first;
            node target = null;

            for(iCnt = 1;iCnt < pos - 1 ; iCnt++)
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

class program378
{
 public static void main(String A[])
    {
        DoublyCircularLL sobj = new DoublyCircularLL();

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
