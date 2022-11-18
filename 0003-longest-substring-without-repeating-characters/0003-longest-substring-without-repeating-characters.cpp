class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        map<char,int>mp;
        for(auto e:s){mp[e]=-1;}
        int start=-1;
        int ans=0;
        for(int i=0;i<n;i++){
            start=max(start,mp[s[i]]+1);
            ans=max(ans,i+1-start);
            mp[s[i]]=i;
        }
        return ans;
    }
};