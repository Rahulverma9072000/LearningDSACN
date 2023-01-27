//Input given is 
//n and m 
//n -> Number of nodes 
//m -> number of edges 
//m (a,b) input is taken 
#include<bits/stdc++.h>
using namespace std;
//2 ways to store -> Adjacent matrix 
//Adjacent list 
int main()
{
    //Adjacent Matrix 
    int n,m;cin>>n>>m;
    int adj[n+1][m+1];
    for(int i=0;i<m;i++)
    {
        int u,v;cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    //Adjacency list
    vector<int> adjl[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adjl[u].push_back(v);
        //This is not there in directed graph 
        // adjl[v].push_back(u);
    }
    //In case of weighted graph 
    //in Adjacency matrix where you write 1 
    //write the weight there 
    //IN Adjacency list instead of storing the elements 
    //store the pairs in it.
    //For connectedf component i have to maintain a visited array 
    return 0;
}

//Province is a group of directly or indirectly connected 
//cities and no other cities outside of the group
int numProvinces(vector<vector<int>> adj, int V) {
    //Adjacency matrix given 
}