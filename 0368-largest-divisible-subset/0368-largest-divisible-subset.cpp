class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        map<int,int>from;
        for(int i=0;i<n;i++)from[i]=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        from[i]=j;
                    }
                }
            }
        }
        int mx=*max_element(dp.begin(),dp.end());
        //for(auto e:dp)cout<<e<<" ";cout<<endl;
        
       // for(auto e:from)cout<<e.first<<" "<<e.second<<endl;
        vector<int>ans;
        int idx;
        for(int i=0;i<n;i++){
            if(dp[i]==mx){idx=i;break;}
        }
      ////  cout<<idx<<endl;
        while(idx!=-1){
            ans.push_back(nums[idx]);
            idx=from[idx];
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};