#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib/commands.h"
#include "garage.c"

void start(void);

void construct(void)
{
    // Body props
    char make[20];
    int topSpeed;
    int doors;
    int hasAbs;
    char options[10][100];

    // Engine props
    int hp;
    int cylinders;
    int displacement;

    printf("Make: ");
    scanf("%s", *&make); // `
    printf("Top Speed: ");
    scanf("%d", &topSpeed);
    printf("Doors: ");
    scanf("%d", &doors);
    printf("ABS (1 for \"yes\", 0 for \"no\"): ");
    scanf("%d", &hasAbs);

    printf("Options (max. 10):\n");

    for (int i = 0; i < 10; i++)
    {
        printf("Part name (\"exit\" to abort): ");

        char name[100];
        scanf("%99s", *&name);

        if (strcmp(name, "exit") == 0)
        {
            break;
        }

        strcpy(options[i], name);
    };

    printf("Horse Power: ");
    scanf("%d", &hp);
    printf("Cylinders: ");
    scanf("%d", &cylinders);
    printf("Displacement: ");
    scanf("%d", &displacement);

    Engine engine;
    engine.hp = hp;
    engine.cylinders = cylinders;
    engine.displacement = displacement;

    Car car;
    strcpy(car.make, make);
    car.topSpeed = topSpeed;
    car.doors = doors;
    car.hasAbs = hasAbs == 1 ? TRUE : FALSE;

    for (int i = 0; i < sizeof(options); i++)
    {
        // ⚠️ Breaking: `SIGSEGV (Address boundary error)`, memalloc?
        // strcpy(car.options[i], options[i]);
    }

    car.engine = engine;

    addToGarage(car);

    printf("\nCar was added to the Garage!\n");
    printf("\nEnter the following command to view all cars:\n\n    ~ print garage");
}

void removeCarFromParkinglot(void)
{
    printf("\nWhat Car would you like to remove from the Garage?\n");

    int input;
    printf("\n~ ");
    scanf("%d", &input);
    printf("\n");

    removeFromGarage(garage[input]);

    printf("\nCar was removed from the Garage!\n");
    printf("\nEnter the following command to view all cars:\n\n    ~ print garage");
}

void estimateCarValue(void)
{
    printf("\nWhat Car would you like to calculate the value of?\n");

    int input;
    printf("\n~ ");
    scanf("%d", &input);
    printf("\n");

    int value = calcValue(garage[input]);
    if (value > 0)
    {
        printf("\nThe Car in spot %d goes for %d\n", input, value);
    }
};

void printCarInformation(void)
{
    printf("\nWhat Car would you like to get the details for?\n");

    int input;
    printf("\n~ ");
    scanf("%d", &input);
    printf("\n");

    printCar(garage[input]);
};

void printAllCars(void)
{
    printGarage();
}

void man(void)
{
    printf("Usage: cli\n");
    printf("\nCommands:\n");
    printf("    %-15s   Show this manual page\n", CLI_PROMPT_HELP);
    printf("    %-15s   Add a new Car to the Garage\n", CLI_PROMPT_NEW);
    printf("    %-15s   Remove a Car from the Garage\n", CLI_PROMPT_REMOVE);
    printf("    %-15s   Calculate the value of a Car\n", CLI_PROMPT_CALC);
    printf("    %-15s   Show details of a Car\n", CLI_PROMPT_PRINT);
    printf("    %-15s   Show details of all Cars\n", CLI_PROMPT_PRINT_ALL);
    printf("    %-15s   Exit the program\n", CLI_PROMPT_EXIT);
}

void start(void)
{
    // Capture user input
    char input[100];
    printf("\n~ ");
    fgets(input, 100, stdin);
    printf("\n");

    // Remove trailing new line character
    if ((strlen(input) > 0) && (input[strlen(input) - 1] == '\n'))
        input[strlen(input) - 1] = '\0';

    if (strcmp(input, CLI_PROMPT_HELP) == 0)
    {
        man();
    }
    else if (strcmp(input, CLI_PROMPT_NEW) == 0)
    {
        construct();
    }
    else if (strcmp(input, CLI_PROMPT_REMOVE) == 0)
    {
        removeCarFromParkinglot();
    }
    else if (strcmp(input, CLI_PROMPT_CALC) == 0)
    {
        estimateCarValue();
    }
    else if (strcmp(input, CLI_PROMPT_PRINT) == 0)
    {
        printCarInformation();
    }
    else if (strcmp(input, CLI_PROMPT_PRINT_ALL) == 0)
    {
        printAllCars();
    }
    else if (strcmp(input, CLI_PROMPT_EXIT) == 0)
    {
        exit(0);
    }
    else
    {
        if (strlen(input) != 1)
            printf("\nInvalid command: `%s\n`", input);
    }

    start();
}

int main()
{
    system("clear");
    man();
    start();
    return 0;
}