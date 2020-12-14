.table
float a_main_VARIABLE
float b_main_VARIABLE
float c_main_VARIABLE
.code
jump main
main:
add $0, 3.5, 2.1
sub $0, $0, 2.2
mul $0, $0, 7.4
div $0, $0, 2.0
mov a_main_VARIABLE, $0
add $0, 5.3, a_main_VARIABLE
mov b_main_VARIABLE, $0
add $0, b_main_VARIABLE, a_main_VARIABLE
mov c_main_VARIABLE, $0
println a_main_VARIABLE
println 3
println b_main_VARIABLE
println c_main_VARIABLE
