class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>v(nums);
       for(auto it:nums){
           v.push_back(it);
       }
        
        return v;
    }
};