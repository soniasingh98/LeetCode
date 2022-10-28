class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(0,1,k,prices,n,dp);
    }
    int f(int i,int buy,int k,vector<int>&prices,int n,vector<vector<vector<int>>>&dp){
        if(k==0 || i==n)return 0;
        if(dp[i][buy][k]!=-1)return dp[i][buy][k];
        if(buy){
            return dp[i][buy][k]=max(-prices[i]+f(i+1,0,k,prices,n,dp),f(i+1,1,k,prices,n,dp));
        }
        return dp[i][buy][k]=max(prices[i]+f(i+1,1,k-1,prices,n,dp),f(i+1,0,k,prices,n,dp));
    }
};