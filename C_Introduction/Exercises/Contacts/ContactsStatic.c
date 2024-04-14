// =====================================================================================
// ContactsStatic.c
// =====================================================================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ==========================================
// Kontakte-Verwaltung

#define MaxContacts  10

struct Contact
{
    char             m_firstname[32];
    char             m_lastname[32];
    size_t           m_phone;
    int              m_isEmpty;
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

    printf("Geben Sie den Vornamen ein: ");

    // UGLY
    fgets(tmp.m_firstname, sizeof(tmp.m_firstname), stdin);  // flush .......
    fgets(tmp.m_firstname, sizeof(tmp.m_firstname), stdin);
    fflush(stdin);

    printf("Geben Sie den Nachnamen ein: ");
    fgets(tmp.m_lastname, sizeof(tmp.m_lastname), stdin);

    char buffer[64] = { 0 };
    printf("Geben Sie die Telefonnummer ein: ");
    fgets(buffer, sizeof(buffer), stdin);

    // Nachbearbeitung:
    // Newlines entfernen
    size_t indexNewline = strlen(tmp.m_firstname);
    tmp.m_firstname[indexNewline - 1] = '\0';
    indexNewline = strlen(tmp.m_lastname);
    tmp.m_lastname[indexNewline - 1] = '\0';

    // convert phone from string to size_t
    tmp.m_phone = atoi(buffer);

    // enter temporary contact into global array
    int succeeded = 0;

    for (int i = 0; i < MaxContacts; i++) {

        if (g_Contacts[i].m_isEmpty == 1) {

            g_Contacts[i] = tmp;  // Strukturzuweisung !
            succeeded = 1;
            break;
        }
    }

    if (succeeded == 0) {
        printf("Contacts Folder full !\n");
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

void exercise_contacts_static()
{
    printfMenu();
}

// =====================================================================================
// End-of-File
// =====================================================================================

