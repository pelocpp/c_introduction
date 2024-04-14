// =====================================================================================
// ContactsDynamic.c
// =====================================================================================

#define _CRT_SECURE_NO_WARNINGS

#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <stdlib.h>          // malloc, free
#include <crtdbg.h>
#include <string.h>

// ==========================================
// Kontakte-Verwaltung

#define MaxContacts  10

struct Contact
{
    char*     m_firstname;
    char*     m_lastname;
    size_t    m_phone;
    int       m_isEmpty;
};

// global
struct Contact g_Contacts[MaxContacts];

static void initContacts()
{
    for (int i = 0; i < MaxContacts; i++) {

        g_Contacts[i].m_isEmpty = 1;
    }
}

static enterContact()
{
    struct Contact tmp = { 0 };
    char buffer[64] = { 0 };

    // UGLY
    fgets(buffer, sizeof(buffer), stdin);  // flush .......

    printf("Geben Sie den Vornamen ein: ");
    fgets(buffer, sizeof(buffer), stdin);
    fflush(stdin);

    // Nachbearbeitung:
    // Newline entfernen
    size_t indexNewline = strlen(buffer);
    buffer[indexNewline - 1] = '\0';

    // Vorname ist vom Puffer in das Hilfsobjekt tmp zu kopieren
    tmp.m_firstname = malloc(indexNewline);
    strcpy_s(tmp.m_firstname, indexNewline, buffer);



    printf("Geben Sie den Nachnamen ein: ");
    fgets(buffer, sizeof(buffer), stdin);
    fflush(stdin);

    // Nachbearbeitung:
    // Newline entfernen
    indexNewline = strlen(buffer);
    buffer[indexNewline - 1] = '\0';

    // Vorname ist vom Puffer in das Hilfsobjekt tmp zu kopieren
    tmp.m_lastname = malloc(indexNewline);
    strcpy_s(tmp.m_lastname, indexNewline, buffer);


    printf("Geben Sie die Telefonnummer ein: ");
    fgets(buffer, sizeof(buffer), stdin);

    // convert phone from string to size_t
    tmp.m_phone = atoi(buffer);



    // enter temporary contact into global array
    int succeeded = 0;

    for (int i = 0; i < MaxContacts; i++) {

        if (g_Contacts[i].m_isEmpty == 1) {

            g_Contacts[i] = tmp;  // Strukturzuweisung ! Geht in diesem Fall auch mit Zeigern
            succeeded = 1;
            break;
        }
    }

    if (succeeded == 0) {
        printf("Contacts Folder full !\n");

        // ACHTUNG:  Hier müssten alle mallocs von oben mit free freigegeben werden !!!
    }
}

static void printContact(struct Contact* contact)
{
    printf("   Vorname:  %s\n", contact->m_firstname);
    printf("   Nachname: %s\n", contact->m_lastname);
    printf("   Phone:    %zu\n", contact->m_phone);
    printf("\n");
}

static void printContacts()
{
    for (int i = 0; i < MaxContacts; i++) {

        if (g_Contacts[i].m_isEmpty == 0) {

            printContact(&g_Contacts[i]);
            // printContact( g_Contacts + i );
        }
    }
}

static void clearContacts()
{
    // müssen zu jedem malloc free aufrufen !!!
    for (int i = 0; i < MaxContacts; i++) {

        if (g_Contacts[i].m_isEmpty == 0) {

            free(g_Contacts[i].m_firstname);
            free(g_Contacts[i].m_lastname);

            g_Contacts[i].m_firstname = NULL;
            g_Contacts[i].m_lastname = NULL;

            g_Contacts[i].m_isEmpty = 1;
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
        printf("(3) = Alle Kontakte loeschen\n");
        printf("(4) = Programm verlassen\n");

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
            clearContacts();
            break;
        case 4:
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
