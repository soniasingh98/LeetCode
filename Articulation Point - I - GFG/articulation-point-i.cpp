// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int>tin(V,-1);
        vector<int>last(V,-1);
        vector<int>vis(V,0);
        vector<int>ans(V,-1);
        vector<int>toreturn;
        vector<int>ne(1,-1);
        int index=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,-1,tin,last,vis,ans,index,adj);
            }
        }
        for(int i=0;i<V;i++){
            if(ans[i]==1){
                toreturn.push_back(i);
            }
        }
        if(toreturn.size()==0){
            return ne;
        }
        return toreturn;
    }
    void dfs(int node,int parent,vector<int>&tin,vector<int>&last,vector<int>&vis,vector<int>&ans,int &index,vector<int>adj[]){
        vis[node]=1;
        int count=0;
        tin[node]=last[node]=index++;
        for(auto it:adj[node]){
            if(it==parent)continue;
            if(!vis[it]){
                dfs(it,node,tin,last,vis,ans,index,adj);
                last[node]=min(last[node],last[it]);
                if(last[it]>=tin[node] && parent!=-1){
                    ans[node]=1;
                }
                count++;
            }
            else{
                last[node]=min(last[node],tin[it]);
            }
        }
        if(parent==-1 && count>1){
            ans[node]=1;
        }
    }
};

// { Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends