import java.util.Scanner;

class node
{
    int data;
    node next;
    node prev;
}

class DoublyLLL
{
    private node first;
    private int iCount;

    public DoublyLLL()
    {
        this.first = null;
        this.iCount = 0;
    }

    public void InsertFirst(int no)
    {
        node newn = null;

        newn = new node();

        newn.data = no;
        newn.next = null;
        newn.prev = null;

        if(first == null)
        {
            first = newn;
        }
        else
        {
            newn.next = first;
            first = newn;
            first.next.prev = first;
        }
        iCount++;
    }

    public void InsertLast(int no)
    {
        node newn = null;
        node temp = null;

        newn = new node();

        newn.data = no;
        newn.next = null;
        newn.prev = null;

        if(first == null)
        {
            first = newn;
        }
        else
        {
           temp = first;

           while(temp.next!= null)
           {
                temp = temp.next;
           }

           temp.next = newn;
           newn.prev = temp;
        }
        iCount++;
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
        node temp = null;

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
            temp = first;

            while(temp.next != null)
            {
                temp = temp.next;
            }

            temp.prev.next = null;
        }

        iCount--;
    }

    public void InsertAtPos(int no, int pos)
    {
        node newn = null;
        node temp = null;

        int i = 0;

        if(pos < 1 || pos > iCount+1)
        {
            System.out.println("Invalid Position");
            return;
        }
        
        if(pos == 1)
        {
            InsertFirst(no);
        }
        else if(pos == iCount+1)
        {
            InsertLast(no);
        }
        else 
        {
            newn = new node();

            newn.data = no;
            newn.next = null;
            newn.prev = null;

            temp = first;

            for(i = 1; i < pos-1; i++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            newn.next.prev = newn;
            temp.next = newn;
            newn.prev = temp;

            iCount++;
        }

    }

    public void DeleteAtPos(int pos)
    {
        node temp = null;

        int i = 0;

        if(pos < 1 || pos > iCount)
        {
            System.out.println("Invalid Position");
            return;
        }
        
        if(pos == 1)
        {
            DeleteFirst();
        }
        else if(pos == iCount)
        {
            DeleteLast();
        }
        else 
        {
            temp = first;

            for(i = 1; i < pos-1; i++)
            {
                temp = temp.next;
            }

            temp.next = temp.next.next;
            temp.next.prev = temp;

            iCount--;
        }

    }

    public void Display()
    {
        node temp = null;

        if(first == null)
        {
            System.out.println("LL is empty");
            return;
        }

        temp = first;

        System.out.print("null <=> ");
        while(temp != null)
        {
            System.out.print("| "+temp.data+" | <=> ");
            temp = temp.next;
        }

        System.out.println("null");
    }

    public int Count()
    {
        return iCount;
    }

    public int CountEven()
    {
        node temp =  null;
        int iCountEven = 0;

        temp = first;

        while(temp != null)
        {
            if(temp.data % 2 == 0)
            {
                iCountEven++;

            }
            temp = temp.next;
        }

        return iCountEven;
    }

    public int CountOdd()
    {
        node temp =  null;
        int iCountOdd = 0;

        temp = first;

        while(temp != null)
        {
            if(temp.data % 2 != 0)
            {
                iCountOdd++;

            }
            temp = temp.next;
        }

        return iCountOdd;
    }

    public int Summation()
    {
        node temp = null;
        int iSum = 0;

        temp = first;

        while(temp != null)
        {
            iSum = iSum + temp.data;
            temp = temp.next;
            
        }

        return iSum;
    }

    public int Maximum()
    {
        node temp = null;
        int iMax = 0;

        temp = first;
        
        iMax = temp.data;

        while(temp != null)
        {
            if(iMax < temp.data)
            {
                iMax = temp.data;
            }
            temp = temp.next;
        }

        return iMax;
    }

    public int Minimum()
    {
        node temp = null;
        int iMin = 0;

        temp = first;
        
        iMin = temp.data;

        while(temp != null)
        {
            if(iMin > temp.data)
            {
                iMin = temp.data;
            }
            temp = temp.next;
        }

        return iMin;
    }

    public int Frequency(int iNo)
    {
        node temp = null;
        int iFrequency = 0;

        temp = first;

        while(temp != null)
        {
            if(temp.data == iNo)
            {
                iFrequency++;
            }
            temp  = temp.next;
        }

        return iFrequency;
    }

    public boolean Search(int iNo)
    {
        node temp = null;
        
        temp = first;

        while(temp != null)
        {
            if(temp.data == iNo)
            {
                return true;
            }
            temp = temp.next;
        }
        return false;

    }

}

