class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>v;
        f(0,ans,v,s);
        return ans;
    }
    void f(int i,vector<vector<string>>&ans,vector<string>&v,string &s){
        if(i==s.size()){
            ans.push_back(v);
            return;
        }
        for(int j=i;j<s.size();j++){
            if(isPalindrome(i,j,s)){
                v.push_back(s.substr(i,j-i+1));
                f(j+1,ans,v,s);
                v.pop_back();
            }
        }
    }
    bool isPalindrome(int i,int j,string &s){
        while(i<j){
            if(s[i++]!=s[j--])return false;
        }
        return true;
    }
};