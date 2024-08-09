# Semana 8 - Árboles binarios de búsqueda y el TAD Conjunto

<div class="aims">
<div class="aims_header">
✔️ Objetivos
</div>

* Identificar las operaciones principales del TAD Conjunto. 

* Diferenciar los casos de uso del TAD Conjunto y los del TAD Lista.

* Conocer las propiedades de los árboles binarios de búsqueda.

* Conocer la implementación de las operaciones de inserción, búsqueda y borrado en árboles binarios de búsqueda.
    
<div class="aims_header">
✔️ Tiempo de estudio
</div>

* **Vídeos**: 57min (+14 min opcionales)

* **Total** *(incluyendo vídeos, cuestionarios y actividades de autoevaluación, pero no los problemas de la sección 8.5)*: 2h

</div>


## 8.1. Operaciones del TAD Conjunto

Esta semana comenzamos con un nuevo tipo abstracto de datos para almacenar colecciones de elementos: el TAD Conjunto. Para ello, utilizamos el enfoque de siempre: identificamos un modelo al que se le asocian un conjunto de operaciones.

▶️ [El TAD Conjunto - operaciones](https://youtu.be/xtKtoEhbXyo) (6:18)

Es esencial conocer la diferencia entre los conjuntos y las listas. Existen varias propiedades que los diferencian. En primer lugar, el contenido de una lista depende del orden en el que insertemos los elementos. Esto implica que los dos fragmentos de programa que aparecen a continuación **no** son equivalentes:

<div style="display:flex;justify-content: center;gap:1em">
<div>

**Programa 1**

```cpp
list<int> l;
l.push_back(1);
l.push_back(2);
```

</div>
<div>

**Programa 2**

```cpp
list<int> l;
l.push_back(2);
l.push_back(1);
```

</div>
</div>

Por el contrario, en los conjuntos, las inserciones son intercambiables. Los fragmentos que vas a ver a continuación sí son semánticamente equivalentes:

<div style="display:flex;justify-content: center;gap:1em">
<div>

**Programa 1**

```cpp
set<int> s;
s.insert(1);
s.insert(2);
```

</div>
<div>

**Programa 2**

```cpp
set<int> s;
s.insert(2);
s.insert(1);
```

</div>
</div>

Otra propiedad que disfrutan los conjuntos, pero no las listas, es el hecho de que la operación de inserción es idempotente. Es decir, los siguientes fragmentos son semánticamente equivalentes:

<div style="display:flex;justify-content: center;gap:1em">
<div>

**Programa 1**

```cpp
set<int> s;
s.insert(1);
s.insert(1);
```

</div>
<div>

**Programa 2**

```cpp
set<int> s;
s.insert(1);
```

</div>
</div>

Con las listas no ocurre lo mismo. Si se añade un mismo elemento dos veces al final de una lista, la lista contendrá ambas apariciones del mismo elemento.

## 8.2. Primera implementación del TAD Conjunto: listas ordenadas

Nuestro primer intento de implementación del TAD Conjunto se basa en el TAD Lista que ya hemos visto anteriormente. La idea consiste en mantener una lista que contenga los elementos del conjunto, evitando tener elementos duplicados. Las tres operaciones básicas de los conjuntos (insertar, eliminar y comprobar la pertenencia de un elemento) requieren hacer una búsqueda por la lista[^1], cosa que sabemos hacer.

Ya conocéis, además, que la búsqueda es más eficiente si se hace en una lista ordenada, ya que en estos casos puede utilizarse el algoritmo de búsqueda binaria.

▶️ [Implementación del TAD Conjunto mediante listas ordenadas](https://youtu.be/zUjo35qBQEE) (Opcional - 13:56)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/blob/main/arboles/set_list_v1/set_list.h)

Pese a la relativa sencillez de la implementación, las listas ordenadas no resultan demasiado útiles para implementar el TAD Conjunto, porque hay alternativas mejores. En particular, se obtienen implementaciones más eficientes mediante otros mecanismos como, por ejemplo, los árboles binarios de búsqueda y las tablas *hash*. En la siguiente sección se describen los árboles binarios de búsqueda. Las tablas *hash* se estudiarán dentro de dos semanas.

[^1]: En el caso de la inserción, necesitamos la búsqueda para comprobar que el elemento que se quiere insertar no exista ya en la lista.

## 8.3. Árboles binarios de búsqueda

Pasamos a ver una de las estructuras de datos más importantes de este curso: los árboles binarios de búsqueda (ABB).

▶️ [Árboles binarios de búsqueda - introducción](https://youtu.be/RDxSW4j3iGw) (12:01)

Un comentario sobre el coste: Resulta fácil ver que la búsqueda tiene coste lineal con respecto a la **altura** del árbol. También resulta intuitivo el hecho de que la altura, en el caso peor, puede llegar a ser lineal con respecto al número de nodos del árbol (esto pasa, en particular, cuando el árbol es degenerado). No obstante, **si el árbol es equilibrado, la altura es logarítmica con respecto al número de nodos del árbol**.

Hemos visto cómo se buscan elementos en un ABB. Pasamos a estudiar la inserción de elementos. 

<div class="exercise">
<div class="title">
📝 Ejercicio 8.1
</div>
<div class="body">

 Antes de pasar al vídeo, vamos a intentar deducir las líneas generales del algoritmo:

❓ [Ejercicio - inserción en un árbol binario de búsqueda](quizzes/sem08_1.md)

</div>
</div>

Ahora veamos cómo se implementa la inserción en C++:

▶️ [Inserción en árboles binarios de búsqueda](https://youtu.be/ZQlN1k2A_PY) (9:39)

Pasamos al borrado de elementos en un ABB. Esto es más difícil de lo que parece, sobre todo si eliminamos un nodo interno. De nuevo, es importante que intentes el siguiente ejercicio/cuestionario para poder entender mejor el vídeo que viene después.

<div class="exercise">
<div class="title">
📝 Ejercicio 8.2
</div>
<div class="body">

❓ [Ejercicio - borrado en un árbol binario de búsqueda](quizzes/sem08_2.md)

</div>
</div>

Ahora sí, vemos la explicación e implementación en C++:

▶️ [Eliminación en árboles binarios de búsqueda](https://youtu.be/t0c758n5BLM) (15:31)

El vídeo anterior explica que para borrar un nodo con dos hijos hemos de reemplazar el nodo borrado con el menor de los elementos del hijo derecho. Otra posibilidad podría haber sido reemplazarlo con el mayor de los elementos del hijo izquierdo. Para ello tendríamos que bajar al hijo izquierdo y, desde allí, seguir el camino descendente bajando por los hijos derechos de cada nodo, hasta que no sea posible descender más.

A continuación vamos a ver unos resultados importantes sobre los árboles binarios de búsqueda. En particular, vamos a ver la relación entre el orden de inserción en un ABB y el hecho de que esté equilibrado. Luego veremos las propiedades del recorrido en inorden en un ABB.

<div class="exercise">
<div class="title">
📝 Ejercicio 8.3
</div>
<div class="body">

❓ [Ejercicio - Orden de inserción en un ABB y recorridos en inorden](quizzes/sem08_3.md)

</div>
</div>

De este ejercicio se deduce un aspecto importante sobre el coste de estos algoritmos, que depende de si el árbol sobre el que se aplican está equilibrado o no. A su vez, el hecho de que un árbol esté equilibrado depende del orden en el que se hayan insertado sus elementos. Por ejemplo, si insertamos en un ABB vacío los elementos 5, 1 y 7 (en este orden), obtenemos un árbol equilibrado. Por el contrario, si insertamos en un ABB vacío los elementos 1, 5 y 7 (en ese orden) no obtenemos un árbol equilibrado.

<div class="info">
<div class="title">
ℹ️  Árboles binarios de búsqueda equilibrados
</div>
<div class="body">

Existen otras implementaciones de ABBs que se **reequilibran automáticamente cada vez que se inserta o borra un elemento**. De este modo, las operaciones de inserción, eliminación y búsqueda siempre tienen coste logarítmico. Este tipo de árboles se estudian en otras asignaturas más avanzadas de algoritmia. En esta asignatura nos conformaremos con saber que existen implementaciones así. Entre ellas:

* **Árboles AVL**: Consiguen equilibrar el árbol mediante rotaciones en sus nodos ([Referencia](https://en.wikipedia.org/wiki/AVL_tree)).

* **Árboles rojinegros**: Cada nodo lleva asociado un color (rojo o negro), y existen algunas reglas que determinan la estructura del árbol (por ejemplo, los hijos de un nodo rojo han de ser negros). Mantener esas reglas desemboca en el hecho de que el árbol acaba estando equilibrado ([Referencia](https://en.wikipedia.org/wiki/Red%E2%80%93black_tree)).


</div>
</div>


## 8.4. El retorno del TAD Conjunto

¿Por qué hemos estado hablando tanto de los árboles de búsqueda? Porque son un mecanismo muy útil para implementar el TAD Conjunto, que hemos visto al principio de esta semana, y el TAD Diccionario, que veremos la semana que viene. En el caso de los conjuntos, utilizar árboles binarios de búsqueda supera con creces, en términos de coste asintótico, la eficiencia de la implementación basada en listas ordenadas.

▶️ [Implementación del TAD Conjunto mediante ABBs](https://youtu.be/bFpYvMZo09k) (13:46)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/blob/main/arboles/set_tree_v1/set_tree.h)

<div class="exercise">
<div class="title">
📝 Ejercicio 8.4
</div>
<div class="body">

En el tema introductorio sobre Tipos Abstractos de Datos comenzamos con un juego en el que dos jugadores iban nombrando letras hasta que el primero de ellos nombraba una letra repetida. Allí se utilizaba una implementación rudimentaria del TAD Conjunto que estaba restringida a caracteres comprendidos entre A y Z. Ahora podemos hacer uso de nuestra implementación `SetTree` para poder extender el rango de caracteres. ¿Te animas?

💻 [Ejercicio: juego de letras](https://godbolt.org/z/h3oWrcPfb)

💻 [Solución](https://godbolt.org/z/3MjMr6n9Y)

</div>
</div>

<div class="exercise">
<div class="title">
📝 Ejercicio 8.5
</div>
<div class="body">

Terminamos la teoría de esta semana con un pequeño cuestionario sobre el TAD conjunto.

❓ [Cuestionario - El TAD Conjunto](quizzes/sem08_4.md)

</div>
</div>

## 8.5. Problemas de laboratorio

<div class="exercise">
<div class="title">
📝 Ejercicio 8.6
</div>
<div class="body">

💻 [El juego de la mona](assignments/L08-1.pdf)

</div>
</div>

<div class="exercise">
<div class="title">
📝 Ejercicio 8.7
</div>
<div class="body">

💻 [El método `count_interval`](assignments/L08-2.pdf)

</div>
</div>

<div class="exercise">
<div class="title">
📝 Ejercicio 8.8
</div>
<div class="body">

💻 [Los viejos teclados T9](assignments/L08-3.pdf)

</div>
</div>