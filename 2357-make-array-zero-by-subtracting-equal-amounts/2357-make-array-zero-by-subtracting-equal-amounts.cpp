class Solution {
public:
    int minimumOperations(vector<int>& nums) {
         set<int>s;
        int count=0;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        for(auto element:s){
            if(element!=0){
                count++;
            }
        }
        return count;
    }
};