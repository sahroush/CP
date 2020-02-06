#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =2e6;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

struct mobl{
    int x1 , x2 , y1 , y2;
}mob[maxn];

int n , m , a;
int l[maxn] , r[maxn] , u[maxn] , d[maxn];
map < pii , int > mp;

int main(){
    migmig
    cin >> a >> n >> m;
    for (int i = 1 ; i <= a ; i ++){
        cin >> mob[i].x1 >> mob[i].y1 >> mob[i].x2 >> mob[i].y2;
        mp[pii(mob[i].x1 , mob[i].y1)] = mp[pii(mob[i].x2 , mob[i].y2)] = i;
        l[min(mob[i].x1 , mob[i].x2)]++;
        r[max(mob[i].x1 , mob[i].x2)]++;
        u[min(mob[i].y1 , mob[i].y2)]++;
        d[max(mob[i].y1 , mob[i].y2)]++;
    }
    for (int i = 1 , j = 1e5 ; i <= 1e5 ; i ++ , j --){
        l[i]+=l[i - 1];
        u[i]+=u[i - 1];
        r[j]+=r[j + 1];
        d[j]+=d[j + 1];
    }
    mobl mm;
    cin >> mm.x1 >> mm.y1 >> mm.x2 >> mm.y2;
    for (int i = 1; i <= a ; i ++){
        int chap = l[max(mob[i].x1 , mob[i].x2) - 1];
        int rast = r[min(mob[i].x1 , mob[i].x2) + 1];
        if(min(mob[i].x1 , mob[i].x2) != max(mob[i].x1 , mob[i].x2)){
            chap-- , rast--;
        }
        int bala = u[max(mob[i].y1 , mob[i].y2) - 1];
        int payin = d[min(mob[i].y1 , mob[i].y2) + 1];
        if(min(mob[i].y1 , mob[i].y2) != max(mob[i].y1 , mob[i].y2)){
            bala-- , payin--;
        }
        if(chap == mm.x1 and rast == mm.y1 and bala== mm.x2 and payin == mm.y2){
            dokme(i)
        }
    }
    cout << -1;
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
