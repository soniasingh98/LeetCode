class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        f(0,v,ans,nums,n);
        return ans;
    }
    void f(int i,vector<int>&v,vector<vector<int>>&ans,vector<int>&nums,int n){
        if(i==n){
            for(auto it:ans){
                if(v==it)return;
            }
            ans.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        f(i+1,v,ans,nums,n);
        v.pop_back();
        f(i+1,v,ans,nums,n);
    }
};