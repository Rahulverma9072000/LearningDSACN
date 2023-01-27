
#include <bits/stdc++.h>
using namespace std;

// } Driver Code End
class Solution {
  public:
    int dir[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{-1,1},{1,1},{-1,-1},{1,-1}};
    //Traverse the grid 
    void traverseGrid(vector<vector<char> >& grid,bool** visited,int i,int j,int n,int m)
    {
        //Outside condition 
        if(i>=n or j<0 or j>=m or i<0) return ;
        //Other False condition 
        if(grid[i][j]!='1' or visited[i][j]) return ;
        //If this is the correct index 
        visited[i][j] = true;
        //Move in all direction 
        for(int k =0;k<8;k++)
        {
            int x = dir[k][0];
            int y = dir[k][1];
            traverseGrid(grid,visited,i+x,j+y,n,m);
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char> >& grid) {
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        //Have to return the number of Island in the grid 
        //Have to make visited 2d array 
        bool** visited = new bool*[n];
        for(int i=0;i<n;i++)
        {
            visited[i] = new bool[m];
            for(int j=0;j<m;j++)
            {
                visited[i][j] = false;
            }
        }
        //I have to start traversing the grid for only one 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' and !visited[i][j])
                {
                    //start traversing the graph here
                    // cout<<"Calling for "<<i<<" "<<j<<endl;
                    res+=1;
                    traverseGrid(grid,visited,i,j,n,m);
                }
            }
        }
        return res;
    }
};
void bfs(int row,int col,vector<vector<int> > &vis,vector<vector<char> > &grid)
{
    vis[row][col] = true;
    queue<pair<int,int> > q;
    q.push({row,col});
    int n = grid.size();
    int m = grid[0].size();
    while(!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        //traverse in the nneighbiurs and mark them land
        for(int delrow = -1;delrow<=1;delrow++)
        {
            for(int delcol = -1;delcol<=1;delcol++)
            {
                int nrow = row+delrow;
                int ncol = col+delcol;
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]=='1' and !vis[nrow][ncol])
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
}
//Striver's Way BFS 
int numIsland(vector<vector<char> >& grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int> > vis(n,vector<int>(m,0));
    int cnt = 0;
    for(int row =0;row<n;row++)
    {
        for(int col=0;col<m;col++)
        {
            if(!vis[row][col])
            {
                cnt++;
                bfs(row,col,vis,grid);
            }
        }
    }
    return cnt;
}
//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char> > grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends