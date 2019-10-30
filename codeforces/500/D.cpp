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



ll n , l[maxn] , r , w , post[maxn] , boz[maxn] , a[maxn] , b[maxn];
vector <pair <ll , ll > > vec[maxn];
map < ll , pair <ll , ll> > mp;
map < pair < ll , ll > , ll > sz;
ld avg = 0;
ld prob[maxn];
bool mark[maxn];
ll par[maxn];
ll chi[maxn];

void dfs(ll v ){
	mark[v] = true;
	post[v] = 1;
    for (ll i = 0 ; i < vec[v].size() ; i ++){
       ll u = vec[v][i].first;
       if (!mark[u]){
           dfs(u);
           boz[vec[v][i].second] = post[u];
           post[v] += post[u];
       }
   }
}


int main (){
    migmig
    cin >> n;
    ll cnt = 1;
    for (ll  i =1 ;  i < n ; i ++){
        ll x , y;
        cin >> x >> y >> l[i];
        vec[x].push_back(make_pair(y , i));
        vec[y].push_back(make_pair(x , i));
        mp[cnt] = make_pair (min (x , y) , max(x , y));
        sz[make_pair (min (x , y) , max(x , y))] = l[i];
        cnt++;
    }

    ll q;
    cin >> q;
    /*
    for (ll i = 0 ; i  < q ; i ++){
        cin >> r[i] >> w[i];
    }
    */
    dfs(1);

    for(ll i = 1; i < n; i++){
		avg += boz[i] * (n - boz[i]) * l[i];
	}
    ld div =  (ld)n * ((ld)n-1)  ;

    cout << fixed << setprecision(6);
    /*
    for (ll i = 0 ; i < q ; i ++){
        avg -= a[r[i]] * (n - a[r[i]]) * l[r[i]];
        l[r[i]] = w[i];
		avg += a[r[i]] * (n - a[r[i]]) * l[r[i]];
        cout << avg*6 / div << endl;
    }
    */
    while (q--){
        cin >> r >> w;
		avg -= boz[r] * (n - boz[r]) * l[r];
		l[r] = w;
		avg += boz[r] * (n - boz[r]) * l[r];
		cout << (avg * 6.0) / (div) << endl;
    }

    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
