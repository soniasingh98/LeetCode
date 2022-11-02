class Solution {
public:
     static bool comp(string &a,string &b){
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n=words.size();
        int maxi=1;
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(checkpossible(words[i],words[j]) && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
   
    bool checkpossible(string &a,string &b){
        if(a.size()!=b.size()+1)return false;
        int first=0,second=0;
        while(first<a.size()){
        if(a[first]==b[second]){
            first++;
            second++;
        }
            else{
                first++;
            }
        }
        if(first==a.size() && second==b.size())return true;
        return false;
    }
};