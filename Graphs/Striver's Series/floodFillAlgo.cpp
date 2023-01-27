//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(vector<vector<int> >& image,int sr,int sc,int prevColor,int newColor,vector<vector<int> > &vis)
    {
        int n = image.size();
        int m = image[0].size();
        //Check the index of 2d image 
        //Check if the same color //
        image[sr][sc] = newColor;
        //Mark it visited
        vis[sr][sc] = 1;
        //Check if it's neighbour are of same color or not 
        for(int i=0;i<4;i++)
        {
            int newX = sr+dir[i][0];
            int newY = sc + dir[i][1];
            if(newX>=0 and newX<n and newY >=0 and newY<m and image[newX][newY]==prevColor and !vis[newX][newY])
            {
                dfs(image,newX,newY,prevColor,newColor,vis);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        //Change the color of all elements connected from the given coordinate 
        //if they have the same color present as the starting node 
        //and apply traversal from it 
        int n = image.size();
        int m = image[0].size();
        int prevColor = image[sr][sc];
        //Apply dfs
        //Have to make a visited 2d array 
        vector<vector<int> > vis(n,vector<int>(m,0));
        dfs(image,sr,sc,prevColor,newColor,vis);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends