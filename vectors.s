; Vector Table for H8S/2633
; Johann Gysin
; 18.06.2002

        .h8300s
        .section        .vectors
        .global         _vector_table

      _vector_table:
        .long _startp            ;  0 Power-On Reset
        .long _startm            ;  1 Manual Reset
        .long _unused_isr        ;  2 Reserved
        .long _unused_isr        ;  3 Reserved
        .long _unused_isr        ;  4 Reserved
        .long _unused_isr        ;  5 Trace
        .long _unused_isr        ;  6 Reserved
        .long _unused_isr        ;  7 External Interrupt (NMI)
        .long _unused_isr        ;  8 Trap Instruction A 0
        .long _unused_isr        ;  9 Trap Instruction A 1
        .long _unused_isr        ; 10 Trap Instruction A 2
        .long _unused_isr        ; 11 Trap Instruction A 3
        .long _unused_isr        ; 12 Trap Instruction A 4
        .long _unused_isr        ; 13 Trap Instruction A 5
        .long _unused_isr        ; 14 Trap Instruction A 6
        .long _unused_isr        ; 15 Trap Instruction A 7
        .long _unused_isr        ; 16 IRQ0 (External Pin)
        .long _unused_isr        ; 17 IRQ1 (External Pin)
        .long _unused_isr        ; 18 IRQ2 (External Pin)
        .long _unused_isr        ; 19 IRQ3 (External Pin)
        .long _unused_isr        ; 20 IRQ4 (External Pin)
        .long _unused_isr        ; 21 IRQ5 (External Pin)
        .long _unused_isr        ; 22 IRQ6 (External Pin)
        .long _unused_isr        ; 23 IRQ7 (External Pin)
        .long _unused_isr        ; 24 SWDTEND Software Activation Interrupt End (DTC)
        .long _unused_isr        ; 25 WOVI0 Interval Timer (Watchdog Timer 0)
        .long _unused_isr        ; 26 CMI Refresh Timer
        .long _unused_isr        ; 27 PC Break
        .long _unused_isr        ; 28 ADI A/D Conversion End
        .long _unused_isr        ; 29 WOVI1 Interval Timer (Watchdog Timer 1)
        .long _unused_isr        ; 30 Reserved
        .long _unused_isr        ; 31 Reserved
        .long _unused_isr        ; 32 TGI0A TGR0A Input Capture/Compare Match (TPU Channel 0)
        .long _unused_isr        ; 33 TGI0B TGR0B Input Capture/Compare Match (TPU Channel 0)
        .long _unused_isr        ; 34 TGI0C TGR0C Input Capture/Compare Match (TPU Channel 0)
        .long _unused_isr        ; 35 TGI0D TGR0D Input Capture/Compare Match (TPU Channel 0)
        .long _unused_isr        ; 36 TCI0V Overflow 0 (TPU Channel 0)
        .long _unused_isr        ; 37 Reserved
        .long _unused_isr        ; 38 Reserved
        .long _unused_isr        ; 39 Reserved
        .long _unused_isr        ; 40 TGI1A TGR1A Input Capture/Compare Match (TPU Channel 1)
        .long _unused_isr        ; 41 TGI1B TGR1B Input Capture/Compare Match (TPU Channel 1)
        .long _unused_isr        ; 42 TCI1V Overflow 1 (TPU Channel 1)
        .long _unused_isr        ; 43 TCI1U Underflow 1 (TPU Channel 1)
        .long _unused_isr        ; 44 TGI2A TGR2A Input Capture/Compare Match (TPU Channel 2)
        .long _unused_isr        ; 45 TGI2B TGR2B Input Capture/Compare Match (TPU Channel 2)
        .long _unused_isr        ; 46 TCI2V Overflow 2 (TPU Channel 2)
        .long _unused_isr        ; 47 TCI2U Underflow 2 (TPU Channel 2)
        .long _unused_isr        ; 48 TGI3A TGR3A Input Capture/Compare Match (TPU Channel 3)
        .long _unused_isr        ; 49 TGI3B TGR3B Input Capture/Compare Match (TPU Channel 3)
        .long _unused_isr        ; 50 TGI3C TGR3C Input Capture/Compare Match (TPU Channel 3)
        .long _unused_isr        ; 51 TGI3D TGR3D Input Capture/Compare Match (TPU Channel 3)
        .long _unused_isr        ; 52 TCI3V Overflow 3 (TPU Channel 3)
        .long _unused_isr        ; 53 Reserved
        .long _unused_isr        ; 54 Reserved
        .long _unused_isr        ; 55 Reserved
        .long _unused_isr        ; 56 TGI4A TGR4A Input Capture/Compare Match (TPU Channel 4)
        .long _unused_isr        ; 57 TGI4B TGR4B Input Capture/Compare Match (TPU Channel 4)
        .long _unused_isr        ; 58 TCI4V Overflow 4 (TPU Channel 4)
        .long _unused_isr        ; 59 TCI4U Underflow 4 (TPU Channel 4)
        .long _unused_isr        ; 60 TGI5A TGR5A Input Capture/Compare Match (TPU Channel 5)
        .long _unused_isr        ; 61 TGI5B TGR5B Input Capture/Compare Match (TPU Channel 5)
        .long _unused_isr        ; 62 TCI5V Overflow 5 (TPU Channel 5)
        .long _unused_isr        ; 63 TCI5U Underflow 5 (TPU Channel 5)
        .long _unused_isr        ; 64 CMIA0 Compare Match A0 (8-Bit Timer Channel 0)
        .long _unused_isr        ; 65 CMIB0 Compare Match B0 (8-Bit Timer Channel 0)
        .long _unused_isr        ; 66 OVI0 Overflow 0 (8-Bit Timer Channel 0)
        .long _unused_isr        ; 67 Reserved
        .long _unused_isr        ; 68 CMIA1 Compare Match A1 (8-Bit Timer Channel 1)
        .long _unused_isr        ; 69 CMIB1 Compare Match B1 (8-Bit Timer Channel 1)
        .long _unused_isr        ; 70 OVI1 Overflow 1 (8-Bit Timer Channel 1)
        .long _unused_isr        ; 71 Reserved
        .long _unused_isr        ; 72 DED0A Channel 0 / Channel 0A Transfer End (DMAC)
        .long _unused_isr        ; 73 DEND0B Channel 0B Transfer End (DMAC)
        .long _unused_isr        ; 74 DEND1A Channel 1 / Channel 1A Transfer End (DMAC)
        .long _unused_isr        ; 75 DEND1B Channel 1B Transfer End (DMAC)
        .long _unused_isr        ; 76 Reserved
        .long _unused_isr        ; 77 Reserved
        .long _unused_isr        ; 78 Reserved
        .long _unused_isr        ; 79 Reserved
        .long _unused_isr        ; 80 ERI0 Receive Error 0 (SCI Channel 0)
        .long _unused_isr        ; 81 RXI0 Reception Completed 0 (SCI Channel 0)
        .long _unused_isr        ; 82 TXI0 Transmit Data Empty 0 (SCI Channel 0)
        .long _unused_isr        ; 83 TEI0 Transmission End 0 (SCI Channel 0)
        .long eri1_irq           ; 84 ERI1 Receive Error 1 (SCI Channel 1)
        .long rxi1_irq           ; 85 RXI1 Reception Completed 1 (SCI Channel 1)
        .long _unused_isr        ; 86 TXI1 Transmit Data Empty 1 (SCI Channel 1)
        .long _unused_isr        ; 87 TEI1 Transmission End 1 (SCI Channel 1)
        .long _unused_isr        ; 88 ERI2 Receive Error 2 (SCI Channel 2)
        .long _unused_isr        ; 89 RXI2 Reception Completed 2 (SCI Channel 2)
        .long _unused_isr        ; 90 TXI2 Transmit Data Empty 2 (SCI Channel 2)
        .long _unused_isr        ; 91 TEI2 Transmission End 2 (SCI Channel 2)
        .long _unused_isr        ; 92 CMIA0 Compare Match A2 (8-Bit Timer Channel 2)
        .long _unused_isr        ; 93 CMIB0 Compare Match B2 (8-Bit Timer Channel 2)
        .long _unused_isr        ; 94 OVI0 Overflow 2 (8-Bit Timer Channel 2)
        .long _unused_isr        ; 95 Reserved
        .long _unused_isr        ; 96 CMIA1 Compare Match A3 (8-Bit Timer Channel 3)
        .long _unused_isr        ; 97 CMIB1 Compare Match B3 (8-Bit Timer Channel 3)
        .long _unused_isr        ; 98 OVI1 Overflow 3 (8-Bit Timer Channel 3)
        .long _unused_isr        ; 99 Reserved
        .long _unused_isr        ;100 IICI0 1 Byte Transmission/Reception Completed (IIC Channel 0) Optional
        .long _unused_isr        ;101 DDCSW1 Format Switch (IIC Channel 0) Optional
        .long _unused_isr        ;102 IICI1 1 Byte Transmission/Reception Completed (IIC Channel 1) Optional
        .long _unused_isr        ;103 Reserved
        .long _unused_isr        ;104 Reserved
        .long _unused_isr        ;105 Reserved
        .long _unused_isr        ;106 Reserved
        .long _unused_isr        ;107 Reserved
        .long _unused_isr        ;108 Reserved
        .long _unused_isr        ;109 Reserved
        .long _unused_isr        ;110 Reserved
        .long _unused_isr        ;111 Reserved
        .long _unused_isr        ;112 Reserved
        .long _unused_isr        ;113 Reserved
        .long _unused_isr        ;114 Reserved
        .long _unused_isr        ;115 Reserved
        .long _unused_isr        ;116 Reserved
        .long _unused_isr        ;117 Reserved
        .long _unused_isr        ;118 Reserved
        .long _unused_isr        ;119 Reserved
        .long _unused_isr        ;120 ERI3 Reception Error 3 (SCI Channel 3)
        .long _unused_isr        ;121 RXI3 Reception Completed 3 (SCI Channel 3)
        .long _unused_isr        ;122 TXI3 Transmission Data Empty 3 (SCI Channel 3)
        .long _unused_isr        ;123 TEI3 Transmission End 3 (SCI Channel 3)
        .long _unused_isr        ;124 ERI4 Reception Error 4 (SCI Channel 4)
        .long _unused_isr        ;125 RXI4 Reception Completed 4 (SCI Channel 4)
        .long _unused_isr        ;126 TXI4 Transmission Data Empty 4 (SCI Channel 4)
        .long _unused_isr        ;127 TEI4 Transmission End 4 (SCI Channel 4)

        .end
