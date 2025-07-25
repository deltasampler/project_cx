#include "scanner.h"

bool is_alpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool is_num(char c) {
    return c >= '0' && c <= '9';
}

bool is_alnum(char c) {
    return is_alpha(c) || is_num(c);
}

bool is_space(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f';
}

void scanner_new(scanner_t& scanner, const char* data, ssize len, ssize i) {
    scanner.data = data;
    scanner.len = len;
    scanner.i = i;
}

scanner_t scanner_new(const char* data, ssize len, ssize i) {
    scanner_t scanner;
    scanner.data = data;
    scanner.len = len;
    scanner.i = i;

    return scanner;
}

void scanner_move(scanner_t& scanner, ssize i) {
    scanner.i += i;
}

char scanner_char(scanner_t& scanner, ssize i) {
    ssize index = scanner.i + i;

    if (index < 0 || index >= scanner.len) {
        return '\0';
    }

    return scanner.data[index];
}
