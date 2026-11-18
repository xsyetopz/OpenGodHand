/* `ld -r` script for objdiff's per-group objects. BFD crashes while merging
   the ECOFF `.mdebug` debug sections that the SN compiler emits, and objdiff
   does not read them. */
SECTIONS { /DISCARD/ : { *(.mdebug*) } }
