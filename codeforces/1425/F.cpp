//In The Name of Allah
#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int a[N], b[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int x;
    cout << "? " << 1 << ' ' << 3 << '\n';
    cout.flush();
    cin >> x;
    for (int i = 1; i < n; i ++){
        cout << "? " << i << ' ' << i + 1 << '\n';
        cout.flush();
        cin >> b[i];
    }
    a[1] = x - b[2];
    for (int i = 2; i <= n; i ++)
        a[i] = b[i - 1] - a[i - 1];
    cout << "! ";
    for (int i = 1; i <= n; i ++)
        cout << a[i] << ' ';
    cout << '\n';
    cout.flush();
    return 0;
}
