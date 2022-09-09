class Solution {
public:
     static bool comp(vector<int> &a,vector<int> &b){
        if(a[0]!=b[0])
            return a[0]>b[0];
        return a[1]<b[1];
    }
    int numberOfWeakCharacters(vector<vector<int>>& pro) {
        sort(pro.begin(),pro.end(),comp);
        int ct=0;
        int mx=INT_MIN;
        for(auto p:pro){
            if(mx>p[1])ct++;
            else mx=p[1];
        }
        return ct;
    }
};