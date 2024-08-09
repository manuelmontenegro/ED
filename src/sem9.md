# Semana 9 - Diccionarios y recorridos iterativos de árboles binarios

<div class="aims">
<div class="aims_header">
✔️ Objetivos
</div>

* Conocer el tipo abstracto de datos Diccionario, e identificar sus casos de uso.

* Implementar el TAD Diccionario utilizando árboles binarios de búsqueda.

* Conocer el algoritmo de recorrido en inorden iterativo.

* Utilizar iteradores en implementaciones de TADs basados en árboles.

* Saber parametrizar los árboles binarios de búsqueda en función de la relación de orden utilizada.
    
<div class="aims_header">
✔️ Tiempo de estudio
</div>

* **Vídeos**: 48 min (+16 min opcionales)

* **Total** *(incluyendo vídeos, cuestionarios y actividades de autoevaluación, pero no los problemas de la sección 9.4)*: 2h

</div>

Esta semana presentamos el TAD Diccionario y una de sus implementaciones, basada en árboles binarios de búsqueda. Existen otras implementaciones, basadas en tablas *hash*, que estudiaremos la semana que viene.

También aprovecharemos esta semana para profundizar en los recorridos sobre árboles binarios. Nuestro objetivo será recorrer en inorden los nodos de un árbol binario **de manera iterativa**, mediante iteradores.

## 9.1. Operaciones del TAD Diccionario

Los diccionarios (*maps* en inglés) son unos de los tipos abstractos de datos más utilizados para almacenar colecciones de elementos. Cada *valor* almacenado en un diccionario va asociado a una *clave*, que es la que utilizamos para posteriormente buscar dicho valor. Comenzamos describiendo las operaciones básicas:

