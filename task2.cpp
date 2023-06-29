#include<iostream>
#include"Arr.cpp"
#include"LL.cpp"
using namespace std;

class List
{
    //USING TWO LISTS IN ONE CLASS
    int z=1;
public :
    ARR test; 
    list test1;
    void init(int x)
    {
        if (x==0) z=1;//z=1 or x=0 means it is a LINKED LIST BASED IMPLEMENTATION
        if (z==1)
        {
            test1.init();
        }
        else 
        {
            test.init(x);
        }
    }
    //ONLY FOR LINKED LIST BASED IMPLEMENTATION-INITIALIZATION
    void init()
    {
        test1.init();
    }
    void append(int item)
    {
        if (z==1)
        {
            int pos=test1.currPos();
            test1.moveToEnd();
            test1.next();
            test1.insert(item);
            test1.moveToPos(pos);
            test1.print();
        }
        else
        {
            int pos=test.currPos();
            test.moveToEnd();
            test.next();
            test.insert(item);
            test.moveToPos(pos);
            test.print();
        }
    }
    int search(int item)
    {
        if (z==1)
        {
            int curpos=test1.currPos();
            int pos=-1;
            test1.moveToStart();
            int len=test1.length();
            while (test1.currPos()<len)
            {
                if ( test1.getValue()==item)
                {
                    pos=test1.currPos();
                    break;
                }
                test1.next();
            }
            test1.moveToPos(curpos);
            return pos;
        }
        else 
        {
            int curpos=test.currPos();
            int pos=-1;
            test.moveToStart();
            int len=test.length();
            while (test.currPos()<len)
            {
                if ( test.getValue()==item)
                {
                    pos=test.currPos();
                    break;
                }
                test.next();
            }
            test.moveToPos(curpos);
            return pos;
        }
    }
    void next()
    {
        if (z==1) test1.next();
        else test.next();
    }
    void print()
    {
        if (z==1) test1.print(); //checking again
        else test.print();
    }
    void insert(int item)
    {
        if (z==1) test1.insert(item); //checking again
        else test.insert(item);
    }

    void clear()
    {
        if (z==0)
        {
            test.moveToStart();
            while ( test.length()!=0)
            {
                test.remove();
            }
            test.print();
        }
        else 
        {
            test1.moveToStart();
            while ( test1.length()!=0)
            {
                test1.remove();
            }
            test1.print();
        }
    }
};

int main()
{
    List ADT;
    int k,x;
    cout<<"enter non zero value of x to use array based implementation. ";
    cout<<"or use x=0 to use linked list based implementation\n";
    cout<<"enter k and x(if any) : ";
    cin>>k>>x;
    ADT.init(x);
    for ( int i=0;i<k;i++)
    {
        int a;
        cin>>a;
        /****decided to take input manually so that we can easily
        sort our initial array or list ****/
        ADT.insert(a);
        ADT.print();
        //printing out to check again
        ADT.next();
        /****to make initial array to look like sample input
        or to maintain the input order -> 20 23 12 15  ****/
    }
    ADT.print();
    int q;
    while (1)
    {
        if (k==0 && x==0) break;
        cout<<"enter operation q : ";
        cin>>q;
        if (q==0) break;
        else if (q==1)
        {
            ADT.clear();
            cout<<-1<<endl; //no return value 

        }
        else if (q==2)
        {
            int a;
            cin>>a;
            ADT.append(a);
            cout<<-1<<endl;
        }
        else if (q==3)
        {
            int a;
            cin>>a;
            int ind=ADT.search(a);
            cout<<ind<<endl;
            ADT.print();
        }
    }
}