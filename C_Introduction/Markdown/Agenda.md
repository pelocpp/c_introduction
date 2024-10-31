# Agenda

[Zurück](../../Readme.md)

<img src="Embedded_Cpp.jpg" width="500">

---

## Agenda zu C


### [Einführung in die Arbeitsweise der Werkzeuge](../Tutorial/HelloWorld/HelloWorld.md) 
  * Editor
  * Präprozessor
  * Übersetzer (Compiler)
  * Linker
  * Debugger
  * "Hello World" &ndash; das erste Programm
  * Fehlermeldungen des Übersetzers

### [Datentypen, Variablen und Konstanten](../Tutorial/DatatypesVariablesConstants/DatatypesVariablesConstants.md) 
  * Konstante (Literale)
  * Variablen und Schlüsselwörter
  * Datentypen
  * C-Standarddatentypen (`int`, `long`, `short`, `float`, `double`)
  * Zeichen (Datentyp `char`)
  * Typumwandlungen
  * Initialisierung und Zuweisung

### [Operatoren und Ausdrücke](../Tutorial/Operators/Operators.md)
  * Wertzuweisung
  * Arithmetische Operatoren
  * Logische Operatoren
  * Arithmetische Ausdrücke
  * Inkrement und Dekrement
  * Vorrang und Assoziativität von Operatoren

### [Anweisungen und Konstrollstrukturen](../Tutorial/ControlStructures/ControlStructures.md)
  * Bedingungen, Verzweigungen und Wiederholungen
  * Die `if`- und `if`-`else`-Anweisung
  * Die `switch`-Anweisung
  * Wiederholungsanweisungen (Schleifen)
  * `while`, `do`-`while` und `for`-Anweisung
  * Sprünge in Schleifen (`break` und `continue`)
  * Endlosschleifen

### [Blockschachtelung](../Tutorial/NestedScope/NestedScope.md)
  * Schachtelung von Kontrollstrukturen
  * Schachtelung von Variablen-Definitionen
  * Verdeckung von Variablen
   
### [Felder (Arrays)](../Tutorial/Arrays/Arrays.md)
  * Deklaration und Initialisierung
  * Auf Feldelemente zugreifen
  * Felder in Schleifen durchlaufen


### [Funktionen / Unterprogramme](../Tutorial/Subroutines/Subroutines.md)
  * Funktionsdeklaration und Aufruf
  * Rückgabewert und Parameter
  * Lokale und globale Variablen
  * Funktionen und der *Stack* (*Stapel*)

### [Zeichen und Zeichenketten](../Tutorial/Strings/Strings.md)
  * Definition von Zeichen (Datentyp `char`) und Zeichenketten (Datentyp `const char*`)
  * Übergabe von Zeichenketten an Unterprogramme

### [Zeiger (*Pointer*)](../Tutorial/Pointers/Pointers.md)
  * Definition
  * Zeiger (Pointer) initialisieren (Referenzierung), Nullzeiger
  * Dereferenzierung
  * Zeigerarithmetik
  * Anwendung: Parameterübergabemechanismus *Call-by-Value* und *Call-by-Address*
  * Zeiger auf Zeiger
  * Funktionszeiger

### [Mehrdimensionale Felder](../Tutorial/MultidimensionalArrays/MultidimensionalArrays.md)
  * Mehrdimensionale Felder definieren und vorbelegen
  * Mehrdimensionale Felder an Unterprogramme übergeben

### [Strukturen](../Tutorial/Structs/Structs.md)
  * Definition und Anwendung
  * Schlüsselwort `struct`
  * Zugriff auf Elemente
  * Initialisierung von Strukturen
  * Felder von Strukturen
  * Schlüsselwort `typedef`

### [Bitfelder, Unions und Enums](../Tutorial/UnionsBitFieldsEnums/UnionsBitFieldsEnums.md)
  * Bitfelder
  * Unions
  * Schlüsselwort `union`
  * Aufzählungstypen 
  * Schlüsselwort `enum`

### [Speicherbereiche eines C–Programms](../Tutorial/MemoryManagement/MemoryManagement.md)
  * Globale Variablen
  * Lokale Variablen
  * Statische Variablen
  * Dynamische Variablen
  * Lebensdauer von Variablen in einem C&ndash;Programm
  
### [Dynamische Speicherverwaltung](../Tutorial/DynamicMemory/DynamicMemory.md)
  * Stapel und Halde (*Stack* und *Heap*)
  * Speicher reservieren und freigeben: `malloc` und `free`
  * [*Memory Leaks Detection* in C](MemoryLeaksDetection.md)
   
### [Die C-Standardbibliothek *CRT* (*C-Runtime-Library*)](../Tutorial/CRT/CRT.md)
  * Ein- und Ausgabe auf die Konsole: `printf`
  * Zeichenkettenverarbeitung mit `strlen`, `strcpy` etc.
  * Zufallszahlen: `rand`, `srand`
  * Typkonvertierungen: `atof`, `atoi`, `atol`, `strtod`, `strtol`, `strtoul`

### [Einige fortgeschrittene Themen](../Tutorial/AdvancedTopics/AdvancedTopics.md)
  * Vektorisieren von Funktionsaufrufen (Makro-Techniken, Gebrauch von `__VA_ARGS__`)
  * Funktionsüberladungen nachahmen (C11 Schlüsselwort `_Generic`)
  * &bdquo;Generische Programmierung in C&rdquo;&ndash; `void*`


---

[Zurück](../../Readme.md)

---
