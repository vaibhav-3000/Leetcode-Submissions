class Solution {
public:
    map<int,vector<vector<int>>>graph;
    int ans;
    map<int,bool>vis;
    void dfs(int src)
    {
        vis[src]=true;
        for(auto nbrs:graph[src])
        {
            ans=min(ans,nbrs[1]);
            if(!vis[nbrs[0]])
            dfs(nbrs[0]);
        }
        return ;
    }
    int minScore(int n, vector<vector<int>>& roads)
    {
        ans=INT_MAX;
        for(auto x:roads)
        {
            int u=x[0];
            int v=x[1];
            int wt=x[2];
            graph[u].push_back({v,wt});
            graph[v].push_back({u,wt});
        }
        dfs(1);
        return ans;
    }
};