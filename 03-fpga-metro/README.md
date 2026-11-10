# 03 · Banco de pruebas VHDL para un bus de 16 bits

**Mi rol:** verificación del buffer de bus en FPGA · **Stack:** VHDL, Xilinx ISE · **Contexto:** proyecto de sistema de metro (trabajo internacional)

## El problema

Antes de instrumentar la tarjeta, había que saber si el buffer bidireccional que adapta el bus del microcontrolador a los periféricos se comportaba como dice la especificación: direcciones estables con `ALE`, sentido correcto del buffer, y `CS`/`RD`/`WR` respetando tiempos.

Depurar eso sobre el hardware físico significa pinzar el bus a ciegas. El banco de pruebas permite ejercitar la lógica antes de tocar la tarjeta.

## Qué hace

[`test_sistema_metro.vhd`](test_sistema_metro.vhd) es un testbench que instancia el buffer (`BufferD15`) y le aplica estímulos sobre:

- `SEL_0..2`, `CS_0` — selección del periférico.
- `RD` / `WR` — sentido de la transferencia.
- `ALE_UC` — captura de dirección, y `A7` como bit de dirección.
- `X_0..3`, `IO_0..2` — líneas de datos y del bus externo.

Y verifica las salidas de control que el diseño genera a partir de eso: `DIR_BUF`, `EN_BUF`, `LE_INPDL`, `LE_OPDL`, `LE_OPDH`, `EN_INPDH`, `STATE_2`, `INT_RD`, `INT_WR`.

## Resultado

Permitió validar la secuencia de control del buffer contra la especificación del bus antes de integrarlo, y aislar el comportamiento del FPGA del resto de la cadena.

## Qué mejoraría hoy

- Convertir los estímulos en aserciones automáticas (`assert`) con mensaje de fallo, en vez de inspección visual de la forma de onda.
- Parametrizar los tiempos en constantes con nombre, para poder probar variantes del bus sin editar el banco.
