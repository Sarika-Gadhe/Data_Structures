import java.util.Scanner;

class node <T>
{
    T data;
    node <T> next;
    node <T> prev;
}

class DoublyLLL<T>
{
    private node <T>first;
    private int iCount;

    public DoublyLLL()
    {
        this.first = null;
        this.iCount = 0;
    }

    public void InsertFirst(T no)
    {
        node <T>newn = null;

        newn = new node<T>();

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

    public void InsertLast(T no)
    {
        node <T>newn = null;
        node <T>temp = null;

        newn = new node<T>();

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
        node <T> temp = null;

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

    public void InsertAtPos(T no, int pos)
    {
        node <T> newn = null;
        node <T> temp = null;

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
            newn = new node<T>();

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
        node <T> temp = null;

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
        node <T>temp = null;

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
}

public class DoublyLinearLL
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);
        int ipos = 0,iRet = 0;

        System.out.println("Select Data Type : ");
        System.out.println("1. Integer");
        System.out.println("2. Double");
        System.out.println("3. Character");
        System.out.println("Enter Your Choice : ");

        int datatype = sobj.nextInt();
        sobj.nextLine();

        int ichoice = 1;

        if(datatype == 1)
        {
            DoublyLLL<Integer> list = new DoublyLLL<Integer>();
            int iValue = 0;

            while(ichoice != 0)
            {
                System.out.println("-------------------------------------------------------------------------------");
                System.out.println("----------------------------- Doubly Linear Linked List In Generic -----------------------");
                System.out.println("-------------------------------------------------------------------------------");

                System.out.println("1 : Insert First");
                System.out.println("2 : Insert Last");
                System.out.println("3 : Insert At Position");
                System.out.println("4 : Delete First");
                System.out.println("5 : Delete Last");
                System.out.println("6 : Delete At Position");
                System.out.println("7 : Display List");
                System.out.println("8 : Count Total Number of Nodes");
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
                    
                    case 0: 
                        System.out.println("Thank you for using the Doubly Linear Linked List In Generic application...!");
                        sobj.close();
                        return;

                    default :
                        System.out.println("Invalid Choice.");   

                }
                
            }
        } 
        else if(datatype == 2)    
        {
             DoublyLLL<Double> list = new DoublyLLL<Double>();
             double iValue = 0.0;

            while(ichoice != 0)
            {
                System.out.println("-------------------------------------------------------------------------------");
                System.out.println("----------------------------- Doubly Linear Linked List In Generic -----------------------");
                System.out.println("-------------------------------------------------------------------------------");

                System.out.println("1 : Insert First");
                System.out.println("2 : Insert Last");
                System.out.println("3 : Insert At Position");
                System.out.println("4 : Delete First");
                System.out.println("5 : Delete Last");
                System.out.println("6 : Delete At Position");
                System.out.println("7 : Display List");
                System.out.println("8 : Count Total Number of Nodes");
                System.out.println("0 : Exit");
                System.out.println("-------------------------------------------------------------------------------");
                
                System.out.println("Please Enter your Choice : ");
                
                ichoice = sobj.nextInt();

                switch(ichoice)
                {
                    case 1: 
                        System.out.println("Enter the value that you want to insert at first : ");
                        iValue = sobj.nextDouble();
                        list.InsertFirst(iValue);
                        break;
                        
                    case 2: 
                        System.out.println("Enter the value that you want to insert at last :");
                        iValue = sobj.nextDouble();
                        list.InsertLast(iValue);
                        break;

                    case 3: 
                        System.out.println("Enter the value that you want to insert at a specific position :");
                        iValue = sobj.nextDouble();
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
                    
                    case 0: 
                        System.out.println("Thank you for using the Doubly Linear Linked List In Generic application...!");
                        sobj.close();
                        return;

                    default :
                        System.out.println("Invalid Choice.");    

                }
            }    
        }  
        else if(datatype == 3)    
        {
             DoublyLLL<Character> list = new DoublyLLL<Character>();
             char iValue;

            while(ichoice != 0)
            {
                System.out.println("-------------------------------------------------------------------------------");
                System.out.println("----------------------------- Doubly Linear Linked List In Generic -----------------------");
                System.out.println("-------------------------------------------------------------------------------");

                System.out.println("1 : Insert First");
                System.out.println("2 : Insert Last");
                System.out.println("3 : Insert At Position");
                System.out.println("4 : Delete First");
                System.out.println("5 : Delete Last");
                System.out.println("6 : Delete At Position");
                System.out.println("7 : Display List");
                System.out.println("8 : Count Total Number of Nodes");
                System.out.println("0 : Exit");
                System.out.println("-------------------------------------------------------------------------------");
                
                System.out.println("Please Enter your Choice : ");
                
                ichoice = sobj.nextInt();

                switch(ichoice)
                {
                    case 1: 
                        System.out.println("Enter the value that you want to insert at first : ");
                        iValue = sobj.next().charAt(0);
                        list.InsertFirst(iValue);
                        break;
                        
                    case 2: 
                        System.out.println("Enter the value that you want to insert at last :");
                        iValue = sobj.next().charAt(0);
                        list.InsertLast(iValue);
                        break;

                    case 3: 
                        System.out.println("Enter the value that you want to insert at a specific position :");
                        iValue = sobj.next().charAt(0);
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
                        ipos = sobj.nextInt();
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
                    
                    case 0: 
                        System.out.println("Thank you for using the Doubly Linear Linked List In Generic application...!");
                        sobj.close();
                        return;

                    default :
                        System.out.println("Invalid Choice.");    

                }
            }    
        }  
        else 
        {
            System.out.println("Invalid Choice...!");
        }

    }
}