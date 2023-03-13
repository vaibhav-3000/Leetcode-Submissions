//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int parent[1001];

class Solution
{
	public:
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
	        //cout<<b<<" "<<a<<endl;
	        parent[b]=a;
	    }
	}
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        set<vector<int>>edges;//wt,u,v;
        for(int i=0;i<V;i++){
            for(auto e:adj[i]){
                edges.insert({e[1],i,e[0]});
            }
        }
        //for(auto e:edges)cout<<e[0]<<" "<<e[1]<<" "<<e[2]<<endl;
        int total=0;
        for(int i=0;i<V;i++){make(i);}
        for(auto e:edges){
            int wt=e[0];
            int u=e[1];
            int v=e[2];
            if(find(u)!=find(v)){
                total+=wt;
                //cout<<u<<" "<<v<<endl;
                Union(u,v);
            }
        }
        return total;

    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends