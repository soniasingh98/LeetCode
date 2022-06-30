// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<int>vis(V,0);
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,st,adj);
            }
        }
        vector<int>reverse[V];
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto it:adj[i]){
                reverse[it].push_back(i);
            }
        }
          int ans=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
          
            if(!vis[node]){
              
                check(node,reverse,vis);
                  ans++;
               }
        }
        return ans;
    }
    void check(int node,vector<int>reverse[],vector<int>&vis){
       vis[node]=1;
        for(auto it:reverse[node]){
            if(!vis[it]){
            check(it,reverse,vis);
            }
        }
    }
    void dfs(int node,vector<int>&vis,stack<int>&st,vector<int>adj[]){
      vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,st,adj);
            }
        }
        st.push(node);
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends