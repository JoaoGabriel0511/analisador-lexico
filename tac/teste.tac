.table
int a_main_VARIABLE
.code
jump main
main:
and $0, 0, 1
mov a_main_VARIABLE, $0
brz L0, a_main_VARIABLE
println 'T'
jump L1
L0:
println 'F'
L1:
println
