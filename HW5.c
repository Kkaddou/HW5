#include <stdio.h>
#include <stdlib.h>

/* Vehicle interface using function pointers */
typedef struct Vehicle {
    void (*startEngine)(void *self);
    void (*accelerate)(void *self);
    void (*brake)(void *self);
    void *self_ptr;   /* points to the real car object */
} Vehicle;

/* Car type */
typedef struct {
    Vehicle vtable;
    const char *name;
} Car;

/* Car behavior functions */
void car_startEngine(void *self) {
    printf("Engine started!\n");
}

void car_accelerate(void *self) {
    Car *c = (Car *)self;
    printf("Car: Pressing gas pedal... (%s)\n", c->name);
}

void car_brake(void *self) {
    Car *c = (Car *)self;
    printf("Car: Applying brakes... (%s)\n", c->name);
}

/* Constructor */
Car *createCar(const char *name) {
    Car *c = malloc(sizeof(Car));
    if (!c) return NULL;

    c->name = name;

    c->vtable.startEngine = car_startEngine;
    c->vtable.accelerate  = car_accelerate;
    c->vtable.brake       = car_brake;
    c->vtable.self_ptr    = c;

    return c;
}

int main() {
    Car *janeCar = createCar("Jane's car");
    Car *jackCar = createCar("Jack's car");

    janeCar->vtable.startEngine(janeCar);
    janeCar->vtable.accelerate(janeCar);
    janeCar->vtable.brake(janeCar);

    jackCar->vtable.startEngine(jackCar);
    jackCar->vtable.accelerate(jackCar);
    jackCar->vtable.brake(jackCar);

    free(janeCar);
    free(jackCar);

    return 0;
}
