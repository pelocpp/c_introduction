// ===========================================================================
// NestedScope.c // Block Schachtelung
// ===========================================================================

#include <stdio.h>

// ===========================================================================

static void testNestedScope_01()
{
    int n = 123;
    printf("n = %d\n", n);

    {
        int n = 456;
        printf("n = %d\n", n);

    }

    printf("n = %d\n", n);
}


// ===========================================================================

static int m = 123;

static void testNestedScope_02()
{
    printf("m = %d\n", m);

    {
        int m = 456;
        printf("m = %d\n", m);

    }

    printf("m = %d\n", m);
}


// ===========================================================================

static void testNestedScope_03()
{
    int n = 1;
    printf("n = %d\n", n);

    {
        int n = 2;
        printf("n = %d\n", n);

        {
            int n = 3;
            printf("n = %d\n", n);

            {
                int n = 4;
                printf("n = %d\n", n);
            }

            printf("n = %d\n", n);
        }

        printf("n = %d\n", n);
    }

    printf("n = %d\n", n);
}

// ===========================================================================

static void testNestedScope_04()
{
    int i = 123;  // <== put into comments
    printf("i = %d\n", i);

    for (int i = 1; i < 5; ++i) {
        printf("%d\n", i);
    }

    printf("i = %d\n", i);
}

// ===========================================================================

void testNestedScope()
{
    testNestedScope_01();
    testNestedScope_02();
    testNestedScope_03();
    testNestedScope_04();
}

// ===========================================================================
// End-of-File
// ===========================================================================
