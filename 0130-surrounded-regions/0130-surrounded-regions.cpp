class Solution {
public:
    int n;
    int m;
    vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(int i,int j,vector<vector<char>>&board,vector<vector<int>>&vis){
        for(auto e:dir){
            int x=i+e.first;
            int y=j+e.second;
            if(x>=0 && x<n && y>=0 && y<m){
                if(board[x][y]=='O' && vis[x][y]==0){
                    vis[x][y]=1;
                    dfs(x,y,board,vis);
                }
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        n=board.size();
        m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int j=0;j<m;j++){
            if(vis[0][j]==0 && board[0][j]=='O'){
                vis[0][j]=1;
                dfs(0,j,board,vis);
            }
            if(vis[n-1][j]==0 && board[n-1][j]=='O'){
                vis[n-1][j]=1;
                dfs(n-1,j,board,vis);
            }
        }
        
        for(int i=0;i<n;i++){
            if(vis[i][0]==0 && board[i][0]=='O'){
                vis[i][0]=1;
                dfs(i,0,board,vis);
            }
            if(vis[i][m-1]==0 && board[i][m-1]=='O'){
                vis[i][m-1]=1;
                dfs(i,m-1,board,vis);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j])board[i][j]='O';
                else board[i][j]='X';
            }
        }
        
        
        
    }
};