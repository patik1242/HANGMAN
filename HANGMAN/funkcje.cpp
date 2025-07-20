#include "funkcje.h"
#include <iomanip>
#include <vector>
#include <string>
#include <cstdlib>
#include <thread>
#include <ctime>
#include <fstream>
#include <windows.h>
using namespace std;
void przywitanie(string message) //wyświetla tytuł gry
{
    system();
    cout << setfill('*') << setw(50) << "*" << endl;
    cout << setfill(' ') << setw(25) << "HANGMAN" << endl;
    cout << setfill('*') << setw(50) << "*" << endl;
    cout << message << endl;
    cout << endl;
}
void obraz(int bledy) { //funkcja odpowiada za wizualizację wisielca
    system();
    if (bledy == 1) {
        cout << "_____\n";
    }
    else if (bledy == 2) {
        cout << "  |\n";
        cout << "  |\n";
        cout << "  |\n";
        cout << "  |\n";
        cout << "_____\n";

    }
    else if (bledy == 3) {
        cout << "  ---------\n";
        cout << "  |\n";
        cout << "  |\n";
        cout << "  |\n";
        cout << "  |\n";
        cout << "_____\n";
    }
    else if (bledy == 4) {
        cout << "  ---------|\n";
        cout << "  |\n";
        cout << "  |\n";
        cout << "  |\n";
        cout << "  |\n";
        cout << "_____\n";
    }
    else if (bledy == 5) {
        cout << "  ---------|\n";
        cout << "  |/\n";
        cout << "  |\n";
        cout << "  |\n";
        cout << "  |\n";
        cout << "_____\n";
    }
    else if (bledy == 6) {
        cout << "  ---------|\n";
        cout << "  |/       O\n";
        cout << "  |\n";
        cout << "  |\n";
        cout << "  |\n";
        cout << "_____\n";
    }
    else if (bledy == 7) {
        cout << "  ---------|\n";
        cout << "  |        O\n";
        cout << "  |        |\n";
        cout << "  |\n";
        cout << "  |\n";
        cout << "_____\n";
    }
    else if (bledy == 8) {
        cout << "  ---------|\n";
        cout << "  |        O\n";
        cout << "  |       /|\n";
        cout << "  |\n";
        cout << "  |\n";
        cout << "_____\n";
    }
    else if (bledy == 9) {
        cout << "  ---------|" << endl;
        cout << "  |        O" << endl;
        cout << "  |       /|\\ " << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "_____" << endl;
    }
    else if (bledy == 10) {
        cout << "  ---------|\n";
        cout << "  |        O" << endl;
        cout << "  |       /|\\" << endl;
        cout << "  |       / " << endl;
        cout << "  |\n";
        cout << "_____\n";
    }
    else if (bledy == 11) {
        cout << "  ---------|\n";
        cout << "  |        O" << endl;
        cout << "  |       /|\\" << endl;
        cout << "  |       / \\ " << endl;
        cout << "  |\n";
        cout << "_____\n";
    }
}
void status(const vector<char>& litery_gracz) //funkcja pokazuje podane błędne literki
{
    system();
    cout << "Bledy: " << endl;
    for (int i = 0; i < litery_gracz.size(); i++) {
        cout << litery_gracz[i] << " ";
    }
}
void wygrana(string& slowo, string& odp_gracz, string& odp_komputer, int zle_gracz, int zle_komputer)
{
    // Komunikat w przypadku odgadnięcia hasła
    if (odp_gracz == slowo) {
        cout << "Gracz odgadl cale haslo i wygrywa!" << endl;
        cout << "Haslo to: " << slowo << endl;
        return;
    }
    else if (odp_komputer == slowo) {
        cout << "Komputer odgadl cale haslo! Przegrywasz..." << endl;
        cout << "Haslo to: " << slowo << endl;
        return;
    }

    // Komunikaty w przypadku przekroczenie limitu błędów
    if (zle_gracz >= 12) {
        cout << "Gracz wyczerpal limit bledow i niestety przegrywa." << endl;
        cout << "Haslo to: " << slowo << endl;
    }
    else if (zle_komputer >= 12) {
        cout << "Komputer wyczerpal limit bledow. Gracz wygrywa!" << endl;
        cout << "Haslo to: " << slowo << endl;
    }
}

