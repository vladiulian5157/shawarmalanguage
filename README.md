# shawarmalanguage
A basic language, made with bison and flex

It is required to have a linux distro/wsl and to install flex and bison packages and a compiler for basic compilation with gcc/g++.
lexer.l is used to tokenize input source code (identifiers, numbers, operators, etc).
parser.y is used to parse the tokens using a well-defined grammar
Shaorma is the executable compilated. In order to run: ./shaorma inputOK.txt
The text file can be replaced with any other textfile which is the actual code.
