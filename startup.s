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

_start2:
        mov.l   #_data,er0              ; start of RAM .data section
        mov.l   #_edata,er1             ; end of RAM .data section
        mov.l   #_etext,er2             ; location of ROM .data storage
data_init_loop:
        mov.w   @er2,r3                 ; get next word
        mov.w   r3,@er0                 ; move it
        adds    #2,er2                  ; increment source ptr
        adds    #2,er0                  ; increment destination ptr
        cmp.l   er1,er0                 ; test for done
        blo     data_init_loop

; inti ram vectors
; ramvectors must be direct behind data. do not touch er2! it's used later when copying the ramvector into place
; first make sane vector values
ramvector_write_0xff:
        mov.l   #_ram_vectors,er0       ; start of RAM vectors
        mov.l   #_eram_vectors,er1      ; end of RAM vectors
        ; check if ram_vectors are empty and skip to bss_init
        cmp.l   er1, er0
        blo     bss_init_loop
ramvector_write_0xff_loop:
        mov.w   #0xffff, @er0
        adds    #2, er0
        cmp.l   er1,er0
        blo     ramvector_write_0xff_loop
        mov.l   #_ram_vectors,er0       ; reset er0 to start of RAM vectors
ramvector_copy_loop:
        mov.w   @er2,r3                 ; get next word
        mov.w   r3,@er0                 ; move it
        adds    #2,er2                  ; increment source ptr
        adds    #2,er0                  ; increment destination ptr
        cmp.l   er1,er0                 ; test for done
        blo     ramvector_copy_loop

; zero out .bss ram data area
        mov.l   #_bss,er0               ; start of RAM .bss section
        mov.l   #_ebss,er1              ; end of RAM .bss section
        mov.w   #0,r2
bss_init_loop:
        mov.w   r2,@er0                 ; clear memory
        adds    #2,er0                  ; increment ptr
        cmp.l   er1,er0                 ; test for done
        blo     bss_init_loop

; initialize stack area to 'DEAD' to track stack usage
        mov.l   #_stack_last,er0        ; beginning of RAM .stack section
        mov.l   #_stack_first,er1       ; end of RAM .stack section
        mov.w   #0xDEAD,r2              ; marker indicating unused stack
stack_init_loop:
        mov.w   r2,@er0                 ; store marker
        adds    #2,er0                  ; increment ptr
        cmp.l   er1,er0                 ; test for done
        blo     stack_init_loop

; call main
        jmp     @_main                  ; start the main() program
        .end
