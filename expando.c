#include <stdio.h>
#include <stdlib.h>
#include "expando.h"

int Ex_set(Expando *e, size_t index, unsigned char data) {
    if (index >= e->len) {
        return EX_OUT_OF_BOUNDS;
    }
    
    e->buf[index] = data;
    return 0;
    
}

int Ex_get(Expando *e, size_t index) {
    if (index >= e->len) {
        return EX_OUT_OF_BOUNDS;
    }
    
    return e->buf[index];
}

int Ex_append(Expando *e, unsigned char data) {
    if (e->len + 1 >= e->cap) {
        size_t newcap = e->cap + (e->cap / 8 > 0 ? e->cap / 8 : 1);
        e->buf = realloc(e->buf, newcap);
        e->cap = newcap;
        
        if (e->buf == NULL) {
            return EX_ALLOC_FAILED;
        }
    }
    e->buf[e->len] = data;
    e->len++;
    
    return 0;
}

void Ex_release(Expando *e) {
    puts("release");
    e->len = 0;
    e->cap = 0;
    free(e->buf);
    e->buf = NULL;
}