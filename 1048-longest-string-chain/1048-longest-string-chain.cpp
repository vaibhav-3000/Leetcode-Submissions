
class Solution {
public:
   static bool comp(string &a,string &b){ 
       return a.size()<b.size();
    }
    bool isPossible(string &a,string &b){
        int c=0;
        int n1=a.size();
        int n2=b.size();
        int i=0;
        int j=0;
        while(i<n1 && j<n2){
            if(a[i]!=b[j]){
                c++;
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        if(i==n1 && j==n2 && c==1)return true;
        if(i==n1 && j==n2-1)return true;
        return false;
    }
    
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),comp);
       // for(auto e:words)cout<<e<<" ";cout<<endl;
        vector<int>dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(isPossible(words[j],words[i])){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
      //  for(auto e:dp)cout<<e<<" ";cout<<endl;
        return *max_element(dp.begin(),dp.end());
    }
};