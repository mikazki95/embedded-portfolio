# 03 · Remanufactura de equipos ferroviarios sin documentación

**Mi rol:** diagnóstico, reconstrucción de esquemático e ingeniería inversa · **Resultado:** 3 equipos devueltos a servicio

## El problema

Equipos de una línea ferroviaria fuera de servicio. Sin documentación técnica: ni esquemático, ni manual de servicio, ni soporte del fabricante. Tres unidades para recuperar, y sin plano no hay forma de saber qué está mal ni dónde buscarlo.

## El método

1. **Reconocimiento sobre la placa.** Identificar componentes, mapear qué está conectado con qué y formar una hipótesis del bus antes de tocar nada.
2. **Reconstrucción del esquemático por rastreo de señales.** No adivinando: midiendo continuidad y respuesta, y confirmando cada hipótesis con una prueba concreta. El esquemático se dibuja a medida que se comprueba, no antes.
3. **Un entorno de diagnóstico propio.** En lugar de la interfaz gráfica del equipo —que no sirve para esto—, un sistema mínimo dedicado a ejercitar la tarjeta: memoria, buses y periféricos, reportando qué falla y en qué dirección.
4. **Pruebas por etapas, de dentro hacia afuera.** Primero lo más cercano al microcontrolador, después la periferia. Si se prueba todo a la vez, se persiguen dos fallas simultáneas y ninguna se aísla.

## Resultado

- **3 equipos reparados y devueltos a servicio.**
- **Esquemático reconstruido** de la tarjeta, que no existía.
- Herramientas de diagnóstico reutilizables para las siguientes unidades, no un arreglo puntual.

Las utilidades de lectura y escritura de memoria que salieron de este trabajo están en [05 · Diagnóstico](../05-diagnostico/).

## En curso

Ingeniería inversa del firmware del microcontrolador H8 del equipo, para evaluar la lógica y no solo el hardware. Entender qué espera el software del resto de la tarjeta permite diagnosticar fallas que eléctricamente se ven correctas: el bus responde, los voltajes están bien, y aun así el equipo no opera.

## Por qué esto importa más de lo que parece

Diagnosticar sin documentación no es reparar: es reconstruir un sistema a partir de su comportamiento observable, sabiendo en cada momento si una hipótesis está confirmada o solo es plausible. Ese criterio —distinguir lo probado de lo supuesto— es el mismo que separa un diagnóstico de una corazonada, y aplica igual a un tablero de ferrocarril que a cualquier sistema complejo.

## Qué no se publica

Esquemáticos, mapas de memoria y el firmware analizado son propiedad del cliente. Lo que se puede mostrar es el método y las herramientas propias.
