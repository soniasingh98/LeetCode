class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int prevbuy=0,prevnotbuy=0,curbuy=0,curnotbuy=0;
        for(int i=n-1;i>=0;i--){
            
                    curbuy=max(-prices[i]+prevnotbuy,prevbuy);
            
                    curnotbuy=max(prices[i]+prevbuy,prevnotbuy);
                     prevbuy=curbuy;
                     prevnotbuy=curnotbuy;
                
        }
        
       return prevbuy;
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