void wygrana1(string& slowo, string& odp, bool tura_gracza) {
    system();
    if (!tura_gracza) {
        if (slowo == odp) {
            cout << "Wygrales!!";
        }
        else {
            cout << "Przegraliscie" << endl;
            cout << "Haslo to: " << slowo << endl;
        }
    }
    else {
        if (slowo == odp)
            cout << "Komputer wygral!!";
        else
        {
            cout << "Przegraliscie" << endl;
            cout << "Haslo to: " << slowo << endl;
        }
    }


}
void clear_screen() { //funkcja, która odpowiada za czyszczenie ekranu
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
vector<string>losowanie_slowa(string plik) { //funkcja, która wczytuje zawartość pliku i zapisuje każdą linie jako osobny element wektora kategorie
    system();
    ifstream plik1{};
    plik1.open(plik);
    vector<string> kategorie;
    string text;

    if (plik1.good()) {
        while (!plik1.eof()) {
            getline(plik1, text);
            kategorie.push_back(text);
        }
    }
    else
        cout << "Nie da się otworzyc" << endl;
    plik1.close();
    return kategorie;
}
vector<string>wybierzKategorie(bool losuj, string& kategoria) {  //odpowiada za wybór kategorii słów do gry i odczytanie słów z odpowiedniego pliku
    system();
    string plik;

    if (losuj) {
        srand(time(nullptr));
        int losowaKategoria = rand() % 5 + 1;
        switch (losowaKategoria) {
        case 1:
            plik = "zwierzeta.txt";
            kategoria = "Wylosowana kategoria: Zwierzeta";
            break;
        case 2:
            plik = "jedzenie.txt";
            kategoria = "Wylosowana kategoria: Jedzenie";
            break;
        case 3:
            plik = "uczucia.txt";
            kategoria = "Wylosowana kategoria: Uczucia";
            break;
        case 4:
            plik = "przyroda.txt";
            kategoria = "Wylosowana kategoria: Przyroda";
            break;
        case 5:
            plik = "przedmioty.txt";
            kategoria = "Wylosowana kategoria: Przedmioty";
            break;
        default:
            kategoria = "Nie ma takiej kategorii";
            break;
        }
    }
    else {
        cout << "Wybierz kategorie: " << endl;
        cout << "1. Zwierzeta " << endl;
        cout << "2. Jedzenie " << endl;
        cout << "3. Uczucia " << endl;
        cout << "4. Przyroda " << endl;
        cout << "5. Przedmioty " << endl;
        cout << "Wybierz numer kategorii: ";
        int wybor{};
        cin >> wybor;
        switch (wybor) {
        case 1:
            plik = "zwierzeta.txt";
            kategoria = "Wybrana kategoria: Zwierzeta";
            break;
        case 2:
            plik = "jedzenie.txt";
            kategoria = "Wylosowana kategoria: Jedzenie";
            break;
        case 3:
            plik = "uczucia.txt";
            kategoria = "Wybrana kategoria: Uczucia";
            break;
        case 4:
            plik = "przyroda.txt";
            kategoria = "Wylosowana kategoria: Przyroda";
            break;
        case 5:
            plik = "przedmioty.txt";
            kategoria = "Wylosowana kategoria: Przedmioty";
            break;
        default:
            kategoria = "Nie ma takiej kategorii";
            break;
        }
        clear_screen();
    }
    return losowanie_slowa(plik);
}
void system() { //funkcja odpowiada za działanie polskich znaków
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
}
string losujSlowoZKategorii(vector<string> slowa) { //losuje i zwraca losowe słowa z wektora słowo
    system();
    srand(time(nullptr));
    return slowa[rand() % slowa.size()];
}
bool losowanie_kategoria() { //pyta użytkownika czy kategoria ma być losowana i na podstawie odpowiedzi zwraca wartość logiczna
    system();
    int losuj_kategorie;
    cout << "Czy chcesz, aby kategoria byla losowana? (1 - Tak, 0 - Nie)  ";
    cin >> losuj_kategorie;

    if (losuj_kategorie == 1)
        return true;
    else if (losuj_kategorie == 0)
        return false;
    else {
        cout << "Niepoprawny wybor" << endl;
        return true;
    }

}


