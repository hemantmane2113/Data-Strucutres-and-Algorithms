class node
{
    public int data;
    public node next;
}

class StackX
{
    private node first;
    private int iCount;

    public StackX()
    {
        this.first = null;
        this.iCount = 0;
    }

    public void push(int no)//InsertFirst
    {
        node newn = null;

        newn = new node();

        newn.data = no;
        newn.next = null;

        newn.next = first;
        first = newn;

        iCount++;
    }

    public int pop() // DeleteFirst,int in place of void 
    {
        node temp = first;

        if(this.first == null)//stack is empty
        {
            System.out.println("unable to remove as queue is empty.");
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
            System.out.println("| "+temp.data+" |");
            temp = temp.next;
        }
    }
    public int Count()
    {
        return iCount;
    }

}


class StackXX
{
    public static void main(String A[])
    {
        StackX sobj = new StackX();
        int iRet = 0;

        sobj.push(10);
        sobj.push(20);
        sobj.push(30);
        sobj.push(40);
        sobj.push(50);

        sobj.Display();

        iRet = sobj.Count();

        System.out.println("Total numbers in the stack are: "+iRet);

        iRet = sobj.pop();
        sobj.Display();
        System.out.println("Poped element is : "+iRet);

        iRet = sobj.pop();
        sobj.Display();
        System.out.println("Poped element is : "+iRet);

        iRet = sobj.pop();
        sobj.Display();
        System.out.println("Poped element is : "+iRet);


        sobj.Display();

        iRet = sobj.Count();

        System.out.println("Total numbers in the stack are: "+iRet);
    }
}