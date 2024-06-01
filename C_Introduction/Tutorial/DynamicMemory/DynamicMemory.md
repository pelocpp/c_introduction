# Dynamische Speicherverwaltung

[Zurück](../../Markdown/Agenda.md)

---

## Allgemeines

*Beispiel*:


```c
001: static void dynamic_01()
002: {
003:     // eine int Variable auf der Halde / auf dem Heap anlegen
004: 
005:     int* ip = (int*) malloc(sizeof(int));
006: 
007:     *ip = 123;
008: 
009:     printf("Ein Wert auf dem Heap: %d\n", *ip);
010: 
011:     free(ip);
012: }
013: 
014: static void dynamic_02()
015: {
016:     // eine int Variable auf der Halde / auf dem Heap anlegen
017: 
018:     int* ip = (int*) malloc(sizeof(int));
019: 
020:     if (ip != NULL) {
021: 
022:         *ip = 123;
023: 
024:         printf("Ein Wert auf dem Heap: %d\n", *ip);
025: 
026:         free(ip);
027:     }
028:     else {
029: 
030:         printf("Out of memory !\n");
031:     }
032: }
033: 
034: static void dynamic_03()
035: {
036:     _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
037: 
038:     // eine int Variable auf der Halde / auf dem Heap anlegen
039: 
040:     int* ip = (int*) malloc(sizeof(int));
041: 
042:     *ip = 123;
043: 
044:     printf("Ein Wert auf dem Heap: %d\n", *ip);
045: 
046:     // _CrtDumpMemoryLeaks();
047: 
048:     free(ip);
049: }
050: 
051: // ================================================================
052: 
053: static void tueWasMitDenDaten(int* data)
054: {
055:     printf("tueWasMitDenDaten: %d\n", *data);
056: 
057:     // free(data); 
058: }
059: 
060: static void dynamic_04()
061: {
062:     int* ip = (int*)malloc(sizeof(int));
063: 
064:     *ip = 123;
065: 
066:     printf("Ein Wert auf dem Heap: %d\n", *ip);
067: 
068:     tueWasMitDenDaten(ip);
069: 
070:     printf("Ein Wert auf dem Heap: %d\n", *ip);
071: 
072:     free(ip);
073: }
074: 
075: // ================================================================
076: 
077: #define Length 10
078: 
079: static void dynamic_05()
080: {
081:     // ein Feld auf dem Heap anlegen
082: 
083:     int* ip = (int*) malloc(Length * sizeof(int));
084: 
085:     // mit dem Array arbeiten
086: 
087:     // a) Mit Zeigern arbeiten
088:     for (int i = 0; i < Length; i++) {
089:         *(ip + i) = 2 * i;
090:     }
091: 
092:     // b) In der Notation / Syntax eines Felds arbeiten
093:     for (int i = 0; i < Length; i++) {
094:         ip[i] = 2 * i;
095:     }
096: 
097:     // c) Feld ausgeben
098:     for (int i = 0; i < Length; i++) {
099:         // printf("Wert an %d: %d\n", i, ip[i]);
100:         printf("%02d: %d\n", i, *(ip + i));
101:     }
102: 
103:     free(ip);
104: }
105: 
106: // ================================================================
107: 
108: static void initData(int* data, int length)
109: {
110:     // a) Vorbelegen, mit Zeiger-Arithmetik
111:     for (int i = 0; i < length; ++i) {
112:         *(data + i) = 2 * i;
113:     }
114: 
115:     // b) Vorbelegen, mit Index-Operator
116:     for (int i = 0; i < length; ++i) {
117:         data[i] = 2 * i;
118:     }
119: }
120: 
121: static void printData(int* data, int length)
122: {
123:     // a) ausgeben, mit Zeiger-Arithmetik
124:     for (int i = 0; i < length; ++i) {
125:         printf("%02d: %3d\n", i, *(data + i));
126:     }
127: 
128:     // b) ausgeben, mit Index-Operator
129:     for (int i = 0; i < length; ++i) {
130:         printf("%02d: %3d\n", i, data[i]);
131:     }
132: }
133: 
134: // oder
135: 
136: static void initData1(int data[], int length)
137: {
138:     // a) Vorbelegen, mit Zeiger-Arithmetik
139:     for (int i = 0; i < length; ++i) {
140:         *(data + i) = 2 * i;
141:     }
142: 
143:     // b) Vorbelegen, mit Index-Operator
144:     for (int i = 0; i < length; ++i) {
145:         data[i] = 2 * i;
146:     }
147: }
148: 
149: static void printData1(int data[], int length)
150: {
151:     // a) ausgeben, mit Zeiger-Arithmetik
152:     for (int i = 0; i < length; ++i) {
153:         printf("%02d: %3d\n", i, *(data + i));
154:     }
155: 
156:     // b) ausgeben, mit Index-Operator
157:     for (int i = 0; i < length; ++i) {
158:         printf("%02d: %3d\n", i, data[i]);
159:     }
160: }
161: 
162: static void dynamic_06()
163: {
164:     // ein Feld auf dem Heap anlegen
165:     int* ip = (int*) malloc(Length * sizeof(int));
166: 
167:     // mit dem Feld arbeiten
168:     initData(ip, Length);
169:     printData(ip, Length);
170: 
171:     // mit dem Feld arbeiten
172:     initData1(ip, Length);
173:     printData1(ip, Length);
174: 
175:     // Feld freigeben
176:     free(ip);
177: }
```

---

## Quellcode des Beispiels:

[*DynamicMemory.c*](DynamicMemory.c)<br />

---

[Zurück](../../Markdown/Agenda.md)

---
