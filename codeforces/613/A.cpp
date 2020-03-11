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
pll s;
pll p[maxn];
ld mn = 1e9;
ld mx = -1e9;

ld dist(pll p , pll s){
    return((ld)sqrt(ld(abs(p.first - s.first)*abs(p.first - s.first) + abs(p.second - s.second)*abs(p.second - s.second))));
}

int main(){
    migmig
    cin >> n;
    cin >> s.first >> s.second;
    for (int i = 0 ; i < n ; i ++){
        cin >> p[i].first >> p[i].second;
        mn = min(mn , dist(s , p[i]));
        mx = max(mx , dist(s , p[i]));
    }
    p[n] = p[0];
    for (int i = 0 ; i < n; i ++){
        if(dist(p[i] , p[i + 1]) * dist(p[i] , p[i + 1]) + dist(p[i] , s) * dist(p[i] , s) <= dist(p[i + 1] , s) * dist(p[i + 1] , s)){
            continue;
        }
        if(dist(p[i] , p[i + 1]) * dist(p[i] , p[i + 1]) + dist(p[i + 1] , s) * dist(p[i + 1] , s) <= dist(p[i] , s) * dist(p[i] , s)){
            continue;
        }
        ld a = (dist(p[i] , p[i + 1]) + dist(p[i] , s) + dist(p[i + 1] , s))/2;
        ld b = sqrt(a * (a - dist(p[i] , p[i + 1])) * (a - dist(p[i] , s)) * (a - dist(p[i + 1] , s)));
        mn = min(mn , b*2/dist(p[i] , p[i + 1]));
    }
    cout << fixed << setprecision(10);
    cout << (PI)*(mx*mx - mn*mn);
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
