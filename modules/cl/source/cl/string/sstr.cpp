#include "sstr.h"

void sstr_new(sstr_t& sstr, char* data, usize cap, usize len) {
    sstr.data = data;
    sstr.cap = cap;
    sstr.len = len;
}

sstr_t sstr_new(char* data, usize cap, usize len) {
    sstr_t sstr;
    sstr_new(sstr, data, cap, len);

    return sstr;
}

char sstr_at(sstr_t& sstr, usize i) {
    if (i >= sstr.len) {
        return '\0';
    }

    return sstr.data[i];
}

void sstr_assign(sstr_t& sstr, char c) {
    sstr.data[0] = c;
    sstr.data[1] = '\0';
    sstr.len = 1;
}

void sstr_assign(sstr_t& sstr, const char* cstr) {
    sstr.len = 0;

    while (sstr.len < (sstr.cap - 1) && cstr[sstr.len] != '\0') {
        sstr.data[sstr.len] = cstr[sstr.len];
        sstr.len += 1;
    }

    sstr.data[sstr.len] = '\0';
}

void sstr_concat(sstr_t& sstr, char c) {
    if (sstr.len >= (sstr.cap - 1)) {
        return;
    }

    sstr.data[sstr.len] = c;
    sstr.len += 1;
    sstr.data[sstr.len] = '\0';
}

void sstr_concat(sstr_t& sstr, const char* cstr) {
    usize i = 0;

    while (sstr.len < (sstr.cap - 1) && cstr[i] != '\0') {
        sstr.data[sstr.len] = cstr[i];
        sstr.len += 1;
        i += 1;
    }

    sstr.data[sstr.len] = '\0';
}
