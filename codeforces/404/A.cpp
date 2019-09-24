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

int n;
string s[301];

int main(){
    //migmig
    cin >> n;
    for (int i = 0 ; i < n  ; i ++){
        cin >> s[i];
    }
    char x = s[0][0];
    for (int i = 0 ; i <  n ; i ++ ){
        if (i!= n/2 ){
            if (s[i][i] != x or s[i][n-i-1] != x){
                dokme("NO");
            }
        }
        else{
            if (s[i][i] != s[0][0]){
                dokme("NO");
            }
        }
    }
    char y = s[0][1];
    for (int  i = 0 ; i <  n ; i ++){
        for (int j = 0 ; j < n ; j++){
            if (i!=j and j!=n-i-1 and s[i][j] != y){
                dokme("NO");
            }
        }
    }
    if (x==y){
        dokme("NO")
    }
    dokme("YES")
    return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, l is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
