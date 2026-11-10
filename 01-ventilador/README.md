# 01 · Ventilador neumático de soporte vital

**Mi rol:** firmware de control del ciclo (en equipo) y diseño de la parte neumática · **Duración:** ~1.5 años · **Stack:** ensamblador

## El problema

Un ventilador neumático de soporte vital tiene que entregar el ciclo respiratorio de forma repetible, y detectar y reaccionar cuando no puede hacerlo. El firmware es el último responsable de que eso ocurra: si el ciclo se desvía, el equipo tiene que alarmar, no improvisar.

## Restricciones

- Microcontrolador de 8 bits, sin unidad de punto flotante y con RAM muy limitada.
- Ensamblador puro: cada ciclo de instrucción cuenta para sostener el lazo de tiempo real.
- Comportamiento determinista: las rutinas de seguridad no pueden depender de cuánto tarde otra tarea.
- El equipo forma parte de un ecosistema mayor, así que el firmware tenía que respetar interfaces ya fijadas por el resto del sistema.

## Qué hice

- Máquina de estados del ciclo respiratorio, temporizada por interrupciones.
- Control de válvulas y lectura de sensores dentro del lazo de tiempo real.
- Diseño de la parte neumática del equipo: trayectorias de aire, válvulas y sensores. El firmware y el circuito neumático se diseñaron juntos, no uno después del otro.
- Rutinas de seguridad y alarmas: detección de condiciones fuera de rango y paso a estado seguro.
- Integración con el resto del ecosistema del equipo.

## Resultado

El equipo quedó funcional a nivel de prototipo; no llegó a comercializarse. El ciclo y las rutinas de seguridad operaban de forma estable sobre el hardware objetivo.

## Qué mejoraría hoy

- Separar la lógica de control en capas testeables, para poder probar la máquina de estados sin hardware.
- Un simulador de ciclo que permita reproducir fallos de sensor sin instrumentar el equipo.
- Documentar los presupuestos de tiempo por bloque, que hoy viven solo en el código.

---

> El código es propiedad del cliente y no se publica. Puedo recorrer la arquitectura y las decisiones de diseño en una entrevista.
