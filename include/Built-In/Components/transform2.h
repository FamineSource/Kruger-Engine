#ifndef TRANSFORM2_H
#define TRANSFORM2_H

#include "component.h"
#include "logger.h"
#include "raylib.h"

class Transform2 : public Component {
public:
    Vector2 position;
    float rotation;
    Vector2 scale;

public:
    void print();
};

#endif