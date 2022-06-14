class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int mx=INT_MIN;
        for(int i=0;i<accounts.size();i++){
            int sum=0;
            for(auto it:accounts[i]){
                sum+=it;
            }
            mx=max(sum,mx);
        }
        return mx;
    }
};