# Die C-Standardbibliothek *CRT* (*C-Runtime-Library*)

[Zurück](../../Markdown/Agenda.md)

---

## Allgemeines


*Beispiel*:

```c
01: void crt_01()
02: {
03:     // einzelne Zeichen
04: 
05:     char ch;
06: 
07:     ch = 'A';
08:     printf("%d\n", isalpha(ch));
09: 
10:     ch = '1';
11:     printf("%d\n", isalpha(ch));
12: 
13:     printf("%d\n", isdigit(ch));
14: 
15:     ch = 'A';
16:     ch = tolower(ch);
17:     printf("%c\n", ch);
18: 
19:     ch = toupper(ch);
20:     printf("%c\n", ch);
21: }
22: 
23: void crt_02()
24: {
25:     char* s = "123456789";
26: 
27:     printf("%zu\n", strlen(s));
28:     printf("%zu\n", sizeof("123456789"));
29: 
30:     // string concatenation
31:     char dest[50] = "ABCDEF";
32:     // char* dest = "ABCDEF";  // <====== VORSICHT
33:     strcat_s(dest, 50, "123456789");
34:     printf("%s\n", dest);
35: }
36: 
37: void crt_03()
38: {
39:     // ascii to integer
40:     int n = atoi("1234");
41:     printf("%d\n", n);
42: 
43:     n = atoi("1234XXX");
44:     printf("%d\n", n);
45: 
46:     n = atoi("XXX1234");
47:     printf("%d\n", n);
48: 
49:     n = atoi("0");
50:     printf("%d\n", n);
51: 
52:     // don't forget:  isdigit
53: }
54: 
55: #define FILE_NAME_1 "..\\C_Introduction\\Tutorial\\CRT\\CRT.c"
56: 
57: #define FILE_NAME_2 "C:\\Development\\Seminar_C_All_In_One_April_2024\\ErsteSchritte\\ErsteSchritte\\Datei_11.c"
58: 
59: #define FILE_NAME_3 R"(C:\Development\Seminar_C_All_In_One_April_2024\ErsteSchritte\ErsteSchritte\Datei_11.c)"
60: 
61: void crt_04()
62: {
63:     FILE* fp;
64: 
65:     fp = fopen(FILE_NAME_1, "r");
66: 
67:     if (fp == NULL) {
68:         printf("File %s not found\n", FILE_NAME_1);
69:     }
70:     else {
71: 
72:         // Lese alle Zeilen aus der Datei ein:
73: 
74:         while (1) {
75: 
76:             char line[256];
77:             char* result = fgets(line, 256, fp);
78: 
79:             if (result == NULL) {
80:                 break;
81:             }
82: 
83:             // remove line-break '\n'
84:             size_t indexLineBreak = strlen(line);
85:             line[indexLineBreak - 1] = '\0';
86: 
87:             printf("> %s\n", line);
88:         }
89: 
90:         fclose(fp);
91:     }
92: }
```


---

## Quellcode des Beispiels:

[*CRT.c*](CRT.c)<br />

---

[Zurück](../../Markdown/Agenda.md)

---
