/*Written by Hossam Eid
for lesson_3 lab_1 in
learn-in-detpth diploma*/
.global _reset


.section .vectors

.word 	0x20001000 /*Stack top*/
.word	_reset
.word 	Vector_handler 	
.word 	Vector_handler 	
.word 	Vector_handler 	
.word 	Vector_handler 	
.word 	Vector_handler 	
.word 	Vector_handler 	
.word 	Vector_handler 	
.word 	Vector_handler 	
.word 	Vector_handler 	
.word 	Vector_handler 	
.word 	Vector_handler 	

.section .text

_reset:
	b main
	b .

.thumb_func
	
Vector_handler:
	b _reset
