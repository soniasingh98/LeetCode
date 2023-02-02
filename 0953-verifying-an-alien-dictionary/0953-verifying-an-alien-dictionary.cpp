  unordered_map<char,int>m;
  bool cmp(string &a,string &b){
        int s=min(a.size(),b.size());
        for(int i=0;i<s;i++){
            if(m[a[i]]<m[b[i]])return true;
            else if(m[a[i]]>m[b[i]])return false;
        }
        if(a.size()<=b.size())return true;
        return false;
    }
class Solution {
public:
  
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<order.size();i++){
            m[order[i]]=i;
        }
        vector<string>temp=words;
        sort(temp.begin(),temp.end(),cmp);
        if(words==temp)return true;
        return false;
    }
};