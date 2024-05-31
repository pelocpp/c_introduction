# Datentypen, Variablen and Konstanten

[Zurück](../../Markdown/Agenda.md)

---

## Allgemeines

*Beispiel*:

```c
01: static void integral_datatypes()
02: {
03:     int n = 1;
04:     long l = -2;
05:     short s = 3;
06:     long long ll = -4;
07: 
08:     unsigned int ui = 1; 
09:     unsigned long ul = 2;
10:     unsigned short us = 3;
11:     unsigned long long ull = 4;
12: 
13:     size_t x = 0;
14: 
15:     size_t width_int = sizeof(int);
16:     size_t width_long = sizeof(long);
17:     size_t width_short = sizeof(short);
18:     size_t width_long_long = sizeof(long long);
19:     size_t width_size_t = sizeof(size_t);
20: 
21:     printf("sizeof (int):         %zu\n", width_int);
22:     printf("sizeof (long):        %zu\n", width_long);
23:     printf("sizeof (short):       %zu\n", width_short);
24:     printf("sizeof (long long):   %zu\n", width_long_long);
25:     printf("sizeof (size_t):      %zu\n", width_size_t);
26: }
27: 
28: static void floating_point_datatypes()
29: {
30:     double d = 123.456;
31:     float f = 654.321F;
32: 
33:     printf("sizeof (double):      %zu\n", sizeof(double));
34:     printf("sizeof (float):       %zu\n", sizeof(float));
35: }
36: 
37: static void char_string_datatypes()
38: {
39:     // chars
40:     char ch = 'A';
41:     char newLine = '\n';
42: 
43:     // string
44:     const char* s = "ABC";
45: 
46:     printf("ch:                   %c\n", ch);
47:     printf("s:                    %s\n", s);
48: }
49: 
50: static void pointer_datatypes()
51: {
52:     int n = 123;
53: 
54:     int* ip = &n;
55: 
56:     printf("n:                    %d\n", n);
57:     printf("&n:                   %p\n", ip);
58:     printf("sizeof (int*):        %zu\n", sizeof(int*));
59: }
60: 
61: static void constants()
62: {
63:     int n1 = 123;
64:     int n2 = 0x19AF;
65:     int n3 = 0b1101010101010;
66: 
67:     int ooops = 012;
68:     printf("ooops:                %d\n", ooops);
69: }
```
---

## Quellcode des Beispiels:

[*DatatypesVariablesConstants.c*](DatatypesVariablesConstants.c)<br />

---

[Zurück](../../Markdown/Agenda.md)

---
