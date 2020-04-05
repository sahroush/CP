#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<ll  ,ll > pii;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

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

int n;
pii p[maxn] , p2[maxn];
ll ans = 0;
map <ll , ll > pos;

int main(){
    migmig
    cin >> n;
    for(int i = 0 ; i < n ; i ++){
    	cin >> p[i].first;
	}
	for(int i =0 ; i < n ; i ++){
		cin >> p[i].second;
		p2[i] = p[i];
		swap(p2[i].first , p2[i].second);
	}
	sort(p , p + n);
	sort(p2 ,p2+ n);
	for(int i =0 ; i < n ; i ++){
		ans+=p[i].first*(2*i+1-n);
		pos[p[i].first] = i;
	}
	
	for(int i = 0 ; i < n ; i ++ ){
		ans -= p2[i].second * (pos[p2[i].second] - i);
	}
	
	
	cout << ans;


    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u p�ajtal m�ak jach t�aj meyajilo'ob le castigadas tumen ch'aik descansos.

