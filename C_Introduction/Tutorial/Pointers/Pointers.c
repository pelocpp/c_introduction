// ===========================================================================
// Pointers.c // Zeiger (Pointer)
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

void testPointer()
{
    test_pointer_01();
    test_pointer_02();
    test_pointer_03();
    test_pointer_04();
    test_pointer_05_gimmicks();
}

// ===========================================================================
// End-of-File
// ===========================================================================
