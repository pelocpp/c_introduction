// ===========================================================================
// GenericProgramming.c
// ===========================================================================

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <stdio.h>
#include <string.h>

// ---------------------------------------------------------------------------

struct key_value_pair
{
    char* m_key;
    void* m_value;
};

typedef struct key_value_pair KeyValuePair;

static KeyValuePair* newKeyValue   (char* key, void* value);
static KeyValuePair* copyKeyValue  (KeyValuePair* in);
static void          freeKeyValue  (KeyValuePair* in);
static int           keyMatches    (char const* key, KeyValuePair* in);

static KeyValuePair* newKeyValue(char* key, void* value)
{
    KeyValuePair* out = malloc(sizeof(KeyValuePair));
    if (out == NULL) {
        exit(-1);
    }

    *out = (KeyValuePair){ .m_key = key, .m_value = value };
    return out;
}

static KeyValuePair* copyKeyValue(KeyValuePair* in)
{
    KeyValuePair* out = malloc(sizeof(KeyValuePair));
    if (out == NULL) {
        exit(-1);
    }

    *out = *in;  // structure assignment
    return out;
}

static void freeKeyValue(KeyValuePair* in)
{
    free(in);
}

static int keyMatches(char const* key, KeyValuePair* in)
{
    int result = strcmp(key, in->m_key);
    return result;
}

// ---------------------------------------------------------------------------

struct dictionary
{
    KeyValuePair** m_pairs;
    int            m_size;
};

typedef struct dictionary Dictionary;

static Dictionary* dictionary_new               ();
static void        dictionary_add_key_value     (Dictionary* in, KeyValuePair* kv);
static void        dictionary_add_key_and_value (Dictionary* in, char* key, void* value);
static void*       dictionary_find              (const Dictionary* in, char const* key);
static Dictionary* dictionary_copy              (const Dictionary* in);
static void        dictionary_free              (Dictionary* in);
static void        dictionary_print_keys        (Dictionary* in);

static Dictionary* dictionary_new()
{
    Dictionary* out = malloc(sizeof(Dictionary));
    if (out == NULL) {
        exit(-1);
    }

    *out = (Dictionary){ .m_pairs = NULL, .m_size = 0 };
    return out;
}

static void dictionary_add_key_value(Dictionary* in, KeyValuePair* kv)
{
    ++in->m_size;

    // assign the result of realloc to a temporary pointer variable,
    // and then replace the original pointer after successful reallocation

    KeyValuePair** tmp = realloc(in->m_pairs, in->m_size * sizeof(KeyValuePair*));
    if (tmp == NULL) {
        exit(-1);
    }
    in->m_pairs = tmp;

    // add new key/value pair at the end
    in->m_pairs[in->m_size - 1] = kv;
}

static void dictionary_add_key_and_value(Dictionary* in, char* key, void* value)
{
    if (key == (char*)0) {
        return;
    }

    dictionary_add_key_value(in, newKeyValue(key, value));
}

static void* dictionary_find(const Dictionary* in, char const* key)
{
    for (int i = 0; i < in->m_size; ++i) {
        if (keyMatches(key, in->m_pairs[i]) == 0) {
            return in->m_pairs[i]->m_value;
        }
    }
    return NULL;
}

static Dictionary* dictionary_copy(const Dictionary* in)
{
    Dictionary* out = dictionary_new();

    for (int i = 0; i < in->m_size; ++i) {
        KeyValuePair* kv = copyKeyValue(in->m_pairs[i]);
        dictionary_add_key_value(out, kv);
    }

    return out;
}

static void dictionary_free(Dictionary* in)
{
    for (int i = 0; i < in->m_size; ++i) {
        free(in->m_pairs[i]);
    }
    free(in->m_pairs);
    free(in);
}

static void dictionary_auto_free(Dictionary* in)
{
    for (int i = 0; i < in->m_size; ++i) {
        free(in->m_pairs[i]);
    }
    free(in->m_pairs);
}

static void dictionary_print_keys(Dictionary* in)
{
    printf("Dictionary: %d entries:\n", in->m_size);
    for (int i = 0; i < in->m_size; ++i) {
        printf("%02d:\t%s\n", (i + 1), in->m_pairs[i]->m_key);
    }
}

// ---------------------------------------------------------------------------

static void testDictionary_01()
{
    // testing a dictionary allocated on the stack
    // values are of type 'float', allocated also on the stack

    float one = 1.0f;
    float two = 2.0f;
    float three = 3.0f;
    float four = 4.0f;

    Dictionary dict = { .m_pairs = NULL, .m_size = 0 };

    dictionary_add_key_and_value(&dict, "float one", &one);
    dictionary_add_key_and_value(&dict, "float two", &two);
    dictionary_add_key_and_value(&dict, "float three", &three);
    dictionary_add_key_and_value(&dict, "float four", &four);

    dictionary_print_keys(&dict);

    char* key = "float one";
    float* fp = dictionary_find(&dict, key);
    printf("float:  %f\n", *fp);

    key = "float two";
    fp = dictionary_find(&dict, key);
    printf("float:  %f\n", *fp);

    key = "float three";
    fp = dictionary_find(&dict, key);
    printf("float:  %f\n", *fp);

    key = "float four";
    fp = dictionary_find(&dict, key);
    printf("float:  %f\n", *fp);

    void* unknown = dictionary_find(&dict, "what");
    if (unknown == (void*)0) {
        printf("'what' not found!\n");
    }

    dictionary_auto_free(&dict);
}

