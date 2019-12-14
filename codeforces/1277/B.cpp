#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

const ll maxn =9e5+1000;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define mkp make_pair
#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define random_init mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ms(x , y) memset(x , y , sizeof x);
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int q;
int n;
int a[maxn];
int b[maxn];
vector <int> vec;
set <int> st;

int main(){
    migmig
    cin >> q;
    while(q -- ){
        cin >> n;
        vec.clear();
        st.clear();
        for (int i = 0 ; i < n ; i ++){
            cin >> a[i];
            if(a[i] % 2 == 0){
                if(st.count(a[i]) == 0){
                    vec.pb(a[i]);
                }
                st.insert(a[i]);
            }
        }
        sort(vec.begin() , vec.end());
        //reverse(vec.begin() , vec.end());
        //dokme(vec.back());
        int ans = 0 ;
        std::set <int> :: iterator it;
        while(st.size()){
            it = st.end();
            it --;
            int v = *it;
            st.erase(v);
            v/=2;
            ans++;
            if(v%2 == 0){
                if(st.count(v) == 0){
                    st.insert(v);
                }
                //st.insert(v);
            }
        }
        cout << ans << endl;


    }


    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
