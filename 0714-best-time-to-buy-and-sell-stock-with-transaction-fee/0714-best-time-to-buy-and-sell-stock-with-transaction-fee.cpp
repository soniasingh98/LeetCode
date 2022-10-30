class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,1,prices,fee,n,dp);
    }
    int f(int i,int buy,vector<int>&prices,int fee,int n,vector<vector<int>>&dp){
        if(i==n)return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        if(buy){
            return dp[i][buy]=max(-prices[i]+f(i+1,0,prices,fee,n,dp),f(i+1,1,prices,fee,n,dp));
        }
        return dp[i][buy]=max(prices[i]-fee+f(i+1,1,prices,fee,n,dp),f(i+1,0,prices,fee,n,dp));
    }
};