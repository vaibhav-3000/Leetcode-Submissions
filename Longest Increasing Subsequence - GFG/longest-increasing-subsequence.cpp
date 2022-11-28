//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    int longestSubsequence(int n, int a[])
    {
        vector<int>sub;
        for(int i=0;i<n;i++){
            int x=a[i];
            if(sub.size()==0 || sub[sub.size()-1]<x){
                sub.push_back(x);
            }
            else{
                auto it=lower_bound(sub.begin(),sub.end(),x);
                *it=x;
            }
        }
        return sub.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends