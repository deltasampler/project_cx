#include <cl/string/cstr.h>
#include "lexer.h"

bool lexer_push(scanner_t& scanner, token_t& token, TOKEN_TYPE type, const char* value) {
    token_new(token);

    token.type = type;
    token_concat(token, value);

    scanner_move(scanner, token.len);

    return true;
}

bool lexer_token(scanner_t& scanner, token_t& token) {
    char c;

    while (c = scanner_char(scanner)) {
        if (is_space(c)) {
            scanner_move(scanner);

            continue;
        }

        // keyword, identifier
        if (is_alpha(c)) {
            token_new(token);
            token_concat(token, c);

            scanner_move(scanner);

            while ((c = scanner_char(scanner)) && (is_alnum(c) || c == '_')) {
                token_concat(token, c);

                scanner_move(scanner);
            }

            token.type = token_type_keyword(token);

            if (token.type == TOKEN_TYPE::UNKNOWN) {
                token.type = TOKEN_TYPE::IDENTIFIER;
            }

            return true;
        }

        // number literal
        if (is_num(c) || (c == '.' && is_num(scanner_char(scanner, 1)))) {
            token_new(token);
            token_concat(token, c);

            scanner_move(scanner);

            while ((c = scanner_char(scanner)) && (is_alnum(c) || c == '.')) {
                token_concat(token, c);

                scanner_move(scanner);
            }

            token.type = TOKEN_TYPE::LIT_NUMBER;

            return true;
        }

        // string literal
        if (c == '"' || c == '\'') {
            char quote = c;

            token_new(token);
            token_concat(token, c);

            scanner_move(scanner);

            while ((c = scanner_char(scanner)) && c != quote) {
                token_concat(token, c);

                scanner_move(scanner);
            }

            token_concat(token, c);

            scanner_move(scanner);

            token.type = TOKEN_TYPE::LIT_STRING;

            return true;
        }

        // punctuator
        char p1 = scanner_char(scanner, 1);
        char p2 = scanner_char(scanner, 2);

        switch (c) {
            case '+':
                if (p1 == '+') return lexer_push(scanner, token, TOKEN_TYPE::PLUS_PLUS, "++");
                else if (p1 == '=') return lexer_push(scanner, token, TOKEN_TYPE::PLUS_EQ, "+=");
                else return lexer_push(scanner, token, TOKEN_TYPE::PLUS, "+");
            case '-':
                if (p1 == '-') return lexer_push(scanner, token, TOKEN_TYPE::MINUS_MINUS, "--");
                else if (p1 == '=') return lexer_push(scanner, token, TOKEN_TYPE::MINUS_EQ, "-=");
                else if (p1 == '>') return lexer_push(scanner, token, TOKEN_TYPE::ARROW, "->");
                else return lexer_push(scanner, token, TOKEN_TYPE::MINUS, "-");
            case '*':
                if (p1 == '=') return lexer_push(scanner, token, TOKEN_TYPE::STAR_EQ, "*=");
                else return lexer_push(scanner, token, TOKEN_TYPE::STAR, "*");
            case '/':
                if (p1 == '=') return lexer_push(scanner, token, TOKEN_TYPE::SLASH_EQ, "/=");
                else return lexer_push(scanner, token, TOKEN_TYPE::SLASH, "/");
            case '%':
                if (p1 == '=') return lexer_push(scanner, token, TOKEN_TYPE::MOD_EQ, "%=");
                else return lexer_push(scanner, token, TOKEN_TYPE::MOD, "%");
            case '=':
                if (p1 == '=') return lexer_push(scanner, token, TOKEN_TYPE::EQ_EQ, "==");
                else return lexer_push(scanner, token, TOKEN_TYPE::EQ, "=");
            case '!':
                if (p1 == '=') return lexer_push(scanner, token, TOKEN_TYPE::NOT_EQ, "!=");
                else return lexer_push(scanner, token, TOKEN_TYPE::NOT, "!");
            case '<':
                if (p1 == '<' && p2 == '=') return lexer_push(scanner, token, TOKEN_TYPE::SHIFT_LEFT_EQ, "<<=");
                else if (p1 == '=' && p2 == '>') return lexer_push(scanner, token, TOKEN_TYPE::SPACESHIP, "<=>");
                else if (p1 == '<') return lexer_push(scanner, token, TOKEN_TYPE::SHIFT_LEFT, "<<");
                else if (p1 == '=') return lexer_push(scanner, token, TOKEN_TYPE::LESSER_EQ, "<=");
                else return lexer_push(scanner, token, TOKEN_TYPE::LESSER, "<");
            case '>':
                if (p1 == '>' && p2 == '=') return lexer_push(scanner, token, TOKEN_TYPE::SHIFT_RIGHT_EQ, ">>=");
                else if (p1 == '>') return lexer_push(scanner, token, TOKEN_TYPE::SHIFT_RIGHT, ">>");
                else if (p1 == '=') return lexer_push(scanner, token, TOKEN_TYPE::GREATER_EQ, ">=");
                else return lexer_push(scanner, token, TOKEN_TYPE::GREATER, ">");
            case '~':
                return lexer_push(scanner, token, TOKEN_TYPE::BIT_NOT, "~");
            case '&':
                if (p1 == '&') return lexer_push(scanner, token, TOKEN_TYPE::AND, "&&");
                else if (p1 == '=') return lexer_push(scanner, token, TOKEN_TYPE::BIT_AND_EQ, "&=");
                else return lexer_push(scanner, token, TOKEN_TYPE::BIT_AND, "&");
            case '|':
                if (p1 == '|') return lexer_push(scanner, token, TOKEN_TYPE::BIT_XOR, "||");
                else if (p1 == '=') return lexer_push(scanner, token, TOKEN_TYPE::BIT_OR_EQ, "|=");
                else return lexer_push(scanner, token, TOKEN_TYPE::BIT_OR, "|");
            case '^':
                if (p1 == '=') return lexer_push(scanner, token, TOKEN_TYPE::BIT_XOR_EQ, "^=");
                else return lexer_push(scanner, token, TOKEN_TYPE::BIT_XOR, "^");
            case '.':
                if (p1 == '.' && p2 == '.') return lexer_push(scanner, token, TOKEN_TYPE::DOT_DOT_DOT, "...");
                else return lexer_push(scanner, token, TOKEN_TYPE::DOT, ".");
            case ':':
                if (p1 == ':') return lexer_push(scanner, token, TOKEN_TYPE::COLON_COLON, "::");
                else return lexer_push(scanner, token, TOKEN_TYPE::COLON, ":");
            case '?':
                if (p1 == ':') return lexer_push(scanner, token, TOKEN_TYPE::QUESTION_COLON, "?:");
                else return lexer_push(scanner, token, TOKEN_TYPE::QUESTION, "?");
            case '(':
                return lexer_push(scanner, token, TOKEN_TYPE::PAREN_LEFT, "(");
            case ')':
                return lexer_push(scanner, token, TOKEN_TYPE::PAREN_RIGHT, ")");
            case '[':
                return lexer_push(scanner, token, TOKEN_TYPE::BRACKET_LEFT, "[");
            case ']':
                return lexer_push(scanner, token, TOKEN_TYPE::BRACKET_RIGHT, "]");
            case '{':
                return lexer_push(scanner, token, TOKEN_TYPE::BRACE_LEFT, "{");
            case '}':
                return lexer_push(scanner, token, TOKEN_TYPE::BRACE_RIGHT, "}");
            case ';':
                return lexer_push(scanner, token, TOKEN_TYPE::SEMICOLON, ";");
            case ',':
                return lexer_push(scanner, token, TOKEN_TYPE::COMMA, ",");
        }

        return false;
    }

    return false;
}
