class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=rocks.size();
        vector<int>need(n);
        for(int i=0;i<n;i++){
            need[i]=capacity[i]-rocks[i];
        }
        sort(need.begin(),need.end());
        int i=0;
       for( i=0;i<n;i++){
            if(additionalRocks<need[i]){
             break;
         }
         additionalRocks-=need[i];
        
       }
       return i;
    }
};