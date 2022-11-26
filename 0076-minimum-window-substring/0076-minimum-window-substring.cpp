class Solution {
public:
    string minWindow(string s, string t) 
    {
        map<char,int>t_map;
        for(auto x:t)
            t_map[x]++;
        int start=0;
        int end=0;
        int n=s.length();
        int res=INT_MAX;
        map<char,int>mp;
        int fstart,fend;
        while(end<n)
        {
            char curr=s[end];
            mp[curr]++;
            bool flag=true;     
            for(auto x:t_map)
            {
                char ch=x.first;
                if(mp[ch]<t_map[ch])
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                int clen=end-start+1;
                if(clen<res)
                { 
                    res=clen;
                    fstart=start;
                    fend=end;
                }
                    mp[s[start]]--;
                    start++;
                    mp[s[end]]--;
            }
            else
            {
                end++;
            }
        }
        if(res==INT_MAX)return "";
        return s.substr(fstart,fend-fstart+1);
    }
};