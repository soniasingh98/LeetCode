class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_map<string,int>m;
        for(auto it:words){
            m[it]++;
        }
        vector<string>v;
        for(auto it:words){
            if(isconcat(it,m)){
                v.push_back(it);
            }
        }
        return v;
    }
    bool isconcat(string s,unordered_map<string,int>&m){
       
        for(int i=0;i<s.size();i++){
           string prefix=s.substr(0,i);
            string suffix=s.substr(i);
            if(m[prefix] && (m[suffix] || isconcat(suffix,m)))return true;
        }
        return false;
    }
};