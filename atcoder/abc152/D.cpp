#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =8e5+5;
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

int main(){
    migmig
    cin >> n;
    int a[10][10] , b =0 , c;
    int cnt =0;
    ms(a , 0);
    for (int i = 0 ; i < n ; i ++){
        cnt = i + 1;
        b = cnt%10;
        while(cnt){
            c = cnt%10;
            cnt/=10;
        }
        a[c][b]++;
    }
    int ans=  0;
    for (int i = 0 ; i < 10 ; i ++)
{
    for (int j = 0 ; j < 10 ; j ++){
        ans+=a[i][j]*a[j][i];
    }
}
    cout << ans;
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
