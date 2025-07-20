#include <iostream>
#include <windows.h>
#include "funkcje.h"
#include <conio.h>

using namespace std;
int main() {
    system();
    system("color F5"); //zmienia kolor czcionki i tła konsoli
    int wybor;
    char decyzja;
    while (true) {
        przywitanie("Ktory wariant wisielca wybierasz?");
        cout << "Znajac kategorie i dlugosc hasla twoim zadaniem jest zgadnac jak najszybciej haslo!" << endl;
        cout << "W kazdym trybie scigasz sie z komputerem kto szybciej zgadnie haslo." << endl<<endl;
        cout << "1. Gra w jednego wisielca z losowym haslem." << endl;
        cout << "2. Gra w dwa wisielce z losowym haslem." << endl;
        cout << "3. Gra w jednego wisielca, ale uzytkownik podaje haslo" << endl;
        cout << "4. Wyjdz z gry" << endl;
        cin >> wybor;
        clear_screen(); //czyści ekran

        bool losowanie = false;
        if (wybor == 1 || wybor == 2) {
            losowanie = losowanie_kategoria();
        }

        switch (wybor) {
        case 1:
            clear_screen();
            wisielec_losowe_haslo(losowanie);
            break;
        case 2:
            clear_screen();
            wisielce_losowe_haslo(losowanie);
            break;
        case 3:
            clear_screen();
            wisielec_haslo();
            break;
        case 4:
            cout << "Dziekujemy za gre! Do Zobaczenia!" << endl;
            break;
        default:
            cout << "Nie ma takiej opcji w menu" << endl;

        }
        wcout << "Czy chcesz kontynuować? (t/n)  ";
        cin >> decyzja;
        if (decyzja == 't' || decyzja == 'T')
        {
            continue;
        }
        else if (decyzja == 'n' || decyzja == 'N') {
            cout << "Dziekujemy za gre!";
            break;
        }
        else
            cout << "Niepoprawny znak. Zakonczono gre";
    }
    return 0;
}