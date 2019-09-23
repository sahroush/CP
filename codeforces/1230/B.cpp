#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 1e3+1;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int n , k;
char s[200020];

int main(){
    cin >> n >> k;
    cin >> s;
    if (k == 0){
        dokme(s);
    }

    if (k == n and n== 1){
        s[0] = '0';
    }
    else if (s[0] != '1'){
        k--;
        s[0] = '1';
    }

    int cnt = 1;
    for (int i = 1 ; i < n ; i ++){
        if (s[i] != '0' and k > 0){
            k--;
            s[i] = '0';
        }
    }
    cout << s;

    return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, l is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
