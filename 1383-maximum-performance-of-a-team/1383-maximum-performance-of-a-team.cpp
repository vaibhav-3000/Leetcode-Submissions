#define ll long long
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        multiset<ll>mst;
        vector<pair<ll,ll>>vp;
        for(int i=0;i<n;i++){
            vp.push_back({efficiency[i],speed[i]});
        }
        sort(vp.begin(),vp.end());
       // for(auto e:vp)cout<<e.first<<" "<<e.second<<endl;
        ll totalSpeed=0;
        ll ans=0;
        for(int i=n-1;i>=0;i--){
            if(mst.size()==k){
                ll mn=*mst.begin();
                totalSpeed-=(mn);
                mst.erase(mst.begin());
                mn=max(mn,vp[i].second);
                totalSpeed+=mn;
                mst.insert(mn);
                //cout<<totalSpeed<<" "<<totalSpeed*(vp[i].first)<<endl;
                ans=max(ans,totalSpeed*(vp[i].first));
            }
            else{
                totalSpeed+=vp[i].second;
                mst.insert(vp[i].second);
                //cout<<totalSpeed*vp[i].first<<endl;
                ans=max(ans,totalSpeed*vp[i].first);
            }
        }
        return ans%1000000007;
        
    }
};