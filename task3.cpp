#include<iostream>
#include"Arr.cpp"
#include"LL.cpp"
using namespace std;
//by changing the below line we can interchange between 2 implementations
//****************
#define dtype list
//****************

int maximum(dtype &temp,int &max_i)
{
    temp.moveToStart();
    int maxm=temp.getValue();
    temp.next();
    while (temp.getValue()!=-1)
    {
        if (maxm<temp.getValue()) 
        {
            maxm=temp.getValue();
            max_i=temp.currPos();
        }
        temp.next();
    }
    return maxm;
}

void print(dtype temp)
{
    temp.moveToStart();
    while ( temp.getValue()!=-1)
    {
        cout<<temp.getValue()<<" ";
        temp.next();
    }
    cout<<endl;
}

int minimum(dtype &temp,int &min_i)
{
    temp.moveToStart();
    int minm=temp.getValue();
    temp.next();
    while (temp.getValue()!=-1)
    {
        if (minm>temp.getValue()) 
        {
            minm=temp.getValue();
            min_i=temp.currPos();
        }
        temp.next();
    }
    return minm;
}

int main()
{
    int x,y,z;
    cout<<"number of total cars : ";
    cin>>x;
    cout<<"number of garages : ";
    cin>>y;
    cout<<"number of cars in each garage : ";
    cin>>z;
    //list array[y];
    dtype array[y];
    for ( int i=0;i<y;i++)
    {
        int g,cars;;
        cin>>g>>cars;
        g--;
        array[g].init(z);
        for ( int j=0;j<cars;j++)
        {
            int b;
            cin>>b;
            if (array[g].length()<=z) 
            {
                array[g].insert(b);
                array[g].next();
            }
        }
        array[g].moveToStart();
        //print(array[g]);
        int minind=0,maxind=0;
        

    }
    for ( int i=0;i<y;i++)
        {
            array[i].moveToStart();
            print(array[i]);
        }
    string com;
    while (1)
    {
        cin>>com;
        if (com=="end") break;
        if (com=="req")
        {
            int d=0;
            while (1)
            {
                if (d>=y) 
                {
                    cout<<"NO CARS ARE AVAILABLE\n";
                    break;
                }
                if (array[d].length()==0)
                {
                    d++;
                    continue;
                }
                int minind=0;
                int minm=minimum(array[d],minind);
                //cout<<"index : "<<minind<<"value : "<<minm<<endl;
                cout<<" car "<<minm <<" is requested\n";
                array[d].moveToPos(minind);
                array[d].remove();
                break;
            }
        }
        if (com=="ret")
        {
            int car;
            cin>>car;
            int d=y-1;
            while (1)
            {
                if (d<0) 
                {
                    cout<<"ALL GARAGES ARE FULL\n";
                    break;
                }
                if (array[d].length()==z)
                {
                    d--;
                    continue;
                }
                int maxind=0;
                int maxm=maximum(array[d],maxind);
                if (array[d].length()==0) maxind=-1;
                //cout<<"index : "<<maxind<<"value : "<<maxm<<endl;
                array[d].moveToPos(maxind+1);
                array[d].insert(car);
                break;
            }
        }
        for ( int i=0;i<y;i++)
        {
            array[i].moveToStart();
            print(array[i]);
        }
    }
}