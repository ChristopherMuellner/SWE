## Datenstrukturen in Java: ArrayList, LinkedList, HashMap und Hashtable

In Java gibt es mehrere wichtige Datenstrukturen, darunter `ArrayList`, `LinkedList`, `HashMap` und `Hashtable`. Jede dieser Strukturen hat eigene Anwendungsfälle und Vor- bzw. Nachteile. Hier ist eine Übersicht dieser Datenstrukturen.

### 1. ArrayList
Eine `ArrayList` ist ein dynamisches Array, dessen Größe zur Laufzeit angepasst werden kann. Sie speichert Elemente in der Reihenfolge ihres Einfügens und bietet schnellen Zugriff über den Index.

#### Vorteile:
- **Zugriff auf Elemente**: Sehr schneller Zugriff über den Index (O(1)).
- **Größe**: Kann dynamisch wachsen oder schrumpfen.

#### Nachteile:
- **Einfügen/Löschen**: Das Hinzufügen und Entfernen von Elementen kann teuer sein (O(n)), besonders in der Mitte oder am Anfang.

#### Beispiel:
```java
// ArrayList Beispiel
ArrayList<Integer> arrayList = new ArrayList<>();
arrayList.add(1);
arrayList.add(2);
arrayList.add(3);
for (int i : arrayList) {
    System.out.print(i + " ");  // Ausgabe: 1 2 3
}
System.out.println();
```

### 2. LinkedList
Eine `LinkedList` ist eine doppelt verkettete Liste, bei der jedes Element auf das nächste und vorherige zeigt. Das Hinzufügen und Entfernen von Elementen ist effizient, besonders in der Mitte der Liste.

#### Vorteile:
- **Einfügen/Löschen**: Effizientes Hinzufügen und Entfernen von Elementen an beliebigen Positionen (O(1), wenn der Zeiger bekannt ist).

#### Nachteile:
- **Zugriff auf Elemente**: Langsamer als bei einer `ArrayList` (O(n)).

#### Beispiel:
```java
// LinkedList Beispiel
LinkedList<Integer> linkedList = new LinkedList<>();
linkedList.add(1);
linkedList.add(2);
linkedList.add(3);
for (int i : linkedList) {
    System.out.print(i + " ");  // Ausgabe: 1 2 3
}
```

### 3. HashMap
Eine `HashMap` speichert Daten als Schlüssel-Wert-Paare. Der Zugriff auf Elemente erfolgt über eine Hash-Funktion, die die Daten effizient in Buckets aufteilt.

#### Vorteile:
- **Zugriff**: Sehr schneller Zugriff auf Daten (O(1) durchschnittlich).
- **Flexibilität**: Unterstützt `null`-Werte und `null`-Schlüssel.

#### Nachteile:
- **Threadsicherheit**: Nicht threadsicher. Für eine threadsichere Alternative wird `Hashtable` oder `ConcurrentHashMap` verwendet.
- **Ordnung**: Die Reihenfolge der Elemente ist nicht garantiert.

#### Beispiel:
```java
// HashMap Beispiel
HashMap<String, Integer> hashMap = new HashMap<>();
hashMap.put("apple", 5);
hashMap.put("banana", 3);

System.out.println("apple: " + hashMap.get("apple"));  // Ausgabe: apple: 5
System.out.println("banana: " + hashMap.get("banana"));  // Ausgabe: banana: 3
```

### 4. Hashtable
Eine `Hashtable` ist ähnlich wie eine `HashMap`, aber sie ist threadsicher. Das bedeutet, dass sie in Multi-Threading-Umgebungen sicher verwendet werden kann.

#### Vorteile:
- **Threadsicherheit**: Geeignet für den Einsatz in Umgebungen mit mehreren Threads.

#### Nachteile:
- **Leistung**: Langsamer als `HashMap` aufgrund der Synchronisierung.
- **Null-Werte**: Unterstützt keine `null`-Schlüssel oder `null`-Werte.

---

### Zusammenfassung:
- **ArrayList**: Dynamisches Array, schneller Zugriff, ineffizientes Einfügen/Löschen in der Mitte.
- **LinkedList**: Verkettete Liste, effizient beim Einfügen/Löschen, langsamer Zugriff.
- **HashMap**: Schneller, flexibler Zugriff auf Schlüssel-Wert-Paare, nicht threadsicher.
- **Hashtable**: Threadsichere Alternative zur `HashMap`, aber langsamer und keine Unterstützung für `null`-Werte.

#### Wichtige Punkte:
- **ArrayList**: O(1) für Lesezugriffe.
- **LinkedList**: O(1) für Einfügen/Löschen, O(n) für Lesezugriffe.
- **HashMap**: O(1) Zugriff auf Schlüssel-Werte-Paare, nicht threadsicher.
- **Hashtable**: Threadsicher, langsamer, keine `null`-Schlüssel/Werte.
