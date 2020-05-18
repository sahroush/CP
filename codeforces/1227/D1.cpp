#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> sett;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m , cur;
pii a[maxn];
pair < pii , int > q[maxn];
sett st;
int ans[maxn];

bool cmp (pii i , pii j){
	if(i.first == j.first){
		return(i.second < j.second);
	}
	return(i.first > j.first);
}

void add(pii a){
	swap(a.first , a.second);
	st.insert(a);
}

int solve(int pos){
	return((*st.find_by_order(pos-1)).second);
}

int main(){
    migmig
    cin >> n;
    for(int i = 0 ; i < n ; i ++)
		cin >> a[i].first , a[i].second = i;
    cin >> m;
    sort(a , a + n , cmp);
    for(int i = 0 ; i < m ;i ++)
		cin >> q[i].first.first >> q[i].first.second,q[i].second = i;
	sort(q , q + m);
	for(int i = 0 ; i < n ; i ++){
		add(a[i]);
		while(cur < m and q[cur].first.first == i+1){
			ans[q[cur].second]=solve(q[cur].first.second);
			cur++;
		}
	}
	for(int i = 0 ; i < m ; i ++)cout << ans[i] << endl;
    return(0);
}