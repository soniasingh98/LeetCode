class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            int sum=0-nums[i];
            int a=i+1,b=n-1;
            while(a<b){
                if(nums[a]+nums[b] > sum)b--;
                else if(nums[a]+nums[b]<sum)a++;
                else{
                    vector<int>v;
                    v.push_back(nums[i]);
                    v.push_back(nums[a]);
                    v.push_back(nums[b]);
                    ans.push_back(v);
                    while(a<b && nums[a]==v[1])a++;
                    while(a<b && nums[b]==v[2])b--;
                }
            }
            while(i+1<n && nums[i+1]==nums[i])i++;
        }
        return ans;
    }
};