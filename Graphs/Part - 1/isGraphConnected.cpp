#include <iostream>
using namespace std;
//Check if graph is connected or not
void DFS(int** edges,int n,int sv,bool* visited)
{
    visited[sv] = true;
    for(int i=0;i<n;i++)
    {
        if(i==sv) continue;
        if(edges[sv][i]==1)
        {
            if(visited[i]) continue;
            DFS(edges,n,i,visited);
        }
    }
}
bool isConnected(int** edges,int n)
{
    bool* visited = new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i] = false;
    }
    //Making a normal call for 0 
    DFS(edges,n,0,visited);
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        return false;
    }
    return true;
}
int main()
{
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    //Check if Graph is connected or not 
    if(isConnected(edges,n))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
    //Delete All the Memory
    for(int i=0;i<n;i++)
    {
        delete[] edges[i];
    }
    delete [] edges;
    return 0;
}