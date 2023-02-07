class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        sort(nums.begin(),nums.end());
        f(0,ans,v,nums);
        return ans;
    }
    void f(int ind,vector<vector<int>>&ans,vector<int>&v,vector<int>&nums){
        ans.push_back(v);
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1])continue;
            v.push_back(nums[i]);
            f(i+1,ans,v,nums);
            v.pop_back();
        }
    }
};

