// =====================================================================================
// ContactsStatic.c
// =====================================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ==========================================
// Kontakte-Verwaltung

#define MaxContacts    10
#define MaxNameLength  32

#define NotEmpty       0
#define Empty          1

struct Contact
{
    char     m_firstName[MaxNameLength];
    char     m_lastName[MaxNameLength];
    size_t   m_phone;
    int      m_isEmpty;
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
    struct Contact tmp = { 0 };

    printf("Bitte Vornamen eingeben: ");
    scanf_s("%s", tmp.m_firstName, MaxNameLength);

    printf("Bitte Nachnamen eingeben: ");
    scanf_s("%s", tmp.m_lastName, MaxNameLength);

    printf("Bitte Tel.Nummer eingeben: ");
    scanf_s("%zu", &tmp.m_phone);

    // enter temporary contact into global array
    int succeeded = 0;

    for (int i = 0; i < MaxContacts; i++) {

        if (g_Contacts[i].m_isEmpty == Empty) {

            g_Contacts[i] = tmp;  // Strukturzuweisung !
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
    char firstName[MaxNameLength] = { 0 };
    char lastName[MaxNameLength] = { 0 };;

    printf("Bitte Vornamen eingeben: ");
    scanf_s("%s", firstName, MaxNameLength);

    printf("Bitte Nachnamen eingeben: ");
    scanf_s("%s", lastName, MaxNameLength);

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

        if (g_Contacts[i].m_isEmpty == NotEmpty) {

            printContact(&g_Contacts[i]);
        }
    }
}

static void clearContacts()
{
    initContacts();
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

void exercise_contacts_static()
{
    printfMenu();
}

// =====================================================================================
// End-of-File
// =====================================================================================
