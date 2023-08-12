#include<iostream>
using namespace std;

//operations in a stack using linked list

class node
{
    public:
    int data;
    node*next;
};
class stack
{
    private:
    node*top;
    public:
    stack()
    {
        top=NULL;
    }
    void push(int val);
    void pop();
    void display();
};

// PUSH operation

void stack::push(int val)
{
    node*temp=new node();
    if(temp==NULL)
    {
        cout<<"Stack Overflow!"<<endl;
    }
    else
    {
        temp->data=val;
        temp->next=top;
        top=temp;
    }
}

//POP operation

void stack::pop()
{
    node*p=top;
    if(top==NULL)
    {
        cout<<"Stack Underflow!"<<endl;
    }
    else
    {
         cout<<"The deleted value is "<<top->data<<endl;
         top=top->next;
         delete p;
    }
}

//display

void stack::display()
{
    node*q=top;
    while(q!=NULL)
    {
        cout<<q->data<<" ";
        q=q->next;
    }
    cout<<endl;
}
int main()
{
    stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.display();
    st.pop();
    st.pop();
    st.display();
}
