class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        map<char,int>mp;
        map<char,int>temp;
        for(auto e:t)mp[e]++;
        int i=0;
        int ans=INT_MAX;
        int st,en;
        for(int j=0;j<n;){
            temp[s[j]]++;
            int f=1;
            for(auto e:mp){
                if(temp[e.first]<e.second){
                    f=0;break;
                }
            }
            if(f){
               // cout<<i<<" "<<j<<endl;
                //for(auto e:temp)cout<<e.first<<" "<<e.second<<"::";cout<<endl;
                if(j-i+1<ans){
                    ans=j-i+1;
                    st=i;
                    en=j;
                }
                temp[s[i]]--;
                temp[s[j]]--;
                i++;
            }
            else{
                j++;
            }
        }
     //   cout<<ans<<endl;
        if(ans==INT_MAX)return "";
        return s.substr(st,en-st+1);
    }
};