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
#define int ll

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
int a[maxn];
int srt[maxn];
ll ans = 0;
int fen[maxn] , fen2[maxn];

bool cmp(int i , int j){
    return(a[i] < a[j]);
}
void add(int pos){
    for(;pos<maxn;pos+=pos&(-pos))
        fen[pos]++;
}
void add(int pos ,int x){
    for(;pos<maxn;pos+=pos&(-pos))
        fen2[pos]+=x;
}
int get(int pos){
    int ans = 0;
    for(;pos;pos-=pos&(-pos))
        ans+=fen[pos];
    return(ans);
}
int get2(int pos){
    int ans = 0;
    for(;pos;pos-=pos&(-pos))
        ans+=fen2[pos];
    return(ans);
}

int32_t main(){
    migmig
    cin  >> n;
    for(int i = 1; i <= n ; i ++){
        cin >> a[i];srt[i] = i;}
    sort(srt + 1 , srt + n + 1 , cmp);
    for(int i = 1 ; i <= n ; i ++)
        a[srt[i]] = i;
    for(int i = n ; i > 0 ; i --){
        int x = get(a[i]);
        add(a[i]);
        ans += get2(a[i]);
        add(a[i] , x);
    }
    cout << ans;
    return(0);
}