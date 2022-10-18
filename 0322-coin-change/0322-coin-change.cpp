class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans= f(n-1,amount,coins,dp);
        if(ans==1e9)return -1;
        else return ans;
    }
    int f(int i,int t,vector<int>&coins,vector<vector<int>>&dp){
        if(i==0){
            if(t%coins[i]==0)return t/coins[i];
            else return 1e9;
        }
        if(dp[i][t]!=-1)return dp[i][t];
        int nt=0+f(i-1,t,coins,dp);
        int take=INT_MAX;
        if(coins[i]<=t)take=1+f(i,t-coins[i],coins,dp);
        return dp[i][t]=min(nt,take);
    }
};