class Solution {
public:
    int n;
    int m;
    int HistogramArea(vector<int>&a){
        //leftMin
        stack<int>st;
        vector<int>left(m+1,-1);
        for(int i=1;i<=m;i++){
            int idx=0;
            while(!st.empty()){
                int f=st.top();
                if(a[f]<a[i]){
                    idx=f;
                    break;
                }
                else{
                    st.pop();
                }
            }
            
            left[i]=idx;
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        vector<int>right(m+1,-1);
        for(int i=m;i>=1;i--){
            int idx=m+1;
            while(!st.empty()){
                int f=st.top();
                if(a[f]<a[i]){
                    idx=f;
                    break;
                }
                else{
                    st.pop();
                }
            }
            right[i]=idx;
            st.push(i);
        }
        int ans=0;
        for(int i=1;i<=m;i++){
            ans=max(ans,(right[i]-left[i]-1)*a[i]);
        }
        return ans;
        
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        vector<vector<int>>arr(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                matrix[i][j]=='1'?arr[i+1][j+1]=1:arr[i+1][j+1]=0;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(arr[i][j]){
                    arr[i][j]+=arr[i-1][j];
                }
            }
            ans=max(ans,HistogramArea(arr[i]));
        }
        return ans;
        
    }
};