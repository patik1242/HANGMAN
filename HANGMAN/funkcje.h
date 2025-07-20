#pragma once
#include <iostream>
#include <vector>
#include <fstream>
void przywitanie(std::string message);
void obraz(int bledy);
void status(const std::vector<char>& litery_gracz);
void wygrana(std::string& slowo, std::string& odp_gracz, std::string& odp_komputer, int zle_gracz, int zle_komputer);
void wygrana1(std::string& slowo, std::string& odp, bool tura_gracza);
void wisielce_losowe_haslo(bool losuj_kategorie);
void wisielec_losowe_haslo(bool losuj_kategorie);
void wisielec_haslo();
void clear_screen();
std::vector<std::string>wybierzKategorie(bool losuj, std::string& kategoria);
std::vector<std::string>losowanie_slowa(std::string plik);
std::string losujSlowoZKategorii(std::vector<std::string> slowa);
bool losowanie_kategoria();
void pokaz_obrazki(int bledy_gracz, int bledy_komputer);
void system();
