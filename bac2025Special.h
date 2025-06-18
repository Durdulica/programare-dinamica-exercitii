#ifndef BAC2025SPECIAL_H
#define BAC2025SPECIAL_H
#include <iostream>
using namespace std;

///Subiectul I

//ex 1: d.

//ex 2: c.

//ex 3: a.

//ex 4: b.

//ex 5: ???

///Subiectul II

//ex 1: a) 88 77
//      b)2225 2226
//c)

inline void trans() {
    int m,n;
    cin >> m >> n;
    for(int i = n; i >= m; i--) {
        int x = i, c = x % 10;
        do {
            x = x / 10;
        }while(x % 10 == c);
        if(x == 0) cout << x << ' ';
    }
}

// d)structura repetitiva cu test initial

//citeste m,n
//i <- n
//cat timp i >= m executa
//      x <- i
//      c <- x % 10
//      repeta
//         x <- [x/10]
//      pana cand x % 10 != c
//      daca x = 0 atunci
//         scrie i, ' '
//      i <- i - 1


//ex 2: arbore ???

//ex 3:

struct punct {
    int x, y;
};

struct figura {
    punct A, B;
}inline d;

inline void solve() {
    if(d.A.y == d.B.x && d.A.x == d.B.y) {
        cout << "DA";
    }
    else {
        cout << "NU";
    }
}

///Subiectul III

//ex 1:
//subprogramul diviz are un parametru n, prin care primeste un nr. nat. Subprogramul returneaza cmmd al lui n care este patr. perf.

inline int diviz(int n) {
    int rez = 1;
    for(int d = 2; d <= n; d++) {
        if(n % d == 0) {
            for(int j = 2; j <= d; j++) {
                if(j * j == d) {
                    rez = d;
                }
            }
        }
    }
    return rez;
}

//ex 2:
//se citeste un text de 100 caractere. Sa se transforme prin elim. sau adaugarea unor spatii si a unor cratime(-) a. i.
//intre oricare doua cuv. consecutive sa fie cate o cratima, incadrata de cate un spatiu
//"anul     acesta devin           student"
#include <cstring>

inline void ex2() {
    char s[100] , s2[100] = "", sCopy[100];
    cin.getline(s, 100);
    strcpy(sCopy, s);

    char*cuv = strtok(sCopy, " ");

    while(cuv) {
        strcat(s2, cuv);
        strcat(s2, " ");
        cuv = strtok(nullptr, " ");
    }

    strcpy(s, "");
    int ind = 0;

    for(int i = 0; i < strlen(s2); i++) {
        if(s2[i] == ' ' && s2[i + 1] != '\0') {
            s[ind++] = ' ';
            s[ind++] = '-';
            s[ind++] = ' ';
        }
        else {
            s[ind++] = s2[i];
        }
    }

    for(int i = 0; i < ind; i++) {
        cout << s[i];
    }
}

//ex 3:
//un fisier contine cel mult 10 la puterea 6 triplete de nr. nat din intervalul [1,100], fiecare nr. repr. lung. lat. unui triunghi
//Se cere sa se afis pe ecran nr. max. de triunghiuri dr. din fisier care au aceeasi lungime a ipotenuzei
#include <fstream>

inline void sortVec(int v[], int dim) {
    for(int i = 0; i < dim; i++) {
        for(int j = i; j < dim; j++) {
            if(v[i] > v[j]) {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

inline int maxVec(int v[], int dim) {
    int max = INT_MIN;
    for(int i = 0; i < dim; i++) {
        if(v[i] > max) {
            max = v[i];
        }
    }
    return max;
}

inline void ex3() {
    ifstream fin("D:/info/c++/clion/programareDinamica-Exercitii/matrice.txt");

    int v[3]{}, indRez[101]{};
    while(fin) {
        fin >> v[0] >> v[1] >> v[2];
        sortVec(v, 3);
        if(v[0] * v[0] + v[1] * v[1] == v[2] * v[2]) {
            indRez[v[2]]++;
        }
    }
    cout << maxVec(indRez, 101);
}

#endif //BAC2025SPECIAL_H