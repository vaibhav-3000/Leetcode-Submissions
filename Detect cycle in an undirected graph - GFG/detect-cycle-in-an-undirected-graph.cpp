//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int parent[100010];
  int sizez[100010];
  void make(int i){
      parent[i]=i;
  }
  int find(int v){
      if(v==parent[v])return v;
      return parent[v]=find(parent[v]);
  }
  void Union(int a,int b){
      a=find(a);
      b=find(b);
      if(a!=b){
          if(sizez[a]<sizez[b])swap(a,b);
          parent[b]=a;
          sizez[a]+=sizez[b];
      }
  }
  bool isCycle(int V, vector<int> adj[]) {
        for(int i=0;i<V;i++){
            make(i);
        }
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            vis[i]=1;
            for(auto child:adj[i]){
                if(vis[child])continue;
                if(find(i)==find(child))return true;
                Union(i,child);
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends