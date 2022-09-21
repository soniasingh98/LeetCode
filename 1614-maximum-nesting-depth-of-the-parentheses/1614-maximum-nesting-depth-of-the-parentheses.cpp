class Solution {
public:
    int maxDepth(string s) {
        int ct=0,mx=INT_MIN;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                ct++;
                mx=max(ct,mx);
                
            }
            else if(s[i]==')'){
                ct--;
            }
        }
        if(mx==INT_MIN)return 0;
        return mx;
    }
};