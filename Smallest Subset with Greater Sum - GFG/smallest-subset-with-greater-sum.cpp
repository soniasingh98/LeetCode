//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int minSubset(vector<int> &Arr,int N){
        sort(Arr.begin(),Arr.end());
        long long totsum=0,elesum=0;
        int ans=0,j=N-1;
        for(int i=0;i<N;i++){
            totsum+=Arr[i];
        }
        while(totsum>=elesum){
            ans++;
            totsum-=Arr[j];
            elesum+=Arr[j];
            j--;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        cout<<ob.minSubset(Arr,N)<<endl;
    }
    return 0;
}
// } Driver Code Ends