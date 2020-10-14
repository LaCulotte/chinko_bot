// le résultat d'une Expression est dans HL pour un naturel, OP1 pour un réel

#define _ASM_IF \
"%s\n\
	ld de,0\n\
	or a\n\
	sbc hl,de\n\
	jp z,endif%d\n\
%s\n\
endif%d:"

#define _ASM_IFELSE \
"%s\n\
	ld de,0\n\
	or a\n\
	sbc hl,de\n\
	jp z,else%d\n\
%s\n\
	jp endif%d\n\
else%d:\n\
%s\n\
endif%d:"

#define _ASM_WHILE \
"%s\n\
	ld de,0\n\
	or a\n\
	sbc hl,de\n\
	jp z,endwhile%d\n\
%s\n\
endwhile%d:"

#define _ASM_ASSIGN \
"%s\n\
	ld (pixelshadow+%d),hl"

#define _ASM_PRINT \
"	ld hl,(pixelshadow+%d)\n\
	call _dispHL"


/* EXPRESSIONS */

#define _ASM_EQUAL \
"%s\n\
	push hl\n\
%s\n\
	pop de\n\
	or a\n\
	sbc hl,de\n\
	inc hl\n\
	jr z,+_\n\
	or a\n\
	sbc hl,hl\n\
_:"

#define _ASM_NEQUAL \
"%s\n\
	push hl\n\
%s\n\
	pop de\n\
	or a\n\
	sbc hl,de\n\
	jr z,+_\n\
	ld hl,1\n\
_:"

#define _ASM_GT \
"%s\n\
	push hl\n\
%s\n\
	pop de\n\
	or a\n\
	sbc hl,de\n\
	ld hl,0\n\
	jr c,+_\n\
	jr z,+_\n\
	inc hl\n\
_:"

#define _ASM_LT \
"%s\n\
	push hl\n\
%s\n\
	pop de\n\
	or a\n\
	sbc hl,de\n\
	ld hl,0\n\
	jr nc,+_\n\
	inc hl\n\
_:"

#define _ASM_GTEQ \
"%s\n\
	push hl\n\
%s\n\
	pop de\n\
	or a\n\
	sbc hl,de\n\
	ld hl,1\n\
	jr nc,+_\n\
	dec hl\n\
_:"

#define _ASM_LTEQ \
"%s\n\
	push hl\n\
%s\n\
	pop de\n\
	or a\n\
	sbc hl,de\n\
	ld hl,1\n\
	jr c,+_\n\
	jr z,+_\n\
	dec hl\n\
_:"

#define _ASM_ADDSUB \
"%s\n\
	push hl\n\
%s\n\
	pop de\n\
	%s hl,de"

// VERFIER QUE LES ENTREES -> SORTIE DE IMULU SONT BIEN HL ET BC -> HL
#define _ASM_MULT \
"%s\n\
	push hl\n\
%s\n\
	pop bc\n\
	call __imulu"

#define _ASM_DIV \
"%s\n\
	push hl\n\
%s\n\
	pop bc\n\
	call __idivs"

#define _ASM_LOADNAT \
"	ld hl,%d"

#define _ASM_LOADVAR \
"	ld hl,(pixelshadow+%d)"
