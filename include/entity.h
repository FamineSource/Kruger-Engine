#ifndef ENTITY_H
#define ENTITY_H

#include "component.h"
#include <vector>
#include <cstdint>
#include "esystem.h"

class Entity {
private:
    std::vector<Component*> components;
    std::vector<ESystem*> systems;
    const char* name;
    uint32_t id;

private:
    void setID(int);
    friend class Scene;

public:
    Entity(const char* name);
    ~Entity();

    bool addComponent(Component* c);
    template<typename T>
    T* getComponent();

    void addSystem(ESystem* sys);
    void runStart();
    void runUpdate(float);

    int componentCount() const;
    const char* getName() const;
    uint32_t getId() const;
};

// Ho notato che è possibile usare dei file .tpp per i template. Idea che probabilmente non perseguiterò
template<typename T>
T* Entity::getComponent() {
    for (auto* comp : components) {
        if (T* casted = dynamic_cast<T*>(comp)) return casted;
    }
    return nullptr;
}

#endif