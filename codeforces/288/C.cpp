#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =2e6;
const ll mod = 1e9+7;//998244353;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dominance true
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md = mod) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % md, b / 2, md) % md : pw(a * a % md, b / 2, md) % md));
}

int n;
ll ans = 0;
int p[maxn];

int main(){
    migmig
    cin >> n;
    int boz = n;
    while(!0){
        int mxt = 1<<(int)log2(boz);
        int mnt = mxt - 1;
        while(mxt <= boz){
            p[mxt] = mnt;
            p[mnt] = mxt;
            ans+=(ll)(mxt ^ mnt);
            mxt++;
            mnt--;
        }
        boz = mnt;
        if(boz<=0){
            break;
        }
    }
    cout << ans*2 << endl;
    for (int i = 0 ; i <= n ; i ++){
        cout << p[i] << ' ';
    }


    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
