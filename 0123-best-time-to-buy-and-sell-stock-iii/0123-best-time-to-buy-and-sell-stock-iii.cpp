class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy){
                        dp[i][buy][cap]=max(-prices[i]+dp[i+1][0][cap],dp[i+1][1][cap]);
                    }
                    else{
                        dp[i][buy][cap]=max(prices[i]+dp[i+1][1][cap-1],dp[i+1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
    int f(int i,int buy,int cap,vector<int>&prices,int n,vector<vector<vector<int>>>&dp){
        if(cap==0 || i==n)return 0;
        if(dp[i][buy][cap]!=-1)return dp[i][buy][cap];
        if(buy){
            return dp[i][buy][cap]=max(-prices[i]+f(i+1,0,cap,prices,n,dp),f(i+1,1,cap,prices,n,dp));
        }
        return dp[i][buy][cap]=max(prices[i]+f(i+1,1,cap-1,prices,n,dp),f(i+1,0,cap,prices,n,dp));
    }
    
};