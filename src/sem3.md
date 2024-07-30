# Semana 3 - TAD Lista. Listas enlazadas dobles y circulares

<div class="aims">
<div class="aims_header">
✔️ Objetivos
</div>

* Simplificar las implementaciones de listas mediante el uso de nodos fantasma.

* Conocer las listas doblemente enlazadas y circulares.

* Aplicar los mecanismos de sobrecarga de operadores de C++ a los TADs para mejorar la legibilidad de los programas.
    
<div class="aims_header">
✔️ Tiempo de estudio
</div>

* **Vídeos**: 1h 4min

* **Total** *(incluyendo vídeos, cuestionarios y actividades de autoevaluación)*: 2h 30min

</div>

## 3.1. Incorporando un nodo fantasma

 La semana pasada presentamos las listas enlazadas simples como mecanismo de implementación del TAD Lista. Ahora vamos a incorporar una pequeña mejora en nuestra implementación. Consiste en introducir un nodo extra al principio de la lista enlazada, al que llamaremos *nodo fantasma*.

¿Para qué sirve esto? Aparentemente, es absurdo tener en memoria un nodo extra cuya información es irrelevante. Sin embargo, este nodo va a simplificar mucho las implementaciones.

▶️ ️[Nodos fantasma](https://youtu.be/YDE5_oIRG-U) (9:07)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/tree/main/lineales/list_linked_single_v3)

Puede que después de esto pienses: *«Bueno, tampoco hemos ganado tanto. Solo se han simplificado dos métodos»*. Ten paciencia. Los beneficios del nodo fantasma serán más evidentes cuando lleguemos a las listas enlazadas circulares. 

## 3.2. Listas doblemente enlazadas
 
En los ejercicios que hemos hecho durante la semana pasada hemos tenido que recorrer una lista enlazada simple para manipular sus punteros. Estos recorridos se hacían de izquierda a derecha, ya que es más fácil avanzar por los nodos de una lista enlazada siguiendo el flujo de los punteros que retroceder por ellos. Al fin y al cabo, cada nodo contiene una conexión directa con el siguiente, pero no con el anterior.

<div class="exercise">
<div class="title">
📝 Ejercicio 3.1
</div>
<div class="body">

Para motivar mejor la utilidad de lo que viene a continuación, vamos a hacer un ejercicio, similar a los de la semana pasada, pero más sencillo (para que os dé menos pereza hacerlo :-)).

💻 [Ejercicio - Imprimir los elementos de una lista al revés](quizzes/sem03_1.md)

</div>
</div>

Pasamos ahora a introducir las listas doblemente enlazadas: 

