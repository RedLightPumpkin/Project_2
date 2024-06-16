#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

struct STUDENT{
    string Imie_Nazwisko;
    int oceny[6];
    float srednia_ocena;
    string ocena_koncowa;
}student;

float oblicz_sred(int tab[]){
    float suma = 0;
    for(int i = 0; i < 6; i++){
        suma += tab[i];
    }
    return round((suma / 6) * 100) / 100;
}

void sred_sred(vector<STUDENT>& studenci){
    float suma = 0;
    int ilosc_studentow = 0;
    for(const auto& student : studenci){
        suma += student.srednia_ocena;
    }
    float srednia_srednich = round((suma / studenci.size()) * 100) / 100;
    for(const auto& student : studenci) {
        if(student.srednia_ocena > srednia_srednich){
            ilosc_studentow += 1;
        }
    }
    cout <<"Srednia srednich ocen wszystkich studentow wynosi "<< srednia_srednich << ". Studentow powyzej sredniej jest " << ilosc_studentow << endl;
}

void najwyzsza_srednia(vector<STUDENT>& studenci) {
    float najw_sred = 0;
    for (const auto &student: studenci) {
        if (student.srednia_ocena > najw_sred) {
            najw_sred = student.srednia_ocena;
        }
    }
    cout << "Najwyzsza srednia wynosi " << najw_sred << endl;

    ofstream myfile2("najlepszy_student.txt");

    for (const auto &student: studenci) {
        if (student.srednia_ocena == najw_sred) {
            cout << "Posiada ja " << student.Imie_Nazwisko << endl;
            cout << "Z ocenami: ";
            for (int i = 0; i < 6; ++i) {
                cout << student.oceny[i] << " ";
            }
            cout << endl;


            myfile2 << "Posiada ja " << student.Imie_Nazwisko << endl;
            myfile2 << "Z ocenami: ";
            for (int i = 0; i < 6; ++i) {
                myfile2 << student.oceny[i] << " ";
            }
            myfile2 << endl;
        }
    }

    myfile2.close();
}

void wyszukaj_studenta_imie(const vector<STUDENT>& studenci, const string& x) {
    bool found = false;

        for (const auto &student: studenci) {
            if (student.Imie_Nazwisko == x) {
                found = true;
                cout << "Student: " << student.Imie_Nazwisko << endl;
                cout << "Oceny: ";
                for (int i = 0; i < 6; i++) {
                    cout << student.oceny[i] << " ";
                }
                cout << endl;
                cout << "Srednia ocena: " << student.srednia_ocena << endl;
                cout << "Ocena koncowa: " << student.ocena_koncowa << endl;
                break;
            }
        }
        if (!found) {
            cout << "Nie znaleziono danego studenta!" << endl;
        }
    }

void wyszukaj_studenta_srednia(const vector<STUDENT>& studenci, const float& x) {
    bool found = false;

    for (const auto &student: studenci) {
        if (student.srednia_ocena == x) {
            found = true;
            cout << "Student: " << student.Imie_Nazwisko << endl;
            cout << "Oceny: ";
            for (int i = 0; i < 6; i++) {
                cout << student.oceny[i] << " ";
            }
            cout << endl;
            cout << "Srednia ocena: " << student.srednia_ocena << endl;
            cout << "Ocena koncowa: " << student.ocena_koncowa << endl;
            break;
        }
    }
    if (!found) {
        cout << "Nie znaleziono studenta z dana srednia!" << endl;
    }
}

void dodaj_studenta(vector<STUDENT>& studenci, int x) {
    ofstream myfile3("studenci.txt", ios::app);
    string imie_nazwisko;
    int ocena;

    cin.ignore();

    for(int i = 0; i < x; i++) {
        myfile3 << "\n";
        cout << "Wprowadz imie i nazwisko studenta: ";
        getline(cin, imie_nazwisko);
        myfile3 << imie_nazwisko << endl;

        cout << "Wprowadz oceny studenta (6 ocen): ";
        for(int j = 0; j < 6; j++) {
            cout << "Wprowadz ocene: ";
            cin >> ocena;
            myfile3 << ocena << " ";
        }


        cin.ignore();

        if (i < x - 1) {
            myfile3 << endl;
        }
    }

    myfile3.close();
}

