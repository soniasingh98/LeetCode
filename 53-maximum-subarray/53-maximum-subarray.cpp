class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,mn=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            mn=max(sum,mn);
            if(sum<0){
                sum=0;
            }
        }
        return mn;
    }
};