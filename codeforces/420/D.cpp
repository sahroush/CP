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

const ll maxn  = 3e6+10;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int ans[maxn] , mark[maxn];
int cnt = 2e6;
int n , m;

struct Tree {
    int sz = 0, bit[maxn];

    int size() {
        return sz;
    }

    void update(int k, int x) {
        while (k < maxn) {
            bit[k] += x;
            k += k & -k;
        }
        sz += x;
    }

    int find_by_order(int k) {
        int ans = 0, sum = 0;
        for (int j = 30; j >= 0; --j) {
            ans += 1 << j;
            if (ans < maxn && sum + bit[ans] < k) {
                sum += bit[ans];
            } else {
                ans -= 1 << j;
            }
        }
        return ans + 1;
    }

    int order_of_key(int k) {
        k++;
        int ans = 0;
        while (k >= 1) {
            ans += bit[k];
            k -= k & -k;
        }
        return ans - 1;
    }
}pbds;

int main(){
    migmig
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++)
        pbds.update(i+2e6, 1);
    while(m --){
        int x , pos;
        cin >> x >> pos;
        int i = pbds.find_by_order(pos);
        if(i > 2e6){
            if(mark[x])
                dokme(-1);
            ans[i] = x;
            mark[x] = 1;
            pbds.update(i , -1);
            pbds.update(cnt , 1);
            ans[cnt] = x;
            cnt --;
        }
        else{
            if(ans[i]!=x)
                dokme(-1);
            pbds.update(i , -1);
            pbds.update(cnt , 1);
            ans[cnt] = x;
            cnt --;
        }
    }
    cnt = 1;
    for(int i = 1 ; i <= n;  i ++){
        if(ans[i+2000000]){
            cout << ans[i+2000000] << ' ';continue;}
        while(mark[cnt])cnt++;
        cout << cnt << ' ';
        cnt++;
    }
    
    return(0);
}