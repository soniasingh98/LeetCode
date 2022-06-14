class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>v(2*n,0);
        for(int i=0;i<n;i++){
            v[2*i]=nums[i];
        }
        int k=1;
        for(int j=n;j<2*n;j++){
            v[k]=nums[j];
            k+=2;
        }
        return v;
    }
};