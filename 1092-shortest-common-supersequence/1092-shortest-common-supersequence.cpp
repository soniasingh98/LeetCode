class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // 1. Find the longest common subsequence
        int n=str1.size();
        int m=str2.size();
        vector<vector<int>> t(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(str1[i-1]==str2[j-1])
                {
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else {
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
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
            if(str1[i-1]==str2[j-1])
            {
                res+=str1[i-1];
                i--;
                j--;
            }
            // Adding different char's
            else if(t[i-1][j]>t[i][j-1])
            {
                res+=str1[i-1];
                i--;
            }
            else {
                res+=str2[j-1];
                j--;
            }
        }
        //Now we have to add remaining chars
        
        while(i>0)
        {
            res+=str1[i-1];
            i--;
        }
        while(j>0)
        {
            res+=str2[j-1];
            j--;
        }
        //3. Reverse the string as we are iterating from last
        reverse(res.begin(),res.end());
        return res;
    }

};