.table
int a_main_VARIABLE
int b_main_VARIABLE
.code
jump main
main:
mov a_main_VARIABLE, 1
add $0, 2, a_main_VARIABLE
div $0, $0, 2
mov b_main_VARIABLE, $0
println a_main_VARIABLE
