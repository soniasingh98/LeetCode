class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size()<k)return false;
        unordered_set<string>a;
        for(int i=0;i<=s.size()-k;i++){
            a.insert(s.substr(i,k));
        }
        if(a.size()==pow(2,k))return true;
        return false;
    }
};