#ifndef EXERCITII_H
#define EXERCITII_H
#include <iostream>
using namespace std;

//se considera un sir de n nr. nat. Se cere sa se det. cel mai lung subsir strict cresc. al sirului, cu propr. ca toate elem
//sale sunt nr. prime

void afisVec(int v[], int dim) {
    for (int i = 0; i < dim; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

bool isPrim(int number) {
    if (number <= 2) {
        return true;
    }

    for(int d = 2; d*d <= number; d++) {
        if(number % d == 0) {
            return false;
        }
    }
    return true;
}

void dinamica(int v[], int d[], int n, int&dm) {
    d[n - 1] = 1;

    for(int i = n - 2; i >= 0; i--) {
        int max = 0;
        for(int j = i + 1; j < n; j++) {
            if(d[j] > max && v[i] < v[j] && isPrim(v[i])) {
                max = d[j];
            }
        }
        d[i] = max + 1;
        if(dm < d[i]) dm = d[i];
    }
}

void drum(int v[], int d[], int dm) {
    int t = 0, p = 0;
    cout << dm << endl;
    do {
        while(d[p] != dm || v[t] > v[p]) p++;
        cout << v[p] << " ";
        t = p;
        dm--;
    }while(dm > 0);
}

void ex1() {
    int v[100]{2,5,3,7,7,9,11,8,6,13}, n = 10, d[100], dm;

    dinamica(v, d, n, dm);
    drum(v, d, dm);
}

//se considera o multime de n obiecte de valori cunoscute folosite pt. premierea unor sportivi. Sa se det. care este nr. max.
//de valori ale unui premiu, care se pot obtine folosind obiectele date
const int MAX_N=200;
const int MAX_V=100;

const int MAX_S=MAX_N*MAX_V;

int numarPremii(int v[],int n) {
    bool folosit[MAX_S]{false};
    folosit[v[0]] = true;
    int sMaxim=v[0];

    for(int i = 1; i < n; i++) {
        for(int s=sMaxim; s>=0; s--) {

            if(folosit[s]) {
                folosit[s+v[i]] = true;
                sMaxim+=s;
            }
        }

    }

    for(int i = 0; i < n; i++) {
        folosit[v[i]] = true;
    }

    int ct=0;

    for(int s = 0; s < sMaxim; s++) {
        if(folosit[s]) {
            cout << s << " ";
            ct++;
        }
    }
    return ct;
}

void ex2() {
    int v[100]{6,3}, n = 2;

    cout << numarPremii(v, n) << endl;
}

//se considera o secventa de n nr. intregi din intervalul [-10000,10000]. Sa se gaseasca un subsir de suma max. cu propr. ca
//oricare 2 elem. ale subsirului nu sunt aflate pe poz. consecutive in secventa.

void dinamica3(int v[],int d[], int n) {
    d[0] = v[0];

    for(int i = 1; i < n; i++) {
        d[i] = max(d[i-1], d[i-2] + v[i]);
    }
}

void ex3() {
    int v[100]{3, 7, 5, -1, 6, 6, 2}, n = 7;
    int d[100];

    dinamica3(v, d, n);

    cout << d[n - 1] << endl;
}

//se considera 2 siruri n <= 200. Sa se det. subsirul cresc. de lungime max al sirului obtinut prin intercalarea a celor 2 siruri

void intercVec(int s1[], int dim1, int s2[], int dim2, int rez[]) {
    int k = 0;
    for(int i = 0; i < dim1; i++) {
        rez[k++] = s1[i];
    }
    for(int i = 0; i < dim2; i++) {
        rez[k++] = s2[i];
    }
}

void dinamica4(int v[], int n, int dp[], int&dm) {
    dp[n - 1] = 1;

    for(int i = n - 2; i >= 0; i--) {
        int max = 0;
        for(int j = i + 1; j < n; j++) {
            if(dp[j] > max && v[i] < v[j]) {
                max = dp[j];
            }
            dp[i] = max + 1;

            if(dm < dp[i]) dm = dp[i];
        }
    }
}

void ex4() {
    int s1[200]{2,1,0,5,3,7}, dim1 = 6;
    int s2[200]{4,3,6,1,8}, dim2 = 5;
    int v[400]{}, dp[400], dm = 0;

    intercVec(s1, dim1, s2, dim2, v);
    dinamica4(v,dim1 + dim2, dp, dm);
    drum(v, dp, dm);
}

//se considera un sir de n <= 200 nr. nat. Sa se det. un subsir de lungime max, in care fiecare valoare contine mai putine cif de 1
//in repr. binara decat elem. urmator

int ct1NrBinar(int nr) {
    if(nr == 0) return 0;
    if(nr % 2 == 1) {
        return ct1NrBinar(nr / 2) + 1;
    }
    return ct1NrBinar(nr / 2);
}

void dinamica5(int v[], int n, int ctBinar[], int d[], int&dm) {
    d[n - 1] = 1;

    for(int i = n - 2; i >= 0; i--) {
        int max = 0;
        for(int j = i + 1; j < n; j++) {
            if(d[j] > max && ctBinar[i] < ctBinar[j]) {
                max = d[j];
            }
        }
        d[i] = max + 1;
        if(dm < d[i]) dm = d[i];
    }
}

void drum5(int v[], int d[], int dm) {
    int t = 0, p = 0;
    cout << dm << endl;
    do {
        while(d[p] != dm) p++;
        cout << v[p] << " ";
        t = p;
        dm--;
    }while(dm > 0);
}

void ex5() {
    int v[200]{3,7,5,16,6,9,7,15}, n = 8, ctBinar[200]{};
    int d[200], dm = 0;

    for(int i = 0; i < n; i++) {
        ctBinar[i] = ct1NrBinar(v[i]);
    }

    dinamica5(v, n, ctBinar, d,dm);

    drum5(v, d, dm);
}

//se considera un sir de n <= 200 nr. de max. 2 cif. Sa se det. o submultime ded suma S formata din nr. min. de val.

void subm(int v[], int n, int s[], int t[], int S) {
    int mx = 0;
    t[0] = 0;
    s[0] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = mx; j >= 0; j--) {
            if(s[j] && !s[j + v[i]] && j + v[i] <= S) {
                s[j + v[i]] = 1;
                t[j + v[i]] = v[i];
                if(j + v[i] > mx) mx = j + v[i];
            }
        }
    }
}

