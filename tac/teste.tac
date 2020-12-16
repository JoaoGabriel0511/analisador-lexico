.table
int i_main_VARIABLE
.code
jump main
main:
mov i_main_VARIABLE, 0
L0:
slt $0, 5, i_main_VARIABLE
brz L1, $0
println i_main_VARIABLE
add $0, 1, i_main_VARIABLE
mov i_main_VARIABLE, $0
jump L0
L1:
println
println i_main_VARIABLE
