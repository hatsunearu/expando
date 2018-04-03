cdef extern from "../expando.h":

    cdef struct Expando:
        size_t len
        size_t cap
        char *buf
        
    int Ex_set(Expando *, size_t, unsigned char);
    int Ex_get(Expando *, size_t);
    int Ex_append(Expando *, unsigned char);
    void Ex_release(Expando *);
