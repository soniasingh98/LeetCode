//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	 int findpar(int i,vector<int>&parent){
            return parent[i]= (i==parent[i])?i:findpar(parent[i],parent);
        }
        
        int unionn(int i,int j,vector<int>&rank,vector<int>&parent){
            int u=parent[i];
            int v=parent[j];
            if(rank[u]>rank[v]){
                parent[v]=u;
            }
            else if(rank[v]>rank[u]){
                parent[u]=v;
            }
            else{
                parent[u]=v;
                v++;
            }
        }
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int>rank(V,0),parent(V);
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
       
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
        sort(edges.begin(),edges.end());
        int ans=0;
        for(auto it:edges){
            if(findpar(it[1],parent)!=findpar(it[2],parent)){
                ans+=it[0];
                unionn(it[1],it[2],rank,parent);
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