class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int>m;
        for(int i=0;i<allowed.size();i++){
            m[allowed[i]]++;
        }
        int ans=0;
        for(int i=0;i<words.size();i++){
            int ct=0;
            for(int j=0;j<words[i].size();j++){
                if(m[words[i][j]]==1){
                    ct++;
                }
            }
            if(ct==words[i].size()){
                ans++;
            }
        }
        return ans;
    }
};