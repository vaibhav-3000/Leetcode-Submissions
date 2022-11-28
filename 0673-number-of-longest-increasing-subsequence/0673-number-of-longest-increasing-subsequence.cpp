class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>ways(n,0);
        for(int i=0;i<n;i++){
            int x=nums[i];
            int mx=1;
            for(int j=0;j<i;j++){
                if(x>nums[j]){
                    mx=max(mx,dp[j]+1);
                }
            }
            dp[i]=mx;
            for(int j=0;j<i;j++){
                if(x>nums[j] && dp[j]==dp[i]-1){
                    ways[i]+=ways[j];
                }
            }
            ways[i]=max(1,ways[i]);
        }
        int mx=*max_element(dp.begin(),dp.end());
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==mx){
                ans+=ways[i];
            }
        }
        return ans;
    }
};