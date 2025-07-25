#pragma once

#include <stdlib.h>
#include <cl/types.h>

template <typename type_t>
struct sl_item_t {
    type_t data;
    sl_item_t<type_t>* next;
};

template <typename type_t>
struct sl_list_t {
    sl_item_t<type_t>* first;
    sl_item_t<type_t>* last;
    usize len;
};

template <typename type_t>
void sl_list_new(sl_list_t<type_t>& list) {
    list.first = nullptr;
    list.last = nullptr;
    list.len = 0;
}

template <typename type_t>
void sl_list_del(sl_list_t<type_t>& list) {
    if (list.len == 0) {
        return;
    }

    sl_item_t<type_t>* curr = list.first;

    while (curr != nullptr) {
        sl_item_t<type_t>* temp = curr;
        curr = curr->next;
        free(temp);
    }

    list.first = nullptr;
    list.last = nullptr;
    list.len = 0;
}

template <typename type_t>
void sl_list_push(sl_list_t<type_t>& list, const type_t& data) {
    sl_item_t<type_t>* item = (sl_item_t<type_t>*)malloc(sizeof(sl_item_t<type_t>));
    item->data = data;
    item->next = nullptr;

    if (list.len == 0) {
        list.first = item;
        list.last = item;
        list.len = 1;
    } else {
        list.last->next = item;
        list.last = item;
        list.len += 1;
    }
}

template <typename type_t>
void sl_list_pop(sl_list_t<type_t>& list) {
    if (list.len == 0) {
        return;
    }

    if (list.len == 1) {
        free(list.first);
        list.first = nullptr;
        list.last = nullptr;
        list.len = 0;
    } else {
        sl_item_t<type_t>* prev = list.first;

        while (prev->next != list.last && prev != nullptr) {
            prev = prev->next;
        }

        prev->next = nullptr;

        free(list.last);
        list.last = prev;
        list.len -= 1;
    }
}

template <typename type_t>
sl_item_t<type_t>* sl_list_at(sl_list_t<type_t>& list, usize i) {
    if (list.len == 0 || list.len <= i) {
        return nullptr;
    }

    sl_item_t<type_t>* curr = list.first;
    usize index = 0;

    while (index != i && curr != nullptr) {
        curr = curr->next;
        index += 1;
    }

    return curr;
}
