//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    pair<int,int>ans={INT_MIN,INT_MAX};
    for(int i=0;i<n;i++){
        int a=arr[i];
        if(a<=x){
            ans.first=max(ans.first,a);
        }
        if(a>=x){
            ans.second=min(ans.second,a);
        }
    }
    if(ans.first==INT_MIN)ans.first=-1;
    if(ans.second==INT_MAX)ans.second=-1;
    return ans;
}