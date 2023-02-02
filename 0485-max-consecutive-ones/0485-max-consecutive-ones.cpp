class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ct=0,maxi=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)ct++;
            else{
                maxi=max(maxi,ct);
                ct=0;
            }     
        }
        maxi=max(maxi,ct);
        return maxi;
    }
};