# Mehrdimensionale Felder

[Zurück](../../Markdown/Agenda.md)

---

## Allgemeines


Wir betrachten die Themen:

  * Ablage von Arrays im Speicher
  * Initialisierung eines mehrdimensionalen Arrays
  * Übergabe eines mehrdimensionalen Arrays als Parameter
  * Konzept &bdquo;Zeiger auf ein Array&rdquo;

---

## Ablage von Arrays im Speicher

<img src="c_array_02.svg" width="700">

*Abbildung* 1. Ablage eines 2-dimensionalen Arrays im Speicher

---

## Initialisierung eines mehrdimensionalen Arrays

*Beispiel*: 2-dimensionale Arrays


```c
01: #define  M    2
02: #define  N    3
03: 
04: void multidimensional_arrays()
05: {
06:     int numbers1[M][N] = 
07:     {
08:         { 1, 2, 3 },
09:         { 4, 5, 6 } 
10:     };
11: 
12:     int numbers2[][N]  = 
13:     { 
14:         { 1, 2, 3 }, 
15:         { 4, 5, 6 } 
16:     };
17: 
18:     int numbers3[M][N] = { 1, 2, 3, 4, 5, 6 };
19: }
```

*Beispiel*: 2-dimensionale Arrays &ndash; mit der *designator list syntax*


```c
01: int grid[3][4] =
02: { 
03:     [0][0] = 1,[0][1] =  2, [0][2] =  3, [0][3] =  4,
04:     [1][0] = 5,[1][1] =  6, [1][2] =  7, [1][3] =  8,
05:     [2][0] = 9,[2][1] = 10, [2][2] = 11, [2][3] = 12 
06: };
```

*Beispiel*: 3-dimensionale Arrays


```c
01: #define  M    2
02: #define  N    3
03: #define  O    4
04: 
05: void multidimensional_arrays()
06: {
07:     int numbers1[M][N][O] =
08:     {
09:         {
10:             { 1, 2, 3, 4    }, 
11:             { 5, 6, 7, 8    },
12:             { 9, 10, 11, 12 }
13:         },
14:         {
15:             { 13, 14, 15, 16 }, 
16:             { 17, 18, 19, 20 }, 
17:             { 21, 22, 23, 24 }
18:         } 
19:     };
20: 
21:     int numbers2[M][N][O] =
22:     {
23:         1, 2, 3, 4 , 5, 6, 7, 8, 9, 10, 11, 12 , 13, 14, 15, 16 , 17, 18, 19, 20, 21, 22, 23, 24
24:     };
25: }
```


*Beispiel*: Traversieren eines 2-dimensionalen Arrays &ndash; *Brace*-Notation

```c
01: for (int i = 0; i < M; ++i)
02: {
03:     for (int j = 0; j < N; ++j)
04:     {
05:         printf("[%d][%d]: %2d   ", i, j, numbers1[i][j]);
06:     }
07: }
```

*Beispiel*: Traversieren eines 2-dimensionalen Arrays &ndash; Zeiger-Arithmetik

```c
01: for (int i = 0; i < M; ++i)
02: {
03:     for (int j = 0; j < N; ++j)
04:     {
05:         printf("[%d][%d]: %2d   ", i, j, *(*(numbers1 + i) + j));
06:     }
07: }
```

*Beispiel*: Traversieren eines 3-dimensionalen Arrays &ndash; *Brace*-Notation

```c
01: for (int i = 0; i < M; ++i)
02: {
03:     for (int j = 0; j < N; ++j)
04:     {
05:         for (int k = 0; k < O; ++k)
06:         {
07:             printf("[%d][%d][%d]: %2d   ", i, j, k, numbers1[i][j][k]);
08:         }
09:     }
10: }
```

*Beispiel*: Traversieren eines 3-dimensionalen Arrays &ndash; Zeiger-Arithmetik

```c
01: for (int i = 0; i < M; ++i)
02: {
03:     for (int j = 0; j < N; ++j)
04:     {
05:         for (int k = 0; k < O; ++k)
06:         {
07:             printf("[%d][%d][%d]: %2d   ", i, j, k, *(*(*(numbers1 + i) + j) + k));
08:         }
09:     }
10: }
```


---

## Übergabe eines mehrdimensionalen Arrays als Parameter

### Fall 1: Beide Dimensionen sind global verfügbar

*Beispiel*:

```c
01: #define  N     3
02: 
03: void print(int arr[N][N])
04: {
05:     for (int i = 0; i < N; i++)
06:     {
07:         for (int j = 0; j < N; j++) 
08:         {
09:             printf("%d ", arr[i][j]);
10:         }
11:         printf("\n");
12:     }
13: }
14: 
15: void multidimensional_arrays()
16: {
17:     int numbers[][N] =
18:     { 
19:         { 1, 2, 3 },
20:         { 4, 5, 6 }, 
21:         { 7, 8, 9 } 
22:     };
23: 
24:     print(numbers);
25: }
```

