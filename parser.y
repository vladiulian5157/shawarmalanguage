%{
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <cstdlib>

using namespace std;

extern int yylex();
extern int yylineno;
void yyerror(const char* s);
%}


%code requires {
    #include <iostream>
    #include <string>
    #include <vector>
    #include <map>
    using namespace std;

    class SymbolTable;
    struct VarInfo;
    struct FuncInfo;
    struct ParamInfo;
    class ASTNode; 

    struct ParamInfo { string type; string name; };
    struct VarInfo { string name; string type; string value; };
    struct FuncInfo { string name; string returnType; vector<ParamInfo> params; };

    class SymbolTable {
    public:
        string scopeName;
        SymbolTable* parinte;
        map<string, VarInfo> vars;
        map<string, FuncInfo> funcs;
        map<string, SymbolTable*> children;

        SymbolTable(const string& name, SymbolTable* parentScope = nullptr)
            : scopeName(name), parinte(parentScope) {}

        void addVariable(const string& name, const string& type, const string& value = "") {
            if (vars.count(name)) return;
            vars[name] = VarInfo{name, type, value};
        }

        void addFunction(const string& name, const string& retType, const vector<ParamInfo>& params) {
            if (funcs.count(name)) return;
            funcs[name] = FuncInfo{name, retType, params};
        }

        void addChild(SymbolTable* child) { children[child->scopeName] = child; }

        void updateVariable(const string& name, const string& val) {
            SymbolTable* t = this;
            while (t) {
                if (t->vars.count(name)) {
                    t->vars[name].value = val;
                    return;
                }
                t = t->parinte;
            }
        }

        void print(ostream& out, int indent = 0) const {
            string ind(indent, ' ');
            out << ind << "---SCOPE: " << scopeName << "---\n";
            if (!vars.empty()) {
                out << ind << "   Variabile:\n";
                for (auto& v : vars)
                    out << ind << "     " << v.second.name << " : " << v.second.type << " = " << v.second.value << "\n";
            }
            if (!funcs.empty()) {
                out << ind << "   Functii:\n";
                for (auto& f : funcs) out << ind << "     " << f.second.name << "\n";
            }
            out << "\n";
            for (auto& c : children) c.second->print(out, indent + 2);
        }
    };

    /* sa nu dea multiple definition eroare */
    extern SymbolTable* globalTable;
    extern SymbolTable* currentTable;
    extern vector<SymbolTable*> allTables;
    extern vector<ParamInfo> currentParams;
    extern vector<vector<string>> argTypeVector;
    extern bool semanticOK;

    void semanticError(const string& msg);
    VarInfo* lookupVar(const string& name, SymbolTable* start);
    FuncInfo* lookupFunc(const string& name, SymbolTable* start);
    void checkFuncCall(const string& funcName, string& retType);
    void initSymbolTables();
    void printAllTables(const string& filename);
    SymbolTable* findClassScope(const string& className);

    enum ValType { V_INT, V_FLOAT, V_BOOL, V_STRING, V_VOID };
    struct Value {
        ValType type; int iVal; float fVal; bool bVal; string sVal;
        Value() : type(V_VOID), iVal(0), fVal(0), bVal(false) {}
        Value(int v) : type(V_INT), iVal(v), fVal(0), bVal(false) {}
        Value(float v) : type(V_FLOAT), iVal(0), fVal(v), bVal(false) {}
        Value(bool v) : type(V_BOOL), iVal(0), fVal(0), bVal(v) {}
        Value(string v) : type(V_STRING), iVal(0), fVal(0), bVal(false), sVal(v) {}
        
        string toString() {
            if (type == V_INT) return to_string(iVal);
            if (type == V_FLOAT) return to_string(fVal);
            if (type == V_BOOL) return bVal ? "true" : "false";
            if (type == V_STRING) return sVal;
            return "";
        }
    };

    enum NodeType { NODE_OP, NODE_INT, NODE_FLOAT, NODE_BOOL, NODE_STRING, NODE_ID, NODE_ASSIGN, NODE_PRINT, NODE_OTHER, NODE_IF, NODE_WHILE, NODE_BLOCK };

    class ASTNode {
    public:
        NodeType nodeType; string op; Value val; string idName; string tipNod;
        ASTNode *left, *right;
        vector<ASTNode*> children; // PENTRU BLOCURI SI STRUCTURI COMPLEXE

        ASTNode(string oper, ASTNode* l, ASTNode* r, NodeType type = NODE_OP) : nodeType(type), op(oper), left(l), right(r), tipNod("unknown") {}
        ASTNode(Value v, NodeType type) : nodeType(type), val(v), left(nullptr), right(nullptr), tipNod("unknown") {}
        ASTNode(string name) : nodeType(NODE_ID), idName(name), left(nullptr), right(nullptr), tipNod("unknown") {}
        ASTNode(NodeType type, ASTNode* l) : nodeType(type), left(l), right(nullptr), tipNod("void") {}
        
        // constructor pt noduri cu mai multi copii (if while etc)
        ASTNode(NodeType type, vector<ASTNode*> copii) : nodeType(type), left(nullptr), right(nullptr), children(copii), tipNod("void") {}

        Value evaluate() {
            if (nodeType == NODE_INT) return val;
            if (nodeType == NODE_FLOAT) return val;
            if (nodeType == NODE_BOOL) return val;
            if (nodeType == NODE_STRING) return val;
            if (nodeType == NODE_OTHER) {
                if (tipNod == "int" || tipNod == "carne") return Value(0);
                if (tipNod == "float" || tipNod == "cartofi") return Value(0.0f);
                if (tipNod == "bool" || tipNod == "salata") return Value(false);
                if (tipNod == "string" || tipNod == "sos") return Value(string(""));
                return Value();
            }
 

            // blocuri for
            if (nodeType == NODE_BLOCK) {
                for (ASTNode* child : children) {
                    if (child) child->evaluate();
                }
                return Value();
            }

            // blocuri if
            if (nodeType == NODE_IF) {
                // children[0] = conditie, children[1] = thenBlock, children[2] = elseBlock (optional)
                Value cond = children[0]->evaluate();
                if (cond.bVal) {
                    if (children[1]) children[1]->evaluate();
                } else {
                    if (children.size() > 2 && children[2]) children[2]->evaluate();
                }
                return Value();
            }

            // blocuri while
            if (nodeType == NODE_WHILE) {
                // children[0] = conditie, children[1] = body
                while (true) {
                    Value cond = children[0]->evaluate();
                    if (!cond.bVal) break;
                    if (children[1]) children[1]->evaluate();
                }
                return Value();
            }

            if (nodeType == NODE_ID) {  /* verifica variabilele sa fie ok */
                VarInfo* v = lookupVar(idName, currentTable); 
                if (!v) { cout << "Eroare: veriabila " << idName << " nu a fost gasita.\n"; return Value(); }
                if (v->type == "int" || v->type == "carne") {
                    try { return Value(stoi(v->value.empty() ? "0" : v->value)); } catch(...) { return Value(0); }
                }
                if (v->type == "float" || v->type == "cartofi") {
                    try { return Value(stof(v->value.empty() ? "0.0" : v->value)); } catch(...) { return Value(0.0f); }
                }
                if (v->type == "bool" || v->type == "salata") return Value(v->value == "true");
                if (v->type == "string" || v->type == "sos") return Value(v->value);
                return Value();
            }

            if (nodeType == NODE_ASSIGN) {
                Value res = right->evaluate();
                if (currentTable) currentTable->updateVariable(left->idName, res.toString());
                return res;
            }

            if (nodeType == NODE_PRINT) {
                Value res = left->evaluate();
                cout << "[OUTPUT]: " << res.toString() << endl;
                return res;
            }

            if (nodeType == NODE_OP) {
                Value v1 = left->evaluate();
                Value v2 = right->evaluate();

                if (v1.type != v2.type) {
                    cout << "Eroare runtime: operatie intre variabile de tipuri diferite '" << op << "'" << endl;
                    return Value();
                }

                if (op == "+") {
                    if (v1.type == V_INT) return Value(v1.iVal + v2.iVal);
                    if (v1.type == V_FLOAT) return Value(v1.fVal + v2.fVal);
                    if (v1.type == V_STRING) return Value(v1.sVal + v2.sVal);
                }

                if (op == "-") {
                    if (v1.type == V_INT) return Value(v1.iVal - v2.iVal);
                    if (v1.type == V_FLOAT) return Value(v1.fVal - v2.fVal);
                }

                if (op == "*") {
                    if (v1.type == V_INT) return Value(v1.iVal * v2.iVal);
                    if (v1.type == V_FLOAT) return Value(v1.fVal * v2.fVal);
                }

                if (op == "/") {
                    if (v1.type == V_INT) {
                        if (v2.iVal == 0) { cerr << "Eroare: impartire la 0\n"; return Value(); }
                        return Value(v1.iVal / v2.iVal);
                    }
                    if (v1.type == V_FLOAT) {
                        if (v2.fVal == 0.0f) { cerr << "Eroare: impartire la 0\n"; return Value(); }
                        return Value(v1.fVal / v2.fVal);
                    }
                }

                if (op == "<") {
                    if (v1.type == V_INT) return Value(v1.iVal < v2.iVal);
                    if (v1.type == V_FLOAT) return Value(v1.fVal < v2.fVal);
                }

                if (op == ">") {
                    if (v1.type == V_INT) return Value(v1.iVal > v2.iVal);
                    if (v1.type == V_FLOAT) return Value(v1.fVal > v2.fVal);
                }

                if (op == "<=") {
                    if (v1.type == V_INT) return Value(v1.iVal <= v2.iVal);
                    if (v1.type == V_FLOAT) return Value(v1.fVal <= v2.fVal);
                }

                if (op == ">=") {
                    if (v1.type == V_INT) return Value(v1.iVal >= v2.iVal);
                    if (v1.type == V_FLOAT) return Value(v1.fVal >= v2.fVal);
                }

                if (op == "==") {
                    if (v1.type == V_INT) return Value(v1.iVal == v2.iVal);
                    if (v1.type == V_FLOAT) return Value(v1.fVal == v2.fVal);
                    if (v1.type == V_BOOL) return Value(v1.bVal == v2.bVal);
                    if (v1.type == V_STRING) return Value(v1.sVal == v2.sVal);
                }

                if (op == "!=") {
                    if (v1.type == V_INT) return Value(v1.iVal != v2.iVal);
                    if (v1.type == V_FLOAT) return Value(v1.fVal != v2.fVal);
                    if (v1.type == V_BOOL) return Value(v1.bVal != v2.bVal);
                    if (v1.type == V_STRING) return Value(v1.sVal != v2.sVal);
                }

                if (op == "&&") {
                    if (v1.type == V_BOOL) return Value(v1.bVal && v2.bVal);
                    cerr << "Eroare runtime: tip invalid pentru && (se asteapta bool)\n"; return Value();
                }

                if (op == "||") {
                    if (v1.type == V_BOOL) return Value(v1.bVal || v2.bVal);
                    cerr << "Eroare runtime: tip invalid pentru || (se asteapta bool)\n"; return Value();
                }
            }
            return Value();
        }
    };
}

