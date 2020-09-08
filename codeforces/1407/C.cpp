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
//#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int p[maxn];
set < int > st;

int ask(int x, int y){ 
    cout << "? "<< x << ' ' << y << endl;
    int ans;
    cin >> ans;
    return(ans);
}
bool mark[maxn];

int32_t main(){
    migmig
    cin >> n;
    if(n == 1){
        dokme("! 1"); 
    }
    for(int i = 1 ; i <= n ; i ++)
        st.insert(i);
    while(st.size() > 1){
        int a = *st.begin();
        st.erase(a);
        int b = *st.begin();
        st.insert(a);
        int x = ask(a , b);
        int y = ask(b , a);
        if(x > y){
            p[a] = x;
            mark[x] = 1;
            st.erase(a);
        }
        else{
            p[b] = y;
            mark[y] = 1;
            st.erase(b);
        }
    }
    int pos =  *st.begin();
    for(int i = 1 ; i <= n ; i ++)
        if(mark[i] == 0)
            p[pos] = i;
    cout << "! ";
    for(int i = 1 ; i <= n ; i ++)
        cout << p[i] << ' ';


    return(0);
}