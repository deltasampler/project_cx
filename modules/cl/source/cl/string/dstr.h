#pragma once
#include <cl/types.h>

struct dstr_t {
    char* data;
    usize cap;
    usize len;
};

void dstr_new(dstr_t& str, usize cap);
void dstr_del(dstr_t& str);
void dstr_realloc(dstr_t& str, usize cap);
void dstr_resize(dstr_t& str, usize cap);
void dstr_assign(dstr_t& str, char c);
void dstr_assign(dstr_t& str, const char* cstr);
void dstr_concat(dstr_t& str, char c);
void dstr_concat(dstr_t& str, const char* cstr);
char dstr_at(dstr_t& str, usize i);
