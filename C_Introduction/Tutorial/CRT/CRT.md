# Die C-Standardbibliothek *CRT* (*C-Runtime-Library*)

[Zurück](../../Markdown/Agenda.md)

---

## Allgemeines


*Beispiel*:

```c
001: static void crt_01()
002: {
003:     char text[] = "This is a simple string";
004:     size_t length;
005: 
006:     length = strlen(text);
007:     printf("String \"%s\" has %zu characters.\n", text, length);
008: }
009: 
010: static void crt_02()
011: {
012:     char text[20] = { '\0' };
013: 
014:     strcpy_s(text, sizeof (text), "Hallo!");
015:     printf("%s\n", text);
016: 
017:     strcpy_s(text, sizeof(text), "Yes - You!");
018:     printf("%s\n", text);
019: }
020: 
021: static void crt_03()
022: {
023:     char* s = "123456789";
024: 
025:     printf("%zu\n", strlen(s));
026:     printf("%zu\n", sizeof("123456789"));
027: 
028:     // string concatenation
029:     char dest[50] = "ABCDEF";
030:     // char* dest = "ABCDEF";  // <====== VORSICHT
031:     strcat_s(dest, 50, "123456789");
032:     printf("%s\n", dest);
033: }
034: 
035: static void crt_04()
036: {
037:     const char string1[] = "Hello";
038:     const char string2[] = "World";
039:     const char string3[] = "Hello";
040: 
041:     if (strcmp(string1, string2) == 0)
042:     {
043:         printf("The strings %s und %s are identical.\n", string1, string2);
044:     }
045:     else
046:     {
047:         printf("The strings %s und %s are different.\n", string1, string2);
048:     }
049: 
050:     if (strcmp(string1, string3) == 0)
051:     {
052:         printf("The strings %s und %s are identical.\n", string1, string3);
053:     }
054:     else
055:     {
056:         printf("The strings %s und %s are different.\n", string1, string3);
057:     }
058: }
059: 
060: // ===========================================================================
061: // <ctype.h> examples
062: 
063: static void crt_05()
064: {
065:     // single character functions
066:     char ch;
067: 
068:     ch = 'A';
069:     printf("%d\n", isalpha(ch));
070: 
071:     ch = '1';
072:     printf("%d\n", isalpha(ch));
073: 
074:     printf("%d\n", isdigit(ch));
075: 
076:     ch = 'A';
077:     ch = tolower(ch);
078:     printf("%c\n", ch);
079: 
080:     ch = toupper(ch);
081:     printf("%c\n", ch);
082: }
083: 
084: static void crt_06()
085: {
086:     // ascii to integer
087:     int n = atoi("1234");
088:     printf("%d\n", n);
089: 
090:     n = atoi("1234XXX");
091:     printf("%d\n", n);
092: 
093:     n = atoi("XXX1234");
094:     printf("%d\n", n);
095: 
096:     n = atoi("0");
097:     printf("%d\n", n);
098: }
099: 
100: // ===========================================================================
101: // <stdlib.h> examples
102: 
103: #define FILE_NAME_1 "..\\C_Introduction\\Tutorial\\CRT\\CRT.c"
104: 
105: #define FILE_NAME_2 "C:\\Development\\Seminar_C_All_In_One_April_2024\\ErsteSchritte\\ErsteSchritte\\Datei_11.c"
106: 
107: #define FILE_NAME_3 R"(C:\Development\Seminar_C_All_In_One_April_2024\ErsteSchritte\ErsteSchritte\Datei_11.c)"
108: 
109: static void crt_07()
110: {
111:     FILE* fp;
112: 
113:     fp = fopen(FILE_NAME_1, "r");
114: 
115:     if (fp == NULL) {
116:         printf("File %s not found\n", FILE_NAME_1);
117:     }
118:     else {
119: 
120:         // Lese alle Zeilen aus der Datei ein:
121: 
122:         while (1) {
123: 
124:             char line[256];
125:             char* result = fgets(line, 256, fp);
126: 
127:             if (result == NULL) {
128:                 break;
129:             }
130: 
131:             // remove line-break '\n'
132:             size_t indexLineBreak = strlen(line);
133:             line[indexLineBreak - 1] = '\0';
134: 
135:             printf("> %s\n", line);
136:         }
137: 
138:         fclose(fp);
139:     }
140: }
```


---

## Quellcode des Beispiels:

[*CRT.c*](CRT.c)<br />

---

[Zurück](../../Markdown/Agenda.md)

---
