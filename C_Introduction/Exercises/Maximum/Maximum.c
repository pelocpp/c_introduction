// =====================================================================================
// Maximum.c
// =====================================================================================

#include <stdio.h>

void exercise_maximum_solution_01()
{
    // Find largest among three numbers using if..else statement

    int n1 = -4;
    int n2 = 5;
    int n3 = 2;

    if (n1 >= n2 && n1 >= n3) 
    {
        printf("%d is the largest number!", n1);
    }
    else if (n2 >= n1 && n2 >= n3)
    {
        printf("%d is the largest number!", n2);
    }
    else 
    {
        printf("%d is the largest number!", n3);
    }
}

void exercise_maximum_solution_02()
{
    // Find the largest number among three using nested if..else statement

    int n1 = -4;
    int n2 = 5;
    int n3 = 2;

    if (n1 >= n2)
    {
        if (n1 >= n3) 
        {
            printf("%d is the largest number!", n1);
        }
        else 
        {
            printf("%d is the largest number!", n3);
        }
    }
    else 
    {
        if (n2 >= n3) 
        {
            printf("%d is the largest number!", n2);
        }
        else 
        {
            printf("%d is the largest number!", n3);
        }
    }
}

void exercise_maximum()
{
    exercise_maximum_solution_01();
    exercise_maximum_solution_02();
}

// =====================================================================================
// End-of-File
// =====================================================================================
