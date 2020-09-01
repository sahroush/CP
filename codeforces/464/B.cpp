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

#define int ll
#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int a[8][3];

ll dist(int i ,int j){
    ll sum = 0;
    for(int k = 0 ; k < 3 ; k ++)
        sum += (a[i][k] - a[j][k]) * (a[i][k] - a[j][k]);
    return(sum);
}

bool check(){
    ll zel = 5e18;
    for(int i = 0 ; i < 8 ; i ++)
        for(int j = i + 1; j < 8 ; j ++)
            zel = min(zel , dist(i , j));
    int cnt[3] = {0 , 0 , 0};
    for(int i = 0 ; i < 8 ; i ++)
        for(int j = i + 1 ; j < 8 ; j ++){
            ll d = dist(i , j);
            if(d == zel)
                cnt[0]++;
            else if(d == zel*2)
                cnt[1]++;
            else if(d == zel*3)
                cnt[2] ++;
            else 
                return(0);
            
        }
    if(cnt[0]!= cnt[1])
        return(0);
    if(cnt[0]!=12)
        return(0);
    if(cnt[2]!=4)
        return(0);
    return(1);
}

int solve(int i = 0){
    if(i == 7)
        return(check());
    int res = 1;
    while(res){
        if(solve(i + 1))
            return(1);
        res = next_permutation(a[i] , a[i] + 3);
    }
    return(0);
}

int32_t main(){
    migmig
    for(int i = 0 ; i  < 8 ; i ++)
        for(int j = 0 ; j < 3 ; j ++)
            cin >> a[i][j];
    for(int i = 0 ; i < 8 ; i ++)
        sort(a[i] , a[i] + 3);
    int res = solve();
    if(res == 0)
        dokme("NO");
    cout << "YES" << endl;
    for(int i = 0 ; i  < 8 ; i ++){
        for(int j = 0 ; j < 3 ; j ++)
            cout <<  a[i][j] << ' ';
        cout << endl;
    }
    return(0);
}