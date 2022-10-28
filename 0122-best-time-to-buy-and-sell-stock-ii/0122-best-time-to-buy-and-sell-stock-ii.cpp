class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            
                    dp[i][1]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
            
                    dp[i][0]=max(prices[i]+dp[i+1][1],dp[i+1][0]);
                
        }
        
       return dp[0][1];
           // return f(0,1,prices,dp,n);
    }
    int f(int i,int buy,vector<int>&prices,vector<vector<int>>&dp,int n){
        if(i==n)return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        int profit=0;
        if(buy){
            profit=max(-prices[i]+f(i+1,0,prices,dp,n),f(i+1,1,prices,dp,n));
        }
        else{
            profit=max(prices[i]+f(i+1,1,prices,dp,n),f(i+1,0,prices,dp,n));
        }
        return dp[i][buy]=profit;
    }
};