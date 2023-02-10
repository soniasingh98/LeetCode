//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        if(m[0][0]==1)solve(0,0,m,n,"",ans);
        return ans;
    }
    void solve(int i,int j,vector<vector<int>> &m,int n,string s,vector<string>&ans){
        if(i==n-1 && j==n-1){
            ans.push_back(s);
            return;
        }
        //down
        if(i+1<n && m[i+1][j]==1){
            m[i][j]=0;
            solve(i+1,j,m,n,s+'D',ans);
            m[i][j]=1;
        }
        //left
        if(j-1>=0 && m[i][j-1]==1){
            m[i][j]=0;
            solve(i,j-1,m,n,s+'L',ans);
            m[i][j]=1;
        }
        //right
        if(j+1<n && m[i][j+1]==1){
            m[i][j]=0;
            solve(i,j+1,m,n,s+'R',ans);
            m[i][j]=1;
        }
        //up
        if(i-1>=0 && m[i-1][j]==1){
            m[i][j]=0;
            solve(i-1,j,m,n,s+'U',ans);
            m[i][j]=1;
        }
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends