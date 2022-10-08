class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalsum=0;
        for(auto i:nums){
            totalsum+=i;
        }
        if(totalsum%2!=0)return false;
        else{
            int k=totalsum/2;
            vector<vector<int>>dp(n,vector<int>(k+1,-1));
            return f(n-1,k,nums,dp);
        }
    }
    bool f(int i,int target,vector<int>& nums,vector<vector<int>>&dp){
        if(target==0)return true;
        if(i==0)return nums[i]==target;
        if(dp[i][target]!=-1)return dp[i][target];
        bool nt=f(i-1,target,nums,dp);
        bool t=false;
        if(nums[i]<=target)t=f(i-1,target-nums[i],nums,dp);
        return dp[i][target]=nt | t;
    }
};