typedef struct Expando {
    size_t len;
    size_t cap;
    char *buf;
} Expando;

#define EXPANDO_INIT {0}

#define EX_ALLOC_FAILED 1
#define EX_OUT_OF_BOUNDS -1

int Ex_set(Expando *, size_t, unsigned char);
int Ex_get(Expando *, size_t);
int Ex_append(Expando *, unsigned char);
void Ex_release(Expando *);




