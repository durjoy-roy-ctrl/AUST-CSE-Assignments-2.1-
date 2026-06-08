#include<bits/stdc++.h>
using namespace std;

stack<char>S;
stack<int>P;

int priority(char s)
{
    if(s == '^') return 100;
    else if(s == '*' || s == '/') return 50;
    else if(s == '+' || s == '-') return 20;
    else return 0;
}

int main()
{
    string infix, postfix = "";
    cin >> infix;

    for(int i=0; i<infix.size(); i++)
    {
        char symbol = infix[i];

        if(symbol == ' ') continue;

        if(symbol >= '0' && symbol <= '9')
        {
            while(i < infix.size() && infix[i] >= '0' && infix[i] <= '9')
            {
                postfix += infix[i];
                i++;
            }
            postfix += ' ';
            i--;
        }
        else if(symbol == '(')
        {
            S.push(symbol);
        }
        else if(symbol == ')')
        {
            while(!S.empty() && S.top() != '(')
            {
                postfix += S.top();
                S.pop();
            }
            S.pop();
        }
        else
        {
            while(!S.empty() && priority(S.top()) >= priority(symbol))
            {
                postfix += S.top();
                S.pop();
            }
            S.push(symbol);
        }
    }

    while(!S.empty())
    {
        postfix += S.top();
        S.pop();
    }

    cout << "Postfix: " << postfix << endl;

    for(int i=0; i<postfix.size(); i++)
    {
        char token = postfix[i];

        if(token == ' ') continue;
        if(token >= '0' && token <= '9')
        {
            int num =0;
            while(i < postfix.size() && postfix[i]>= '0' && postfix[i] <= '9')
            {
                num = num*10 + (postfix[i] - '0');
                i++;
            }
            P.push(num);
            i--;
        }
        else
        {
            int a = P.top();
            P.pop();
            int b = P.top();
            P.pop();
            int c;
            if(token == '+') c = b+a;
            else if(token == '-') c = b-a;
            else if(token == '*') c = b*a;
            else if(token == '/') c = b/a;
            else if(token == '^') c = pow(b,a);
            P.push(c);
        }
    }

    cout << "Evaluate result: " << P.top();
    return 0;
}
