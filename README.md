# Proyecto Final - Arquitectura de Computadores

## Parcial seleccionado

Parcial 2023-2

## Algoritmos implementados

### Algoritmo A
Transposición de matrices mediante recorrido fila-columna.

### Algoritmo B
Transposición de matrices utilizando tiling 2x2.

## Compilación

### Sin optimizaciones

g++ benchmark.cpp algoritmoA.cpp algoritmoB.cpp -O0 -o programa_O0

### Con optimizaciones

g++ benchmark.cpp algoritmoA.cpp algoritmoB.cpp -O3 -o programa_O3

## Ejecución

programa_O0.exe

programa_O3.exe

## Validación

Se verifica que la matriz obtenida sea la transpuesta correcta de la matriz original.

## Medición

Las mediciones se realizan utilizando std::chrono::high_resolution_clock.