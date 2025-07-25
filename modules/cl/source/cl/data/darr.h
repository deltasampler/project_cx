#pragma once

#include <stdlib.h>
#include <assert.h>
#include <cl/types.h>

template <typename type_t>
struct darr_t {
    type_t* data = nullptr;
    usize cap;
    usize len;
};

template <typename type_t>
void darr_new(darr_t<type_t>& arr, usize cap) {
    darr_del(arr);

    arr.data = (type_t*)malloc(sizeof(type_t) * cap);
    arr.cap = cap;
    arr.len = 0;
}

template <typename type_t>
void darr_del(darr_t<type_t>& arr) {
    if (arr.data == nullptr) {
        return;
    }

    free(arr.data); arr.data = nullptr;
    arr.cap = 0;
    arr.len = 0;
}

template <typename type_t>
void darr_resize(darr_t<type_t>& arr, usize cap) {
    type_t* data = (type_t*)malloc(sizeof(type_t) * cap);

    usize len = 0;

    while (len < cap && len < arr.len) {
        data[len] = arr.data[len];
        len += 1;
    }

    if (data != nullptr) {
        free(arr.data);
    }

    arr.data = data;
    arr.cap = cap;
    arr.len = len;
}

template <typename type_t>
void darr_push(darr_t<type_t>& arr, const type_t& value) {
    if (arr.cap <= arr.len) {
        darr_resize(arr, arr.cap == 0 ? 1 : arr.cap * 2);
    }

    arr.data[arr.len] = value;
    arr.len += 1;
}

template <typename type_t>
void darr_pop(darr_t<type_t>& arr) {
    if (arr.len == 0) return;

    arr.len -= 1;
}

template <typename type_t>
type_t& darr_top(darr_t<type_t>& arr) {
    return arr.data[arr.len - 1];
}

template <typename type_t>
type_t& darr_at(darr_t<type_t>& arr, usize i) {
    assert(i < arr.len && "Index out of bounds");

    return arr.data[i];
}
