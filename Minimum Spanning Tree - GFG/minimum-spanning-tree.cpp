//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	int par(int i,vector<int>&parent){
	    if(i==parent[i])return i;
	    return par(parent[i],parent);
	}
     void unionn(int i,int j,vector<int>&rank,vector<int>&parent){
         int u=par(i,parent),v=par(j,parent);
         if(rank[u]>rank[v]){
             parent[v]=u;
         }
         else if(rank[v]>rank[u]){
             parent[u]=v;
         }
         else{
             parent[u]=v;
             rank[v]++;
         }
     }
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<vector<int>>edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                 vector<int>v;
                 v.push_back(it[1]);
                 v.push_back(i);
                 v.push_back(it[0]);
                 edges.push_back(v);
            }
        }
        vector<int>parent(V);
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        vector<int>rank(V,0);
        sort(edges.begin(),edges.end());
        int ans=0;
        for(auto it:edges){
            int w=it[0];
            int u=it[1];
            int v=it[2];
            if(par(u,parent)!=par(v,parent)){
                ans+=w;
                unionn(u,v,rank,parent);
            }
        }
        return ans;
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