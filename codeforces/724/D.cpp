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

int m;
string s;
int cnt[27];
int mx = 0;

int32_t main(){
    migmig
    cin >> m;
    cin >> s;
    s = "F" + s;
    int n = s.size();
    n--;
    for(int i = 1 ; i <= n ; i ++){
        cnt[s[i] - 'a']++;
        if(i >= m){if(i > m)cnt[s[i - m] - 'a'] --;
        for(int j = 0 ; j < 26 ; j ++)
            if(cnt[j]){mx = max(mx , j) ;break;}}
    }
    string ans = "";
    for(int i = 1 ; i <= n ; i ++){
        if(s[i] - 'a' < mx)
            ans += s[i];
    }
    int cur = 0;
    int cnt = 0;
    for(int i = 1 ; i <= n ; i ++){
        cnt ++ ;
        if(s[i] - 'a' < mx)cnt = 0;
        if(s[i] - 'a' == mx){
            cur = i;
        }
        if(cnt == m){
            ans += char('a' + mx);
            cnt = i - cur;
        }
    }

    sort(ans.begin() , ans.end());
    cout << ans;
    return(0);
}