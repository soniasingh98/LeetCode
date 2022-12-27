class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size(),j=0,i=0,mx=INT_MIN;
        unordered_map<char,int>m;
        while(j<n){
            m[s[j]]++;
            if(m.size()==j-i+1){
                mx=max(mx,j-i+1);
                j++;
            }
            else if(m.size()<j-i+1){
                while(m.size()<j-i+1){
                    m[s[i]]--;
                    if(m[s[i]]==0){
                        m.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        if(mx==INT_MIN)return 0;
        return mx;
    }
};