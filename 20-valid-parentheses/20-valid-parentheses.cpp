class Solution {
public:
    bool isValid(string s) {
        int arr[s.size()];
        int top=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                top++;
                arr[top]=s[i];
            } 
            else if(s[i]==')' || s[i]=='}' || s[i]==']'){
                if(top==-1){
                    return false;
                }
                else{
                    if(check(s[i],arr[top])){
                        top--;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
           if(top==-1)return true;
        else{return false;}
    }
    bool check(char char1,char char2){
         if(char1=='}' && char2=='{'){
                    return true;
                }
          else if(char1==')' && char2=='('){
                   return true;
                }
          else if(char1==']' && char2=='['){
                    return true;
                }
        return false;
    }
};