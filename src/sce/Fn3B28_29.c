// COMPILER: ee-gcc2.9-991111
// Handwritten SDK routine reproduced as one inline asm body.

// FUNCTION: GAME 0x3B2850
void sceSifWriteBackDCache(void *p, int n)
{
    __asm__ volatile(".set noreorder\n\tlui $25,0xFFFF\n\tori $25,$25,0xFFC0\n\tblez $5,9f\n\taddu $10,$4,$5\n\tand $8,$4,$25\n\taddiu $10,$10,-1\n\tand $9,$10,$25\n\tsubu $10,$9,$8\n\tsrl $11,$10,6\n\taddiu $11,$11,1\n\tandi $9,$11,7\n\tbeqz $9,2f\n\tsrl $10,$11,3\n\t1:\n\tsync\n\tcache 0x18,0($8)\n\tsync\n\tnop\n\taddiu $9,$9,-1\n\tbgtz $9,1b\n\taddiu $8,$8,0x40\n\t2:\n\tbeqz $10,9f\n\t3:\n\taddiu $10,$10,-1\n\tsync\n\tcache 0x18,0($8)\n\tsync\n\tcache 0x18,64($8)\n\tsync\n\tcache 0x18,128($8)\n\tsync\n\tcache 0x18,192($8)\n\tsync\n\tcache 0x18,256($8)\n\tsync\n\tcache 0x18,320($8)\n\tsync\n\tcache 0x18,384($8)\n\tsync\n\tcache 0x18,448($8)\n\tsync\n\tbgtz $10,3b\n\taddiu $8,$8,0x200\n\t9:\n\t.set reorder");
}
