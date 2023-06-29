#include<iostream>
#include<cmath>
#include"stack.cpp"
using namespace std;

int check_precedence_to_pop(char top,char check)
{
    if ( top==-1) return 0; 
    else if ((top=='+' || top=='-') && (check=='*' || check=='/') ) return 0;
    else if ((top=='+' || top=='-') && (check==')' ) ) return 1;
    else if ( (top=='*' || top=='/') && ( check==')' )) return 1;
    else if ( (top=='+' || top=='-') && ( check==')' )) return 1;
    else if (top=='+' && check=='-') return 1;
    else if ((top=='*' || top=='/') && (check=='-' || check=='+')) return 1;
    else if ((top=='+' || top=='-') && (check=='+' || check=='-')) return 1;
    else if (top=='*' && check=='/') return 1;
    else if (top=='/' && check=='*') return 1;
    else if ( top=='(' || check=='(') return 0;
    else if ( top=='(') return 0; 
    else return 0;
}

string postfix(string exp, stack<char> &saved)
{
    int len=exp.length();
    string ret="";
    int numb=1;
    int number;
    for ( int i=0;i<len;i++)
    {
        char k=exp[i];
        if (exp[i]==' ') continue;
        if (isdigit(exp[i]))
        {
            if (numb==0) ret+=' ';
            ret+=exp[i];
            // cout<<ret<<endl;
            numb=1;
        }
        else{
            numb=0;
            char op=exp[i];
            if (i>0) 
            {
                if (exp[i-1]=='(' && exp[i]=='-')
                {
                    numb=1;
                    ret=ret+" -";
                    // cout<<ret<<endl;
                    continue;
                }
            }
            char top=saved.topValue();
            if (op==')')
            {
                while (top!='(')
                {
                    top=saved.pop();
                    // saved.print();
                    if (top=='(') break;
                    ret=ret+" "+top;
                    top=saved.topValue();
                }
                top=saved.topValue();
                if (top=='(')   top=saved.pop();
                // saved.print();
            }
            else if ( op=='(' || top=='(' || saved.isEmpty() || !check_precedence_to_pop(top,op))
            {
                saved.push(op);
                // saved.print();
            }
            else 
            {
                while ( true)
                {
                    char top=saved.pop();
                    // saved.print();
                    ret=ret+" "+top;
                    // cout<<ret<<endl;
                    if (!check_precedence_to_pop( saved.topValue(),exp[i])) break;

                }
                saved.push(exp[i]);
                // saved.print();
            }
        }
    }
    if ( saved.length()!=0)
    {
        while (saved.length()!=0)
        {
            char top=saved.pop();
            // saved.print();
            if (top!=')' || top!='(') ret=ret+" "+top;
        }
    }
    ret=ret+" ";
    return ret;

}

bool isOperator(char a)
{
    if (a=='+' || a=='-' || a=='*' || a=='/') return true ;
    else return false;
}

int main()
{
    string expression;
    // expression="5*(-12)";
    stack<char> parenthesis;
    parenthesis.init(20);
    cin>>expression;
    int len=expression.length();
    for (int i=0;i<len;i++)
    {
        char c=expression[i];
        if ( c=='(') parenthesis.push('(');
        else if (c==')')
        {
            if (parenthesis.topValue()=='(')
            {
                parenthesis.pop();
            }
            else if (parenthesis.length()==0)
            {
                cout<<"Not valid\n";
                return 0;
            }
        }
    }
    for (int i=0;i<len;i++)
    {
        char c=expression[i];
        int p=0;
        if (i<len-1)
        {   
            char d=expression[i+1];
            if (c=='(' && d==')')  
            {
                p=1;
            }
            if (c=='(' && d=='+' )  
            {
                p=1;
            }
            if (c=='(' && d=='*' )  
            {
                p=1;
            }
            if (c=='(' && d=='/')  
            {
                p=1;
            }
            else if ( isOperator(c) && isOperator(d)) 
            {
                p=1;
            }

        }
        if (i==len-1 && isOperator(c)) p=1;
        if (p==1) 
        {
            cout<<"Not valid\n";
            return 0;
        }
    }
    if (parenthesis.length()!=0) 
    {
        cout<<"Not valid\n";
        return 0;
    }
    else cout<<"Valid expression.\n";
    stack<char> saved ;
    saved.init(15);
    string post=postfix(expression,saved);
    // cout<<post<<endl;
    stack<double> evaluate;
    evaluate.init(10);
    int num=0;
    double x=1;
    for ( int i=0;i<post.length();i++)
    {
        char z=post[i];
        if ( post[i]==' ' || isOperator(post[i])) 
        {
            num=0;
            if (isdigit(post[i-1])) 
            {
                evaluate.push(x);
                // evaluate.print();
            }
        }
        if (num==0) x=1;
        if (post[i]=='-' && isdigit(post[i+1]) && num==0)
        {
            x=(-1)*x;
            num=1;
        }
        else if (isdigit(post[i]) && num==1)
        {
            if (x==-1 && post[i-1]=='-')
            {
                x=-1*(post[i]-'0');
            }
            else if (x<0)
            {
                x=x*10;
                x=x-(post[i]-'0');
            }
            else 
            {
                if (num==0)
                {
                    x=x*(post[i]-'0');
                }
                else
                {
                    x=x*10+(post[i]-'0');
                }
            }
        }
        else if (isdigit(post[i]))
        {
            if (num==0) x=post[i]-'0';
            else x=x*10+(post[i]-'0');
            num=1;
        }
        // evaluate.print();
    if (z=='+' || (z=='-' && !isdigit(post[i+1])) ||z=='*' || z=='/')
    {
        double a,b;
        b=evaluate.pop();
        a=evaluate.pop();
        double t;
        if (z=='+') t=a+b;
        if (z=='-') t=a-b;
        if (z=='*') t=a*b;
        if (z=='/') t=a/b;
        evaluate.push(t);
        // evaluate.print();
    }
    }
    // evaluate.print();
    cout<<"Computed value : "<<evaluate.pop()<<endl;
}