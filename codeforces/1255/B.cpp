#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =2e6+5;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int q;
int a[maxn];

int main(){
    migmig
    cin >> q;
    while(q--){
        set<pii>st;
        int n , m;
        st.clear();
        cin >> n >> m;
        for (int i = 1; i  <= n ; i ++){
            cin >> a[i];
            st.insert(pii(a[i] , i));
        }
        if(m < n or n<=2){
            cout << -1;
            cout << endl;
            continue;
        }
        int c=0;
        //sort(a + 1 , a + n + 1);
        for (int i = 1 ; i <= n ; i ++ ){
            c+= 2*a[i];
        }
        pii min1 , min2;
        min1 = *st.begin();
        st.erase(min1);
        min2 = *st.begin();
        c+=(m - n)*(min1.first + min2.first);
        cout << c << endl;
        for (int i = 1 ; i < n ; i ++){
            cout << i << ' ' << i + 1 << endl;
        }
        cout << n << ' ' << 1 << endl;
        for (int i = 0 ; i < m - n ; i ++){
            cout << min1.second << ' ' << min2.second << endl;
        }

    }


    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
