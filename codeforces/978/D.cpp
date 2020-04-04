#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;//AmShZ
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md = mod) {
    ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);
}

int mn = 1e9;
int n;
ll a[maxn];
ll b[maxn];

int solve(int x , int y){
    int ans = 0;
    if(x!=0){
        ans++;
    }
    if(y!=0){
        ans++;
    }
    a[0]+=x;
    a[1]+=y;
    ll jump = a[1]-a[0];
    for(ll i = 0 ; i < n ; i ++){
        if(a[i]!=a[0]+i*jump){
            if(abs(a[i] - (a[0]+i*jump)) > 1){
                return(1e9);
            }
            ans++;
        }
    }
    return(ans);
}

int main(){
    migmig
    cin >> n;
    if(n <=2){
        dokme(0);
    }
    for(int i =0 ; i < n ; i ++){
        cin >> a[i];
        b[i] = a[i];
    }
    int d[] = {-1 , 0 , 1};
    for(int i = 0 ; i < 3 ; i ++){
        for(int j = 0 ; j < 3 ; j ++){
            mn = min(mn , solve(d[i] , d[j]));
            for(int i = 0;  i < n; i ++){
                a[i] = b[i];
            }
        }
    }
    if(mn == 1e9){
        dokme(-1)
    }
    cout << mn;
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
