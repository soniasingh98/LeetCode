class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int>adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        return dfs(adj,0,hasApple,vis);
    }
    int dfs(vector<int>adj[],int index,vector<bool>&hasApple,vector<int>&vis){
        vis[index]=1;
        int time=0;
        for(auto it:adj[index]){
            if(!vis[it]){
                time+=dfs(adj,it,hasApple,vis);
            }
        }
        if(index==0)return time;
        if(hasApple[index] || time>0){
            time+=2;
        }
        return time;
    }
};