.table
int nro_GLOBAL_VARIABLE
int nro2_GLOBAL_VARIABLE
int nro_funcao_VARIABLE
float nro2_funcao_VARIABLE
int nro4_main_VARIABLE
int nro3_main_VARIABLE
.code
jump main
funcao:
pop nro_funcao_VARIABLE
inttofl $7, 2
mov nro2_funcao_VARIABLE, $7
fltoint $7, nro2_funcao_VARIABLE
add $0, $7, nro_funcao_VARIABLE
mov nro_funcao_VARIABLE, $0
println nro_funcao_VARIABLE
return
main:
mov nro3_main_VARIABLE, 5
mul $0, 5, 4
add $0, $0, nro3_main_VARIABLE
mov nro4_main_VARIABLE, $0
brz L0, 1
param nro4_main_VARIABLE
call funcao
L0:
nop
println nro4_main_VARIABLE
