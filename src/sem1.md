# Semana 1 - Introducción a los tipos abstractos de datos

<div class="aims">
<div class="aims_header">
✔️ Objetivos
</div>

* Conocer la definición de Tipo Abstracto de Datos.

* Utilizar los mecanismos de encapsulación de C++ para la implementación de
  Tipos Abstractos de Datos.

* Conocer la terminología básica de TADs: modelo, representación, e invariantes.
    
<div class="aims_header">
✔️ Tiempo de estudio
</div>

* **Vídeos**: 1h 4min

* **Total** *(incluyendo vídeos, cuestionarios y actividades de autoevaluación)*: 2h 10min

</div>

En la última clase de teoría hemos hecho un ejercicio de planificación de horarios. Aquí tienes el ejercicio junto con las soluciones.

📝 [Planificación de horarios A (con solución)](sem1/HorasASol.pdf)

📝 [Planificación de horarios B (con solución)](sem1/HorasBSol.pdf)

Este ejercicio es similar al siguiente problema de Acepta el Reto: [ACR 278: El baile de Cenicienta](https://www.aceptaelreto.com/problem/statement.php?id=278).

## 1.1. Motivación

En el ejercicio de planificación de horarios, tenemos dos maneras de
representar las duraciones: (1) mediante un `struct` que almacene los
distintos campos de una duración por separado, y (2) mediante un único número
entero que denote una cantidad de segundos. Cada una de estas
representaciones tiene sus ventajas e inconvenientes, y no existe una opción
que sea mejor que la otra en todos los casos. No obstante, lo que sí
resultaría claramente perjudicial sería que tu código dependiese, en gran
medida, de la opción escogida. ¿Qué pasaría si, pasado un tiempo tras haber
escogido una representación, tienes que rectificar y escoger la otra?

En el primer video que se enlaza a continuación vamos a presentar un ejemplo parecido:

▶️ [Tipos Abstractos de Datos (TADs) - Motivación](https://youtu.be/VQtm5SucUkE) (8:32)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/blob/main/intro/juego_letras/juego.cpp)

<div class="exercise">
<div class="title">
📝 Ejercicio 1.1
</div>
<div class="body">

Antes de que en el siguiente video arreglemos nuestra implementación, puedes
acceder en el siguiente enlace a una sesión de *Compiler Explorer* con el
código que tenemos hasta ahora.

💻 [Implementación inicial del juego](https://godbolt.org/z/bTP5aY7TG)

¿Puedes arreglarlo tú mismo? El objetivo es que modifiques la función `main`, añadiendo las funciones auxiliares que necesites, para que puedas cambiar entre las dos implementaciones de `ConjuntoChar` sin tener que realizar cambios en la función `main` resultante.

¿No sabes utilizar *Compiler Explorer*? Aquí tienes un mini-manual: [Cómo usar Compiler Explorer]()

</div>
</div>

En el siguiente video veremos cómo se puede realizar esta encapsulación:

▶️ [Definición de TAD](https://youtu.be/EBWgkN5TMEg) (11:56)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/blob/main/intro/juego_letras_struct/ConjuntoCharArray.h) (versión que utiliza un array de elementos)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/blob/main/intro/juego_letras_struct/ConjuntoCharBool.h) (versión que utiliza un array de valores booleanos)

<div class="exercise">
<div class="title">
📝 Ejercicio 1.2
</div>
<div class="body">

En la siguiente sesión de *Compiler Explorer* se encuentra el nuevo método `main`.

💻 [Método main](https://godbolt.org/z/YWKnf99YM)

Observa que se hace un `#include` sobre la implementación que utiliza arrays
de caracteres (`ConjuntoCharArray.h`). Vamos a demostrar que esta
implementación es intercambiable con la que utiliza un array de booleanos
(`ConjuntoCharBool.h`). Para ello sustituye el `#include` anterior por uno que
haga referencia a este último fichero. El programa debería funcionar
perfectamente, ¡sin modificar una línea del método `main`!

</div>
</div>

## 1.2. Clases en C++

El último vídeo de la sección anterior nos deja un interrogante. ¿No sería
mejor que el compilador nos impidiese acceder a las representaciones internas
de los tipos de datos? Pues bien, esto es posible mediante **clases** en C++. A
continuación se presentan tres vídeos sobre esto. Los dos primeros presentan
conceptos que ya conocéis de la asignatura de *Tecnología de la Programación*: clases,
métodos, constructores, etc. Aun así, prestad atención porque la sintaxis
difiere bastante de lo que habéis visto en Java. El último vídeo introduce
los métodos constantes; una característica propia de C++ que no se encuentra
en Java.

▶️ [C++ - Atributos y métodos](https://youtu.be/04eOCSzVgeo) (8:04)

▶️ [C++ - Constructores y Listas de inicialización](https://youtu.be/iiehlbf9BAM) (11:14)

▶️ [C++ - Métodos const](https://youtu.be/WKd65gmwvSw) (7:42)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/tree/main/cpp)

<div class="exercise">
<div class="title">
📝 Ejercicio 1.3
</div>
<div class="body">
Mediante el siguiente cuestionario podrás practicar los conceptos vistos en los tres vídeos anteriores.


❓ [Cuestionario de autoevaluación - Clases en C++](quizzes/sem01_1.md)
</div>
</div>

<div class="exercise">
<div class="title">
📝 Ejercicio 1.4
</div>
<div class="body">
El siguiente enlace presenta una sesión de *Compiler Explorer* con el código del juego tras encapsular el acceso a `ConjuntoChar` mediante funciones auxiliares.

💻 [Transformar ConjuntoChar en una clase](https://godbolt.org/z/vf89WscP6)

Sustituye el `struct` por una clase de C++, y modifica las funciones definidas sobre conjuntos para queden integradas como métodos dentro de la clase.
</div>
</div>



La solución está en el siguiente video, en el que introducimos las clases de C++ en nuestro juego.

▶️ [Encapsulación en TADs](https://youtu.be/t1vtj3kU7Kg) (7:58)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/tree/main/intro/juego_letras_clases)

## 1.3. Conceptos básicos en Tipos Abstractos de Datos

En este último vídeo vamos a introducir de manera informal los conceptos que aparecen en el estudio de las estructuras de datos y los TADs: modelos, representaciones e invariantes de representación. También se introduce la importante distinción entre operaciones constructoras, observadoras y mutadoras.

▶️ [Modelo vs representación en TADs](https://youtu.be/2rLjYFZ03ek) (13:31)


<div class="exercise">
<div class="title">
📝 Ejercicio 1.5
</div>
<div class="body">
El siguiente cuestionario presenta más ejemplos de TADs y sus correspondientes modelos.

❓ [Cuestionario - Modelo vs Representación](quizzes/sem01_2.md)
</div>
</div>


