# Arrays

[Zurück](../../Markdown/Agenda.md)

---

## Allgemeines

*Beispiel*:

```c
001: #define   Length   10
002: 
003: static void arrays_01()
004: {
005:     int numbers[Length];
006:     
007:     int n = numbers[0];  // using uninitialized memory :)
008:     numbers[0] = 123;
009: 
010:     for (int i = 0; i < Length; i++) {
011:         numbers[i] = 2 * i;
012:     }
013: 
014:     for (int i = 0; i < Length; i++) {
015:         printf("%2d: %d\n", i, numbers[i]);
016:     }
017: }
018: 
019: static void arrays_02()
020: {
021:     // Feld variabler Länge: Never - Arrays are Fixed-Size !
022: 
023:     int n;
024:     // .......
025:     n = 123;
026: 
027:     // int numbers [n];   // does NOT compile
028: }
029: 
030: static void arrays_03()
031: {
032:     // array initialization with initializer list
033:     int numbers1[Length] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
034: 
035:     for (int i = 0; i < Length; i++) {
036:         printf("%2d: %d\n", i, numbers1[i]);
037:     }
038: 
039:     // ========================================
040: 
041:     int numbers2[] = { 1, 2, 3, 4, 5 };   // compiler computes length of array
042: 
043:     int length = sizeof(numbers2) / sizeof(int);
044: 
045:     for (int i = 0; i < length; i++) {
046:         printf("%2d: %d\n", i, numbers2[i]);
047:     }
048: 
049:     // ========================================
050: 
051:     int numbers3[10] = { 1 };
052: 
053:     for (int i = 0; i < 10; i++) {
054:         printf("%2d: %d\n", i, numbers3[i]);
055:     }
056: }
057: 
058: static void initArray01(int* data, int length)
059: {
060:     // watch difference
061:     printf("sizeof numbers: %zu\n", sizeof(data));
062:     printf("sizeof int: %zu\n", sizeof(int));
063:     printf("Length: %zu\n", sizeof(data) / sizeof(*data));
064: 
065:     for (int i = 0; i < length; ++i) {
066: 
067:         data[i] = 2 * i;       // go for this syntax
068:         // oder
069:         *(data + i) = 2 * i;
070:     }
071: }
072: 
073: static void initArray02(int feld[], int length)
074: {
075:     // same as above
076: }
077: 
078: static void initArray03(int feld[10], int length)
079: {
080:     // same as above
081: }
082: 
083: static void arrays_04()
084: {
085:     int numbers[Length];
086: 
087:     printf("sizeof numbers: %zu\n", sizeof(numbers));
088:     printf("sizeof int: %zu\n", sizeof(int));
089:     printf("Length: %zu\n", sizeof(numbers) / sizeof(*numbers));
090: 
091:     initArray01(numbers, Length);
092: 
093:     initArray02(numbers, Length);
094: 
095:     for (int i = 0; i < Length; ++i) {
096:         printf("%02d: %d\n", i, numbers[i]);
097:     }
098: }
099: 
100: static void createRandomNumbers()
101: {
102:     time_t now;
103: 
104:     time(&now);
105: 
106:     // Seed : Samen ===> "Es wächst eine Pfanze"  
107: 
108:     srand((unsigned int) now);   // Startwert für den Algorithmus  
109: 
110:     // oder
111:     unsigned int start = 123;
112:     srand(start);                // Startwert für den Algorithmus  
113: 
114:     // s == 123  // s == seed : Samen ===> Wächst eine Pfanze  
115: 
116:     int zahl = rand();   // Zufallszahlen werden berechnet
117:     printf("Zufall: %d\n", zahl);
118: 
119:     zahl = rand();       // Zufallszahlen werden berechnet
120:     printf("Zufall: %d\n", zahl);
121: 
122:     zahl = rand();       // Zufallszahlen werden berechnet
123:     printf("Zufall: %d\n", zahl);
124: }
125: 
126: static void arrays_05()
127: {
128:     int numbers[Length];
129: 
130:     time_t now;
131:     time(&now);
132:     srand((unsigned int)now); 
133: 
134:     for (int i = 0; i < Length; i++) {
135:         numbers[i] = rand() % 10 + 1;   // 1 .. 10
136:     }
137: 
138:     for (int i = 0; i < Length; i++) {
139:         printf("%2d: %d\n", i, numbers[i]);
140:     }
141: }
142: 
143: static void arrays_06()
144: {
145:     // Wertzuweisung von Arrays
146: 
147:     // Bei Arrays sieht die Runtime einen Namen als ANFANGSADRESSE.
148: 
149:     int numbers1[Length] = { 0 };
150:     int numbers2[Length] = { 0 };
151: 
152:     // numbers1 = numbers2;                // Wertzuweisung: so nicht !!!!
153: 
154:     for (int i = 0; i < Length; i++) {     // Wertzuweisung
155:         numbers1[i] = numbers2[i];
156:     }
157: }
158: 
159: static void arrays_07_gimmicks()
160: {
161:     int numbers[Length] = { 0 };  // Hier wird speicher reserviert
162: 
163:     // Was ist 'numbers' per C Sprachdefinition: 
164:     // numbers ist die Anfangsadresse des reservierten Speichers.
165:     // Diese ist KONSTANT.
166: 
167:     // Wert 123 in das erste Element des Felds schreiben:
168:     *numbers = 123;
169: 
170:     // Pointer Arithmetik mit ++
171:     int* ip = numbers;
172:     ip++;
173:     *ip = 12;
174: 
175:     int offset = 3;
176: 
177:     // Pointer Arithmetik mit +:     // Adresse + Offset
178:     *(numbers + offset) = 6;         // So sieht es der Compiler
179:     // versus
180:     numbers[offset] = 6;             // Schreibweise für den Anwender
181: 
182:     // Zum Abschluss:
183:     numbers[-3] = 6;                 // Prinzipiell in C definiert :)
184: 
185:     // Oderzum guten Abschluss: Eine Auswirkung der Zeiger-Arithmetik
186:     *(offset + numbers) = 6;
187:     // oder
188:     3[numbers] = 6;
189: }
```

---

## Quellcode des Beispiels:

[*Arrays.c*](Arrays.c)<br />

---

[Zurück](../../Markdown/Agenda.md)

---
