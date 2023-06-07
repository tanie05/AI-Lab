#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void IDBeamSearch(vector<vector<int>> edge, int w, int d, bool visited[], int a){

    int n = edge[0].size()-1;
    
    cout<<a<<" ";
    visited[a]=true;

    if(d==1)
    return; 

    int count=0;
    
        for(int i=0;i<=n;i++){ 

            if(edge[a][i]==1 && visited[i]==false && d>1 && count<w){

                count++;
                IDBeamSearch(edge, w, d-1, visited, i);     
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

    cout << "ITERATIVE DEEPENING BEAM SEARCH"<< endl<<endl;
    
    int depth;

    for(depth = 1; depth <= 4; depth++)
    {  
        cout<<"FOR DEPTH = "<<depth<<endl;
        
        for(int w=1;w<=3;w++)

            {
                cout<<"width-"<<w<<endl;
                IDBeamSearch(edge, w, depth, visited, 1);
                cout<<endl;

                for(int j=0;j<=n;j++)
                visited[j]=false;
            }
        cout<<endl;

    }
    


}
         