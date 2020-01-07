//
// Created by Maxim on 07.12.2019.
//

#ifndef LAB1_C___OPERATIONTREE_H
#define LAB1_C___OPERATIONTREE_H

#include <iostream>
#include <fstream>
#include <vector>

#include "TokenTree.h"
#include "BoolExpression.h"

enum lexType {
    _assume_,
    _if_,
    _while_,
    _begin_,
    _id_,
    _be_,
    _e_,
};

class LexNode {
public:
    lexType type;
    std::string value;
    std::vector<LexNode*> operations;

    TokenNode* tokenNode = nullptr;

    LexNode(){}

    LexNode(lexType type, std::string value) {
        this->type = type;
        this->value = value;
    }
};

static lexType LexType (std::string lex) {
    if (lex == "ID") {
        return _id_;
    } else if (lex == "E") {
        return _e_;
    } else if (lex == "BE") {
        return _be_;
    } else if (lex == ":=") {
        return _assume_;
    } else if (lex == "if") {
        return _if_;
    } else if (lex == "while") {
        return _while_;
    } else if (lex == "begin") {
        return _begin_;
    }
}

void LexTree(std::ifstream &fin, std::string prevLex, LexNode*& root) {
    LexNode* node = nullptr;
    std::string lex, operation;

        fin >> lex;

        lexType type = LexType(lex);

        switch (type) {
            case _id_:
                LexTree(fin, lex, root);
                break;

            case _assume_: {
                node = new LexNode(type, lex);
                node->operations.push_back(new LexNode(LexType(prevLex), prevLex));
                //Is E check
                node->operations.push_back(new LexNode(_e_, "E"));

                std::vector<Token> tokens;

                fin >> lex;
                while (lex != ";") {
                    tokens.push_back(StringToToken(lex));
                    fin >> lex;
                }

                node->operations[node->operations.size() - 1]->tokenNode = CreateTree(createPostfixForm(tokens));

                root->operations.push_back(node);
                break;
            }

            case _if_:
                node = new LexNode(type, lex);
                node->operations.push_back(new LexNode(_be_, "BE"));

                //Is BE check

                node->operations[node->operations.size() - 1]->tokenNode = GetBoolTokenNode(fin);

                //Is THEN check
                fin >> lex;
                LexTree(fin, lex, node);
                //Is ELSE check
                fin >> lex;
                LexTree(fin, lex, node);
                root->operations.push_back(node);
                break;

            case _while_:
                node = new LexNode(type, lex);
//                node->operations.push_back(new LexNode(_while_, "while"));
                //Is BE check
                node->operations[node->operations.size() - 1]->tokenNode = GetBoolTokenNode(fin);
                //Is DO check
                fin >> lex;
                LexTree(fin, lex, node);
                root->operations.push_back(node);
                break;

            case _begin_:
                node = new LexNode(type, lex);

                std::fpos<mbstate_t> position = fin.tellg();
                fin >> lex;

                while (!(lex == "end"  || lex == "end." || lex == "end;") && !fin.eof()) {
                    fin.seekg(position);
                    LexTree(fin, lex, node);

                    position = fin.tellg();
                    fin >> lex;
                }

                if (root == nullptr) {
                    root = node;
                } else {
                    root->operations.push_back(node);
                }

                break;
        }
}

void PrintTokenTree(TokenNode* node, int offset) {
    if (node) {
        for (int i = 0; i < offset; i++) {
            std::cout << " ";
        }
        std::cout << "|->";

        if (node->token.type == 2 || node->token.type == 4) {
            std::cout << node->token.value.o_h << std::endl;
        } else if (node->token.type == 5) {
            if (node->token.value.f == 0) {
                std::cout << "false" << std::endl;
            } else if (node->token.value.f == 1) {
                std::cout << "true" << std::endl;
            }
        } else {
            std::cout << node->token.value.f << std::endl;
        }

        offset += 3;

        PrintTokenTree(node->left, offset);
        PrintTokenTree(node->right, offset);
    }
}

void PrintLexTree(LexNode* node, int offset) {
    for (int i = 0; i < offset; i++) {
        std::cout << " ";
    }
    std::cout << "|->";

    std::cout << node->value << std::endl;

    offset += node->value.size() + 2;

    if (node->tokenNode != nullptr) {
        PrintTokenTree(node->tokenNode, offset);
    }

    for (int i = 0; i < node->operations.size(); i++) {
        PrintLexTree(node->operations.at(i), offset);
    }
}

#endif //LAB1_C___OPERATIONTREE_H
