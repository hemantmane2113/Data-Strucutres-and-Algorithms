class node
{
    public int data;
    public node next;
}

class SinglyCircularLL
{
    private node first;
    private node last;
    private int iCount;

    public SinglyCircularLL()
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

        if(first == null && last == null)//LL is empty
        {
            first = newn;
            last = newn;

            last.next = first;
        }
        else 
        {
            newn.next = first;

            first = newn;
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


        if(first == null && last == null)//ll is empty
        {
            first = newn;
            last = newn;
            last.next = first;
        }
        else
        {
            last.next = newn;
            last = newn;
            last.next = first;
        }
        iCount++;
    }

    public void Display()
    {   
        node temp = null;

        if(first == null && last == null)
        {
            return;
        }
        temp = first;
        do 
        {
            System.out.print("|"+ temp.data + " | ->");
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
            System.out.println("Invalid position");
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
            node temp = null;

            node newn = null;
            newn = new node();

            newn.data = no;
            newn.next = null;

            int iCnt = 0;

            temp = first;

            for(iCnt = 1;iCnt < pos - 1;iCnt++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next = newn;
            iCount++;
        }
        

    }

    public void DeleteFirst()
    {
        node temp = null;

        if(first == null && last == null)//LL is empty
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            temp = first;
            first = temp.next;
            last.next = first;
        }
        iCount--;
    }

    public void DeleteLast()
    {
        node temp = null;

        if(first == null && last == null)
        {
            return;
        }
        else if(first.next == first)
        {
            first = null;
            last = null;
        }
        else
        {
            temp = first;
            while(temp.next != last)
            {
                temp = temp.next;
            }
            last = temp;
            temp.next = first;

        }
        iCount--;
    }

    public void DeleteAtPos(int pos)
    {   


        if(pos < 1 || pos > iCount)
        {
            System.out.println("Invalid position");
            return;
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
            int iCnt = 0;
            node temp = null;
            node target = null;
            temp = first;

            for(iCnt = 1;iCnt < pos - 1;iCnt++)
            {
                temp = temp.next;
            }
            target = temp.next;

            temp.next = target.next;

            iCount--;
        }
    }
}

class program377
{
 public static void main(String A[])
    {
        SinglyCircularLL sobj = new SinglyCircularLL();

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
