#ifndef SPRITE_H
#define SPRITE_H

#include "component.h"
#include "esystem.h"
#include "transform2.h"
#include "error_handler.h"

class Component;

class Sprite : public Component {
    private:
        Texture2D spriteTexture;
        
    public:
        Transform2 transform;
    public:
        Sprite(float x, float y);
        Sprite(float x, float y, const char *path);
        Sprite(float x, float y, float width, float height);
        Sprite(float x, float y, float width, float height, const char *path);
        ~Sprite();

        bool setSprite(const char* path);
        Texture2D getSprite();

        void setRotation(float rotation);
};

class DrawSprite : public ESystem {
    private:
        Sprite* comp_sprite = nullptr;

    public:
        void onStart(Entity& entity) override;
        void onUpdate(Entity& entity, float deltatime) override;
};

#endif