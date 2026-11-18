#ifndef COMFN19A_SHARED_H
#define COMFN19A_SHARED_H

// Constructors of map objects that own an array of 0x60-byte sub-records,
// each cleared with five zero quad stores and a flag reset.
extern "C" void func_0016F640(char *self, char v);
#define ZQ(p, o) __asm__ volatile("sqc2 $vf0," #o "(%0)" : : "r"(p) : "memory")
extern "C" void func_001BBEB8(void *self);
extern "C" void func_001C27E8(void *self);
extern "C" void func_001C7D98(void *self);
extern const char D_00425630[];
extern const char D_00425718[];
extern const char D_004258F0[];
extern const char D_004259D8[];
extern const char D_00425B90[];
extern const char D_00425C78[];
extern const char D_00425D48[];

extern "C" void func_001B6E90(void *self);
extern const char D_00423148[];
extern const char D_00423338[];
extern const char D_00423608[];
extern const char D_00423700[];
extern const char D_00425FB0[];
extern const char D_00426098[];
extern const char D_00426180[];
extern const char D_00426268[];
extern const char D_00426350[];
extern const char D_004294F0[];
extern const char D_00423230[];
extern const char D_00423400[];
extern const char D_004234E8[];
extern const char D_00423B88[];
extern const char D_00426438[];
extern const char D_00426520[];
extern const char D_00426608[];
extern const char D_004266F0[];
extern const char D_004268C8[];
extern const char D_004269B0[];
extern const char D_00426A98[];
extern const char D_00426B80[];
extern const char D_00426C68[];

extern const char D_00426D50[];

extern const char D_00427060[];

extern const char D_00427148[];

extern const char D_004284A0[];

extern const char D_00423078[];

extern const char D_004237E8[];

extern const char D_004238D8[];

extern const char D_004239C8[];

extern const char D_00423AB8[];

extern const char D_004267F8[];

extern const char D_00422F90[];

extern const char D_00423D40[];

extern const char D_00427690[];

extern "C" void *func_0019A998(char *self);
extern "C" void *func_0019AC18(char *self);
extern "C" void *func_0019BBB8(char *self);
extern "C" void *func_0019BE28(char *self);
extern "C" void *func_0019C320(char *self);
extern "C" void *func_0019C588(char *self);
extern "C" void *func_0019D340(char *self);
extern "C" void *func_0019D9C0(char *self);
extern "C" void *func_0019DC48(char *self);
extern "C" void *func_0019DED0(char *self);
extern "C" void *func_0019E1C0(char *self);
extern "C" void *func_0019E448(char *self);
extern "C" void *func_00187750(char *self);
extern "C" void *func_00187C88(char *self);
extern "C" void *func_00188F80(char *self);
extern "C" void *func_0018A598(char *self);
extern "C" void *func_001BDE50(char *self);
extern "C" void *func_001879C8(char *self);
extern "C" void *func_00188A68(char *self);
extern "C" void *func_00188CF8(char *self);
extern "C" void *func_0018EA10(char *self);
extern "C" void *func_0019E6C0(char *self);
extern "C" void *func_0019E938(char *self);
extern "C" void *func_0019EBB8(char *self);
extern "C" void *func_0019EE30(char *self);
extern "C" void *func_0019FEA8(char *self);
extern "C" void *func_001A0120(char *self);
extern "C" void *func_001A0390(char *self);
extern "C" void *func_001A0608(char *self);
extern "C" void *func_001A0880(char *self);
extern "C" void *func_001A0AF0(char *self);
extern "C" void *func_001A3A98(char *self);
extern "C" void *func_001A3D10(char *self);
extern "C" void *func_001B2220(char *self);
extern "C" void *func_00186998(char *self);
extern "C" void *func_0018B290(char *self);
extern "C" void *func_0018C098(char *self);
extern "C" void *func_0018CEA0(char *self);
extern "C" void *func_0018DC58(char *self);
extern "C" void *func_0019F0A8(char *self);
extern "C" void *func_00186738(char *self);
extern "C" void *func_0018EEA8(char *self);
extern "C" void *func_001A8150(char *self);

#endif
