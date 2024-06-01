# Blockschachtelung

[Zurück](../../Markdown/Agenda.md)

---

## Allgemeines

*Beispiel*:

```c
01: static void testNestedScope_01()
02: {
03:     int n = 123;
04:     printf("n = %d\n", n);
05: 
06:     {
07:         int n = 456;
08:         printf("n = %d\n", n);
09: 
10:     }
11: 
12:     printf("n = %d\n", n);
13: }
14: 
15: 
16: // ===========================================================================
17: 
18: static int m = 123;
19: 
20: static void testNestedScope_02()
21: {
22:     printf("m = %d\n", m);
23: 
24:     {
25:         int m = 456;
26:         printf("m = %d\n", m);
27: 
28:     }
29: 
30:     printf("m = %d\n", m);
31: }
32: 
33: // ===========================================================================
34: 
35: static void testNestedScope_03()
36: {
37:     int n = 1;
38:     printf("n = %d\n", n);
39: 
40:     {
41:         int n = 2;
42:         printf("n = %d\n", n);
43: 
44:         {
45:             int n = 3;
46:             printf("n = %d\n", n);
47: 
48:             {
49:                 int n = 4;
50:                 printf("n = %d\n", n);
51:             }
52: 
53:             printf("n = %d\n", n);
54:         }
55: 
56:         printf("n = %d\n", n);
57:     }
58: 
59:     printf("n = %d\n", n);
60: }
61: 
62: static void testNestedScope_04()
63: {
64:     int i = 123;  // <== put into comments
65:     printf("i = %d\n", i);
66: 
67:     for (int i = 1; i < 5; ++i) {
68:         printf("%d\n", i);
69:     }
70: 
71:     printf("i = %d\n", i);
72: }
```

---

## Quellcode des Beispiels:

[*NestedScope.c*](NestedScope.c)<br />

---

[Zurück](../../Markdown/Agenda.md)

---
