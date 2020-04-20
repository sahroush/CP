#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll  ,ll > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e4;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int st[maxn][2];
int n;
int k[2];
int cnt[maxn][2];
int a[maxn][2];

void state (int pos , int turn){
	st[pos][1 - turn]  = 0;
	for(int i = 0 ; i < k[turn] ; i ++){
		int nxtt =(pos - a[i][turn]+n)%n;
		if(nxtt == 0) continue;
		if(st[nxtt][turn] == -1){
			st[nxtt][turn] = 1;
			for(int j = 0 ;j < k[!turn] ; j ++){
				int go = (nxtt - a[j][!turn] + n)%n;
				if(go == 0)continue;
				if(++cnt[go][1 - turn] == k[1 - turn]) state(go , turn);
			}
		}
	}			
}

int main(){
    migmig
    cin >> n;
    cin >> k[0];
    for(int i = 0 ; i < k[0] ; i ++)
		cin >> a[i][0];
	cin >> k[1];
	for(int i = 0 ; i < k[1] ; i ++)
		cin >> a[i][1];
	ms(st , -1);
	state(0 , 1);
	state(0 , 0);
	//0 = L , 1 = W , 2 = LOOP
	for(int j = 0 ; j < 2 ; j ++)
	for(int i = 1 ; i < n ; i ++){
		int res = st[i][j];
		if(res == 1) cout << "Win" << ' ';
		if(res == 0) cout << "Lose" << ' ';
		if(res == -1) cout << "Loop" << ' ';
		if(i == n-1 and j == 0)
			cout << '\n';
	}
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