void drum6(int S, int t[]) {
    if(S != 0) {
        cout << t[S] << " ";
        drum6(S - t[S], t);
    }
}


void ex6() {
    int v[200]{3,2,1,4}, n = 4, S = 7;
    int s[200]{}, t[200]{};

    subm(v, n, s, t, S);

    drum6(S,t);
}

//se da un set de n val. distincte si o limita ka nr. de val. care pot fi lipite pe plic. Sa se det. cea mai mare sec.
//de val. consecutive de la 1 la M.(sa se afis M)

void subm7(int v[], bool dp[], int cnt[], int n, int k, int&dm) {
    dp[0] = true;
    cnt[0] = 0;

    for(int i = 1; i < 10000; i++){
        for(int j = 0; j < n; j++) {
            if(i >= v[j] && dp[i - v[j]] && cnt[i - v[j]] + 1 <= k) {
                dp[i] = true;
                cnt[i] = min(cnt[i],cnt[i - v[j]] + 1);
            }
        }

        if(!dp[i]) {
            dm = i - 1;
        }
    }
}

void ex7() {
    int v[50]{1,3}, n = 2, k = 5, dm = 0;
    int cnt[10000]{}; //nr. min. de timbre pt. suma i
    bool dp[10000]{}; //true daca pot forma suma i

    subm7(v,dp,cnt,n,k,dm);

    cout << dm << endl;
}

