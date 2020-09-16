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

map < int , int > mp;
int n;
set < pii > st;


int32_t main(){
    migmig
    cin >> n;
    for(int i = 0 ; i < n ; i ++){
        int x;
        cin >> x;
        mp[x]++;
    }
    for(auto [f , s] : mp)
        st.insert({s , f});
    pii ans = {0 , 0};
    int mx = 0;
    int cnt = 0;
    for(int i = 1 ; i * i <= n ; i ++){
        cnt+=st.size();
        while(st.size() and (*st.begin()).first == i)
            st.erase(*st.begin());
        if(i > cnt/i) continue;
        if(i * (cnt/i) > mx)
            mx = i * (cnt/i),
            ans = {i , cnt/i};
    }
    cout << mx << endl;
    cout << ans.first << ' ' << ans.second << endl;
    st.clear();
    for(auto [f , s] : mp){
        if(mx == 0)break;
        st.insert({min(min(s , mx) , ans.first) , f}),
        mx -= min(min(s , mx) , ans.first);
    }
    mp.clear();
    int x = 0 , y = 0;
    while(st.size()){
            auto [s , f] = *st.rbegin();
            st.erase({s , f});
            while(s--){
                mp[x*ans.second + y] = f;
                x++ , y++;
                x%= ans.first, y%=ans.second;
                if(mp[x*ans.second + y])x++;
            }
    }
    for(int i = 0 ; i < ans.first * ans.second ; i ++){
        cout << mp[i] << ' ';
        if((i+1)%(ans.second) == 0)
            cout << endl;
    }
    return(0);
}