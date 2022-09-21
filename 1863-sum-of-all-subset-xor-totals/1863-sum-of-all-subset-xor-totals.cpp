class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<(1<<n);i++){
            vector<int>v;
            for(int bit=0;bit<n;bit++){
                if(i&(1<<bit)){
                    v.push_back(nums[bit]);
                }
            }
            int sum=0;
            for(auto a:v){
                sum=sum^a;
            }
            ans+=sum;
        }  
        return ans;
        }
    
};