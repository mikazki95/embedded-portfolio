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

## Cómo se arma

El proyecto es autocontenido: los dos encabezados que el fuente incluye están aquí.

- `USART0.h` — UART del AVR (conserva la cabecera de su autor original).
- `S29GL256P.h` — mapeo de pines del bus de memoria y constantes del chip.

Requisitos: `avr-gcc` con `avr-libc`, para **ATmega2560** a 14.7456 MHz.

```sh
avr-gcc -mmcu=atmega2560 -DF_CPU=14745600UL -Os -o flash_rw.elf flash_rw_avr.c
```

Esa frecuencia no es arbitraria: es la que fija el archivo en `F_CPU`, y a la que `UBRR0 = 7` entrega exactamente 115200 baudios, que es lo que espera el protocolo del lado de la PC.

> No compilé este proyecto en el entorno donde armé el repositorio (no había `avr-gcc` disponible), así que el build está pendiente de verificación.

## Qué mejoraría hoy

- Un checksum por bloque al final de cada ráfaga, para detectar corrupción en el momento y no al releer todo.
- Reintentos con retroceso ante fallo de `wait_ready()`: la flash puede tardar más de lo nominal y hoy es un fallo duro.
- Separar el protocolo serie del acceso a memoria, para poder probar la lógica de tramas sin hardware.
