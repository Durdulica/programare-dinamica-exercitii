#ifndef INTERCALARE_H
#define INTERCALARE_H
#include <iostream>
using namespace std;
#include <climits>

const int MAXN = 200;
const int INF_NEG = INT_MIN / 2;

inline int m, n;
inline int A[MAXN], B[MAXN];

inline int   dp     [MAXN + 1][MAXN + 1][3];
inline char  nextSeq[MAXN + 1][MAXN + 1][3];
inline short nextPos[MAXN + 1][MAXN + 1][3];
inline bool  viz    [MAXN + 1][MAXN + 1][3];

inline int rez(int i, int j, int last)
{
    if (viz[i][j][last]) return dp[i][j][last];

    viz[i][j][last] = true;
    nextSeq[i][j][last] = -1;

    int best = 0;
    int lastVal;
    if ((last == 0))
        lastVal = A[i - 1];
    else
        if (last == 1)
            lastVal = B[j - 1];
        else
            lastVal = INF_NEG;

    for (int k = i; k < m; ++k)
        if (A[k] > lastVal) {
            int cur = 1 + rez(k + 1, j, 0);
            if (cur > best) {
                best = cur;
                nextSeq[i][j][last] = 0;
                nextPos[i][j][last] = k;
            }
        }

    for (int l = j; l < n; ++l)
        if (B[l] > lastVal) {
            int cur = 1 + rez(i, l + 1, 1);
            if (cur > best) {
                best = cur;
                nextSeq[i][j][last] = 1;
                nextPos[i][j][last] = l;
            }
        }

    return dp[i][j][last] = best;
}

inline int ex4(){
    cin >> m >> n;
    for (int i = 0; i < m; ++i) cin >> A[i];
    for (int j = 0; j < n; ++j) cin >> B[j];

    rez(0, 0, 2);

    int i = 0, j = 0, last = 2;
    bool first = true;
    while (nextSeq[i][j][last] != -1) {
        if (nextSeq[i][j][last] == 0) {
            int k = nextPos[i][j][last];
            if (!first) cout << ' ';
            cout << A[k];
            first = false;
            i = k + 1;
            last = 0;
        }
        else {
            int l = nextPos[i][j][last];
            if (!first) cout << ' ';
            cout << B[l];
            first = false;
            j = l + 1;
            last = 1;
        }
    }
    cout << endl;
    return 0;
}
#endif //INTERCALARE_H
