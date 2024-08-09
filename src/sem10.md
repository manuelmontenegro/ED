# Semana 10 - Tablas *hash*

<div class="aims">
<div class="aims_header">
✔️ Objetivos
</div>

* Conocer las tablas *hash* y su utilidad en la implementacion de diccionarios y conjuntos.

* Conocer los distintos mecanismos de resolución de conflictos en una tabla *hash*: tablas abiertas y cerradas.

* Conocer la noción de factor de carga, y su influencia en el coste de las operaciones.

* Utilizar las clases de la STL relacionadas con conjuntos y diccionarios.
  
<div class="aims_header">
✔️ Tiempo de estudio
</div>

* **Vídeos**: 45 min (+30 min opcionales)

* **Total** *(incluyendo vídeos, cuestionarios y actividades de autoevaluación, pero no los problemas de la sección 10.3)*: 1h 30min

</div>


La semana pasada presentamos el TAD Diccionario y lo implementamos utilizando árboles binarios de búsqueda. Esta semana estudiaremos otra forma distinta de implementar los diccionarios: las tablas de dispersión, también conocidas como **tablas** ***hash***. Con ellas conseguiremos que las operaciones de los diccionarios y conjuntos tengan coste en tiempo constante, siempre que se cumplan una serie de requisitos, que se detallarán más adelante.

Tras estudiar las tablas *hash* daremos un breve recorrido por las clases de la STL que implementan los tipos abstractos vistos en las últimas semanas: el TAD Diccionario y el TAD Conjunto.

## 10.1. Tablas *hash*

Una tabla *hash* no es más que un array con un número fijo de posiciones. Cada vez que queremos insertar una entrada en una tabla *hash*, tenemos que colocarla en una de las posiciones de este array. La posición en particular depende de la clave que queramos insertar. A cada clave le corresponde una posición predeterminada dentro de ese array. ¿Cómo sabemos qué posición corresponde a cada clave? Nos lo dice una función que hayamos definido previamente, también llamada *función hash*.

El siguiente vídeo introduce las tablas *hash* y sus mecanismos básicos de inserción y búsqueda. También se plantea por primera vez el problema de colisión entre claves. Sin duda, es el vídeo más importante de todos los de esta semana. En él se resumen las principales ideas que irán desarrollándose a lo largo de este tema.

