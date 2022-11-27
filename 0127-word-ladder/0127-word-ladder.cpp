class Solution {
public:
    int ladderLength(string strt, string en, vector<string>& wordList) {
        unordered_set<string>st;
        for(auto e:wordList)st.insert(e);
        queue<pair<string,int>>q;//word level;
        q.push({strt,1});
        unordered_map<string,int>mp;
        mp[strt]=1;
        while(!q.empty()){
            auto f=q.front();
            q.pop();
            string s=f.first;
            int level=f.second;
            if(s==en)return level;
            for(int i=0;i<s.size();i++){
                string cpy=s;
                for(char c='a';c<='z';c++){
                    cpy[i]=c;
                    if(st.find(cpy)!=st.end()){
                        if(!mp[cpy]){
                            q.push({cpy,level+1});
                            mp[cpy]=1;
                        }
                    }
                }
                
            }
        }
        return 0;
    }
};