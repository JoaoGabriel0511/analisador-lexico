.table
int i_main_VARIABLE[] = {0, 0}
.code
jump main
main:
mov $2, &i_main_VARIABLE
mov $2[0], 12
mov $2[1], 24
