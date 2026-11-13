# Concluzii

Observam urmatoarele

- La no destructor observam memory leaks (nodurile alocate cu new nu sunt sterse niciodata)
- La no copy constructor observam double free: copy constructorul generat implicit copiaza doar pointerii, deci ambele obiecte pointeaza la aceleasi noduri si destructorul le sterge de doua ori
- La no move constructor observam un timp mai mare la move (se face fallback la copy constructor)