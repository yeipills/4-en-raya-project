# Servidor de 4 en raya

## Descripción

Este proyecto implementa la parte del servidor del juego 4 en raya. El servidor maneja múltiples clientes concurrentemente, permitiendo que varios jugadores jueguen partidas independientes de 4 en raya al mismo tiempo.

## Estructura del Proyecto

```shell
    project_root/
    ├── include/
    │   └── common/
    │       └── game_logic.h
    ├── src/
    │   ├── common/
    │   │   └── game_logic.cpp
    │   ├── server/
    │   │   ├── servidor.cpp
    │   │   └── Makefile
    │   │   └── README.md
    ├── build/
```

## Compilación

Para compilar el servidor, navega al directorio `src/server` y ejecuta el siguiente comando:

```sh
make
```

## Ejecución

Para ejecutar el servidor, navega al directorio `build` y ejecuta el siguiente comando:

```sh
./servidor <puerto>
```

Por ejemplo:

```sh
./servidor 7777
```

## Limpieza

Para limpiar los archivos compilados, navega al directorio `src/server` y ejecuta el siguiente comando:

```sh
make clean
```

### Pasos para Compilar y Ejecutar

1. **Compilar el Servidor:**
   - Navega al directorio `src/server`:

     ```sh
     cd src/server
     ```

   - Compila el servidor:

     ```sh
     make
     ```

2. **Ejecutar el Servidor:**
   - Navega al directorio `build`:

     ```sh
     cd ../../build
     ```

   - Ejecuta el servidor:

     ```sh
     ./servidor 7777
