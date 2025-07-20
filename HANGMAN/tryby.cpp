#include "funkcje.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <fstream>
#include <windows.h>
using namespace std;

void wisielec_haslo() {
    system();
    przywitanie("URATUJ SWOJEGO PRZYJACIELA PRZEZ ZGADNIECIE HASLA");
    cout << endl << endl;
    string slowo = "";
    cout << "Podaj haslo: " << endl;
    cin >> slowo;
    string odp = "";
    for (int i = 0; i < slowo.length(); i++) {  //pętla dodaje _ tyle ile jest liter w haśle
        odp += "_";
    }
    int zle{};
    char litera;

    vector<char>bledne_litery;
    vector<char>uzyte_litery;

    cout << "Haslo sklada sie z: " << slowo.length() << " liter. " << endl;
    cout << "Twoje aktualne haslo: " << odp << endl;

    bool tura_gracza = true;


    while (odp != slowo && zle < 12) { //wykonuje pętle do momentu, aż nie zostanie odgadnięte hasło albo użytkownik, komputer nie popełni 12 błędów

        cout << endl << endl;
        obraz(zle); //pokazuje wisielca
        cout << endl << endl;
        status(bledne_litery); //pokazuje błędne literki
        cout << endl << endl;

        cout << endl;
        if (tura_gracza) {
            cout << "Podaj litere: ";
            cin >> litera;
            litera = tolower(litera); //zmienia wielkość litery na małą, jeśli użytkownik poda wielką literę
            cout << endl;
        }
        else if (!tura_gracza) {
            cout << "Komputer wybiera literke..." << endl;
            this_thread::sleep_for(chrono::seconds(1)); //wstrzymuje działanie programu na sekundę
            vector<char>brakuje_litery;
            for (int i = 0; i < slowo.size(); i++) {
                if (odp.find(slowo[i]) == string::npos) {
                    brakuje_litery.push_back(slowo[i]);  //przechowuje litery z hasła, które nie zostały odgadniete
                }
            }
            bool litera_juz_uzyta;
            do {
                litera = rand() % 26 + 'a'; //losuje litery z alfabetu angielskiego
                litera_juz_uzyta = false;

                for (int i = 0; i < uzyte_litery.size(); i++) { //pętla sprawdza czy litera znajduje sie w vectorze uzyte_litery
                    if (litera == uzyte_litery[i]) {
                        litera_juz_uzyta = true; 
                        break;
                    }
                }

            } while (litera_juz_uzyta);

            clear_screen();
            cout << "Komputer wybral: " << litera << endl;

        }
        

        uzyte_litery.push_back(litera); //dodaje użyte litery do wektora uzyte_litery

        bool trafiona = false;

        for (int i = 0; i < slowo.length(); i++) { //sprawdza czy litera wystepuje w slowie i wstawia w odpowiednie miejsce w ciągu odp
            if (litera == slowo[i]) {
                odp[i] = litera;
                trafiona = true;
            }
        }
        if (trafiona) {
            cout << "Dobra litera" << endl;
        }
        else {
            cout << "Zla litera" << endl;
            bledne_litery.push_back(litera); //dodaje błędne litery do wektora bledne_litery 
            zle++; //zwiększa licznik błędów złe o 1
        }
        cout << endl << endl;
        cout << "Aktualny stan: " << odp << endl;
        tura_gracza = !tura_gracza;
    }
    wygrana1(slowo, odp, tura_gracza);
}
void wisielec_losowe_haslo(bool losuj_kategorie) {
    system();
    srand(time(nullptr));
    przywitanie("URATUJ SWOJEGO PRZYJACIELA PRZEZ ZGADNIECIE HASLA");
    string kategoria;
    vector<string> slowa = wybierzKategorie(losuj_kategorie, kategoria); //wybiera kategorie poprzez funkcje wybierzKategorie
    string slowo = slowa[rand() % slowa.size()]; //losuje jedno slowo z listy słów
    string odp = "";
    for (int i = 0; i < slowo.length(); i++) {
        odp += "_";
    }
    int zle{};
    char litera;

    vector<char>bledne_litery;
    vector<char>uzyte_litery;

    cout << "Haslo składa się z: " << slowo.length() << " liter. " << endl;
    cout << "Twoje aktualne haslo: " << odp << endl;
    cout << kategoria << endl;

    bool tura_gracza = true;


    while (odp != slowo && zle < 12) {
        cout << endl << endl;
        obraz(zle);
        cout << endl << endl;
        status(bledne_litery);
        cout << endl << endl;


        cout << endl;
        if (tura_gracza) {
            cout << "Podaj litere: ";
            cin >> litera;
            litera = tolower(litera);
            cout << endl;
        }
        else if (!tura_gracza) {
            cout << "Komputer wybiera literke..." << endl;
            this_thread::sleep_for(chrono::seconds(1));
            vector<char>brakuje_litery;
            for (int i = 0; i < slowo.size(); i++) {
                if (odp.find(slowo[i]) == string::npos) {
                    brakuje_litery.push_back(slowo[i]);
                }
            }
            bool litera_juz_uzyta;
            do {
                litera = rand() % 26 + 'a';
                litera_juz_uzyta = false;

                for (int i = 0; i < uzyte_litery.size(); i++) {
                    if (litera == uzyte_litery[i]) {
                        litera_juz_uzyta = true;
                        break;
                    }
                }

            } while (litera_juz_uzyta);
            clear_screen();
            cout << kategoria << endl; //wyświetla kategorie
            cout << endl << endl;
            cout << "Komputer wybral: " << litera << endl;
        }

        uzyte_litery.push_back(litera);

        bool trafiona = false;

        for (int i = 0; i < slowo.length(); i++) {
            if (litera == slowo[i]) {
                odp[i] = litera;
                trafiona = true;
            }
        }
        if (trafiona) {
            cout << "Dobra litera" << endl;
        }
        else {
            cout << "Zla litera" << endl;
            bledne_litery.push_back(litera);
            zle++;
        }
        cout << endl << endl;
        cout << "Aktualny stan: " << odp << endl;
        tura_gracza = !tura_gracza;
    }
    wygrana1(slowo, odp, tura_gracza);
}
void wisielce_losowe_haslo(bool losuj_kategorie) {
    system();
    przywitanie("URATUJ SWOJEGO PRZYJACIELA PRZEZ ZGADNIECIE HASLA");
    srand(time(nullptr));
    string kategoria;
    vector<string> slowa = wybierzKategorie(losuj_kategorie, kategoria);
    string slowo = slowa[rand() % slowa.size()];

    string odp_gracz = "";
    string odp_komputer = "";
    string odp = "";

    for (int i = 0; i < slowo.length(); i++) {
        odp += "_";
    }
    for (int i = 0; i < slowo.length(); i++) {
        odp_gracz += "_";
    }
    for (int i = 0; i < slowo.length(); i++) {
        odp_komputer += "_";
    }
    int zle_gracz{};
    int zle_komputer{};
    char litera_gracz;
    char litera_komputer;

    vector<char>bledne_litery_gracz;
    vector<char>bledne_litery_komputer;
    vector<char>uzyte_litery_gracz;
    vector<char>uzyte_litery_komputer;

    cout << "Haslo sklada sie z: " << slowo.length() << " liter. " << endl;
    cout << kategoria << endl;

    bool tura_gracza = true;
  


    while ((odp_gracz != slowo && odp_komputer != slowo) && (zle_gracz < 12 && zle_komputer < 12)) {

        cout << endl << endl;
        cout << "---------------------------------------------------------------------------------------" << endl << endl;
        cout << "GRACZ";
        cout << endl << endl;
        obraz(zle_gracz);
        cout << endl << endl;
        status(bledne_litery_gracz);
        cout << endl << endl;
        cout << "Aktualny stan gracza: " << odp_gracz;
        cout << endl << endl;
        cout << "---------------------------------------------------------------------------------------" << endl << endl;
        cout << "KOMPUTER";
        cout << endl << endl;
        obraz(zle_komputer);
        cout << endl << endl;
        status(bledne_litery_komputer);
        cout << endl << endl;
        cout << "Aktualny stan komputera: " << odp_komputer;
        cout << endl << endl;


        if (tura_gracza) {
            cout << "Podaj litere: ";
            cin >> litera_gracz;
            litera_gracz = tolower(litera_gracz);
            cout << endl;

            uzyte_litery_gracz.push_back(litera_gracz);

            bool trafiona = false;

            for (int i = 0; i < slowo.length(); i++) {
                if (litera_gracz == slowo[i]) {
                    odp_gracz[i] = litera_gracz;
                    trafiona = true;
                }
            }
            if (trafiona) {
                cout << "Dobra litera" << endl;
            }
            else {
                cout << "Zla litera" << endl;
                bledne_litery_gracz.push_back(litera_gracz);
                zle_gracz++;
            }
        }

        else if (!tura_gracza) {
            cout << "Komputer wybiera literke..." << endl;
            this_thread::sleep_for(chrono::seconds(1));
            bool litera_juz_uzyta;
            do {
                litera_komputer = rand() % 26 + 'a';
                litera_juz_uzyta = false;

                for (int i = 0; i < uzyte_litery_komputer.size(); i++) {
                    if (litera_komputer == uzyte_litery_komputer[i]) {
                        litera_juz_uzyta = true;
                        break;
                    }
                }

            } while (litera_juz_uzyta);
            clear_screen();
            cout << kategoria << endl;
            cout << endl << endl;
            cout << "Komputer wybral: " << litera_komputer << endl;
            uzyte_litery_komputer.push_back(litera_komputer);

            bool trafiona = false;

            for (int i = 0; i < slowo.length(); i++) {
                if (litera_komputer == slowo[i]) {
                    odp_komputer[i] = litera_komputer;
                    trafiona = true;
                }
            }

            if (trafiona) {
                cout << "Dobra litera" << endl;
            }
            else {
                cout << "Zla litera" << endl;
                bledne_litery_komputer.push_back(litera_komputer);
                zle_komputer++;
            }
        }

        tura_gracza = !tura_gracza;
    }

    wygrana(slowo, odp_gracz, odp_komputer, zle_gracz, zle_komputer);
}
