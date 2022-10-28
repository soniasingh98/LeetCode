class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& st) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>m;
        for(int i=0;i<st.size();i++){
            string s=st[i];
            sort(st[i].begin(),st[i].end());
            m[st[i]].push_back(s);
        }
        for(auto it:m){
            ans.push_back(it.second);
        }
        return ans;
    }
};