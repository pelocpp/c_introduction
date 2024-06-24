// =====================================================================================
// HashTable.h
// =====================================================================================

// defines
// #define  Limit                  7
#define  Limit                  11

// types
struct element
{
    char                        m_key[12];
    char                        m_value[32];
    struct element*             m_next;
};

typedef struct element          Element;

// global variables
extern Element*                 hashTableEx[Limit];

// functions
size_t hash                     (char key[]);
void   initHashTableEx          (Element* table[], int length);
void   fillHashTableEx          (Element* table[]);
void   insert                   (Element* table[], Element element);
int    searchEx                 (char key[], Element* table[], Element** result, size_t* pos);
void   printFirstTableElement   (size_t i, Element* element);
void   printTableElement        (Element* element);
void   printHashTableEx         (Element* table[], int length);
void   releaseHashTableEx       (Element* table[], int length);

// =====================================================================================
// End-of-File
// =====================================================================================
