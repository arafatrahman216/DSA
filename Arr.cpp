#include<iostream>
using namespace std;

class ARR
{
    int MAX_SIZE=0;
    int size=0;
    int pos=0;
    int * arr;
    public :
        void init(int X)
        {
            if (X==0) X=10;//a default MAX_SIZE=10
            MAX_SIZE=X;
            arr= new int[X];
        }
        void clear()
        {
            size=0;
            pos=0;
        }
        void prev()
        {
            if (pos>0) pos--;
        }
        void next()
        {
            if (pos<size) pos++;
        }
        void moveToStart()
        {
            pos=0;
        }
        void moveToEnd()
        {
            if (size>0) pos=size-1;
        }
        int length()
        {
            return size;
        }
        int currPos()
        {
            return pos;
        }
        void moveToPos(int x)
        {
            if (size>=x) pos=x;
            else pos=size;
        }
        void insert(int item)
        {
            if (size==MAX_SIZE) 
            {
                MAX_SIZE*=2;
                arr=(int *) realloc(arr,MAX_SIZE);
            }
            for (int i=size-1;i>=pos;i--)
            {
                arr[i+1]=arr[i];
            }
            arr[pos]=item;
            size++;
        }
        int getValue()
        {
            if (pos>=size) return -1;
            else return arr[pos];
        }
        int remove()
        {
            int a=getValue();
            if (size==0 || size==pos ) 
            {
                return -1;
            }
            for (int i=pos+1;i<size;i++)
            {
                arr[i-1]=arr[i];
            }
            size--;
            if (pos>=size && pos>0) pos--;
            return a;
        }
        
        void print()
        {
            cout<<"<";
            for (int i=0;i<size;i++)
            {
                if (i==pos) cout<<"| ";
                cout<<arr[i];
                if (i+1!=pos && i+1<size) cout<<',';
            }
            if (pos==size && size!=0) cout<<"|";
            cout<<">"<<endl;
        }


};

