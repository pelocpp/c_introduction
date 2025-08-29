// =====================================================================================
// ContactsDynamic.c
// =====================================================================================

#define _CRTDBG_MAP_ALLOC

#include <stdio.h>
#include <stdlib.h>  // malloc, free
#include <crtdbg.h>
#include <string.h>

// ==========================================
// Kontakte-Verwaltung

#define MaxContacts          10
#define MaxNameBufferLength  32

#define NotEmpty             0
#define Empty                1

struct Contact
{
    char*     m_firstName;
    char*     m_lastName;
    size_t    m_phone;
    int       m_isEmpty;
};

// global
struct Contact g_Contacts[MaxContacts];

// ==========================================
// function prototypes

static void initContacts();
static void enterContact();
static void searchContact();
static void printContact(struct Contact* contact);
static void clearContacts();
static void printfMenu();

// ==========================================

static void initContacts()
{
    for (int i = 0; i < MaxContacts; i++) {

        g_Contacts[i].m_isEmpty = Empty;
    }
}

static void enterContact()
{
    char buffer[MaxNameBufferLength] = { '\0' };
    int  number;
    char* ptrFirstName;
    char* ptrLastName;

    printf("Bitte Vornamen eingeben: ");
    scanf_s("%s", buffer, MaxNameBufferLength);

    // allocate dynamic memory according to the exact size of the name
    size_t lenFirstName = 1 + strlen(buffer); // includíng '\0' !!!
    ptrFirstName = (char*) malloc(lenFirstName * sizeof(char));
    if (ptrFirstName == NULL) {
        return;
    }
    strcpy_s(ptrFirstName, lenFirstName * sizeof(char), buffer);

    printf("Bitte Nachnamen eingeben: ");
    scanf_s("%s", buffer, MaxNameBufferLength);

    // allocate dynamic memory according to the exact size of the name
    size_t lenLastName = 1 + strlen(buffer); // includíng '\0' !!!
    ptrLastName = (char*) malloc(lenLastName * sizeof(char));
    if (ptrLastName == NULL) {
        return;
    }
    strcpy_s(ptrLastName, lenLastName * sizeof(char), buffer);

    printf("Bitte Tel.Nummer eingeben: ");
    scanf_s("%d", &number);

    struct Contact tmp = { ptrFirstName , ptrLastName, number, NotEmpty };

    // enter temporary contact into global array
    int succeeded = 0;

    for (int i = 0; i < MaxContacts; i++) {

        if (g_Contacts[i].m_isEmpty == Empty) {

            g_Contacts[i] = tmp;
            succeeded = 1;
            break;
        }
    }

    if (succeeded == 0) {
        printf("Contacts Folder full !\n");
    }
}

static void searchContact()
{
    char firstName[MaxNameBufferLength] = { 0 };
    char lastName[MaxNameBufferLength] = { 0 };;

    printf("Bitte Vornamen eingeben: ");
    scanf_s("%s", firstName, MaxNameBufferLength);

    printf("Bitte Nachnamen eingeben: ");
    scanf_s("%s", lastName, MaxNameBufferLength);

    // search corresponding contact in global array
    int succeeded = 0;

    for (int i = 0; i < MaxContacts; i++) {

        if (g_Contacts[i].m_isEmpty == NotEmpty) {

            struct Contact tmp = g_Contacts[i];

            if (strcmp(tmp.m_firstName, firstName) == 0 && strcmp(tmp.m_lastName, lastName) == 0)
            {
                printf("%s %s hat die Telefonnummer %zu\n", firstName, lastName, tmp.m_phone);
                succeeded = 1;
                break;
            }
        }
    }

    if (succeeded == 0) {
        printf("%s %s im Telefonbuch nicht gefunden!\n", firstName, lastName);
    }
}

static void printContact(struct Contact* contact)
{
    printf("   Vorname:  %s\n", contact->m_firstName);
    printf("   Nachname: %s\n", contact->m_lastName);
    printf("   Phone:    %zu\n", contact->m_phone);
    printf("\n");
}

static void printContacts()
{
    for (int i = 0; i < MaxContacts; i++) {

        if (g_Contacts[i].m_isEmpty == 0) {

            printContact(&g_Contacts[i]);
        }
    }
}

static void clearContacts()
{
    for (int i = 0; i < MaxContacts; i++) {

        if (g_Contacts[i].m_isEmpty == 0) {

            free(g_Contacts[i].m_firstName);
            free(g_Contacts[i].m_lastName);

            g_Contacts[i].m_firstName = NULL;
            g_Contacts[i].m_lastName = NULL;

            g_Contacts[i].m_isEmpty = Empty;
        }
    }
}

static void printfMenu()
{
    initContacts();

    int fertig = 1;   // 1 == nicht fertig, 0 ist fertig

    while (fertig != 0) {

        // printf - menu :)
        printf("\n\n");
        printf("Meine Kontakte:\n\n");
        printf("Bitte Aktion waehlen:\n");
        printf("(1) = Kontakte ausgeben\n");
        printf("(2) = Kontakt eingeben\n");
        printf("(3) = Kontakt suchen\n");
        printf("(4) = Alle Kontakte loeschen\n");
        printf("(5) = Programm verlassen\n");

        int aktion = -1;

        scanf_s("%d", &aktion);

        switch (aktion)
        {
        case 1:
            printContacts();
            break;
        case 2:
            enterContact();
            break;
        case 3:
            searchContact();
            break;
        case 4:
            clearContacts();
            break;
        case 5:
            clearContacts();
            fertig = 0;
            break;
        default:
            printf("Menue unbekannt: %d\n", aktion);
            break;
        }
    }
}

void exercise_contacts_dynamic()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    printfMenu();
}

// =====================================================================================
// End-of-File
// =====================================================================================
