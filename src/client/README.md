# Cliente de 4 en ralla

## Descripción

Este proyecto implementa la parte del cliente del juego 4 en ralla. El cliente se conecta a un servidor y permite a los jugadores interactuar con el juego enviando sus movimientos y recibiendo el estado actualizado del tablero.

## Estructura del Proyecto

```bash

project_root/
├── include/
│   └── common/
│       └── game_logic.h
├── src/
│   ├── common/
│   │   └── game_logic.cpp
│   ├── client/
│   │   ├── cliente.cpp
│   │   └── Makefile
│   │   └── README.md
├── build/

```

## Compilación

Para compilar el cliente, navega al directorio `src/client` y ejecuta el siguiente comando:

```sh
make
```

## Ejecución

Para ejecutar el cliente, navega al directorio `build` y ejecuta el siguiente comando:

```sh
./cliente <direccion IP> <puerto>
```

Por ejemplo:

```sh
./cliente 127.0.0.1 7777
```

## Limpieza

Para limpiar los archivos compilados, navega al directorio `src/client` y ejecuta el siguiente comando:

```sh
make clean
```

### Pasos para Compilar y Ejecutar

1. **Compilar el Cliente:**
   - Navega al directorio `src/client`:
     ```sh
     cd src/client
     ```
   - Compila el cliente:
     ```sh
     make
     ```

2. **Ejecutar el Cliente:**
   - Navega al directorio `build`:
     ```sh
     cd ../../build
     ```
   - Ejecuta el cliente:
     ```sh
     ./cliente 127.0.0.1 7777
     ```