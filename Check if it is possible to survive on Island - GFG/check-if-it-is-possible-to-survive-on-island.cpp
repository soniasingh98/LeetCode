//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        // code here
        int reqfood=S*M;
        int sunday=S/7;
        int daysicanbuyfood=S-sunday;
        int c=0;
        if(reqfood%N==0){
            c=reqfood/N;
        }
        else{
            c=reqfood/N+1;
        }
        return(c<=daysicanbuyfood)?c:-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends