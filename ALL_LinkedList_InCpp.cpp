#include<iostream>
using namespace std;

typedef struct snode
{
    int data;
    struct snode *next;
} SNODE, * SPNODE ;

typedef struct dnode
{
    int data;
    struct dnode *next;
    struct dnode *prev;
} DNODE, * DPNODE;


class SinglyLinearLL
{
    private:
        SPNODE first;
        int iCount;

    public:
        SinglyLinearLL()
        {
            this->first = NULL;
            this->iCount = 0;
        }  
        
        void InsertFirst(int no)
        {
            SPNODE newn = NULL;

            newn = new SNODE;

            newn->data = no;
            newn->next = NULL;

            if(first == NULL)
            {
                first = newn;
            }
            else
            {
                newn->next = first;
                first = newn;
            }
            iCount++;
        }

        void InsertLast(int no)
        {
            SPNODE newn = NULL;
            SPNODE temp = NULL;

            newn = new SNODE;

            newn->data = no;
            newn->next = NULL;

            if(first == NULL)
            {
                first = newn;
            }
            else
            {
                temp = first;

                while(temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newn;
            }
            iCount++;
        }

        void DeleteFirst()
        {
            SPNODE temp = NULL;

            if(first == NULL)
            {
                cout<<"LL is Empty"<<"\n";
                return;
            }
            else if(first->next == NULL)
            {
                delete first;

                first = NULL;
            }
            else
            {
                temp = first;

                first = first->next;

                delete temp;
            }
            iCount--;
        }

        void DeleteLast()
        {
            SPNODE temp = NULL;

            if(first == NULL)
            {
                cout<<"LL is Empty"<<"\n";
                return;
            }
            else if(first->next == NULL)
            {
                delete first;

                first = NULL;
            }
            else
            {
                temp = first;

                while(temp->next->next != NULL)
                {
                    temp = temp->next;
                }
                delete temp->next;

                temp->next = NULL;

            }
            iCount--;
        }

        void Display()
        {
            SPNODE temp = NULL;
            
            temp = first;

            while(temp != NULL)
            {
                cout<<"| "<<temp->data<<" | -> ";
                temp = temp->next;
            }
            cout<<"NULL"<<"\n";
        }

        int Count()
        {
            return iCount;
        }

        void InsertAtPos(int no, int pos)
        {
            SPNODE newn = NULL;
            SPNODE temp = NULL;

            int i = 0;

            if(pos < 1 || pos > iCount + 1)
            {
                cout<<"Invalid Position"<<"\n";
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
                newn = new SNODE;

                newn->data = no;
                newn->next = NULL;

                temp = first;

                for(i = 1; i < pos-1; i++)
                {
                    temp = temp->next;
                }
                
                newn->next = temp->next;
                temp->next = newn;

                iCount++;
            }

        }
        
        void DeleteAtPos(int pos)
        {
            SPNODE temp = NULL;
            SPNODE target = NULL;

            int i = 0;

            if(pos < 1 || pos > iCount)
            {
                cout<<"Invalid Position"<<"\n";
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
                    temp = temp->next;
                }
                target = temp->next;
                temp->next = target->next;

                delete target;

                iCount--;

            }

        }
};

class DoublyLinearLL
{
    private:
        DPNODE first;
        int iCount;

    public:
        DoublyLinearLL()
        {
            this->first = NULL;
            this->iCount = 0;
        }

        void InsertFirst(int no)
        {
            DPNODE newn = NULL;
            
            newn = new DNODE;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(first == NULL)
            {
                first = newn;
            }
            else
            {
                newn->next = first;
                first->prev = newn;

                first = newn;
            }
            iCount++;
        }

        void InsertLast(int no)
        {
            DPNODE newn = NULL;
            DPNODE temp = NULL;

            newn = new DNODE;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(first == NULL)
            {
                first = newn;
            }
            else
            {
                temp = first;

                while(temp->next != NULL)
                {
                    temp = temp->next;
                }
                
                newn->prev = temp;
                temp->next = newn;
            }
            iCount++;
        }

        void DeleteFirst()
        {
            if(first == NULL)
            {
                return;
            }
            else if(first->next == NULL)
            {
                delete first;

                first = NULL;
            }
            else
            {
                first = first->next;
                delete first->prev;
                first->prev = NULL;  
            }
            iCount--;
        }

