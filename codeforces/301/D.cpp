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

const ll maxn  = 3e5;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}


int n , q;
vector < pii > vec;
int pos[maxn];
int a[maxn];
int ans[maxn];
int fen[maxn];
vector < pair < pii , int > > qu; 

bool cmp(pii i , pii j){
    return (i.second < j.second);
}
bool cmp2(pair < pii , int > i , pair < pii , int > j){
    return (i.first.second < j.first.second);
}

void add(int pos){
    for(;pos < maxn ; pos+=pos&(-pos))
        fen[pos]++;
}

int get(int pos){
    int sum = 0;
    for(;pos;pos-=pos&(-pos))
        sum += fen[pos];
    return(sum);
}

int get (int l , int r){
    return (get(r) - get(l-1));
}
int main(){
    migmig
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i ++){
        cin >> a[i];pos[a[i]] = i;}
    for(int i = 1 ; i <= n ; i ++)
        for(int j = i ; j <= n ;j += i)
            vec.pb(((pos[i] < pos[j])?pii(pos[i] , pos[j]) : pii(pos[j] , pos[i])));
    vec.pb({2e5+10 , 2e5+10});
    sort(vec.begin() , vec.end() , cmp);
    for(int i = 0 ; i < q ; i ++){
        int l , r;
        cin >> l >> r;
        qu.pb({{l , r} , i});
    }
    sort(qu.begin() , qu.end() , cmp2);
    int p1 = 0 , p2 = 0;
    while(p2!=qu.size()){
        int l = vec[p1].first, r = vec[p1].second;
        int L = qu[p2].first.first , R = qu[p2].first.second;
        int ind = qu[p2].second;
        if(r > R){
            ans[ind] = get(L , R);
            p2++;
        }
        else{
            add(l);
            p1++;
        }
    }
    for(int i = 0 ; i < q; i ++) cout << ans[i] << endl;
    return(0);
}