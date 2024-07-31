# Semana 5 - Iteradores

<div class="aims">
<div class="aims_header">
✔️ Objetivos
</div>

* Identificar los casos de uso de un iterador.

* Conocer la implementación de los iteradores en las distintas implementaciones del TAD Lista.

* Conocer la noción de iterador como abstracción de puntero.

* Aplicar las clases de la STL para realizar problemas concretos.
    
<div class="aims_header">
✔️ Tiempo de estudio
</div>

* **Vídeos**: 48min (+3 min opcional)

* **Total** *(incluyendo vídeos, cuestionarios y actividades de autoevaluación)*: 2h

</div>

## 5.1. Motivación. ¿Para qué sirven los iteradores?

Los iteradores son unos Tipos Abstractos de Datos muy utilizados para recorrer listas. Permiten a un programador moverse secuencialmente por los elementos de una lista, independientemente de si la lista está implementada mediante un vector o mediante una lista enlazada.


<div class="exercise">
<div class="title">
📝 Ejercicio 5.1
</div>
<div class="body">

Para entender mejor la utilidad de los iteradores, comienza por el siguiente cuestionario:

❓ [Cuestionario de autoevaluación - ¿Para qué sirve un iterador?](quizzes/sem05_1.md)

</div>
</div>

Ahora veamos para qué sirve el TAD Iterador y cuáles son las operaciones que soporta.

