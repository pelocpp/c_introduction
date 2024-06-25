# Unions, Bitfelder und Enums

[Zurück](../../Markdown/Agenda.md)

---

## Allgemeines

*Beispiel*:


```c
01: struct Status1
02: {
03:     unsigned int widthValidated;
04:     unsigned int heightValidated;
05:     unsigned int positionValidated;
06: };
07: 
08: struct Status2
09: {
10:     unsigned int widthValidated    : 1;
11:     unsigned int heightValidated   : 4;
12:     unsigned int positionValidated : 1;
13: };
14: 
15: static void bitfields()
16: {
17:     printf("Memory size occupied by status1 : %zu\n", sizeof(struct Status1));
18:     printf("Memory size occupied by status2 : %zu\n", sizeof(struct Status2));
19: 
20:     struct Status1 s1 = { 0, 0, 0 };
21:     s1.positionValidated = 1;
22: 
23:     struct Status2 s2 = { 0, 0, 0 };;
24:     s2.positionValidated = 0;
25:     s2.heightValidated = 15;
26: }
```


*Ausgabe*:


```
Memory size occupied by status1 : 12
Memory size occupied by status2 : 4
```



*Beispiel*:


```c
01: union UnionExample
02: {
03:     int   member1;
04:     char  member2;
05:     float member3;
06: };
07: 
08: union UnionExampleEx
09: {
10:     int   value;
11:     unsigned char value_bytes[4];
12: };
13: 
14: static void unions()
15: {
16:     // defining a union variable
17:     union UnionExampleEx var = { 0 };
18: 
19:     var.value = 0x00AA0000;
20: 
21:     unsigned char byte1 = var.value_bytes[0];
22:     unsigned char byte2 = var.value_bytes[1];
23:     unsigned char byte3 = var.value_bytes[2];
24:     unsigned char byte4 = var.value_bytes[3];
25: }
```



*Beispiel*:


```c
01: enum Level {
02:     LOW = 10,
03:     MEDIUM,
04:     HIGH
05: };
06: 
07: static void enums()
08: {
09:     enum Level myVar = MEDIUM;
10: 
11:     switch (myVar)
12:     {
13:     case LOW:
14:         printf("Low Level\n");
15:         break;
16:     case MEDIUM:
17:         printf("Medium Level\n");
18:         break;
19:     case HIGH:
20:         printf("High Level\n");
21:         break;
22:     }
23: 
24:     printf("myVar: %d\n", myVar);
25: }
```


*Ausgabe*:


```
Medium Level
myVar: 11
```



---

## Quellcode des Beispiels:

[*UnionsBitFieldsEnums.c*](UnionsBitFieldsEnums.c)<br />

---

[Zurück](../../Markdown/Agenda.md)

---
