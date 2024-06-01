# Zeiger (Pointer)

[Zurück](../../Markdown/Agenda.md)

---

## Allgemeines


*Beispiel*:

```c
001: static void test_pointer_01()
002: {
003:     int n = 0;
004: 
005:     n = 123;
006: 
007:     int* pi = NULL;
008: 
009:     pi = &n;   // Adress-Operator '&'
010: 
011:     // Nomenklatur: Man sagt: eine Adresse einer Variable bilden / eruieren
012:     // Nomenklatur: Auch:     eine Variable referenzieren (Adresse)
013: 
014:     // Wert der Variablen n ändern
015:     n = 456;
016: 
017:     // Wert der Variablen n ändern - OHNE den Bezeichern 'n' zu verwenden
018:     // Indirekter Zugriff
019: 
020:     *pi = 789;   // Indirekten Zugriff (via Adresse): '*'
021: 
022:     // Nomenklatur: Einen Wert einer Variable indirekt zuweisen
023:     // Nomenklatur: Auch: Eine Variable mit einer Adresse dereferenzieren
024: }
025: 
026: static void malZwei(int n)
027: {
028:     n = 2 * n;
029: }
030: 
031: static void test_pointer_02()
032: {
033:     int x = 123;
034: 
035:     printf("x = %d\n", x);   // 123
036: 
037:     malZwei(x);
038: 
039:     printf("x = %d\n", x);   // 123 oder 246
040: }
041: 
042: static void malZweiEx(int* pn)   // pn = lokale Variable von malZweiEx
043: {
044:     int tmp;                 // tmp = lokale Variable von malZweiEx
045: 
046:     tmp = *pn * 2;
047: 
048:     *pn = tmp;
049: 
050:     // oder
051: 
052:     // *pn = *pn * 2;        // kompakt in einer Zeile :)
053: }
054: 
055: static void test_pointer_03()
056: {
057:     int x = 123;
058: 
059:     printf("x = %d\n", x);                // 123
060: 
061:     int* addressOfx = &x;
062: 
063:     printf("Adresse von x = %p\n", &x);
064: 
065:     malZweiEx(&x);
066:     // oder
067:     // malZweiEx(addressOfx);
068: 
069:     printf("x = %d\n", x);                // 123
070: }
071: 
072: static void test_pointer_04()
073: {
074:     int n = 0;
075:     int* pi = NULL;
076: 
077:     pi = &n;
078:     *pi = 123;
079: 
080:     printf("n = %d\n", n);                // 123
081: 
082:     // =======================================
083:     // Zeigerarithmetik
084: 
085:     // pi++;
086:     // oder
087:     pi = pi + 1;  // Auch hier werden 4 Bytes auf die Adresse dazu gezählt
088:                   // 1 steht für sizeof (int)
089: 
090:     printf("n = %d\n", *pi);              // ???
091: 
092:     // geht das: Ja, das geht -- ist aber FALSCH / UNZULÄSSIG
093:     *pi = 789;
094:     printf("n = %d\n", *pi);              // ???
095: 
096:     // wieder im zulässigen Bereich
097:     pi--;
098:     printf("n = %d\n", *pi);              // 123
099: }
100: 
101: 
102: static void test_pointer_05_gimmicks()
103: {
104:     unsigned int n = 0xAABBCCDD;
105: 
106:     unsigned int* ip = &n;
107: 
108:     printf("Wert: %x\n", n);
109: 
110:     unsigned char* cp;
111: 
112:     cp = (char*)ip;
113: 
114:     unsigned char ch = *cp;
115: 
116:     printf("Char Wert: %x\n", ch);
117: 
118:     ++cp;
119: 
120:     printf("Char Wert: %x\n", *cp);
121: 
122:     *cp = 0;
123: 
124:     printf("Wert: %x\n", n);
125: }
```

---

## Quellcode des Beispiels:

[*Pointers.c*](Pointers.c)<br />

---

[Zurück](../../Markdown/Agenda.md)

---