//se considera o secventa de nr. prime. Un nr. este super prim daca si el este prim si daca nr. de ordine in sirul nr. prime
//este un nr. prim. Sa se descompuna un nr. dat ca suma de nr. super prime. Daca exista mai multe posibilitati, sa va afisa cea
//cu nr. min. de termeni

void vecNrSuperPrime(int v[], int dim, int&index) {
    int offset = 0;
    for(int i = 2; i <= dim; i++) {
        if(isPrim(i)) {
            offset++;
            if(isPrim(offset)) {
                v[index++] = i;
            }

        }
    }
}

void subm8(int v[],int nr[], int t[], int n, int dim) {
    nr[0] = 0;
    for(int i = 1; i < dim; i++) {
        for(int j = 0; j < n - v[i];j++) {
            if(nr[j + v[i]] < nr[j] + 1) {
                nr[j + v[i]] = nr[j] + 1;
                t[j + v[i]] = v[i];
            }
        }
    }
}

void drum8(int t[], int n) {
    if(n > 0 && t[n - 2] > 0) {
        cout << t[n - 1] << " ";
        drum8(t, n - 1);
    }
}

void ex8() {
    int n = 6, v[1000]{}, dim = 0;
    int nr[1000]{}, t[1000]{};
    vecNrSuperPrime(v, n, dim);

    subm8(v,nr,t,n,dim);

    drum8(t, n);
}

//intr-o camera se afla n < 51 pers. Fiecare este nascuta intr-una dintre cele z < 366 zile ale unui an. Det. zilele de
//nastere ale fiecarei pers. a. i. in camera sa existe k perechi de pers. nascute in aceeasi zi.

int ctPerechi(int zi[], int n) {
    int ind = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(i != j && zi[i] == zi[j]) {
                ind++;
            }
        }
    }
    return ind;
}

void subm9(int zi[], int n, int z, int k, int ind) {

    if(ind > n) {
        return;
    }
    if(ctPerechi(zi,ind) == k && ind == n) {
        afisVec(zi,ind);
        return;
    }

    for(int i = 0; i < z; i++) {
        zi[ind] = i + 1;
        if(ctPerechi(zi,ind) <= k) {
            subm9(zi,n,z,k,ind + 1);
        }
    }
}

void ex9() {
    int n = 5, z = 20, k = 4;
    int zi[50]{};

    subm9(zi,n,z,k,0);
}

//se considera un triunghi ce contine n linii, pe fiecare aflandu-se valori de cel mult 2 cifre. Sa se realizeze un program
//care det. un drum format din n val. de suma max., care incepe cu nr. de pe prima lin. si se termina cu o val. de pe ultima
//lin. Daca nr. x se afla pe drum, atunci urmatoarea valoare de pe drum este situata in triunghi pe lin. urmatoare, fie sub x,
//fie la st. sau la dr. lui x.

void ex10() {
    int n = 4;
    int mat[100][100]{{2},{3,4},{3,2,5},{8,1,3,2}};

}

void ex11() {

}

//realizati un program care det. nr. de val. nat. formate cu n <= 10 cif. din multimea{1,2,3,4}, a. i. cif. 1 si 2 sa nu
//se afle pe poz. alaturate

bool valid(int s[], int k) {
    if(k > 0 && (s[k - 1] == 1 && s[k] == 2) || (s[k - 1] == 2 && s[k] == 1)) {
        return false;
    }
    return true;
}

void back(int s[], int v[], int n, int k, int&nrSol) {
    if(k == n) {
        nrSol++;
        afisVec(s,n);
        return;
    }

    for(int i = 0; i < 4; i++) {
        s[k] = v[i];
        if(valid(s,k)) {
            back(s,v,n,k + 1, nrSol);
        }
    }
}

void ex12() {
    int v[]{1,2,3,4}, n = 3, s[10], nrSol = 0;

    back(s,v,n,0,nrSol);
    cout << nrSol << endl;
}


#endif //EXERCITII_H