%union {
    int intvalue;
    float floatvalue;
    std::string* stringvalue;
    class ASTNode* node;
    std::vector<class ASTNode*>* vectorStatement;
}

%token <stringvalue> NUMEVAR
%token <intvalue> INT_VAL
%token <floatvalue> FLOAT_VAL
%token <stringvalue> STRING_VAL
%token <intvalue> BOOL_VAL

%token CLASS MAIN IF ELSE WHILE PRINT NEW RETURN
%token TIPDATA_INT TIPDATA_FLOAT TIPDATA_STRING TIPDATA_BOOL TIPDATA_VOID
%token EQ NE LE GE AND OR

%type <stringvalue> tipul_variabilei
%type <node> expresie atribuiri_apeluri print_structura
%type <vectorStatement> interior_main interior_conditie
%type <node> element_main instructiuni if_structura while_structura return_structura
%type <node> variabila_decl obiect_decl sintaxa_conditie

%left OR
%left AND
%left EQ NE
%left '<' '>' LE GE
%left '+' '-'
%left '*' '/'
%right '.'

%start program

%%

program:
    lista_top functie_main { cout << "Validare Semantica reusita.\n"; }
    ;

lista_top:
      lista_top top_item
    | /* empty */
    ;

top_item:
      class_decl
    | functie_decl
    | variabila_decl
    | obiect_decl
    ;

