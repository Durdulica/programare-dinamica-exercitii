#ifndef BAC2025_H
#define BAC2025_H
#include <iostream>
using namespace std;

///Subiectul I

//ex 1: d.

//ex 2: a.

//ex 3: b.

//ex 4: c.

//ex 5: ???grafuri

///Subiectul II

//ex 1: a) 9
//b) m = 24, m = 25
//c)
inline void trans() {
    int m, n;
    cin >> m >> n;
    int nr = 0, i = m;
    do {
        int x = 1;
        while(x * x < i)x++;
        if(x * x == i) nr = i;
        else i++;
    }while(i <= n && nr == 0);

    cout << nr;
}

//d) structura repetitiva cu test final(pseudocod)

// citeste m,n
// nr <- 0; i <- m
// cat timp i <= n si nr = 0 executa
//      x <- 1
//      cat timp x*x < i executa
//          x <- x + 1
//      daca x*x = i atunci nr <- i
//          altfel i <- i + 1
//scrie nr


//ex 2: ??? grafuri + liste

//ex 3:

struct prajitura {
    int cod;
    float pret;
    int informatii[3];
};

///Subiectul III

//ex 1:
//nr. nat. an este ascendent al nr. nat. n daca oricare dintre cif. lui an este mai mare sau egala cu cifra unitatilor lui n
//subprogramul ascendent(int n, int x, int y), x < y. El returneaza suma ascendentilor lui x din intervalul [x,y] sau 0

inline int ascendent(int n, int x, int y) {
    int suma = 0;
    if(x > y) {
        return suma;
    }

    for(int i =  x; i <= y; i++) {
        int aux = i, ok = 1;
        while(aux != 0) {
            if(aux % 10 < n % 10) {
                ok = 0;
                break;
            }
            aux /= 10;
        }

        if(ok) {
            suma += i;
        }
    }

    return suma;
}

//ex 2:
//un cuv. semioglindit se obtine dintr-un cuv. cu 2 * k litere (k <= 100), prin interschimbarea in acesta a secv. formate din
//primele k litere cu secv. formata din ultimele k litere. Scrieti un program care citeste un sir de 200 caractere si il trans.
//prin inlocuirea fiecarui cuv. cu nr. par de litere cu cel semioglindit
#include <string.h>
//"am facut fotografii unei flori mari"
void ex2() {
    char s[200], sCopy[200], s2[200] = "";
    cin.getline(s, 200);
    strcpy(sCopy, s);
    char*cuv = strtok(sCopy, " ");

    while(cuv != NULL) {
        if(strlen(cuv) % 2 == 0) {
            char aux[200]{};
            strncpy(aux, cuv + strlen(cuv)/2, strlen(cuv)/2);
            strcat(s2, aux);
            strncpy(aux, cuv, strlen(cuv)/2);
            strcat(s2, aux);
            strcat(s2, " ");
        }
        else {
            strcat(s2, cuv);
            strcat(s2, " ");
        }

        cuv = strtok(NULL, " ");
    }

    strcpy(s, s2);
    cout << s;
}

//un tanar are o lista cu muzee virtuale si un interval orar pt. fiecare in care muzeul poate fi vizitat gratuit.
//un muzeu este convenabil daca poate fi vizitat gratuit in timpul disponibil si daca pt. vizita ii poate aloca c. p. o ora.
//muzeele sunt numerotate incepand cu 1 si c. p. unul este convenabil. Sa se afis. nr. de muzee convenabile si ultimul muzeu
//pe care il poate vizita
#include <fstream>

void ex3() {
    ifstream fin("D:/info/c++/clion/programareDinamica-Exercitii/matrice.txt");
    int inceput, final;
    fin >> inceput >> final;

    int ind = 1, nrSol = 0;

    while(fin) {
        int x, y;
        fin >> x >> y;

        if(x >= inceput && x < final || y <= final && y > inceput) {
            cout << x << ":" << inceput << " " << y << ":" << final << endl;
            if(x - inceput < final - y) {
                inceput = max(x, inceput);
            }
            else {
                final = min(y, final);
            }
            nrSol++;
        }
        ind++;
    }

    cout << nrSol;
}
#endif //BAC2025_H
