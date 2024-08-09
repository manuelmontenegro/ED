# Estructuras de datos con C++ {.book-title}

## ¡Bienvenido/a!

En estas páginas encontrarás una introducción a la implementación de estructuras de datos con <nobr>C++</nobr>. El material contiene más de 80 vídeos, y gran cantidad de cuestionarios y ejercicios propuestos.

Los contenidos de este sitio fueron creados originalmente como material de la asignatura *Estructuras de Datos* impartida en varias titulaciones de la [Facultad de Informática](https://informatica.ucm.es/) de la [Universidad Complutense de Madrid](https://www.ucm.es/). Los primeros videos fueron grabados a finales del año 2019, en el que comencé a aplicar la metodología de aula invertida ([*flipped classroom*](https://en.wikipedia.org/wiki/Flipped_classroom)) en mis clases. Con ello, dejé de impartir teoría en las clases presenciales; eran los estudiantes los que, por su cuenta, debían trabajar en la teoría de la asignatura mediante los vídeos, explicaciones y cuestionarios que encontrarás aquí, quedando las clases presenciales dedicadas exclusivamente a la resolución de ejercicios y problemas en el laboratorio.

En general, las valoraciones de los estudiantes al material fueron muy positivas. Por ello, he decidido hacer disponible todo el material para cualquier persona que esté interesada en la implementación de estructuras de datos básicas en C++, ya sea estudiante universitario o no.



## Qué encontrarás en este sitio

- Introducción al concepto de Tipo Abstracto de Datos (TAD)
- TADs secuenciales: pilas, colas, colas dobles, listas, etc.
- Implementaciones de tipos de datos basadas en vectores y listas enlazadas
- Árboles binarios y árboles binarios de búsqueda
- TADs asociativos: conjuntos y diccionarios (*maps*)
- Implementaciones de TADs asociativos mediante árboles binarios de búsqueda y tablas *hash*
- Aplicaciones de TADs para resolver problemas concretos
- Características de C++ orientadas a la implementación y uso de TADs:
	- Definición de clases y objetos
	- Sobrecarga de operadores
	- Plantillas (*templates*)
	- Punteros inteligentes (*smart pointers*)
	- Objetos función
	- *Standard Template Library* (STL) de C++


 ## Qué NO encontrarás en este sitio

Este material está orientado a una asignatura particular (*Estructuras de Datos*) impartida en varias titulaciones de la Facultad de Informática de la UCM. Esta asignatura tiene un temario concreto y supone unos conocimientos previos de otras asignaturas cursadas previamente. Por este motivo debes tener en cuenta lo siguiente:

- **Esto *no* es una introducción a la programación con C++**. Se supone que ya conoces los fundamentos básicos de la programación en C++ (bucles, condicionales, punteros, etc.). 

- **Esto *no* es una introducción a la programación orientada a objetos**. Al principio de este curso se explica cómo definir y utilizar clases en C++, pero se espera que conozcas las nociones básicas de la programación orientada a objetos (clases, atributos, métodos e instancias), posiblemente en otro lenguaje. Por ejemplo, en nuestra Facultad todos estos conocimientos se imparten en la asignatura *Tecnología de la Programación*.

  Por el contrario, no es necesario conocer en profundidad la herencia de clases para abordar este curso, ya que las implementaciones de TADs que realizamos en el curso utilizan una interfaz parecida la STL de C++, en las que apenas se hace uso de la herencia.

- **Esto *no* es una introducción al análisis de coste**. En particular, para entender las explicaciones que se dan en los vídeos sobre el coste de los algoritmos, se requiere conocer la notación <math><mrow><mi class="mathcal">𝒪</mi><mo form="prefix" stretchy="false">(</mo><mo>…</mo><mo form="postfix" stretchy="false">)</mo></mrow></math> y sus propiedades básicas. En la sección [*Antes de empezar*](antes_de_empezar.md) puedes encontrar un ejercicio inicial con las cuestiones necesarias relativas al análisis de coste.

- ***No* se tratan los árboles equilibrados (AVL, *red-black*, etc.)** ya que, en las titulaciones de nuestra facultad, este tipo de árboles se estudian en asignaturas de cursos posteriores.

- ***No* se estudia la implementación de grafos, ni sus algoritmos asociados**. Al igual que los árboles equilibrados, este tipo de temas se estudian en otras asignaturas más avanzadas.


 ## Aviso

El material que encontrarás aquí se proporciona tal y como está. Puedo realizar pequeñas correcciones, pero no tengo intención de incorporar más contenidos a medio plazo. Ahora mismo imparto otras asignaturas en la facultad, lo que también conlleva preparar material para ellas. Por desgracia, no me queda demasiado tiempo para mantener actualizado el material de asignaturas que ya no imparto.

Ten en cuenta, además, que la mayoría de vídeos fueron grabados en el año 2019. No se incluyen características interesantes de C++20 o C++23 que podrían ser aplicables a las implementaciones que se explican en los vídeos.

Si eres estudiante de Informática (ya sea en un centro universitario u otro), no ofrezco ninguna garantía de que los contenidos de este curso se adapten totalmente a lo que necesites para tus estudios, aunque puede algunas partes resulten útiles. Incluso si estás cursando *Estructuras de Datos* en la Facultad de Informática de la UCM, ten en cuenta que tu profesor podría utilizar otro enfoque distinto, o incluso que el temario podría cambiar desde la publicación de este sitio.

## ¿Alguna errata?

El material original de esta asignatura estaba disponible a los estudiantes mediante la plataforma Moodle utilizada en el [Campus Virtual](https://www.ucm.es/campusvirtual) de la universidad. Para generar este sitio web he traducido todas las explicaciones al formato *Markdown* (utilizado en [mdBook](https://github.com/rust-lang/mdBook)) y los cuestionarios al formato TOML (utilizado en [mdbook-quiz](https://github.com/cognitive-engineering-lab/mdbook-quiz)). Puede que se me haya escapado algún error en la traducción. Si ves alguna errata, [comunícamelo](mailto:mmontene@ucm.es) y procuraré arreglarla.

---

© [Manuel Montenegro Montes](https://dalila.sip.ucm.es/~manuel) 2024

Gracias a Alberto Verdejo por sus comentarios y correcciones del material original.






