//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int x=k;
        int st=0;
        int en=n;
        while(st<=en){
            int mid=(st+en)/2;
            if(mid>x){
                en=mid-1;
                continue;
            }
            if(x-mid>m){
                st=mid+1;
                continue;
            }
            int mx1=INT_MIN;
            int mx2=INT_MIN;
            int mn1=INT_MAX;
            int mn2=INT_MAX;
            if(mid-1>=0)mx1=arr1[mid-1];
            if(mid<n)mn1=arr1[mid];
            if(x-mid-1>=0)mx2=arr2[x-mid-1];
            if(x-mid<m)mn2=arr2[x-mid];
            if(mx1<=mn2 && mx2<=mn1){
                //cout<<mid<<" "<<mx1<<" "<<mx2<<endl;
                return max(mx1,mx2);
            }
            if(mx1>mn2){
                en=mid-1;
            }
            else st=mid+1;
        }
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends