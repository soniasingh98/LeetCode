class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int mx=INT_MIN;
        for(int i=0;i<sentences.size();i++){
            mx=max(mx,int(count(sentences[i].begin(),sentences[i].end(),' ')+1));
        }
        return mx;
    }
};