# Semana 2 - TAD Lista. Vectores y listas enlazadas simples

<div class="aims">
<div class="aims_header">
✔️ Objetivos
</div>

* Distinguir entre las dos regiones de memoria más importantes en C++: pila y *heap*.

* Conocer las operaciones básicas del TAD Lista.

* Saber implementar un TAD Lista mediante vectores redimensionables y mediante listas enlazadas simples.

* Poder extender las operaciones soportadas por un TAD Lista en cualquiera de las dos implementaciones mencionadas.

* Identificar los casos en los que es necesario escribir un constructor de copia en C++.
    
<div class="aims_header">
✔️ Tiempo de estudio
</div>

* **Vídeos**: 1h 13min

* **Total** *(incluyendo vídeos, cuestionarios y actividades de autoevaluación)*: 2h 30min

</div>

## 2.1. Gestión de memoria dinámica en C++


Esta primera sección es importante. Muy importante. Gran parte de los problemas que aparecen cuando programamos en cualquier lenguaje provienen de la compartición entre las distintas estructuras de datos. Si no somos conscientes de esta compartición, los cambios en una estructura de datos podrían afectar a otras estructuras de manera inadvertida para el/la programador/a. Este problema es especialmente llamativo en C++, donde, al contrario que en Java o Python, somos responsables de liberar la memoria que creamos. Si lo hacemos de manera incorrecta, el programa podría provocar un error en tiempo de ejecución y abortar.

En el primer vídeo se introducen las principales regiones de memoria que entran en juego en ejecución: pila y *heap*. El vídeo es largo, pero es muy importante entenderlo. Ten paciencia y no te lo saltes:

