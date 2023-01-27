//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void bfs(int row,int col,vector<vector<int> > &vis,vector<vector<char> > &grid)
    {
        vis[row][col] = 1;
        queue<pair<int,int> > q;
        q.push({row,col});
        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            //traverse in its neighbours and mark them if it's a land 
            for(int delRow=-1;delRow<=1;delRow++)
            {
                for(int delCol=-1;delCol<=1;delCol++)
                {
                    int nrow = row + delRow;
                    int ncol = col + delCol;
                    if(nrow>=0 and nrow<n and ncol>=0 and ncol<n and grid[nrow][ncol]=='1' and !vis[nrow][ncol])
                    {
                        //than add them in queue 
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }
    // Function to find the number of islands.
    //Writing Bfs function for the same 
    int numIslands(vector<vector<char> >& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int> > vis(n,vector<int>(m,0));
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if(!vis[row][col] and grid[row][col]=='1')
                {
                    cnt++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return cnt;
    }
};

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