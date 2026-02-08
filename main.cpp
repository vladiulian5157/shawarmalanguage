#include <iostream>
#include <cstdio>
#include "parser.tab.h" 

using namespace std;

extern FILE* yyin; 
extern int yyparse();

int main(int argc, char** argv) {
    FILE* input = nullptr;

    if (argc > 1) {
        input = fopen(argv[1], "r");
        if (!input) {
            cerr << "[Eroare] Nu s-a putut deschide fisierul: " << argv[1] << endl;
            return 1;
        }
        yyin = input;
        cout << "Compilare fisier: " << argv[1] << "..." << endl;
    } else {
        cout << "Introduceti codul programului (Ctrl+D / Ctrl+Z pentru a termina):" << endl;
    }

    // initializam structurile de date
    initSymbolTables();

    // pornim procesul de parsare
    int result = yyparse();

    if (input) fclose(input);

    if (result == 0) {
        printAllTables("tables.txt");
        cout << "\n[Succes] Programul a fost parsat si evaluat cu succes." << endl;
        cout << "Tabelele de simboluri au fost salvate in 'tables.txt'." << endl;
    } else {
        cout << "\n[Eroare] Compilarea a esuat." << endl;
    }

    return 0;
}