class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int>distance(n,1e9);
        while(!q.empty()){
            auto a=q.front();
            int steps=a.first;
            int node=a.second.first;
            int dis=a.second.second;
            q.pop();
            if(steps>k)continue;
            for(auto it:adj[node]){
                int adjnode=it.first;
                int adjdis=it.second;
                if(dis+adjdis<distance[adjnode] && steps<=k){
                    distance[adjnode]=dis+adjdis;
                    q.push({steps+1,{adjnode,dis+adjdis}});
                }
            }
        }
        if(distance[dst]==1e9)return -1;
        return distance[dst];
    }
};