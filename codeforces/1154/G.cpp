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

const ll maxn  = 1e7+100;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int a[maxn] , mn[maxn][2];
int mrt[maxn][2];
int n;
pii ans;
ll val = 8e18;

int main(){
    migmig
    cin >> n;
    for(int i = 0 ; i < n ; i ++){
        cin >> a[i];
        if(mn[a[i]][0] == 0)
            mn[a[i]][0]=i+1;
        else if(mn[a[i]][1] == 0)
            mn[a[i]][1]=i+1;
    }
    for(int i = 1 ; i <= 1e7 ; i ++){
        for(int j = i ; j <= 1e7 ; j += i){
            if(!mn[j][0]){
                continue;}
            if(!mrt[i][0]){
                mrt[i][0] = j/i;}
            else if(!mrt[i][1]){
                mrt[i][1] = j/i;}
            if(mn[j][1]){
                mrt[i][1] = j/i;}
            if(mrt[i][1] and mrt[i][0]){
                break;}
        }
        if(mrt[i][1] and mrt[i][0]){
            if(ll(i)*ll(mrt[i][1])*ll(mrt[i][0])<val){
                val = ll(i)*ll(mrt[i][1])*ll(mrt[i][0]);
                ans = {mn[mrt[i][0]*i][0] , mn[mrt[i][1]*i][mrt[i][0] == mrt[i][1]]};
            }
        }
    }
    if(ans.first > ans.second)
        swap(ans.first , ans.second);
    cout << ans.first << ' ' << ans.second;
    return(0);
}