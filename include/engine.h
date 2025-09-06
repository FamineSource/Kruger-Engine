#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include <functional>

#include "raylib.h"
#include "error_handler.h"
#include "entity.h"
#include "logger.h"
#include "scene.h"

enum MouseStatus {
    FREE = 0,
    HIDDENFREE = 1,
    LOCKED = 2,
    HIDDENLOCKED = 3,
};

class Engine {
private:
    int width, height;
    const char* windowTitle;

    MouseStatus mouseStatus;

    std::vector<Scene*> scenes;
    std::vector<std::function<Scene*()>> scene_factories;
    Scene* active_scene = nullptr;

public:
    static bool debugShapes;
public:
    Engine();
    Engine(int, int);
    Engine(int, int, const char*);
    Engine(int, int, int);
    Engine(int, int, const char*, int);
    ~Engine();
    
    void handleMouse();

    void setFPSTarget(int);
    void run();
    void run(int);
    void run(Scene&);
    void setWindowTitle(const char*);
    int displayFPS(float);

    template<typename SceneType>
    void addScene(SceneType* scene) {
        scenes.push_back(scene);
        scene_factories.push_back([]() { return new SceneType(); });
    }

    void playScene(int);

    void setMouseStatus(MouseStatus);
};

#endif
