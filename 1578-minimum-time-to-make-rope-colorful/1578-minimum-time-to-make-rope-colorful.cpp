class Solution {
public:
    int minCost(string colors, vector<int>& time) {
       int sum=0;
        for(int i=0;i<colors.size()-1;i++){
            if(colors[i]==colors[i+1]){
                int f=time[i];
                int s=time[i+1];
                sum+=min(f,s);
                time[i+1]=max(f,s);
            }
        }
        return sum;
    }
};