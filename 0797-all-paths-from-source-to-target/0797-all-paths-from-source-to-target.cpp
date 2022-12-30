class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size()-1;
        vector<vector<int>>ans;
        vector<int>path;
       dfs(graph,0,ans,path,n);   
        return ans;
    }
    void dfs(vector<vector<int>>& graph, int s,vector<vector<int>>& ans,vector<int>&path,int n){
        path.push_back(s);
        for(auto i:graph[s]){
            if(i==n){
                path.push_back(i);
                ans.push_back(path);
                path.pop_back();
                // continue;
            }
            dfs(graph,i,ans,path,n);
            path.pop_back();
        }  
    }
};