//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long arr[],long long temp[],long long left,long long mid,long long right){
        long long i=left,j=mid,k=left,ans=0;
        while(i<=mid-1 && j<=right){
            if(arr[i]<=arr[j]){
                temp[k++]=arr[i++];
            }
            else{
                temp[k++]=arr[j++];
                ans+=(mid-i);
            }
        }
        while(i<=mid-1){
            temp[k++]=arr[i++];
        }
        while(j<=right){
            temp[k++]=arr[j++];
        }
        for(long long i=left;i<=right;i++){
            arr[i]=temp[i];
        }
        return ans;
    }
    long long mergesort(long long arr[],long long temp[],long long left,long long right){
        long long ans=0;
        if(left<right){
            long long mid=(left+right)/2;
            ans+=mergesort(arr,temp,left,mid);
            ans+=mergesort(arr,temp,mid+1,right);
            ans+=merge(arr,temp,left,mid+1,right);
        }
        return ans;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
       long long temp[N];
       return mergesort(arr,temp,0,N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends