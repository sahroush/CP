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
#define dokme(x) cout << x , exit(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
int n;
string s;
vector < int > vec;
int dp[maxn];
set < int > st , s1 , s2;

int32_t main(){
    migmig
    cin >> q;
    while(q -- ){
        cin >> n;
        vec.clear();
        cin >> s;
        for(int i = 0 ; i <= n+10 ; i ++)   dp[i] = 0;
        int cur = (s[0] - '0');
        int cnt = 1;
        for(int i = 1 ; i < n ; i ++){
            if(s[i] - '0' == cur){
                cnt ++;
            }
            else
                vec.pb(cnt) , cur = 1 - cur , cnt = 1;
        }
        if(cnt)vec.pb(cnt);
        s1.clear();
        s2.clear();
        st.clear();
        int ans = 0;
        for(int i = 0 ; i < vec.size() ; i ++ ){
            if(vec[i] == 1)
                s1.insert(i);
            else
                s2.insert(i);
            st.insert(i);
        }
        while(st.size()){
            if(s2.size()){
                ans ++;
                auto x = *s2.begin();
                vec[x] --;
                if(vec[x] == 1)
                    s2.erase(x) , s1.insert(x);
            }
            else{
                ans ++;
                auto x = *s1.rbegin();
                s1.erase(x);
                st.erase(x);
            }
            if(st.size()){
                auto x = *st.begin();
                st.erase(x);
                if(s1.count(x))
                    s1.erase(x);
                if(s2.count(x))
                    s2.erase(x);
            }
        }
        cout << ans << endl;
    }




    return(0);
}