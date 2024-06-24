// =====================================================================================
// HashTable.h
// =====================================================================================

// defines
#define  Limit                 7
//#define  Limit                 11

// types
struct element
{
    size_t                     m_key;
    char                       m_value[6];
    struct element*            m_next;
};

typedef struct element         Element;

// global variables
extern Element*                hashTable[Limit];

// functions
size_t hash                    (size_t key);
void   initHashTable           (Element* table[], int length);
void   fillHashTable           (Element* table[]);
void   fillHashTable2          (Element* table[]);
void   insert                  (Element* table[], Element element);
int    search                  (size_t key, Element* table[], Element** result, size_t* pos);
void   printFirstTableElement  (size_t i, Element* element);
void   printTableElement       (Element* element);
void   printHashTable          (Element* table[], int length);
void   releaseHashTable        (Element* table[], int length);

// =====================================================================================
// End-of-File
// =====================================================================================
