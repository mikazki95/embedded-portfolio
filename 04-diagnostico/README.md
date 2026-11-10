# 04 · Herramientas de diagnóstico de hardware

**Mi rol:** desarrollo completo de las utilidades · **Stack:** C, AVR, USART

## El problema

Sin herramientas del fabricante, caracterizar una tarjeta implica poder leer y escribir su memoria para comparar contra el diagrama: ¿el bus responde? ¿la flash conserva lo escrito? ¿la dirección mapea donde debería?

Las utilidades hacen eso desde una PC, enviando comandos por puerto serie a un microcontrolador AVR que ejecuta los ciclos de bus.

## Qué incluye

[`flash_rw_avr.c`](flash_rw_avr.c) — programador de NOR flash de 256 Mbit desde AVR:

| Función | Qué hace |
|---|---|
| `flash_read()` | Lectura de una palabra de 16 bits en una dirección de 24 bits |
| `flash_write()` | Escritura de palabra con su secuencia de comandos |
| `buffer_write()` | Escritura en ráfaga de 32 palabras, para no pagar el costo del comando por palabra |
| `flash_erase()` | Borrado por sector |
| `wait_ready()` | Sondeo del bit de estado en vez de esperar un tiempo fijo |
| `process_received_frame()` | Interpretación de las tramas que llegan por USART |

El detalle que importa es el manejo de la flash: la secuencia de comandos, el sondeo de estado y el tamaño de ráfaga son los que determinan si el grabado es correcto o silenciosamente corrupto.

## Nota

Los encabezados de bajo nivel (`USART0.h`, y el que define las secuencias del chip de flash) no se incluyen: describen el hardware concreto sobre el que se trabajó. El archivo se publica como referencia de la lógica de acceso, no como proyecto compilable tal cual.

## Qué mejoraría hoy

- Un checksum por bloque al final de cada ráfaga, para detectar corrupción en el momento y no al releer todo.
- Reintentos con retroceso ante fallo de `wait_ready()`: la flash puede tardar más de lo nominal y hoy es un fallo duro.
- Separar el protocolo serie del acceso a memoria, para poder probar la lógica de tramas sin hardware.