▶️ ️[C++ - Objetos y memoria dinámica](https://youtu.be/grWqwqvIrIo) (16:54)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/tree/main/cpp/04_stack_heap)

<div class="exercise">
<div class="title">
📝 Ejercicio 2.1
</div>
<div class="body">

Vamos a poner a prueba los conceptos vistos en el vídeo anterior.  

❓ [Cuestionario de autoevaluación - Objetos y memoria dinámica](quizzes/sem02_1.md)

</div>
</div>

Cuando tenemos objetos que apuntan a otros dentro del heap, puede ser difícil liberar de manera ordenada toda la maraña de objetos. Los destructores de C++ nos facilitan esta tarea:

▶️ ️[C++ - Destructores](https://youtu.be/bb6Pa-72wEg) (5:47)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/tree/main/cpp/05_destructores)

<div class="exercise">
<div class="title">
📝 Ejercicio 2.2
</div>
<div class="body">

Vamos a poner a prueba los conceptos vistos en el vídeo anterior.  

❓ [Cuestionario de autoevaluación - Destructores](quizzes/sem02_2.md)

</div>
</div>


## 2.2. TAD Lista y su implementación mediante vectores

A continuación os presento uno de los tipos de datos más utilizados en la mayoría de lenguajes de programación: las **listas**.

Comencemos viendo qué es una lista, y qué operaciones soporta:

▶️ [El TAD Lista](https://youtu.be/xjt7ICIwrbk)  (6:10)

Ya sabemos las operaciones que ha de soportar este TAD. Ahora nos toca implementarlo. ¿Cómo lo hacemos?. Existen varias maneras:

1. Utilizando un array unidimensional (es decir, un vector) para almacenar elementos.
2. Utilizando una lista enlazada simple.
3. Utilizando una lista doblemente enlazada.
4. Utilizando una lista doblemente enlazada circular.

La primera de estas maneras se explica en esta misma sección. La segunda se explica en la sección siguiente, y las dos restantes se estudiarán la semana que viene.

La implementación de una lista mediante un array parece una tarea sencilla, pero cuidado: los arrays tienen una longitud fija, por lo que tendremos que tratar de modo especial el caso en que queramos añadir un elemento a la lista (operaciones `push_back` y `push_front`), y el array esté "completo". Para ello necesitamos un array que se redimensione a medida que se vaya quedando sin espacio libre.

▶️ [Implementación del TAD Lista mediante arrays](https://youtu.be/fH07NP2dd-E) (9:38)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/tree/main/lineales/list_array_v1)

<div class="exercise">
<div class="title">
📝 Ejercicio 2.3
</div>
<div class="body">

Hasta ahora podemos añadir elementos y eliminar elementos de la lista. Una operación que nos puede interesar es la de *actualizar* un elemento de la lista. Es decir, reemplazar un elemento de la lista por otro. En el siguiente enlace tienes la implementación de listas que tenemos hasta ahora.

💻 [Añadir método update](https://godbolt.org/z/bvKPEY6bj)

💻 [Solución](https://godbolt.org/z/rKxPTEP8Y)

Añade el siguiente método a la clase `ListArray`:

 ```cpp
 void update(int indice, const std::string &elem);
 ```

 Este método ha de reemplazar el elemento de la posición `indice` de la lista por el elemento `elem` pasado como parámetro.
</div>
</div>

Aunque un método `update` como el del ejercicio anterior podría ser útil en un TAD Lista (de hecho, las listas de la biblioteca estándar Java lo implementan), en C++ se utiliza otro enfoque distinto. Para actualizar elementos se hace uso de las *referencias*, que ya conocéis como mecanismo de paso de parámetros en C++. Se explica en el siguiente vídeo.

▶️ [Modificación de listas mediante referencias](https://youtu.be/FnetQzRu25E) (9:43)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/tree/main/lineales/list_array_v2)

<div class="exercise">
<div class="title">
📝 Ejercicio 2.4
</div>
<div class="body">

En el siguiente programa podrás poner en práctica las referencias. Echa un vistazo al método `main` y sigue las instrucciones que aparecen allí.

💻 [Prácticas con referencias](https://godbolt.org/z/njrh8j1er)

💻 [Solución](https://godbolt.org/z/7vaa4cfYx)

</div>
</div>


## 2.3. TAD Lista y su implementación mediante listas enlazadas simples

A continuación viene una de las implementaciones más importantes del TAD Lista: la implementación mediante listas enlazadas. Ojo a esta versión, porque vamos a ir profundizando en ella a lo largo de las siguientes semanas.


▶️ [Implementación del TAD Lista mediante listas enlazadas](https://youtu.be/Rk_kt1uIm3c) (13:09)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/tree/main/lineales/list_linked_single_v1)


<div class="exercise">
<div class="title">
📝 Ejercicio 2.5
</div>
<div class="body">

Ahora que conoces dos implementaciones del TAD Lista, vamos a comparar los costes de sus operaciones: 

❓ [Cuestionario de autoevaluación - Coste de operaciones en el TAD lista](quizzes/sem02_3.md)

</div>
</div>

<div class="info">
<div class="title">
ℹ️  Sobre el invariante de representación (opcional)
</div>
<div class="body">

En el vídeo anterior (minuto 3:55) no soy demasiado preciso en lo que respecta al invariante de representación. Es cierto que este invariante no impone ninguna restricción sobre el atributo `head`, pero también hay que tener en cuenta la información de los nodos. En particular, los atributos `next` de los nodos definen la "forma" de la lista enlazada, y están sujetos a una serie de restricciones:

1. Si un nodo `x` pertenece a la lista, el nodo `x->next` ha de ser `nullptr` o apuntar a un nodo que también debe pertenecer a la lista enlazada.

2. Si partimos del nodo `head` y seguimos la cadena de nodos `next`, en algún momento debemos llegar a `nullptr`. Es decir, la secuencia de punteros `next` no puede formar ningún ciclo.

3. Un nodo pertenece a una única lista. Es decir, no se puede tener dos instancias de `ListLinkedSingle` tales que, si seguimos la cadena de nodos desde sus respectivos punteros `head`, ambas confluyen en un nodo común.

Estas tres restricciones no se pueden expresar mediante una fórmula lógica simple. Dado que la verificación formal no es uno de los objetivos principales del curso, decidí no mencionar estas tres restricciones en el vídeo, pero deben satisfacerse en todo caso.

La segunda restricción podría expresarse fácilmente con ayuda de un predicado auxiliar recursivo. Sin embargo, para expresar las restricciones 1 y 3 necesitamos un concepto adicional, que es el *footprint* de un TAD. Si te interesa el área de la verificación formal de programas, puedes consultar las siguientes referencias:

- R. Leino. [Specification and Verification of Object-Oriented Software](https://www.microsoft.com/en-us/research/uploads/prod/2008/12/Dafny_krml190.pdf).
- J. Blázquez, M. Montenegro, C. Segura. [Verification of mutable linear data structures and iterator-based algorithms in Dafny](https://www.sciencedirect.com/science/article/pii/S2352220823000299?via%3Dihub)

</div>
</div>

## 2.4. El constructor de copia en C++

Descansamos un poco del mundo de los TADs para ver una característica de C++ que no se encuentra en otros lenguajes orientados a objetos. C++ nos permite personalizar la forma en la que se inicializa un objeto a partir de otro. Para ello tenemos que implementar el constructor de copia:



▶️ [C++ - Constructores de copia](https://youtu.be/5SKWoMnKF30) (8:39)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/tree/main/cpp/06_constructor_copia)


<div class="exercise">
<div class="title">
📝 Ejercicio 2.6
</div>
<div class="body">

Las implementaciones del TAD Lista que hemos visto hasta ahora piden a gritos un constructor de copia, para evitar compartición no deseada. Es tu turno: ¿puedes implementarlo en ambas?

💻 [Añadir constructor de copia a implementación mediante arrays](https://godbolt.org/z/oWq4oGsbb)

💻 [Añadir constructor de copia a implementación mediante listas enlazadas](https://godbolt.org/z/Pb6x7ffco)
</div>
</div>


En el siguiente vídeo se muestra una posible forma de implementar el constructor de copia para los TAD vistos hasta ahora:



▶️ [Constructores de copia en el TAD Lista](https://youtu.be/cbmjmZM4-Rg) (3:04)

📄 [Código fuente (implementación mediante vectores)](https://github.com/manuelmontenegro/ED/tree/main/lineales/list_array_v3)

📄 [Código fuente (implementación mediante listas enlazadas)](https://github.com/manuelmontenegro/ED/tree/main/lineales/list_linked_single_v2)

<div class="info">
<div class="title">
ℹ️  Información adicional sobre Java (opcional)
</div>
<div class="body">

En Java existe el constructor de copia como tal, pero es tratado como un constructor cualquiera. Por ejemplo, supongamos la siguiente clase:

```java
class MiClase { ... }
```    

Si asignamos un objeto `c1` a un objeto `c2`,

```java
MiClase c1 = new MiClase();
MiClase c2 = c1;
```    
en realidad estamos haciendo que `c2` apunte al mismo objeto que `c1`. Es decir, en Java no se llama a ningún constructor de copia.

Es posible implementar un constructor de copia en Java, declarándolo como un constructor que recibe otra instancia de `MiClase`.

```java
class MiClase {
    public MiClase() {/* constructor por defecto */}
    public MiClase(MiClase other) {/* constructor de copia */}
    // ...
}
```        
En este caso, tendríamos que llamar al constructor explícitamente para hacer uso de él

```java
MiClase c1 = new MiClase();
MiClase c2 = new MiClase(c1);  // Llama al constructor de copia
```    

Una alternativa al constructor de copia en Java es la clase [`Cloneable`](https://docs.oracle.com/en/java/javase/17/docs/api/java.base/java/lang/Cloneable.html) y el método [`clone()`](https://docs.oracle.com/en/java/javase/17/docs/api/java.base/java/lang/Object.html#clone()) de la clase 
`Object`. 

</div>
</div>


## 2.5. Problemas de laboratorio

<div class="exercise">
<div class="title">
📝 Ejercicio 2.7
</div>
<div class="body">

💻 [Repetir los elementos de una lista](assignments/L02-1.pdf)

</div>
</div>

<div class="exercise">
<div class="title">
📝 Ejercicio 2.8
</div>
<div class="body">

💻 [Escamochar una lista](assignments/L02-2.pdf)

</div>
</div>

