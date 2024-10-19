#ifndef HEADER_ASMATICAL_TOKEN_H
#define HEADER_ASMATICAL_TOKEN_H

#include <stdio.h>

typedef enum {
    Asmatical_Int,
    Asmatical_Add,
    Asmatical_Sub,
    Asmatical_Mul,
    Asmatical_Div,
    Asmatical_Eof,
} Asmatical_TokenKind;

typedef struct Asmatical_Token {
    Asmatical_TokenKind kind;
    int value;
} Asmatical_Token;

Asmatical_Token Asmatical_Token_tokenize(FILE *, const char **);
int Asmatical_Token_is_eof(Asmatical_Token);

#endif /* HEADER_ASMATICAL_TOKEN_H */
