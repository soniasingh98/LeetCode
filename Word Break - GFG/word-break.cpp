//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        //code here
        unordered_map<string,int>m;
        for(auto it:B){
            m[it]++;
        }
        return f(0,A,B,m);
    }
    int f(int ind,string &s,vector<string>&b,unordered_map<string,int>&m){
        if(ind==s.size())return 1;
        string a="";
        for(int i=ind;i<s.size();i++){
            a+=s[i];
            if(m.count(a) && f(i+1,s,b,m))return 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends