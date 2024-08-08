# Antes de empezar

Antes de comenzar con el material del curso, vamos a hacer un par de ejercicios. En el primer de ellos sirve como introducción al primer tema de la asignatura. El segundo de ellos es un cuestionario con algunos conceptos sobre C++ y algoritmia que serán necesarios para seguir el curso.

## Ejercicio 1

En primer lugar, implementa la función `caben_todas` expuesta en el siguiente fichero:

💻 [Planificación de horarios (1)](sem0/HorasA.pdf)

¿Ya has terminado? Pues bien, ahora supongamos que queremos cambiar el modo en el que queremos representar la duración de un evento. El siguiente fichero contiene un enunciado alternativo para el ejercicio que acabamos de hacer. Adapta la solución del ejercicio que has hecho anteriormente para acomodar los cambios propuestos a continuación:

💻 [Planificación de horarios (2)](sem0/HorasB.pdf)

¿Has tenido que modificar la función `caben_todas` para implementar los cambios pedidos? El objetivo del curso es precisamente evitar esto.

Durante la primera semana semana del curso abordaremos el concepto de *Tipo Abstracto de Datos* (TAD), que nos permitirá separar la interfaz de un tipo de datos de su representación interna. Esto nos permitirá alterar la representación interna del tipo `Duracion` y sus operaciones asociadas, sin necesidad de modificar todas las funciones que hacen uso de ese tipo (en particular, `caben_todas`).

## Ejercicio 2

A continuación viene un test con aspectos básicos de C++ y análisis de coste que deberías conocer para abordar el curso:

{{#quiz quizzes/test_previo.toml}}
