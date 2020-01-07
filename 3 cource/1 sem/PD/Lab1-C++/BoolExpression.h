//
// Created by vscho on 20.12.2019.
//

#ifndef LAB1_C_BOOLEXPRESSION_H
#define LAB1_C_BOOLEXPRESSION_H

#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <string>
#include <stack>


int calcPriorityBool(char operation) {
    switch (operation) {
        case '(':
            return 1;
        case '|':
            return 2;
        case '&':
            return 3;
        case '!':
            return 4;
        default:
            return 0;
    }
}

std::vector<Token> createPostfixFormBool(std::vector<Token> tokens) {
    std::stack<Token> operations;
    std::string resultString;
    std::vector<Token> resTokens;

    for (int i = 0; i < tokens.size(); i++) {
        if (tokens.at(i).value.o_h == '!' || tokens.at(i).value.o_h == '&' || tokens.at(i).value.o_h == '|') {
            if (operations.empty()) {
                operations.push(tokens.at(i));
            }
            else {
                if (operations.top().value.o_h == '(') {
                    operations.push(tokens.at(i));
                }
                else if (calcPriorityBool(tokens.at(i).value.o_h) > calcPriorityBool(operations.top().value.o_h)) {
                    operations.push(tokens.at(i));
                }
                else {
                    while (calcPriorityBool(tokens.at(i).value.o_h) <= calcPriorityBool(operations.top().value.o_h) && operations.top().value.o_h != '(' && !operations.empty()) {
                        resultString += operations.top().value.o_h;
                        resultString += " ";
                        resTokens.push_back(operations.top());
                        operations.pop();
                        if (operations.empty() || operations.top().value.o_h == '(')
                        {
                            break;
                        }
                    }
                    operations.push(tokens.at(i));
                }
            }
        } else if (tokens.at(i).value.o_h == '(') {
            operations.push(tokens.at(i));

        } else if (tokens.at(i).value.o_h == ')') {
            while (operations.top().value.o_h != '(') {
                resultString += operations.top().value.o_h;
                resultString += " ";
                resTokens.push_back(operations.top());
                operations.pop();
            }
            operations.pop();
        } else {
            resultString += std::to_string(tokens.at(i).value.f) + " ";
            resTokens.push_back(tokens.at(i));
        }
    }

    while (!operations.empty()) {
        resultString += operations.top().value.o_h;
        resultString += " ";
        resTokens.push_back(operations.top());
        operations.pop();
    }

    return resTokens;
}

TokenNode *CreateBoolTree(std::vector<Token> tokens) {
    std::stack<TokenNode*> nodes;
    TokenNode *node, *node1, *node2;

    for (int i = 0; i < tokens.size(); ++i) {
        if (tokens[i].type == 4) {
            node = new TokenNode(tokens[i]);

            node1 = nodes.top();
            nodes.pop();

            node->left = node1;
            nodes.push(node);

        } else if (tokens[i].type == 5) {
            node = new TokenNode(tokens[i]);
            nodes.push(node);
        } else {
            node = new TokenNode(tokens[i]);

            node1 = nodes.top();
            nodes.pop();
            node2 = nodes.top();
            nodes.pop();

            node->right = node1;
            node->left = node2;

            nodes.push(node);
        }
    }

    node = nodes.top();
    nodes.pop();

    return node;
}

int TokenTypeBool(std::string token) {
    std::regex operations_reg (R"(\&|\||\=)");
    std::regex hooks_reg(R"(\(|\))");

    if (token == "true" || token == "false") {
        return  5;
    } else if (std::regex_match(token, operations_reg)) {
        return  2;
    } else if (std::regex_match(token, hooks_reg)) {
        return 3;
    } else if (token == "!") {
        return 4;
    } else return 0;
}

Token StringToTokenBool(std::string tokenString) {
    Token token;

    int token_type = TokenTypeBool(tokenString);

    if (token_type == 5) {
        if (tokenString == "true") {
            token.value.f = 1;
        }
        else if (tokenString == "false") {
            token.value.f = 0;
        }
    }
    else if (token_type == 2 || token_type == 3 || token_type == 4) {
        token.value.o_h = tokenString.c_str()[0];
    }

    token.type = token_type;

    return token;
}

TokenNode *GetBoolTokenNode(std::ifstream &fin) {

    std::string lex;
    std::vector<Token> tokens;
    std::ios::pos_type position;

    fin >> lex;
    while (true) {
        if (lex == "do" || lex == "then") {
            break;
        }
        position = fin.tellg();
        tokens.push_back(StringToTokenBool(lex));
        fin >> lex;
    }
    fin.seekg(position);
//
//    std::cout << "Tokens: ";
//    for (int i = 0; i < tokens.size(); i++)
//    {
//        if (tokens.at(i).type == 2 || tokens.at(i).type == 4) {
//            std::cout << tokens.at(i).value.o_h << " ";
//        } else {
//            if (tokens.at(i).value.f == 0) {
//                std::cout << "false ";
//            } else if (tokens.at(i).value.f == 1) {
//                std::cout << "true ";
//            }
//
//        }
//    }

    std::vector<Token> resultTokens;
    resultTokens = createPostfixFormBool(tokens);

//    std::cout << std::endl << "Postfix form: ";
//    for (int i = 0; i < resultTokens.size(); i++) {
//        if (resultTokens.at(i).type == 2 || resultTokens.at(i).type == 4) {
//            std::cout << resultTokens.at(i).value.o_h << " ";
//        } else {
//            if (resultTokens.at(i).value.f == 0) {
//                std::cout << "false ";
//            } else if (resultTokens.at(i).value.f == 1) {
//                std::cout << "true ";
//            }
//        }
//    }
//    std::cout << std::endl;

    TokenNode *node = nullptr;
    node = CreateBoolTree(resultTokens);

    return node;
}

#endif //LAB1_C_BOOLEXPRESSION_H
