class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int totalsum=0;
        for(auto it:nums){
            totalsum+=it;
        }
        if(((totalsum-target)<0) || ((totalsum-target)%2))return 0;
        return findways(nums,(totalsum-target)/2);
    }
    int findways(vector<int>& nums, int target){
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return f(n-1,target,dp,nums);
    }
    int f(int i,int t,vector<vector<int>>&dp,vector<int>&nums){
        if(i==0){
            if(nums[0]==0 && t==0)return 2;
            if(t==0 || t==nums[0])return 1;
            return 0;
        }
        if(dp[i][t]!=-1)return dp[i][t];
        int nt=f(i-1,t,dp,nums);
        int ta=0;
        if(nums[i]<=t)ta=f(i-1,t-nums[i],dp,nums);
        return dp[i][t]=nt+ta;
    }
};