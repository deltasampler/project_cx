#include <cl/string/cstr.h>
#include "token.h"

void token_new(token_t& token) {
    token.type = TOKEN_TYPE::KW_AUTO;
    token.value[0] = '\0';
    token.len = 0;
}

void token_concat(token_t& token, char c) {
    token.value[token.len] = c;
    token.len += 1;
    token.value[token.len] = '\0';
}

void token_concat(token_t& token, const char* cstr) {
    char c;

    for (usize i = 0; (c = cstr[i]) != '\0'; i += 1) {
        token_concat(token, c);
    }
}

TOKEN_TYPE token_type_keyword(token_t& token) {
    switch (token.value[0]) {
        case 'a':
            if (cstr_cmp(token.value, "auto")) return TOKEN_TYPE::KW_AUTO;

            break;
        case 'b':
           if (cstr_cmp(token.value, "break")) return TOKEN_TYPE::KW_BREAK;

           break;
        case 'c':
           if (cstr_cmp(token.value, "case")) return TOKEN_TYPE::KW_CASE;
           else if (cstr_cmp(token.value, "char")) return TOKEN_TYPE::KW_CHAR;
           else if (cstr_cmp(token.value, "const")) return TOKEN_TYPE::KW_CONST;
           else if (cstr_cmp(token.value, "continue")) return TOKEN_TYPE::KW_CONTINUE;

           break;
        case 'd':
           if (cstr_cmp(token.value, "default")) return TOKEN_TYPE::KW_DEFAULT;
           else if (cstr_cmp(token.value, "do")) return TOKEN_TYPE::KW_DO;
           else if (cstr_cmp(token.value, "double")) return TOKEN_TYPE::KW_DOUBLE;

           break;
        case 'e':
           if (cstr_cmp(token.value, "else")) return TOKEN_TYPE::KW_ELSE;
           else if (cstr_cmp(token.value, "enum")) return TOKEN_TYPE::KW_ENUM;
           else if (cstr_cmp(token.value, "extern")) return TOKEN_TYPE::KW_EXTERN;

           break;
        case 'f':
           if (cstr_cmp(token.value, "false")) return TOKEN_TYPE::KW_FALSE;
           else if (cstr_cmp(token.value, "float")) return TOKEN_TYPE::KW_FLOAT;
           else if (cstr_cmp(token.value, "for")) return TOKEN_TYPE::KW_FOR;

           break;
        case 'g':
           if (cstr_cmp(token.value, "goto")) return TOKEN_TYPE::KW_GOTO;

           break;
        case 'i':
           if (cstr_cmp(token.value, "if")) return TOKEN_TYPE::KW_IF;
           else if (cstr_cmp(token.value, "inline")) return TOKEN_TYPE::KW_INLINE;
           else if (cstr_cmp(token.value, "int")) return TOKEN_TYPE::KW_INT;

           break;
        case 'l':
           if (cstr_cmp(token.value, "long")) return TOKEN_TYPE::KW_LONG;

           break;
        case 'r':
           if (cstr_cmp(token.value, "register")) return TOKEN_TYPE::KW_REGISTER;
           else if (cstr_cmp(token.value, "restrict")) return TOKEN_TYPE::KW_RESTRICT;
           else if (cstr_cmp(token.value, "return")) return TOKEN_TYPE::KW_RETURN;

           break;
        case 's':
           if (cstr_cmp(token.value, "short")) return TOKEN_TYPE::KW_SHORT;
           else if (cstr_cmp(token.value, "signed")) return TOKEN_TYPE::KW_SIGNED;
           else if (cstr_cmp(token.value, "sizeof")) return TOKEN_TYPE::KW_SIZEOF;
           else if (cstr_cmp(token.value, "static")) return TOKEN_TYPE::KW_STATIC;
           else if (cstr_cmp(token.value, "struct")) return TOKEN_TYPE::KW_STRUCT;
           else if (cstr_cmp(token.value, "switch")) return TOKEN_TYPE::KW_SWITCH;

           break;
        case 't':
            if (cstr_cmp(token.value, "true")) return TOKEN_TYPE::KW_TRUE;
            else if (cstr_cmp(token.value, "typedef")) return TOKEN_TYPE::KW_TYPEDEF;

           break;
        case 'u':
           if (cstr_cmp(token.value, "union")) return TOKEN_TYPE::KW_UNION;
           else if (cstr_cmp(token.value, "unsigned")) return TOKEN_TYPE::KW_UNSIGNED;

           break;
        case 'v':
           if (cstr_cmp(token.value, "void")) return TOKEN_TYPE::KW_VOID;
           else if (cstr_cmp(token.value, "volatile")) return TOKEN_TYPE::KW_VOLATILE;

           break;
        case 'w':
           if (cstr_cmp(token.value, "while")) return TOKEN_TYPE::KW_WHILE;

           break;
         default:
            return TOKEN_TYPE::UNKNOWN;

            break;
    }
}
