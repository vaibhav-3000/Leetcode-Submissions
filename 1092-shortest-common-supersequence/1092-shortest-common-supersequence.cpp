class Solution {
public:
    int n;
    int m;
    string a;
    string b;
    void rec(int i,int j,int idx,string &lcs,string &ans){
        if(idx==lcs.size()){
            for(int k=i;k<a.size();k++){
                ans+=a[k];
            }
            for(int k=j;k<b.size();k++){
                ans+=b[k];
            }
            return;
        }
        if(i==a.size()){
            for(int k=j;k<b.size();k++){
                ans+=b[k];
            }
            return;
        }
        if(j==b.size()){
            for(int k=i;k<a.size();k++){
                ans+=a[k];
            }
            return;
        }
        if(a[i]==lcs[idx] && b[j]==lcs[idx]){
            ans+=a[i];
            rec(i+1,j+1,idx+1,lcs,ans);
        }
        else{
            if(a[i]!=lcs[idx]){
                ans+=a[i];
                rec(i+1,j,idx,lcs,ans);
            }
            else{
                ans+=b[j];
                rec(i,j+1,idx,lcs,ans);
            }
        }
        
    }
    string shortestCommonSupersequence(string str1, string str2) {
        //lcs
        n=str1.size();
        m=str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
            }
        }
        string lcs="";
        int i=n;
        int j=m;
        while(true){
            if(i==0 || j==0)break;
            if(str1[i-1]==str2[j-1]){
                lcs+=str1[i-1];
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1])i--;
                else j--;
            }
        }
        reverse(lcs.begin(),lcs.end());
        string ans="";
        a=str1;
        b=str2;
        rec(0,0,0,lcs,ans);
        return ans;
    }
};