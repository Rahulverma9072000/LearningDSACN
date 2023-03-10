#include <iostream>
#include<vector>
#include <queue>
#include<algorithm>
using namespace std;
void DFS(int** edges,int n,int sv,bool* visited,vector<int> &curr)
{
    curr.push_back(sv);
    visited[sv] = true;
    for(int i=0;i<n;i++)
    {
        if(i==sv) continue;
        if(edges[sv][i]==1)
        {
            if(visited[i]) continue;
            DFS(edges,n,i,visited,curr);
        }
    }
}
vector<vector<int> > AllComponentDFS(int** edges,int n)
{
    vector<vector<int> > res;
    bool* visited = new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i] = false;
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            vector<int> curr;
            DFS(edges,n,i,visited,curr);
            sort(curr.begin(),curr.end());
            res.push_back(curr);
        }
    }
    return res;
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
    vector<vector<int> > res = AllComponentDFS(edges,n);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    //Delete All the Memory
    for(int i=0;i<n;i++)
    {
        delete[] edges[i];
    }
    delete [] edges;
    return 0;
}