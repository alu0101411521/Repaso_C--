# Juego de la vida

El Juego de la vida es un autómata celular diseñado por el matemático británico John Horton Conway en 1970. Es un juego de cero jugadores, en el que su evolución es determinada por un estado inicial, sin requerir intervención adicional.

## El juego

Se trata de un juego de cero jugadores, lo que quiere decir que su evolución está determinada por el estado inicial y no necesita ninguna entrada de datos posterior. El "tablero de juego" es una malla plana formada por cuadrados que pueden contener celulas vivas o muertas que se extiende por él hasta los bordes.

## Las reglas

1. Una célula muerta con exactamente 3 células vecinas vivas "nace" (es decir, al turno siguiente estará viva).
2. Una célula viva con 2 o 3 células vecinas vivas sigue viva, en otro caso muere (por "soledad" o "superpoblación").

- Se considera una celula vecina a cualquier cuadrado cercano al cuadrado a comparar, es decir, generando un radio de 3x3 como se ve a continuación con '*':

```
00000
0***0
0***0
0***0
00000
```

## Implementación

1. Las células vivas se marcarán como un '#' y las las muertas con un '0'.
2. El usuario tiene que poder elegir entre dos modos de juego:
   1. Modo Auto: 
      * El juego generará 'N' células otorgados por el usuario dispersadas de manera aleatoria por el tablero.
      * El juego no se detendrá nunca.
      * Tendrá un tablero por defecto de 10x10
    1. Modo Sandbox: 
       * El usuario tendrá que poder decidir todos los parámetros del juego, es decir, Dimensiones del tablero, iteraciones del juego, número de células y sus posiciones.
       * Opcional. Para simplificar esta operación se puede generar algún sistema de lectura de ficheros para que la partida cargue con dicha configuración.