▶️ ️[Listas doblemente enlazadas (1)](https://youtu.be/lPHRYDIVrko) (7:20)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/tree/main/lineales/list_linked_double_v1)

¿Y bien? ¿Dónde esta la mejora en eficiencia que os he prometido? Pues ahora vamos a ello: ¿cuáles son las operaciones que siguen teniendo coste lineal con respecto al tamaño de la lista? Aquellas que manipulan la lista por el final, ya que nos obligan a navegar por todos nodos de la lista hasta llegar al último de ellos, y hacer allí los cambios correspondientes. Sería ideal tener una manera directa de llegar a este último nodo sin recorrer la lista entera. A continuación lo haremos:

▶️ ️[Listas doblemente enlazadas (2)](https://youtu.be/hd2KfYBKyRc) (7:21)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/tree/main/lineales/list_linked_double_v2)

Bueno, parece que por fin hemos mejorado el coste de algunas de las operaciones gracias a este nuevo puntero al último elemento de la lista.

*SPOILER: no os encariñéis demasiado con el atributo `last`, porque no se va a quedar mucho tiempo con nosotros :-)*

<div class="exercise">
<div class="title">
📝 Ejercicio 3.2
</div>
<div class="body">
 
 Antes de continuar, tengo una pregunta importante: ¿Por qué no hemos aplicado esta misma idea a las listas enlazadas *simples*? Al fin y al cabo, si yo tuviera un puntero al último nodo, el coste de muchas de las operaciones mejorarían... ¿o no?. Veámoslo: 

💻 [Ejercicio - Listas enlazadas simples con puntero al último nodo](quizzes/sem03_2.md)
</div>
</div>


<div class="exercise">
<div class="title">
📝 Ejercicio 3.3
</div>
<div class="body">

En el siguiente cuestionario puedes repasar todos los conceptos vistos hasta ahora:

❓ [Cuestionario de autoevaluación - Listas enlazadas simples](quizzes/sem03_3.md)

</div>
</div>

## 3.3. Listas enlazadas circulares

Pasamos a introducir el último tipo de listas enlazadas: las listas doblemente enlazadas circulares. 

▶️ ️[Listas enlazadas circulares](https://youtu.be/zUXxg2WU9aw) (6:36)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/tree/main/lineales/list_linked_double_v3)


<div class="exercise">
<div class="title">
📝 Ejercicio 3.4
</div>
<div class="body">

En el siguiente cuestionario puedes poner a prueba lo visto en el vídeo anterior:

❓ [Cuestionario de autoevaluación - Listas doblemente enlazadas y circulares](quizzes/sem03_4.md)

</div>
</div>

## 3.4. Sobrecarga de operadores en C++

Vamos a tomarnos un descanso de engarzar punteros entre los nodos de una lista enlazada para presentar una característica interesante de C++: la sobrecarga de operadores. Esta característica también se encuentra en otros lenguajes de programación (Python, C#, Lua, etc.), pero no en Java.

▶️ ️[C++ - Sobrecarga de operadores](https://youtu.be/ny18HCghKBQ) (12:35)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/tree/main/cpp/07_sobrecarga_operadores/Complejo_v2)

En una de las diapositivas del vídeo anterior aparecía la lista de operadores sobrecargables. Entre ellos estaba el operador `=`. Hay que prestar atención a este operador, porque a veces vamos a tener que sobrecargarlo si no queremos que nuestras clases tengan comportamientos inesperados.

¿Qué es lo que hace el operador `=`?. Ya lo conocéis desde el año pasado. Si tenemos lo siguiente:

```cpp
int x;
x = 2 + 4;
```
El operador `=` evalúa lo que tiene a su lado derecho (`2 + 4`) y sobreescribe el valor de la variable del lado izquierdo con el resultado de la evaluación.

Ahora bien ¿Qué pasa si yo hago una asignación de un registro a otro?

```cpp
struct Punto {
  int x;
  int y;
};
// ...
Punto p1;
p1.x = 1;
p1.y = 2;
Punto p2;
p2 = p1;        // <-- Asignación de p1 a p2
```
Por defecto, y salvo que indiquemos lo contrario, el operador `=` asigna el valor del campo `p1.x` a `p2.x` y similarmente con `p1.y`. El código sería equivalente al siguiente:

```cpp
struct Punto {
  int x;
  int y;
};
// ...
Punto p1;
p1.x = 1;
p1.y = 2;
Punto p2;
p2.x = p1.x;    // <-- Asignación del atributo x de p1 al atributo x de p2
p2.y = p1.y;    // <-- Asignación del atributo y de p1 al atributo x de p2
```

El transferir la información, atributo por atributo, de un objeto a otro puede ser razonable en muchos casos, pero no en otros. Este problema ya lo hemos tenido la semana pasada con el constructor de copia. Si uno de los atributos del objeto a copiar es un puntero a otro, no me interesa copiar el puntero sin más, sino hacer una copia del contenido apuntado por ese puntero.

Estos problemas y otros similares son el objeto del siguiente vídeo:

▶️ ️[C++ - Operador de asignación](https://youtu.be/5T-29lMX0VQ) (12:19)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/tree/main/cpp/08_operador_asignacion)

<div class="exercise">
<div class="title">
📝 Ejercicio 3.5
</div>
<div class="body">

En el siguiente cuestionario podrás repasar lo visto en el vídeo anterior:

❓ [Cuestionario de autoevaluación - Sobrecarga de operadores](quizzes/sem03_5.md)

</div>
</div>


 Ya que hemos aprendido cómo se sobrecargan operadores, vamos a ver cómo podemos aplicar la sobrecarga a las clases del TAD lista que hemos creado hasta ahora. En particular, vamos a sobrecargar los operadores de desplazamiento (`<<`), indexación (`[]`) y asignación (`=`).

▶️ [Sobrecargando operadores en el TAD Lista](https://youtu.be/y6RSQWj-WY4) (8:01)

Las implementaciones de nuestras versiones del TAD Lista quedan del siguiente modo:

📄 [Código fuente (TAD Lista mediante arrays)](https://github.com/manuelmontenegro/ED/tree/main/lineales/list_array_v4)

📄 [Código fuente (TAD Lista mediante listas enlazadas simples)](https://github.com/manuelmontenegro/ED/tree/main/lineales/list_linked_single_v4)

📄 [Código fuente (TAD Lista mediante listas doblemente enlazadas circulares)](https://github.com/manuelmontenegro/ED/tree/main/lineales/list_linked_double_v4)



## 3.5. Problemas de laboratorio

<div class="exercise">
<div class="title">
📝 Ejercicio 3.6
</div>
<div class="body">

💻 [Sumar a un elemento de una lista ordenada](assignments/L03-1.pdf)

</div>
</div>

<div class="exercise">
<div class="title">
📝 Ejercicio 3.7
</div>
<div class="body">

💻 [Ordenación por selección](assignments/L03-2.pdf)

</div>
</div>

