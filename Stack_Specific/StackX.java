class node
{
    public int data;
    public node next;
}

class StackXX
{
    private node first;
    private int iCount;

    public StackXX()
    {
        this.first = null;
        this.iCount = 0;
    }

    public void push(int no)
    {
        node newn = null;
        newn = new node();

        newn.data = no;
        newn.next = null;
        
        newn.next = first;
        first = newn;      

        iCount++;

    }

    public int pop()
    {
        node temp = first;

        if(this.first == null)
        {
            System.out.println("Unable to pop as stack is empty");
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

public class StackX
{
    public static void main(String A[])
    {
        StackXX sobj = new StackXX();
        int iRet = 0;

        sobj.push(10);
        sobj.push(20);
        sobj.push(30);
        sobj.push(40);
        sobj.push(50);

        sobj.Display();

        iRet = sobj.Count();
        System.out.println("Number of elements in the stack are : "+iRet);

        iRet = sobj.pop();
        System.out.println("Poped elements from stack is : "+iRet);
        
        iRet = sobj.pop();
        System.out.println("Poped elements from stack is : "+iRet);

        iRet = sobj.pop();        
        System.out.println("Poped elements from stack is : "+iRet);
        
        sobj.Display();

        iRet = sobj.Count();
        System.out.println("Number of elements in the stack are : "+iRet);
    }
}