▶️ [El TAD Diccionario - operaciones](https://youtu.be/KuPRA9gmles) (11:29)

Los diccionarios son la representación abstracta de las tablas de una base de datos relacional. En este tipo de bases de datos, las tablas son conjuntos de filas, cada una de ellas identificada unívocamente mediante una clave. Las bases de datos optimizan la búsqueda de filas a partir de identificadores o claves (o de otros índices que especifique el/la usuario/a). Eso mismo es lo que hace un diccionario.

<div class="info">
<div class="title">
ℹ️ Diferencia entre diccionarios y conjuntos
</div>
<div class="body">

¿Cuál es la diferencia entre el TAD Diccionario y el TAD Conjunto visto anteriormente? Al fin y al cabo, en lugar de un diccionario podríamos tener un objeto `SetTree` que almacene objetos de tipo `pair<clave, valor>`, ¿no?

Pues bien, un diccionario **no** es lo mismo que un conjunto de pares. La diferencia reside en las operaciones de búsqueda:

* En un diccionario, las operaciones `contains` y `at` permiten buscar un par suponiendo que solo conocemos su primera componente (la clave). Además, la operación `at` devuelve el valor asociado a esa clave.

* Por otro lado, en un TAD Conjunto solo tenemos la operación `contains` de búsqueda, que en este caso tendría que recibir **las dos componentes** del par (clave, valor) que queremos buscar. Es decir, necesitamos pasar a la función `contains` de un conjunto ambas componentes para que nos diga si ese par está o no en el conjunto.

En resumen: para buscar una entrada en un diccionario tan solo necesitamos la clave de esa entrada. Para buscar un par en un conjunto necesitaríamos las dos componentes: clave y valor.

El TAD Diccionario y el TAD Conjunto, no obstante, comparten algunas similitudes. Una de ellas es que el orden en el que insertemos las entradas o elementos no afecta al diccionario o conjunto resultante.

</div>
</div>

## 9.2. Implementación del TAD Diccionario mediante árboles binarios de búsqueda

Pasamos ahora a implementar las operaciones presentadas en la sección anterior. Queremos realizar búsquedas por clave de manera eficiente. Por tanto, parece razonable utilizar el mismo enfoque que hemos utilizado para el TAD Conjunto de la semana pasada, es decir, utilizar árboles binarios de búsqueda.

En el siguiente vídeo se describe cómo hacer esto. La implementación resultante es muy similar a la del TAD Conjunto, con la diferencia de que ahora se comparan claves, en lugar de elementos. Al final del vídeo se introduce una nueva operación `operator[]`, que es similar a la operación `at`, pero trata de manera diferente los casos en los que la clave a buscar no se encuentra en el diccionario.

▶️ [Implementación del TAD Diccionario mediante ABBs](https://youtu.be/pY1QnOkEey4) (12:52)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/blob/main/diccionarios/map_tree_v1/map_tree.h)


<div class="info">
<div class="title">
ℹ️ Inicialización a cero
</div>
<div class="body">

Observa un detalle que no se menciona en los vídeos. Mira en [esta línea](https://github.com/manuelmontenegro/ED/blob/9e5fe90e3799eb72228222869c6fd98d618f1af7/diccionarios/map_tree_v1/map_tree.h#L33) uno de los constructores de `MapEntry`. Utilizando la expresión `value()` en la lista de inicialización, estamos dando un valor por defecto a `value`. Si el tipo de `value` es un objeto, se llamará a su constructor por defecto, pero si el tipo es básico (por ejemplo `int`), se inicializará a un valor por defecto. En el caso de las variables de tipo `int`, ese valor es `0`. Esto nos permite, en el ejemplo de conteo de palabras visto en el vídeo anterior, sustituir toda la sentencia condicional:

```cpp
if (dicc.contains(palabra)) {
    dicc.at(palabra)++;
} else {
    dicc.insert({palabra, 1});
}
```
por una única sentencia, mucho más corta:

```cpp
dicc[palabra]++;
```

En efecto, si la `palabra` no existe en el diccionario, el operador corchete (`operator[]`) crea una nueva entrada asociada al valor 0, y luego el operador `++` incrementa ese valor. En ese caso, la sentencia anterior sería equivalente a `dicc.insert({palabra, 1})`. Por el contrario, si la palabra ya existe en el diccionario, el uso del corchete es equivalente a `at`, por lo que `dicc[palabra]++` sería equivalente a `dicc.at(palabra)++`.

</div>
</div>

### 9.2.1. Relaciones de orden en árboles binarios de búsqueda

Las mayoría de clases que hemos visto en este curso son paramétricas. Por ejemplo, tenemos `SetTree<T>`, donde `T` representa el tipo de los elementos del conjunto. En la mayoría de ejemplos que hemos visto, este tipo `T` ha sido `int` o `string`. Es decir, hemos trabajado con conjuntos de enteros o de cadenas de texto. Con los diccionarios pasa algo similar. El tipo `MapTree<K, V>` es paramétrico con respecto al tipo de las claves `K` y el tipo de los valores `V`. Hasta ahora hemos tratado con tipos básicos como claves (`int` y `string`). Pero, ¿qué pasa si tenemos un diccionario cuyas claves son objetos definidos por el/la programador/a? Observa el siguiente código:

💻 [Diccionarios con claves compuestas (1)](https://godbolt.org/z/4HNjH8)

¡Se obtiene un error de compilación al descomentar la segunda parte del código! El siguiente vídeo explica por qué se produce este error y cómo solucionarlo. A partir del minuto 7:10 se cuentan algunos detalles de implementación, que son más técnicos, y no es necesario conocerlos.

▶️ [Relaciones de orden en ABBs](https://youtu.be/eGD0b_hkvdE) (8:29)

📄 [Código fuente (TAD Diccionario)](https://github.com/manuelmontenegro/ED/blob/main/diccionarios/map_tree_v2/map_tree.h)

📄 [Código fuente (TAD Conjunto)](https://github.com/manuelmontenegro/ED/blob/main/arboles/set_tree_v2/set_tree.h)

<div class="exercise">
<div class="title">
📝 Ejercicio 9.1
</div>
<div class="body">

En el siguiente código puedes experimentar con algunas relaciones de orden:

💻 [Diccionarios con claves compuestas (2)](https://godbolt.org/z/9ZyZt9)

</div>
</div>

<div class="exercise">
<div class="title">
📝 Ejercicio 9.2
</div>
<div class="body">

Y ahora un cuestionario de autoevaluación:

❓ [Cuestionario - TAD Diccionario mediante ABBs](quizzes/sem09_1.md)

</div>
</div>

## 9.3. Recorridos iterativos e iteradores sobre árboles binarios

Detenemos un poco nuestro estudio de los diccionarios para volver a un aspecto de los recorridos en un árbol binario que tenemos pendiente. Vamos a centrarnos en los recorridos en inorden de un árbol binario. Hasta ahora teníamos una implementación recursiva bastante concisa:

```cpp
void inorder(const NodePointer &node) {
  if (node != nullptr) {
    inorder(node->left, func);
    visitar node->elem;
    inorder(node->right, func);
  }
}
```

El objetivo de esta sección es obtener una **implementación equivalente, pero que no utilice recursión**. Es decir, una implementación que recorra el árbol mediante un bucle.

¿Para qué queremos una implementación iterativa? Si recordáis, cuando estudiábamos el TAD Lista habíamos estudiado los iteradores, que nos permiten recorrer una lista o cualquier otro TAD secuencial. Sería útil poder utilizar iteradores también para recorrer conjuntos o diccionarios. El recorrido que haría el iterador sería similar al recorrido en inorden del árbol correspondiente. Sin embargo, no es fácil implementar las funcionalidades de los iteradores a partir de una implementación recursiva como la anterior. Es más fácil inspirarse en una implementación iterativa. Al fin y al cabo, el recorrido de un iterador es como un bucle, donde cada operación de avanzar el iterador es similar a una iteración de ese bucle.

Por desgracia, recorrer un árbol binario de manera iterativa es bastante más complicado que recorrer una lista. ¿Por qué?. Cada vez que recorríamos una lista, teníamos un puntero al "nodo actual". Pasar al siguiente nodo era relativamente fácil; cada nodo tiene un puntero al siguiente elemento en el recorrido. Pero ahora tenemos árboles, que no son tan "lineales". Supongamos que estamos situados en un nodo determinado, y que ahora queremos pasar al siguiente del recorrido en inorden. ¿Dónde está el nodo siguiente? ¿Es uno de los hijos? ¿Es su padre?. Depende.

<div class="exercise">
<div class="title">
📝 Ejercicio 9.3
</div>
<div class="body">

En el siguiente ejercicio vamos a estudiar los distintos casos que pueden surgir a la hora de recorrer un árbol:

❓ [Ejercicio - ¿Cuál es el siguiente nodo?](quizzes/sem09_2.md)

</div>
</div>

Con esta información, ahora vamos a ver cómo implementar un recorrido en inorden en un árbol binario de manera iterativa. Para ello vamos a necesitar una pila auxiliar.

▶️ [Recorrido en inorden iterativo (1)](https://youtu.be/vlDh2Q6ZCHs) (10:01)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/blob/main/arboles/bintree_v6/bintree.h)

Para los propósitos de este curso, basta con conocer el algoritmo de recorrido iterativo. No obstante, resulta legítimo preguntarse cómo se ha llegado a ese algoritmo, y si realmente el algoritmo equivale a hacer un recorrido en inorden. Pues bien, es posible derivar este algoritmo iterativo partiendo de su versión recursiva y utilizando una serie de transformaciones elementales. Este mecanismo, además, puede ser aplicado a una gran clase de funciones en las que se hagan dos llamadas recursivas. El siguiente vídeo explica, paso a paso, cómo se transforma la versión recursiva del recorrido en inorden en una versión iterativa:

▶️ [Recorrido en inorden iterativo (2)](https://youtu.be/Ux3aC97AiOA) (Opcional - 16:22)

Pues bien, ya tenemos un algoritmo iterativo de recorrido en inorden. El último paso consiste en implementar las operaciones de los iteradores para recorrer árboles binarios:

▶️ [Iteradores en árboles binarios](https://youtu.be/RwERdx2hDxE) (5:26)

📄 [Código fuente (TAD Árbol Binario)](https://github.com/manuelmontenegro/ED/blob/main/arboles/bintree_v7/bintree.h)

📄 [Código fuente (TAD Conjunto)](https://github.com/manuelmontenegro/ED/blob/main/arboles/set_tree_v3/set_tree.h)

📄 [Código fuente (TAD Diccionario)](https://github.com/manuelmontenegro/ED/blob/main/diccionarios/map_tree_v3/map_tree.h)


<div class="exercise">
<div class="title">
📝 Ejercicio 9.4
</div>
<div class="body">

Ahora viene un ejercicio muy sencillo con iteradores. Dado un conjunto de la clase `SetTree`, se trata de obtener la suma de los elementos del conjunto.

💻 [Ejercicio: sumar los elementos de un conjunto](https://godbolt.org/z/85TT98zjW)

💻 [Solución](https://godbolt.org/z/qe4cGrMPh)

</div>
</div>

<div class="exercise">
<div class="title">
📝 Ejercicio 9.5
</div>
<div class="body">

Finalizamos nuestros recorridos iterativos con un cuestionario:

❓ [Cuestionario - Recorrido en inorden iterativo](quizzes/sem09_3.md)

</div>
</div>

## 9.4. Problemas de laboratorio

<div class="exercise">
<div class="title">
📝 Ejercicio 9.6
</div>
<div class="body">

💻 [Tree sort (con solución)](assignments/L09-1.pdf)

</div>
</div>

<div class="exercise">
<div class="title">
📝 Ejercicio 9.7
</div>
<div class="body">

💻 [Compresión RLE](assignments/L09-2.pdf)

</div>
</div>

<div class="exercise">
<div class="title">
📝 Ejercicio 9.8
</div>
<div class="body">

💻 [Evaluando expresiones aritméticas](assignments/L09-3.pdf)

</div>
</div>