        void DeleteLast()
        {
            DPNODE temp = NULL;

            if(first == NULL)
            {
                return;
            }
            else if(first->next == NULL)
            {
                delete first;

                first = NULL;
            }
            else
            {
                temp = first;

                while(temp->next->next != NULL)
                {
                    temp = temp->next;
                }

                delete temp->next;
                temp->next = NULL;
            }
            iCount--;
        }

        void Display()
        {
            DPNODE temp;

            temp = first;

            cout<<"NULL <=> ";
            while(temp != NULL)
            {
                cout<<"| "<<temp->data<<" | <=> ";
                temp = temp->next;
            }

            cout<<"NULL"<<"\n";
            
        }

        int Count()
        {
            return iCount;
        }

        void InsertAtPos(int no, int pos)
        {
            DPNODE temp = NULL;
            DPNODE newn = NULL;

            int i = 0;

            if(pos < 1 || pos > iCount +1)
            {
                cout<<"Position is invalid"<<"\n";
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
                newn = new DNODE;

                newn->data = no;
                newn->next = NULL;
                newn->prev = NULL;

                temp = first;

                for(i = 1; i < pos-1; i++)
                {
                    temp = temp->next;
                }
                newn->next = temp->next;
                temp->next->prev = newn;
                newn->prev = temp;
                temp->next = newn;

                iCount++;
            }
        }

        void DeleteAtPos(int pos)
        {
            DPNODE temp = NULL;
            DPNODE target = NULL;

            int i = 0;

            if(pos < 1 || pos > iCount)
            {
                cout<<"Position is invalid"<<"\n";
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
                    temp = temp->next;
                }
               target = temp->next;

               temp->next = target->next;
               target->next->prev = temp;

               delete target;

                iCount--;
            }

        }
};


class SinglyCLL
{
    private:
        SPNODE first;
        SPNODE last;
        int iCount;

    public:
        SinglyCLL()
        {
            this->first = NULL;
            this->last = NULL;
            this->iCount = 0;
        }

        void InsertFirst(int no)
        {
            SPNODE newn = NULL;

            newn = new SNODE;

            newn->data = no;
            newn->next = NULL;

            if(first == NULL && last == NULL)   // if(iCount == 0)
            {
                first = newn;
                last = newn;

                last->next = first;
            }
            else
            {
                newn->next = first;
                first = newn;

                last->next = first;
            }

            iCount++;
        }

        void InsertLast(int no)
        {
            SPNODE newn = NULL;

            newn = new SNODE;

            newn->data = no;
            newn->next = NULL;

            if(first == NULL && last == NULL)   // if(iCount == 0)
            {
                first = newn;
                last = newn;

                last->next = first;
            }
            else
            {
                last->next = newn;
                last = newn;

                last->next = first;
            }

            iCount++;
        }

        void DeleteFirst()
        {
            if(first == NULL && last == NULL)
            {
                return;
            }
            else if(first == last)
            {
                delete first;

                first = NULL;
                last = NULL;
            }
            else
            {
                first = first -> next;
                delete last->next;

                last->next = first;
            }
            iCount--;
        }

        void DeleteLast()
        {
            SPNODE temp = NULL;

            if(first == NULL && last == NULL)
            {
                return;
            }
            else if(first == last)
            {
                delete first;

                first = NULL;
                last = NULL;
            }
            else
            {
                temp = first;

                while(temp -> next != last)
                {
                    temp = temp -> next;
                }

                delete last;
                last = temp;

                last->next = first;
            }
            iCount--;
        }

        void Display()
        {
            if(first == NULL && last == NULL)
            {
                return;
            }

            SPNODE temp = first;

            do
            {
                cout<<"| "<<temp->data<<" | -> ";
                temp = temp -> next;
            } while (temp != last ->next);
            
            cout<<"\n";
        }

        int Count()
        {
            return iCount;
        }

        void DeleteAtPos(int pos)
        {
            SPNODE temp = NULL;
            SPNODE target = NULL;
            
            int i = 0;
            
            if(pos < 1 || pos > iCount)
            {
                cout<<"Invalid position\n";
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
                    temp = temp -> next;
                }

                target = temp -> next;

                temp->next = target->next;
                delete target;

                iCount--;
            }
        }

        void InsertAtPos(int no, int pos)
        {
            SPNODE temp = NULL;
            SPNODE newn = NULL;

            int i = 0;

            if(pos < 1 || pos > iCount+1)
            {
                cout<<"Invalid position\n";
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
                newn = new SNODE;

                newn->data = no;
                newn->next = NULL;

                temp = first;

                for(i = 1; i < pos -1; i++)
                {
                    temp = temp -> next;
                }

                newn->next = temp -> next;
                temp->next = newn;

                iCount++;
            }
        }
};



