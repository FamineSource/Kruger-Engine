#ifndef ESYSTEM_H
#define ESYSTEM_H

#include "entity.h"
class Entity;

class ESystem {
    public:
        virtual void onStart(Entity& entity) = 0;
        virtual void onUpdate(Entity& entity, float deltatime) = 0;
        virtual ~ESystem() = default;
};

#endif