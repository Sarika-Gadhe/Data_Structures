#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node <T>* next;
};

template <class T>
class StackX
{
    private:
        struct node <T>*first;
        int iCount;

    public:
        StackX();
        void Push(T);
        int Pop();
        void Display();
        int Count();     
};

template <class T>
StackX <T>:: StackX()
{
    this->first = NULL;
    this->iCount = 0;
}

template <class T>
void StackX <T>:: Push(T no)
{
    struct node <T>*newn = NULL;

    newn = new node<T>;
    newn->data = no;
    newn->next = NULL;

    newn->next = first;
    first = newn;
    
    iCount++;

}

template <class T>
int StackX <T>:: Pop()
{
    struct node <T>*temp = NULL;
    T value = 0;

    if(first == NULL)
    {
        cout<<"Unable to pop element as stack is empty"<<"\n";
        return NULL;
    }
    else
    {
        temp = first;
        value = temp->data;

        first = first->next;
        delete temp;

        iCount--;

        return value;

    } 
}

template <class T>
void StackX <T>:: Display()
{
    struct node <T>*temp = NULL;

    temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | - ";
        temp = temp->next;
    }
    cout<<"\n";
}

template <class T>
int StackX <T>:: Count()
{
    return iCount;
}

int main()
{
    StackX <int> *sobj = new StackX<int>();
    int iRet = 0;

    sobj->Push(50);
    sobj->Push(21);
    sobj->Push(11);
    
    sobj->Display();
    iRet = sobj->Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    iRet = sobj->Pop();
    cout<<"Poped elements is :"<<iRet<<"\n";


    iRet = sobj->Pop();
    cout<<"Poped elements is :"<<iRet<<"\n";    
    
    sobj->Display();
    iRet = sobj->Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    delete sobj;
    return 0;
}