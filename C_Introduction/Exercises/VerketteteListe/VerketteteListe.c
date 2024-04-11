// =====================================================================================
// LinkedList.c
// =====================================================================================

#define _CRTDBG_MAP_ALLOC

#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>

struct ListItem
{
    int m_value;
    struct ListItem* m_next;
};

struct LinkedList
{
    struct ListItem* m_root;
    int m_count;
};

void addHead(struct LinkedList* list, int value)
{
    // create a new node
    struct ListItem* node = (struct ListItem*) malloc(sizeof(struct ListItem));
    if (node == (struct ListItem*)0) {
        return;
    }

    node->m_value = value;
    node->m_next = (struct ListItem*)0;

    if (list->m_root == (struct ListItem*)0)
    {
        list->m_root = node;
    }
    else
    {
        node->m_next = list->m_root;
        list->m_root = node;
    }

    list->m_count++;
}

void addTail(struct LinkedList* list, int value)
{
    // create a new node
    struct ListItem* node = (struct ListItem*) malloc(sizeof(struct ListItem));
    if (node == (struct ListItem*)0) {
        return;
    }

    node->m_value = value;
    node->m_next = (struct ListItem*)0;

    if (list->m_root == (struct ListItem*)0)
    {
        list->m_root = node;
    }
    else
    {
        // search end of list
        struct ListItem* last = list->m_root;
        while (last->m_next != (struct ListItem*)0) {
            last = last->m_next;
        }

        // append node
        last->m_next = node;
    }

    list->m_count++;
}

int find(struct LinkedList* list, int value)
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

int insert(struct LinkedList* list, int value, int pos)
{
    // verify params
    if (pos < 0 || pos > list->m_count)
        return 0;

    // create a new node
    struct ListItem* node = (struct ListItem*)malloc(sizeof(struct ListItem));
    if (node == (struct ListItem*)0) {
        return 0;
    }

    node->m_value = value;

    if (pos == 0)
    {
        node->m_next = list->m_root;
        list->m_root = node;
    }
    else // i >= 1
    {
        struct ListItem* current = list->m_root;
        while (pos - 1 > 0)
        {
            current = current->m_next;
            pos--;
        }

        node->m_next = current->m_next;
        current->m_next = node;
    }

    list->m_count++;

    return 1;
}

void printItem(struct ListItem* item)
{
    printf("%d", item->m_value);
}

void printList(struct LinkedList* l)
{
    struct ListItem* item = l->m_root;

    printf("[");

    while (item != (struct ListItem*)0)
    {
        if (item != l->m_root) {
            printf(",");
        }

        printItem(item);

        item = item->m_next;
    }

    printf("] (%d elements)\n", l->m_count);
}

void exercise_linked_list_01()
{
    struct LinkedList list = { (struct ListItem*)0, 0 };

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
}

void exercise_linked_list_02()
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

    exercise_linked_list_01();
    exercise_linked_list_02();
}

// =====================================================================================
// End-of-File
// =====================================================================================



// TO BE DONE: AUFRÄUMEN !!!!!!!!!!!!!!!!!!

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
