# Semana 7 - Recorridos en árboles binarios

<div class="aims">
<div class="aims_header">
✔️ Objetivos
</div>

* Distinguir los distintos tipos de recorridos en un árbol binario: *preorden*, *inorden*, *postorden* y *recorrido en anchura*.

* Saber implementar, de manera recursiva, los recorridos en profundidad: preorden, inorden y postorden.

* Saber implementar, de manera iterativa, el recorrido en anchura de un árbol utilizando una cola auxiliar.

* Utilizar *objetos función* y *expresiones lambda* para definir las acciones a realizar en el recorrido de un árbol.
    
<div class="aims_header">
✔️ Tiempo de estudio
</div>

* **Vídeos**: 47min

* **Total** *(incluyendo vídeos, cuestionarios y actividades de autoevaluación, pero no los problemas de la sección 7.4)*: 2h

</div>

## 7.1. Recorriendo un árbol binario

Ya sabéis cómo recorrer listas utilizando iteradores. ¿Y si quisiéramos recorrer *un árbol*? El problema aquí es más complejo, ya que los árboles son estructuras no lineales y el orden en el que pueden visitarse los nodos no resulta tan obvio como en el caso de una lista.

Dedicaremos esta semana a los tipos de recorridos más habituales en un árbol. El siguiente vídeo es el más importante de esta semana. En él se describen los tipos de recorridos que vamos a estudiar durante este curso.

