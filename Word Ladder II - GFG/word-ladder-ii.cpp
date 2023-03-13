//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
vector<string>find(string &last,unordered_set<string>&st){
        vector<string>result;
        for(char c='a';c<='z';c++){
            int n=last.size();
            for(int i=0;i<n;i++){
                string temp=last;
                temp[i]=c;
                if(st.find(temp)!=st.end())result.push_back(temp);
            }
        }
        return result;
    }
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>>ans;
        vector<string>used;
        unordered_set<string> st(wordList.begin(),wordList.end());
        used.push_back(beginWord);
        queue<vector<string>>q;
        q.push({beginWord});
        int level=0;
        int mnLevel=INT_MAX;
        while(!q.empty()){
            auto f=q.front();
            q.pop();
            if(f.size()>level){
                level++;
                for(auto e:used)st.erase(e);
                used.clear();
            }
            int n=f.size();
            string last=f[n-1];
            if(last==endWord && n<=mnLevel){
                ans.push_back(f);
                mnLevel=level;
            }
            vector<string>nhbr=find(last,st);
            for(auto e:nhbr){
                f.push_back(e);
                q.push(f);
                f.pop_back();
                used.push_back(e);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends