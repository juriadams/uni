typedef enum
{
    FALSE,
    TRUE
} bool;

typedef struct
{
    int hp;
    int cylinders;
    int displacement;
} Engine;

typedef struct
{
    char make[20];
    int topSpeed;
    int doors;
    bool hasAbs;
    char options[10][100];
    Engine engine;
} Car;