class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),comp);
        int ans=0;
        int last=INT_MIN;
        
        for(auto e:arr){
            int st=e[0];
            int en=e[1];
            if(st>=last){
                last=en;
            }
            else ans++;
        }
        return ans;
    }
};