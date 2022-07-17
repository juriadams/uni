#include <stdio.h>

#include <string.h>

#include "./lib/types.h"

Car garage[20];

int calcValue(Car car)
{
    int value = 0;

    if (car.hasAbs == 1)
    {
        value += 3000;
    }

    for (int i = 0; i < sizeof(car.options); i++)
    {
        if (car.options[i])
        {
            value += 5000;
        }
    }

    value = value + car.topSpeed * 50 * car.doors;

    if (strcmp(car.make, "Porsche"))
    {
        value = value * 2;
    }

    return value;
}

void printCar(Car car)
{
    printf("┌ Car\n");
    printf("├ Make: %s\n", car.make);
    printf("├ Top Speed: %d\n", car.topSpeed);
    printf("├ Doors: %d\n", car.doors);
    printf("├ ABS: %d\n", car.hasAbs);
    printf("├ Options:\n");
    for (int i = 0; i < sizeof(car.options) / sizeof(car.options[0]); i++)
    {
        printf("├   %s\n", car.options[i]);
    }
    printf("├ Engine:\n");
    printf("├   Horse Power: %d\n", car.engine.hp);
    printf("├   Cylinders: %d\n", car.engine.cylinders);
    printf("└   Displacement: %d\n", car.engine.displacement);
}

void addToGarage(Car car)
{
    printCar(car);

    garage[0] = car;
    // for (int i = 0; i < 20; i++) {
    //     if (parkinglot[i] -> engine.ps == 0) {
    //         parkinglot[i] = car;
    //     }
    //     break;
    // }
}

void removeFromGarage(Car car)
{
    // for (int i = 0; i < (sizeof(parkinglot) / sizeof(parkinglot[0])); i++) {
    //     if (parkinglot[i] -> brand == car -> brand) {
    //         for (int j = i; j < 20 - 1; j++) {
    //             parkinglot[j] = parkinglot[j + 1];
    //         }

    //     }
    //     break;

    // }
}

void printGarage(void)
{
    for (int i = 0; i < 20; i++)
    {
        printCar(garage[i]);
    }
}

// int main(int argc, char const *argv[]){
//    return 0;
//}