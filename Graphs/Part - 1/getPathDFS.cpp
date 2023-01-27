#include<bits/stdc++.h>
using namespace std;
//I have to return a vector containing a path from s to e
vector<int> getPathDFS(int** edges,int n,int sv,int ev,bool* visited)
{
    vector<int> res;
    //true condition
    if(sv==ev)
    {
        // cout<<"Hello "<<sv<<" "<<ev<<endl;
        res.push_back(sv);
        return res;
    }
    visited[sv] = true;
    for(int i=0;i<n;i++)
    {
        if(edges[sv][i]==1 and !visited[i])
        {
            vector<int> curr = getPathDFS(edges,n,i,ev,visited);
            if(curr.size())
            {
                //that means it contain result 
                // cout<<"Hey i am pushing "<<sv<<endl;
                //Curr should be copied to res 
                for(int i=0;i<curr.size();i++)
                {
                    res.push_back(curr[i]);
                }
                res.push_back(sv);
                return res;
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
    //Call the finction 
    int sv,ev;cin>>sv>>ev;
    vector<int> res = getPathDFS(edges,n,sv,ev,visited);
    // cout<<"Size "<<res.size()<<endl;
    //Print the vector
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}