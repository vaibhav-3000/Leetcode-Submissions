//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[1][1]=arr[0];
        for(int i=1;i<n;i++){
            dp[i+1][0]=max(dp[i][0],dp[i][1]);
            dp[i+1][1]=max(dp[i+1][0],dp[i][0]+arr[i]);
        }
        //for(auto e:dp)cout<<e[0]<<" ";cout<<endl<<endl;
       // for(auto e:dp)cout<<e[1]<<" ";cout<<endl<<endl;
        return max(dp[n][0],dp[n][1]);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends