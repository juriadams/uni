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
    printf("%-15s %s\n", "Make", car.make);
    printf("%-15s %d\n", "Top Speed", car.topSpeed);
    printf("%-15s %d\n", "Doors", car.doors);
    printf("%-15s %d\n", "Has ABS", car.hasAbs);
    printf("Options\n");
    for (int i = 0; i < sizeof(car.options) / sizeof(car.options[0]); i++)
    {
        printf("    %-11d %s\n", i, car.options[i]);
    }
    printf("Engine\n");
    printf("    %-11s %d\n", "Horse Power", car.engine.hp);
    printf("    %-11s %d\n", "Cylinders", car.engine.cylinders);
    printf("    %-11s %d\n", "Displacement", car.engine.displacement);
}

void addToGarage(Car car)
{
    garage[0] = car;

    for (int i = 0; i < 20; i++)
    {
        if (garage[i].engine.hp == 0)
        {
            garage[i] = car;
        }
        break;
    }
}

void removeFromGarage(Car car)
{
    for (int i = 0; i < (sizeof(garage) / sizeof(garage[0])); i++)
    {
        if (garage[i].make == car.make)
        {
            for (int j = i; j < 20 - 1; j++)
            {
                garage[j] = garage[j + 1];
            }
        }
        break;
    }
}

void printGarage(void)
{
    for (int i = 0; i < 20; i++)
    {
        if (garage[0].engine.hp == 0)
        {
            printf("The Garage seems to be empty.\n");
            return;
        }

        if (garage[i].engine.hp != 0)
        {
            printCar(garage[i]);
        }
    }
}
