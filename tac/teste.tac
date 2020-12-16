.table
int i_main_VARIABLE
int j_main_VARIABLE
.code
jump main
main:
mov i_main_VARIABLE, 5
scani j_main_VARIABLE
add $0, j_main_VARIABLE, i_main_VARIABLE
println $0
