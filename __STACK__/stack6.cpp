#include<iostream>
#include<stack>
using namespace std;

//Evaluation of postfix expression

//checking if the postfix expression is an operator or an operand

int isOperand(char x)
{
    if(x=='+'||x=='-'||x=='/'||x=='*')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//Evaluation of postfix expression

int postfixEvaluate(char postfix[])
{
    stack<int>stk;
    int result=0;
    for(int i=0;postfix[i]!='\0';i++)
    {
        if (isOperand(postfix[i]))
        {
            stk.push(postfix[i]-'0');
        }
        else
        {
           int y=stk.top();
           stk.pop();
           int x=stk.top();
           stk.pop();
           switch(postfix[i])
           {
              case '+': result=x+y;
                        break;
              case '-': result=x-y;
                        break;
              case '*': result=x*y;
                        break;
              case '/': result=x/y;
                        break;
           }
           stk.push(result);
        }
    }
    result=stk.top();
    stk.pop();
    return result;
}
int main()
{
    char postfix[]="35*62/+4-";
    cout<<postfixEvaluate(postfix)<<endl;
}