class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==1 || nums.size()==2)return 1;
        int ct=0;
        vector<int>v(nums.size(),-1);
        for(int i=1;i<nums.size();i++){
            int a=nums[i]-nums[i-1];
            if(a>0){
                v[i]=1;
            }
            else if(a<0){
                v[i]=0;
            }
            else{
                v[i]=-1;
                ct++;
            }
        }
        vector<int>ans;
        for(int i=1;i<v.size();i++){
            if(v[i]!=-1){
                ans.push_back(v[i]);
            }
        }
        if(ans.size()==0)return nums.size()-ct;
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i]==ans[i+1]){
                ct++;
            }
        }
        return nums.size()-ct;
    }
};