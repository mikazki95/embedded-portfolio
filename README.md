# Tonatiuh Velázquez Rojas
### Ingeniería de firmware para sistemas críticos

Ingeniero en mecatrónica (Puebla, México). 3–4 años escribiendo firmware que no puede fallar: dispositivos médicos de soporte vital, monitores de signos vitales y equipos de control industrial.

Mi trabajo ha estado sobre todo en el límite del hardware: bring-up de tarjetas, control de periféricos a nivel de registro, tiempo real estricto, y depuración a nivel de bus cuando no había depurador disponible.

---

## Proyectos

| # | Proyecto | Qué muestra | Código |
|---|---|---|---|
| [01](01-ventilador/) | Ventilador neumático de soporte vital | Control del ciclo respiratorio con lazos de seguridad, en ensamblador | Propietario · disponible en entrevista |
| [02](02-monitor-vitales/) | Monitor de signos vitales | Detección de 14 arritmias con DBSCAN adaptado a la señal ECG | Extracto comentado |
| [03](03-remanufactura/) | Remanufactura de equipos ferroviarios | Reconstrucción de esquemático sin documentación y diagnóstico propio | Caso de estudio · 3 equipos operando (lote de 9) |
| [04](04-fpga-metro/) | Banco de pruebas VHDL para bus de 16 bits | Verificación de un buffer de bus con `ALE`/`CS`/`RD`/`WR` | [`test_sistema_metro.vhd`](04-fpga-metro/test_sistema_metro.vhd) |
| [05](05-diagnostico/) | Herramientas de diagnóstico de hardware | Lectura/escritura de NOR flash de 256 Mbit desde AVR por USART | [`flash_rw_avr.c`](05-diagnostico/flash_rw_avr.c) |
| [06](06-driver-linux/) | Driver de plataforma Linux | `probe`/`remove`, device tree, `sysfs`, char device y `poll` | [`nxp_simtemp.c`](06-driver-linux/nxp_simtemp.c) |

---

## Cómo trabajo

Lo que aparece en 01, 02 y 03 tiene algo en común: **el sistema no venía con instrucciones**. Un dispositivo médico sin margen de error, una señal fisiológica que cambia con cada paciente, y una tarjeta ferroviaria sin esquemático ni soporte del fabricante.

Eso obliga a un método más que a una herramienta: formar hipótesis, instrumentar, comprobar, y no dar por cierto lo que solo es plausible. El caso de [remanufactura](03-remanufactura/) es el más claro: sin plano, el diagnóstico es una reconstrucción del sistema a partir de cómo se comporta.

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
