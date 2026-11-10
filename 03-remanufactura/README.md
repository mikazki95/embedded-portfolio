# 03 · Remanufactura de monitores de tren ligero sin documentación

**Mi rol:** diagnóstico, reconstrucción de esquemático e ingeniería inversa · **Duración:** 8 meses · **Estado:** 3 equipos operando, en validación

## El problema

Monitores de un tren ligero, fuera de servicio. Sin documentación de ningún tipo: ni esquemático, ni manual de servicio, ni soporte del fabricante. De un lote de 9 unidades, el cliente entregó 3 como primera prueba; las otras 6 quedaron almacenadas y solo se liberan conforme se valida el trabajo.

## El método

1. **Reconocimiento sobre la placa.** Identificar componentes, mapear qué está conectado con qué y formar una hipótesis del bus antes de tocar nada.
2. **Reconstrucción del esquemático por rastreo de señales.** No adivinando: midiendo continuidad y respuesta, y confirmando cada hipótesis con una prueba concreta. El esquemático se dibuja a medida que se comprueba, no antes.
3. **Un entorno de diagnóstico propio.** En lugar de la interfaz gráfica del equipo —que no sirve para esto—, un sistema mínimo dedicado a ejercitar la tarjeta: memoria, buses y periféricos, reportando qué falla y en qué dirección.
4. **Pruebas por etapas, de dentro hacia afuera.** Primero lo más cercano al microcontrolador, después la periferia. Si se prueba todo a la vez, se persiguen dos fallas simultáneas y ninguna se aísla.

## Resultado

- **3 de 3 unidades entregadas operando: el 100% de la primera entrega.** El lote completo es de 9 y el cliente libera el resto conforme valida el trabajo.
- **Esquemático reconstruido** de la tarjeta, que no existía.
- Herramientas de diagnóstico reutilizables para las siguientes unidades: no un arreglo puntual, sino un proceso repetible.
- **Validación en curso:** una unidad probada sobre el tren detenido, y una semana de operación en servicio programada como prueba final.

## El detalle que costó más

Para cerrar el diagnóstico hacía falta el firmware del microcontrolador H8, pero no se autorizó extraerlo de una unidad en operación. La única vía legítima fue leerlo de las tarjetas dadas de baja: de **6 equipos inservibles se recuperaron los 2 firmwares** que hacían falta.

## En curso

Análisis del firmware del H8 recuperado, para evaluar la lógica y no solo el hardware. Entender qué espera el software del resto de la tarjeta permite diagnosticar fallas que eléctricamente se ven correctas: el bus responde, los voltajes están bien, y aun así el equipo no opera.

## Por qué esto importa más de lo que parece

Diagnosticar sin documentación no es reparar: es reconstruir un sistema a partir de su comportamiento observable, sabiendo en cada momento si una hipótesis está confirmada o solo es plausible. Ese criterio —distinguir lo probado de lo supuesto— es el mismo que separa un diagnóstico de una corazonada, y aplica igual a un tablero de ferrocarril que a cualquier sistema complejo.

## Qué no se publica

Esquemáticos, mapas de memoria y el firmware analizado son propiedad del cliente. Lo que se puede mostrar es el método y las herramientas propias.
