class Solution {
public:
    int numberOfSteps(int num) {
        int ct=0;
        while(num>0){
            if(num%2==0){
                num=num/2;
                ct++;
            }
            else{
                num=num-1;
                ct++;
            }
        }
        return ct;
    }
};