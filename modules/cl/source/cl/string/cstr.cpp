#include <stdlib.h>

#include "cstr.h"

usize cstr_len(const char* cstr) {
    usize len = 0;

    while (cstr[len] != '\0') {
        len += 1;
    }

    return len;
}

char* cstr_copy(const char* cstr) {
    usize cap = cstr_len(cstr) + 1;
    char* out = (char*)malloc(sizeof(char) * cap);

    for (usize i = 0; i < cap; i += 1) {
        out[i] = cstr[i];
    }

    return out;
}

bool cstr_cmp(const char* cstr0, const char* cstr1) {
    usize i = 0;

    while (cstr0[i] != '\0' && cstr1[i] != '\0') {
        if (cstr0[i] != cstr1[i]) {
            return false;
        }

        i += 1;
    }

    return cstr0[i] == '\0' && cstr1[i] == '\0';
}
