class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            int ct=0;
            for(int j=0;j<nums.size();j++){
                if(i!=j){
                    if(nums[j]<nums[i]){
                        ct++;
                    }
                }
            }
            v.push_back(ct);
        }
        return v;
    }
};