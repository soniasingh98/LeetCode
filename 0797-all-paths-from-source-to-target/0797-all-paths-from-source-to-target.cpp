class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>path;
        int n=graph.size()-1;
        path.push_back(0);
        queue<vector<int>>q;
        q.push(path);
        while(!q.empty()){
            path=q.front();
            q.pop();
            int val=path.back();
            if(val==n){
                ans.push_back(path);
            }
            for(auto i:graph[val]){
                vector<int>v(path);
                v.push_back(i);
                q.push(v);
            }
        }
        return ans;
    }
};