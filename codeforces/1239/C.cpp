/*
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll  ,ll > pii;

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

ll n , val;

queue < pii > q;
set < ll > inq , ongo;
pii p[maxn];

ll ans[maxn];
ll t[maxn];
bool mark[maxn];

int main(){
    migmig
    cin >> n >> val;
    for(int i = 1; i <= n ; i ++){
        cin >> t[i];
        p[i] = {t[i] , i};
    } 
    sort(p + 1 , p + 1 + n);
    inq.insert(p[1].second);
    mark[p[1].second] = 1;
    q.push(p[1]);
    inq.insert(n+1);
    ll lst = 0 , cur = 1;
    while(!q.empty()){
        pii v = q.front();
        q.pop();
        lst = ans[v.second] = max(v.first , lst) + val;
        while(cur <= n and p[cur].first <= lst){
            if(!mark[p[cur].second] and (*inq.begin()) < p[cur].second)
                ongo.insert(p[cur].second);
            else if(!mark[p[cur].second])
                mark[p[cur].second] = 1,
                inq.insert(p[cur].second),
                q.push({max(p[cur].first , lst) , p[cur].second});
            cur ++;
        }
        inq.erase(inq.find(v.second));
        while(!ongo.empty() and (*ongo.begin()) < (*inq.begin())){
            ll boz = *ongo.begin();
            q.push({max(t[boz] ,lst ) , boz});
            inq.insert(boz);
            mark[boz] = 1;
            ongo.erase(boz);
        }
        if(inq.size() == 1 and cur <= n){
            if(mark[p[cur].second])cur++;
            inq.insert(p[cur].second);
            q.push({max(p[cur].first , lst) , p[cur].second});
            cur++;
        }
    }
    for(int i = 1; i <= n ; i ++)
        cout << ans[i] << ' ';
    return(0);
}