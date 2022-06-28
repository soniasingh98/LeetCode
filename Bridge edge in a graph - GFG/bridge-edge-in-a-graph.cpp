// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<int>vis(V,0);
        vector<int>tip(V,- 1);
        vector<int>last(V,-1);
        vector<pair<int,int>>ans;
        int index=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
            dfs(i,-1,vis,tip,last,index,ans,adj); 
            }
        }
       
        
        for(auto it:ans){
            if((it.first==c && it.second==d) || (it.first==d && it.second==c)){
                return 1;
            }
        }
        return 0;
    }
    void dfs(int node,int parent,vector<int>&vis,vector<int>&tip,vector<int>&last,int &index,vector<pair<int,int>>&ans,vector<int>adj[]){
        vis[node]=1;
        tip[node]=last[node]=index++;
        for(auto it:adj[node]){
            if(it==parent)continue;
            if(!vis[it]){
              dfs(it,node,vis,tip,last,index,ans,adj);
              last[node]=min(last[node],last[it]);
              if(last[it]>tip[node]){
                  ans.push_back({node,it});
              }
           }
          else{
              last[node]=min(last[node],tip[it]);
          }
       }
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends