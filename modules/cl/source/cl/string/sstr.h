#pragma once
#include <cl/types.h>

struct sstr_t {
    char* data;
    usize cap;
    usize len;
};

void sstr_new(sstr_t& sstr, char* data, usize cap, usize len = 0);
sstr_t sstr_new(char* data, usize cap, usize len = 0);
char sstr_at(sstr_t& sstr, usize i);
void sstr_assign(sstr_t& sstr, char c);
void sstr_assign(sstr_t& sstr, const char* cstr);
void sstr_concat(sstr_t& sstr, char c);
void sstr_concat(sstr_t& sstr, const char* cstr);