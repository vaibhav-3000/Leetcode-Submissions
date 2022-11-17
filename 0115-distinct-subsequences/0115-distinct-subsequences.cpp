class Solution {
public:
    int n;
    int m;
    int numDistinct(string s, string t) {
        swap(s,t);
        n=s.size();
        m=t.size();
        vector<vector<unsigned long long int>>dp(n+1,vector<unsigned long long int>(m+1,0));
        for(int i=0;i<=m;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char a=s[i-1];
                char b=t[j-1];
                if(a==b){
                    dp[i][j]=dp[i][j-1]+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
        
        return dp[n][m];
        
    }
};