#include<iostream>
#include"stack.cpp"
using namespace std;

int d=1;

int main()
{
    // int d=1;
    cout<<"choose data type : [1] integer [2] character\n";
    cin>>d;
    if (d==1) 
    {
        stack<int> ADT;
        int k,x;
        cout<<"enter x and k : ";
        cin>>x>>k;
        ADT.init(x);
        for ( int i=0;i<k;i++)
        {
                int a;
                cin>>a;
                ADT.push(a);
            ADT.print();
        }
        ADT.print();
        int q;
        while (1)
        {
            if (k==0 && x==0) break;
            cout<<"enter operation q : [1] clear | [2] push(item) | [3] pop | [4] length | [5] topValue | [6] isEmpty :  ";
            cin>>q;
            if (q==0) break;
            else if (q==1)
            {
                ADT.clear();
                cout<<-1<<endl; //no return value 
                ADT.print();
            }
            else if (q==2)
            {
                    int a;
                    cin>>a;
                    ADT.push(a);
                    cout<<-1<<endl;
                    ADT.print();
            }
            else if (q==3)
            {
                    int a; 
                    a=ADT.pop();
                    if (a>0) cout<<a<<endl;
                    else cout<<-1<<endl;
                    ADT.print();
            }
            else if (q==4)
            {
                int ind=ADT.length();
                cout<<ind<<endl;
                ADT.print();
            }
            else if (q==5)
            {
                    int a;
                    a=ADT.topValue();
                    cout<<a<<endl;
                    ADT.print();
            }
            else if (q==6)
            {
                bool ind=ADT.isEmpty();
                cout<<ind<<endl;
                ADT.print();
            }
        }
    }
    else {
        stack<char> ADT;
        int k,x;
        cout<<"enter x and k : ";
        cin>>x>>k;
        ADT.init(x);
        for ( int i=0;i<k;i++)
        {
                char a;
                cin>>a;
                ADT.push(a);
            ADT.print();
        }
        ADT.print();
        int q;
        while (1)
        {
            if (k==0 && x==0) break;
            cout<<"enter operation q : [1] clear | [2] push(item) | [3] pop | [4] length | [5] topValue | [6] isEmpty :  ";
            cin>>q;
            if (q==0) break;
            else if (q==1)
            {
                ADT.clear();
                cout<<-1<<endl; //no return value 
                ADT.print();
            }
            else if (q==2)
            {
                    char a;
                    cin>>a;
                    ADT.push(a);
                    cout<<-1<<endl;
                    ADT.print();
            }
            else if (q==3)
            {
                    char a; 
                    a=ADT.pop();
                    if (a>0) cout<<a<<endl;
                    else cout<<-1<<endl;
                    ADT.print();
            }
            else if (q==4)
            {
                int ind=ADT.length();
                cout<<ind<<endl;
                ADT.print();
            }
            else if (q==5)
            {
                    char a;
                    a=ADT.topValue();
                    cout<<a<<endl;
                    ADT.print();
            }
            else if (q==6)
            {
                bool ind=ADT.isEmpty();
                cout<<ind<<endl;
                ADT.print();
            }
        }
    }
   
}