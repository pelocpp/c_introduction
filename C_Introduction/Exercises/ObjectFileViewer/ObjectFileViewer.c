// =====================================================================================
// ObjectFileViewer.h
// =====================================================================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "ObjectFileViewer.h"

// A)
// https://wiki.osdev.org/COFF


// B)
// Sehr gute Beschreibung:
// https://www3.physnet.uni-hamburg.de/physnet/Tru64-Unix/HTML/APS31DTE/DOCU_013.HTM


// C) 
// https://www.tortall.net/projects/yasm/manual/html/objfmt-win32.html
// hier ist Section Name: .drectve beschrieben


// D)
// Benutze Tool dumpbin !!
// Ist in der Kommando Zeile "VS Studio 2022 Tools ..."
// C:\Development\Scratch_C\Scratch_C > dumpbin / ALL TEST_JaggedArray.obj
// Microsoft(R) COFF / PE Dumper Version 14.40.33811.0
// Copyright(C) Microsoft Corporation.All rights reserved.

// E)
// Magic Number: 0x8664

// COFF / File header
// Machine : 0x8664 IMAGE_FILE_MACHINE_AMD64
//
// Gefunden in 
// https ://github.com/fwupd/fwupd/issues/2910

// =====================================================================

static int open(const char* name, FILE** fp)
{
    FILE* ptr = fopen(name, "rb");  // r for read, b for binary

    if (ptr != NULL) {
        *fp = ptr;
        return 1;
    }
    else {
        printf("File %s not found\n", name);
        return 0;
    }
}

static int openWithOffset(const char* name, FILE** fp, long int offset)
{
    FILE* ptr = fopen(name, "rb");  // r for read, b for binary

    if (ptr != NULL) {
        *fp = ptr;

        fseek(ptr, offset, SEEK_SET);

        return 1;
    }
    else {
        printf("File %s not found\n", name);
        return 0;
    }
}


static void close(FILE* fp)
{
    fclose(fp);
}

static void read(FILE* ptr)
{
    unsigned char buffer[20];
    size_t count = fread(buffer, sizeof(buffer), 1, ptr);
}

static void readFileHeader(struct FileHeader* header, FILE* ptr)
{
    size_t count = fread(header, sizeof(struct FileHeader), 1, ptr);
}

static void dumpFileHeader(struct FileHeader* header)
{

    printf("Machine:                  %04x\n", header->f_magic);
    printf("Number of sections:       %d\n",   header->f_numSections);
    printf("Date / time stamp:        %04x\n", header->f_timdat);
    printf("Symbol Table offset:      %04x\n", header->f_symptr);
    printf("Number of Symbols:        %ld\n",  header->f_nsyms);
    printf("Size of optional header:  %04x\n", header->f_opthdr);
    printf("Flags:                    %04x\n", header->f_flags);
    printf("\n");

   // char buff[32];
   //// time_t now = time(NULL);
   // strftime(buff, 32, "%Y-%m-%d %H:%M:%S", localtime(&header->f_timdat));
   // printf("Date / Time:              %sx\n", buff);

    //asctime_s(str, sizeof str, localtime_s(&t, &buf));
    //printf("local:     %s", str);

    printf("\n");
}


static void readSectionHeader(struct SectionHeader* header, FILE* ptr)
{
    size_t count = fread(header, sizeof(struct SectionHeader), 1, ptr);
}

static void dumpSectionHeader(struct SectionHeader* header)
{
    printf("Section Name:                                          %s\n", header->s_name);
    printf("Physical Address:                                      %d\n", header->s_paddr);
    printf("Virtual Address:                                       %d\n", header->s_vaddr);
    printf("Section Size in Bytes:                                 %d\n", header->s_size);
    printf("File offset to the Section data:                       %d\n", header->s_scnptr);
    printf("File offset to the Relocation table for this Section:  %d\n", header->s_relptr);
    printf("File offset to the Line Number table for this Section: %d\n", header->s_lnnoptr);
    printf("Number of Relocation table entries:                    %d\n", header->s_nreloc);
    printf("Number of Line Number table entries:                   %d\n", header->s_nlnno);
    printf("Flags for this section:                                %04lX\n", header->s_flags);
    printf("\n");
}

// =============================================================

void readSectionRawData(FILE* ptr, long size)
{
    char* buffer = malloc(size + 1);

    if (buffer != NULL) {

        size_t numReadBytes = fread(buffer, 1, size, ptr);

        buffer[size] = '\0';

        printf("Raw Data:\n");
        printf("%s", buffer);

        free(buffer);
    }


}

// =============================================================

void exercise_object_file_viewer()
{
    char* fileName = FileName02;
    FILE* ptr;

    if (!(open(fileName, &ptr))) {
        printf("Error\n");
    }
    else {
        printf("Succeeded\n");

        struct FileHeader fileHeader;

        readFileHeader(&fileHeader, ptr);
        dumpFileHeader(&fileHeader);

        unsigned short numSections = fileHeader.f_numSections;

        struct SectionHeader firstSectionHeader;
        readSectionHeader(&firstSectionHeader, ptr);
        dumpSectionHeader(&firstSectionHeader);

        // ===============================================

        struct SectionHeader sectionHeader;
        for (int i = 1; i < numSections; ++i) {

            readSectionHeader(&sectionHeader, ptr);
            dumpSectionHeader(&sectionHeader);
        }

        close(ptr);

        // ===============================================

        openWithOffset(fileName, &ptr, firstSectionHeader.s_scnptr);

        readSectionRawData(ptr, firstSectionHeader.s_size);

        close(ptr);
    }
}

//void main_obj_viewer()
//{
//    char* fileName = FileName01;
//    FILE* ptr;
//
//    if (!(open(fileName , &ptr))) {
//        printf("Error\n");
//    }
//    else {
//        printf("Succeeded\n");
//
//        struct FileHeader fileHeader;
//        struct SectionHeader sectionHeader;
//
//        readFileHeader(&fileHeader, ptr);
//        dumpFileHeader(&fileHeader);
//
//        unsigned short numSections = fileHeader.f_numSections;
//
//        for (int i = 0; i < numSections; ++i) {
//
//            readSectionHeader(&sectionHeader, ptr);
//            dumpSectionHeader(&sectionHeader);
//        }
//
//        close(ptr);
//    }
//}


// =====================================================================================
// End-of-File
// =====================================================================================
