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


int q;
int n , k ;
ll a[maxn];

int32_t main(){
    migmig
    cin >> q;
    while(q -- ){
        cin >> n >> k;
        for(int i = 0 ; i < n ; i ++)
            cin >> a[i];
        sort(a , a + n);
        for(int i = n - 2 ; i >= 0 ; i --){
            if(k){
                k -- ;
                a[n-1] += a[i];
                a[i] = 0;
            }
        }
        sort(a , a + n);
        cout << a[n -1 ] - a[0] << endl;
    }




    return(0);
}