/*
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int q;
vector < int > points;
vector < pii > segs;
int ans[maxn] , ghat[maxn];
set < int > st;
set < pii > res;

int32_t main(){
    migmig
    cin >> q;
    while(q -- ){
        points.clear();
        segs.clear();
        st.clear();
        res.clear();
        cin >> n;
        for(int i = 1 ; i <= n; i ++){
            int l , r;
            cin >> l >> r;
            points.pb(l) , points.pb(r);
            segs.pb({l , r});
        }
        sort(segs.begin() , segs.end());
        sort(points.begin() , points.end());
        points.resize(unique(points.begin() , points.end()) - points.begin());
        for(auto &[l , r] : segs)
            l = lower_bound(points.begin() , points.end() , l) - points.begin(),
            r = lower_bound(points.begin() , points.end() , r) - points.begin();
        int cnt = 0;
        int i = 0;
        while(i < n){
            while(st.size() and *st.begin() < segs[i].first)
                st.erase(*st.begin());
            if(st.empty())
                cnt++;
            int cur = segs[i].first;
            while(i < n and segs[i].first == cur )
                st.insert(segs[i].second) , i++;
        }
        st.clear();
        i = 0;
        while(i < n){
            while(res.size() and (*res.begin()).first < segs[i].first)
                st.erase((*res.begin()).second),
                res.erase(*res.begin());
            if(res.size() == 1 and ghat[(*res.begin()).second])
                ans[(*res.begin()).second]++;
            int cur = segs[i].first;
            while(i < n and segs[i].first == cur){
                if(res.empty())
                    st.insert(i);
                else{
                    while(st.size())
                        ghat[*st.begin()] = 1,
                        st.erase(*st.begin());
                    ghat[i] = 1;
                }
                res.insert({segs[i].second , i});
                i++;
            }
        }
        int mx = 0;
        for(int i = 0 ; i < n ; i ++)
            if(ghat[i])
                mx = max(mx , cnt + ans[i]) , ghat[i] = 0 , ans[i]=0;
            else
                mx = max(mx , cnt - 1);
        cout << mx << endl;
    }
    return(0);
}