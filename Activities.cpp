#include <bits/stdc++.h>
using namespace std;

vector<pair<long long int, long long int>> arr;
vector<long long int> dp(1000005);
long long int n;

long long int binarySearch(long long int id) {
    long long int lo = 0, hi = id - 1, mid, ret = 0;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (arr[mid].first <= arr[id].second) {
            lo = mid + 1;
            ret = max(ret, mid);
        } else {
            hi = mid - 1;
        }
    }
    return ret;
}

int main() {
    long long int mod=1e8;
    while (cin >> n) {
        if (n == -1) break;

        fill(dp.begin(), dp.end(), 0);
        arr.clear();
        arr.push_back({0, 0});

        long long int l, r;
        for (int i = 0; i < n; i++) {
            cin >> l >> r;
            arr.push_back({r, l});
        }

        sort(arr.begin(), arr.end());

        for (int i = 1; i <= n; i++) {
            long long int id = binarySearch(i);
            dp[i] = dp[id] + 1;
            dp[i] += dp[i - 1];
            dp[i] %= mod;
        }

        cout << setw(8) << setfill('0') << dp[n] << endl;
    }
}
