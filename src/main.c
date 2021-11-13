#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/lex.h"
#include "include/parse.h"
#include "include/stack.h"
#include "include/io.h"
#include "include/visitor.h"

int main(int argc, char* argv[]) {
    if (argc == 2) {
        lexer_T* lexer = init_lexer(get_file_contents(argv[1]));
        parser_T* parser = init_parser(lexer);
        AST_T* node = parser_parse(parser, parser->stack);
        visitor_T* visitor = init_visitor();
        visitor_visit(visitor, node);

        free(lexer); free(parser); free(node); free(visitor);
    }
    else
    {
        printf("Usage:\n");
        printf("    tsh <filename>.t#\n");
        exit(1);
    }

    return 0;
}
