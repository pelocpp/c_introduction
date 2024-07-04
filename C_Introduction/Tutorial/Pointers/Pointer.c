// ===========================================================================
// Pointer.c // Zeiger (Pointer)
// ===========================================================================

#include <stdio.h>

static void test_pointer_01()
{
    int n = 0;

    n = 123;

    int* pi = NULL;

    pi = &n;   // Adress-Operator '&'

    // Nomenklatur: Man sagt: eine Adresse einer Variable bilden / eruieren
    // Nomenklatur: Auch:     eine Variable referenzieren (Adresse)

    // Wert der Variablen n ändern
    n = 456;

    // Wert der Variablen n ändern - OHNE den Bezeichern 'n' zu verwenden
    // Indirekter Zugriff

    *pi = 789;   // Indirekten Zugriff (via Adresse): '*'

    // Nomenklatur: Einen Wert einer Variable indirekt zuweisen
    // Nomenklatur: Auch: Eine Variable mit einer Adresse dereferenzieren
}

static void malZwei(int n)
{
    n = 2 * n;
}

static void test_pointer_02()
{
    int x = 123;

    printf("x = %d\n", x);   // 123

    malZwei(x);

    printf("x = %d\n", x);   // 123 oder 246
}

static void malZweiEx(int* pn)   // pn = lokale Variable von malZweiEx
{
    int tmp;                 // tmp = lokale Variable von malZweiEx

    tmp = *pn * 2;

    *pn = tmp;

    // oder

    // *pn = *pn * 2;        // kompakt in einer Zeile :)
}

static void test_pointer_03()
{
    int x = 123;

    printf("x = %d\n", x);                // 123

    int* addressOfx = &x;

    printf("Adresse von x = %p\n", &x);

    malZweiEx(&x);
    // oder
    // malZweiEx(addressOfx);

    printf("x = %d\n", x);                // 123
}

static void test_pointer_04()
{
    int n = 0;
    int* pi = NULL;

    pi = &n;
    *pi = 123;

    printf("n = %d\n", n);                // 123

    // =======================================
    // Zeigerarithmetik

    // pi++;
    // oder
    pi = pi + 1;  // Auch hier werden 4 Bytes auf die Adresse dazu gezählt
                  // 1 steht für sizeof (int)

    printf("n = %d\n", *pi);              // ???

    // geht das: Ja, das geht -- ist aber FALSCH / UNZULÄSSIG
    *pi = 789;
    printf("n = %d\n", *pi);              // ???

    // wieder im zulässigen Bereich
    pi--;
    printf("n = %d\n", *pi);              // 123
}

static void test_pointer_05_gimmicks()
{
    unsigned int n = 0xAABBCCDD;

    unsigned int* ip = &n;

    printf("Wert: %x\n", n);

    unsigned char* cp;

    cp = (char*)ip;

    unsigned char ch = *cp;

    printf("Char Wert: %x\n", ch);

    ++cp;

    printf("Char Wert: %x\n", *cp);

    *cp = 0;

    printf("Wert: %x\n", n);
}

// ===========================================================================

static void test_pointer_06_pointer_of_pointer()
{
    int n = 123;

    int* ip = &n;
    int** ip2 = &ip;
    int*** ip3 = &ip2;
    int**** ip4 = &ip3;

    int m;
    m = *ip;
    m = **ip2;
    m = ***ip3;
    m = ****ip4;

    printf("Wert von n: %d\n", n);
    printf("Wert von n: %d\n", *ip);
    printf("Wert von n: %d\n", **ip2);
    printf("Wert von n: %d\n", ***ip3);
    printf("Wert von n: %d\n", ****ip4);
}

// ===========================================================================

// function with an int parameter and void return type 

static void function(int a)
{
    printf("Value: %d\n", a);
}

static void test_pointer_07_function_pointer_01()
{
    // Zeiger einer Funktion // Adresse einer Funktion // Funktionszeiger
    void (*fp)(int a);
    fp = &function;

    // oder
    void (*fp1)(int a) = &function;

    // oder - gleichbedeutend
    void (*fp2)(int a) = function;

    // Aufruf der Funktion mittels Funktionszeiger
    (*fp)(123);
    (*fp1)(456);
    (*fp2)(789);
}

// ===========================================================

static int add(int a, int b)
{
    printf("add: %d+%d=%d\n", a, b, a + b);
    return a + b;
}

static int sub(int a, int b)
{
    printf("sub: %d-%d=%d\n", a, b, a - b);
    return a + b;
}

static int mul(int a, int b)
{
    printf("mul: %d*%d=%d\n", a, b, a * b);
    return a + b;
}

static int div(int a, int b)
{
    printf("div: %d/%d=%d\n", a, b, a / b);
    return a + b;
}

void test_pointer_07_function_pointer_02()
{
    // 'calculator' is an array of function pointers 
    // See 'Jump Table'

    int (*(calculator[])) (int, int) =
    {
        add, sub, mul, div
    };

    int result = 0;

    result = (*calculator[0])(8, 4);
    result = (*calculator[1])(8, 4);
    result = (*calculator[2])(8, 4);
    result = (*calculator[3])(8, 4);
}

// ===========================================================================

void mainPointer()
{
    test_pointer_01();
    test_pointer_02();
    test_pointer_03();
    test_pointer_04();
    test_pointer_05_gimmicks();
    test_pointer_06_pointer_of_pointer();
    test_pointer_07_function_pointer_01();
    test_pointer_07_function_pointer_02();
}

// ===========================================================================
// End-of-File
// ===========================================================================
