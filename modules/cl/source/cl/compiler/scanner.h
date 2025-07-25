#pragma once
#include <cl/types.h>

bool is_alpha(char c);
bool is_num(char c);
bool is_alnum(char c);
bool is_space(char c);

struct scanner_t {
    const char* data;
    ssize len;
    ssize i;
};

void scanner_new(scanner_t& scanner, const char* data, ssize len, ssize i);
scanner_t scanner_new(const char* data, ssize len, ssize i);
void scanner_move(scanner_t& scanner, ssize i = 1);
char scanner_char(scanner_t& scanner, ssize i = 0);
