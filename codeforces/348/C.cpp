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

const ll maxn  = 1e5 + 10;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

struct com{
    int sz;
    int ind = -1;
    vector < int > st;
}comp[maxn];

int n , m ,q;
const int sq = 320;
int cnt = 1;
ll a[maxn];
vector < int > pos[maxn];
ll sum[sq] , delta[sq];
int sct[sq][maxn];

void prep(){
    for(int i = 1 ; i <= m ; i ++)
        if(comp[i].ind>0){
            for(auto x : comp[i].st)
                for(auto y : pos[x])
                    sct[comp[i].ind][y]++;
            comp[i].st.clear(); //shayad mle nashe :/
        }
}

void Add(int k , ll x){
    delta[comp[k].ind]+=x;
    for(int i = 1;  i < cnt ; i ++){
        sum[i] += x * (ll)sct[i][k];
    }
}
void add(int k , ll x){
    for(auto i : comp[k].st)
        a[i]+=x;
    for(int i = 1;  i < cnt ; i ++){
        sum[i] += x * (ll)sct[i][k];
    }
}
void Query(int k){
    cout <<  sum[comp[k].ind] << endl;
}
void query(int k){
    ll sum = 0;
    for(auto i : comp[k].st)
        sum+=a[i];
    for(int i = 1;  i < cnt ; i ++){
        sum += delta[i] * (ll)sct[i][k];
    }
    cout << sum << endl;
}

int main(){
    migmig
    cin >> n >> m >> q;
    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i];
    for(int i = 1; i <= m ; i ++){
        cin >> comp[i].sz;
        if(comp[i].sz > sq){
            comp[i].ind = cnt;
            for(int j = 0 ; j < comp[i].sz ; j ++){
                int x;
                cin >> x;
                comp[i].st.pb(x);
                sum[cnt]+=a[x];
                pos[x].pb(i);
            }
            cnt++;
        }
        else{
            for(int j = 0 ; j < comp[i].sz ; j ++){
                int x;
                cin >> x;
                comp[i].st.pb(x);
                pos[x].pb(i);
            }
        }
    }
    prep();
    while(q -- ){
        string s;
        cin >> s;
        if(s == "?"){
            int k;
            cin >> k;
            if(comp[k].sz > sq){
                Query(k);
            }
            else{
                query(k);
            }
        }
        else{
            int k;
            ll x;
            cin >> k >> x;
            if(comp[k].sz > sq){
                Add(k , x);
            }
            else{
                add(k , x);
            }
        }
    }
    return(0);
}