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
    ll res = 1;while(b){if(b&1){res=(a*res)%mod;}a=(a*a)%mod;b>>=1;}return(res);
}

int n;
int a[maxn] , b[maxn] , c[maxn];

int main(){
    migmig
    cin >> n;
    for(int i = 2; i <= 2*n ; i ++){
        for(int j = 1; j < i ; j ++){
            int inp;
            cin >> inp;
            a[inp] = i;
            b[inp] = j;
        }
    }
    for(int i = maxn-2 ; i >= 0 ; i -- ){
        if(a[i] and !c[a[i]] and !c[b[i]]){
            c[a[i]] = b[i];
            c[b[i]] = a[i];
        }
    }
    for(int  i =1 ; i <= 2*n ; i ++){
        cout << c[i] << ' ';
    }



    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
