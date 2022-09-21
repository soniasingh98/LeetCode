class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string>se;
        string arr[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(int i=0;i<words.size();i++){
            string s="";
            for(int j=0;j<words[i].size();j++){
                int index=words[i][j]-'a';
                s+=arr[index];
            }
            se.insert(s);
        }
        return se.size();
    }
};