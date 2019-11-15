#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const ll maxn =1e6+10;
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

int n , m;
string s[maxn];
vector <int> vec[maxn];
int name[1100][1100];
pii pos[maxn];
int cnt = 1;
bool rowmark[maxn], colmark[maxn] , mark[maxn] , mrk[maxn];
queue <pii> q;
int dist[1100][1100];

int main (){
    migmig
    cin >> n >> m ;
    for (int i = 0 ; i < n; i ++){
        cin >> s[i];
    }
    for (int i = 0 ; i < n ; i ++){
        for (int j = 0 ; j <  m; j++){
            if (s[i][j]=='#'){
                pos[cnt] = make_pair(i , j);
                name[i][j]  = cnt;
                cnt++;
            }
        }
    }
    for (int i = 0 ; i < m ; i ++){
        if (s[0][i] == '#'){
            vec[0].push_back(name[0][i]);
            vec[name[0][i]].push_back(0);
            dist[0][i]=1;
			q.push(make_pair(0,i));
        }
        if (s[n-1][i] == '#'){
            vec[cnt].push_back(name[n-1][i]);
            vec[name[n-1][i]].push_back(cnt);
        }
    }
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		if(x==n-1){
			dokme(dist[x][y]);
		}
		q.pop();
		if(mark[x]==0){
			mark[x]=1;
			for(int i = 0 ; i < m ; i++){
				if(s[x][i]=='#' and dist[x][i]==0){
					dist[x][i]=dist[x][y]+1;
					q.push(make_pair(x,i));
				}
            }
		}
		if(mrk[y]==0){
			mrk[y]=1;
			for(int i = 0 ;i < n ; i++){
				if(s[i][y]=='#' and dist[i][y]==0){
					dist[i][y]=dist[x][y]+1;
					q.push(make_pair(i,y));
				}
            }
		}
	}
	dokme(-1);


    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you wiint come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
