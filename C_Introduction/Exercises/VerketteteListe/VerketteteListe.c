// =====================================================================================
// LinkedList.c
// =====================================================================================

#define _CRTDBG_MAP_ALLOC

// ===========================================================================================
// Includes

#include <stdio.h>
#include <stdlib.h>  // malloc, free
#include <crtdbg.h>

// =====================================================================================
// Types

struct ListItem
{
    int               m_value;
    struct ListItem*  m_next;
};

struct LinkedList
{
    struct ListItem*  m_root;
    size_t            m_count;
};

// =====================================================================================
// Function Prototypes

void addHead           (struct LinkedList* list, int value);
void addHeadEx         (struct LinkedList* list, int value);
void addTail           (struct LinkedList* list, int value);
int  find              (struct LinkedList* list, int value);
int  insert            (struct LinkedList* list, int value, size_t pos);
void freeList          (struct LinkedList* list);
void freeListEx        (struct LinkedList* list);
void freeListRecursive (struct ListItem* item);
void printList         (struct LinkedList* list);
void printItem         (struct ListItem* item);

// =====================================================================================
// Implementation

static void addHead(struct LinkedList* list, int value)
{
    // create a new node
    struct ListItem* item = (struct ListItem*) malloc(sizeof(struct ListItem));
    if (item == (struct ListItem*)0) {
        return;
    }

    item->m_value = value;
    item->m_next = (struct ListItem*)0;

    if (list->m_root == (struct ListItem*)0)
    {
        list->m_root = item;
    }
    else
    {
        item->m_next = list->m_root;
        list->m_root = item;
    }

    list->m_count++;
}

static void addHeadEx(struct LinkedList* list, int value)
{
    // create a new node
    struct ListItem* item = (struct ListItem*) malloc(sizeof(struct ListItem));
    if (item == (struct ListItem*)0) {
        return;
    }

    // setup node
    item->m_value = value;
    item->m_next = list->m_root;

    // update list
    list->m_root = item;
    list->m_count++;
}

static void addTail(struct LinkedList* list, int value)
{
    // create a new node
    struct ListItem* item = (struct ListItem*) malloc(sizeof(struct ListItem));
    if (item == (struct ListItem*)0) {
        return;
    }

    item->m_value = value;
    item->m_next = (struct ListItem*) 0;

    if (list->m_root == (struct ListItem*) 0)
    {
        list->m_root = item;
    }
    else
    {
        // search end of list
        struct ListItem* last = list->m_root;
        while (last->m_next != (struct ListItem*)0) {
            last = last->m_next;
        }

        // append node
        last->m_next = item;
    }

    list->m_count++;
}

static int find(struct LinkedList* list, int value)
{
    struct ListItem* current = list->m_root;

    while (current != (struct ListItem*)0)
    {
        if (current->m_value == value) {
            return 1;
        }

        current = current->m_next;
    }

    return 0;  // element not found
}

static int insert(struct LinkedList* list, int value, size_t pos)
{
    // verify params
    if (pos > list->m_count)
        return 0;

    // create a new node
    struct ListItem* item = (struct ListItem*) malloc(sizeof(struct ListItem));
    if (item == (struct ListItem*) 0) {
        return 0;
    }

    item->m_value = value;

    if (pos == 0)
    {
        item->m_next = list->m_root;
        list->m_root = item;
    }
    else // pos >= 1
    {
        struct ListItem* current = list->m_root;
        while (pos - 1 != 0)
        {
            current = current->m_next;
            pos--;
        }

        item->m_next = current->m_next;
        current->m_next = item;
    }

    list->m_count++;

    return 1;
}

void freeList(struct LinkedList* list) {

    struct ListItem* next = list->m_root;
    struct ListItem* prev;

    while (next != (struct ListItem*) 0) {

        prev = next;

        next = next->m_next;

        free(prev);
    }
}

void freeListEx(struct LinkedList* list)
{
    struct ListItem* item = list->m_root;

    freeListRecursive(item);
}

void freeListRecursive(struct ListItem* item) {

    if (item->m_next != (struct ListItem*) 0)
    {
        freeListRecursive(item->m_next);
    }

    free(item);
}

static void printItem(struct ListItem* item)
{
    printf("%d", item->m_value);
}

static void printList(struct LinkedList* list)
{
    struct ListItem* item = list->m_root;

    printf("[");

    while (item != (struct ListItem*)0)
    {
        if (item != list->m_root) {
            printf(",");
        }

        printItem(item);

        item = item->m_next;
    }

    printf("] (%zu elements)\n", list->m_count);
}

// =====================================================================================
// application

static void exercise_linked_list_01()
{
    struct LinkedList list = { (struct ListItem*) 0, 0 };

    list.m_root = 0;
    list.m_count = 0;

    // test addHead
    for (int i = 0; i < 5; i++) {
        addHead(&list, 2 * i);
    }

    printList(&list);

    // test addTail
    for (int i = 0; i < 5; i++) {
        addTail(&list, 20 * i);
    }

    printList(&list);

    printf("Searching 8: %d\n", find(&list, 8));
    printf("Searching 39: %d\n", find(&list, 39));
    printf("Searching 80: %d\n", find(&list, 80));

    freeListEx(&list);
}

static void exercise_linked_list_02()
{
    struct LinkedList list = { (struct ListItem*)0, 0 };
    insert(&list, 10, 0);
    printList(&list);

    addHead(&list, 11);
    addHead(&list, 12);
    printList(&list);

    insert(&list, 20, 0);
    printList(&list);

    insert(&list, 21, 4);
    printList(&list);

    insert(&list, 22, 2);
    printList(&list);
}

void exercise_linked_list ()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // create a new node
    struct ListItem* item = (struct ListItem*)malloc(sizeof(struct ListItem));
    if (item == (struct ListItem*)0) {
        return;
    }

   // exercise_linked_list_01();
    // exercise_linked_list_02();
}

// =====================================================================================
// End-of-File
// =====================================================================================

//
//class LinkedList
//{
//    friend ostream& operator<< (ostream&, LinkedList&);
//
//private:
//    // member data
//    ListItem* m_root;
//    int m_count;
//
//public:
//    // c'tors and d'tor
//    LinkedList();
//    LinkedList(const LinkedList&);
//    ~LinkedList();
//
//    // public interface
//    void AddHead(int);              // insert item at begin of list
//    void AddTail(int);              // insert item at end of list
//    bool Insert(int, int);          // insert item at a specified position
//    bool RemoveItemAtPosition(int); // remove item at specified position
//    bool RemoveItem(int);           // remove specified item
//    void RemoveAll();               // remove all items
//    bool Contains(int);             // find item
//    int  Size();                    // retrieve length of linked list
//    bool IsEmpty();                 // is list empty
//    void Concat(const LinkedList&); // concatenation of two lists
//    void Reverse();                 // reverse list
//
//    // additional operators
//    friend LinkedList operator+ (const LinkedList&, const LinkedList&);
//    friend LinkedList& operator+= (LinkedList&, const LinkedList&);
//    friend LinkedList& operator+= (LinkedList&, int);
//    friend LinkedList& operator-= (LinkedList&, int);
//
//    // comparison operators
//    friend bool operator== (const LinkedList&, const LinkedList&);
//    friend bool operator!= (const LinkedList&, const LinkedList&);
//
//    // assignment operator
//    LinkedList& operator= (const LinkedList&);
//};
