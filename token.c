#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "token.h"

static Asmatical_Token get_number(FILE *fp, int first_ch) {
    int digit;
    int ch = first_ch;
    int dot_count = 0;
    int value = 0;
    Asmatical_Token token = { Asmatical_Eof, 0 };

    do {
        digit = atoi((const char *)&ch);
        value = value * 10 + digit;
    } while ((ch = fgetc(fp)) != EOF && isdigit(ch));

    token.kind = Asmatical_Int;
    token.value = value;

    return token;
}



Asmatical_Token Asmatical_Token_tokenize(FILE *fp, const char **error) {
    int ch;
    Asmatical_Token token = { Asmatical_Eof, 0 };

    if (fp == NULL) {
        *error = "File is null";
        return token; /* EOF Token */
    }

    while ((ch = fgetc(fp)) != EOF) {
        switch (ch) {
            case '+':
                token.kind = Asmatical_Add;
                return token;
            case '-':
                token.kind = Asmatical_Sub;
                return token;
            case '*':
                token.kind = Asmatical_Mul;
                return token;
            case '/':
                token.kind = Asmatical_Div;
                return token;
            default:
                if (isspace(ch)) {
                    continue;
                } else if (isdigit(ch)) {
                    return get_number(fp, ch);
                } else {
                    *error = "Illegal character";
                    return token;
                }
        }
    }

    *error = NULL;

    return token;
}

int Asmatical_Token_is_eof(Asmatical_Token token) {
    return token.kind == Asmatical_Eof;
}
