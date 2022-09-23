class Solution {
public:
    int rob(vector<int>& nums) {
      if(nums.size()==1)return nums[0];
        vector<int>v1,v2;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i!=0){
                v1.push_back(nums[i]);
            }
            if(i!=n-1){
                v2.push_back(nums[i]);
            }
        }
        int ans1=maxSum(v1);
        int ans2=maxSum(v2);
        return max(ans1,ans2);
    }
    int maxSum(vector<int>&nums){
       if(nums.size()==1)return nums[0];
        int prev2=nums[0],prev1=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            int take=nums[i]+prev2;
            int nottake=0+prev1;
            int curi=max(take,nottake);
            prev2=prev1;
            prev1=curi;
        }
        return prev1;
    }
};