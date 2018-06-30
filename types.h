#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED
#define SET_BIT(Reg,BitNo) ((Reg|=(1<<BitNo)))
#define CLEAR_BIT(Reg,BitNo) ((Reg&=~(1<<BitNo)))
#define TOGGLE_BIT(Reg,BitNo) ((Reg ^= (1<<BitNo)))
#define GET_BIT(Reg,BitNo) (((Reg&(1<<BitNo))>>BitNo))
#endif // TYPES_H_INCLUDED
