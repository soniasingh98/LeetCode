class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size(),i=0,j=0,ans=0;
        unordered_map<char,int>m;
        while(j<n){
            m[s[j]]++;
            if(m.size()==j-i+1){
                ans=max(ans,j-i+1);
                j++;
            }
            else if(m.size()<j-i+1){
                while(m.size()<j-i+1){
                    m[s[i]]--;
                    if(m[s[i]]==0)m.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};