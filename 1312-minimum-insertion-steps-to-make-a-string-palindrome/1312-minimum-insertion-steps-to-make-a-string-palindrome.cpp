class Solution {
public:
    int n;
    int dp[501][501];
    int rec(int i,int j,string &s){
        if(i>=j)return dp[i][j]=0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==s[j]){
           return dp[i][j]=rec(i+1,j-1,s);
        }
        else{
            return dp[i][j]=min(1+rec(i,j-1,s),1+rec(i+1,j,s));
        }
        
    }
    int minInsertions(string s) {
        memset(dp,-1,sizeof(dp));
        n=s.size();
        return rec(0,n-1,s);
    }
};