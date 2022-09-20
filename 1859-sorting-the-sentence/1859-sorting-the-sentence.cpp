class Solution {
public:
    string sortSentence(string s) {
        string a;
        string arr[10];
        for(int i=0;i<s.size();i++){
            if(!isdigit(s[i]) && s[i]!=' '){
                a+=s[i];
            }
            else if(isdigit(s[i])){
                arr[s[i]-'0']=a;
                a="";
            }
        }
        a="";
        for(auto i:arr){
            if(i!=""){
                a+=i;
                a+=' ';
            }
        }
        a.pop_back();
        return a;
    }
};