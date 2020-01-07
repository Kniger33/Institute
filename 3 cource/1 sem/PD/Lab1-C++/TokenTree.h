//
// Created by Maxim on 14.12.2019.
//

#ifndef LAB1_C___TOKENTREE_H
#define LAB1_C___TOKENTREE_H

#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <string>
#include <stack>

union token_values {
    float f;
    char o_h;
};

struct Token {
    int type;
    token_values value;
};

class TokenNode {
public:
    Token token;
    TokenNode *left = nullptr;
    TokenNode *right = nullptr;

    TokenNode(){}

    TokenNode(Token t) {
        token = t;
    }
};

float CalculateValue(TokenNode *node)
{
    float valueLeft;
    float valueRight;
    if(node->left == nullptr
       && node->right == nullptr
            )
    {
        return node->token.value.f;
    }

    valueLeft = CalculateValue(node->left);
    valueRight = CalculateValue(node->right);

    switch (node->token.value.o_h)
    {
        case '+':
        {
            return valueLeft + valueRight;
        }
        case '-':
        {
            return valueLeft - valueRight;
        }
        case '*':
        {
            return valueLeft * valueRight;
        }
        case '/':
        {
            return valueLeft / valueRight;
        }
    }
}

int calcPriority(char operation) {
    switch (operation) {
        case '(':
            return 1;
        case '-':
            return 2;
        case '+':
            return 3;
        case '/':
            return 4;
        case '*':
            return 5;
        default:
            return 0;
    }
}

std::vector<Token> createPostfixForm(std::vector<Token> tokens) {
    std::stack<Token> operations;
    std::string resultString;
    std::vector<Token> resTokens;

    for (int i = 0; i < tokens.size(); i++) {
        if (tokens.at(i).value.o_h == '+' || tokens.at(i).value.o_h == '-' || tokens.at(i).value.o_h == '*' ||
            tokens.at(i).value.o_h == '/') {
            if (operations.empty()) {
                operations.push(tokens.at(i));
            }
            else {
                if (operations.top().value.o_h == '(') {
                    operations.push(tokens.at(i));
                }
                else if (calcPriority(tokens.at(i).value.o_h) > calcPriority(operations.top().value.o_h)) {
                    operations.push(tokens.at(i));
                }
                else {
                    while (calcPriority(tokens.at(i).value.o_h) <= calcPriority(operations.top().value.o_h) && operations.top().value.o_h != '(' && !operations.empty()) {
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

TokenNode *CreateTree(std::vector<Token> tokens) {
    std::stack<TokenNode*> nodes;
    TokenNode *node, *node1, *node2;

    for (int i = 0; i < tokens.size(); ++i) {
        if (tokens[i].type != 2) {
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

int TokenType(std::string token) {
    std::regex int_reg("-?[1-9][0-9]*");
    std::regex float_reg("-?[0-9]*\\.[0-9]*(e-?[1-9][0-9]*)?");
    std::regex id_reg("_?[a-zA-Z][a-zA-Z0-9]*");
    std::regex operations_reg (R"(\+|\-|\*|\/)");
    std::regex hooks_reg(R"(\(|\))");

    int lex_type = 0;

    if (std::regex_match(token, int_reg)) {
        lex_type = 1;
    } else if (std::regex_match(token, float_reg)) {
        lex_type = 1;
    } else if (std::regex_match(token, operations_reg)) {
        lex_type = 2;
    } else if (std::regex_match(token, hooks_reg)) {
        lex_type = 3;
    }

    return lex_type;
}

Token StringToToken(std::string tokenString) {
    Token token;

    int token_type = TokenType(tokenString);

    if (token_type == 1) {
        std::string::size_type sz;
        token.value.f = std::stof(tokenString, &sz);
    } else if (token_type == 2 || token_type == 3) {
        token.value.o_h = tokenString.c_str()[0];
    }

    token.type = token_type;

    return token;
}

#endif //LAB1_C___TOKENTREE_H
