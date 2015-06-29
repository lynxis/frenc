         .h8300s

         ; shadow vector table location
         .global _unused_isr

         .section .text


 _unused_isr:                            ; Unused interrupt vector: generate
                                         ; an error if this interrupt occurs
         rte


         .end
