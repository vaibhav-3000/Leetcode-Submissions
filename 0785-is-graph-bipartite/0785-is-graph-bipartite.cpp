class Solution {
public:
    vector<int>color;
    vector<int>vis;
    int n;
    
    bool bfs(int node,int c,vector<vector<int>>&g){
        if(vis[node]){
            if(color[node]!=c)return false;
            color[node]=c;
            return true;
        }
        color[node]=c;
        vis[node]=1;
        
        for(auto child:g[node]){
            bool ans=bfs(child,!c,g);
            if(ans==false)return false;
        }
        return true;
        
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        color.resize(101,-1);
        vis.resize(101,0);
        n=graph.size();
        for(int i=0;i<n;i++){
            if(vis[i])continue;
            if(color[i]==-1){
                bool ans=bfs(i,1,graph);
                if(ans==false)return false;
            }
        }
        return true;
        
    }
};