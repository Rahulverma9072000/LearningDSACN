#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
void printBFS(int** edges,int n,int sv,bool* visited)
{
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;
    while(!pendingVertices.empty())
    {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout<<currentVertex<<" ";
        for(int i=0;i<n;i++)
        {
            if(i == currentVertex) continue;
            if(edges[currentVertex][i]==1 and !visited[i])
            {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
}
vector<int> getPathBFS(int** edges,int n,int sv,int ev,bool* visited)
{
    vector<int> res;
    unordered_map<int,int> parent;
    //Ideal Condition 
    if(sv==ev)
    {
        res.push_back(sv);
        return res;
    }
    queue<int> data;
    data.push(sv);
    visited[sv] = true;
    while (!data.empty())
    {
        int currentVertex = data.front();
        // cout<<currentVertex<<"Just checking"<<endl;
        data.pop();
        //Break the condition 
        if(currentVertex==ev)
        {
            // cout<<currentVertex<<" "<<parent[currentVertex]<<endl;
            while(currentVertex!=sv)
            {
                res.push_back(currentVertex);
                currentVertex = parent[currentVertex];
            }
            res.push_back(sv);
            return res;
        }
        for(int i=0;i<n;i++)
        {
            if(edges[currentVertex][i]==1 and !visited[i])
            {
                parent[i] = currentVertex;
                data.push(i);
                visited[i] = true;
            }
        }
    }
    return res;
}
int main()
{
    int n,e;cin>>n>>e;
    int** edges = new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i] = new int[n];
        //Clean the garbage 
        for(int j=0;j<n;j++)
        {
            edges[i][j] = 0;
        }
    }
    //Take the input 
    for(int i=0;i<e;i++)
    {
        int s,e;cin>>s>>e;
        edges[s][e] = 1;
        edges[e][s] = 1;
    }
    bool* visited = new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i] = false;
    }
    // printBFS(edges,n,0,visited);
    //Call the finction 
    int sv,ev;cin>>sv>>ev;
    vector<int> res = getPathBFS(edges,n,sv,ev,visited);
    // cout<<"Size "<<res.size()<<endl;
    //Print the vector
    // cout<<"Res size "<<res.size()<<endl;
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}