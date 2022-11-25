class Solution {
public:
    int mod=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n,0);
        vector<int>firstMin(n,-1);
        stack<int>st;
        st.push(-1);
        //index of first minimum
        for(int i=0;i<n;i++){
            while(true){
                int f=st.top();
                if(f==-1){
                    firstMin[i]=-1;
                    st.push(i);
                    break;
                }
                else if(arr[f]>arr[i]){
                    st.pop();
                }
                else{
                    firstMin[i]=f;
                    st.push(i);
                    break;
                }
            }
        }
        // for(auto e:firstMin){
        //     cout<<e<<" ";
        // }cout<<endl;
        for(int i=0;i<n;i++){
            if(firstMin[i]==-1){
                dp[i]+=(arr[i]*(i+1))%mod;
                dp[i]%=mod;
            }
            else{
                dp[i]+=(dp[firstMin[i]]+((i-firstMin[i])*arr[i])%mod)%mod;
                dp[i]%=mod;
            }
        }
        int ans=0;
        for(auto e:dp){
            //cout<<e<<" ";
            ans+=e;
            ans%=mod;
        }//cout<<endl;
        return ans;
        
        
        
        
    }
};