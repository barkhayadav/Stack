#include<iostream>
using namespace std;

//operations in a stack using ARRAY

class stack
{
    public:
    int size;
    int top;
    int*a;
    stack(int size)
    {
        this->size=size;
        top=-1;
        a=new int[size];
    }
    void push(int val);
    void pop();
    int peek(int pos);
    int stackTop();
    int isFull();
    int isEmpty();
    void display();

};

//PUSH operation

void stack::push(int val)
{
    if(top==size-1)
    {
        cout<<"Stack Overflow!"<<endl;
    }
    else
    {
        top++;
        a[top]=val;
    }
    
}

//POP operation

void stack::pop()
{
    if(top==-1)
    {
        cout<<"Stack Underflow!"<<endl;
    }
    else
    {
        cout<<"\nThe deleted value is "<<a[top]<<endl;
        top--;
    }
}

//PEEK operation

int stack::peek(int pos)
{
    if(top+pos-1<0)
    {
        cout<<"Invalid Index!";
    }
    return a[top-pos+1];
}

//Stack's TOP VIEW

int stack::stackTop()
{
    if(top==-1)
    {
        cout<<"Stack is Empty!"<<endl;
    }
    return a[top];
}

//checking if stack is FULL

int stack::isFull()
{
    top==size-1?cout<<"\nStack is Full!":cout<<"\nStack is not Full!";
}

//checking if stack is Empty

int stack::isEmpty()
{
    top==-1?cout<<"\nStack is Empty!":cout<<"\nStack is not empty!";
}

//Display

void stack::display()
{
    for(int i=top;i>=0;i--)
    {
        cout<<a[i]<<" ";
    }
}
int main()
{
    stack st(20);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.display();
    st.pop();
    st.display();
    int x=st.peek(3);
    cout<<"\nThe element at 3 position is "<<x<<endl;
    st.isFull();
}