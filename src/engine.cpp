#include "engine.h"
#include <cstdint>
#include <string>

const char* intToConstCharPtr(int num) {
    static std::string s;
    s = std::to_string(num);
    return s.c_str();
}

Engine::Engine() : Engine(800, 600, "Kruger Engine - Game", 30) {}
Engine::Engine(int width, int height) : Engine(width, height, "Kruger Engine - Game", 30) {}
Engine::Engine(int width, int height, int targetFPS) : Engine(width, height, "Kruger Engine - Game", targetFPS) {}
Engine::Engine(int width, int height, const char *title) : Engine(width, height, title, 30) {}
Engine::Engine(int width = 800, int height = 600, const char *title = "Kruger Engine - Game", int targetFPS = 30) : width(width), height(height), windowTitle(title)
{
    Log::info("Engine Initialized!");
    try {
        setFPSTarget(targetFPS);
        InitWindow(width, height, title);
    } catch(int error) {
        handleStatus(error);
    }
}

Engine::~Engine() {
    Log::warn("The engine has been removed");
}

void Engine::setFPSTarget(int fps) {
    if(fps < 0) throw 501;
    SetTargetFPS(fps);
}

void Engine::run() {
    if(scenes.empty()) { handleStatus(500); return; }
    run(*scenes.front());
}

void Engine::run(int index) {
    run(*scenes[index]);
}

void Engine::run(Scene &scene) {
    active_scene = &scene;

    float previousTime = GetTime();
    while (!WindowShouldClose()) {
        PollInputEvents();
        BeginDrawing();
        ClearBackground(BLACK);
        float currentTime = GetTime();
        float deltaTime = currentTime - previousTime;
        previousTime = currentTime;

        if (active_scene)
            active_scene->runScene(deltaTime);

        EndDrawing();
    }
    CloseWindow();
}

void Engine::setWindowTitle(const char *title) {
    windowTitle = title;
    SetWindowTitle(windowTitle);
}

int Engine::displayFPS(float deltaTime) {
    int fps = (int)(1 / deltaTime);
    std::string fpsStr = std::to_string(fps);
    DrawText(fpsStr.c_str(), 10, 10, 32, GREEN);
    return fps;
}

void Engine::playScene(int index) {
    if (active_scene && !scene_factories.empty()) {
        for (int i = 0; i < scenes.size(); i++) {
            if (scenes[i] == active_scene && scene_factories[i] != nullptr) {
                delete active_scene;
                scenes[i] = scene_factories[i]();
                active_scene = scenes[i];
                break;
            }
        }
    }
    
    if (index < scenes.size()) {
        active_scene = scenes[index];
    }
}