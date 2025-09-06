class node
{
    int data;
    node next;
}

class QueueXX
{
    private node first;
    private int iCount;

    public QueueXX()
    {
        this.first = null;
        this.iCount = 0 ;
    }

    public void enqueue(int no)
    {
        node newn = null;
        node temp = null;

        newn = new node();

        newn.data = no;
        newn.next = null;
        
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

    public int dequeue()
    {
        node temp = this.first;

        if(this.first == null)
        {
            System.out.println("Unable to remove as queue is empty");
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
        System.out.println();
    }

    public int Count()
    {
        return iCount;
    }
}

public class QueueX 
{
    public static void main(String A[])
    {
        QueueXX sobj = new QueueXX();
        int iRet = 0;

        sobj.enqueue(10);
        sobj.enqueue(20);
        sobj.enqueue(30);
        sobj.enqueue(40);
        sobj.enqueue(50);

        sobj.Display();

        iRet = sobj.Count();
        System.out.println("Number of elements in the queue are : "+iRet);

        iRet = sobj.dequeue();
        System.out.println("removed elements from queue is : "+iRet);
        
        iRet = sobj.dequeue();
        System.out.println("removed elements from queue is : "+iRet);

        iRet = sobj.dequeue();        
        System.out.println("removed elements from queue is : "+iRet);
        
        sobj.Display();

        iRet = sobj.Count();
        System.out.println("Number of elements in the queue are : "+iRet);
    }
}
