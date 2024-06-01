# Anweisungen und Konstrollstrukturen

[Zurück](../../Markdown/Agenda.md)

---

## Allgemeines

*Beispiel*:

```c
001: static void test_if_01()
002: {
003:     int n = 1;
004:     int m = 2;
005: 
006:     if (m > n) {
007: 
008:         printf("erfuellt\n");
009:     }
010: }
011: 
012: static void test_if_02()
013: {
014:     int n = 3;
015:     int m = 4;
016: 
017:     if (m > n) {
018: 
019:         printf("erfuellt\n");
020:     }
021:     else {
022: 
023:         printf("nicht erfuellt\n");
024:     }
025: }
026: 
027: static void test_if_03()
028: {
029:     int n = 123;
030: 
031:     // Test auf Gleichheit: ==
032:     if (n == 123) {
033: 
034:         printf("erfuellt\n");
035:     }
036: 
037:     // Test auf Ungleichheit: !=
038:     if (n != 123) {
039: 
040:         printf("erfuellt\n");
041:     }
042: }
043: 
044: static void test_if_04()
045: {
046:     int n = 5;
047:     int m = 6;
048: 
049:     if (n >= 3 && m <= 4) {
050: 
051:         printf("erfuellt\n");
052:     }
053: 
054:     if (n >= 3 || m <= 4) {
055: 
056:         printf("erfuellt\n");
057:     }
058: 
059:     if (! (n >= 3)) {
060: 
061:         printf("erfuellt\n");
062:     }
063: }
064: 
065: static void test_if_05()
066: {
067:     int n = 5;
068:     int m = 6;
069: 
070:     if (n >= 3 && m <= 4) {
071: 
072:         printf("erfuellt\n");
073:     }
074: 
075:     if (n >= 3 || m <= 4) {
076: 
077:         printf("erfuellt\n");
078:     }
079: 
080:     if (!(n >= 3)) {
081: 
082:         printf("erfuellt\n");
083:     }
084: }
085: 
086: static void test_if_06()
087: {
088:     int n = 123;
089: 
090:     // Vorsicht: 1.)
091:     // Synonym: n != 0
092:     if (n) {
093: 
094:         printf("erfuellt\n");
095:     }
096: 
097:     // Vorsicht: 2.)
098:     // Synonym:
099:     if (n = 456) {
100: 
101:         printf("erfuellt\n");
102:     }
103: 
104:     // ist gleich
105:     if ((n = 456) != 0) {
106: 
107:         printf("erfuellt\n");
108:     }
109: }
110: 
111: static void test_if_07()
112: {
113:     int n;
114: 
115:     // Frage:
116: 
117:     n = 2;
118: 
119:     // Version 1:
120: 
121:     if (n == 1) {
122:         printf("n = 1\n");
123:     }
124: 
125:     if (n == 2) {
126:         printf("n = 2\n");
127:     }
128: 
129:     if (n == 3) {
130:         printf("n = 3\n");
131:     }
132: 
133:     // vs Version 2:
134: 
135:     if (n == 1) {
136:         printf("n = 1\n");
137:     }
138:     else if (n == 2) {
139:         printf("n = 2\n");
140:     }
141:     else if (n == 3) {
142:         printf("n = 3\n");
143:     }
144: }
145: 
146: // ===========================================================================
147: 
148: static void test_for_01()
149: {
150:     // for-Anweisung
151:     for (int i = 0; i < 5; i = i + 1) {
152: 
153:         printf("Bin hier: %d\n", i);
154:     }
155: }
156: 
157: static void test_for_02()
158: {
159:     // for-Anweisung
160:     for (int i = 0; i < 5; i = i + 1) {
161: 
162:         if (i == 3) {  // Ausnahme , unerwarteter Wert von einer Eingabe
163:             break;
164:         }
165: 
166:         printf("Bin hier: %d\n", i);
167:     }
168: }
169: 
170: static void test_for_03()
171: {
172:     // for-Anweisung
173:     for (int i = 0; i < 5; i = i + 1) {
174: 
175:         if (i == 3) {  // Ausnahme , unerwarteter Wert von einer Eingabe
176:             continue;
177:         }
178: 
179:         printf("Bin hier: %d\n", i);
180:     }
181: }
182: 
183: static void test_for_04()
184: {
185:     // for-Anweisung // Gimmicks
186: 
187:     int i = 0;
188: 
189:     // Endlos-Schleife
190:     for (;;) {
191: 
192:         // i = i + 1;
193:         ++i;
194:         //oder
195:         i++;
196: 
197:         printf("Bin hier: %d\n", i);
198: 
199:         if (i >= 10) {
200:             break;
201:         }
202:     }
203: }
204: 
205: // ===========================================================================
206: 
207: static void test_while_01()
208: {
209:     // for-Anweisung
210:     for (int i = 0; i < 5; i = i + 1) {
211: 
212:         printf("for -   Bin hier: %d\n", i);
213:     }
214: 
215:     // Dasselbe mit while:
216: 
217:     int k = 0;
218: 
219:     while (k < 5) {
220: 
221:         printf("while - Bin hier: %d\n", k);
222: 
223:         k++;
224:     }
225: }
```


---

## Quellcode des Beispiels:

[*ControlStructures.c*](ControlStructures.c)<br />

---

[Zurück](../../Markdown/Agenda.md)

---
