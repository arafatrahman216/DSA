#include<iostream>
#include"Arr.cpp"
#include"LL.cpp"
using namespace std;
//#define dtype ARR
//#define dtype list
int main()
{
    //two implementations are presented below 
{
    cout<<"use of array based implementation : ";
    ARR ADT;
    int k,x;
    cout<<"enter k and x(if any) : ";
    cin>>k>>x;
    ADT.init(x);
    //printing out initial state to check if print method works or not
    ADT.print();
    for ( int i=0;i<k;i++)
    {
        int a;
        cin>>a;
        /****decided to take input manually so that we can easily...****
        sort our initial array*/
        ADT.insert(a);
        ADT.print();
        //printing out to check again
        ADT.next();
        /****to make initial array to look like sample input
        or to maintain the input order -> 20 23 12 15  ****/
    }
    ADT.print(); //checking again
    int q;
    while (1)
    {
        if (k==0 && x==0) break;
        cout<<"enter operation q : ";
        cin>>q;
        if (q==0) break;
        else if (q==1)
        {
            int p;
            cin>>p;
            ADT.insert(p);
            ADT.print();
            cout<<-1<<endl; //no return value 

        }
        else if (q==2)
        {
            int a=ADT.remove();
            ADT.print();
            cout<<a<<endl;
        }
        else if (q==3)
        {
            ADT.moveToStart();
            ADT.print();
            cout<<-1<<endl;
        }
        else if (q==4)
        {
            ADT.moveToEnd();
            ADT.print();
            cout<<-1<<endl;
        }
        else if (q==5)
        {
            ADT.prev();
            ADT.print();
            cout<<-1<<endl;
        }
        else if (q==6)
        {
            ADT.next();
            ADT.print();
            cout<<-1<<endl;
        }
        else if (q==7)
        {
            int a=ADT.length();
            ADT.print();
            cout<<a<<endl;
        }
        else if (q==8)
        {
            int a=ADT.currPos();
            ADT.print();
            cout<<a<<endl;
        }
        else if (q==9)
        {
            int p;
            cin>>p;
            ADT.moveToPos(p);
            ADT.print();
            cout<<-1<<endl;
        }
        else if (q==10)
        {
            int a=ADT.getValue();
            ADT.print();
            cout<<a<<endl;
        }
    }

}
//using two scope for 2 types of implementation
{   cout<<"use of linked list based implementation : ";
    list ADT;
    int k,x;
    cout<<"enter k and x(if any) : ";
    cin>>k>>x;
    ADT.init(x);
    /*I've used function overloading to accept both taking input
    and avoiding input in init*/

    ADT.print();
    for ( int i=0;i<k;i++)
    {
        int a;
        cin>>a;
        ADT.insert(a);
        ADT.print();
        ADT.next();
    }
    ADT.print();
    int q;
    while (1)
    {
        if (k==0 && x==0) break; // only for testing
        cin>>q;
        if (q==0) break;
        else if (q==1)
        {
            int p;
            cin>>p;
            ADT.insert(p);
            ADT.print();
            cout<<-1<<endl;

        }
        else if (q==2)
        {
            int a=ADT.remove();
            ADT.print();
            cout<<a<<endl;
        }
        else if (q==3)
        {
            ADT.moveToStart();
            ADT.print();
            cout<<-1<<endl;
        }
        else if (q==4)
        {
            ADT.moveToEnd();
            ADT.print();
            cout<<-1<<endl;
        }
        else if (q==5)
        {
            ADT.prev();
            ADT.print();
            cout<<-1<<endl;
        }
        else if (q==6)
        {
            ADT.next();
            ADT.print();
            cout<<-1<<endl;
        }
        else if (q==7)
        {
            int a=ADT.length();
            ADT.print();
            cout<<a<<endl;
        }
        else if (q==8)
        {
            int a=ADT.currPos();
            ADT.print();
            cout<<a<<endl;
        }
        else if (q==9)
        {
            int p;
            cin>>p;
            ADT.moveToPos(p);
            ADT.print();
            cout<<-1<<endl;
        }
        else if (q==10)
        {
            int a=ADT.getValue();
            ADT.print();
            cout<<a<<endl;
        }
    }
}
}