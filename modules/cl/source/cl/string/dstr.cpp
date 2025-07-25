#include <stdlib.h>
#include "cstr.h"

#include "dstr.h"

void dstr_new(dstr_t& str, usize cap) {
    str.data = (char*)malloc(sizeof(char) * cap);
    str.cap = cap;
    str.len = 0;
}

void dstr_del(dstr_t& str) {
    if (str.data == nullptr) {
        return;
    }

    free(str.data); str.data = nullptr;
    str.cap = 0;
    str.len = 0;
}

void dstr_realloc(dstr_t& str, usize cap) {
    free(str.data); str.data = (char*)malloc(sizeof(char) * cap);
    str.cap = cap;
    str.len = 0;
}

void dstr_resize(dstr_t& str, usize cap) {
    char* data = (char*)malloc(sizeof(char) * cap);

    usize len = 0;

    while (len < cap && len < str.len) {
        data[len] = str.data[len];
        len += 1;
    }

    data[len] = '\0';

    free(str.data); str.data = data;
    str.cap = cap;
    str.len = len;
}

void dstr_assign(dstr_t& str, char c) {
    if (str.cap < 2) {
        dstr_realloc(str, 2);
    }

    str.data[0] = c;
    str.data[1] = '\0';
    str.len = 1;
}

void dstr_assign(dstr_t& str, const char* cstr) {
    usize len = cstr_len(cstr);

    if (str.cap < len + 1) {
        dstr_realloc(str, len + 1);
    }

    for (usize i = 0; i < len + 1; i += 1) {
        str.data[i] = cstr[i];
    }

    str.len = len;
}

void dstr_concat(dstr_t& str, char c) {
    if (str.cap < str.len + 1) {
        dstr_resize(str, str.cap * 2);
    }

    str.data[str.len] = c;
    str.len += 1;
    str.data[str.len] = '\0';
}

void dstr_concat(dstr_t& str, const char* cstr) {
    usize len = cstr_len(cstr);

    if (str.cap < str.len + len + 1) {
        dstr_resize(str, str.cap * 2 + len + 1);
    }

    for (usize i = 0; i < len + 1; i += 1) {
        str.data[str.len + i] = cstr[i];
    }

    str.len += len;
}

char dstr_at(dstr_t& str, usize i) {
    if (i >= str.len) {
        return '\0';
    }

    return str.data[i];
}
