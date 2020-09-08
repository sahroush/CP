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
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
int n;
int a[maxn];
bool mark[1010];

int32_t main(){
    migmig
    cin >> q;
    while(q --){
        cin >> n;
        ms(mark , 0);
        for(int i = 0 ; i < n ; i ++)
            cin >> a[i];
        int mx = 0;
        pii ps = {0 , 0};
        for(int i = 0 ; i < n ; i ++){
            for(int j = i + 1 ; j < n ; j ++){
                if(__gcd(a[i] , a[j]) > mx)
                    mx = __gcd(a[i] , a[j]),
                    ps = {i , j};
            }
        }
        int gc = mx;
        int bx = 2;
        if(gc < *max_element(a , a + n)){
            gc = *max_element(a , a + n);
            mark[max_element(a , a + n) - a] = 1;
            cout << gc << ' ';
            bx = 1;
        }
        else{
            mark[ps.first] = mark[ps.second] = 1;
            cout << a[ps.first] << ' ' << a[ps.second] << ' ';
        }
        for(int i = bx ; i < n ; i ++){
            int mx = -1;
            for(int j = 0 ; j < n ; j ++){
                if(mark[j])
                    continue;
                if(mx == -1)
                    mx = j;
                if(__gcd(a[mx] , gc) < __gcd(a[j] , gc))
                    mx = j;
            }
            cout << a[mx] << ' ';
            mark[mx] = 1;
            gc = __gcd(a[mx] , gc);
        }
        cout << endl;
    }




    return(0);
}