class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
       vector<int>dp(cost.size()+1,0);
        dp[0]=0;
        for(int i=1;i<=cost.size();i++){
            int fs=dp[i-1]+cost[i-1];
            int ss=INT_MAX;
            if(i>1){
                ss=dp[i-2]+cost[i-2];
            }
            dp[i]=min(fs,ss);
        }
        vector<int>dp2(cost.size()+1,0);
        dp2[1]=0;
        for(int i=2;i<=cost.size();i++){
            int fs=dp2[i-1]+cost[i-1];
            int ss=INT_MAX;
            if(i>2){
                ss=dp2[i-2]+cost[i-2];
            }
            dp2[i]=min(fs,ss);
        }
        return(min(dp[cost.size()],dp2[cost.size()]));
    }
};