#include<iostream>
using namespace std;

template <class T>
class SortingX                  
{
    public:
        T *Arr ;
        int iSize;
        bool Sorted;

        SortingX(int no);
        ~SortingX();
        void Accept();
        void Display();
        void BubbleSort();               
        void BubbleSortEfficient();               
        void SelectionSort();
        void InsertionSort();
};

template <class T>
SortingX <T>:: SortingX(int no)
{
    iSize = no;
    Arr = new T[iSize];
    Sorted = true;
}

template <class T>
SortingX <T> :: ~SortingX()
{
    delete []Arr;
}

template <class T>
void SortingX <T>::  Accept()
{
    cout<<"Enter "<<iSize<<" elements : \n";

    int i = 0;                     

    for(i  = 0; i < iSize; i++)
    {
        cout<<"Enter the element no : "<<i+1<<"\n";
        cin>>Arr[i];

        if((i > 0) && (Sorted == true))          
        {
            if(Arr[i] < Arr[i-1])
            {
                Sorted = false;
            }
        }
    }
}

template <class T>
void SortingX <T>:: Display()
{
        cout<<"Elements of the array are : \n";

    int i = 0;

    for(i  = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\t";
    }
    cout<<"\n";
}

template <class T>
void SortingX <T>::  BubbleSort()                
{
    int i = 0, j = 0 ,temp = 0;

    if(Sorted == true)
    {
        return;
    }
    
    for(i = 0; i < iSize ; i++)              
    {
        for(j = 0; j < iSize - 1; j++)          
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }

        cout<<"Data after pass : "<<i+1<<"\n";
        
        Display();
    }
}

template <class T>
void SortingX <T> :: BubbleSortEfficient()               
{
    int i = 0, j = 0 ,temp = 0;
    bool bFlag = true;

    if(Sorted == true)
    {
        return;
    }
    
    for(i = 0; (i < iSize && bFlag == true) ; i++)              // Outer Loop
    {
        bFlag = false;

        for(j = 0; j < iSize - 1 - i ; j++)          // Inner Loop
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;

                bFlag = true;
            }
        }

        cout<<"Data after pass : "<<i+1<<"\n";
        
        Display();
    }
}

template <class T>
void SortingX <T>:: SelectionSort()
{
    int i = 0, j = 0, min_index = 0, temp = 0;

    for(i = 0; i < iSize - 1; i++)
    {
        min_index = i;

        for(j = i +1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index = j;
            }

        }
        if(i != min_index)
        {
            temp = Arr[i];
            Arr[i] = Arr[min_index];
            Arr[min_index] = temp;
        }
    }
}

template <class T>
void SortingX <T>:: InsertionSort()
{
    int  i = 0, j = 0, selected = 0;

    for(i = 1; i < iSize; i++)
    {
        for(j = i - 1,selected = Arr[i]; (j >= 0) && (Arr[j] > selected); j--)
        {
            Arr[j + 1] = Arr[j];
        }
        Arr[j + 1] = selected;
    }
}

int main()
{
    int iLength = 0;
    int iValue = 0;
    bool bRet = false;
    

    cout<<"Enter the size of array\n";
    cin>> iLength;

    SortingX <int> *aobj = new SortingX<int>(iLength);

    aobj->Accept();

    aobj->Display();

    aobj->InsertionSort();

    cout<<"Data after soting : \n";

    aobj->Display();

    
    delete aobj;
    
    return 0;
}