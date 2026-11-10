# 06 · Driver de plataforma Linux

**Mi rol:** implementación completa · **Stack:** C, kernel Linux (platform driver, device tree, sysfs)

## El problema

Un sensor de temperatura simulado, expuesto al espacio de usuario como un dispositivo de caracteres, configurable desde device tree y observable por `sysfs`. El ejercicio está pensado para recorrer el modelo de drivers de Linux completo, no un `hello world` de módulo.

## Qué implementa

[`nxp_simtemp.c`](nxp_simtemp.c) — driver de plataforma con:

- **Registro como platform driver** con tabla `of_device_id` (`nxp,simtemp`) y `MODULE_DEVICE_TABLE`.
- **Lectura de configuración desde device tree**: `temp-base`, `amplitude`, `frequency`, `alarm-high`, `alarm-low`, `update-interval`.
- **Char device** con `file_operations`: `open`, `release`, `read`, `poll`.
- **`poll()` real**: el proceso de usuario puede bloquearse esperando muestra nueva en vez de hacer sondeo.
- **`sysfs`**: `temperature` (solo lectura), y `threshold_high`, `threshold_low`, `sampling_ms`, `amplitude`, `base_temp`, `frequency` (lectura/escritura) mediante `DEVICE_ATTR_RO` / `DEVICE_ATTR_RW`.
- **Generación periódica** de la muestra con temporizador del kernel y cálculo de la señal dentro del driver.
- **Rutas de error** en `init`: `goto` con etiquetas que deshacen en orden inverso lo ya creado.

## Por qué está aquí

Es la pieza que muestra el modelo de kernel sin depender de hardware ni de un cliente: se puede leer de principio a fin y discutir cada decisión (por qué `poll` y no busy-wait, por qué sysfs y no `ioctl`, cómo se maneja el buffer entre contexto de interrupción y de usuario).

## Qué mejoraría

- Un `kfifo` real para la cola de muestras: hoy `read()` sirve la última, así que dos lectores rápidos pueden perder muestras.
- Devolver `-EAGAIN` correctamente en modo no bloqueante, que es el caso que más se rompe en drivers de este tipo.
- Pruebas con `kunit` para el cálculo de la señal, que es lógica pura y no necesita kernel vivo.
