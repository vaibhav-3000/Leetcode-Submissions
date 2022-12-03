class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,1));
        for(int i=n;i>=1;i--){
            for(int j=n;j>=1;j--){
                if(i>j)continue;
                if(i==j){ans++;continue;}
                if(dp[i+1][j-1]){
                    if(s[i-1]==s[j-1]){
                        dp[i][j]=1;
                        ans++;
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return ans;
        
    }
};