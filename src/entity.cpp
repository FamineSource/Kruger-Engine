#include "entity.h"
#include <stdio.h>

Entity::Entity(const char* name) : name(name){}

Entity::~Entity() {
    for (auto* c : components) delete c;
    for (auto* s : systems) delete s;
}

bool Entity::addComponent(Component* c) {
    components.push_back(c);
    return true;
}

void Entity::addSystem(ESystem* sys) {
    systems.push_back(sys);
}

void Entity::runStart() {
    for (auto* sys : systems) {
        sys->onStart(*this);
    }
}

void Entity::runUpdate(float deltatime) {
    for (auto* sys : systems) {
        sys->onUpdate(*this, deltatime);
    }
}

int Entity::componentCount() const {
    return components.size();
}

const char* Entity::getName() const {
    return name;
}

uint32_t Entity::getId() const {
    return id;
}

void Entity::setID(int new_id) {
    id = new_id;
}