class_decl:
    CLASS NUMEVAR '{'
    {
        string className = "class " + *$2;
        SymbolTable* classTable = new SymbolTable(className, currentTable);
        currentTable->addChild(classTable);
        allTables.push_back(classTable);
        currentTable = classTable;
    }
    interior_clasa
    '}'
    { currentTable = currentTable->parinte; }
    ;

interior_clasa: interior_clasa element_clasa | ;
element_clasa: variabila_decl | obiect_decl | functie_decl ;

functie_decl:
    tipul_variabilei NUMEVAR '(' { currentParams.clear(); } lista_parametri ')'
    {
        string funcName = *$2; string retType = *$1;
        currentTable->addFunction(funcName, retType, currentParams);
        SymbolTable* funcTable = new SymbolTable("function " + funcName, currentTable);
        string parentName = currentTable->scopeName;
            if (parentName.rfind("class ", 0) == 0) {
                string clsType = parentName.substr(6);
                funcTable->addVariable("self", clsType, "null");
            }
        currentTable->addChild(funcTable);
        allTables.push_back(funcTable);
        for (auto& p : currentParams) funcTable->addVariable(p.name, p.type, "0");
        currentTable = funcTable;
    }
    '{' interior_functie '}' { currentTable = currentTable->parinte; }
    |
    NUMEVAR NUMEVAR '(' { currentParams.clear(); } lista_parametri ')'
    {
        string retType = *$1; string funcName = *$2;
        currentTable->addFunction(funcName, retType, currentParams);
        SymbolTable* funcTable = new SymbolTable("function " + funcName, currentTable);
        currentTable->addChild(funcTable);
        allTables.push_back(funcTable);
        for (auto& p : currentParams) funcTable->addVariable(p.name, p.type, "0");
        currentTable = funcTable;
    }
    '{' interior_functie '}' { currentTable = currentTable->parinte; }
    ;

