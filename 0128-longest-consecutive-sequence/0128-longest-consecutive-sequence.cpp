class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        unordered_map<int,int>m;
        for(auto it:nums){
            m[it]++;
        }
        int ct=0,mx=1;
        for(int i=0;i<nums.size();i++){
            int a=nums[i];
            if(m.find(nums[i]-1)==m.end()){
                ct=0;
                while(m.find(a)!=m.end()){
                    ct++;
                    a++;
                }
                mx=max(mx,ct);
            }
        }
        return mx;
    }
};