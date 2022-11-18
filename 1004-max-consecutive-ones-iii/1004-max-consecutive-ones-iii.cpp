class Solution {
public:
    int longestOnes(vector<int>& s, int k) {
        int n=s.size();
        int i=0;
        int j=0;
        int rem=k;
        int ans=0;
        set<int>st;
        while(true){
            if(j==n)break;
            if(s[j]==0){
                if(rem){
                    rem--;
                    st.insert(j);
                }
                else{
                    st.insert(j);
                    i=*(st.begin())+1;
                    st.erase(st.begin());
                }
                j++;
            }
            else{
              j++;  
            }
          //  cout<<i<<" "<<j<<endl;
            ans=max(ans,j-i);
        }
        return ans;
    }
};