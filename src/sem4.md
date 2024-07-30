# Semana 4 - Pilas, colas y colas dobles

<div class="aims">
<div class="aims_header">
✔️ Objetivos
</div>

* Conocer las operaciones soportadas por los TADs Pila, Cola y Cola doble, y sus posibles implementaciones.

* Aplicar estos tipos abstractos de datos a problemas concretos.

* Utilizar plantillas de C++ para implementar estructuras de datos y tipos abstractos de datos genéricos.
    
<div class="aims_header">
✔️ Tiempo de estudio
</div>

* **Vídeos**: 40min

* **Total** *(incluyendo vídeos, cuestionarios y actividades de autoevaluación)*: 2h 30min

</div>

## 4.1. Introducción a las plantillas de C++ (templates)

 Hasta ahora hemos estudiado uno de los TADs más utilizados en programación, que es el TAD de las listas. Sabemos que una lista es una secuencia de elementos, pero ¿de qué tipo son esos elementos?. En los vídeos de las semanas anteriores hemos utilizado el tipo `string` para los elementos de la lista, pero por otro lado, en algunos de los problemas que hemos hecho las listas tenían elementos de tipo `int`.

Resulta fácil obtener una implementación de listas de enteros a partir de la implementación de listas de `string`. Basta con sustituir `string` por `int`, y listo. No obstante, cuando uno programa «en el mundo real», resulta engorroso tener que implementar varias versiones de las listas, una para cada tipo de datos que vayamos a utilizar. Y esto no solo implica la incomodidad de copiar/pegar/sustituir. Si más adelante queremos extender la implementación del TAD Lista con nuevas operaciones, tendremos que realizar los cambios en todas las versiones que hayamos derivado, una para cada tipo.

Puede que en la asignatura de *Tecnología de la Programación* hayáis estudiado (o lo estéis haciendo) la solución a esto: *Generics*. Java permite definir clases y funciones genéricas, que pueden ser utilizadas con distintos tipos de datos. Pues bien, resulta que en C++ también es posible disponer de este tipo de genericidad. El mecanismo es parecido, pero tiene un nombre distinto: plantillas o *templates*:

