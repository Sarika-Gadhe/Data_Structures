class snode
{
    public int data;
    public snode next;
}

class dnode
{
    public int data;
    public dnode next;
    public dnode prev;
}


class SinglyLL
{
    private snode first;
    private int iCount;

    public SinglyLL()
    {
        System.out.println("Inside constructor");
        first = null;
        iCount = 0;
    }

    public void InsertFirst(int no)
    {
        snode newn = null;

        newn = new snode();

        newn.data = no;
        newn.next = null;

        if(first == null)   // LL is empty
        {
            first = newn;
        }
        else    // LL contains atleast 1 node
        {
            newn.next = first;
            first = newn;
        }
        iCount++;
    }

     public void InsertLast(int no)
    {
        snode newn = null;
        snode temp = null;

        newn = new snode();

        newn.data = no;
        newn.next = null;

        if(first == null)   // LL is empty
        {
            first = newn;
        }
        else    // LL contains atleast 1 node
        {
            temp = first;

            while(temp.next != null)
            {
                temp = temp.next;
            }

            temp.next = newn;
        }
        iCount++;
    }

    public void Display()
    {
        snode temp = null;

        temp = first;

        while(temp != null)
        {
            System.out.print("| "+temp.data+" |-> ");
            temp = temp.next;
        }

        System.out.println("null");
    }

    public int Count()
    {
        return iCount;
    }

    public void DeleteFirst()
    {
      if(first == null)         // LL is empty
      {
        return;
      } 
      else if(first.next == null)   // LL contains 1 node
      {
        first = null;
      } 
      else      // LL contains more than 1 node
      {
        first = first.next;
      }
      iCount--;
    }

    public void DeleteLast()
    {
        snode temp = null;

        if(first == null)         // LL is empty
      {
        return;
      } 
      else if(first.next == null)   // LL contains 1 node
      {
        first = null;
      } 
      else      // LL contains more than 1 node
      {
            temp = first;

            while(temp.next.next != null)
            {
                temp = temp.next;
            }

            temp.next = null;
      }
      iCount--;
    }

    public void InsertAtPos(int no, int pos)
    {
        snode temp = null;
        snode newn = null;

        int iCnt = 0;

        if(pos < 1 || pos > iCount+1)
        {
            System.out.println("Invalid position");
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
            newn = new snode();

            newn.data = no;
            newn.next = null;

            temp = first;

            for(iCnt = 1; iCnt < pos-1; iCnt++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next = newn;

            iCount++;
        }   
    }

    public void DeleteAtPos(int pos)
    {
        snode temp = null;
        int iCnt = 0;

        if(pos < 1 || pos > iCount)
        {
            System.out.println("Invalid position");
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

            for(iCnt = 1; iCnt < pos-1; iCnt++)
            {
                temp = temp.next;
            }

            temp.next = temp.next.next;

            iCount--;
        }   
    }
}

class SinglyCLL
{
    private snode first;
    private snode last;
    private int iCount;

    public SinglyCLL()
    {
        first = null;
        last = null;
        iCount = 0;
    }

    public void InsertFirst(int no)
    {
        snode newn = null;

        newn = new snode();

        newn.data = no;
        newn.next = null;

        if(first == null && last == null)
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
         snode newn = null;

        newn = new snode();

        newn.data = no;
        newn.next = null;

        if(first == null && last == null)
        {      
            first = newn;
            last = newn;

            last.next = first;
        }
        else
        {
           last.next = newn;
           last = newn;
           newn.next = first;
        }

        iCount++;

    }
    
    public void DeleteFirst()
    {
        if(first == null && last == null)
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
            first = first.next;
            last.next = first;
        }
        iCount--;
    }

    public void DeleteLast()
    {
        snode temp = null;

        if(first == null && last == null)
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

            while(temp.next != last)
            {
                temp = temp.next;
            }
            last = temp;
            last.next = first;
        }
        iCount--;
    }
    
    public void Display()
    {
        if(first == null && last == null)
        {
            return;
        }

        snode temp = null;

        temp = first;

        do
        {
            System.out.print("| "+temp.data+" | -> ");
            temp = temp.next;
        }while(temp != last.next);

        System.out.println();
    }

    public int Count()
    {
        return iCount;
    }
    
    public void InsertAtPos(int no, int pos)
    {
        snode temp = null;
        snode newn = null;

        int i = 0;

        if(pos < 1 || pos > iCount + 1)
        {
            System.out.println("Invalid position");
            return;
        }

        if(pos  == 1)
        {
            InsertFirst(no);
        }
        else if(pos == iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            newn = new snode();

            newn.data = no;
            newn.next = null;

            temp = first;

            for(i = 1; i < pos-1; i++)
            {
                temp = temp.next;
            }
            
            newn.next = temp.next;
            temp.next = newn;

            iCount++;

        }
    }
    
    public void DeleteAtPos(int pos)
    {
        snode temp = null;

        int i = 0;

        if(pos < 1 || pos > iCount)
        {
            System.out.println("Invalid position");
            return;
        }

        if(pos  == 1)
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
            
            iCount--;
        }
    }
}


