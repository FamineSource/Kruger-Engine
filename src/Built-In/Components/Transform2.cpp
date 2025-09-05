#include "entity.h"
#include "transform2.h"
#include "component.h"

void Transform2::print() {
    printf("Position: {%f, %f}\n", position.x, position.y);
    printf("Rotation: {%f, %f}\n", rotation.x, rotation.y);
    printf("Scale: {%f, %f}\n", scale.x, scale.y);
}