lista_parametri: lista_parametri ',' parametru | parametru | ;
parametru:
    tipul_variabilei NUMEVAR { currentParams.push_back(ParamInfo{ *$1, *$2 }); }
    | NUMEVAR NUMEVAR { currentParams.push_back(ParamInfo{ *$1, *$2 }); }
    ;

interior_functie: interior_functie element_functie | ;
element_functie: instructiuni | variabila_decl | obiect_decl ;

functie_main:
    MAIN '(' ')'
    {
        if(!globalTable) initSymbolTables();
        globalTable->addFunction("main", "void", {});
        SymbolTable* mainTable = new SymbolTable("function main", globalTable);
        globalTable->addChild(mainTable);
        allTables.push_back(mainTable);
        currentTable = mainTable;
    }
    '{' interior_main '}'
    {
        cout << "\n--- Executie Program (Evaluare AST) ---\n";
        vector<ASTNode*>* vectorStatement = $6; /* $6=interior_main */
        if(vectorStatement) {
            for (ASTNode* node : *vectorStatement) {
                if (node) node->evaluate();
            }
        }
        currentTable = currentTable->parinte;
    }
    ;

interior_main:
      interior_main element_main
    {
        $$ = $1;  /* $$ interior main = interior main */
        if ($2 != nullptr) $$->push_back($2);
    }
    | { $$ = new vector<ASTNode*>(); }
    ;

element_main:
      instructiuni { $$ = $1; }
    | variabila_decl { $$ = $1; }
    | obiect_decl { $$ = $1; }
    ;

sintaxa_conditie:
    '{' interior_conditie '}'
    {
        // Impachetam vectorul de instructiuni intr-un nod BLOCK
        $$ = new ASTNode(NODE_BLOCK, *$2);
    }
    ;

interior_conditie:
      interior_conditie element_main
    {
        $$ = $1;
        if ($2 != nullptr) $$->push_back($2);
    }
    | /* empty */ { $$ = new vector<ASTNode*>(); }
    ;

instructiuni:
      if_structura { $$ = $1; }
    | while_structura { $$ = $1; }
    | print_structura { $$ = $1; }
    | return_structura { $$ = nullptr; }
    | atribuiri_apeluri { $$ = $1; }
    ;

/* nodul pentru if */
if_structura:
      IF '(' expresie ')' sintaxa_conditie
    {
        // if fara else: 2 copii (cond, then)
        vector<ASTNode*> copii;
        copii.push_back($3); // conditie
        copii.push_back($5); // bloc then
        $$ = new ASTNode(NODE_IF, copii);
    }
    | IF '(' expresie ')' sintaxa_conditie ELSE sintaxa_conditie
    {
        // if cu else: 3 copii (cond, then, else)
        vector<ASTNode*> copii;
        copii.push_back($3); // if conditie
        copii.push_back($5); // then
        copii.push_back($7); // else
        $$ = new ASTNode(NODE_IF, copii);
    }
    ;

/* === AICI CONSTRUIM NODUL WHILE === */
while_structura:
      WHILE '(' expresie ')' sintaxa_conditie
    {
        vector<ASTNode*> copii;
        copii.push_back($3); // conditie
        copii.push_back($5); // blocul care se repeta
        $$ = new ASTNode(NODE_WHILE, copii);
    }
    ;

