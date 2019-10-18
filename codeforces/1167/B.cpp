#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 5e5;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int a[4];

int main(){
    //migmig
    cout << "? 1 2" << endl;
    cout << "? 2 3" << endl;
    cout << "? 4 5" << endl;
    cout << "? 5 6" << endl;
    fflush(stdout);
    for (int i  = 0 ; i < 4 ; i ++){
        cin >> a[i];
    }
    int b[6] = {4 , 8 , 15 , 16 , 23 , 42};
    for (int i = 0 ; i < 6 ; i ++){
        for (int j = 0 ; j < 6 ; j ++){
            for (int k = 0 ; k < 6 ; k ++){
                for (int h = 0 ; h  <6 ; h ++){
                    for (int l = 0 ; l < 6 ; l++){
                        for (int g = 0 ; g < 6 ; g ++){
                            if (i!= j and i!= k  and i!=h and i!=l and i!=g and j!=k and j!=h and j!=l and j!=g and k!=h and k!=l and k!=g and h!=l and h!=g and l!=g){
                                if (b[i]*b[j] == a[0] and b[j]*b[k] == a[1] and b[h]*b[l] == a[2] and b[l]*b[g] == a[3]){
                                    cout << '!' << ' ' << b[i] << ' ' << b[j] << ' ' << b[k] << ' ' << b[h] << ' ' << b[l] << ' ' << b[g];
                                    return(0);
                                }
                            }
                        }
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
