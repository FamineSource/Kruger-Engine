#ifndef TRANSFORM3_H
#define TRANSFORM3_H

#include "component.h"
#include "logger.h"
#include "raylib.h"

class Transform3 : public Component {
public:
    Vector3 position;
    Vector3 rotation;
    Vector3 scale;

public:
    void print();
};

#endif