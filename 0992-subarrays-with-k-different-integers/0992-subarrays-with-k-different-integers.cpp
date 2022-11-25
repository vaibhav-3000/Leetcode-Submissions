class Solution {
public:
    
    //atmost k
    int func(vector<int>&nums,int k){
        int i=0;
        int j=0;
        int n=nums.size();
        map<int,int>mp;
        int total=0;
        while(j<n){
            mp[nums[j]]++;
            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                i++;
            }
            total+=j-i+1;
            j++;
        }
        return total;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int x=func(nums,k);
        int y=func(nums,k-1);
        return x-y;
    }
};