# 02 · Monitor de signos vitales: detección de arritmias

**Mi rol:** el monitor se desarrolló en equipo; el algoritmo de detección y su integración son míos · **Stack:** C, FreeRTOS, Linux embebido (AM6442)

## El problema

Clasificar 14 tipos de arritmia sobre la señal del monitor, en línea y sobre hardware embebido. El obstáculo no es detectar el latido: es que la morfología cambia entre pacientes, así que un umbral fijo falla en cuanto cambia la persona.

## El enfoque

En lugar de umbrales, agrupar los latidos por similitud morfológica y tratar la arritmia como una desviación del grupo dominante del propio paciente. Eso es lo que hace la calibración adaptativa: el patrón de referencia se construye con los latidos del paciente en curso.

El clustering es **multietapa**, y cada etapa usa una métrica distinta:

1. **Etapa 1 — vecindad restringida.** No basta con estar cerca en el plano: el vecino tiene que caer dentro de una ventana temporal acotada (`width_neigh`) además de dentro del radio `eps`. Así se evita que dos latidos morfológicamente parecidos pero muy separados en el tiempo se agrupen.
2. **Etapa 2 — euclídea.** Sobre el resultado de la primera, un agrupamiento clásico por distancia euclídea, que consolida los grupos y descarta el ruido.

El extracto incluido compara las dos métricas: `get_neighbors()` (etapa 1, con la ventana) y `get_neighbors_2()` (etapa 2, euclídea pura).

## Extracto

[`fragmento_dbscan.c`](fragmento_dbscan.c) — vecindad de ambas etapas, extraído del original con comentarios añadidos. El resto del archivo (adquisición, tareas FreeRTOS, protocolo serie y la tabla de las 14 arritmias) es propiedad del cliente.

## Resultado

Detección de las 14 arritmias en línea sobre AM6442, con calibración por paciente en lugar de umbrales fijos.

## Qué mejoraría hoy

- **Repartir el pipeline entre los dos núcleos del AM6442.** Hoy corren dos núcleos pero sin comunicación entre ellos: el procesamiento vive en uno solo y el segundo no aporta a esta tarea. Un esquema de IPC bien delimitado (un núcleo adquiere, otro clasifica) sería el cambio de mayor impacto.
- Versionar un conjunto de pruebas con señales sintéticas de cada arritmia, para medir sensibilidad y especificidad por tipo.
- Sacar el algoritmo a un módulo con interfaz pura (entra señal, sale clasificación), sin las tareas de RTOS alrededor.
- Medir el costo por etapa: el clustering es lo caro, y conviene saber cuánto de eso es la métrica y cuánto la iteración.
