#ifndef CHEST_H
#define CHEST_H
#include "entity.h"
#include <vector>
class Chest : Entity{
    public:
    bool isOpen;
    Chest(int, int);
};

#endif