class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        set<int>s;
        for(auto it:nums){
           s.insert(it);
        }
        int ct=0,mx=1;
        for(int i=0;i<nums.size();i++){
            if(!s.count(nums[i]-1)){
                int a=nums[i];
                ct=0;
                while(s.count(a)){
                    ct++;
                    a++;
                }
                mx=max(mx,ct);
            }
        }
        return mx;
    }
};