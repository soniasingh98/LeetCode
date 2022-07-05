class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1)return nums.size();
        sort(nums.begin(),nums.end());
        vector<int>v;
        for(int k=0;k<nums.size()-1;k++){
            if(nums[k]==nums[k+1])continue;
            else{
                v.push_back(nums[k]);
            }
        }
        v.push_back(nums[nums.size()-1]);
        if(v.size()==1)return 1;
        int mx=INT_MIN;
        int ct=0;
        int i=0,j=1;
        while(i<v.size()-1){
            if(v[i]+1==v[i+1]){
                ct++;
                i++;
            }
            else{
                i=j;
                j++;
                 ct=0;
            }
             mx=max(ct,mx);
        }
        return mx+1;
    }
};