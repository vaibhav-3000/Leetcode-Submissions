class Solution {
public:
    vector<int> prices;
    int fee;
    
    //0:buy
    //1:sell/hold
    //sell to buy = -fee
    int dp[2][50001];
    int rec(int i,int state){
        if(i==prices.size())return dp[state][i]=0;
        if(dp[state][i]!=-1)return dp[state][i];
        if(state==0){
            int x=rec(i+1,0);
            int y=-1*prices[i]+rec(i+1,1);
            return dp[state][i]=max(x,y);
        }
        else{
            int x=rec(i+1,1);
            int y=prices[i]+rec(i+1,0)-fee;
            return dp[state][i]=max(x,y);
        }
    }
    int maxProfit(vector<int>& p, int f) {
        prices=p;
        fee=f;
        memset(dp,-1,sizeof(dp));
        return rec(0,0);
        
    }
};