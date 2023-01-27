#include<bits/stdc++.h>
using namespace std;
//Implementing Graph basic functions
//Depth First Search -> means it go into depth first 
void print(int** edges,int n,int sv,bool* visited)
{
    cout<<sv<<endl;
    visited[sv] = true;
    for(int i=0;i<n;i++)
    {
        if(edges[sv][i]==1)
        {
            if(visited[i])
                continue;
            print(edges,n,i,visited); 
        }
    }
}
//i have return true if there is path between start node and end node 
bool hasPath(int**edges ,int n,int sv ,int ev ,bool* visited)
{
    //base case 
    if(sv==ev) return true;
    visited[sv] = true;
    bool res = false;
    for(int i=0;i<n;i++)
    {
        if(edges[sv][i]==1 && !visited[i])
        {
            res = hasPath(edges,n,sv,ev,visited);
            if(res) return true;
        }
    }
    return false;
}
int main()
{
    int n,e;cin>>n>>e;
    int** edges = new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i] = new int[n];
        //Remove all garbage 
        for(int j=0;j<n;j++)
            edges[i][j] = 0;
    }
    //Input graph edges
    for(int i=0;i<e;i++)
    {
        int f,s;cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    //Print the Graph 
    bool* visited = new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i] = false;
    }
    print(edges,n,0,visited);
    return 0;
}