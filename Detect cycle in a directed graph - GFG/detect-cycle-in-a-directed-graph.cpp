//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0);
        vector<int>dfsvis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,dfsvis))return true;
            }
        }
        return false;
    }
    bool dfs(int n,vector<int>adj[],vector<int>&vis,vector<int>&dfsvis){
        vis[n]=1;
        dfsvis[n]=1;
        for(auto it:adj[n]){
            if(!vis[it]){
                if(dfs(it,adj,vis,dfsvis))return true;
            }
            else if(dfsvis[it])return true;
        }
        dfsvis[n]=0;
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