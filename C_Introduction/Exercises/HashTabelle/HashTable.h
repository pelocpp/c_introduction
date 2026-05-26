// =====================================================================================
// HashTable.h
// =====================================================================================

// defines
#define  MaxValueSize          6

// types
struct element
{
    size_t                     m_key;
    char                       m_value[MaxValueSize];
    struct element*            m_next;
};

typedef struct element         Element;

// general hash table functions
void   initHashTable           (Element* table[], size_t length);
void   insertElement           (Element* table[], size_t length, Element element);
int    insertKeyValue          (Element* table[], size_t length, size_t key, const char* value);
int    search                  (Element* table[], size_t length, size_t key, Element** result, size_t* pos);
void   printHashTable          (Element* table[], size_t length);
void   releaseHashTable        (Element* table[], size_t length);

// =====================================================================================
// End-of-File
// =====================================================================================
