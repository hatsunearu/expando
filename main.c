#include <stdio.h>
#include "expando.h"

int main() {
    Expando e[1] = {EXPANDO_INIT};
    
    Ex_append(e, 69);
    Ex_append(e, 123);
    printf("%d\n", Ex_get(e, 0));
    printf("%d\n", Ex_get(e, 1));
    
    Ex_set(e, 0, 39);
    printf("%d\n", Ex_get(e, 0));
    
    Ex_release(e);
    
    return 0; 
}