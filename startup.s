; Startup Code for H8S 2161
; Original from Johan Henning
; Little modifications by Johann Gysin
; Very little modifications by Alexander Couzens
; 29.06.2015
;
        .h8300s
        .section .text
        .global _startp
        .global _startm

        .extern _etext                  ; ROM copy of initialized data segment
        .extern _data                   ; beginning of initialized data segment
        .extern _edata                  ; end of initialized data segment
        .extern _bss                    ; beginning of uninitialized data segment
        .extern _ebss                   ; end of uninitialised data segment
        .extern _stack                  ; stack segment

_startp:
; C runtime start from power-on reset
;        mov.w   #0x0001, r2
;        mov.l   #0x0000, er3
;        mov.w   r2, @er3         ; A value of 1 in po_reset will denote power-on-reset
;        jmp     _continue        ;

_startm:
;; C runtime start from manual reset
;        mov.w   #0x0000, r2
;        mov.l   #0x0000, er3
;        mov.w   r2, @er3         ; A value of 0 in po_reset will denote manual-reset

_continue:
; Set stack pointer
        mov.l   #_stack,sp

; call main
        jsr     @_init
        jmp     @_main
        .end