public class DoublyLinearLL
{
    public static void main(String A[])
    {
        DoublyLLL list = new DoublyLLL();

        Scanner sobj = new Scanner(System.in);
        
        int iValue = 0, ichoice = 0, ipos = 0,iRet = 0;
        boolean bRet = false;
    

        while(true)
        {
            
            System.out.println("-------------------------------------------------------------------------------");
            System.out.println("----------------------------- Doubly Linear Linked List -----------------------");
            System.out.println("-------------------------------------------------------------------------------");

            System.out.println("1 : Insert First");
            System.out.println("2 : Insert Last");
            System.out.println("3 : Insert At Position");
            System.out.println("4 : Delete First");
            System.out.println("5 : Delete Last");
            System.out.println("6 : Delete At Position");
            System.out.println("7 : Display List");
            System.out.println("8 : Count Total Number of Nodes");
            System.out.println("9 : Count Even Nodes");
            System.out.println("10 : Count Odd Nodes");
            System.out.println("11 : Summation of All Elements");
            System.out.println("12 : Find Maximum Element");
            System.out.println("13 : Find Minimum Elements");
            System.out.println("14 : Search an Element");
            System.out.println("15 : Frequency of a number");
            System.out.println("0 : Exit");
            System.out.println("-------------------------------------------------------------------------------");
            
            System.out.println("Please Enter your Choice : ");
            ichoice = sobj.nextInt();

            switch(ichoice)
            {
                case 1: 
                    System.out.println("Enter the value that you want to insert at first : ");
                    iValue = sobj.nextInt();
                    list.InsertFirst(iValue);
                    break;
                    
                case 2: 
                    System.out.println("Enter the value that you want to insert at last :");
                    iValue = sobj.nextInt();
                    list.InsertLast(iValue);
                    break;

                case 3: 
                    System.out.println("Enter the value that you want to insert at a specific position :");
                    iValue = sobj.nextInt();
                    System.out.println("Enter the position where you want to insert the value: ");
                    ipos = sobj.nextInt();
                    list.InsertAtPos(iValue,ipos);
                    break;

                case 4: 
                    System.out.println("Delete the first node from the linked list.");
                    list.DeleteFirst();
                    break;

                case 5: 
                    System.out.println("Delete the last node from the linked list.");
                    list.DeleteLast();
                    break;

                case 6: 
                    System.out.println("Enter the position of the node that you want to delete:");
                    ipos = sobj.nextInt();;
                    list.DeleteAtPos(ipos);
                    break;

                case 7: 
                    System.out.println("Displaying the linked list:");
                    list.Display();
                    break;

                case 8:
                    iRet = list.Count(); 
                    System.out.println("Total number of nodes are : "+iRet);
                    break;

                case 9: 
                    iRet = list.CountEven();
                    System.out.println("Total number of Even nodes are : "+iRet);
                    break;

                case 10: 
                    iRet = list.CountOdd();
                    System.out.println("Total number of Odd nodes are : "+iRet);
                    break;

                case 11: 
                    iRet = list.Summation();
                    System.out.println("Summation of total nodes are : "+iRet);
                    break;

                case 12: 
                    iRet = list.Maximum();
                    System.out.println("Maximum Elements is : "+iRet);
                    break;

                case 13: 
                    iRet = list.Minimum();
                    System.out.println("Minimum Element is : "+iRet);
                    break;

                case 14: 
                    System.out.println("Enter node that you want to search : ");
                    iValue = sobj.nextInt();;
                    bRet = list.Search(iValue);

                    if(bRet)
                    {
                        System.out.println("Element is present.");
                    }
                    else
                    {
                        System.out.println("Element is not present.");
                    }

                    break;

                case 15: 
                    System.out.println("Enter number to check frequency : ");
                    iValue = sobj.nextInt();;
                    iRet = list.Frequency(iValue);
                    System.out.println("Frequency : "+iRet);
                    break;

                case 0: 
                    System.out.println("Thank you for using the Doubly Linear Linked List application...!");
                    sobj.close();
                    return;

                default :
                    System.out.println("Invalid Choice.");    
            }
        }
    }
}