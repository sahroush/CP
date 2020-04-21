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

int n , m , mx  = 0;
char T[][13] = {"###.#.#....#",".#..#.######",".#.####....#"} , cur[20][20] , ans[20][20];
int tof;

void solve(int r = 0 ,int c = 0 ,int cnt = 0){
	if(r >= n - 2){
		if(mx < cnt){
			mx = cnt;
			for(int  i = 0 ; i < n ; i ++ )
				for(int j = 0 ; j < m ; j ++)
					ans[i][j] = cur[i][j];
		}
		return;
	}
	if(cnt + tof/5 <= mx)return;
	if(c >= m-2){
		solve(r + 1 , 0 , cnt);
		return;
	}
	if(cur[r][c] == '.')tof--;
	for(int i = 0 ; i < 12 ; i += 3){
		bool oke = 1;
		for(int j = 0 ; j < 3 ; j ++)
			for(int k = 0 ; k < 3 ; k ++)
				if(T[j][i + k] == '#' and cur[r + j][c + k]!='.'){
					oke = 0;
					break;
				}
				
		if(oke){
			for(int j = 0 ; j < 3 ; j ++ )
				for(int k = 0 ;  k < 3 ; k ++)
					if(T[j][i + k] == '#')
						cur[r+j][c + k] = char(cnt+ 'A');
			tof-=5;
			solve(r , c + 1 , cnt+1);
			tof+=5;
			for(int j = 0 ; j < 3 ; j ++ )
				for(int k = 0 ;  k < 3 ; k ++)
					if(T[j][i + k] == '#')
						cur[r+j][c + k] = '.';
		}				
	}
	solve(r , c +1, cnt);
	if(cur[r][c] == '.')tof++;
}


int main(){
    migmig
    cin >> n >> m;
    /*
    if(min(n , m ) < 3){
		cout << 0 << endl;
		for(int i = 0 ; i < n ; i ++ ){
			for(int j = 0 ; j < m ; j ++)
				cout << '.';
			cout << endl;
		}
		return(0);
    }
    */
    tof = n * m ;
    for(int i = 0 ; i < n ; i ++ )
		for(int j = 0 ; j < m ; j ++)
			cur[i][j] = ans[i][j] = '.';
	solve();
	cout << mx << endl;
	for(int i = 0 ; i < n ; i ++)
	{
		for(int j = 0 ; j < m ; j ++)cout << ans[i][j];
		cout << endl;
	}
    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
