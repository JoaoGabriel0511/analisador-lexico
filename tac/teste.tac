.table
int a_func_VARIABLE
int a_main_VARIABLE
.code
jump main
func:
pop a_func_VARIABLE
println a_func_VARIABLE
return
main:
mov a_main_VARIABLE, 2
call func
println a_main_VARIABLE
return
