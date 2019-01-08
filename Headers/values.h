#ifndef VALUES_H
#define VALUES_H

#include <QtGlobal>

#define RV_PAYLOAD_SIZE 0x8
#define PRESENT_PAYLOAD_SIZE 0xC
#define LETTER_PAYLOAD_SIZE 0x290
#define HHS_HOUSE_PAYLOAD_SIZE 0x7DC8
#define UNK_PAYLOAD_SIZE 0x84

typedef quint8   u8; //  8-bit unsigned integer
typedef quint16 u16; // 16-bit unsigned integer
typedef quint32 u32; // 32-bit unsigned integer
typedef quint64 u64; // 64-bit unsigned integer

typedef qint8   s8; //  8-bit signed integer
typedef qint16 s16; // 16-bit signed integer
typedef qint32 s32; // 32-bit signed integer
typedef qint64 s64; // 64-bit signed integer

#pragma pack(push, 1)

struct Villagers {
    const char*     Name; //Villager Name
    const u16       VID;  //Villager ID
};

struct Species {
    const char      *Name; //Species Name
    const u32       Start; //Start of Species in Villagers array
    const u32       End;   //End of Species in Villagers array
};

#pragma pack(pop)

extern const Species        g_species[36];
extern const Villagers      g_villagers[430];


#endif // VALUES_H
