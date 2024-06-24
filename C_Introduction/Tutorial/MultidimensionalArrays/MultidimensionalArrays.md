# Mehrdimensionale Felder

[Zurück](../../Markdown/Agenda.md)

---

## Ablage von Arrays im Speicher

<img src="c_array_02.svg" width="700">

*Abbildung* 1. Ablage eines 2-dimensionalen Arrays im Speicher

---

## Allgemeines

### Initialisierung eines mehrdimensionalen Arrays

*Beispiel*:


```c
01: #define  M    2
02: #define  N    3
03: #define  O    4
04: 
05: void multidimensional_arrays_01()
06: {
07:     int numbers1[M][N] = { { 1, 2, 3 }, { 4, 5, 6} };
08: 
09:     int numbers2[][N]  = { { 1, 2, 3 }, { 4, 5, 6} };
10: 
11:     int numbers3[M][N] = { 1, 2, 3, 4, 5, 6 };
12: }
13: 
14: static void multidimensional_arrays_02()
15: {
16:     int numbers1[M][N][O] =
17:     {
18:         {
19:             { 1, 2, 3, 4 }, 
20:             { 5, 6, 7, 8 },
21:             { 9, 10, 11, 12 }
22:         },
23:         {
24:             { 13, 14, 15, 16 }, 
25:             { 17, 18, 19, 20 }, 
26:             { 21, 22, 23, 24 }
27:         } 
28:     };
29: 
30:     int numbers2[M][N][4] =
31:     {
32:         1, 2, 3, 4 , 5, 6, 7, 8, 9, 10, 11, 12 , 13, 14, 15, 16 , 17, 18, 19, 20, 21, 22, 23, 24
33:     };
34: }
35: 
```


---

## Übergabe eines mehrdimensionalen Arrays als Parameter

### Fall 1: Beide Dimensionen sind global verfügbar

*Beispiel*:

```c
01: #define  M        2
02: #define  N        3
03: 
04: void print(int arr[M][N])
05: {
06:     for (int i = 0; i < M; i++) 
07:     {
08:         for (int j = 0; j < N; j++) 
09:         {
10:             printf("%d ", arr[i][j]);
11:         }
12:         printf("\n");
13:     }
14: }
15: 
16: void multidimensional_arrays()
17: {
18:     int numbers[][N] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
19: 
20:     print(numbers);
21: }
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
17:     printEx(numbers, 4);
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
01: static void printExEx(int* arr, int m, int n)
02: {
03:     for (int i = 0; i < m; i++)
04:     {
05:         for (int j = 0; j < N; j++)
06:         {
07:             int value = *((arr + i * n) + j);
08: 
09:             printf("%2d ", value);
10:         }
11:         printf("\n");
12:     }
13: }
14: 
15: static void multidimensional_arrays_05()
16: {
17:     int numbers[][N] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { 10, 11, 12 } };
18: 
19:     int m = 4;
20:     int n = 3;
21: 
22:     printExEx(&numbers[0][0], m, n);
23: 
24:     // oder 
25: 
26:     printExEx( (int*) numbers, m, n);
27: }
```

*Ausgabe*:

```
 1  2  3
 4  5  6
 7  8  9
10 11 12
```


---

### Fall 3: Zweites Beispiel zum Verwenden des Konzepts eines Zeigers auf ein einzelnes Element



*Beispiel*:

```c
01: static void doSomething(int* arr)
02: {
03:     int value = *arr;
04:     printf("Value: %d\n", value);
05: 
06:     arr++;
07: 
08:     value = *arr;
09:     printf("Value: %d\n", value);
10: 
11:     arr++;
12: 
13:     value = *arr;
14:     printf("Value: %d\n", value);
15: }
```

*Ausgabe*:

```
Value: 1
Value: 2
Value: 3
```

---


### Fall 4: Verwenden des Konzepts eines Zeigers auf ein Array

*Beispiel*:

```c
01: static void printExExEx(int(*arr)[N])
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
13: static void multidimensional_arrays_06()
14: {
15:     int numbers[][N] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
16: 
17:     printExExEx(numbers);
18: }
```

*Ausgabe*:

```
1 2 3
4 5 6
7 8 9
```


---


### Fall 4: Zweites Beispiel zum Verwenden des Konzepts eines Zeigers auf ein Array

*Beispiel*:

```c
01: static void doSomethingEx(int(*arr)[N])
02: {
03:     int value = *arr[0];
04:     printf("Value: %d\n", value);
05: 
06:     arr++;
07: 
08:     value = *arr[0];
09:     printf("Value: %d\n", value);
10: 
11:     arr++;
12: 
13:     value = *arr[0];
14:     printf("Value: %d\n", value);
15: }
```

*Ausgabe*:

```
Value: 1
Value: 4
Value: 7
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
