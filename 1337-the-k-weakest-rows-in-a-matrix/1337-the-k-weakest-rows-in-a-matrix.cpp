class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<mat.size();i++){
            int ct=0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1){
                    ct++;
                }
            }
            pq.push({ct,i});
        }
        vector<int>v;
        for(int i=0;i<k;i++){
            int element=pq.top().second;
            v.push_back(element);
            pq.pop();
        }
        return v;
    }
};