#include <stdio.h>
#include "token.h"
#include "parse.h"

static const char *generate(FILE *in, FILE *out) {
    Asmatical_Token token;
    int parse_result;
    const char *error = NULL;

    fputs(".section .data\n\n.section .text\n.global _start\n\n_start:\n", out);

    while (!Asmatical_Token_is_eof(token = Asmatical_Token_tokenize(in, &error)) && error == NULL) {
        parse_result = Asmatical_parse(token, out, 1);

        if (parse_result == 0) {
            return "Parsing error";
        }
    }

    fputs("\n\n\tmovl %%ebx, %%eax\n\tmovl $60, %%eax\n\tsyscall\n", out);

    return error;
}

int main(void) {
    generate(stdin, stdout);

    return 0;
}
