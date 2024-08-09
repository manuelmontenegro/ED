# Semana 11 - Aplicaciones de Tipos Abstractos de Datos



<div class="aims">
<div class="aims_header">
✔️ Objetivos
</div>

* Identificar los TADs que se necesitan para resolver un problema concreto.

* Evaluar qué implementaciones de un TAD son las más adecuadas para resolver un determinado problema, tomando como criterio principal el coste asintótico en tiempo de sus operaciones.

* Diseñar e implementar un TAD de propósito específico combinando varios de los TADs vistos a lo largo del curso.
  
<div class="aims_header">
✔️ Tiempo de estudio
</div>

* **Vídeos**: 50 min (+17 min opcionales)

* **Total** *(incluyendo vídeos, cuestionarios y actividades de autoevaluación, pero no los problemas de la sección 11.6)*: 2h

</div>

 Esta semana comenzamos el último tema de la asignatura, titulado *Aplicaciones de Tipos Abstractos de Datos*. Este tema es puramente práctico. Consiste, básicamente, en realizar ejercicios de cierta complejidad en el que intervienen varios de los TADs vistos en este curso. Por tanto, no tenemos apenas teoría que ver esta semana, salvo algunos conceptos de C++ relacionados con las excepciones, que ya conocéis de la asignatura *Tecnología de la Programación*. Tras presentar las excepciones, estudiaremos dos ejemplos, abordando el primero de ellos de manera incremental.

 ## 11.1. Manejo de excepciones en C++

 Hasta ahora hemos utilizado la macro `assert` para detectar condiciones de error en nuestros TADs (por ejemplo, al obtener la cima de una pila vacía, o acceder al valor de un iterador que apunta al fin de una lista). Como ya sabéis, esta macro evalúa la condición que recibe como parámetro. Si esta condición no se cumple, el programa aborta con un mensaje de error.

En muchos casos, abortar el programa en caso de error resulta demasiado radical. Ya sabéis que en Java existe un mecanismo de gestión de errores más sofisticado que los `assert`. Este mecanismo está basado en el lanzamiento y captura de *excepciones*. Pues bien, en C++ también disponemos de excepciones. Sus detalles sintácticos y semánticos son muy parecidos a los de Java, así que el siguiente vídeo se centrará en las diferencias:

