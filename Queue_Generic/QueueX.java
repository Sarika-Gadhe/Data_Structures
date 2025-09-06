class node<T>
{
    T data;
    node <T>next;
}

class QueueXX<T>
{
    private node <T>first;
    private int iCount;

    public QueueXX()
    {
        this.first = null;
        this.iCount = 0 ;
    }

    public void enqueue(T no)
    {
        node <T>newn = null;
        node <T>temp = null;

        newn = new node<T>();

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

    public T dequeue()
    {
        node <T> temp = this.first;

        if(this.first == null)
        {
            System.out.println("Unable to remove as queue is empty");
            return null;
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
        node <T> temp = null;

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
        QueueXX <Double> sobj = new QueueXX<>();
        int iRet = 0;
        double dRet= 0.0;

        sobj.enqueue(10.0);
        sobj.enqueue(20.0);
        sobj.enqueue(30.0);
        sobj.enqueue(40.0);
        sobj.enqueue(50.0);

        sobj.Display();

        iRet = sobj.Count();
        System.out.println("Number of elements in the queue are : "+iRet);

        dRet = sobj.dequeue();
        System.out.println("removed elements from queue is : "+dRet);
        
        dRet = sobj.dequeue();
        System.out.println("removed elements from queue is : "+dRet);

        dRet = sobj.dequeue();        
        System.out.println("removed elements from queue is : "+dRet);
        
        sobj.Display();

        iRet = sobj.Count();
        System.out.println("Number of elements in the queue are : "+iRet);


    }
}
