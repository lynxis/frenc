.h8300s

.global _unused_isr
.global _rxi1_isr
.global _eri1_isr
.extern _rxi1_irq
.extern _eri1_irq
.section .text

_unused_isr:
  rte

_eri1_isr:
  jsr @_eri1_irq
  rte

_rxi1_isr:
  jsr @_rxi1_irq
  rte
  .end
