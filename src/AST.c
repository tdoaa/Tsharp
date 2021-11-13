#include "include/AST.h"
#include <stdlib.h>

AST_T* init_ast(int type)
{
    AST_T* ast = calloc(1, sizeof(struct AST_STRUCT));
    ast->type = type;

    ast->stack = (void*) 0;

    // AST_PUSH
    ast->push_value = (void*) 0;

    // AST_STRING
    ast->string_value = (void*) 0;

    // AST_INT
    ast->int_value = 0;

    // AST_COMPOUND
    ast->compound_value = (void*) 0;
    ast->compound_size = 0;

    return ast;
}