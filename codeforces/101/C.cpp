#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll  ,ll > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}


#define x first
#define y second

pii a , b , c;

int main(){
    migmig
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    /*
		each operation:
			1 - (x , y) = (y , -x)
			2 - (x , y) = (x + cx , y + cy)
	*/
	//we may check all the rotations
	for(int i = 0 ; i < 4 ; i ++){
		if(a == b){
			dokme("YES")}
		ll difx = b.x - a.x , dify = b.y - a.y;
		ll c2 = c.x*c.x + c.y*c.y;
		if(c2 > 0 and (c.x * difx + c.y *dify)%c2 == 0 and (c.x*dify - c.y*difx) %c2 == 0){
			dokme("YES");}
		swap(a.x , a.y);
		a.y*=-1;
	}
    cout << "NO";
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
