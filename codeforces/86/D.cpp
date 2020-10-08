/*
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
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

int n , q;
int a[maxn];
pii qu[maxn];
int srt[maxn];
int sq = 450;
int ans[maxn];
int cnt[maxn];


bool cmp(int i , int j){
    pii a = qu[i] , b = qu[j];
    if(a.first / sq != b.first / sq) return(a.first / sq < b.first / sq);
    return(a.second > b.second);
}

int32_t main(){
    migmig
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i ++)  
        cin >> a[i];
    for(int i = 0 ; i < q ; i ++)
        cin >> qu[i].first >> qu[i].second , srt[i] = i;
    sort(srt , srt + q , cmp);
    int l = 1 , r = 1;
    cnt[a[1]] ++;
    int cur = a[1];
    for(int i = 0 ; i < q ; i ++ ){
        while(l < qu[srt[i]].first){
            cur -= cnt[a[l]] * cnt[a[l]] * a[l];
            cnt[a[l]] --;
            cur += cnt[a[l]] * cnt[a[l]] * a[l];
            l ++;
        }
        while(r < qu[srt[i]].second){
            r++;
            cur -= cnt[a[r]] * cnt[a[r]] * a[r];
            cnt[a[r]] ++;
            cur += cnt[a[r]] * cnt[a[r]] * a[r];
        }
        while(l > qu[srt[i]].first){
            l --;
            cur -= cnt[a[l]] * cnt[a[l]] * a[l];
            cnt[a[l]] ++;
            cur += cnt[a[l]] * cnt[a[l]] * a[l];
        }
        while(r > qu[srt[i]].second){
            cur -= cnt[a[r]] * cnt[a[r]] * a[r];
            cnt[a[r]] --;
            cur += cnt[a[r]] * cnt[a[r]] * a[r];
            r --;
        }
        ans[srt[i]] = cur;
    }
    for(int i = 0 ; i < q ; i ++) cout << ans[i] << endl;
    return(0);
}