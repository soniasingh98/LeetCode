class Solution {

public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>vis(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(vis[i]==-1){
                if(!bip(i,graph,vis)){
                    return false;
                }
            }
        }
        return true;
    }
    bool bip(int node,vector<vector<int>>&graph,vector<int>&vis){
        if(vis[node]==-1){
            vis[node]=1;
        }
        for(auto it:graph[node]){
            if(vis[it]==-1){
                vis[it]=1-vis[node];
                if(!bip(it,graph,vis)){
                    return false;
                }
            }
            else if(vis[it]==vis[node])return false;
        }
        return true;
    }
};