atribuiri_apeluri:
    NUMEVAR '=' expresie ';'
    {
        VarInfo* v = lookupVar(*$1, currentTable);
        ASTNode* idNode = new ASTNode(*$1);
        $$ = new ASTNode("=", idNode, $3, NODE_ASSIGN);
    }
    | NUMEVAR '.' NUMEVAR '=' expresie ';'
    {
        VarInfo* obj = lookupVar(*$1, currentTable);
        if (!obj) {
            semanticError("Obiectul '" + *$1 + "' nu este declarat.");
        } else {
            SymbolTable* cls = findClassScope(obj->type);
            if (!cls) {
                semanticError("Tipul '" + obj->type + "' nu este o clasa definita (pentru '" + *$1 + "').");
            } else {
                auto it = cls->vars.find(*$3);
                if (it == cls->vars.end()) {
                    semanticError("Campul '" + *$3 + "' nu exista in clasa '" + obj->type + "'.");
                } else {
                    if ($5 && $5->tipNod != "unknown" && it->second.type != $5->tipNod) {
                        semanticError("Asignare incompatibila: campul '" + *$3 + "' are tip "
                            + it->second.type + " dar expresia are tip " + $5->tipNod + ".");
                    }
                }
            }
        }
        $$ = nullptr; // conform cerintei: AST NULL pentru alte statement-uri
    }
    | NUMEVAR '(' { argTypeVector.push_back(vector<string>()); } arg_lista ')' ';'
    {
        string temp; checkFuncCall(*$1, temp); 
        $$ = new ASTNode(Value(), NODE_OTHER);
    }
    | NUMEVAR '.' NUMEVAR '(' { argTypeVector.push_back(vector<string>()); } arg_lista ')' ';'
    {
        if(!argTypeVector.empty()) argTypeVector.pop_back();
        $$ = new ASTNode(Value(), NODE_OTHER);
    }
    ;

variabila_decl:
      tipul_variabilei NUMEVAR ';'
    {
        string initVal = "0";
        if (*$1 == "string" || *$1 == "sos") initVal = "";
        currentTable->addVariable(*$2, *$1, initVal);
        $$ = nullptr;
    }
    | tipul_variabilei NUMEVAR '=' expresie ';'
    {
        string initVal = "0";
        if (*$1 == "string" || *$1 == "sos") initVal = "";
        currentTable->addVariable(*$2, *$1, initVal);
        ASTNode* idNode = new ASTNode(*$2);
        $$ = new ASTNode("=", idNode, $4, NODE_ASSIGN);
    }
    ;

obiect_decl:
      NUMEVAR NUMEVAR ';'
    {
        currentTable->addVariable(*$2, *$1, "null");
        $$ = nullptr;
    }
    | NUMEVAR NUMEVAR '=' expresie ';'
    {
        currentTable->addVariable(*$2, *$1, "null");
        ASTNode* idNode = new ASTNode(*$2);
        $$ = new ASTNode("=", idNode, $4, NODE_ASSIGN);
    }
    ;

print_structura:
    PRINT '(' expresie ')' ';' { $$ = new ASTNode(NODE_PRINT, $3); }
    ;

return_structura: RETURN expresie ';' ;

arg_lista:
      arg_lista ',' expresie { if (!argTypeVector.empty()) argTypeVector.back().push_back($3->tipNod); }
    | expresie { if (!argTypeVector.empty()) argTypeVector.back().push_back($1->tipNod); }
    | ;

tipul_variabilei:
      TIPDATA_INT    { $$ = new string("int"); }
    | TIPDATA_FLOAT  { $$ = new string("float"); }
    | TIPDATA_STRING { $$ = new string("string"); }
    | TIPDATA_BOOL   { $$ = new string("bool"); }
    | TIPDATA_VOID   { $$ = new string("void"); }
    ;

