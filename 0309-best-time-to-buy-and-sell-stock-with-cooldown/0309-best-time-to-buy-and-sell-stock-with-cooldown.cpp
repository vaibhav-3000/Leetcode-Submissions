class Solution {
public:
    //0: buy
    //1: sell/hold
    int dp[2][5001];
    int rec(int i,int state,vector<int>&prices){
        if(i>=prices.size())return dp[state][i]=0;
        if(dp[state][i]!=-1)return dp[state][i];
        if(state==0){
            int x=rec(i+1,state,prices);
            int y=-1*prices[i]+rec(i+1,1,prices);
            return dp[state][i]=max(x,y);
        }
        else{
            int x=rec(i+1,state,prices);
            int y=prices[i]+rec(i+2,0,prices);
            return dp[state][i]=max(x,y);
        }
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return rec(0,0,prices);
    }
};