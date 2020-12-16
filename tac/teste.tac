.table
int i_main_VARIABLE
.code
jump main
main:
mov i_main_VARIABLE, 5
L0:
brz L1
println i_main_VARIABLE
add $0, 1, i_main_VARIABLE
mov i_main_VARIABLE, $0
jump L0
L1:
println
println i_main_VARIABLE
