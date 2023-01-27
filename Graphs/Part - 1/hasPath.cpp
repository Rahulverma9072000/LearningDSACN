#include <iostream>
using namespace std;
#include<queue>
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
void BFS(int** edges,int n)
{
    //THis function will take care of the graph is connected or disconnected
    bool* visited = new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i] = false;
    }
    //Now call the function to print BFS
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
            printBFS(edges,n,i,visited);
    }
    delete [] visited;
}
//hasPath done from bfs 
bool hasPath(int** edges,int n,int sv,int ev,bool* visited)
{
    //True Condition 
    if(sv==ev) return true;
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;
    while(!pendingVertices.empty())
    {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        //See if it's adjacent verices have path 
        //Run a loop 
        for(int i=0;i<n;i++)
        {
            if(edges[currentVertex][i] and !visited[i])
            {
                //Check the condition 
                if(ev==i)
                {
                    return true;
                }
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
    //Last condition 
    return false;
}
//i have return true if there is path between start node and end node 
// hasPath using DFS Traversal 
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
            res = hasPath(edges,n,i,ev,visited);
            if(res) return true;
        }
    }
    return false;
}
int main() {
    // Write your code here
    int n,e;cin>>n>>e;
    //Will use ajacency matrix 
    int** edges = new int*[n];
    //Forming the graph 
    for(int i=0;i<n;i++)
    {
        edges[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j] = 0;
        }
    }
    //Taking input of the edges in the graph 
    for(int i=0;i<e;i++)
    {
        int s,e;cin>>s>>e;
        edges[s][e] = 1;
        edges[e][s] = 1;
    }
    cout<<"BFS : ";
    BFS(edges,n);
    cout<<endl;
    //Check haspath Function 
    bool* visited = new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i] = false;
    }
    int sv,ev;cin>>sv>>ev;
    cout<<hasPath(edges,n,sv,ev,visited);
    //Delete graph 
    for(int i=0;i<n;i++)
    {
        delete [] edges[i];
    }
    return 0;
}