class DoublyCLL
{
    private:
        DPNODE first;
        DPNODE last;
        int iCount;

    public:
        DoublyCLL();

        void Display();
        int Count();

        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int,int);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
};

DoublyCLL :: DoublyCLL()
{
    
    first = NULL;
    last = NULL;
    iCount = 0;
}

void DoublyCLL :: InsertFirst(int no)
{
    DPNODE newn = NULL;

    newn = new DNODE;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)   // LL is empty
    {
        first = newn;
        last = newn;
    }   
    else    // LL contains atleast one node
    {
        newn->next = first;
        first->prev = newn;

        first = newn;
    } 

    last->next = first;
    first->prev = last;

    iCount++;
}

void DoublyCLL :: InsertLast(int no)
{
    DPNODE newn = NULL;

    newn = new DNODE;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)   // LL is empty
    {
        first = newn;
        last = newn;
    }   
    else    // LL contains atleast one node
    {
        last->next = newn;
        newn->prev = last;

        last = newn;
    } 

    last->next = first;
    first->prev = last;
    
    iCount++;
}

void DoublyCLL :: Display()
{
    DPNODE temp = NULL;

    temp = first;

    if(first == NULL && last == NULL)
    {
        cout<<"LinkedList is empty\n";
        return;
    }

    cout<<"<=> ";
    do
    {
        cout<<"| "<< temp->data <<" | <=> ";
        temp = temp->next;   
    } while (temp != first);
    cout<<"\n";
}

int DoublyCLL :: Count()
{
    return iCount;  
}

void DoublyCLL :: DeleteFirst()
{
    if(first == NULL && last == NULL)   // LL is empty
    {
        return;
    }
    else if(first == last)  // LL contains 1 node
    {
        delete first;
    
        first = NULL;
        last = NULL;
    }
    else    // LL contains more than 1 nodes
    {
        first = first -> next;
        delete first->prev;     // delete last->next;

        last->next = first;
        first->prev = last;
    }

    iCount--;
}

void DoublyCLL :: DeleteLast()
{
    if(first == NULL && last == NULL)   // LL is empty
    {
        return;
    }
    else if(first == last)  // LL contains 1 node
    {
        delete last;
    
        first = NULL;
        last = NULL;
    }
    else    // LL contains more than 1 nodes
    {
        last = last -> prev;
        delete last->next;

        last->next = first;
        first->prev = last;
    }

    iCount--;
}

