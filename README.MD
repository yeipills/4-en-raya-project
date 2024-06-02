# 4 en raya

## Descripción

Este proyecto implementa el juego "4 en raya" utilizando el modelo Cliente/Servidor. El servidor gestiona las conexiones de los clientes y controla el flujo del juego.

## Requisitos

- C++17
- pthreads

## Estructura del Proyecto

La estructura del proyecto es la siguiente:

```bash
project_root/
├── include/
│   └── common/
│       └── game_logic.h
├── src/
│   ├── common/
│   │   ├── game_logic.cpp
│   ├── server/
│   │   ├── servidor.cpp
│   │   ├── Makefile
│   │   └── README.md
│   └── client/
│       ├── cliente.cpp
│       ├── Makefile
│       └── README.md
├── build/
├── Makefile
└── README.md
```

## Compilación

Utilice el siguiente comando para compilar el proyecto:

```sh
make
```

## Ejecución

Primero, ejecute el servidor especificando el puerto:

```sh
./build/servidor <puerto>
```

Luego, ejecute el cliente especificando la IP del servidor y el puerto:

```sh
./build/cliente <IP del servidor> <puerto>
```

### Ejemplo

Para ejecutar el servidor en el puerto 7777:

```sh
./build/servidor 7777
```

Para conectar un cliente al servidor en la IP `127.0.0.1` y puerto `7777`:

```sh
./build/cliente 127.0.0.1 7777
```

## Uso

El cliente solicitará al usuario que ingrese una columna donde desea colocar su ficha. El servidor y el cliente alternarán los turnos hasta que haya un ganador o un empate.

## Funcionalidades

- **Servidor:**
  - Levantar servicio y esperar por conexiones.
  - Manejar múltiples conexiones simultáneamente.
  - Seleccionar al azar quién comienza el juego.
  - Solicitar y verificar las jugadas.
  - Enviar resultados a los clientes.
  - Mostrar estado de las conexiones y resultados en la terminal.

- **Cliente:**
  - Conectarse al servidor.
  - Visualizar el tablero.
  - Esperar por la indicación del servidor respecto de quién comienza.
  - Indicar columna donde dejar caer la ficha.
  - Visualizar el resultado.

## Documentación Adicional

Para más detalles sobre la compilación y ejecución del cliente y del servidor, consulte los siguientes documentos:

- [README del Servidor](src/server/README.md)
- [README del Cliente](src/client/README.md)

## Contribuciones

Las contribuciones son bienvenidas. Por favor, cree un fork del repositorio y realice un pull request con sus cambios.

# Servidor de 4 en raya

## Descripción

Este proyecto implementa la parte del servidor del juego 4 en raya. El servidor maneja múltiples clientes concurrentemente, permitiendo que varios jugadores jueguen partidas independientes de 4 en raya al mismo tiempo.

## Estructura del Proyecto

``` bash

project_root/
├── include/
│   └── common/
│       └── game_logic.h
├── src/
│   ├── common/
│   │   ├── game_logic.cpp
│   ├── server/
│   │   ├── servidor.cpp
│   │   ├── Makefile
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

# Cliente de 4 en raya

## Descripción

Este proyecto implementa la parte del cliente del juego 4 en raya. El cliente se conecta a un servidor y permite a los jugadores interactuar con el juego enviando sus movimientos y recibiendo el estado actualizado del tablero.

## Estructura del Proyecto

```bash

project_root/
├── include/
│   └── common/
│       └── game_logic.h
├── src/
│   ├── common/
│   │   ├── game_logic.cpp
│   ├── client/
│   │   ├── cliente.cpp
│   │   ├── Makefile
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