void wczytaj_dane(vector<STUDENT>& studenci){
    ifstream myfile("studenci.txt");
    string linijka;
    if(!myfile.is_open()){
        cout << "Nie mozna odnalezc pliku" << endl;
        return;
    }
    while(getline(myfile, linijka)) {
        STUDENT student;
        student.Imie_Nazwisko = linijka;
        bool oceny = true;

        for(int i = 0; i < 6; i++) {
            if (!(myfile >> student.oceny[i])) {
                oceny = false;
                break;
            }
        }

        if(!oceny){
            break;
        }
        myfile.ignore(1000, '\n');

        student.srednia_ocena = oblicz_sred(student.oceny);

        if(student.srednia_ocena <= 50){
            student.ocena_koncowa = "NZAL";
        }
        else if(student.srednia_ocena > 50 && student.srednia_ocena <= 60){
            student.ocena_koncowa = "DST";
        }
        else if(student.srednia_ocena > 60 && student.srednia_ocena <= 70){
            student.ocena_koncowa = "DST+";
        }
        else if(student.srednia_ocena > 70 && student.srednia_ocena <= 80){
            student.ocena_koncowa = "DB";
        }
        else if(student.srednia_ocena > 80 && student.srednia_ocena <= 90){
            student.ocena_koncowa = "DB+";
        }
        else if(student.srednia_ocena > 90){
            student.ocena_koncowa = "BDB";
        }
        studenci.push_back(student);
    }
    myfile.close();
}

int main() {
    int wybor;
    string szuk_imie;
    float szuk_sred;
    vector<STUDENT> studenci;
    wczytaj_dane(studenci);
    for (const auto& student : studenci) {
        cout << "Imie i Nazwisko: " << student.Imie_Nazwisko << endl;
        cout << "Oceny: ";
        for(int i = 0; i < 6; ++i) {
            cout << student.oceny[i] << " ";
        }
        cout << endl;
        cout << "Srednia ocen: " << student.srednia_ocena << endl;
        cout << "Ocena koncowa: "<< student.ocena_koncowa << endl;
    }
    cout << "----------------------------------------------"<< endl;
    sred_sred(studenci);
    cout << "----------------------------------------------"<< endl;
    najwyzsza_srednia(studenci);

    char wybor_szukanie;
    cout << "Czy chcesz wyszukac konkretnego studenta? (T/N)" << endl;
    cin >> wybor_szukanie;
    if(wybor_szukanie == 'T' || wybor_szukanie == 't'){
        cout << "Za pomoca jakich danych chesz szukac? "<<endl;
        cout << "1 - Imie i Nazwisko;"<<endl;
        cout << "2 - Srednia;"<<endl;
        cin >> wybor;
        cin.ignore();

        if(wybor == 1){
            cout << "Podaj Imie I nazwisko studenta "<<endl;
            getline(cin, szuk_imie);
            wyszukaj_studenta_imie(studenci,szuk_imie);
        }
        else if(wybor == 2){
            cout << "Podaj srednia studenta: ";
            cin >> szuk_sred;
            wyszukaj_studenta_srednia(studenci,szuk_sred);
        }
    }

    char wybor_dodaj;
    cout << "Czy chcesz dodac dodatkowych studentow? (T/N): ";
    cin >> wybor_dodaj;
    if(wybor_dodaj == 'T' || wybor_dodaj == 't'){
        int ilosc;
        cout << "Ilu studentow chcesz dodac?: ";
        cin >> ilosc;
        dodaj_studenta(studenci, ilosc);
    }

    return 0;
}