class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start=0;
        int end=numbers.size()-1;
        vector<int>v;
        while(start<end){
            if((numbers[start]+numbers[end])==target){
                v.push_back(start+1);
                v.push_back(end+1);
                break;
            }
            else if((numbers[start]+numbers[end]) > target){
                end--;
            }
            else{
                start++;
            }
        }
        return v;
    }
};