expresie:
      expresie '+' expresie
        {
            $$ = new ASTNode("+", $1, $3);
            auto norm = [](const string& t)->string{
                if (t=="carne") return "int";
                if (t=="cartofi") return "float";
                if (t=="salata") return "bool";
                if (t=="sos") return "string";
                return t;
            };
            string t1 = norm($1->tipNod), t2 = norm($3->tipNod);
            if (t1 != t2) {
                semanticError("Operatie '+' intre tipuri diferite: " + $1->tipNod + " si " + $3->tipNod + ".");
                $$->tipNod = "unknown";
            } else {
                if (t1 == "bool") {
                    semanticError("Operatia '+' nu este permisa pe bool.");
                    $$->tipNod = "unknown";
                } else {
                    $$->tipNod = $1->tipNod;
                }
            }
        }

        | expresie '-' expresie
        {
            $$ = new ASTNode("-", $1, $3);
            auto norm = [](const string& t)->string{
                if (t=="carne") return "int";
                if (t=="cartofi") return "float";
                if (t=="salata") return "bool";
                if (t=="sos") return "string";
                return t;
            };
            string t1 = norm($1->tipNod), t2 = norm($3->tipNod);
            if (t1 != t2) {
                semanticError("Operatie '-' intre tipuri diferite: " + $1->tipNod + " si " + $3->tipNod + ".");
                $$->tipNod = "unknown";
            } else {
                // '-' permis doar pe numeric
                if (t1 != "int" && t1 != "float") {
                    semanticError("Operatia '-' este permisa doar pe int/float.");
                    $$->tipNod = "unknown";
                } else {
                    $$->tipNod = $1->tipNod;
                }
            }
        }

        | expresie '*' expresie
        {
            $$ = new ASTNode("*", $1, $3);
            auto norm = [](const string& t)->string{
                if (t=="carne") return "int";
                if (t=="cartofi") return "float";
                if (t=="salata") return "bool";
                if (t=="sos") return "string";
                return t;
            };
            string t1 = norm($1->tipNod), t2 = norm($3->tipNod);
            if (t1 != t2) {
                semanticError("Operatie '*' intre tipuri diferite: " + $1->tipNod + " si " + $3->tipNod + ".");
                $$->tipNod = "unknown";
            } else {
                if (t1 != "int" && t1 != "float") {
                    semanticError("Operatia '*' este permisa doar pe int/float.");
                    $$->tipNod = "unknown";
                } else {
                    $$->tipNod = $1->tipNod;
                }
            }
        }

        | expresie '/' expresie
        {
            $$ = new ASTNode("/", $1, $3);
            auto norm = [](const string& t)->string{
                if (t=="carne") return "int";
                if (t=="cartofi") return "float";
                if (t=="salata") return "bool";
                if (t=="sos") return "string";
                return t;
            };
            string t1 = norm($1->tipNod), t2 = norm($3->tipNod);
            if (t1 != t2) {
                semanticError("Operatie '/' intre tipuri diferite: " + $1->tipNod + " si " + $3->tipNod + ".");
                $$->tipNod = "unknown";
            } else {
                if (t1 != "int" && t1 != "float") {
                    semanticError("Operatia '/' este permisa doar pe int/float.");
                    $$->tipNod = "unknown";
                } else {
                    $$->tipNod = $1->tipNod;
                }
            }
        }

        | expresie '<' expresie
        {
            $$ = new ASTNode("<", $1, $3);
            auto norm = [](const string& t)->string{
                if (t=="carne") return "int";
                if (t=="cartofi") return "float";
                if (t=="salata") return "bool";
                if (t=="sos") return "string";
                return t;
            };
            string t1 = norm($1->tipNod), t2 = norm($3->tipNod);
            if (t1 != t2) {
                semanticError("Comparatie '<' intre tipuri diferite: " + $1->tipNod + " si " + $3->tipNod + ".");
            } else {
                // optional: permiti doar numeric la < >
                if (t1 != "int" && t1 != "float") {
                    semanticError("Comparatia '<' este permisa doar pe int/float.");
                }
            }
            $$->tipNod = "bool";
        }

        | expresie '>' expresie
        {
            $$ = new ASTNode(">", $1, $3);
            auto norm = [](const string& t)->string{
                if (t=="carne") return "int";
                if (t=="cartofi") return "float";
                if (t=="salata") return "bool";
                if (t=="sos") return "string";
                return t;
            };
            string t1 = norm($1->tipNod), t2 = norm($3->tipNod);
            if (t1 != t2) {
                semanticError("Comparatie '>' intre tipuri diferite: " + $1->tipNod + " si " + $3->tipNod + ".");
            } else {
                if (t1 != "int" && t1 != "float") {
                    semanticError("Comparatia '>' este permisa doar pe int/float.");
                }
            }
            $$->tipNod = "bool";
        }

        | expresie LE expresie
        {
            $$ = new ASTNode("<=", $1, $3);
            auto norm = [](const string& t)->string{
                if (t=="carne") return "int";
                if (t=="cartofi") return "float";
                if (t=="salata") return "bool";
                if (t=="sos") return "string";
                return t;
            };
            string t1 = norm($1->tipNod), t2 = norm($3->tipNod);
            if (t1 != t2) {
                semanticError("Comparatie '<=' intre tipuri diferite: " + $1->tipNod + " si " + $3->tipNod + ".");
            } else {
                if (t1 != "int" && t1 != "float") {
                    semanticError("Comparatia '<=' este permisa doar pe int/float.");
                }
            }
            $$->tipNod = "bool";
        }

        | expresie GE expresie
        {
            $$ = new ASTNode(">=", $1, $3);
            auto norm = [](const string& t)->string{
                if (t=="carne") return "int";
                if (t=="cartofi") return "float";
                if (t=="salata") return "bool";
                if (t=="sos") return "string";
                return t;
            };
            string t1 = norm($1->tipNod), t2 = norm($3->tipNod);
            if (t1 != t2) {
                semanticError("Comparatie '>=' intre tipuri diferite: " + $1->tipNod + " si " + $3->tipNod + ".");
            } else {
                if (t1 != "int" && t1 != "float") {
                    semanticError("Comparatia '>=' este permisa doar pe int/float.");
                }
            }
            $$->tipNod = "bool";
        }

        | expresie EQ expresie
        {
            $$ = new ASTNode("==", $1, $3);
            auto norm = [](const string& t)->string{
                if (t=="carne") return "int";
                if (t=="cartofi") return "float";
                if (t=="salata") return "bool";
                if (t=="sos") return "string";
                return t;
            };
            string t1 = norm($1->tipNod), t2 = norm($3->tipNod);
            if (t1 != t2) {
                semanticError("Comparatie '==' intre tipuri diferite: " + $1->tipNod + " si " + $3->tipNod + ".");
            }
            $$->tipNod = "bool";
        }

        | expresie NE expresie
        {
            $$ = new ASTNode("!=", $1, $3);
            auto norm = [](const string& t)->string{
                if (t=="carne") return "int";
                if (t=="cartofi") return "float";
                if (t=="salata") return "bool";
                if (t=="sos") return "string";
                return t;
            };
            string t1 = norm($1->tipNod), t2 = norm($3->tipNod);
            if (t1 != t2) {
                semanticError("Comparatie '!=' intre tipuri diferite: " + $1->tipNod + " si " + $3->tipNod + ".");
            }
            $$->tipNod = "bool";
        }

        | expresie AND expresie
        {
            $$ = new ASTNode("&&", $1, $3);
            auto norm = [](const string& t)->string{
                if (t=="salata") return "bool";
                return t;
            };
            string t1 = norm($1->tipNod), t2 = norm($3->tipNod);
            if (t1 != "bool" || t2 != "bool") {
                semanticError("Operatie '&&' necesita bool && bool, dar ai: " + $1->tipNod + " si " + $3->tipNod + ".");
            }
            $$->tipNod = "bool";
        }

        | expresie OR expresie
        {
            $$ = new ASTNode("||", $1, $3);
            auto norm = [](const string& t)->string{
                if (t=="salata") return "bool";
                return t;
            };
            string t1 = norm($1->tipNod), t2 = norm($3->tipNod);
            if (t1 != "bool" || t2 != "bool") {
                semanticError("Operatie '||' necesita bool || bool, dar ai: " + $1->tipNod + " si " + $3->tipNod + ".");
            }
            $$->tipNod = "bool";
        }

        | '(' expresie ')' { $$ = $2; }

        | NUMEVAR
        {
            $$ = new ASTNode(*$1);
            VarInfo* v = lookupVar(*$1, currentTable);
            if (!v) {
                semanticError("Identificatorul '" + *$1 + "' nu este declarat.");
                $$->tipNod = "unknown";
            } else {
                $$->tipNod = v->type;
            }
        }

        | NUMEVAR '.' NUMEVAR
        {
            $$ = new ASTNode(Value(), NODE_OTHER);
            $$->tipNod = "unknown";

            VarInfo* obj = lookupVar(*$1, currentTable);
            if (!obj) {
                semanticError("Obiectul '" + *$1 + "' nu este declarat.");
            } else {
                SymbolTable* cls = findClassScope(obj->type);
                if (!cls) {
                    semanticError("Tipul '" + obj->type + "' nu este o clasa definita (pentru '" + *$1 + "').");
                } else {
                    auto it = cls->vars.find(*$3);
                    if (it == cls->vars.end()) {
                        semanticError("Campul '" + *$3 + "' nu exista in clasa '" + obj->type + "'.");
                    } else {
                        $$->tipNod = it->second.type;
                    }
                }
            }
        }
        | INT_VAL   { $$ = new ASTNode(Value($1), NODE_INT);   $$->tipNod = "int"; }
        | FLOAT_VAL { $$ = new ASTNode(Value($1), NODE_FLOAT); $$->tipNod = "float"; }
        | STRING_VAL{ $$ = new ASTNode(Value(*$1), NODE_STRING); $$->tipNod = "string"; }
        | BOOL_VAL  { $$ = new ASTNode(Value((bool)$1), NODE_BOOL); $$->tipNod = "bool"; }

        | NUMEVAR '(' { argTypeVector.push_back(vector<string>()); } arg_lista ')'
        {
            string temp; checkFuncCall(*$1, temp);
            $$ = new ASTNode(Value(), NODE_OTHER);
            $$->tipNod = temp;
        }

        | NEW NUMEVAR '(' ')'
        {
            $$ = new ASTNode(Value(), NODE_OTHER);
            $$->tipNod = *$2; // tipul este numele clasei
        }
        | NUMEVAR '.' NUMEVAR '(' { argTypeVector.push_back(vector<string>()); } arg_lista ')'
        {
            vector<string> args;
            if (!argTypeVector.empty()) args = argTypeVector.back();
            if (!argTypeVector.empty()) argTypeVector.pop_back();

            $$ = new ASTNode(Value(), NODE_OTHER);
            $$->tipNod = "unknown";

            VarInfo* obj = lookupVar(*$1, currentTable);
            if (!obj) {
                semanticError("Obiectul '" + *$1 + "' nu este declarat.");
            } else {
                SymbolTable* cls = findClassScope(obj->type);
                if (!cls) {
                    semanticError("Tipul '" + obj->type + "' nu este o clasa definita (pentru '" + *$1 + "').");
                } else {
                    auto itf = cls->funcs.find(*$3);
                    if (itf == cls->funcs.end()) {
                        semanticError("Metoda '" + *$3 + "' nu exista in clasa '" + obj->type + "'.");
                    } else {
                        FuncInfo& mf = itf->second;
                        if (args.size() != mf.params.size()) {
                            semanticError("Apel invalid la metoda '" + obj->type + "." + *$3
                                + "': nr parametri asteptat " + to_string(mf.params.size())
                                + ", primit " + to_string(args.size()) + ".");
                        } else {
                            for (size_t i = 0; i < args.size(); i++) {
                                if (args[i] != "unknown" && args[i] != mf.params[i].type) {
                                    semanticError("Apel invalid la metoda '" + obj->type + "." + *$3
                                        + "': parametrul " + to_string(i+1) + " asteapta "
                                        + mf.params[i].type + ", primit " + args[i] + ".");
                                }
                            }
                        }
                        $$->tipNod = mf.returnType;
                    }
                }
            }
        }

    ;

