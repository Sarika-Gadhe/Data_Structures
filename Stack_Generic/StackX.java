class node<T>
{
    public T data;
    public node <T> next;
}

class StackXX<T>
{
    private node <T>first;
    private int iCount;

    public StackXX()
    {
        this.first = null;
        this.iCount = 0;
    }

    public void push(T no)
    {
        node <T>newn = null;
        newn = new node<T>();

        newn.data = no;
        newn.next = null;
        
        newn.next = first;
        first = newn;      

        iCount++;

    }

    public T pop()
    {
        node <T>temp = first;

        if(this.first == null)
        {
            System.out.println("Unable to pop as stack is empty");
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
        node <T>temp = null;

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

public class StackX
{
    public static void main(String A[])
    {
        StackXX <Integer> sobj1 = new StackXX <>();
        int iRet = 0;

        sobj1.push(10);
        sobj1.push(20);
        sobj1.push(30);
        sobj1.push(40);
        sobj1.push(50);

        sobj1.Display();

        iRet = sobj1.Count();
        System.out.println("Number of elements in the stack are : "+iRet);

        iRet = sobj1.pop();
        System.out.println("Poped elements from stack is : "+iRet);
        
        iRet = sobj1.pop();
        System.out.println("Poped elements from stack is : "+iRet);

        iRet = sobj1.pop();        
        System.out.println("Poped elements from stack is : "+iRet);
        
        sobj1.Display();

        iRet = sobj1.Count();
        System.out.println("Number of elements in the stack are : "+iRet);

/////////////////////////////////////////////////////////////////////////////////////////////////!SECTION

        StackXX <String> sobj2 = new StackXX<>();

        String str = null;

        sobj2.push("C");
        sobj2.push("C++");
        sobj2.push("Java");
        sobj2.push("Python");
        sobj2.push("JavaScript");

        sobj2.Display();

        iRet = sobj2.Count();
        System.out.println("Number of elements in the stack are : "+iRet);

        str = sobj2.pop();
        System.out.println("Poped elements from stack is : "+str);
        
        str = sobj2.pop();
        System.out.println("Poped elements from stack is : "+str);

        str = sobj2.pop();        
        System.out.println("Poped elements from stack is : "+str);
        
        sobj2.Display();

        iRet = sobj2.Count();
        System.out.println("Number of elements in the stack are : "+iRet);
    }
}