▶️ [C++ - Gestión de excepciones](https://youtu.be/2yDgFbBR_po) (4:47)

Un pequeño apunte para el que no se haya dado cuenta: el método `what` es equivalente al método `getMessage` de las excepciones de Java.

En los ejercicios de este tema vamos a hacer uso de excepciones para gestionar los casos de error que vayan surgiendo.


## 11.2. Primer ejemplo: gestión de una academia

Supongamos que queremos gestionar una academia que ofrece varios cursos de formación. Cada uno de estos cursos puede acoger una cantidad limitada de estudiantes. En esta sección vamos a implementar un TAD para manejar los cursos y estudiantes de esta academia. Lo haremos mediante una clase `Academia` que ofrece los siguientes métodos públicos:

* `Academia()`

  Constructor que crea una academia vacía, sin cursos ni estudiantes.

* `void anyadir_curso(const std::string &nombre, int numero_plazas)`

  Añade un curso a la academia, con un nombre de curso y un número máximo de plazas.

* `void eliminar_curso(const Curso &curso)`
  
  Elimina de la academia el curso cuyo nombre coincida con el pasado como parámetro. El tipo de datos `Curso` es un alias de `std::string`.

* `void matricular_en_curso(const Estudiante &est, const Curso &curso)`

  Añade un determinado estudiante a la lista de estudiantes inscritos en un curso. En este caso también podemos considerar que el tipo `Estudiante` es un alias de `std::string`.

* `int plazas_libres(const Curso &curso) const`

  Obtiene el número de plazas disponibles en el curso cuyo nombre se recibe como parámetro.

* `std::vector<Estudiante> estudiantes_matriculados(const Curso &curso) const`

  Obtiene un listado ordenado de los estudiantes matriculados en un determinado curso.

<div class="exercise">
<div class="title">
📝 Ejercicio 11.1
</div>
<div class="body">
Aunque en el siguiente vídeo vamos a resolver este problema, tú ya tienes los conocimientos necesarios para llevar a cabo esta tarea. Te invito a que intentes resolverlo tú mismo/a antes de ver el vídeo. Utiliza las librerías de la STL de C++.

💻 [Ejercicio: TAD Academia (1)](https://godbolt.org/z/1c4adbdor)
</div>
</div>

La solución al ejercicio anterior se encuentra en el siguiente vídeo:

▶️ [Gestión de una academia (1)](https://youtu.be/wiAQ3Y26UMs) (12:47)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/blob/main/aplicaciones/academia_v1/academia.h)

Nuestro diseño actual tiene una serie de inconvenientes. Uno de ellos es el ya mencionado anteriormente: No es buena idea identificar a un estudiante mediante su nombre y apellido, ya que puede haber dos personas con los mismos nombres y apellidos. Es más adecuado utilizar un número de documento de identidad (NIF, NIE, etc.). Otro inconveniente es el problema que conllevaría saber cuántos estudiantes tenemos en la academia. Para ello necesitaríamos recorrer todos los cursos y saber cuántos hay matriculados en cada uno de ellos, procurando no contar por duplicado aquellos estudiantes que esten matriculados en varios cursos.

Por estos motivos, resulta más cómodo tener un registro de los estudiantes inscritos en la academia. Un estudiante inscrito en la academia puede estar matriculado en cero, uno, o varios cursos.

Añadimos las siguientes operaciones a nuestro TAD: 


* `void anyadir_estudiante(const Estudiante &id_est, const std::string &nombre, const std::string &apellidos)`
    
  Registra un estudiante en la academia.
  
* `std::vector<std::string> cursos_estudiante(const Estudiante &id_est) const`
  
  Devuelve una lista (ordenada alfabéticamente) con los nombres de los cursos en los que está matriculado un estudiante.

▶️ [Gestión de una academia (2)](https://youtu.be/CY3lx1MI7W0) (10:36)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/blob/main/aplicaciones/academia_v2/academia.h)

Ahora realizamos una tercera ampliación: listas de espera. Si un estudiante quiere matricularse en un curso y no hay plazas disponibles, a ese estudiante se le pone en una lista de espera asociada a ese curso. Cuando algún otro estudiante se dé de baja en el curso, se matriculará automáticamente al primer estudiante de la lista de espera. Queremos, por tanto, añadir una nueva operación:

* `void dar_de_baja_en_curso(const Estudiante &est, const Curso &curso)`

  Da de baja a un estudiante de la academia en un determinado curso. Si hay más estudiantes en lista de espera, se matricula automáticamente al primero de dicha lista. 



▶️ [Gestión de una academia (3)](https://youtu.be/kQmY7BJGNuA) (3:22)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/blob/main/aplicaciones/academia_v3/academia.h)

## 11.3. Segundo ejemplo: líneas de transporte público

El siguiente ejemplo que vamos a estudiar consiste en un TAD que nos permitirá gestionar las lineas regulares de un sistema de transporte (por ejemplo, metro). En particular, queremos gestionar los horarios de salida de los trenes, y conocer cuál es el tiempo que debemos esperar al próximo tren desde una determinada estación.

Este ejemplo va hacer uso de un TAD auxiliar para manejar horas. Ya hemos abordado este problema al principio de curso, pero conviene que lo recuerdes:

📝 [La hora de la pastilla (con solución)](assignments/L01-4.pdf)

Pasamos ahora a implementar el TAD de gestión de líneas de metro. Queremos implementar las siguientes operaciones:

* `Metro()`

  Crea un sistema de metro vacío, sin líneas ni horarios de salida.

* `void nueva_linea(const Linea &nombre)`

  Añade una línea de metro al sistema.

* `void nueva_parada(const Linea &nombre, const Parada &nueva_parada, int tiempo_desde_anterior)`

  Añade una nueva parada al final de la línea que tenga el nombre dado. El tercer parámetro indica el tiempo que tarda un tren desde la parada anterior hasta la parada a insertar.

* `nuevo_tren(const Linea &nombre, const Hora &hora_salida)`

  Añade un nuevo tren a una determinada línea, indicando la hora de salida desde la cabecera de la línea.

* `int numero_trenes(const Linea &nombre) const`

  Indica el número de trenes que salen de una determinada línea.

* `int tiempo_proximo_tren(const Linea &linea, const Parada &parada, const Hora &hora_actual) const`

  Dada una parada dentro de una línea y la hora actual, devuelve el número de segundos que quedan para que llegue el siguiente tren a dicha parada.

Ojo, el siguiente vídeo es bastante denso, así que miradlo con calma. Os he avisado... ;-)

▶️ [Líneas de metro](https://youtu.be/9zdlyFdpVz0) (19:53)

📄 [Código fuente (versión inicial)](https://github.com/manuelmontenegro/ED/blob/main/aplicaciones/metro_v1/metro.h)

📄 [Código fuente (versión alternativa)](https://github.com/manuelmontenegro/ED/blob/main/aplicaciones/metro_v2/metro.h)


## 11.4. Herencia y polimorfismo en C++ (opcional)

A lo largo de este curso hemos visto muchas características de C++ relacionadas con la Programación Orientada a Objetos (OOP). En cualquier curso sobre OOP es casi obligatorio hablar sobre herencia y polimorfismo, conceptos que ya habéis estudiado en *Tecnología de la Programación* y que, sin embargo, en este curso han brillado por su ausencia. El motivo es que a la hora de implementar nuestros TADs (listas, colas, conjuntos, etc.) siempre hemos intentado imitar, en la medida de lo posible, las implementaciones de la STL, y en la STL apenas se hace uso de la herencia. De hecho, el propio creador de la STL [es bastante crítico con la programación orientada a objetos](http://www.stlport.org/resources/StepanovUSA.html).

Independientemente del (no-)uso que hayamos hecho de la herencia, es necesario saber al menos que en C++ existe herencia entre clases, además de los conceptos de OOP que ya habéis visto en TP aplicados a Java. En este video se hace un breve resumen de cómo se maneja la herencia en C++:

▶️ [C++ - Herencia y polimorfismo](https://youtu.be/oNrGP9jGlMs) (Opcional - 11:44)

## 11.5. TADs asociativos en Java (opcional)

Ya hicimos un primer repaso de los TADs lineales en Java hace unas semanas. Ahora le toca el turno a los TADs no lineales, como son los conjuntos y los diccionarios. Aunque en este curso no hemos programado nada con Java, la información de aquí os puede ser útil en otras asignaturas, sean presentes o futuras.

▶️ [Java - Contenedores asociativos](https://youtu.be/nhFNPOQDXnY) (Opcional - 5:30)

## 11.6. Problemas de laboratorio


<div class="exercise">
<div class="title">
📝 Ejercicio 11.2
</div>
<div class="body">

💻 [Elecciones presidenciales](assignments/L11-1.pdf)

</div>
</div>

<div class="exercise">
<div class="title">
📝 Ejercicio 11.3
</div>
<div class="body">

💻 [Las torres del desierto](assignments/L11-2.pdf)

</div>
</div>

<div class="exercise">
<div class="title">
📝 Ejercicio 11.4
</div>
<div class="body">

💻 [Spitter](assignments/L11-3assignments/L11-1.pdf.pdf)

</div>
</div>