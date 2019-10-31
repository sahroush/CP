#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 1e5+100;
const ll ZERO = 0;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int x[maxn] , y[maxn] , n , ans ,m ,type[maxn];
pair <int , int> pos;

int mnhtn(int a, int b){
    return (abs(y[a]-y[b]) + abs(x[a]-x[b]));
}

bool dfs(int a, int t){
    if (type[a]!=-1){
		return (type[a]!=t);
	}
    type[a]=t;
    for (int i = 0 ; i < n ; i ++){
		if (mnhtn(i, a) > m and dfs(i, t^1)) return (1);
	}
    return 0;
}

pair <int , int>  chk(){
    int cnt=1;
    memset(type, -1, sizeof(type));
    for (int i = 0 ; i < n ; i ++){
		if (type[i]==-1){
			cnt=cnt*2%mod;
			if (dfs(i, 0)){
				return (make_pair(0, 0));
			}
		}
	}
    return (make_pair(1, cnt));
}



int main (){
    migmig
	cin >> n;
	for (int i = 0 ; i < n; i ++){
		cin >> x[i];
		cin >> y[i];
	}
	pos = make_pair(0 , 1);
	for (int i = 0 ;i  < n ; i ++){
		for (int j = 0 ; j < i ; j ++){
			if (mnhtn(i, j) > mnhtn(pos.first, pos.second)){
				pos=make_pair(i, j);
			}
		}
	}
	int l = 0, r = mnhtn(pos.first, pos.second);
	while(l < r){
        m=(l + r) / 2;
        pair <int , int > pii=chk();
        if (pii.first){
			r=m, ans=pii.second;
		}
        else l=m + 1;
    }
	cout << l << endl;
	dokme(ans);
    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
