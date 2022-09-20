class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ct=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                for(int k=j;k<nums.size();k++){
                    if((nums[j]-nums[i]==diff) && (nums[k]-nums[j]==diff)){
                        ct++;
                    }
                }
            }
        }
        return ct;
    }
};