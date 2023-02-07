class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>v;
        f(0,target,ans,v,candidates);
        return ans;
    }
   void f(int ind,int target,vector<vector<int>>&ans,vector<int>&v,vector<int>&a){
      
           if(target==0){
               ans.push_back(v);
               return;
           }
          
       
       for(int i=ind;i<a.size();i++){
           if(i!=ind && a[i]==a[i-1])continue;
           if(a[i]>target)break;
           v.push_back(a[i]);
           f(i+1,target-a[i],ans,v,a);
           v.pop_back();
       }
   }
};