//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    int st=0;
	    int en=n-1;
	    int ans=0;
	    while(st<=en){
	        int mid=(st+en)/2;
	        if(arr[mid]<arr[0]){
	            ans=mid;
	            en=mid-1;
	        }
	        else{
	            st=mid+1;
	        }
	    }
	    return ans;
	    
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends