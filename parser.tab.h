/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 17 "parser.y"

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

#line 323 "parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUMEVAR = 258,                 /* NUMEVAR  */
    INT_VAL = 259,                 /* INT_VAL  */
    FLOAT_VAL = 260,               /* FLOAT_VAL  */
    STRING_VAL = 261,              /* STRING_VAL  */
    BOOL_VAL = 262,                /* BOOL_VAL  */
    CLASS = 263,                   /* CLASS  */
    MAIN = 264,                    /* MAIN  */
    IF = 265,                      /* IF  */
    ELSE = 266,                    /* ELSE  */
    WHILE = 267,                   /* WHILE  */
    PRINT = 268,                   /* PRINT  */
    NEW = 269,                     /* NEW  */
    RETURN = 270,                  /* RETURN  */
    TIPDATA_INT = 271,             /* TIPDATA_INT  */
    TIPDATA_FLOAT = 272,           /* TIPDATA_FLOAT  */
    TIPDATA_STRING = 273,          /* TIPDATA_STRING  */
    TIPDATA_BOOL = 274,            /* TIPDATA_BOOL  */
    TIPDATA_VOID = 275,            /* TIPDATA_VOID  */
    EQ = 276,                      /* EQ  */
    NE = 277,                      /* NE  */
    LE = 278,                      /* LE  */
    GE = 279,                      /* GE  */
    AND = 280,                     /* AND  */
    OR = 281                       /* OR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 291 "parser.y"

    int intvalue;
    float floatvalue;
    std::string* stringvalue;
    class ASTNode* node;
    std::vector<class ASTNode*>* vectorStatement;

#line 374 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
