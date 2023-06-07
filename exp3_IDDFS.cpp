#include<iostream>
#include<vector>
using namespace std;

void  DFS(vector<vector<int>> edge, int v, bool visited[], int d)
{
    int n = edge[0].size()-1;
   
    visited[v] = true;
    cout<<v+1<<" ";

    if(d==1)
    return;

    for(int i=1;i<=n;i++)
    {
        if(edge[v][i] && !visited[i] && d>1)
        {
            DFS(edge, i, visited, d-1);
        }
    }

}

int main()
{

    //iterative deepening DFS
    //graph starting from 1

    int n;
    cout<<"enter number of vertices - ";
    cin>>n;

    int edges;
    cout<<"enter number of edges - ";
    cin>>edges;

    vector<vector<int>> edge(n+1,vector<int> (n+1,0)) ;

    for(int a=0;a<=n;a++)
    {
        for(int b=0;b<=n;b++)
        edge[a][b] = 0 ;
    }

    cout << "enter vertices that have edge between them - " << endl;
    for(int k = 0; k < edges; k++)
    {
        int i, j;
        cin >> i >> j;
        edge[i][j] = edge[j][i] = 1 ;
    }

    int v;
    cout << "enter starting node - ";
    cin >> v;


    bool visited[n+1];

    for(int i = 0; i <= n; i++)
    visited[i] = 0;

    cout << "Iterative deepning search" << endl;

    for(int depth = 1; depth <= 4 ; depth++){
        
        cout << "For depth = " << depth << endl;
        DFS(edge, v, visited, depth);

        for(int i = 0; i <= n; i++)
        visited[i] = 0;

        cout<<endl;
       
    }

}
