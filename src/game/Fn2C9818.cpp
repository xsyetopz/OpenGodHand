extern "C" int getSkill__9cCoreSave8PL_SKILL(void *, int);
extern "C" void setSkill__9cCoreSave8PL_SKILLSc(void *, int, int);
extern char CoreSave[];

struct SkillTbl {
    char *tbl;
    char _p[0x10];
    signed char list[1];
};

// FUNCTION: GAME 0x2C9818
extern "C" void func_002C9818(SkillTbl *self, int skill, int *count, unsigned mask, unsigned char want)
{
    if (*(unsigned *)(self->tbl + skill * 0x24 + 0xC) & 1) {
        if (getSkill__9cCoreSave8PL_SKILL(CoreSave, skill) == -1)
            setSkill__9cCoreSave8PL_SKILLSc(CoreSave, skill, 0);
    }
    if (want == 1) {
        if (getSkill__9cCoreSave8PL_SKILL(CoreSave, skill) >= 0 &&
            (*(unsigned *)(self->tbl + skill * 0x24 + 0xC) & mask)) {
            self->list[(*count)] = skill;
            *count += 1;
        }
    } else {
        if (getSkill__9cCoreSave8PL_SKILL(CoreSave, skill) >= 0 &&
            !(*(unsigned *)(self->tbl + skill * 0x24 + 0xC) & mask)) {
            self->list[(*count)] = skill;
            *count += 1;
        }
    }
}
