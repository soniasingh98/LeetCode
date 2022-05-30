class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int a;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                a=i;
                break;
            }
            else if(nums[i]>target){
                a=i;
                break;
            }
        }
        return a;
    }
};