class DoublyCLL
{
    private dnode first;
    private dnode last;
    private int iCount;

    public DoublyCLL()
    {
        first = null;
        last = null;
        iCount = 0;
    }

    public void InsertFirst(int no)
    {
        dnode newn = null;

        newn = new dnode();

        newn.data = no;
        newn.next = null;
        newn.prev = null;

        if(first == null && last == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn.next = first;
            first.prev = newn;
            first = newn;
        }

         last.next = first;
         first.prev = last;

         iCount++;
    }

    public void InsertLast(int no)
    {
        dnode newn = null;

        newn = new dnode();

        newn.data = no;
        newn.next = null;
        newn.prev = null;

        if(first == null && last == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
           last.next = newn;
           newn.prev = last;
           last = newn;
        }

         last.next = first;
         first.prev = last;

         iCount++;
    }

    public void DeleteFirst()
    {
        if(first == null && last == null)
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
            first.prev = last;
            last.next = first;
        }
        iCount--;
    }
    
    public void Display()
    {
        dnode temp = null;

        temp = first;

        if(first == null && last == null)
        {
            System.out.println("LL is empty");
            return;
        }

        do
        {
            System.out.print("| "+temp.data+" | <=> ");
            temp = temp.next;
        }while(temp != first);

        System.out.println();
    }

    public int Count()
    {
        return iCount;
    }

        
    public void InsertAtPos(int no, int pos)
    {
        dnode newn = null;
        dnode temp = null;

        int i = 0;

        if(pos < 1 || pos > iCount + 1)
        {
            System.out.println("Invalid Position");
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
            newn = new dnode();

            newn.data = no;
            newn.prev = null;
            newn.next = null;

            temp = first;

            for(i = 1; i < pos-1; i++)
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

    
    public void DeleteAtPos(int pos)
    {
        dnode temp = null;

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
    
}

class DoublyLLL
{
    private dnode first;
    private int iCount;

    public DoublyLLL()
    {
        first = null;
        iCount = 0;
    }

    public void InsertFirst(int no)
    {
        dnode newn = null;

        newn = new dnode();

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
            first.prev = newn;

            first = newn;
        }
        iCount++;
    }

    public void InsertLast(int no)
    {
        dnode newn = null;
        dnode temp = null;

        newn = new dnode();

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

           while(temp.next != null)
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
            System.out.println("LL is empty");
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
        dnode temp = null;

         if(first == null)
        {
            System.out.println("LL is empty");
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
    
    public void Display()
    {   
       dnode temp = null;

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
        
    public void InsertAtPos(int no, int pos)
    {
        dnode newn = null;
        dnode temp = null;

        int i = 0;

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
            newn = new dnode();

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
        dnode temp = null;

        int i = 0;

        if(pos < 1 || pos > iCount)
        {
            System.out.println("Invalid position");
            return;
        }

        if(pos == 1)
        {
            DeleteFirst();
        }
        else if(pos == iCount + 1)
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
    
}

class ALL_LinkedListinJava
{
    public static void main(String A[])
    {
        System.out.println("=====================================================================================================");
        System.out.println("===================================== Singly Linear Linked List =====================================");
        System.out.println("=====================================================================================================");    
     
        SinglyLL SinglyLinearLLobj = new SinglyLL();
        int iRet = 0;

        SinglyLinearLLobj.InsertFirst(51);
        SinglyLinearLLobj.InsertFirst(21);
        SinglyLinearLLobj.InsertFirst(11);

        SinglyLinearLLobj.InsertLast(101);
        SinglyLinearLLobj.InsertLast(111);        
        SinglyLinearLLobj.InsertLast(121);

        SinglyLinearLLobj.Display();
        iRet = SinglyLinearLLobj.Count();
        System.out.println("Number of elements in the LinkedList are : "+iRet);

        SinglyLinearLLobj.InsertAtPos(105,5);
        SinglyLinearLLobj.Display();
        iRet = SinglyLinearLLobj.Count();
        System.out.println("Number of elements in the LinkedList are : "+iRet);

        SinglyLinearLLobj.DeleteFirst();
        SinglyLinearLLobj.Display();
        iRet = SinglyLinearLLobj.Count();
        System.out.println("Number of elements in the LinkedList are : "+iRet);

        SinglyLinearLLobj.DeleteLast();
        SinglyLinearLLobj.Display();
        iRet = SinglyLinearLLobj.Count();
        System.out.println("Number of elements in the LinkedList are : "+iRet);

        SinglyLinearLLobj.DeleteAtPos(3);
        SinglyLinearLLobj.Display();
        iRet = SinglyLinearLLobj.Count();
        System.out.println("Number of elements in the LinkedList are : "+iRet);
         
        System.out.println("=====================================================================================================");
        System.out.println("===================================== Doubly Linear Linked List =====================================");
        System.out.println("=====================================================================================================");    
     
        DoublyLLL DoublyLinearLLobj = new DoublyLLL();

        DoublyLinearLLobj.InsertFirst(51);
        DoublyLinearLLobj.InsertFirst(21);
        DoublyLinearLLobj.InsertFirst(11);

        DoublyLinearLLobj.InsertLast(101);
        DoublyLinearLLobj.InsertLast(111);        
        DoublyLinearLLobj.InsertLast(121);

        DoublyLinearLLobj.Display();
        iRet = DoublyLinearLLobj.Count();
        System.out.println("Number of elements in the LinkedList are : "+iRet);

        DoublyLinearLLobj.InsertAtPos(105,5);
        DoublyLinearLLobj.Display();
        iRet = DoublyLinearLLobj.Count();
        System.out.println("Number of elements in the LinkedList are : "+iRet);

        DoublyLinearLLobj.DeleteFirst();
        DoublyLinearLLobj.Display();
        iRet = DoublyLinearLLobj.Count();
        System.out.println("Number of elements in the LinkedList are : "+iRet);

        DoublyLinearLLobj.DeleteLast();
        DoublyLinearLLobj.Display();
        iRet = DoublyLinearLLobj.Count();
        System.out.println("Number of elements in the LinkedList are : "+iRet);

        DoublyLinearLLobj.DeleteAtPos(3);
        DoublyLinearLLobj.Display();
        iRet = DoublyLinearLLobj.Count();
        System.out.println("Number of elements in the LinkedList are : "+iRet);

                 
        System.out.println("=====================================================================================================");
        System.out.println("===================================== Singly Circular Linked List ===================================");
        System.out.println("=====================================================================================================");    
     
        SinglyCLL SinglyCircularLLobj = new SinglyCLL();

        SinglyCircularLLobj.InsertFirst(51);
        SinglyCircularLLobj.InsertFirst(21);
        SinglyCircularLLobj.InsertFirst(11);

        SinglyCircularLLobj.InsertLast(101);
        SinglyCircularLLobj.InsertLast(111);        
        SinglyCircularLLobj.InsertLast(121);

        SinglyCircularLLobj.Display();
        iRet = SinglyCircularLLobj.Count();
        System.out.println("Number of elements in the LinkedList are : "+iRet);

        SinglyCircularLLobj.InsertAtPos(105,5);
        SinglyCircularLLobj.Display();
        iRet = SinglyCircularLLobj.Count();
        System.out.println("Number of elements in the LinkedList are : "+iRet);

        SinglyCircularLLobj.DeleteFirst();
        SinglyCircularLLobj.Display();
        iRet = SinglyCircularLLobj.Count();
        System.out.println("Number of elements in the LinkedList are : "+iRet);

        SinglyCircularLLobj.DeleteLast();
        SinglyCircularLLobj.Display();
        iRet = SinglyCircularLLobj.Count();
        System.out.println("Number of elements in the LinkedList are : "+iRet);

        SinglyCircularLLobj.DeleteAtPos(3);
        SinglyCircularLLobj.Display();
        iRet = SinglyCircularLLobj.Count();
        System.out.println("Number of elements in the LinkedList are : "+iRet);

        
                 
        System.out.println("=====================================================================================================");
        System.out.println("===================================== Doubly Circular Linked List ===================================");
        System.out.println("=====================================================================================================");    
     
        DoublyCLL DoublyCircularLLobj = new DoublyCLL();

        DoublyCircularLLobj.InsertFirst(51);
        DoublyCircularLLobj.InsertFirst(21);
        DoublyCircularLLobj.InsertFirst(11);

        DoublyCircularLLobj.InsertLast(101);
        DoublyCircularLLobj.InsertLast(111);        
        DoublyCircularLLobj.InsertLast(121);

        DoublyCircularLLobj.Display();
        iRet = DoublyCircularLLobj.Count();
        System.out.println("Number of elements in the LinkedList are : "+iRet);

        DoublyCircularLLobj.InsertAtPos(105,5);
        DoublyCircularLLobj.Display();
        iRet = DoublyCircularLLobj.Count();
        System.out.println("Number of elements in the LinkedList are : "+iRet);

        DoublyCircularLLobj.DeleteFirst();
        DoublyCircularLLobj.Display();
        iRet = DoublyCircularLLobj.Count();
        System.out.println("Number of elements in the LinkedList are : "+iRet);

        DoublyCircularLLobj.DeleteLast();
        DoublyCircularLLobj.Display();
        iRet = DoublyCircularLLobj.Count();
        System.out.println("Number of elements in the LinkedList are : "+iRet);

        DoublyCircularLLobj.DeleteAtPos(3);
        DoublyCircularLLobj.Display();
        iRet = DoublyCircularLLobj.Count();
        System.out.println("Number of elements in the LinkedList are : "+iRet);

    }
}