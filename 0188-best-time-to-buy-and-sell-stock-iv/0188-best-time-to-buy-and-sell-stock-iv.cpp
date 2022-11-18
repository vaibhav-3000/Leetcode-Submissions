class Solution {
public:
         //state
         //transaction 
         //index
    int dp[2][101][1001];
    
    int rec(int i,int j,int k,vector<int>&prices,int total){
        if(j==total)return dp[i][j][k]=0;
        if(k==prices.size()){
            return dp[i][j][k]=0;
        }
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        if(i==0){
            int x=rec(0,j,k+1,prices,total);
            int y=-1*prices[k]+rec(1,j,k+1,prices,total);
            return dp[i][j][k]=max(x,y);
        }
        else{
            int x=rec(1,j,k+1,prices,total);
            int y=prices[k]+rec(0,j+1,k+1,prices,total);
            return dp[i][j][k]=max(x,y);
        }
    }
    
    int maxProfit(int k,vector<int>& prices) {
        for(int i=0;i<2;i++){
            for(int j=0;j<101;j++){
                for(int k=0;k<1001;k++){
                    dp[i][j][k]=-1;
                }
            }
        }
       return rec(0,0,0,prices,k);
    }
};