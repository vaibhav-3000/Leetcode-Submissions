class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pre(n+1,0);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+(nums[i]%2);
        }
        map<int,int>mp;
        int ans=0;
        for(int i=0;i<=n;i++){
            ans+=mp[pre[i]-k];
            mp[pre[i]]++;
        }
        return ans;
    }
};