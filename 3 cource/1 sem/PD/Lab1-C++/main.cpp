#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <string>
#include <stack>

#include "operationTree.h"
#include "TokenTree.h"
#include "BoolExpression.h"

std::ifstream fin;
std::string yytext;
int lex_type;

std::vector<Token> tokens;

void PrintTree(TokenNode *node, int tab) {
    if (node) {
        PrintTree(node->left, tab + 1);
        for (int i = 0; i < tab; ++i) {
            std::cout << "    ";
        }
        if (node->token.type == 2) {
            std::cout << node->token.value.o_h << std::endl;
        } else {
            std::cout << node->token.value.f << std::endl;
        }
        PrintTree(node->right, tab + 1);
    }
}

void yylex() {
    std::regex int_reg("-?[1-9][0-9]*");
    std::regex float_reg("-?[0-9]*\\.[0-9]*(e-?[1-9][0-9]*)?");
    std::regex id_reg("_?[a-zA-Z][a-zA-Z0-9]*");
    std::regex operations_reg (R"(\+|\-|\*|\/)");
    std::regex hooks_reg(R"(\(|\))");

    std::string str;

    if (!fin.eof()) {
        fin >> str;
        if (std::regex_match(str, int_reg)) {
            std::cout << "INT" << std::endl;
            lex_type = 1;
            yytext = str;
        } else if (std::regex_match(str, float_reg)) {
            lex_type = 1;
            std::cout << "FLOAT" << std::endl;
            yytext = str;
        } else if (std::regex_match(str, id_reg)) {
            std::cout << "ID" << std::endl;
            yytext = str;
        } else if (std::regex_match(str, operations_reg)) {
            lex_type = 2;
            std::cout << "OPERATION" << std::endl;
            yytext = str;
        } else if (std::regex_match(str, hooks_reg)) {
            lex_type = 3;
            std::cout << "HOOK" << std::endl;
            yytext = str;
        } else {
            std::cout << "UNDEFINED" << std::endl;
            yytext = "";
        }

        str = "";
    }
}

void AddToken(int type, token_values value) {
    Token new_token;
    new_token.type = type;

    switch (new_token.type) {
        case 1: {
            new_token.value.f = value.f;
            break;
        }

        case 2: {
            new_token.value.o_h = value.o_h;
            break;
        }

        case 3: {
            new_token.value.o_h = value.o_h;
            break;
        }

        default:
            break;
    }

    tokens.push_back(new_token);
}

std::string lexType(std::string lex)
{
    if(lex == "begin" || lex == "if" || lex == "while" || lex == "do" || lex == "then" || lex == "else" || lex == ":=")
    {
        return "operation";
    }
    else if (lex == "end" || lex == ";" || lex == "." || lex == "end." || lex == "end;")
    {
        return "endOperation";
    }
    else
    {
        return "undefined";
    }
}

bool parse(std::ifstream &fin, std::string op) {
    bool isCorrect = false;

    std::string lex;

    while (!fin.eof()) {
        fin>> lex;
        if (lexType(lex) == "operation") {
            isCorrect = parse(fin, lex);
        } else if (lexType(lex) == "endOperation") {
            return isCorrect;
        } else {
            if (op == "if" && lex == "BE") {
                fin>> lex;
                if (lex == "then") {
                    isCorrect = parse(fin, lex);
                } else {
                    return false;
                }
            } else if (op == "while" && lex == "BE") {
                fin>> lex;
                if (lex == "do") {
                    isCorrect = parse(fin, lex);
                } else {
                    return false;
                }
            } else if (op == ":=" && lex == "E") {
                isCorrect = true;
            } else if (lex == "ID") {
                isCorrect = parse(fin, lex);
            } else {
                return false;
            }
        }
        if (!isCorrect) return false;
    }

    return isCorrect;
}

int main() {
    //fin.open("/home/sergei/University/tranlsators/Lab1-C++/text.txt");
    fin.open(R"(C:\Users\vscho\Desktop\Translator\Lab1-C++\text.txt)", std::ios::binary);
    //fin.open(R"(F:\ClionProjects\translator\Lab1-C++\text.txt)", std::ios::binary);

//    std::string expression;
//
//    while (!fin.eof()) {
//        yylex();
//        expression += yytext;
//        token_values new_value;
//
//        if (lex_type == 1) {
//            std::string::size_type sz;
//            new_value.f = std::stof(yytext, &sz);
//        } else if (lex_type == 2 || lex_type == 3) {
//            new_value.o_h = yytext.c_str()[0];
//        }
//
//        AddToken(lex_type, new_value);
//    }
//
//    TokenNode *root = CreateTree(createPostfixForm());
//    PrintTree(root, 0);
//
//    std::cout << std::endl << "Result: " << CalculateValue(root) << std::endl;

    //std::cout << "Is correct: " << parse(fin, "") << std::endl;

    LexNode* root = nullptr;
    LexTree(fin, "", root);

    fin.close();

    PrintLexTree(root, 0);


    return 0;
}
