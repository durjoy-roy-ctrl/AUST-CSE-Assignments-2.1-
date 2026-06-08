#include<bits/stdc++.h>
using namespace std;

vector<int>V[100];
bool visited[100];

void DFS(int node)
{
    visited[node] = true;
    cout << node << " ";

    for(int i= 0; i< V[node].size(); i++)
    {
        int next = V[node][i];
        if(!visited[next])
        {
            DFS(next);
        }
    }
}

int main()
{
    int n,e;
    cout << "Number of nodes & edges : " ;
    cin >> n >> e;

    for(int i=0; i<e ; i++)
    {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;

        V[nodeA].push_back(nodeB);
        V[nodeB].push_back(nodeA);
    }

    int s;
    cout << "Starting node : ";
    cin >> s;

    cout << "DFS Traversal : " ;
    DFS(s);


    return 0;
}




/*
void DFS(int s)
{

    stack<int>st;
    visited[s] = true;
    st.push(s);

    while(!st.empty())
    {
        int node = st.top();
        st.pop();

        cout << node << " ";

        for(int i= V[node].size()-1; i>=0; i--)
        {
            int next = V[node][i];
            if(!visited[next])
            {
                visited[next] = true;
                st.push(next);
            }
        }
    }
}
*/
