class Solution {
public:
    bool checkString(string s) {
        int a=-1,flag=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                a=i;
            }
        }
        if(a==-1)return true;
        for(int i=0;i<=a;i++){
            if(s[i]=='b'){
                flag=1;
            }
        }
        if(flag==1)return false;
        return true;
    }
};