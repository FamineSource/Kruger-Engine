#include "entity.h"
#include "transform3.h"

void Transform3::print() {
    printf("Position: {%f, %f, %f}", position.x, position.y, position.z);
    printf("Rotation: {%f, %f, %f}", rotation.x, rotation.y, rotation.z);
    printf("Scale: {%f, %f, %f}", scale.x, scale.y, scale.z);
}