*Ausgabe*:


```
1 2 3
4 5 6
```

---

### Fall 2: Nur die zweite (und alle weiteren) Dimensionen sind global verfügbar

*Beispiel*:

```c
01: void print(int arr[][N], int m)
02: {
03:     for (int i = 0; i < m; i++)
04:     {
05:         for (int j = 0; j < N; j++)
06:         {
07:             printf("%2d ", arr[i][j]);
08:         }
09:         printf("\n");
10:     }
11: }
12: 
13: void multidimensional_arrays()
14: {
15:     int numbers[][N] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { 10, 11, 12 } };
16: 
17:     print(numbers, 4);
18: }
```

*Ausgabe*:


```
 1  2  3
 4  5  6
 7  8  9
10 11 12
```

---

### Fall 3: Verwenden des Konzepts eines Zeigers auf ein einzelnes Element

Wir müssen das mehrdimensionale Array beim Übergeben an die Funktion in einen anderen Typ umwandeln.


*Beispiel*:

```c
01: void print(int* arr, int m, int n)
02: {
03:     for (int i = 0; i < m; i++)
04:     {
05:         for (int j = 0; j < n; j++)
06:         {
07:             int value = *((arr + i * n) + j);
08: 
09:             printf("%2d ", value);
10:         }
11:         printf("\n");
12:     }
13: }
14: 
15: #define  N   3
16: 
17: void multidimensional_arrays()
18: {
19:     int numbers[][N] = 
20:     {
21:         { 1, 2, 3 },
22:         { 4, 5, 6 },
23:         { 7, 8, 9 }, 
24:         { 10, 11, 12 } 
25:     };
26: 
27:     int m = 4;
28: 
29:     print(&numbers[0][0], m, N);
30: 
31:     // oder 
32: 
33:     print((int*) numbers, m, N);
34: }
```

*Ausgabe*:

```
 1  2  3
 4  5  6
 7  8  9
10 11 12
```

---


### Fall 4: Verwenden des Konzepts eines Zeigers auf ein Array

*Beispiel*:

```c
01: void print(int(*arr)[N])
02: {
03:     for (int i = 0; i < N; i++)
04:     {
05:         for (int j = 0; j < N; j++)
06:         {
07:             printf("%d ", arr[i][j]);
08:         }
09:         printf("\n");
10:     }
11: }
12: 
13: void multidimensional_arrays()
14: {
15:     int numbers[][N] = 
16:     {
17:         { 1, 2, 3 },
18:         { 4, 5, 6 },
19:         { 7, 8, 9 } 
20:     };
21: 
22:     print(numbers);
23: }
```

*Ausgabe*:

```
1 2 3
4 5 6
7 8 9
```


---


### Fall 4: Zweites Beispiel zum Verwenden des Konzepts eines Zeigers auf ein Array

Hier wird demonstriert, wie das Konzept &bdquo;Konzepts eines Zeigers auf ein Array&rdquo;
beim Traversieren des mehrdimensionalen Arrays auch ohne den Index-Operator
erfolgen kann:

*Beispiel*:

```c
01: void print(int(*arr)[N], int length)
02: {
03:     for (int(*ap)[N] = arr; ap < &arr[length]; ap++)
04:     {
05:         for (int* ip = *ap; ip < &(*ap)[N]; ip++)
06:         {
07:             printf("%d ", *ip);
08:         }
09:         printf("\n");
10:     }
11: }
12: 
13: void multidimensional_arrays()
14: {
15:     int numbers[][N] =
16:     {
17:         {  1,  2,  3 },
18:         {  4,  5,  6 },
19:         {  7,  8,  9 },
20:         { 10, 11, 12 },
21:     };
22: 
23:     print(numbers, 4);
24: }
```

*Ausgabe*:

```
1 2 3
4 5 6
7 8 9
10 11 12
```

---

## Quellcode des Beispiels:

[*MultidimensionalArrays.c*](MultidimensionalArrays.c)<br />

---

## Literaturhinweise


Die Anregungen zu den Beispielen aus diesem Abschnitt stammen aus dem Artikel

[C Multidimensional Arrays](https://www.programiz.com/c-programming/c-multi-dimensional-arrays) (abgerufen am 20.06.2024)

und einem zweiten Aufsatz:

[How To Pass A 2D Array As A Parameter In C?](https://www.skillvertex.com/blog/how-to-pass-a-2d-array-as-a-parameter-in-c/) (abgerufen am 20.06.2024)

---

[Zurück](../../Markdown/Agenda.md)

---
