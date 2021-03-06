/*=============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        722.cc
#  Description:     UVa Online Judge - 722
=============================================================================*/
#include <bits/stdc++.h>
#pragma GCC optimizer("Ofast")
#pragma GCC target("avx2")
using namespace std;

typedef pair<int, int> ii;
typedef pair<long long, long long> ll;
typedef pair<double, double> dd;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<dd> vdd;

const int INF_INT = 1e9 + 7;
const long long INF_LL = 1e18;

const int MAXN = 105;

int dfs_state[MAXN][MAXN];
vector<string> A;
vi sizes;

void dfs(int r, int c) {
    if (dfs_state[r][c]) return;
    dfs_state[r][c] = sizes.size();
    sizes.back()++;

    for (int dy : {-1, 0, 1}) {
        for (int dx : {-1, 0, 1}) {
            if (dy == 0 and dx == 0) continue;
            if (abs(dy) + abs(dx) == 2) continue;
            if (r + dy < 0 or r + dy >= A.size()) continue;
            if (c + dx < 0 or c + dx >= A[r + dy].length()) continue;
            if (A[r + dy][c + dx] != '0') continue;
            if (dfs_state[r + dy][c + dx]) continue;
            dfs(r + dy, c + dx);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    getline(cin, line);
    int T = stoi(line);

    getline(cin, line);  // empty
    while (T--) {
        memset(dfs_state, 0, sizeof(dfs_state));

        getline(cin, line);
        regex re("\\s");
        sregex_token_iterator it(line.begin(), line.end(), re, -1);
        sregex_token_iterator it_end;

        vi nums;
        while (it != it_end) {
            nums.push_back(stoi(it->str()));
            it++;
        }
        nums[0]--;
        nums[1]--;

        A.clear();
        while (getline(cin, line)) {
            if (line == "") break;
            A.push_back(line);
        }

        sizes.clear();
        sizes.push_back(0);

        if (A[nums[0]][nums[1]] == '0') dfs(nums[0], nums[1]);

        int ans = sizes[0];
        cout << ans << endl;

        if (T) cout << endl;
    }

    return 0;
}