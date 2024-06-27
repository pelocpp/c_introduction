// =====================================================================================
// ObjectFileViewer.c
// =====================================================================================

#pragma once

// defines

//#define FileName01 "TEST_Point.bin"
//#define FileName02 "TEST_JaggedArray.bin"

#define FileName01 "..\\C_Introduction\\Exercises\\ObjectFileViewer\\TEST_Point.bin"
#define FileName02 "..\\C_Introduction\\Exercises\\ObjectFileViewer\\TEST_JaggedArray.bin"
#define FileName03 "..\\C_Introduction\\Exercises\\ObjectFileViewer\\TEST_ObjectFileViewer.bin"


// functions
int open(const char* name, FILE** fp);
void close(FILE* ptr);
void read(FILE* ptr);

int openWithOffset(const char* name, FILE** fp, long int offset);

void readFileHeader(struct FileHeader* header, FILE* ptr);
void dumpFileHeader(struct FileHeader* header);

void readSectionHeader(struct SectionHeader* header, FILE* ptr);
void dumpSectionHeader(struct SectionHeader* header);

void readSectionRawData(FILE* ptr, long size);

void convertToDateTime(time_t dateTime, char* result, int length);

// types
struct FileHeader
{
    unsigned short     f_magic;           /* Magic number */
    unsigned short     f_numSections;     /* Number of Sections */
    long               f_timdat;          /* Time & date stamp */
    long               f_symptr;          /* File pointer to Symbol Table */
    long               f_nsyms;           /* Number of Symbols */
    unsigned short     f_opthdr;          /* sizeof(Optional Header) */
    unsigned short     f_flags;           /* Flags */
};

struct SectionHeader
{
    char               s_name[8];    /* Section Name */
    long               s_paddr;      /* Physical Address */
    long               s_vaddr;      /* Virtual Address */
    long               s_size;       /* Section Size in Bytes */
    long               s_scnptr;     /* File offset to the Section data */
    long               s_relptr;     /* File offset to the Relocation table for this Section */
    long               s_lnnoptr;    /* File offset to the Line Number table for this Section */
    unsigned short     s_nreloc;     /* Number of Relocation table entries */
    unsigned short     s_nlnno;      /* Number of Line Number table entries */
    long               s_flags;      /* Flags for this section */
};

// =====================================================================================
// End-of-File
// =====================================================================================
