# Get_next_line
## Descripción del proyecto
Este proyecto trata sobre la creación de una función que permite leer una linea de un archivo descriptor independientemente del tamaño de esta. Se puede llamar varias veces a la función para leer un archivo entero sin importar su tamaño. Esto se consigue mediante el uso de una variable estatica que va guardando el punto de lectura actual. La función recibe un descriptor de archivo y devuelve la siguiente linea como una cadena de caracteres terminado en null.
## Compilación
Este programa se compila como una libreria. Es por eso que el primer paso es hacer:

    make

Despues puedes ejecutar tu main junto con la libreria con:

    cc -Wall -Wextra -Werror tu_main.c get_next_line.a
## Objetivos de Aprendizaje
- Uso de variables estaticas
- Aprendizaje sobre programas secuenciales
## Más sobre mi
- Para ver mi progresion en el common core 42 [AQUI](https://github.com/pmelo-cl/42Cursus)
