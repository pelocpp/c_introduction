// ===========================================================================
// Arrays.c // Felder (Arrays)
// ===========================================================================

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define   Length   5

static void arrays_01()
{
    int numbers1[Length] = { 1, 2, 3, 4, 5 };   // array initialization with initializer list

    for (int i = 0; i < Length; i++) {
        printf("%2d: %d\n", i, numbers1[i]);
    }

    // ========================================

    int numbers2[] = { 10, 20, 30, 40, 50 };         // compiler computes length of array

    int length = sizeof(numbers2) / sizeof(int);

    for (int i = 0; i < length; i++) {
        printf("%2d: %d\n", i, numbers2[i]);
    }

    // ========================================

    int numbers3[10] = { 0 };                   // all elements are initialized with zero

    for (int i = 0; i < 10; i++) {
        printf("%2d: %d\n", i, numbers3[i]);
    }
}

static void arrays_02()
{
    int numbers[Length];
    
    int n = numbers[0];  // using uninitialized memory :)
    numbers[0] = 123;

    for (int i = 0; i < Length; i++) {
        numbers[i] = 2 * i;
    }

    for (int i = 0; i < Length; i++) {
        printf("%2d: %d\n", i, numbers[i]);
    }
}

static void arrays_03()
{
    /* designated initializer syntax
    */

    // standard syntax
    int vector1[3] = { [0] = 1, [1] = 2, [2] = 3 };

    // length of array is calculated
    int vector2[] = { [0] = 1, [1] = 2, [2] = 3 };

    // order of initializers doesn't matter
    int vector3[3] = { [2] = 3, [1] = 2, [0] = 1 };

    // list of order initializers may be uncomplete
    int vector4[3] = { [2] = 3 };

    // length of array is calculated again,
    // list of order initializers may be uncomplete
    int vector5[] = { [10] = 10 };
}

static void arrays_04()
{
    // Feld variabler Länge: Never - Arrays are Fixed-Size !

    int n;
    // .......
    n = 123;

    // int numbers [n];   // does NOT compile
}

static void initArray01(int* data, int length)
{
    // watch difference
    printf("sizeof numbers: %zu\n", sizeof(data));
    printf("sizeof int: %zu\n", sizeof(int));
    printf("Length: %zu\n", sizeof(data) / sizeof(*data));

    for (int i = 0; i < length; ++i) {

        data[i] = 2 * i;       // go for this syntax
        // or
        *(data + i) = 2 * i;
    }
}

static void initArray02(int feld[], int length)
{
    // same as above
}

static void initArray03(int feld[10], int length)
{
    // same as above
}

static void arrays_05()
{
    int numbers[Length] = { 0 };

    printf("sizeof numbers: %zu\n", sizeof(numbers));
    printf("sizeof int: %zu\n", sizeof(int));
    printf("Length: %zu\n", sizeof(numbers) / sizeof(*numbers));

    initArray01(numbers, Length);

    initArray02(numbers, Length);

    for (int i = 0; i < Length; ++i) {
        printf("%02d: %d\n", i, numbers[i]);
    }
}

static void randomNumbersDemo()
{
    time_t now;

    time(&now);

    // Seed : Samen ===> "Es wächst eine Pfanze"  

    srand((unsigned int) now);       // Startwert für den Algorithmus  

    // oder
    unsigned int start = 123;
    srand(start);                    // Startwert für den Algorithmus  

    int number = rand();             // Zufallszahlen werden berechnet
    printf("Zufall: %d\n", number);

    number = rand();                 // Zufallszahlen werden berechnet
    printf("Zufall: %d\n", number);

    number = rand();                 // Zufallszahlen werden berechnet
    printf("Zufall: %d\n", number);
}

static void arrays_06()
{
    int numbers[Length] = { 0 };

    time_t now;
    time(&now);
    srand((unsigned int)now); 

    for (int i = 0; i < Length; i++) {
        numbers[i] = rand() % 10 + 1;          // 1 .. 10
    }

    for (int i = 0; i < Length; i++) {
        printf("%2d: %d\n", i, numbers[i]);
    }
}

static void arrays_07()
{
    // Wertzuweisung von Arrays

    // Bei Arrays steht der Name für die ANFANGSADRESSE des Speicherbereichs.
    // Diese ist KONSTANT.

    int numbers1[Length] = { 0 };
    int numbers2[Length] = { 0 };

    // numbers1 = numbers2;                // Wertzuweisung: so nicht !!!!

    for (int i = 0; i < Length; i++) {     // Wertzuweisung
        numbers1[i] = numbers2[i];
    }

    // Das geht:
    *numbers1 = 123;

    // Pointer Arithmetik mit ++
    int* ip = numbers1;
    ip++;
    *ip = 12;
}

static void arrays_08_gimmicks()
{
    int numbers[Length] = { 0 };

    // first gimmick: negative indices are generally defined
    numbers[-3] = 123;

    // second gimmick: pointer arithmetic taken literally :)
    int index = 3;
    *(index + numbers) = 123;

    // third gimmick: do you remember the commutative law.
    3[numbers] = 123;
}

static double sum(double numbers[])
{
    double result = 0.0;
    
    int k = 0;
    while (numbers[k] != 0.0)
    {
        result += numbers[k];
        ++k;
    }

    return result;
}

static void arrays_09()
{
    double values[] = { 1.0, 2.0, 3.0, 4.0, 5.0, 0.0 };
    double result = sum(values);

    // or using a "Compound Literal"

    result = sum((double[]) { 1.0, 2.0, 3.0, 4.0, 5.0, 0.0 });

    // or with a similar syntax:

    double* list = (double[]){ 1.0, 2.0, 3.0, 4.0, 5.0, 0.0 };
    result = sum(list);
}

static double sumSafe(double numbers[])
{
    double result = 0.0;

    int k = 0;
    while (numbers[k] != 0.0)
    {
        result += numbers[k];
        ++k;
    }

    return result;
}

#define SafeSum(...) sumSafe ((double[]) { __VA_ARGS__, 0.0 } )

static void arrays_10()
{

    // or using a "Compound Literal" in combination with __VA_ARGS__

    double result = SafeSum(1.0, 2.0, 3.0, 4.0, 5.0);
}


void mainArrays()
{
    arrays_01();
    arrays_02();
    arrays_03();
    arrays_04();
    randomNumbersDemo();
    arrays_05();
    arrays_06();
    arrays_07();
    arrays_08_gimmicks();
    arrays_09();
    arrays_10();
}

// ===========================================================================
// End-of-File
// ===========================================================================
