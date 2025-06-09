#ifndef CALSAH_H
#define CALSAH_H
#include <iostream>
using namespace std;

///todo: ex10
//se considera o tabla de sah de nxn. Sa se det. un drum de lungime min. prin care un cal aflat in poz (xi,yi) se deplaseaza
//in (xf,yf)

inline int dx[8] = {-2,-2,-1, 1, 2, 2, 1,-1};
inline int dy[8] = {-1, 1, 2, 2, 1,-1,-2,-2};

inline int xi, yi, xf, yf, n, nrSol = 0, kmin = 1000;
inline bool vizitat[10][10]{false};

struct pozitie {
    int x;
    int y;
};
inline pozitie drum[100], drumMin[100];

inline bool inBounds(int x, int y) {
    return (x > 0 && x <= n && y > 0 && y <= n);
}

inline void back(int k) {
    int x = drum[k].x;
    int y = drum[k].y;

    if(x == xf && y == yf) {
        nrSol++;
        if(k < kmin) {
            kmin = k;
            for(int i = 1; i <= kmin; i++) {
                drumMin[i] = drum[i];
            }
        }
    }

    for(int i = 0; i < 8; i++){
        int x1 = x + dx[i];
        int y1 = y + dy[i];

        if(inBounds(x1, y1)) {
            if(!vizitat[x1][y1]) {
                vizitat[x1][y1] = true;

                drum[k + 1].x = x1;
                drum[k + 1].y = y1;

                back(k + 1);

                vizitat[x1][y1] = false;
            }
        }
    }
}

inline void solve() {
    cin >> n >> xi >> yi >> xf >> yf;

    drum[1].x = xi;
    drum[1].y = yi;
    vizitat[xi][yi] = true;

    back(1);

    cout << nrSol << endl << kmin << endl;


    if(nrSol > 0) {
        for(int i = 1; i <= kmin; i++) {
            cout << "(" << drumMin[i].x << ", " << drumMin[i].y << ")" << " ";
        }
    }
}
#endif //CALSAH_H
