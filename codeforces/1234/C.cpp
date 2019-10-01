#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 2e5+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int q , n;
char a[maxn] , b[maxn];

int main(){
    migmig
    cin >> q;
    for (int  j = 0 ; j < q ; j ++){
        cin >> n ;
        cin >> a >> b;
        for (int i =0  ; i < n ; i ++){
            if (a[i] == '1' or a[i] == '2'){
                a[i] = '_';
            }
            if (b[i] == '1' or b[i] == '2'){
                b[i] = '_';
            }
        }
        for (int i = 0  ; i < n ; i ++){
            if (a[i] != '_'){
                a[i] = '/';
            }
            if (b[i] != '_'){
                b[i] = '/';
            }
        }
        int pos = 0;
        bool r = 1;
        bool f =0 ;
        for (int i = 0 ; i < 2*n ;  i++){
            if (pos > n-1){
                cout << "NO" << endl ;
                break;
            }
            if (r){
                if (a[pos] == '_'){
                    pos++;
                }
                else if (a[pos] == '/'){
                    if (b[pos] != '/'){
                        cout << "NO" << endl;
                        break;
                    }
                    else{
                        if (pos == n-1){
                            cout << "YES" << endl;
                            break;
                        }
                        else{
                            r = 0;
                            pos++;
                        }
                    }
                }
            }
            if (!r){
                if (b[pos] == '_'){
                    if (pos == n-1){
                        cout << "YES" << endl;
                        break;
                    }
                    pos++;
                }
                else if (b[pos] =='/' ){
                    if (a[pos] != '/'){
                        cout << "NO" << endl ;
                        break;
                    }
                    else{
                        pos++;
                        r = 1;
                    }
                }
            }
        }
    }

    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
