class Solution {
public:
    //0 buy
    //1 sell or hold
    
    int n;
    int dp[2][100001];
    int rec(int i,int state,vector<int>&prices){
        if(i==n){
            return dp[state][i]=0;
             
        }
        
        if(dp[state][i]!=-1)return dp[state][i];
    
        if(state==0){
            int x=-1*prices[i]+rec(i+1,1,prices);
            int y=rec(i+1,0,prices);
            return dp[state][i]=max(x,y);
        }
        else{
            int x=prices[i]+rec(i+1,0,prices);
            int y=rec(i+1,1,prices);
            return dp[state][i]=max(x,y);
        }
        
    
    }
    int maxProfit(vector<int>& prices) {
        for(int i=0;i<2;i++){
            for(int j=0;j<100000;j++){
                dp[i][j]=-1;
            }
        }
        n=prices.size();
        return rec(0,0,prices);
        
    }
};