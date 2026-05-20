========================================================================
   PROYECTO: INTÉRPRETE DE COMANDOS SIMPLE (MYSHELL) - TALLER 1
========================================================================
Asignatura: Sistemas Operativos (2026)
Profesor: Juan Felipe González Saavedra

Integrantes:

- Benjamín Campos
- Matías Rodríguez
- Lester Sáez
- Franco Sepúlveda

------------------------------------------------------------------------
1. REQUISITOS DEL SISTEMA
------------------------------------------------------------------------
- Sistema Operativo: GNU/Linux.
- Compilador: GCC (GNU Compiler Collection).

------------------------------------------------------------------------
2. INSTRUCCIONES DE COMPILACIÓN
------------------------------------------------------------------------
Abra una terminal en la raíz del directorio donde se encuentra el archivo 
'Taller1.c' y ejecute el siguiente comando para generar el binario ejecutable:

$ gcc -Wall Taller1.c -o myshell

* Nota: El parámetro '-Wall' activa todas las advertencias del compilador 
  para asegurar un código limpio.

------------------------------------------------------------------------
3. INSTRUCCIONES DE EJECUCIÓN
------------------------------------------------------------------------
Una vez compilado el programa sin errores, puede iniciar la shell ejecutando:

$ ./myshell

------------------------------------------------------------------------
4. COMANDOS SOPORTADOS
------------------------------------------------------------------------
A. Comando Interno:
   - exit : Finaliza la ejecución de myshell de forma limpia y ordenada.

B. Comandos Externos (en Foreground):
   Soporta cualquier comando estándar disponible en el PATH del sistema operativo
   Linux, incluyendo argumentos indeterminados separados por espacios.
   Ejemplos de uso:
   - myshell> ls
   - myshell> ls -la /home
   - myshell> pwd
   - myshell> clear
   - myshell> mkdir carpeta_prueba
========================================================================
