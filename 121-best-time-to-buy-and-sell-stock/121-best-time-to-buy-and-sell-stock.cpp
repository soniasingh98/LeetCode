class Solution {
public:
    int maxProfit(vector<int>& prices) {
       
      int profit=0;
      int mn=prices[0];
        for(int i=1;i<prices.size();i++){
            profit=max(profit,prices[i]-mn);
            mn=min(mn,prices[i]);
        }
        return profit;
    }
    
};