#include<bits/stdc++.h>
using namespace std;

vector<int>V[100];
bool visited[100];

void BFS(int s)
{

    queue<int>q;
    visited[s] = true;
    q.push(s);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for(int i=0; i<V[node].size(); i++)
        {
            int next = V[node][i];
            if(!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
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

    cout << "BFS Traversal : " ;
    BFS(s);


    return 0;
}