▶️ [Introducción a los iteradores](https://youtu.be/W2BlFbgP6Ys) (9:41) 

## 5.2. Iteradores en listas enlazadas

La primera implementación de iteradores que veremos será en el contexto de la clase `ListLinkedDouble`. En este caso, un iterador contiene un puntero al nodo que está siendo señalado actualmente por el iterador.

▶️ [Iteradores y listas enlazadas](https://youtu.be/NkLadw80I4E) (5:30)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/blob/main/lineales/list_linked_double_v6/list_linked_double.h)

Vamos a hacer un pequeño inciso sobre un aspecto de C++ que no está cubierto en los vídeos. Observa el constructor de la clase `iterator` en el código fuente de `ListLinkedDouble`. ¡Es un constructor privado!. En primer lugar, ¿por qué es privado?. En segundo lugar, ¿cómo creo instancias de `iterator` si su constructor es privado?. Respondemos a estas preguntas a continuación: 

* **¿Por qué es privado?** Por dos motivos. El primero es porque queremos que un/a
   usuario/a de la clase `ListLinkedDouble` solamente pueda obtener iteradores
   llamando a los métodos `begin` y `end`. El segundo motivo se debe a que el
   cliente de la clase `ListLinkedDouble` no tiene acceso al tipo `Node`, ya que
   su definición también es privada (y así debe seguir siéndolo). Por
   tanto, ¿cómo podría un/a programador/a crear un iterador directamente, si
   no tiene ningún puntero a `Node` con el que llamar a su constructor? Y si,
   aun así, tuviese acceso al tipo `Node` ¿qué garantiza que el/la
   programador/a vaya a crear un iterador de manera correcta?. Por estos
   motivos, es mejor encapsular la creación de iteradores exclusivamente
   mediante el uso de los métodos `begin` y `end`. 

* **¿Cómo creo instancias de `iterator`?** En general, no es posible acceder a
     los métodos y atributos privados de una clase desde fuera de ella, pero
     hemos hecho un pequeño «truco». La clave está en la siguiente
     [declaración](https://github.com/manuelmontenegro/ED/blob/9e5fe90e3799eb72228222869c6fd98d618f1af7/lineales/list_linked_double_v6/list_linked_double.h#L140) dentro de la clase `iterator`: 

     ```cpp
     friend class ListLinkedDouble;
     ```

     Con esto estamos diciendo que la clase `ListLinkedDouble` es *amiga* de
     `iterator`. Esto significa que la clase `ListLinkedDouble` puede acceder
     a los atributos y métodos privados de la clase `iterator`. Por este
     motivo, en los métodos `begin` y `end` hemos podido llamar a los
     constructores de `iterator`, aunque sean privados. En general, C++ nos
     permite declarar clases y funciones amigas de una determinada clase `A`.
     Estas clases y funciones podrán acceder, en su código, a los atributos y
     métodos privados de `A`. Fíjate en que la declaración `friend` debe
     estar *dentro* de la definición de la clase `A`. Con esto nos aseguramos
     de que la persona que ha creado la clase `A` indica expresamente quiénes
     son las amigas de la clase. 

<div class="exercise">
<div class="title">
📝 Ejercicio 5.2
</div>
<div class="body">

 Los iteradores nos permiten hacer referencia a posiciones arbitrarias dentro de una lista. 

* ¿Puedes escribir un método dentro de `ListLinkedDouble` que inserte un elemento antes de la posición indicada por un iterador?

* ¿Puedes escribir un método que elimine el elemento señalado por un iterador?


💻 [Ejercicio: inserción y eliminación de elementos en una lista](https://godbolt.org/z/Mzxs4vdTb)

</div>
</div>

En el siguiente vídeo se explica la solución. Ten en cuenta que las implementaciones que se detallan allí no solo realizan la inserción/borrado correspondientes, sino que también devuelven otro iterador. Es importante saber por qué.

▶️ [Inserción y borrado con iteradores](https://youtu.be/GOMNAzVbCZk) (3:16)

De este vídeo se extrae un importante resultado: 

<div class="warning">

**Aviso**

Las operaciones que insertan o eliminan elementos de una lista pueden afectar, o incluso **invalidar**, los iteradores que actualmente existan sobre esa lista.

</div>

 Uno de los principales errores del principiante es, precisamente, el acceso a iteradores invalidados. Cuando veamos la STL más adelante, veremos cómo saber qué operaciones sobre listas alteran o invalidan a los iteradores existentes. 

 <div class="exercise">
<div class="title">
📝 Ejercicio 5.3
</div>
<div class="body">

En el siguiente cuestionario podrás practicar todo lo visto hasta ahora:

❓ [Cuestionario de autoevaluación - Iteradores sobre listas](quizzes/sem05_2.md)

</div>
</div>

En el siguiente vídeo vamos a ver la relación que existe entre los iteradores y el modificador `const`. A partir del minuto 4:20 se explican unos detalles de implementación. Si te pierdes en esos detalles, no te preocupes; no es esencial para la asignatura.

▶️ [Iteradores constantes](https://youtu.be/-TE-3-3DEWk) (5:59)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/blob/main/lineales/list_linked_double_v7/list_linked_double.h)

Ahora viene una parte bonita, conocida como el *azúcar sintáctico*. En el siguiente vídeo vamos a renombrar los métodos `advance` y `elem` que hemos definido hasta ahora, con el objetivo de acercar la sintaxis que estamos utilizando a la sintaxis de los punteros de C++. También aprovechamos para presentar el especificador `auto` y la sintaxis de los bucles `for` que hacen uso de iterador.

▶️ [Adaptando la sintaxis de los iteradores](https://youtu.be/Prx6lK-C1Mg) (7:13)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/blob/main/lineales/list_linked_double_v8/list_linked_double.h)


## 5.3. Iteradores en arrays

De nuevo, seguimos en el TAD Lista, pero ahora en su implementación mediante vectores. Gracias a la sintaxis que hemos empleado en el último vídeo (el operador `*` en lugar del método `elem` y el operador `++` en lugar del método `advance`), la incorporación de iteradores a esta implementación es extremadamente simple.

Ojo a la parte final del video, que explica por qué los iteradores son una generalización de los punteros.

▶️ [Iteradores en ListArray](https://youtu.be/vrNJ-575-g4) (4:01)

El concepto de iterador es omnipresente en el lenguaje C++. Hemos visto que existen iteradores para *strings*. En la sección siguiente veremos que también existen iteradores para flujos de salida (`ofstream` y compañía). De momento, vamos a practicar un poco los iteradores sobre cadenas con un par de ejercicios:

<div class="exercise">
<div class="title">
📝 Ejercicio 5.4 - Pasar una cadena a mayúsculas
</div>
<div class="body">

La función `toupper`, definida en el fichero de cabecera `<cctype>`, recibe un carácter y devuelve su carácter equivalente en mayúsculas. Utilizando iteradores sobre cadenas, extiende esta función para que transforme todos los caracteres de una cadena a mayúsculas:

💻 [Ejercicio - Pasar una cadena a letras mayúsculas](https://godbolt.org/z/jGT4GYYe8)

💻 [Solución](https://godbolt.org/z/v4eEj6ajb)

</div>
</div>


<div class="exercise">
<div class="title">
📝 Ejercicio 5.5 - Cadenas «cochanbrosas»
</div>
<div class="body">

Decimos que una cadena es *cochanbrosa* (sic) si contiene una letra `n` antes de una letra `p`, o antes de una letra `b`. Por ejemplo: `"Inbécil"`, `"Colonbia"`. Escribe una función que determine si una cadena es cochanbrosa. Para ello utiliza dos iteradores que recorran simultáneamente la lista.

💻 [Ejercicio - Cadenas cochanbrosas](https://godbolt.org/z/aszbYGG1d)

💻 [Solución](https://godbolt.org/z/7Yzc845v1)

</div>
</div>

## 5.4. Introducción a la STL

El acrónimo STL proviene de Standard Template Library. La STL forma parte de la librería estándar de C++ y consiste, básicamente, en un conjunto de clases que implementan los Tipos Abstractos de Datos que hemos visto este curso, y algunos TADs más que nos quedan por ver. Además de eso, la STL implementa una gran cantidad de algoritmos que trabajan sobre estos TADs: ordenación, búsqueda, etc.

En efecto, todo lo que hemos visto sobre los TADs Lista, Pila, Cola y Doble Cola ya está implementado. También todo lo relacionado con los iteradores. A partir de ahora os voy a pedir que utilicéis las clases de la STL para realizar los problemas que requieran el uso de estos TADs, en lugar de las implementaciones que os he ido proporcionando estas semanas. Pero ¡ojo!, si en algún ejercicio os pido añadir alguna operación que requiera acceso a la representación interna de los TADs, entonces sí que debéis utilizar las implementaciones que hemos ido desarrollando en los vídeos de estas semanas.

Aunque la interfaz de los TADs de la STL es siempre es la misma, las implementaciones concretas dependen del compilador que utilicéis, y además suelen ser bastante crípticas debido al gran número de optimizaciones y características avanzadas de C++ de las que hacen uso.

Pero entonces, si todo esto está ya implementado, ¿por qué hemos estado perdiendo el tiempo implementándolo nosotros/as?. En realidad, no hemos estado perdiendo el tiempo. Uno de los objetivos de este curso es conocer la implementación interna de estos TADs para poder tener una decisión informada sobre qué implementación nos conviene para según qué propósito.

Dicho todo esto, vamos a iniciar nuestro estudio de los TADs de la STL, pero antes te voy a dar la oportunidad de que la explores tú mismo/a.

<div class="exercise">
<div class="title">
📝 Ejercicio 5.6
</div>
<div class="body">

Accede al siguiente enlace:

🌎 [Librería de contenedores](https://en.cppreference.com/w/cpp/container)

Investiga un poco las clases que están bajo el apartado *Sequence containers* y *Container adaptors*. A continuación, resuelve el siguiente cuestionario:

❓ [TADs lineales en la STL - Cuestionario previo](quizzes/sem05_3.md)

</div>
</div>

Ahora sí, los vídeos:

▶️ [C++ - Contenedores lineales en la STL](https://youtu.be/p0lGTTcN7PE) (3:06)

▶️ [C++ - Iteradores en la STL](https://youtu.be/jyO3QMIavrI) (3:46)

▶️ [C++ - Algoritmos en la STL (1)](https://youtu.be/RRh-JFxMl2c) (4:58) 

<div class="exercise">
<div class="title">
📝 Ejercicio 5.7
</div>
<div class="body">

Aquí tienes un ejemplo para que puedas ir practicando con los algoritmos de la STL:

💻 [Ejercicio: algoritmos de la STL](https://godbolt.org/z/YfoPrx3d8)

💻 [Solución](https://godbolt.org/z/xK4TfPvGM)

</div>
</div>

Queda comentar un último aspecto de la STL que es importantísimo tener en cuenta a la hora de trabajar con los iteradores. De nuevo, accede a la siguiente página:

🌎 [Librería de contenedores](https://en.cppreference.com/w/cpp/container)

Observa la sección *Iterator invalidation*. La tabla nos dice qué iteradores se invalidan a la hora de hacer una modificación sobre un determinado TAD. Debes recordar lo siguiente:


* Tras hacer una inserción en un objeto de la clase `list`, los iteradores que hubiese sobre esa lista **siguen siendo válidos**. Si se realiza un borrado, también siguen siendo válidos **excepto si apuntan al elemento borrado**.

* Tras hacer una inserción en un objeto de la clase `vector`, si el array se redimensiona, todos los iteradores quedan invalidados. Si no se redimensiona, solo los iteradores que apunten antes del elemento insertado se mantienen válidos; los que apuntan después del elemento insertado quedan invalidados. Lo mismo se aplica a los borrados. Para un/a usuario/a de la clase `vector` resulta difícil predecir de antemano cuándo se produce un redimensionado del array, por lo que normalmente hay que suponer que, cuando se realiza una inserción o borrado en un `vector`, **todos los iteradores se invalidan**.

<div class="exercise">
<div class="title">
📝 Ejercicio 5.8
</div>
<div class="body">

Finalizamos nuestro viaje por la STL con un cuestionario: 

❓ [Cuestionario de autoevaluación - STL (1)](quizzes/sem05_4.md)

</div>
</div>

## 5.5. TADs en la librería estándar de Java (Opcional)

Aunque este curso está centrado en C++, seguramente utilizas Java en otras asignaturas. Te dejo un breve vídeo con las clases que necesitas conocer para utilizar los TADs vistos hasta ahora en Java.

▶️ [Java - TADs Lineales](https://youtu.be/OtaCEwlZb_U) (Opcional) (3:02)

## 5.6. Problemas de laboratorio

<div class="exercise">
<div class="title">
📝 Ejercicio 5.9
</div>
<div class="body">

💻 [Matriz de Toeplitz](assignments/L05-1.pdf)

</div>
</div>

<div class="exercise">
<div class="title">
📝 Ejercicio 5.10
</div>
<div class="body">

💻 [De postre, un chuletón](assignments/L05-2.pdf)

</div>
</div>

<div class="exercise">
<div class="title">
📝 Ejercicio 5.11
</div>
<div class="body">

💻 [Suavizar una lista de números enteros](assignments/L05-3.pdf)

</div>
</div>