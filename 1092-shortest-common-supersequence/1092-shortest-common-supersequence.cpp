class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        // 1. Find the longest common subsequence
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        //2. Now we will iterate our dp tabel 
        // if char is same then we will go to i-- and j--
        // else we will go to max value in the tabel
        string res="";
        int i=n,j=m;
        while(i>0 && j>0)
        {
            // Adding same char's
            if(s[i-1]==t[j-1])
            {
                res+=s[i-1];
                i--;
                j--;
            }
            // Adding different char's
            else if(dp[i-1][j]>dp[i][j-1])
            {
                res+=s[i-1];
                i--;
            }
            else {
                res+=t[j-1];
                j--;
            }
        }
        //Now we have to add remaining chars
        
        while(i>0)
        {
            res+=s[i-1];
            i--;
        }
        while(j>0)
        {
            res+=t[j-1];
            j--;
        }
        //3. Reverse the string as we are iterating from last
        reverse(res.begin(),res.end());
        return res;
    }

};