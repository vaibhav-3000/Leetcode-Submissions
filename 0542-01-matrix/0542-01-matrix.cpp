class Solution {
public:
    vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));
        queue<vector<int>>q;//i,j,level
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    vis[i][j]=0;
                    q.push({i,j,0});
                }
            }
        }
        while(!q.empty()){
            auto f=q.front();
            q.pop();
            int i=f[0];
            int j=f[1];
            int level=f[2];
            for(auto e:dir){
                int x=i+e.first;
                int y=j+e.second;
                if(x>=0 && x<n && y>=0 && y<m){
                    if(vis[x][y]!=-1)continue;
                    q.push({x,y,level+1});
                    vis[x][y]=level+1;
                }
            }
        }
        return vis;
    }
};