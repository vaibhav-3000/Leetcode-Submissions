class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        multiset<int>st;
        stations.push_back({target,0});
        int n=stations.size();
        long long fuel=startFuel;
        int ans=0;
        for(int i=0;i<n;){
            int pos=stations[i][0];
            int f=stations[i][1];
            if(pos<=fuel){
                i++;
                st.insert(f);
            }
            else{
                if(st.size()==0)return-1;
                fuel+=(*(--st.end()));
                st.erase(--st.end());
                ans++;
            }
        }
        return ans;
    }
};