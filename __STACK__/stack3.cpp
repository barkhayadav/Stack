#include<iostream>
#include<stack>
using namespace std;

//Parenthesis matching

int isBalanced(char exp[])
{
    stack<char>stk;
    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
        {
            stk.push(exp[i]);
        }
        else if(exp[i]==')')
        {
            stk.pop();
        }
    }
    if(stk.empty())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char exp[]="(((a+b))";
    int x=isBalanced(exp);
    if(x==1)
    {
        cout<<"It is Balanced!"<<endl;
    }
    else
    {
        cout<<"It is not Balanced!"<<endl;
    }
}