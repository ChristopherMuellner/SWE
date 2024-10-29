## Datenstrukturen in C++: std::vector, std::list und std::unordered_map

In C++ gibt es ähnliche Datenstrukturen wie in Java, die verwendet werden, um Daten effizient zu speichern und zu verwalten. Die häufig genutzten Containerklassen sind `std::vector`, `std::list` und `std::unordered_map`. Diese Strukturen bieten leistungsfähige und flexible Möglichkeiten für verschiedene Anwendungen.

### 1. std::vector
Ein `std::vector` ist ein dynamisches Array, das seine Größe automatisch anpassen kann. Es bietet schnellen Zugriff auf Elemente über den Index und ermöglicht das Hinzufügen neuer Elemente am Ende des Containers.

#### Vorteile:
- **Zugriff auf Elemente**: Sehr schneller Zugriff über den Index (O(1)).
- **Größenanpassung**: Kann dynamisch wachsen, um mehr Elemente aufzunehmen.

#### Nachteile:
- **Einfügen/Löschen**: Das Einfügen oder Entfernen von Elementen, besonders in der Mitte oder am Anfang, ist relativ teuer (O(n)).

#### Beispiel:
```cpp
#include <iostream>
#include <vector>

int main()
{
    // std::vector Beispiel
    std::vector<int> vec = {1, 2, 3, 4, 5};
    vec.push_back(6);
    for (int i : vec)
    {
        std::cout << i << " ";  // Ausgabe: 1 2 3 4 5 6
    }
    std::cout << std::endl;
}
```

### 2. std::list
Eine `std::list` ist eine doppelt verkettete Liste, bei der jedes Element auf das nächste und vorherige Element verweist. Das Einfügen und Entfernen von Elementen an beliebigen Stellen ist sehr effizient.

#### Vorteile:
- **Einfügen/Löschen**: Sehr effizient, besonders in der Mitte oder am Anfang (O(1), wenn der Zeiger bekannt ist).

#### Nachteile:
- **Zugriff auf Elemente**: Langsamer als bei einem `std::vector`, da kein direkter Indexzugriff möglich ist (O(n)).

#### Beispiel:
```cpp
#include <iostream>
#include <list>

int main()
{
    // std::list Beispiel
    std::list<int> lst = {1, 2, 3};
    lst.push_back(4);
    for (int i : lst)
    {
        std::cout << i << " ";  // Ausgabe: 1 2 3 4
    }
}
```

### 3. std::unordered_map
Ein `std::unordered_map` ist eine Hash-Tabellen-Implementierung, die Schlüssel-Wert-Paare speichert. Der Zugriff auf die Werte erfolgt effizient über die Schlüssel, wobei die Daten in Buckets organisiert sind.

#### Vorteile:
- **Zugriff**: Sehr schnelle Zugriffszeiten (O(1) durchschnittlich) auf Schlüssel-Wert-Paare.
- **Flexibilität**: Ermöglicht das Speichern von Daten in nicht geordneter Weise, wobei die Reihenfolge nicht garantiert ist.

#### Nachteile:
- **Threadsicherheit**: Nicht threadsicher ohne explizite Synchronisierungsmaßnahmen.
- **Ordnung**: Die Reihenfolge der Elemente wird nicht garantiert.

#### Beispiel:
```cpp
#include <iostream>
#include <unordered_map>

int main()
{
    // std::unordered_map Beispiel
    std::unordered_map<std::string, int> hashTable;
    hashTable["apple"] = 5;
    hashTable["banana"] = 3;

    std::cout << "apple: " << hashTable["apple"] << std::endl;  // Ausgabe: apple: 5
    std::cout << "banana: " << hashTable["banana"] << std::endl;  // Ausgabe: banana: 3
}
```

---

### Zusammenfassung:
- **std::vector**: Dynamisches Array, schneller Zugriff auf Elemente über den Index, ineffizient bei Einfügen oder Entfernen in der Mitte.
- **std::list**: Verkettete Liste, effizient für häufiges Einfügen und Entfernen, aber langsamer beim Zugriff.
- **std::unordered_map**: Schneller Zugriff auf Schlüssel-Wert-Paare, nicht geordnet, nicht threadsicher.

#### Wichtige Punkte:
- **std::vector**: O(1) für Lesezugriffe, O(n) für Einfügen/Löschen in der Mitte.
- **std::list**: O(1) für Einfügen/Löschen, O(n) für Lesezugriffe.
- **std::unordered_map**: O(1) Zugriff auf Schlüssel-Wert-Paare, nicht geordnet.
