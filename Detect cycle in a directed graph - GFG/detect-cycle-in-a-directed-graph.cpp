//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int>vis;
    vector<bool>inPath;
    bool cycleMila(int node,vector<int>adj[]){
        vis[node]=1;
        inPath[node]=true;
        for(auto child:adj[node]){
            if(inPath[child])return true;
            if(vis[child])continue;
            bool f=cycleMila(child,adj);
            if(f)return true;
        }
        inPath[node]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vis.resize(V,0);
        inPath.resize(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(cycleMila(i,adj))return true;
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends