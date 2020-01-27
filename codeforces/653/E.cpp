#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =8e5+5;
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

int n , m ,k ,cnt = 0;
vector <int> vec[maxn];
vector <int> ans[maxn];
bool mark[maxn];
set < int > st;
int boz = 1;
int par[maxn];

int getpar(int v){
    return((v == par[v])? v : par[v] = getpar(par[v]));
}

void solve(int v, int num){
	ans[num].push_back(v);
	st.erase(v);
    std::set <int> :: iterator it ;
    std :: vector < int > :: iterator low;
	for (it = st.begin(); it != st.end(); it){
		int p = *it;
		low = lower_bound(vec[v].begin(), vec[v].end(), p);
		if (low == vec[v].end() or *low != p)	solve(p, num);
		it = st.lower_bound(p+1);
	}
}

int main(){
    migmig
    cin >> n >> m >> k;
    for (int i = 0; i < m ; i ++){
    	int x , y;
    	cin >> x >> y;
    	vec[x].pb(y);
    	vec[y].pb(x);
        if(x == 1 or y == 1){
            boz++;
        }
	}
    for (int i = 1 ; i<=n; i ++){
        sort (vec[i].begin() , vec[i].end());
        st.insert(i);
    }
	for (int i = 1 ; i <= n ; i ++){
		if (st.count(i)){
			solve(i , cnt);
			cnt++;
		}
	}

    if(cnt!=1 ){
        dokme("impossible");
    }
    int mx = n - boz;

    if(mx < k){
        dokme("impossible")
    }
    cnt = 0;
    for (int i = 2 ; i<=n; i ++){
        sort (vec[i].begin() , vec[i].end());
        st.insert(i);
    }
    for (int i = 2 ; i <= n ; i ++){
		if (st.count(i)){
			solve(i , cnt);
			cnt++;
		}
	}
    if(cnt > k){
        dokme("impossible")
    }
    cout << "possible";
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
