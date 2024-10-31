#include <bits/stdc++.h>
using namespace std;

int precedence(char op)
{
    if (op == '^')
    {
        return 3;
    }
    else if (op == '*' || op == '/' || op == '%')
    {
        return 2;
    }
    else if (op == '+' || op == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

string infixToPostfix(string s)
{
    string postfix = "";
    stack<char> op;

    for (auto &x : s)
    {
        if (isalnum(x))
        {
            postfix += x;
        }
        else if (x == '(')
        {
            op.push(x);
        }
        else if (x == ')')
        {
            while (!op.empty() && op.top() != '(') 
            {
                postfix += op.top();
                op.pop();
            }
            if (!op.empty()) 
            {
                op.pop(); 
            }
        }
        else 
        {
            while (!op.empty() && precedence(x) <= precedence(op.top())) 
            {
                postfix += op.top();
                op.pop();
            }
            op.push(x);
        }
    }

    while (!op.empty())
    {
        postfix += op.top();
        op.pop();
    }

    return postfix;
}

int main()
{
    string s = "a+b*(c^d-e)^(f+g*h)-i"; // Example input
    string postfix = infixToPostfix(s);
    cout << "Postfix: " << postfix << endl; // Output the result
    return 0;
}
