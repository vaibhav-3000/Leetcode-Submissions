//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int count(int k,vector<vector<int>>&matrix){
        int n=matrix.size();
        int m=matrix[0].size();
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]<=k)c++;
            }
        }
        return c;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        int st=1;
        int en=2000;
        while(st<=en){
            int mid=(st+en)/2;
            int c=count(mid,matrix);
            if(c>=(R*C)/2+1){
                en=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        return st;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends