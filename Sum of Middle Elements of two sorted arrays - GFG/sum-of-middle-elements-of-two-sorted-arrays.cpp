//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int findMidSum(int ar1[], int ar2[], int n) {
            // code here 
            int low=0,high=n;
            
            while(low<=high){
                int cut1=(low+high)/2;
                int cut2=n-cut1;
                int left1=(cut1==0)?INT_MIN:ar1[cut1-1];
                int left2=(cut2==0)?INT_MIN:ar2[cut2-1];
                int right1=(cut1==n)?INT_MAX:ar1[cut1];
                int right2=(cut2==n)?INT_MAX:ar2[cut2];
                if(left1<=right2 && left2<=right1){
                    return (max(left1,left2)+min(right1,right2));
                }
                else if(left1>right2){
                    high=cut1-1;
                }
                else{
                    low=cut1+1;
                }
            }
            return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++) {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends