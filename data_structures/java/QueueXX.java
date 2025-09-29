class node
{
    public int data;
    public node next;
}

class QueueX
{
    private node first;
    private int iCount;

    public QueueX()
    {
        this.first = null;
        this.iCount = 0;
    }

    public void enqueue(int no)//InsertLast
    {
        node newn = null;

        newn = new node();

        newn.data = no;
        newn.next = null;
        node temp = null;

        if(this.first == null)
        {
            this.first = newn;
        }
        else
        {
            temp = this.first;
            while(temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = newn; 
        }


        iCount++;
    }

    public int dequeue() // DeleteFirst,int inplace of void 
    {
        node temp = first;

        if(this.first == null)//queue is empty
        {
            System.out.println("unable to dequeue as queue is empty.");
            return -1;
        }
        else
        {
            first = first.next;
            iCount--;

            return temp.data;
        }
    }
    public void Display()
    {
        node temp = null;
        temp = this.first;

        while(temp != null)
        {
            System.out.print("| "+temp.data+" |");
            temp = temp.next;
        }
    }
    public int Count()
    {
        return iCount;
    }

}


class QueueXX
{
    public static void main(String A[])
    {
        QueueX sobj = new QueueX();

        int iRet = 0;

        sobj.enqueue(10);
        sobj.enqueue(20);
        sobj.enqueue(30);
        sobj.enqueue(40);
        sobj.enqueue(50);

        sobj.Display();

        iRet = sobj.Count();

        System.out.println("Total numbers in the queue are: " +iRet);

        iRet = sobj.dequeue();
        sobj.Display();
        System.out.println("removed element is: " +iRet);

        iRet = sobj.dequeue();
        sobj.Display();
        System.out.println("removed element is: " +iRet);

        iRet = sobj.dequeue();
        sobj.Display();
        System.out.println("removed element is: " +iRet);


        sobj.Display();

        iRet = sobj.Count();

        System.out.println("Total numbers in the queue are: " +iRet);
    }
}