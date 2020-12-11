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

const ll maxn  = 3000+20;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
int n;
int a[maxn];
vector < pii > vec;
int fen[maxn];

bool cmp(pii i , pii j){
    return(i.second < j.second);
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
    cin >> q;
    while(q -- ){
        ms(fen , 0);
        vec.clear();
        cin >> n;
        for(int i = 1 ; i <= n ; i ++)
            cin >> a[i];
        for(int i = 1 ; i <= n ; i ++)
            for(int j = i + 1 ; j <= n ; j ++)
                if(a[i] == a[j])
                    vec.pb({i , j});
        sort(vec.begin() , vec.end() , cmp);
        int p1 = 0 , p2 = 0;
        vec.pb({1e5 , 1e5});
        ll ans = 0;
        while(p2!=int(vec.size()) - 1){
            int l = vec[p1].first, r = vec[p1].second;
            int L = vec[p2].first , R = vec[p2].second;
            if(r > R){
                ans -= get(L+1 , R-1);
                p2++;
            }
            else{
                add(l);
                p1++;
            }
        }
        for(auto [l , r] : vec){
            if(l == 1e5)break;
            ans += get(l+1 , r-1);}
        cout << ans << endl;
    }




    return(0);
}