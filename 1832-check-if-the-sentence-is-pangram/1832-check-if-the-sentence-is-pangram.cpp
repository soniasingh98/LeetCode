class Solution {
public:
    bool checkIfPangram(string s) {
        int arr[26]={0};
        for(int i=0;i<s.size();i++){
            int index=s[i]-'a';
            arr[index]++;
        }
        for(int i=0;i<26;i++){
            if(arr[i]==0)return false;
        }
        return true;
    }
};