#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

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
int ans[maxn];
int fen[maxn];
int num[maxn];

void update(int pos){
	for(;pos<=n;pos+=pos&-pos)
		fen[pos]++;
}

int find(int val){
	int pos = 0;
	int ans = 0;
	for(int i = 20 ; i>=0 ; i --){
		if(pos+(1 << i) <= n and ans+fen[pos+(1 << i)]<val)
			pos += (1 << i), ans += fen[pos];
	}
	return(pos);
}

bool cmp (pii i , pii j){
	if(i.first == j.first){
		return(i.second < j.second);
	}
	return(i.first > j.first);
}

int main(){
    migmig
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
		cin >> a[i].first , a[i].second = i , num[i] = a[i].first;
    cin >> m;
    sort(a+1 , a + n+1 , cmp);
    for(int i = 0 ; i < m ;i ++)
		cin >> q[i].first.first >> q[i].first.second,q[i].second = i;
	sort(q , q + m);
	for(int i = 1 ; i <= n ; i ++){
		update(a[i].second);
		while(cur < m and q[cur].first.first == i){
			int pos = q[cur].first.second;
			ans[q[cur].second]=num[find(pos)+1];
			cur++;
		}
	}
	for(int i = 0 ; i < m ; i ++)cout << ans[i] << endl;
    return(0);
}