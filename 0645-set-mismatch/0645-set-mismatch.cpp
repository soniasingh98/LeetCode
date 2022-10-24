class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int initialsum=accumulate(nums.begin(),nums.end(),0);
        set<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int setsum=accumulate(s.begin(),s.end(),0);
        int repeated=initialsum-setsum;
        int n=nums.size();
        int replaced=(n*(n+1)/2)-setsum;
        return {repeated,replaced};
    }
};