#include "entity.h"
#include "sprite.h"
#include "component.h"

Sprite::Sprite(float x, float y) : Sprite(x, y, 1, 1, "resources/kruger-logo.png") {}
Sprite::Sprite(float x, float y, const char *path) : Sprite(x, y, 1, 1, path) {}
Sprite::Sprite(float x, float y, float width, float height) : Sprite(x, y, width, height, "resources/kruger-logo.png") {}
Sprite::Sprite(float x, float y, float width, float height, const char *path) {
    spriteTexture = LoadTexture(path);
    transform.position.x = x;
    transform.position.y = y;
    transform.scale.x = width;
    transform.scale.y = height;
}

Sprite::~Sprite() {
    UnloadTexture(spriteTexture);
}

bool Sprite::setSprite(const char* path) {
    if(!FileExists(path)) return false;
    UnloadTexture(spriteTexture);
    spriteTexture = LoadTexture(path);
    return true;
}

Texture2D Sprite::getSprite() {
    return spriteTexture;
}

void Sprite::setRotation(float rotation) {
    transform.rotation = rotation;
}

void DrawSprite::onStart(Entity& entity) { comp_sprite = entity.getComponent<Sprite>(); }

void DrawSprite::onUpdate(Entity& entity, float deltatime) {
    if(comp_sprite == nullptr) { handleStatus(260); return; }
    Rectangle source = {0, 0, (float)comp_sprite->getSprite().width, (float)comp_sprite->getSprite().height};
    Rectangle dest = {comp_sprite->transform.position.x, comp_sprite->transform.position.y, 
                      comp_sprite->getSprite().width * comp_sprite->transform.scale.x, comp_sprite->getSprite().height * comp_sprite->transform.scale.y};
    Vector2 origin = {dest.width * 0.5f, dest.height * 0.5f};
    DrawTexturePro(comp_sprite->getSprite(), source, dest, origin, comp_sprite->transform.rotation, WHITE);
}