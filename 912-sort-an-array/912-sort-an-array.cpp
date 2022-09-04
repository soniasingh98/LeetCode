class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
         sort(nums.begin(),nums.end());
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            v.push_back(nums[i]);
        }
        return v;
    }
};