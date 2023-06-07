#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
unordered_map<int, char> umap;

int insertHeuristicValue(int n, int arr[])
{
    for(int i=1;i<=n;i++)
    {
        cout<<"enter heuristic value of node "<<umap[i]<<endl;
        int val;
        cin>>val;
        arr[i]=val;
    }
}
void creatingMap(int n)
{
    for(int i=1;i<=n;i++)
    {
        cout<<"enter node no. "<<i<<endl;
        char ch;
        cin>>ch;
        umap[i] = ch ;
    }
}

void aStarAlgo(vector<vector<int>> graph, int source, int destination, int n, int arr[])
{
    
    vector<int> path;
    path.push_back(source);
    int start = source;
    int distTillStart = 0;

    while(start != destination)
    {
        
        int miniDistance = 1000;
        int nextNode = -1;

        for(int i=1;i<=n;i++)
        {
    
        if(graph[start][i]>0)
        {
            int d = distTillStart + graph[start][i] + arr[i]; 
            if(d < miniDistance)
            {
                miniDistance = d;
                nextNode = i;
            }
        }
        }
        graph[start][nextNode] = 0;
        graph[nextNode][start] = 0;
    
    path.push_back(nextNode);
    distTillStart += graph[start][nextNode];
    start = nextNode;
    } 

    
    for(int i=0;i<path.size();i++)
    {
        cout<<umap[path[i]]<<" ";
    }
    cout<<endl;
    
}
int main()
{
    int n;
    cout<<"enter number of vertices - ";
    cin>>n;

    int edges;
    cout<<"enter number of edges - ";
    cin>>edges;

    vector<vector<int>> edge(n+1,vector<int> (n+1,0)) ;

    for(int a=1;a<=n;a++)
    {
        for(int b=1;b<=n;b++)
        edge[a][b] = 0 ;
    }
    creatingMap(n);

    cout<<"enter vertices(number) that have edge between them and their value"<<endl;
    for(int k=0;k<edges;k++)
    {
        int i,j,d;
        cin >> i >> j>>d;
        edge[i][j] = edge[j][i] = d ;
    }
    int arr[n+1];

    insertHeuristicValue(n,arr);
    
    char source, destination;
    cout<<"enter source node number - ";
    cin>>source;
    cout<<"enter destination node number- ";
    cin>>destination;

    aStarAlgo(edge, source, destination, n, arr); 


}