#include<iostream>
#include<stack>
#include<queue>
using namespace std;
vector<int> beamSearch(vector<vector<int>> edge, int v, int w){

    int n = edge[0].size();

    bool visited[n];

    for(int i=0;i<=n;i++)
    visited[i]=false;

    vector<int> vec;

    queue<int> q;
    
    q.push(v);
    visited[v]=true;

    while(!q.empty()){

        int a = q.front();
        q.pop();
        vec.push_back(a);

        for(int i=0;i<=n;i++){

            if(edge[a][i]==1 && visited[i]==false && q.size()<w){

                visited[i]=true;
                q.push(i);
               
            }
        }

    }
    return vec;

}
int main(){


//    // nodes starting with zero 

   vector<vector<int>> edge1, edge2 ;


  // sample graph with 10 nodes
    edge1 = {
         {0, 1, 1, 0, 0, 1, 0, 0, 0, 0}, 
         {1, 0, 1, 1, 0, 0, 0, 0, 0, 0}, 
         {1, 1, 0, 0, 1, 0, 0, 1, 0, 0}, 
         {0, 1, 0, 0, 1, 0, 1, 0, 1, 0}, 
         {0, 0, 1, 1, 0, 1, 1, 0, 0, 0}, 
         {1, 0, 0, 0, 1, 0, 0, 0, 0, 1}, 
         {0, 0, 0, 1, 1, 0, 0, 1, 0, 0}, 
         {0, 0, 1, 0, 0, 0, 1, 0, 0, 0}, 
         {0, 0, 0, 1, 0, 0, 0, 0, 0, 1}, 
         {0, 0, 0, 0, 0, 1, 0, 0, 1, 0}
         };

    //sample graph with 12 nodes
        edge2 = {
            {0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, 
            {1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, 
            {0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, 
            {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, 
            {0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0}, 
            {0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0}, 
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, 
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1}, 
            {0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0}, 
            {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1}, 
            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0}
    };

   cout<<"For sample graph with 10 nodes - "<<endl;

   int v;
   cout<<endl<<"Enter starting node - ";
   cin>>v;

   int w;
   cout<<"Enter width - ";
   cin>>w;

    vector<int> ans ;
    ans = beamSearch(edge1, v, w);
    cout<<"The beam search is - "<<endl;
    for(auto i : ans){
        cout<<i<<" ";
    }cout<<endl;

    cout<<endl<<"For sample graph with 12 nodes - "<<endl;

   cout<<"Enter starting node - ";
   cin>>v;

   cout<<"Enter width - ";
   cin>>w;

    ans = beamSearch(edge2, v, w);
    cout<<"The beam search is - "<<endl;
    for(auto i : ans){
        cout<<i<<" ";
    }cout<<endl;

    //input the graph
  // int n;
    // cout<<"enter number of vertices - ";
    // cin>>n;

    // int edges;
    // cout<<"enter number of edges - ";
    // cin>>edges;

    // vector<vector<int>> edge(n+1,vector<int> (n+1,0)) ;

    // for(int a=0;a<=n;a++)
    // {
    //     for(int b=0;b<=n;b++)
    //     edge[a][b] = 0 ;
    // }

    // cout<<"enter vertices that have edge between them - "<<endl;
    // for(int k=0;k<edges;k++)
    // {
    //     int i,j;
    //     cin >> i >> j;
    //     edge[i][j] = edge[j][i] = 1 ;
    // }

    // int v;
    // cout<<"enter starting node - ";
    // cin>>v;

    // int width;
    // cout<<"enter width";
    // cin>>width;

    // vector<int> ans;
    // ans = beamSearch(edge,v,width);
    // for(auto i : ans){
    //     cout<<i<<" ";
    // }
//

}
         