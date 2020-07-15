#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 800;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m;
ll a[maxn];
ll mn[maxn];
priority_queue < ll > pq;

ll chk(ll x){
    ll ans = 0;
    while(pq.size())pq.pop();
    for(int i = 0 ; i < n;  i++){
        x += a[i];
        if(a[i] < 0){
            pq.push(-a[i]);
        }
        if(x < 0){
            x+=pq.top();
            pq.pop();
            ans++;
        }
    }
    return(ans);
}

int main(){
    migmig
    cin >> n >> m;
    for(int i = 0 ; i < n ; i ++)
        cin >> a[i];
    for(int i = 0 ; i <= n ; i ++){
        ll l = -1 , r = 1e15+100;
        while(r - l > 1){
            ll mid = (r + l)/2;
            if(chk(mid) <= i){
                r = mid;
            }
            else
                l = mid;
        }
        mn[i] = r;
    }
    while(m--){
        ll q;
        cin >> q;
        ll l = -1 , r = n;
        while(r - l > 1){
            ll mid = (l + r)/2;
            if(mn[mid] > q)
                l = mid;
            else
                r = mid;
        }
        cout << r << endl;
    }
    return(0);
}
