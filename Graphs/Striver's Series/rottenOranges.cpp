//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int dfs(vector<vector<int> >& grid,vector<vector<int> >& vis,int i,int j)
    {
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        //Mark it visited now
        vis[i][j] = 1;
        //Now see all the oranges which are fresh 
        for(int k=0;k<4;k++)
        {
            int newX = i+dir[k][0];
            int newY = j+dir[k][1];
            //Check all the condition 
            if(newX>=0 and newX<n and newY>=0 and newY<m and grid[newX][newY]==1 and !vis[newX][newY])
            {
                //Call this function 
                res = max(res,dfs(grid,vis,newX,newY));
            }
        }
        return res+1;
    }
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //Visited array to avoid seg fault 
        vector<vector<int> > vis(n,vector<int>(m,0));
        // Have to find minimum time required to rot all oranges 
        int res = 0;
        //So i have to maximum time so that all the oranges can be rotten 
        //so every time i will call the function dfs it will start from 0 
        //time will be required is the number of time function calls 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2 and !vis[i][j])
                {
                    //this orange is rotten now call dfs 
                    int time = dfs(grid,vis,i,j);
                    res = max(res,time);
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends