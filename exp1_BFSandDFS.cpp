#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
vector<int> BFS(vector<vector<int>> edge, int v)
{
    vector<int> vect;
    int n = edge[0].size();
    bool visited[n];

    for(int i=0;i<n;i++)
    visited[i] = false;

    queue<int> q;

    q.push(v);
    visited[v]=true;

    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        vect.push_back(t);

        for(int i=0;i<n;i++)
        {
            if(edge[t][i] && !visited[i])
            {
                
            visited[i]=true;
            q.push(i);
              
            }
        }
    }
    return vect;
}

void  DFS(vector<vector<int>> edge, int v, bool visited[])
{
    int n = edge[0].size() ;
    
    visited[v] = true;
    cout<<v<<" ";

    for(int i=0;i<n;i++)
    {
        if(edge[v][i] && !visited[i])
 
        {
            DFS(edge, i,visited);
        }
    }

}
int main()
{
    //for graphs starting with 0

    int n;
    cout<<"enter number of vertices - ";
    cin>>n;

    int edges;
    cout<<"enter number of edges - ";
    cin>>edges;

    vector<vector<int>> edge(n,vector<int> (n,0)) ;

    for(int a=0;a<n;a++)
    {
        for(int b=0;b<n;b++)
        edge[a][b] = 0 ;
    }

    cout<<"enter vertices that have edge between them - "<<endl;
    for(int k=0;k<edges;k++)
    {
        int i,j;
        cin >> i >> j;
        edge[i][j] = edge[j][i] = 1 ;
    }

    int v;
    cout<<"enter starting node - ";
    cin>>v;

    
    cout<<"choose an option - \n1. BFS\n2. DFS\n";

    int a; cin >> a;
    
    switch (a)
    {
    case 1:
        {vector<int> ans;
        ans = BFS(edge,v);
        cout<<"BFS - "<<endl;
        for(auto i : ans)
        {
            cout<< i<<" ";
        }
        cout<<endl;
        break;}
    case 2:
        {bool visited[n];
        for(int i=0;i<n;i++)
        visited[n]=0;
        DFS(edge,v,visited);
        break;}

    
    }


   
    
}