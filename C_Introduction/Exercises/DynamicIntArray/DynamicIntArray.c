//// =====================================================================================
//// DynamicIntArray.c
//// =====================================================================================
//
//#include <stdio.h>
//
//// ===========================================================================================
//// Dynamic Array
//// Implementation
//
//#include "Exercise_DynamicArray.h"
//
//// =================================================================================
//// =================================================================================
//
//void initDynamicIntArray(struct DynamicIntArray* da, size_t length)
//{
//    int* tmp = (int*)calloc(length, sizeof(int));
//    if (tmp == NULL) {
//        printf("initDynamicIntArray: Out of memory");
//        exit(-1);
//    }
//
//    da->m_ptr = tmp;
//    da->m_length = length;
//}
//
//void releaseDynamicIntArray(struct DynamicIntArray* da)
//{
//    if (da->m_ptr != NULL) {
//
//        free(da->m_ptr);
//
//        da->m_ptr = NULL;
//        da->m_length = 0;
//    }
//}
//
//void createDynamicIntArrayFromArray(struct DynamicIntArray* array, int* values, int length)
//{
//    array->m_ptr = (int*)malloc(sizeof(int) * length);
//    if (array->m_ptr == (int*)0) {
//        return;
//    }
//
//    for (int i = 0; i < length; i++) {
//        array->m_ptr[i] = values[i];
//    }
//
//    array->m_length = length;
//}
//
//
//void createDynamicIntArrayFromDynamicIntArray(struct DynamicIntArray* array, struct DynamicIntArray* other)
//{
//    array->m_ptr = (int*)malloc(sizeof(int) * other->m_length);
//    if (array->m_ptr == (int*)0) {
//        printf("Out of memory");
//        return;
//    }
//
//    for (int i = 0; i < other->m_length; i++) {
//        array->m_ptr[i] = other->m_ptr[i];
//    }
//
//    array->m_length = other->m_length;
//}
//
//void fillDynamicIntArray(struct DynamicIntArray* array, int value)
//{
//    for (int i = 0; i < array->m_length; i++) {
//        array->m_ptr[i] = value;
//    }
//}
//
//size_t getLength(struct DynamicIntArray* array)
//{
//    return array->m_length;
//}
//
//int get(struct DynamicIntArray* array, int index)
//{
//    if (index < array->m_length) {
//        return array->m_ptr[index];
//    }
//    else {
//        printf("Wrong Index: %d [Length = %zu]\n", index, array->m_length);
//        return -1;
//    }
//}
//
//void set(struct DynamicIntArray* array, int index, int value)
//{
//    if (index < array->m_length) {
//        array->m_ptr[index] = value;
//    }
//    else {
//        printf("Wrong Index: %d [Length = %zu]\n", index, array->m_length);
//    }
//}
//
//// STL: std::vector ==> shrink_to_fit
//// int shrinkToFitDynamicIntArray(struct DynamicIntArray* array);
//
//int resizeDynamicIntArray(struct DynamicIntArray* array, int newLength)
//{
//    if (newLength <= array->m_length)
//    {
//        // just shorten length, keep buffer
//        array->m_length = newLength;
//
//        return 1;
//    }
//    else {
//
//        // allocate new (temporary) buffer
//        int* tmp = (int*)calloc(newLength, sizeof(int));
//        if (tmp == NULL) {
//            printf("initDynamicIntArray: Out of memory");
//            exit(-1);   // beendet das Programm
//            // return 0;
//        }
//        else {
//
//            // copy current buffer into new one
//            for (size_t i = 0; i < array->m_length; ++i) {
//                tmp[i] = array->m_ptr[i];
//            }
//
//            // release current buffer
//            free(array->m_ptr);
//
//            // switch to new buffer
//            array->m_ptr = tmp;
//            array->m_length = newLength;
//
//            return 1;
//        }
//    }
//}
//
//int minimum(struct DynamicIntArray* array)
//{
//    if (array->m_length == 0) {
//        return 0;
//    }
//
//    int min = array->m_ptr[0];
//
//    for (int i = 1; i < array->m_length; i++) {
//        if (min > array->m_ptr[i]) {
//            min = array->m_ptr[i];
//        }
//    }
//
//    return min;
//}
//
//int maximum(struct DynamicIntArray* array)
//{
//    if (array->m_length == 0) {
//        return 0;
//    }
//
//    int max = array->m_ptr[0];
//
//    for (int i = 1; i < array->m_length; i++) {
//        if (max < array->m_ptr[i]) {
//            max = array->m_ptr[i];
//        }
//    }
//
//    return max;
//}
//
//int indexOf(struct DynamicIntArray* array, int value)
//{
//    // perform a linear search
//    for (int i = 0; i < array->m_length; i++) {
//        if (array->m_ptr[i] == value) {
//            return i;
//        }
//    }
//
//    return -1;
//}
//
//int equalsDynamicIntArray(struct DynamicIntArray* array, struct DynamicIntArray* other)
//{
//    if (array->m_length != other->m_length) {
//        return 0;
//    }
//
//    for (int i = 0; i < array->m_length; i++) {
//        if (array->m_ptr[i] != other->m_ptr[i]) {
//            return 0;
//        }
//    }
//
//    return 1;
//}
//
//int containsDynamicIntArray(struct DynamicIntArray* array, int value)
//{
//    for (int i = 0; i < array->m_length; i++) {
//        if (array->m_ptr[i] == value) {
//            return 1;
//        }
//    }
//
//    return 0;
//}
//
//
////void printDynamicIntArray(struct DynamicIntArray* da)
////{
////    for (int i = 0; i < da->m_length; ++i) {
////        printf("%03d: %d\n", i, da->m_ptr[i]);
////    }
////    printf("\n");
////}
//
//void printDynamicIntArray(struct DynamicIntArray* array)
//{
//    printf("{");
//    for (int i = 0; i < array->m_length; i++)
//    {
//        printf("%d", array->m_ptr[i]);
//        if (i < array->m_length - 1) {
//            printf(",");
//        }
//    }
//    printf("}\n");
//}
//
//// ==========================================================================
//// ==========================================================================
//
//void exercise_DynamicIntArray_01()
//{
//    struct DynamicIntArray einFeld; // = { NULL, 0 };
//
//    // int n;
//
//    // Ritchie: "A programmer knows what he does"
//    releaseDynamicIntArray(&einFeld);
//}
//
//void exercise_DynamicIntArray_02()
//{
//    struct DynamicIntArray einFeld = { NULL, 0 };
//
//    initDynamicIntArray(&einFeld, 10);
//
//    printDynamicIntArray(&einFeld);
//
//    releaseDynamicIntArray(&einFeld);
//}
//
//
//void exercise_DynamicIntArray_03()
//{
//    struct DynamicIntArray sa = { 0, 0 };
//
//    initDynamicIntArray(&sa, 5);
//
//    fillDynamicIntArray(&sa, 5);
//
//    printDynamicIntArray(&sa);
//
//    resizeDynamicIntArray(&sa, 8);
//
//    printDynamicIntArray(&sa);
//
//    releaseDynamicIntArray(&sa);
//
//    printDynamicIntArray(&sa);
//}
//
//void exercise_DynamicIntArray_04()
//{
//    int values[] = { -10, -5, 0, 5, 10 };
//
//    struct DynamicIntArray sa = { 0, 0 };
//
//    // ===> From C to Objekt Orientierung
//    // ===> Konstruktor
//    // ===> Poor man's choice: Objekt Orientierung in C:
//    // ===> Strukturen mit passenden Funktionen
//
//    createDynamicIntArrayFromArray(&sa, values, 5);
//
//    printDynamicIntArray(&sa);
//
//    int min = minimum(&sa);
//    printf("Minimum: %d\n", min);
//
//    int max = maximum(&sa);
//    printf("Maximum: %d\n", max);
//
//    releaseDynamicIntArray(&sa);
//}
//
//void exercise_DynamicIntArray_05()
//{
//    int values[] = { 10, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
//
//    struct DynamicIntArray sa = { 0, 0 };
//
//    createDynamicIntArrayFromArray(&sa, values, 10);
//
//    printDynamicIntArray(&sa);
//
//    int n = get(&sa, 5);
//    printf("Value at index 5: %d\n", n);
//
//    set(&sa, 5, 30);
//
//    printDynamicIntArray(&sa);
//
//    releaseDynamicIntArray(&sa);
//}
//
//void exercise_DynamicIntArray_06()
//{
//    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//
//    // https://learn.microsoft.com/en-us/cpp/c-runtime-library/find-memory-leaks-using-the-crt-library?view=msvc-170
//
//    int values[] = { 10, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
//
//    struct DynamicIntArray sa = { 0, 0 };
//
//    createDynamicIntArrayFromArray(&sa, values, 10);
//
//    printDynamicIntArray(&sa);
//
//    //   releaseDynamicIntArray(&sa);
//
//    _CrtDumpMemoryLeaks();
//}
//
//
//void exercise_DynamicIntArray_07()
//{
//    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//
//    int values[] = { 10, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
//
//    struct DynamicIntArray sa1 = { 0, 0 };
//
//    createDynamicIntArrayFromArray(&sa1, values, 10);
//
//    // ------------------------
//
//    // Standard C: Hmm, da wird eine neue Struktur-Variable
//    // mit dem Inhalt einer vorhandenen Struktur vorbelegt.
//
//    // Das ist falsch - und eine Schwachstelle !
//    // struct DynamicIntArray sa2 = sa1;    // Da habe ich aktuell keine Idee / Ansatz ==> Absturz
//
//    // Lösung
//    struct DynamicIntArray sa2;
//    createDynamicIntArrayFromDynamicIntArray(&sa2, &sa1);
//
//    printDynamicIntArray(&sa1);
//    printDynamicIntArray(&sa2);
//
//    releaseDynamicIntArray(&sa1);
//    releaseDynamicIntArray(&sa2);    // VORSICHT! DAS MUSS releaseDynamicIntArray anders programmiert werden !!!!!!!!!!! WIE ????
//
//    _CrtDumpMemoryLeaks();
//}
//
//void exercise_DynamicIntArray()
//{
//    //exercise_DynamicIntArray_01();
//    //exercise_DynamicIntArray_02();
//    //exercise_DynamicIntArray_03();
//    //exercise_DynamicIntArray_04();
//    //exercise_DynamicIntArray_05();
//    //exercise_DynamicIntArray_06();
//    exercise_DynamicIntArray_07();
//}
//
//// =================================================================================
//// ==========================================================================
//
//
//
//// =====================================================================================
//// End-of-File
//// =====================================================================================
