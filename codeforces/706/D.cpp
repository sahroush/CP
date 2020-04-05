#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6+100;//AmShZ
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define lowbit(x) ((x)&(-(x)))
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
bitset < 32 > a;
map <pii , int > adj;

void upd(int x , char t){
    int d = 1;
    if(t == '-'){
        d = -1;
    }
    a = x;
    a[31] = 1;
    ll cur = 1;
    for(int i = 30 ; i >= 0 ; i --){
        cur = 2*cur+(int)a[i];
        adj[{cur/2 , cur}]+=d;
    }
}

void solve(int x){
    a = x;
    a[31] = 1;
    int cur = 1;
    int ans = 0;
    for(int i = 30 ; i >= 0 ; i --){
        if(a[i]){
            if(adj[{cur , 2*cur}]){
                cur*=2;
                ans+=(1<<i);
            }
            else{
                cur*=2;
                cur++;
            }
        }
        else{
            if(adj[{cur , 2*cur+1}]){
                cur*=2;
                cur++;
                ans+=(1<<i);
            }
            else{
                cur*=2;
            }
        }
    }
    cout << max(x , ans) << endl;
}

int main(){
    migmig
    cin >> q;
    while(q -- ){
        char t;
        int x;
        cin >> t >> x;
        if(t == '?'){
            solve(x);
        }
        else{
            upd(x , t);
        }
    }
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
