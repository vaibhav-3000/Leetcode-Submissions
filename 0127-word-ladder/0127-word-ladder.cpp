class Solution {
public:
    map<string,list<string>> graph;
    bool cmp(string &s,string &t)
    {
        int n=s.length();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=t[i])
                cnt++;
        }
        return cnt==1 ? true : false;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {   wordList.push_back(beginWord);
        int n=wordList.size();
        for(int i=0;i<n;i++)
        {
            string par=wordList[i];
            for(int j=i+1;j<n;j++)
            {
                string child=wordList[j];
                bool ok=cmp(par,child);
                if(ok)
                {
                    graph[par].push_back(child);
                    graph[child].push_back(par);
                }
            }
        }
        // for(auto e:graph){
        //     cout<<e.first<<"::";
        //     for(auto it:e.second)cout<<it<<" ";cout<<endl;
        // }
        map<string,int>dis;
        dis[beginWord]=1;
        queue<string>q;
        q.push(beginWord);
        while(!q.empty())
        {
            auto f=q.front();
            q.pop();
            //cout<<f<<" "<<dis[f]<<endl;
            for(auto nbrs:graph[f])
            {  
                if(!dis.count(nbrs))
                { 
                    dis[nbrs]=1+dis[f];
                    q.push(nbrs);
                }
            }
        }
        return dis[endWord];
    }
};