%%

void yyerror(const char* s) { cout << "Eroare de sintaxa la linia " << yylineno << ": " << s << endl; }

SymbolTable* globalTable = nullptr;
SymbolTable* currentTable = nullptr;
vector<SymbolTable*> allTables;
vector<ParamInfo> currentParams;
vector<vector<string>> argTypeVector;
bool semanticOk = true;

void semanticError(const string& msg) {
    semanticOk = false;
    cout << "Eroare semantica la linia " << yylineno << ": " << msg << endl;
}


SymbolTable* findClassScope(const string& className) {
    string scopeName = "class " + className;
    if (!globalTable) return nullptr;
    auto it = globalTable->children.find(scopeName);
    if (it != globalTable->children.end()) return it->second;
    return nullptr;
}

VarInfo* lookupVar(const string& name, SymbolTable* start) {
    SymbolTable* t = start;
    while (t) {
        auto it = t->vars.find(name);
        if (it != t->vars.end()) return &it->second;
        t = t->parinte;
    }
    return nullptr;
}

FuncInfo* lookupFunc(const string& name, SymbolTable* start) {
    SymbolTable* t = start;
    while (t) {
        auto it = t->funcs.find(name);
        if (it != t->funcs.end()) return &it->second;
        t = t->parinte;
    }
    return nullptr;
}

