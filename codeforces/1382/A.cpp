#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e3;
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
int n , m;
int a[maxn] , b[maxn];
int cnt1[maxn] , cnt2[maxn];

int main(){
    migmig
    cin >> q;
    while(q -- ){
        cin >> n >> m;
        for(int i = 0 ; i < n ; i ++)
            cin >> a[i];
        for(int i = 0 ; i < m ; i ++)
            cin >> b[i];
        for(int i = 0 ; i < n ; i ++ )
            cnt1[a[i]]=1;
        for(int j = 0 ; j < m ; j ++)
            cnt2[b[j]] = 1;
        int ans = -1;
        for(int i = 0 ; i < 3e3 ; i ++ )
            if(cnt1[i] and cnt2[i]) ans = i;
        ms(cnt1 , 0 );
        ms(cnt2 , 0);
        if(ans == -1)
            cout << "NO";
        else
            cout << "YES" << endl << 1 << ' ' << ans;
        cout << endl;
    }



    return(0);
}