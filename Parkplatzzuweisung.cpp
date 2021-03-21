#include <iostream>
#include <windows.h>
#include <stdlib.h>

#define GRUEN           0x0002
#define ROT             0x0004
#define NORMAL          0x0007
#define HELLBLAU        0x0009

using namespace std;

const int i_anzahl_parkplaetze = 50;
// Globales array zum Speichern der Parkplaetze
int LKW_P[i_anzahl_parkplaetze] = {0, 1, 0, 1, 0, 2};

void Statusuebersicht(); //Funktion zur Ausgabe aller Parkplätze, Belegungsstatus 
void Farbe(WORD color);  //Funktion zum Setzen der Ausgabefarben des Textes
void Parkplatzbelegung();//Funktion zur Abfrage und Belegung eines Parkplatzes

// main Funktion, in der die Parkplatzverwaltung organisiert wird
int main() {
    // Endlosschleife um die Parkplatzverwaltung dauerhaft laufen zu lassen.
    while (1) {
        // Ausgabe des Status der Parkplätze
        Statusuebersicht();

        // Belegung eines Parkplatzes
        Parkplatzbelegung();
    }
    return 0;
}

// Gibt den Status eines Parkplatzes aus
void Statusuebersicht() {
    // Ausgabe Status der Parkplaetze
    // 0: frei in gruen
    // 1: belegt rot
    // 2: reserviert in blau

    for (int i = 0; i < i_anzahl_parkplaetze; ++i) {
        cout << "P-Nr: " + to_string(i) + " = ";

        switch (LKW_P[i]) {
            case 0:
                cout << "              ";
                break;
            case 1:
                Farbe(ROT);
                cout << "belegt        ";
                break;
            case 2:
                Farbe(HELLBLAU);
                cout << "reserviert    ";
                break;
            case 3:
                Farbe(GRUEN);
                cout << "frei          ";
                break;
        }

        if ((i % 3) == 0) {
            cout << endl;
        }
        Farbe(NORMAL);
    }
    cout << endl;
}


void Parkplatzbelegung() {
    // Variable zur Auswahl der Parkplaetze
    int i_parkplatz_auswahl = 0;
    // Parkplatzbelegung
    cout << "Welchen Parkplatz wollen Sie belegen?  ";
    cin >> i_parkplatz_auswahl;

    // Je nach Benutzerauswahl wird ein anderes Element des arrays modifiziert
    if (i_parkplatz_auswahl < 0 || i_parkplatz_auswahl >= i_anzahl_parkplaetze) {
        cout << "Dieser Parkplatz existiert (noch) nicht!" << endl;
        return;
    }

    // Ein Parkplatz kann nur gebucht werden, wenn er frei ist.
    if (LKW_P[i_parkplatz_auswahl] == 0) {
        cout << "Sie haben Parkplatz " + to_string(i_parkplatz_auswahl) + " gebucht" << endl;
        LKW_P[i_parkplatz_auswahl] = 1;
    } else {
        cout << "Parkplatz " + to_string(i_parkplatz_auswahl) + " kann nicht gebucht werden" << endl;
    }
}

//Funktion zum Setzen der Ausgabefarben des Textes
void Farbe(WORD color) {
    SetConsoleTextAttribute(::GetStdHandle(STD_OUTPUT_HANDLE), color);
}
