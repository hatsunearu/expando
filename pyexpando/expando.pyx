cimport expando_d

cdef class CyExpando:
    
    cdef expando_d.Expando _expando
    
    def __cinit__(self):
        self._expando.len = 0
        self._expando.cap = 0
        self._expando.buf = NULL
    
    def __dealloc__(self):
        expando_d.Ex_release(&self._expando)
    
    cpdef append(self, unsigned char b):
        expando_d.Ex_append(&self._expando, b)
        
    def __len__(self):
        return self._expando.len
        
    def __getitem__(self, size_t ind):
        if ind >= self._expando.len:
            raise IndexError("expando index out of range")
        
        return expando_d.Ex_get(&self._expando, ind)
    
    def __setitem__(self, size_t ind, unsigned char b):
        if ind >= self._expando.len:
            raise IndexError("expando index out of range")
        
        expando_d.Ex_set(&self._expando, ind, b)
    
    def __iter__(self):
        cdef size_t i
        for i in range(0, self._expando.len):
            yield self._expando.buf[i]
    
