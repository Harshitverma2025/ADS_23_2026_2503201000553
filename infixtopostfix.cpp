#include<iostream>
#include<stack>
#include<string>
using namespace std;

int getPrecedence(char ch)
{
    if(ch=='+' || ch=='-')
        return 1;
    else if(ch=='*' || ch=='/')
        return 2;
    else if(ch=='^')
        return 3;
    return 0;
}

string infixToPostfix(string infix)
{
    stack<char> st;
    string postfix="";

    for(int i=0; i<infix.length(); i++)
    {
        char ch=infix[i];

        if(isalnum(ch))
        {
            postfix+=ch;
        }
        else if(ch=='(')
        {
            st.push(ch);
        }
        else if(ch==')')
        {
            while(st.top()!='(')
            {
                postfix+=st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while(!st.empty() && getPrecedence(st.top())>=getPrecedence(ch))
            {
                postfix+=st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while(!st.empty())
    {
        postfix+=st.top();
        st.pop();
    }

    return postfix;
}

int main()
{
    string infix="(A+B*C-D)";
    cout<<"Postfix = "<<infixToPostfix(infix);

    return 0;
}