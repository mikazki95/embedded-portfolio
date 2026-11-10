# Tonatiuh Velázquez Rojas
### Ingeniería de firmware para sistemas críticos

Ingeniero en mecatrónica (Puebla, México). 3–4 años escribiendo firmware que no puede fallar: dispositivos médicos de soporte vital, monitores de signos vitales y sistemas de control industrial.

Mi trabajo ha estado sobre todo en el límite del hardware: bring-up de tarjetas, control de periféricos a nivel de registro, tiempo real estricto, y depuración a nivel de bus cuando no había depurador disponible.

---

## Proyectos

| # | Proyecto | Qué muestra | Código |
|---|---|---|---|
| [01](01-ventilador/) | Ventilador neumático de soporte vital | Control de ciclo respiratorio con lazos de seguridad, en ensamblador | Propietario · disponible en entrevista |
| [02](02-arritmias-dbscan/) | Detección de arritmias con DBSCAN multietapa | Algoritmo de clustering adaptado a señal ECG en tiempo real | Extracto comentado |
| [03](03-fpga-metro/) | Banco de pruebas VHDL para bus de 16 bits | Verificación de un buffer de bus con `ALE`/`CS`/`RD`/`WR` | [`test_sistema_metro.vhd`](03-fpga-metro/test_sistema_metro.vhd) |
| [04](04-diagnostico/) | Herramientas de diagnóstico de hardware | Lectura/escritura de NOR flash de 256 Mbit desde AVR por USART | [`flash_rw_avr.c`](04-diagnostico/flash_rw_avr.c) |
| [05](05-driver-linux/) | Driver de plataforma Linux | `probe`/`remove`, device tree, `sysfs`, char device y `poll` | [`nxp_simtemp.c`](05-driver-linux/nxp_simtemp.c) |

---

## Qué vas a encontrar aquí, y qué no

**Sí:** código propio y descripciones técnicas de mi autoría.

**No:** código de producto de mis clientes, esquemáticos de fabricante ni mapas de memoria de equipos. Ese material es propiedad de terceros; puedo explicarlo y discutirlo en una entrevista.

La razón es simple: en dispositivos médicos la confidencialidad no es una formalidad, es parte del trabajo.

---

## Stack

`C` · `Ensamblador` · `VHDL` · `FreeRTOS` · `Linux embebido` (drivers, device tree) · `AM6442` / `ARM Cortex` · `UART` · `SPI` · `I²C` · `GPIO` · `MVB`

## Contacto

- Email: tonatiuh_vr95@hotmail.com
- GitHub: [@mikazki95](https://github.com/mikazki95)
