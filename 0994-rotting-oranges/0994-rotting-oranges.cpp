class Solution {
public:
    vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>>q;//i,j,level;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){q.push({i,j,0});}
            }
        }
        int ans=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        while(!q.empty()){
            auto f=q.front();
            q.pop();
            int i=f[0];
            int j=f[1];
            vis[i][j]=1;
            int level=f[2];
            ans=max(ans,level);
            for(auto e:dir){
                int x=i+e.first;
                int y=j+e.second;
                if(x>=0 && x<n && y>=0 && y<m){
                    if(!vis[x][y] && grid[x][y]==1){
                        vis[x][y]=1;
                        q.push({x,y,level+1});
                    }
                }
            }
            
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0)return -1;
            }
        }
        return ans;
        
    }
};