void checkFuncCall(const string& funcName, string& retType) {
    FuncInfo* f = lookupFunc(funcName, currentTable);
    if (!f) {
        semanticError("Functia '" + funcName + "' nu este declarata.");
        if(!argTypeVector.empty()) argTypeVector.pop_back();
        retType = "unknown";
        return;
    }

    vector<string> args;
    if (!argTypeVector.empty()) args = argTypeVector.back();
    if(!argTypeVector.empty()) argTypeVector.pop_back();

    if (args.size() != f->params.size()) {
        semanticError("Apel invalid la '" + funcName + "': nr parametri asteptat "
            + to_string(f->params.size()) + ", primit " + to_string(args.size()) + ".");
        retType = f->returnType;
        return;
    }

    for (size_t i = 0; i < args.size(); i++) {
        if (args[i] != "unknown" && args[i] != f->params[i].type) {
            semanticError("Apel invalid la '" + funcName + "': parametrul " + to_string(i+1)
                + " asteapta " + f->params[i].type + ", primit " + args[i] + ".");
        }
    }
    retType = f->returnType;
}

void initSymbolTables() {
    globalTable = new SymbolTable("global", nullptr);
    currentTable = globalTable;
    allTables.push_back(globalTable);
}

void printAllTables(const string& filename) {
    ofstream out(filename);
    if(globalTable) globalTable->print(out);
    out.close();
}
