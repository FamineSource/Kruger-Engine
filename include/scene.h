#ifndef SCENE_H
#define SCENE_H

#include <cstdint>
#include <stdio.h>
#include <functional>
#include <vector>

#include "entity.h"
#include "error_handler.h"

class Scene {
    private:
        bool isRunning;
        uint32_t id_counter;
        std::vector<Entity*> entity_list;

    private:
        void runScene(float);
        friend class Engine;
        
        void runStartAll();
        void runUpdateAll(float);

    protected:
        virtual void onStart() {}
        virtual void onLateStart() {}
        virtual void onUpdate(float deltatime) {}
        virtual void onLateUpdate(float deltatime) {}

    public:
        Scene() : isRunning(false), id_counter(0) {};
        virtual ~Scene() {}

        void Instantiate(Entity &entity);
        int getEntityCount();
};

#endif