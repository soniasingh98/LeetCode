class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        cs(0,candidates,target,ans,v);
        return ans;
    }
    void cs(int i,vector<int>&c,int t,vector<vector<int>>&ans,vector<int>&v){
        if(i==c.size()){
            if(t==0){
                // vector<int>temp;
                // for(int i=0;i<v.size();i++){
                //     temp.push_back(v[i]);
                // }
                ans.push_back(v);
            }
        }
        else{
            v.push_back(c[i]);
            if(t>=c[i]){
            cs(i,c,t-c[i],ans,v);}
            v.pop_back();
            cs(i+1,c,t,ans,v);
        }
    }
};