# Train Level Crossing Control with PowerDevs

## Descripción

Este proyecto implementa un sistema de control de paso a nivel para trenes utilizando PowerDevs. El objetivo es garantizar la seguridad en los cruces ferroviarios mediante la simulación y control de barreras automáticas.

## Características

- **Lenguajes Utilizados**: C++, Python
- **Frameworks**: PowerDevs

## Instalación

1. Clona el repositorio:
    ```sh
    git clone https://github.com/tu-usuario/train-level-crossing-control-with-powerdevs.git
    ```
2. Navega al directorio del proyecto:
    ```sh
    cd train-level-crossing-control-with-powerdevs
    ```
3. Crea un entorno virtual:
    ```sh
    python -m venv venv
    ```
4. Activa el entorno virtual:
    ```sh
    source venv/bin/activate
    ```
5. Instala las dependencias necesarias:
    ```sh
    pip install -r requirements.txt
    ```

## Uso

1. Reemplazar las carpetas de src/power-devs (atomic, examples, library) por sus respectivas carpetas en PowerDevs.
2. Una vez realizadas las simulaciones y haberlas guardado dentro de análisis-de-salidas/script/output con el formato 
"output-trainN" siendo N un número natural, ejecuta el script en Python:
    ```sh
    python main.py
    ```

## Estructura del Proyecto

- `src/`: Contiene el código fuente en C++ y Python.
- `docs/`: Documentación del proyecto.
- `README.md`: Este archivo.