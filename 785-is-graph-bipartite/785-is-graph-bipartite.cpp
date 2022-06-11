class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>vis(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(vis[i]==-1){
                if(!bip(i,vis,graph)){
                    return false;
                }
            }
        }
        return true;
    }
    bool bip(int node,vector<int>&vis,vector<vector<int>>&graph){
        vis[node]=1;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int a=q.front();
            q.pop();
            for(auto it:graph[a]){
                if(vis[it]==-1){
                    q.push(it);
                    vis[it]=1-vis[a];
                }
                else if(vis[it]==vis[a])return false;
            }
        }
        return true;
    }
};