static void testDictionary_02()
{
    // testing a dictionary allocated on the stack
    // values are of type 'float', allocated on the heap

    float* fp1 = malloc(sizeof(float));
    if (fp1 == NULL) {
        exit(-1);
    }

    float* fp2 = malloc(sizeof(float));
    if (fp2 == NULL) {
        exit(-1);
    }

    *fp1 = 1.0f;
    *fp2 = 2.0f;

    Dictionary dict = { .m_pairs = NULL, .m_size = 0 };

    dictionary_add_key_and_value(&dict, "float one", fp1);
    dictionary_add_key_and_value(&dict, "float two", fp2);

    dictionary_print_keys(&dict);

    char* key = "float one";
    float* fp = dictionary_find(&dict, key);
    printf("float:  %f\n", *fp);

    key = "float two";
    fp = dictionary_find(&dict, key);
    printf("float:  %f\n", *fp);

    free(fp1);
    free(fp2);
    dictionary_auto_free(&dict);
}

static void testDictionary_03()
{
    // testing a dictionary allocated on the stack
    // values are of different type - imho: don't do that

    short one = 1;
    int two = 2;
    float three = 3.0f;
    double four = 4.0;

    Dictionary dict = { .m_pairs = NULL, .m_size = 0 };

    dictionary_add_key_and_value(&dict, "a short", &one);
    dictionary_add_key_and_value(&dict, "an int", &two);
    dictionary_add_key_and_value(&dict, "a float", &three);
    dictionary_add_key_and_value(&dict, "a double", &four);

    dictionary_print_keys(&dict);

    short* sp = dictionary_find(&dict, "a short");
    printf("short:  %d\n", *sp);

    int* ip = dictionary_find(&dict, "an int");
    printf("int:    %d\n", *ip);

    float* fp = dictionary_find(&dict, "a float");
    printf("float:  %f\n", *fp);

    double* dp = dictionary_find(&dict, "a double");
    printf("double: %f\n", *dp);

    void* unknown = dictionary_find(&dict, "what");
    if (unknown == (void*)0) {
        printf("'what' not found!\n");
    }

    dictionary_auto_free(&dict);
}

static void testDictionary_04()
{
    // testing a dictionary allocated on the heap
    // values are of type short

    short one = 1;
    short two = 2;

    Dictionary* dict = dictionary_new();

    dictionary_add_key_and_value(dict, "first short", &one);
    dictionary_add_key_and_value(dict, "second short", &two);

    short* s = dictionary_find(dict, "first short");
    printf("s1: %d\n", *s);

    s = dictionary_find(dict, "second short");
    printf("s2: %d\n", *s);

    dictionary_free(dict);
}

static void testDictionary_05()
{
    // testing a dictionary allocated on the heap
    // values are of type short
    // testing dictionary copy

    short one = 1;
    short two = 2;

    Dictionary* dict = dictionary_new();

    dictionary_add_key_and_value(dict, "first short", &one);
    dictionary_add_key_and_value(dict, "second short", &two);

    Dictionary* copy = dictionary_copy(dict);

    short* s = dictionary_find(dict, "first short");
    printf("s1: %d\n", *s);
    s = dictionary_find(dict, "second short");
    printf("s2: %d\n", *s);

    s = dictionary_find(copy, "first short");
    printf("copy s1: %d\n", *s);
    s = dictionary_find(copy, "second short");
    printf("copy s2: %d\n", *s);

    dictionary_free(dict);
    dictionary_free(copy);
}

struct Point
{
    int x;
    int y;
};

static void testDictionary_06()
{
    // testing a dictionary allocated on the heap
    // values are of type 'struct Point', allocated on the stack

    struct Point p1 = { .x = 1, .y = 2 };
    struct Point p2 = { .x = 3, .y = 4 };

    Dictionary* dict = dictionary_new();

    dictionary_add_key_and_value(dict, "first point", &p1);
    dictionary_add_key_and_value(dict, "second point", &p2);

    struct Point* p = dictionary_find(dict, "first point");
    printf("Point: (%d,%d)\n", p->x, p->y);

    p = dictionary_find(dict, "second point");
    printf("Point: (%d,%d)\n", p->x, p->y);

    dictionary_free(dict);
}

static void testDictionary_07()
{
    // testing a dictionary allocated on the heap
    // values are of type 'struct Point', allocated also on the heap

    struct Point* p1 = malloc(sizeof(struct Point));
    if (p1 == NULL) {
        exit(-1);
    }

    struct Point* p2 = malloc(sizeof(struct Point));
    if (p2 == NULL) {
        exit(-1);
    }

    *p1 = (struct Point){ .x = 1, .y = 2 };
    *p2 = (struct Point){ .x = 3, .y = 4 };

    Dictionary* dict = dictionary_new();

    dictionary_add_key_and_value(dict, "first point", p1);
    dictionary_add_key_and_value(dict, "second point", p2);

    struct Point* p = dictionary_find(dict, "first point");
    printf("Point: (%d,%d)\n", p->x, p->y);

    p = dictionary_find(dict, "second point");
    printf("Point: (%d,%d)\n", p->x, p->y);

    free(p1);
    free(p2);
    dictionary_free(dict);
}

// ---------------------------------------------------------------------------

void mainGenericProgramming()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    testDictionary_01();
    testDictionary_02();
    testDictionary_03();
    testDictionary_04();
    testDictionary_05();
    testDictionary_06();
    testDictionary_07();
}

// ===========================================================================
// End-of-File
// ===========================================================================
