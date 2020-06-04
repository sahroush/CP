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

int n;
int a[maxn];

int main(){
    migmig
    cin >> n;
    for(int i = 0 ; i < n ; i ++)
        cin >> a[i];
    sort(a , a + n);
    swap(a[n - 1] , a[n - 2]);
    for(int i = 0 ; i < n ; i ++){
        int prev = (i - 1 + n)%n;
        int nxt = (i + 1)%n;
        if(a[i] >= a[prev] + a[nxt])dokme("NO");
    }
    cout << "YES" << endl;
    for(int i = 0 ; i < n ; i ++)
        cout << a[i] << ' ';




    return(0);
}