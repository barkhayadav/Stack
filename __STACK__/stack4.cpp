#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

//infix to postfix conversion

//checking if the infix expression is an operator or an operand

int isOperand(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//checking precedence of the infix expression

int pre(char x)
{
    if(x=='+'||x=='-')
    {
        return 1;
    }
    else if(x=='*'||x=='/')
    {
        return 2;
    }
    else
    {
        return -1;
    }
}

//converting infix expression into postfix expression

char *inToPos(char infix[])
{
    stack<char>stk;
    int n=strlen(infix);
    char *postfix=new char[n+1];
    stk.push('#');
    int i=0;
    int j=0;
    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
        {
            postfix[j++]=infix[i++];
        }
        else
        {
            if(pre(infix[i])>pre(stk.top()))
            {
                stk.push(infix[i]);
                i++;
            }
            else
            {
                postfix[j++]=stk.top();
                stk.pop();
            }
        }
    }
    while(!stk.empty())
    {
        postfix[j++]=stk.top();
        stk.pop();
    }
    postfix[j]='\0';
    return postfix;
}
int main()
{
    char infix[]="a+b*c";
    cout<<inToPos(infix);
}