void DoublyCLL :: InsertAtPos(int no, int pos)
{
    DPNODE temp = NULL;
    DPNODE newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position\n";
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
        newn = new DNODE;
        
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

void DoublyCLL :: DeleteAtPos(int pos)
{
    DPNODE temp = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
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
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}


int main()
{
    cout<<"=====================================================================================================\n";
    cout<<"===================================== Singly Linear Linked List =====================================\n";
    cout<<"=====================================================================================================\n";
    cout<<endl;

    SinglyLinearLL SinglyLinearLLobj;


    int iRet = 0;

    SinglyLinearLLobj.InsertFirst(51);
    SinglyLinearLLobj.InsertFirst(21);
    SinglyLinearLLobj.InsertFirst(11);
    
    SinglyLinearLLobj.Display();
    iRet = SinglyLinearLLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    SinglyLinearLLobj.InsertLast(101);
    SinglyLinearLLobj.InsertLast(111);
    SinglyLinearLLobj.InsertLast(121);
    
    SinglyLinearLLobj.Display();
    iRet = SinglyLinearLLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    SinglyLinearLLobj.DeleteFirst();

    SinglyLinearLLobj.Display();
    iRet = SinglyLinearLLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    SinglyLinearLLobj.DeleteLast();

    SinglyLinearLLobj.Display();
    iRet = SinglyLinearLLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    SinglyLinearLLobj.InsertAtPos(151,3);
        
    SinglyLinearLLobj.Display();
    iRet = SinglyLinearLLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";
    
    SinglyLinearLLobj.DeleteAtPos(3);
        
    SinglyLinearLLobj.Display();
    iRet = SinglyLinearLLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";
    
    cout<<endl;
    cout<<"=====================================================================================================\n";
    cout<<"===================================== Doubly Linear Linked List =====================================\n";
    cout<<"=====================================================================================================\n";
    cout<<endl;

    DoublyLinearLL DoublyLinearLLobj;


    DoublyLinearLLobj.InsertFirst(21);
    DoublyLinearLLobj.InsertFirst(51);
    DoublyLinearLLobj.InsertFirst(11);
    
    DoublyLinearLLobj.Display();
    iRet = DoublyLinearLLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    DoublyLinearLLobj.InsertLast(101);
    DoublyLinearLLobj.InsertLast(111);
    DoublyLinearLLobj.InsertLast(121);
    
    DoublyLinearLLobj.Display();
    iRet = DoublyLinearLLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    DoublyLinearLLobj.DeleteFirst();

    DoublyLinearLLobj.Display();
    iRet = DoublyLinearLLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    DoublyLinearLLobj.DeleteLast();

    DoublyLinearLLobj.Display();
    iRet = DoublyLinearLLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    DoublyLinearLLobj.InsertAtPos(151,3);
        
    DoublyLinearLLobj.Display();
    iRet = DoublyLinearLLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";
    
    DoublyLinearLLobj.DeleteAtPos(3);
        
    DoublyLinearLLobj.Display();
    iRet = DoublyLinearLLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    cout<<endl;
    cout<<"=====================================================================================================\n";
    cout<<"===================================== Singly Circular Linked List =====================================\n";
    cout<<"=====================================================================================================\n";
    cout<<endl;  
    
    SinglyCLL SinglyCircularLLobj;


    SinglyCircularLLobj.InsertFirst(21);
    SinglyCircularLLobj.InsertFirst(51);
    SinglyCircularLLobj.InsertFirst(11);
    
    SinglyCircularLLobj.Display();
    iRet = SinglyCircularLLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    SinglyCircularLLobj.InsertLast(101);
    SinglyCircularLLobj.InsertLast(111);
    SinglyCircularLLobj.InsertLast(121);
    
    SinglyCircularLLobj.Display();
    iRet = SinglyCircularLLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    SinglyCircularLLobj.DeleteFirst();

    SinglyCircularLLobj.Display();
    iRet = SinglyCircularLLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    SinglyCircularLLobj.DeleteLast();

    SinglyCircularLLobj.Display();
    iRet = SinglyCircularLLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    SinglyCircularLLobj.InsertAtPos(151,3);
        
    SinglyCircularLLobj.Display();
    iRet = SinglyCircularLLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";
    
    SinglyCircularLLobj.DeleteAtPos(3);
        
    SinglyCircularLLobj.Display();
    iRet = SinglyCircularLLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";
    
    cout<<endl;
    cout<<"=====================================================================================================\n";
    cout<<"===================================== Doubly Circular Linked List =====================================\n";
    cout<<"=====================================================================================================\n";
    cout<<endl;   
    
    
    DoublyCLL DoublyCircularLLobj;


    DoublyCircularLLobj.InsertFirst(21);
    DoublyCircularLLobj.InsertFirst(51);
    DoublyCircularLLobj.InsertFirst(11);
    
    DoublyCircularLLobj.Display();
    iRet = DoublyCircularLLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    DoublyCircularLLobj.InsertLast(101);
    DoublyCircularLLobj.InsertLast(111);
    DoublyCircularLLobj.InsertLast(121);
    
    DoublyCircularLLobj.Display();
    iRet = DoublyCircularLLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    DoublyCircularLLobj.DeleteFirst();

    DoublyCircularLLobj.Display();
    iRet = DoublyCircularLLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    DoublyCircularLLobj.DeleteLast();

    DoublyCircularLLobj.Display();
    iRet = DoublyCircularLLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    DoublyCircularLLobj.InsertAtPos(151,3);
        
    DoublyCircularLLobj.Display();
    iRet = DoublyCircularLLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";
    
    DoublyCircularLLobj.DeleteAtPos(3);
        
    DoublyCircularLLobj.Display();
    iRet = DoublyCircularLLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";    
    

    return 0;
}