class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>a,b,c;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='a')a.push_back(i);
            if(s[i]=='b')b.push_back(i);
            if(s[i]=='c')c.push_back(i);
        }
        if(a.size()==0 || b.size()==0 || c.size()==0)return 0;
        int i=0,j=0,k=0;
        int x=a.size();
        int y=b.size();
        int z=c.size();
        int ans=0;
        while(i<x && j<y && k<z){
            int idxA=a[i];
            int idxB=b[j];
            int idxC=c[k];
            int mn=min({idxA,idxB,idxC});
            int mx=max({idxA,idxB,idxC});
            //cout<<idxA<<" "<<idxB<<" "<<idxC<<endl;
            //cout<<n<<" "<<mx<<endl;
            ans+=n-mx;
            //cout<<"ans:"<<ans<<endl;
            if(mn==idxA){
                i++;
            }
            else if(mn==idxB){
                j++;
            }
            else{
                k++;
            }
            
        }
        return ans;
        
    }
};