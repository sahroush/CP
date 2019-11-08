#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const ll maxn = 1e6+100;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int n , m , cnt = 0;
vector <int> vec[maxn];
vector <int> ans[maxn];
bool mark[maxn];
set < int > st;

/*
void solve(int v){
	set <int> s;
	set <int> x;
	set <int> y;
	s.insert(v);
	mark[v] = 1;
	std::set <int> :: iterator u;
	for (u = vec[v].begin() ; u !=vec[v].end(); u ++){
		if (!mark[*u]) y.insert(*u);
	}
	for (int i = 1 ; i <= n ; i ++){
		if (!mark[i] and y.count(i) ==0){
			x.insert(i);
		}
	}
	std::set <int> :: iterator it;
	it = x.begin();
	//y.insert(1e5);
	while(!x.empty()){
		it = x.begin();
		mark[*it] = 1;
		vector <int> del;
		del.clear();
		for (u = y.begin() ; u!=y.end() ; u++){
			if (vec[*it].count(*u) == 0 and mark[*u] == 0){
				x.insert(*u);
				s.insert(*u);
				mark[*u] = 1;
				//y.erase(*u);
				del.push_back(*u);
			}
		}
		for (int i =0 ; i < del.size() ; i ++){
			y.erase(del[i]);
		}
		s.insert(*it);
		//cout << *it;
		x.erase(x.begin());
	}

	it = s.begin();
	while(it!=s.end()){
		mark[*it] = 1;
		ans[cnt].push_back(*it);
		it++;
	}
	s.clear();
	x.clear();
	y.clear();
	return ;
}
*/

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

int main (){
    migmig
    cin >> n >> m;
    for (int i = 0; i < m ; i ++){
    	int x , y;
    	cin >> x >> y;
    	vec[x].pb(y);
    	vec[y].pb(x);
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
    cout << cnt << endl;
    for (int i = 0 ; i < cnt ; i ++){
    	cout << ans[i].size() << '\t';
    	for (int j = 0 ; j < ans[i].size() ; j++){
    		cout << ans[i][j] << ' ';
		}
		cout << endl;
	}
    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you wiint come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
