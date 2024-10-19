#include "parse.h"
#include "token.h"

static void operation(FILE *fp, const char *op, int use_tabs, int divide) {
    const char *nl = use_tabs ? "\n\t" : "\n";

    if (divide) {
        fprintf(fp, "%spopl %%eax%spopl %%ebx%sxorl %%edx, %%edx%s%s %%eax%spushl %%eax%s", use_tabs ? "\t" : "", nl, nl, nl, op, nl, "\n");
    } else {
        fprintf(fp, "%spopl %%eax%spopl %%ebx%s%s %%ebx, %%eax%spushl %%eax%s", use_tabs ? "\t" : "", nl, nl, op, nl, "\n");
    }
}

int Asmatical_parse(Asmatical_Token token, FILE *fp, int use_tabs) {
    if (fp == NULL) {
        return 0;
    }

    switch (token.kind) {
        case Asmatical_Int:
            fprintf(fp, "%spushl $%d\n", use_tabs ? "\t" : "", token.value);
            break;
        case Asmatical_Add:
            operation(fp, "addl", use_tabs, 0);
            break;
        case Asmatical_Sub:
            operation(fp, "subl", use_tabs, 0);
            break;
        case Asmatical_Mul:
            operation(fp, "imull", use_tabs, 0);
            break;
        case Asmatical_Div:
            operation(fp, "idivl", use_tabs, 1);
            break;
        case Asmatical_Eof:
            break;
    }

    return 1;
}
