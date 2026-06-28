#ifndef COLA_NODOCOLA_H
#define COLA_NODOCOLA_H
#include "ElementoCola.h"
struct NodoCola {
    struct ElementoCola elemento;
    NodoCola * siguiente;
};
#endif //COLA_NODOCOLA_H