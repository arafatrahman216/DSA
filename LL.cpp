#include<iostream>
using namespace std;

class node
{
    public :
        int val;
        node* next;
};
class list 
{
    int size=0;
    int pos=0;
    node *head=NULL,*tail=NULL,*cur,*dum;
public :
    void init()
    {
        size=0;
        dum=new node;
        cur=dum;
        cur->next=NULL;
    }
    void init(int x)
    {
        pos=0;
        dum=new node;
        cur=dum;
        cur->next=NULL;
    }
    void insert(int item)
    {
        node *new_node= new node;
        new_node->val=item;
        new_node->next=cur->next;
        cur->next=new_node;
        if (cur==dum) 
        {
            int f=0;
            if (head==NULL) f=1;
            head=new_node;
            if (f==1) 
            {
                tail=head;
                head->next=NULL;
            }
        }
        else if (cur==tail && cur!=NULL ) tail=new_node;
        size++;
    }
    int remove()
    {
        if (cur!=tail)
        {
            node* temp=cur->next;
            int a=temp->val;
            if (cur->next==tail) tail=cur;
            cur->next=temp->next;
            delete temp;
            if ( cur==dum)
            {
                head=dum->next;
            }
            size--;
            if (cur==tail) prev();
            return a;
        }
        else return -1;
    }
    void next()
    {
        if (pos<size ) 
        {
            pos++;
            cur=cur->next;
        }
        //! previous implementation //
        /*if (cur!=tail && cur!=NULL)
        {
            cur=cur->next;
            pos++;
        }*/

    }
    void moveToEnd()
    {
        node* temp=dum;
        while (temp->next!=tail && temp->next!=NULL)
        {
            temp=temp->next;

        }
        cur=temp;
        if (head==NULL || dum->next==NULL) 
        {
            cur= dum;
        }
        pos=size-1;
    }
    int length()
    {
        return size;
    }
    void moveToStart()
    {
        cur=dum;
        pos=0;
    }
    int getValue()
    {
        if (size==0 || pos==size) return -1;
        else if (cur!=tail && cur !=NULL)
        {
            return (cur->next)->val;
        }
        else return -1;
    }
    void moveToPos(int pos)
    {
        this->pos=pos;
        node* temp=dum;
        for ( int i=0;i<pos;i++)
        {
            temp=temp->next;
        }
        cur=temp;
        //!previous implementation
        /*int n=0;
        node* temp=dum;
        while (true)
        {
            if (temp==tail || pos<=n)
            {
                break;
            }
            temp=temp->next;
            cur=temp;
            n++;
        }
        cur=temp;*/
    }
    int currPos()
    {
        /* int pos=0;
        node* temp=dum ;
        if (cur==dum) return pos;
        else {
            pos++;
            while (1)
            {
                if (cur==temp->next)
                {
                    return pos;
                }
                temp=temp->next;
                pos++;
            }
        }*/
        return pos;
    }
    void prev()
    {
        /* if (cur==head || cur==dum) cur=dum;
        cannot go backward when already in 1st position
        if currPos is head then it'll go to the dummy position//
        else 
        {
            node* temp=head;
            traversing nodes until the next node is current node
            and the current traversing node will be current node now
            while(temp->next!=NULL )
            {
                if ( temp->next==cur) 
                {
                    cur=temp;
                    return;
                }
                temp=temp->next;
            }
        }*/
        if (pos>0) pos--;
        moveToPos(pos);
    }
    void print()
    {
        cout<<"<";
        for ( node *i=head; i!=NULL;i=i->next)
        {
            if (cur->next==i) cout<<"|";
            cout<<i->val;
            if (i!=cur && i!=tail) cout<<',';
            if (i==tail) break;
        }
        if (cur==tail && head!=NULL) cout<<"|";
        cout<<">\n";
    }
};
