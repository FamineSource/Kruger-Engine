#include "scene.h"

void Scene::runStartAll() {
    for (auto* ent : entity_list) {
        ent->runStart();
    }
}

void Scene::runUpdateAll(float deltatime) {
    for (auto* ent : entity_list) {
        ent->runUpdate(deltatime);
    }
}

void Scene::Instantiate(Entity &entity) {
    entity.setID(++id_counter);
    entity_list.push_back(&entity);
}

int Scene::getEntityCount() {
    return entity_list.size();
}

void Scene::runScene(float deltatime) {
    if (!isRunning) {
        isRunning = true;
        onStart();
        runStartAll();
        onLateStart();
    }
    
    onUpdate(deltatime);
    runUpdateAll(deltatime);
    onLateUpdate(deltatime);
}