▶️ [Recorridos de árboles binarios](https://youtu.be/_ikOWSTvTYg) (7:41)

<div class="exercise">
<div class="title">
📝 Ejercicio 7.1
</div>
<div class="body">

¿Has entendido la diferencia entre los recorridos? En el siguiente test puedes practicarlos:

❓ [Cuestionario de autoevaluación - Recorridos en árboles binarios](quizzes/sem07_1.md)

</div>
</div>


## 7.2. Una primera implementación de los recorridos en un árbol

Conocidos los conceptos relativos a los recorridos, vamos a comenzar con las implementaciones. Para facilitar las cosas, supondremos que la operación de visitar un nodo consiste, simplemente, en imprimir su contenido.

La implementación de los recorridos en profundidad es bastante sencilla si se aborda con un diseño recursivo:

▶️ [Implementación de recorridos en profundidad (DFS)](https://youtu.be/Vv9rB-xJpgc) (3:25)

La implementación de los recorridos en anchura se complica un poco más, debido al hecho de que utiliza una cola auxiliar. No obstante, la idea siendo bastante intuitiva. Además, para este recorrido no hace falta recursión:

▶️ [Implementación de recorridos en anchura (BFS)](https://youtu.be/VlKaPHpEYKo) (4:11)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/blob/main/arboles/bintree_v4/bintree.h)

## 7.3. Redefiniendo la acción de visitar: funciones de orden superior

Comencemos con un sencillo ejercicio:

<div class="exercise">
<div class="title">
📝 Ejercicio 7.2
</div>
<div class="body">

Nuestra definición de `inorder` hace un recorrido en inorden de un árbol binario, imprimiendo el valor de cada nodo a medida que pasaba por él. En el siguiente ejercicio, modifica el método `inorder` para que reciba dos parámetros adicionales:

* **after** (de tipo `string`) - Indica la cadena que debe imprimirse tras el contenido de cada elemento. Debe sustituir al espacio en blanco (`" "`) que imprime la versión actual de `inorder`.
    
* **min_value** (de tipo `const T &`) - Indica un valor umbral mínimo que ha de tener un elemento para que se muestre por pantalla. Los nodos del árbol cuyo valor sea menor que `min_value` no serán mostrados.

💻 [Ejercicio: parametrizar el método inorder](https://godbolt.org/z/ex1ezezqY)

💻 [Solución](https://godbolt.org/z/PKqqGMjWf)

</div>
</div>

Con este ejercicio hemos conseguido personalizar ligeramente las acciones a realizar en cada nodo durante el recorrido, pero, aun así, hay mucho margen de mejora. ¿Y si quisiéramos hacer otra cosa que no sea, simplemente, imprimir el nodo por pantalla? Sería muy complicado (y absurdo) tener un método `inorder` distinto para cada tipo de acción que queramos hacer sobre un árbol. El objetivo de esta sección es modificar los métodos `preorder`, `inorder` y `postorder` para que **reciban como parámetro una función que implemente la acción a realizar para cada nodo**.

Pero, ¿es posible pasar una **función** como parámetro en C++? Sí, es posible.

Las funciones de C++ pueden asignarse a variables, pueden pasarse por parámetro, o incluso devolverse como resultado. Los lenguajes de programación que permiten todo esto reciben el nombre de lenguajes de *orden superior*.

Vamos a ver cómo funcionan las funciones de orden superior en un sencillo ejemplo con listas. Antes de comenzar con el siguiente vídeo, conviene que repases el primer ejercicio de la hoja que vimos hace un par de semanas ([Recorridos con iteradores](assignments/L05-4.pdf)). En particular, echa un vistazo a la función `eliminar_pares`.

▶️ [C++ - Funciones de orden superior](https://youtu.be/VOhyhj5oTWE) (7:37)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/blob/main/cpp/13_objetos_funcion/main1.cpp)

Antes de seguir, vamos a poner en práctica la nueva función `eliminar` con algunos ejemplos, que también servirán para motivar el vídeo que viene después.


<div class="exercise">
<div class="title">
📝 Ejercicio 7.3
</div>
<div class="body">

Dada una lista de nombres recibida por teclado, utiliza la función `eliminar` para eliminar aquellos nombres que comiencen por la letra `A`.

💻 [Ejercicio: eliminar nombres que comiencen por la letra A](https://godbolt.org/z/54E3chxYG)

💻 [Solución](https://godbolt.org/z/GvvYG9qYP)

</div>
</div>


<div class="exercise">
<div class="title">
📝 Ejercicio 7.4
</div>
<div class="body">

Dada una lista de nombres recibida por teclado, utiliza la función `eliminar` para eliminar aquellos nombres que comiencen por la letra que indique el usuario a través de la entrada.

💻 [Ejercicio: eliminar nombres que comiencen por la letra indicada por el usuario](https://godbolt.org/z/48cexrfeM)

</div>
</div>


¿Has conseguido resolver este último? Es más difícil, porque la función que se pasa como parámetro depende de la letra introducida por el usuario. No obstante, el ejercicio se puede resolver con los mecanismos que hemos visto en el vídeo anterior. A continuación se muestra una posible solución, aunque podría no gustarte:

💻 [Solución: eliminar nombres que comiencen por la letra indicada por el usuario](https://godbolt.org/z/665hdjeeh)

*¡Aggg! ¿Eso era una variable global?*. Sí, pero tenemos suerte, porque los *objetos función*, que veremos a continuación, permiten librarnos de esta variable:

▶️ [C++ - Objetos función](https://youtu.be/HCzk_mhBiSc) (11:57)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/blob/main/cpp/13_objetos_funcion/main2.cpp)


<div class="exercise">
<div class="title">
📝 Ejercicio 7.5
</div>
<div class="body">

Intenta ahora resolver el problema anterior, pero utilizando objetos función:

💻 [Ejercicio: eliminar nombres que comiencen por la letra indicada por el usuario](https://godbolt.org/z/vdr9xef9h)

💻 [Solución](https://godbolt.org/z/c3njbWxzE)

</div>
</div>

Con los objetos función hemos conseguido lo que queríamos, pero sin hacer uso variables globales. No obstante, hemos tenido que crear una clase adicional para implementar la sobrecarga del operador `()`. A continuación presentamos las expresiones lambda, que permiten declarar objetos función «de usar y tirar»:

▶️ [C++ - Expresiones lambda](https://youtu.be/tE1nvNFvuO0) (7:29)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/blob/main/cpp/13_objetos_funcion/main3.cpp)

<div class="exercise">
<div class="title">
📝 Ejercicio 7.6
</div>
<div class="body">

A continuación, modifica la solución del ejercicio anterior sustituyendo el objeto función por una expresión lambda:

💻 [Ejercicio: expresiones lambda para eliminar nombres comiencen por la letra indicada por el usuario](https://godbolt.org/z/vdr9xef9h)

💻 [Solución](https://godbolt.org/z/K436Mb5hv)

</div>
</div>

Todo lo que ha venido en esta sección ha sido bastante denso. Vamos a aplicarlo al tema que hemos estado tratando esta semana: los recorridos en un árbol.

▶️ [Parametrizando el recorrido de un árbol](https://youtu.be/ZrsuwmI2J8Q) (5:19)

📄 [Código fuente](https://github.com/manuelmontenegro/ED/blob/main/arboles/bintree_v5/bintree.h)

<div class="exercise">
<div class="title">
📝 Ejercicio 7.7
</div>
<div class="body">

Finalizamos con un test de autoevaluación sobre la implementación de recorridos:

❓ [Cuestionario de autoevaluación - Implementación de los recorridos de un árbol](quizzes/sem07_2.md)

</div>
</div>

## 7.4. Ejercicios y problemas de laboratorio

<div class="exercise">
<div class="title">
📝 Ejercicio 7.8
</div>
<div class="body">

💻 [Reconstrucción de un árbol a partir de sus recorridos](assignments/L07-1.pdf)

</div>
</div>

<div class="exercise">
<div class="title">
📝 Ejercicio 7.9
</div>
<div class="body">

💻 [Diferencia máxima en un árbol binario](assignments/L07-2.pdf)

</div>
</div>


<div class="exercise">
<div class="title">
📝 Ejercicio 7.10
</div>
<div class="body">

💻 [Niveles aventajados en un árbol binario](assignments/L07-3.pdf)

</div>
</div>