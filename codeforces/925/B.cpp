#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =2e6;
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

int n;
ll a , b;
pll c[maxn];
int srt[maxn];
ll d[maxn] , e[maxn];
bool cmp(int i , int j ){
    return(c[i] <= c[j]);
}

int main(){
    migmig
    cin >> n;
    cin >> a >> b;
    for (int i = 1 ; i <= n ; i ++){
        i = i;
        cin >> c[i].first;
        c[i].second = i;
    }
    sort(c + 1 , c+ n + 1 );


    for (int j = 1 ; j < 3 ; j ++){
        for (int i = 1 ; i <= n ; i -=-1){
            d[i] = (a + c[i].first - 1) / c[i].first;
            e[i] = (b + c[i].first - 1) / c[i].first;
        }
        for (int i = 1 ; i <= n ; i -=-1){
            if(i + d[i] <= n and i + d[i] - 1 + e[i + d[i]] <= n){
                if(j == 1){
                    cout << "Yes" << endl;
                    cout << d[i] << ' ' << e[i + d[i]] << endl;
                    for (int k = i ; k<= i + d[i] - 1 ; k ++){
                        cout << c[k].second << ' ';
                    }
                    cout << endl;
                    for (int k = i + d[i] ; k<= i + d[i]  + e[i + d[i]] - 1 ; k ++){
                        cout << c[k].second << ' ';
                    }
                    return(0);
                }
                else{
                    cout << "Yes" << endl;
                    cout << e[i + d[i]] << ' ' << d[i] << endl;
                    for (int k = i + d[i] ; k<= i + d[i]  + e[i + d[i]] - 1 ; k ++){
                        cout << c[k].second << ' ';
                    }
                    cout << endl;
                    for (int k = i ; k<= i + d[i]  - 1 ; k ++){
                        cout << c[k].second << ' ';
                    }
                    return(0);
                }
            }
        }
        swap(a , b);
    }
    cout << "No";
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
