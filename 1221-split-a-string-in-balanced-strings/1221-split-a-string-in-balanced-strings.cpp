class Solution {
public:
    int balancedStringSplit(string s) {
        int ans=0,ctl=0,ctr=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='L'){
                ctl++;
            }
            else{
                ctr++;
            }
            if(ctl==ctr){
                ans++;
            }
        }
        return ans;
    }
};