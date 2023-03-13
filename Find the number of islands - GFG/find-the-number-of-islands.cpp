//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

vector<pair<int,int>>dir={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

class Solution {
  public:
    void dfs(int i,int j,vector<vector<char>>& grid,int n,int m){
    for(auto e:dir){
        int x=i+e.first;
        int y=j+e.second;
        if(x>=0 && y>=0 && x<n && y<m && grid[x][y]=='1'){
            grid[x][y]='0';
            dfs(x,y,grid,n,m);
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){dfs(i,j,grid,n,m);ans++;}
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
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