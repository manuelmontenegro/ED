# Semana 6 - Árboles binarios

<div class="aims">
<div class="aims_header">
✔️ Objetivos
</div>

* Conocer las definiciones básicas de los árboles y los conceptos que indican
  las relaciones entre los nodos.

* Conocer la subcategoría más habitual al trabajar con árboles: los árboles
  binarios.

* Implementar funciones sobre árboles.
    
<div class="aims_header">
✔️ Tiempo de estudio
</div>

* **Vídeos**: 54min (+3:55min opcionales)

* **Total** *(incluyendo vídeos, cuestionarios y actividades de autoevaluación)*: 2h 30min

</div>

## 6.1. Presentando los árboles

Esta semana comenzamos un nuevo tema: los tipos de datos basados en estructuras arborescentes y, en particular, los árboles binarios. Los árboles binarios nos proporcionan una base sobre la que implementar los TADs que nos quedan por ver en este curso: conjuntos, multiconjuntos y diccionarios.

En el siguiente vídeo se introduce la definición de árbol y una serie de conceptos asociados que aparecerán de manera recurrente a lo largo de las próximas semanas:

▶️ [Introducción a los árboles](https://youtu.be/tegHDFJQ_ig) (6:03)

<div class="exercise">
<div class="title">
📝 Ejercicio 6.1
</div>
<div class="body">

El vídeo anterior contiene mucha terminología nueva. Vamos a ponerla en práctica con ejemplos:

❓ [Cuestionario de autoevaluación - Árboles](quizzes/sem06_1.md)

</div>
</div>

## 6.2. Árboles binarios

Dentro de los distintos tipos de árboles que hemos introducido en el vídeo anterior, los árboles binarios son, sin duda, los más utilizados. Esta subcategoría de árboles proporciona los mecanismos que necesitaremos a la hora de implementar los TADs mencionados arriba, sin llegar a introducir más complejidad que la necesaria.

Como siempre, cada vez que presentamos un nuevo Tipo Abstracto de Datos, enumeramos las operaciones soportadas por él. Esto es lo que hacemos en el siguiente vídeo:

▶️ [El TAD Árbol Binario](https://youtu.be/cBmopiKUeLM) (4:21)

<div class="exercise">
<div class="title">
📝 Ejercicio 6.2
</div>
<div class="body">

Para entender los costes de los algoritmos que trabajan sobre árboles es necesario conocer muy bien la relación entre el número de nodos que hay en un árbol binario en función de su altura. Dado un árbol de altura *h*, ¿cuántos nodos tiene como mínimo? ¿y como máximo?

❓ [Cuestionario de autoevaluación - Número de nodos en un árbol binario](quizzes/sem06_2.md)

</div>
</div>

Hay varias maneras de implementar el TAD de los árboles binarios. La más habitual es la implementación mediante nodos en el *heap*. La idea es muy similar a la de las listas enlazadas: tenemos nodos que apuntan a otros nodos.

▶️ [Implementación de árboles binarios](https://youtu.be/YVmeIDmiCiI) (10:09)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/blob/main/arboles/bintree_v1/bintree.h)

<div class="exercise">
<div class="title">
📝 Ejercicio 6.2
</div>
<div class="body">

El final del vídeo revelaba un problema peliagudo: ¿Cómo se destruyen los nodos de manera ordenada, es decir, sin acabar haciendo `delete` sobre el mismo nodo dos veces?. El hecho de que los árboles compartan nodos dificulta la tarea. En el vídeo anterior se menciona una alternativa que eliminaría el problema de raíz: *evitar la compartición entre nodos*. Pero hay otra posibilidad:

¿Cómo modificarías la clase `BinTree` para que su constructor hiciese una **copia** de los nodos de los árboles que recibe?

💻 [Ejercicio: Evitar la compartición mediante copias de nodos](https://godbolt.org/z/Y95jWG6W6)

💻 [Solución](https://godbolt.org/z/5778v9fr6)

</div>
</div>

En la siguiente sección presentaremos la alternativa que involucra el uso de
punteros inteligentes. Esta es la que utilizaremos a lo largo de esta semana.

## 6.3. Punteros inteligentes en C++ y su aplicación al TAD Árbol Binario

 Hasta ahora hemos hablado mucho de punteros inteligentes, pero no hemos dicho en qué consisten. Esto es un aspecto más avanzado de C++, el cual vamos a presentar en el siguiente vídeo:

▶️ [C++ - Punteros inteligentes](https://youtu.be/Hjxny-_RgPI) (8:18)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/tree/main/cpp/11_smart_pointers)


<div class="exercise">
<div class="title">
📝 Ejercicio 6.4
</div>
<div class="body">

Si dentro de nuestra clase `BinTree` sustituimos los punteros «tontos» `TreeNode *` por punteros inteligentes, podemos descansar de la tarea de saber cómo y cuando liberar los nodos. ¿Te animas?

💻 [Ejercicio: Punteros inteligentes en la clase TreeNode](https://godbolt.org/z/3s8qoY7o5)

</div>
</div>

La solución está en el siguiente vídeo. **Esta será la implementación que utilizaremos en el resto de esta semana y la siguiente**.


▶️ [Compartición en árboles binarios](https://youtu.be/VDol3zHvZng) (3:13)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/blob/main/arboles/bintree_v3/bintree.h)

## 6.4. Funciones recursivas sobre árboles binarios

 En los ejercicios de evaluación continua que realizaremos esta semana se pide implementar funciones que reciban un árbol binario recibido como parámetro y lo examinen recursivamente para obtener un determinado valor (por ejemplo, número de nodos, altura, etc.). Recuerda que los árboles binarios son un TAD recursivo, por lo que es bastante habitual que las funciones de las que te hablo sean también **recursivas**.



<div class="exercise">
<div class="title">
📝 Ejercicio 6.5 (Importante!)
</div>
<div class="body">

Vamos a comenzar con unos ejemplos sencillos. Para ello comienza accediendo al siguiente enlace:

💻 [Funciones sobre árboles](https://godbolt.org/z/7h5cs5dMe)


1. Implementa una función que, dado un `BinTree`, devuelva el número de nodos
que contiene. La función es **externa** a la clase `BinTree`. Es decir, la
implementación no debe hacer uso de los atributos privados de esta clase, ni
siquiera hacer uso de `TreeNode`.
   
   ```cpp
   template <typename T>
   int numero_nodos(const BinTree<T> &tree);
   ```

2. Implementa una función que, dado un `BinTree`, devuelva su altura. La función
es externa a la clase `BinTree`.

   ```cpp
   template <typename T>
   int altura(const BinTree<T> &tree);
   ```


3. Implementa una función que, dado un `BinTree` de números enteros, devuelva la
suma de la información contenida en todos sus nodos. La función es externa a
la clase `BinTree`.

   ```cpp
   int suma_nodos(const BinTree<int> &tree);
   ```

4. Implementa una función que, dado un `BinTree` de números enteros, devuelva un valor booleano indicando si alguno de sus nodos contiene un número par. La función es externa a la clase `BinTree`.

   ```cpp
   bool contiene_pares(const BinTree<int> &tree);
   ```

💻 [Soluciones](https://godbolt.org/z/nxdh1crTx)

</div>
</div>

 Antes de continuar estudiando más funciones sobre árboles binarios, vamos a hacer una breve parada por algunas clases de la librería estándar de C++. Estas funciones nos van a ser útiles para implementar funciones que devuelvan varios resultados. Puede que ya las conozcas de la asignatura de *Fundamentos de Algoritmia*.

▶️ [C++ - Los tipos pair y tuple](https://youtu.be/-z4Ek2SZ70o) (8:33) 

## 6.5. Árboles binarios equilibrados

 A continuación se muestra una definición muy importante: los *árboles equilibrados*. Un árbol está equilibrado si es el árbol vacío, o bien la diferencia entre las alturas de sus hijos es menor o igual que 1 y ambos hijos son equilibrados. Aparentemente podemos implementar una función similar a las que has hecho antes para poder determinar si un árbol está equilibrado. Pero ¡ojo!, si lo haces de manera «ingenua» puedes incurrir en costes elevados. Se explica en el siguiente vídeo:

▶️ [Funciones sobre árboles binarios](https://youtu.be/eTxLBxKji20) (13:07)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/blob/main/arboles/bintree_v3/main.cpp#L39)

En el anterior vídeo se ha quedado una propiedad pendiente de demostrar. Aquí explico la demostración:

▶️ [Demostración del coste de la versión inicial de la función `height()`](https://youtu.be/xU_jIbIc90I) (Opcional) (3:55)

El siguiente documento te puede resultar útil para saber cómo resolver una recurrencia, pero ten en cuenta que esto es un **prerrequisito** de este curso. Concretamente, habéis visto este material en la asignatura de *Fundamentos de Algoritmia*.

📕 [Cálculo de costes en funciones recursivas](sem6/recurrencias.pdf)

<div class="exercise">
<div class="title">
📝 Ejercicio 6.6
</div>
<div class="body">

El siguiente test plantea varios algoritmos genéricos sobre árboles. Debes plantear la recurrencia y utilizar las fórmulas del documento anterior para obtener el orden de complejidad de los algoritmos.

❓ [Cuestionario de autoevaluación - Funciones sobre árboles binarios](quizzes/sem06_3.md)

</div>
</div>


## 6.6. Ejercicios y problemas de laboratorio

<div class="exercise">
<div class="title">
📝 Ejercicio 6.7
</div>
<div class="body">

💻 [Árboles zurdos (con solución)](assignments/L06-1.pdf)

</div>
</div>


<div class="exercise">
<div class="title">
📝 Ejercicio 6.8
</div>
<div class="body">

💻 [Árboles equilibrados raquíticos](assignments/L06-2.pdf)

</div>
</div>


<div class="exercise">
<div class="title">
📝 Ejercicio 6.9
</div>
<div class="body">

💻 [Área más grande en un árbol binario](assignments/L06-3.pdf)

</div>
</div>


<div class="exercise">
<div class="title">
📝 Ejercicio 6.10
</div>
<div class="body">

💻 [Árboles estables en altura](assignments/L06-4.pdf)

</div>
</div>

<div class="exercise">
<div class="title">
📝 Ejercicio 6.11
</div>
<div class="body">

💻 [Árboles equilibrados estables](assignments/L06-5.pdf)

</div>
</div>


