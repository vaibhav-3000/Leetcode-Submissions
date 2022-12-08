//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {   set<vector<int>>ans; //{{temp}{temp}{temp}{temp}};
        //1 2 3 3
    //  j=3 2 1 0
        for(int i=0;i<pow(2,n);i++){
            int x=i;
            vector<int>temp;
            int j=0;
            while(x!=0){
                int last=x&1; // jth bit set hai ki nahi
                if(last){
                    temp.push_back(arr[j]);
                }
                x=x>>1;
                j++;
            }
            sort(temp.begin(),temp.end());
            ans.insert(temp);
        }
        vector<vector<int>>finalAns;
        for(auto e:ans)finalAns.push_back(e);
        
        return finalAns;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   



// } Driver Code Ends