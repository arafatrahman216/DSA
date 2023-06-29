#include<iostream>
using namespace std;


template <typename Dtype> class stack
{

    int MAX_SIZE=10;
    int len=0;
    int pos=0;
    Dtype * arr;
    //! these are private functions
    void prev()
    {
        if (pos>0) pos--;
    }
    //! these are private functions
    void next()
    {
        if (pos<len) pos++;
    }
    //! these are private functions
    void moveToStart()
    {
        pos=0;
    }
    //! these are private functions
    void moveToEnd()
    {
        if (len>0) pos=len-1;
    }
    //! these are private functions
    int currPos()
    {
        return pos;
    }
    //! these are private functions
    void moveToPos(int x)
    {
        if (len>=x) pos=x;
        else pos=len;
    }
    //! these are private functions
    Dtype getValue()
    {
        if (pos>=len || len==0) return -1;
        else 
        {
            return arr[len-1];
        }
    }
    //! these are private functions
    Dtype remove()
    {
        Dtype a=getValue();
        if (len==0 || len==pos ) 
        {
            return -1;
        }
        for (int i=pos+1;i<len;i++)
        {
            arr[i-1]=arr[i];
        }
        len--;
        if (pos>=len && pos>0) pos--;
        return a;
    }
    //! these are private functions
    
    void insert(Dtype item)
    {
        if (len==MAX_SIZE) 
        {
            MAX_SIZE*=2;
            arr=(Dtype *) realloc(arr,MAX_SIZE);
        }
        for (int i=len-1;i>=pos;i--)
        {
            arr[i+1]=arr[i];
        }
        arr[pos]=item;
        len++;
    }
    public :
        stack() {}
        ~stack()
        {
            delete [] arr;
        }
        void init(int X)
        {
            if (X==0) X=10;//a default MAX_SIZE=10
            MAX_SIZE=X;
            len=0;
            arr= new Dtype[X];
        }
        void clear()
        {
            len=0;
            pos=0;
        }
        int length()
        {
            return len;
        }
        void print()
        {
            cout<<"<";
            for (int i=0;i<len;i++)
            {
                if (i==pos) cout<<" ";
                cout<<arr[i];
                if (i+1!=pos && i+1<len) cout<<' ';
            }
            if (pos==len && len!=0) cout<<" ";
            cout<<">"<<endl;
        }
        Dtype pop()
        {
            moveToEnd();
            Dtype x=remove();
            return x;
        }
        void push(Dtype item)
        {
            moveToEnd();
            next();
            insert(item);

        }
        Dtype topValue()
        {
            moveToEnd();
            Dtype x=getValue();
            if (x<0) return -1;
            return x;
        }
        bool isEmpty()
        {
            if (len==0) return true;
            else return false;
        }
};