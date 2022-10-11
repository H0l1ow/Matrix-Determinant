// macierz Determinant.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include<iostream>
#include<math.h>

using namespace std;

const int maxMatrix = 10;


int wyznacznik(int macierz[maxMatrix][maxMatrix], int n) 
{
    int det = 0;
    int macierz_pomoc[maxMatrix][maxMatrix];
    if (n == 2)                                                                         // Wprzypadku 2 stopnia oblicza macierz poza petla
        return ((macierz[0][0] * macierz[1][1]) - (macierz[1][0] * macierz[0][1]));
    else {
        for (int x = 0; x < n; x++) 
        {
            int subi = 0;
            for (int i = 1; i < n; i++) 
            {
                int subj = 0;                                                           // Algorytm obliczajacy wyznacznik
                for (int j = 0; j < n; j++) 
                {
                    if (j == x)
                        continue;
                    macierz_pomoc[subi][subj] = macierz[i][j];
                    subj++;
                }
                subi++;
            }
            det = det + (pow(-1, x) * macierz[0][x] * wyznacznik(macierz_pomoc, n - 1));        // Uzycie rekurencji
        }
    }
    return det;
}
int main() {
    
    int n, i, j;
    int macierz[maxMatrix][maxMatrix];
    
    cout << "Witam w Programie do obliczania wyznacznika macierzy!!! Az do maxMatrix stopnia!\n";
    cout << "=========================================================================\n\n";
    
    do {
        cout << "Wprowadz wielkosc (stopien) macierzy: "; cin >> n;
        if (n > maxMatrix || n < 2)
        {
            cout << "musisz podac koniecznie z zakresu <2,maxMatrix>" << endl;      // Zabezpieczenie przed zadeklarowaniem zbyt malej lub zbyt duzej macierzy
        }

    } while (n < 2 || n > maxMatrix);
    
    cout << "Wprowadz elementy macierzy jeden po drugim:\n";
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)                                 // Wczytywanie liczb do macierzy
        {
            cin >> macierz[i][j];
        }
    }
    cout << "\nTak wyglada twoja macierz:\n" << endl;
    
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++)
        {
            cout << macierz[i][j] << " ";                       // Wyswietlanie macierzy
        }
        cout << endl;
    }
    cout << "\nWyznacznikiem tej macierzy jest: " << wyznacznik(macierz, n) << endl;
    return 0;
}