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

int f(int i,string A,vector<string>&B,unordered_map<string,int>&m){
    if(i==A.size())return true;
    string s="";
    for(int ind=i;ind<A.size();ind++){
        s+=A[ind];
        if(m.count(s) && (m.count(A.substr(ind+1,A.size())) || f(ind+1,A,B,m)))return 1;
    }
    return 0;
}
    int wordBreak(string A, vector<string> &B) {
        //code here
        unordered_map<string,int>m;
        for(int i=0;i<B.size();i++){
            m[B[i]]++;
        }
        return f(0,A,B,m);
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