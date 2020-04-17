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

int n , m , k;
int a[maxn] , b[maxn];
ll ans = 0;
ll prta[maxn] , prtb[maxn];

int main(){
    migmig
	cin >> n >> m >> k;
	for(int i = 0 ; i < n ; i ++)
		cin >> a[i];
	for(int i = 0 ; i < m ; i ++)
		cin >> b[i];
    vector < int > vec;
    int cnt = 0;
    prta[1] = a[0];
    for(int i = 0 ; i < n ; i ++){
		if(i)
			prta[i+1] = prta[i]+a[i];
		if(a[i])
			cnt++;
		else
			if(cnt){
				vec.pb(cnt);
				cnt = 0;
			}
	}
    if(cnt){
		vec.pb(cnt);
		cnt = 0;
	}
	vector < int > v;
	prtb[1]=b[0];
	for(int i = 0 ; i < m ; i ++){
		if(i)
			prtb[i+1] = prtb[i]+b[i];
		if(b[i])
			cnt++;
		else
			if(cnt){
				v.pb(cnt);
				cnt = 0;
			}
	}
    if(cnt){
		v.pb(cnt);
		cnt = 0;
	}
	for(int i = 1 ; i <= n ; i ++){
		if(k%i == 0){
			int bb = k/i;
			int x = 0 , y = 0;
			for(int j = i ; j <= n ; j ++)
				if(prta[j] - prta[j - i] == i)
					x++;
			for(int j = bb ; j <= m ; j ++)
				if(prtb[j] - prtb[j - bb] == bb)
					y++;
			
			ans+=x*y;
		}
	}
	//out << ans;
			
		
		
		
		
	cout << ans;
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
