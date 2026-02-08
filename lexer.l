%{
#include <iostream>
#include <string>
#include <cstring>
#include "parser.tab.h"
using namespace std;
%}

%option noyywrap
%option yylineno

%%

"shaorma"       { return CLASS; }
"carne"         { return TIPDATA_INT; }
"cartofi"       { return TIPDATA_FLOAT; }
"sos"           { return TIPDATA_STRING; }
"salata"        { return TIPDATA_BOOL; }
"dietetic"      { return TIPDATA_VOID; }

"comanda"       { return MAIN; }
"daca_are"      { return IF; }
"fara"          { return ELSE; }
"cat_timp_mananc" { return WHILE; }
"serveste"      { return PRINT; }
"proaspat"      { return NEW; }
"impacheteaza"  { return RETURN; }

"cu_de_toate"   { yylval.intvalue = 1; return BOOL_VAL; }
"fara_nimic"    { yylval.intvalue = 0; return BOOL_VAL; }

[0-9]+\.[0-9]+  { yylval.floatvalue = atof(yytext); return FLOAT_VAL; }
[0-9]+          { yylval.intvalue = atoi(yytext); return INT_VAL; }

\"[^\"]*\"      { 
    // scoatem ghilimelele din string
    yylval.stringvalue = new string(yytext + 1, strlen(yytext) - 2); 
    return STRING_VAL; 
}

[a-zA-Z_][a-zA-Z0-9_]* {
    yylval.stringvalue = new string(yytext);
    return NUMEVAR;
}

"=="        { return EQ; }
"!="        { return NE; }
"<="        { return LE; }
">="        { return GE; }
"&&"        { return AND; }
"||"        { return OR; }

[-+*/=<>;(){},.] { return yytext[0]; }

[ \t\n\r] ;

. { cout << "Eroare lexicala la linia " << yylineno << ": " << yytext << endl; }

%%