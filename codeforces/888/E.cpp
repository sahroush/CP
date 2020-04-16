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

int n , k;
int a[maxn];
set < int  , greater < int > > s1 , s2;

int main(){
    migmig
    cin >> n >> k;
    for(int i = 0 ; i < n ; i ++)
		cin >> a[i] , a[i]%=k;
	for(int i = 0 ; i < (1 << (n/2)) ; i ++){
		int sum = 0 ;
		for(int j = 0 ; j < n/2 ; j ++)
			if(i&(1 << j))
				sum = (sum + a[j])%k;
		s1.insert(sum);
	}
	for(int i = 0 ; i < (1 << (n - n/2)) ; i ++){
		int sum = 0 ;
		for(int j = 0 ; j < (n - n/2) ; j ++)
			if(i&(1 << j))
				sum = (sum + a[n/2 + j])%k;
		s2.insert(sum);
	}
	int ans = 0;
	for(int i : s1){
		ans = max(ans , i);
	}
	for(int i : s2){
		ans = max(ans , i);
	}
	if(n == 1){ dokme(ans)}
	for(int i : s1){
		ans = max(ans , (i + *s2.begin())%k);
		int need = k - i;
		auto it = s2.upper_bound(need);
		if(it!=s2.end()){
			ans = max(ans , i + *it);
		}		
	}
	for(int i : s2){
		ans = max(ans , (i + *s1.begin())%k);
		int need = k - i;
		auto it = s1.upper_bound(need);
		if(it!=s1.end()){
			ans = max(ans , i + *it);
		}		
	}
    cout << ans;
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