▶️ [C++ - Plantillas en funciones](https://youtu.be/ddSVhI_3jqo) (6:35)

▶️ [C++ - Plantillas en clases](https://youtu.be/1lGpvvB1Sxw) (3:27)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/tree/main/cpp/09_plantillas)

A partir de ahora ya somos mayores, y **todas las colecciones que implementemos a partir de ahora serán genéricas**. Es decir, podrán almacenar datos de cualquier tipo.


<div class="exercise">
<div class="title">
📝 Ejercicio 4.1
</div>
<div class="body">

 Vamos a aplicar las plantillas a los tipos de datos que ya hemos implementado. Por ejemplo, volvamos a las listas doblemente enlazadas circulares. En el siguiente enlace puedes acceder a la implementación tal y como quedó la semana pasada. La clase `ListLinkedDouble` almacenaba listas cuyos elementos son de tipo `string`. ¿Puedes modificarla para que ahora pueda almacenar elementos de cualquier tipo `T`?

💻 [Ejercicio: clase ListLinkedDouble genérica](https://godbolt.org/z/of47sqjfE)

💻 [Solución](https://github.com/manuelmontenegro/ED/blob/main/lineales/list_linked_double_v5/list_linked_double.h)

</div>
</div>

Los siguientes enlaces contienen la solución para cada una de las tres implementaciones del TAD lista que hemos visto: listas mediante vectores, listas enlazadas simples, y listas doblemente enlazadas circulares.

📄 [Código fuente - Implementación mediante vectores](https://github.com/manuelmontenegro/ED/blob/main/lineales/list_array_v5/list_array.h)

📄 [Código fuente - Implementación mediante listas enlazadas simples](https://github.com/manuelmontenegro/ED/blob/main/lineales/list_linked_single_v5/list_linked_single.h)

📄 [Código fuente - Implementación mediante listas doblemente enlazadas circulares](https://github.com/manuelmontenegro/ED/blob/main/lineales/list_linked_double_v5/list_linked_double.h)


<div class="exercise">
<div class="title">
📝 Ejercicio 4.2
</div>
<div class="body">

En el siguiente cuestionario podrás repasar lo visto sobre plantillas en C++:
 
❓ [Cuestionario de autoevaluación - Plantillas de C++](quizzes/sem04_1.md)

</div>
</div>


## 4.2. El tipo abstracto de datos Pila

A primera vista, el TAD que vamos a ver ahora parece algo limitado. De hecho, una de las primeras preguntas que se le viene uno a la cabeza cuando conoce las pilas es: *¿para qué sirve esto?*. Curiosamente, resulta que las pilas se aplican una gran cantidad de algoritmos. De hecho, las pilas se encuentran en el modelo de ejecución de los lenguajes de programación que soportan funciones recursivas (vamos, casi todos los lenguajes).

Comenzamos viendo qué es una pila, y qué operaciones soporta:

▶️ [El TAD Pila](https://youtu.be/8ImrgmCeI1w) (4:06)

Parece un TAD sencillo de implementar... y, de hecho, lo es. En el siguiente vídeo vamos a presentar dos implementaciones de este tipo de datos: mediante vectores y mediante listas enlazadas.

▶️ [Implementaciones del TAD Pila](https://youtu.be/ljBGW4dk_W8) (6:32)

📄 [Código fuente - Implementación mediante vectores](https://github.com/manuelmontenegro/ED/blob/main/lineales/stack_array/stack_array.h)

📄 [Código fuente - Implementación mediante listas enlazadas](https://github.com/manuelmontenegro/ED/blob/main/lineales/stack_linkedlist/stack_linkedlist.h)

<div class="exercise">
<div class="title">
📝 Ejercicio 4.3
</div>
<div class="body">

El siguiente cuestionario contiene algunas preguntas sobre las pilas y sus implementaciones:

❓ [Cuestionario de autoevaluación - Pilas](quizzes/sem04_2.md)

</div>
</div>

Por último, veamos un par de campos de aplicación de las pilas:

▶️ [Aplicaciones del TAD Pila](https://youtu.be/gyQ-pX9FFIw) (7:21)

<div class="exercise">
<div class="title">
📝 Ejercicio 4.4
</div>
<div class="body">

El último vídeo esboza la idea de un evaluador de expresiones aritméticas. ¿Eres capaz de implementarlo? En el siguiente enlace encontrarás una plantilla que puedes completar:

💻 [Ejercicio: evaluación de expresiones aritméticas en forma postfija](https://godbolt.org/z/nqeKGxdYP)

💻 [Solución](https://godbolt.org/z/sz13qsrjo)

</div>
</div>

Con respecto a la segunda aplicación que hemos presentado, estás más familiarizado/a con ella de lo que piensas. La pila de llamadas a funciones existe en todos los lenguajes, pero es más «visible» en los lenguajes interpretados, como Python, o aquellos que se ejecutan en una máquina virtual, como Java. Vamos a experimentar con la pila de llamadas a funciones en Java. Seguramente (y más de una vez, por desgracia) te ha salido un mensaje de error en Java debido a una excepción que se ha producido. Por ejemplo, en el siguiente enlace se muestra un programa que lanza un `NullPointerException`:

💻 [Excepciones en Java](https://onlinegdb.com/r1GcLw_7I)


Ejecútalo mediante el botón *Run*. Te debería aparecer un mensaje de error en la parte inferior que reza lo siguiente:

```
Exception in thread "main" java.lang.NullPointerException
        at Main.h(Main.java:13)
        at Main.g(Main.java:17)
        at Main.f(Main.java:21)
        at Main.main(Main.java:25)
```
El listado que aparece debajo del nombre de la excepción es, precisamente, un resumen de la pila de llamadas existente en el momento de producirse dicha excepción. Leyendo desde abajo hacia arriba, desde la línea 25 del método `main` se ha llamado a un método `f`, que a su vez ha llamado a un método `g`, que a su vez ha llamado a otro método `h`, que es el que ha producido la excepción (concretamente en su línea 13).

Por otro lado, ¿te suena el término *stack overflow*? Puede que lo conozcas por el famoso portal web de preguntas y respuestas, pero también es un término utilizado para referirse al desbordamiento de la pila de llamadas. Por ejemplo, accede al siguiente enlace donde podrás ver una definición recursiva típica de la función factorial:

💻 [Desbordamiento de pila en Java](https://onlinegdb.com/H1Nw_D_QU)

Ejecuta el programa y se imprimirá por pantalla el factorial de 10. Hasta ahí todo normal. Ahora cambia el método `main()` (utiliza antes el botón *Fork this*) cambiando la llamada `factorial(10)` por `factorial(-3)`. ¿Qué ha pasado? Se produce la cadena de llamadas `factorial(-3)` → `factorial(-4)` → `factorial(-5)` → ... y nunca se llega al caso base. La máquina virtual de Java reserva, al principio de programa, una cantidad de espacio determinada para la pila de llamadas. En caso de sobrepasarse esta cantidad (cosa que pasará, tarde o temprano, en el ejemplo anterior, al tener una secuencia infinita de llamadas recursivas) se produce un desbordamiento de pila (*stack overflow* en inglés), y la máquina virtual protesta lanzando un `StackOverflowError`.

## 4.3. El tipo abstracto de datos Cola

Pasamos al siguiente tipo abstracto de datos. También es bastante simple, pero ahí reside su utilidad:

▶️ [El TAD Cola](https://youtu.be/ZZuvAwznDQw) (2:52)

Al igual que las pilas, las colas admiten dos representaciones: mediante vectores y mediante listas enlazadas. No obstante, la representación mediante vectores es, en este caso, bastante curiosa...

▶️ [Implementación del TAD Cola](https://youtu.be/THbLVcvcmyY) (6:30)

📄 [Código fuente - Implementación mediante listas enlazadas](https://github.com/manuelmontenegro/ED/blob/main/lineales/queue_linkedlist/queue_linkedlist.h)

📄 [Código fuente - Implementación mediante vectores circulares](https://github.com/manuelmontenegro/ED/blob/main/lineales/queue_array/queue_array.h)

<div class="exercise">
<div class="title">
📝 Ejercicio 4.5
</div>
<div class="body">

Existe una tercera forma de implementar las colas. Consiste en utilizar dos pilas. ¿Te animas? Solamente puedes utilizar las operaciones de la interfaz pública de las pilas para implementar las operaciones de las colas.

💻 [Ejercicio: implementación de una cola mediante dos pilas](https://godbolt.org/z/nsze5sb8z)

💻 [Solución](https://godbolt.org/z/87ac1j8d7)

</div>
</div>

Además de las aplicaciones relacionadas con la implementación de los sistemas operativos, mencionadas en el vídeo [El TAD Cola](https://youtu.be/ZZuvAwznDQw), las colas se utilizan como estructuras auxiliares en varios algoritmos como, por ejemplo, el recorrido en anchura de un árbol, que veremos más adelante.

<div class="exercise">
<div class="title">
📝 Ejercicio 4.6
</div>
<div class="body">

En el siguiente cuestionario podrás poner en práctica los conceptos relativos a las colas:

❓ [Cuestionario de autoevaluación - Colas](quizzes/sem04_3.md)

</div>
</div>

## 4.4. El tipo abstracto de datos Cola Doble (deque)

Terminamos esta semana con otro tipo abstracto de datos que agrupa la funcionalidad de las pilas y las colas:

▶️ [Colas dobles (deques)](https://youtu.be/TrfLrDmTbIs) (2:11)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/blob/main/lineales/deque/dequeue.h)

La brevedad del vídeo se debe a que tanto la interfaz como la implementación de las colas dobles es muy similar a una de las implementaciones del TAD lista, que hemos visto durante la semana pasada. Una doble cola puede ser implementada mediante una lista doblemente enlazada circular con nodo fantasma.

<div class="exercise">
<div class="title">
📝 Ejercicio 4.7
</div>
<div class="body">

Último cuestionario de la semana. En este caso, preguntamos sobre las colas dobles:

❓ [Cuestionario - Colas dobles](quizzes/sem04_4.md)

</div>
</div>

## 4.5. Uso de los TADs vistos esta semana

¿Para qué sirven los tipos abstractos de datos que hemos visto esta semana? Al fin y al cabo, el TAD Lista, que ya conocíamos de antes, permite realizar lo mismo que las pilas, colas y colas dobles, y además soporta más operaciones. ¿Por qué no utilizamos una lista para todos los casos, y nos quitamos de complicaciones? Hay dos motivos:

* **Eficiencia**: En esta asignatura debéis ser capaces de seleccionar
    aquellas estructuras que permitan realizar las operaciones que necesitéis
    teniendo en cuenta (1) el tiempo de ejecución y (2) el espacio ocupado en
    memoria. Supongamos que para resolver un problema necesitamos una pila.
    Si escogemos una implementación del TAD pila basada en listas enlazadas
    simples, todas las operaciones tendrían coste constante. Si utilizamos
    una implementación del TAD lista basada en listas doblemente enlazadas
    circulares, también podríamos realizar las mismas operaciones en coste
    constante, pero a costa de tener más consumo en memoria (cada nodo
    almacena un puntero `prev` que no necesitamos).

* **Claridad**: Cuando un/a programador/a ve un tipo abstracto de datos
    concreto en un programa, se hace una idea preconcebida del uso que se va
    a hacer de él. Por ejemplo, cuando yo veo una variable de tipo
    `StackArray` o `StackLinkedList`, ya sé de antemano que va a almacenar
    una colección de elementos, y que se va a acceder a esos elementos
    siguiendo un orden LIFO (Last In, First Out). En cambio, si esta misma
    variable tuviese tipo `ListArray`, yo esperaría que en algún momento se
    insertasen elementos por el final, o que se hiciese un recorrido de sus
    elementos. Tardaría más tiempo en darme cuenta de que se está haciendo un
    uso LIFO de esa variable. 

    Resumiendo: El hecho no utilizar la estructura de datos más específica a
    tus necesidades puede provocar que otras personas tengan más dificultades
    para comprender tu código.

Los ejercicios que haremos durante esta semana irán destinados a que sepáis
identificar si necesitáis una pila, una cola, o una doble cola para resolver
un determinado problema. En el portal [Acepta el reto](https://www.aceptaelreto.com/) hay varios problemas
para los que se necesita alguno de estos TADs. A continuación enumero algunos
problemas de este tipo, para que puedas ir practicando:


* ACR 127: [Una, dola, tela, catola...](https://www.aceptaelreto.com/problem/statement.php?id=127)
* ACR 145: [El tren del amor](https://www.aceptaelreto.com/problem/statement.php?id=145)
* ACR 146: [Números afortunados](https://www.aceptaelreto.com/problem/statement.php?id=146)
* ACR 187: [Solitario](https://www.aceptaelreto.com/problem/statement.php?id=187)
* ACR 197: [Mensaje interceptado](https://www.aceptaelreto.com/problem/statement.php?id=197)


## 4.6. Problemas de laboratorio

<div class="exercise">
<div class="title">
📝 Ejercicio 4.8
</div>
<div class="body">

💻 [Facundo y el undo](assignments/L04-1.pdf)

</div>
</div>

<div class="exercise">
<div class="title">
📝 Ejercicio 4.9
</div>
<div class="body">

💻 [Link y el vuelo en paravela](assignments/L04-2.pdf)

</div>
</div>

