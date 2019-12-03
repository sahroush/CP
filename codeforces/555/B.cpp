#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

const ll maxn =10e5+10;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define random_init mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

struct segment{
    ll l , r , id;
}seg[maxn];

int n , m ;
ll l [maxn] , r[maxn] , a[maxn];
set <pair < ll , int > > st;
ll ans[maxn];
vector < pair < pair < ll , ll > , int > > vec;

bool cmp1(segment i , segment j){
    return(i.l > j.l);
}

int main(){
    migmig
    cin >> n >> m;
    for (int i = 0 ;  i < n ; i ++){
        cin >> l[i] >> r[i];
    }
    for (int i = 0 ; i < m ; i ++){
        cin >> a[i];
        st.insert(make_pair(a[i] ,  i));
    }
    sort(seg , seg + n - 1 , cmp1);
    std::set<pair <ll , int > > :: iterator it;
    memset(ans , -1 , sizeof ans);
    for (int i = 1 ; i < n ; i ++){
        vec.push_back(make_pair(make_pair(r[i]-l[i-1],l[i]-r[i-1]),i));
    }
    sort(vec.begin() , vec.end());
    for (int i = 0 ; i < vec.size() ; i ++){
        ll mn = vec[i].first.second;
        ll mx = vec[i].first.first;
        std::set < pair < ll , int > > :: iterator it;
        it = st.lower_bound(make_pair(mn , -1));
        if(it == st.end()){
            continue;
        }
        ll sz = it -> first;
        if(sz >= mn and sz <= mx){
            ans[vec[i].second - 1] = it->second;
            st.erase(it);
        }
    }
    for (int i = 0 ; i < n - 1 ; i ++){
        if ( ans [ i ] ==-1){
            dokme("No");
        }
    }
    cout << "Yes" << endl;
    for (int i = 0 ; i < n-  1 ; i ++){
        cout << ++ans[i] << ' ';
    }


    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