▶️ [Introducción a las tablas hash](https://youtu.be/5voK4x-UBq0) (11:26)


<div class="exercise">
<div class="title">
📝 Ejercicio 10.1
</div>
<div class="body">

Un ingrediente básico en este esquema es el de la función *hash*. En efecto, usar una tabla *hash* nos requiere saber cómo transformar una clave en un número entero (su *código hash*). En el vídeo anterior hemos visto posibles formas de calcular el código *hash* de cadenas de texto. En el siguiente ejercicio vamos a explorar cómo podemos hacerlo para el tipo de datos `Fecha` que ya conocemos:

💻 [Ejercicio: función *hash* aplicada a clase `Fecha`](https://godbolt.org/z/7a7KzMPjY)

💻 [Solución](https://godbolt.org/z/nbozTKhGh)
</div>
</div>

## 10.1.1. Tablas *hash* abiertas

Pasamos a la primera implementación de las tablas *hash*. Se trata de las tablas abiertas, que gestionan las colisiones almacenando las entradas que colisionan en el mismo cajón. De este modo, cada cajón contiene una **lista** de entradas.

En el siguiente vídeo se implementa el TAD Diccionario mediante una clase llamada `MapHash`. Existen algunos detalles técnicos que no son demasiado relevantes (por ejemplo, el uso de `erase_after`). Lo importante es conocer la idea general de la implementación.

▶️ [Diccionarios mediante tablas hash abiertas](https://youtu.be/PhPweb-ksrc) (9:42)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/blob/main/diccionarios/map_hash_open_v1/map_hash_open.h)

## 10.1.2. Tablas *hash* abiertas

Ahora pasamos a la otra alternativa: tablas *hash* en las que cada cajón contiene una única entrada. Estas son las tablas *hash* cerradas.

¿Cómo se gestionan las colisiones en este tipo de tablas? Supongamos que queremos insertar una entrada y que, tras aplicar la función *hash* a su clave, determinamos que dicha entrada debe almacenarse en la posición *p<sub>0</sub>* del array, pero esa posición está ocupada. ¿Qué hacemos? Pasamos a realizar un **sondeo** en busca de una posición libre. El procedimiento de sondeo nos devolverá una posición alternativa *p<sub>1</sub>*. Si también está ocupada, hacemos otro sondeo para obtener otra alternativa *p<sub>2</sub>*, y así sucesivamente.

¿Y en qué consiste exactamente un *sondeo*? Depende. Los sondeos pueden realizarse de varias formas. En la implementación que mostramos aquí consideramos un **sondeo lineal**, en el que las posiciones alternativas devueltas son las que se encuentran inmediatamente después de la posición *p<sub>0</sub>* inicial. Si no hay más posiciones después de *p<sub>0</sub>*, volvemos a empezar por el principio del array.

El siguiente vídeo se compone de tres partes:

1. Visión general de la implementación de una tabla *hash* cerrada, y los problemas que conlleva el borrado de entradas (hasta minuto 7:01).

2. Implementación en C++ de este tipo de tablas (minuto 7:01 hasta 13:14).

3. Alternativas al mecanismo de sondeo lineal: sondeo cuadrático, redispersión, etc. (desde 13:14 en adelante).

Las dos últimas partes, al abordar detalles más específicos, pueden considerarse opcionales.

▶️ [Diccionarios mediante tablas *hash* cerradas](https://youtu.be/M4tt_TifZ_w) (17:47)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/blob/main/diccionarios/map_hash_closed_v1/map_hash_closed.h)

## 10.1.3. Análisis de coste y tablas *hash* extensibles

A estas alturas habrás sido consciente de que no hemos hablado del coste en tiempo en las implementaciones realizadas hasta ahora. En el siguiente ejercicio guiado vamos a explorar los factores que intervienen en el coste:


<div class="exercise">
<div class="title">
📝 Ejercicio 10.2
</div>
<div class="body">


❓ [Ejercicio - Análisis de coste en el caso peor](quizzes/sem10_1.md)

</div>
</div>

El análisis de coste en el caso peor es demasiado pesimista. Resulta más interesante realizar un análisis del caso medio, pero esto requiere realizar algunos cálculos probabilísticos y suponer ciertas condiciones sobre la función *hash*. Además, hay que tener en cuenta un componente adicional muy importante: el *factor de carga* de una tabla. En el siguiente vídeo se realiza parte del desarrollo técnico de este análisis. No es necesario entenderlo en su totalidad, pero sí hay algunos aspectos importantes que es necesario remarcar:

* El concepto de factor de carga y la suposición de dispersión uniforme (hasta minuto 2:30).

* La importancia de mantener el factor de carga acotado en las tablas hash abiertas (desde minuto 5:25 hasta 6:27).

* La importancia de mantener el factor de carga acotado en las tablas hash cerradas (desde minuto 11:42 hasta final).

▶️ [Análisis de coste en tablas *hash*](https://youtu.be/Z1jIjYYxTQI) (12:40)

Tal y como se extrae del vídeo anterior, una posible forma de mantener α acotado consiste en ampliar el vector de cajones cuando α supera un determinado valor umbral. Esto es lo que hacemos en el vídeo siguiente:

▶️ [Diccionarios mediante tablas *hash* redimensionables](https://youtu.be/ySIl0jF6DXU) (6:20)

📄 [Código fuente (tablas *hash* abiertas)](https://github.com/manuelmontenegro/ED/blob/main/diccionarios/map_hash_open_v2/map_hash_open.h)

Hemos aplicado esta idea a las tablas *hash* abiertas, pero también podría haberse aplicado a las tablas cerradas.

📄 [Código fuente (tablas *hash* cerradas)](https://github.com/manuelmontenegro/ED/blob/main/diccionarios/map_hash_closed_v2/map_hash_closed.h)


<div class="exercise">
<div class="title">
📝 Ejercicio 10.3
</div>
<div class="body">

Concluimos esta sección con un cuestionario de autoevaluación:

❓ [Cuestionario - Tablas hash](quizzes/sem10_2.md)

</div>
</div>

## 10.2. Conjuntos y diccionarios en la STL

En las últimas semanas hemos introducido dos tipos abstractos de datos nuevos: conjuntos y diccionarios. Estos TADs están implementados en las librerías de C++. Al igual que hicimos la última vez que hablamos de la STL (Semana 5), te animo a que busques por tí mismo/a los nombres de las clases en la documentación de la STL:

<div class="exercise">
<div class="title">
📝 Ejercicio 10.4
</div>
<div class="body">

En el siguiente enlace, examina las clases listadas en la sección *Associative containers* y *Unordered associative containers*.

🌎 [Colecciones en la STL](https://en.cppreference.com/w/cpp/container)

A continuación rellena el siguiente cuestionario:

❓ [Ejercicio - Contenedores asociativos en la STL](quizzes/sem10_3.md)

</div>
</div>

Ahora sí: damos un breve repaso por las clases que implementan los conjuntos y los diccionarios dentro de la STL.

▶️ [C++ - Contenedores asociativos en la STL](https://youtu.be/yoS3orfCTa0) (5:20)

Independientemente de las clases destinadas a almacenar colecciones de datos (listas, pilas, colas, diccionarios, conjuntos, etc.) la STL también implementa, en el fichero de cabecera `<algorithm>`, algunas funciones útiles para manipular estos tipos de datos. Ya vimos en su momento dos de ellas: `copy` y `sort`.

En el siguiente vídeo, que es opcional, se explican algunas funciones más avanzadas. Ten en cuenta que se hace uso extensivo de funciones de orden superior.

▶️ [C++ - Algoritmos en la STL (2)](https://youtu.be/BPnLMFPicGs) (Opcional - 10:47)

## 10.3. Prácticas de laboratorio


<div class="exercise">
<div class="title">
📝 Ejercicio 10.1
</div>
<div class="body">

💻 [El bingo de Azahara](https://aceptaelreto.com/problem/statement.php?id=729)

</div>
</div>

<div class="exercise">
<div class="title">
📝 Ejercicio 10.2
</div>
<div class="body">

💻 [Cadenas expansivas](assignments/L10-2.pdf)

</div>
</div>

