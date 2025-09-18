#include<iostream>
using namespace std;

template <class T>
class SearchingX                
{
    public:
        T *Arr;
        int iSize;
        bool Sorted;

        SearchingX(int no);
        ~SearchingX();
        void Accept();
        void Display();
        bool LinearSearch(T no);                     
        bool BiDirectionalSearch(T no); 
        bool BinarySearchInc(T no);                 
        bool BinarySearchDec(T no);             
        bool BinarySearchEfficientInc(T no);
        bool BinarySearchEfficientDec(T no);
        bool CheckSortedInc();
        bool CheckSortedDec();
};

template <class T>
SearchingX <T> :: SearchingX(int no)
{
    iSize = no;
    Arr = new T[iSize];
    Sorted = true;
}

template <class T>
SearchingX <T> :: ~SearchingX()
{
    delete []Arr;
}

template <class T>
void SearchingX <T> :: Accept()
{
    cout<<"Enter "<<iSize<<" elements : \n";

    int i = 0;                     

    for(i  = 0; i < iSize; i++)
    {
        cout<<"Enter the element no : "<<i+1<<"\n";
        cin>>Arr[i];

        if((i > 0) && (Sorted == true))            // Important
        {
            if(Arr[i] < Arr[i-1])
            {
                Sorted = false;
            }
        }
    }
}

template <class T>
void SearchingX <T> :: Display()
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
bool SearchingX <T> :: LinearSearch(T no)                        // TimeComplexity - N
{
    int i = 0;
    bool bFlag = false;

    if(Sorted == true)
    {
        cout<<"data is Sorted\n";
        return BinarySearchEfficientInc(no);
    }

    for(i = 0; i< iSize; i++)
    {
        if(Arr[i] == no)
        {

            bFlag = true;
            break;
        }
    }

    return bFlag;

}

template <class T>
bool SearchingX <T> :: BiDirectionalSearch(T no)                          // RimeComplexity -  N/2 
{
    int iStart = 0;
    int iEnd = 0;
    bool bFlag = false;

    for(iStart = 0,iEnd = iSize-1 ; iStart <= iEnd ; iStart++,iEnd--)
    {
        if(Arr[iStart] == no || Arr[iEnd] == no)
        {

            bFlag = true;
            break;
        }
    }

    return bFlag;

}

template <class T>
bool SearchingX <T> :: BinarySearchInc(T no)                // Increasing order
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;


    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if(Arr[iMid] == no)
        {
            bFlag = true;
            break;
        }
        else if(no < Arr[iMid])     // First half (left Window)
        {
            iEnd = iMid - 1;
        }
        else if(no > Arr[iMid])    // second half (right Window)
        {
            iStart = iMid + 1;
        }

    } // End of while

    return bFlag;
    
}

template <class T>
bool SearchingX <T> :: BinarySearchDec(T no)                // Decreasing order
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;


    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if(Arr[iMid] == no)
        {
            bFlag = true;
            break;
        }
        else if(no > Arr[iMid])     // First half (left Window)
        {
            iEnd = iMid - 1;
        }
        else if(no < Arr[iMid])    // second half (right Window)
        {
            iStart = iMid + 1;
        }

    } // End of while

    return bFlag;
    
}

template <class T>
bool SearchingX <T> :: BinarySearchEfficientInc(T no)
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;

    if(Sorted = false)           // New
    {
        cout<<"Data is not sorted\n";
        return LinearSearch(no);             // Important - it gives return value of LinearSearch fuction
    }

    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if((Arr[iMid] == no) || (Arr[iStart] == no) || (Arr[iEnd] == no))       // change
        {
            bFlag = true;
            break;
        }
        else if(no < Arr[iMid])     // First half (left Window)
        {
            iEnd = iMid - 1;
        }
        else if(no > Arr[iMid])    // second half (right Window)
        {
            iStart = iMid + 1;
        }

    } // End of while

    return bFlag;
    
}

template <class T>
bool SearchingX <T> :: BinarySearchEfficientDec(T no)
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;


    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if((Arr[iMid] == no) || (Arr[iStart] == no) || (Arr[iEnd] == no))       // change
        {
            bFlag = true;
            break;
        }
        else if(no > Arr[iMid])     // First half (left Window)
        {
            iEnd = iMid - 1;
        }
        else if(no < Arr[iMid])    // second half (right Window)>
        {
            iStart = iMid + 1;
        }

    } // End of while

    return bFlag;
    
}

template <class T>
bool SearchingX <T> :: CheckSortedInc()
{
    bool bFlag= true;
    int i = 0;

    for(i = 0; i < iSize - 1; i++)
    {
        if(Arr[i] > Arr[i+1])             // change          
        {
            bFlag = false;
            break;
        }
        
    }

    return bFlag;
}

template <class T>
bool SearchingX <T> :: CheckSortedDec()                            
{
    bool bFlag= true;
    int i = 0;

    for(i = 0; i < iSize - 1; i++)
    {
        if(Arr[i] < Arr[i+1])                 
        {
            bFlag = false;
            break;
        }
        
    }

    return bFlag;
}

int main()
{
    int iLength = 0;
    int iValue = 0;
    bool bRet = false;
    

    cout<<"Enter the size of array\n";
    cin>> iLength;

    SearchingX <int>*aobj = new SearchingX<int>(iLength);
    

    aobj->Accept();

    aobj->Display();

    cout<<"Enter the value that you want to search :\n";
    cin>> iValue;

    bRet = aobj->LinearSearch(iValue);

    if(bRet == true)
    {
        cout<<"Element is present\n";
    }
    else 
    {
        cout<<"Element is not present\n";
    }

    delete aobj;
    
    return 0;
}