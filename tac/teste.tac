.table
int a_main_VARIABLE
int b_main_VARIABLE
int c_main_VARIABLE
.code
jump main
main:
add $0, 3, 2
sub $0, $0, 2
mul $0, $0, 7
div $0, $0, 2
mov a_main_VARIABLE, $0
add $0, 5, a_main_VARIABLE
mov b_main_VARIABLE, $0
add $0, b_main_VARIABLE, a_main_VARIABLE
mov c_main_VARIABLE, $0
println a_main_VARIABLE
println 3
println b_main_VARIABLE
