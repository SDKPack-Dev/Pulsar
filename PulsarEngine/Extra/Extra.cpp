#include <PulsarSystem.hpp>

namespace Codes {

//Anti Mii Crash
asmFunc AntiWiper() {
    ASM(
        nofralloc;
loc_0x0:
  cmpwi r4, 0x6;
  ble validMii;
  lhz r12, 0xE(r30);
  cmpwi r12, 0x0;
  bne validMii;
  li r31, 0x0;
  li r4, 0x6;
validMii:
  mr r29, r4;
  blr;
    )
}
kmCall(0x800CB6C0, AntiWiper);
kmWrite32(0x80526660, 0x38000001); //Credits to Ro for the last line.

//Anti Item Collission Crash [Marioiscool246]
extern "C" void __ptmf_test(void*);
asmFunc AntiItemColCrash() {
    ASM(
        nofralloc;
loc_0x0:
  stwu r1, -0xC(r1);
  stw r31, 8(r1);
  mflr r31;
  addi r3, r29, 0x174;
  bl __ptmf_test;
  cmpwi r3, 0;
  bne end;
  addi r31, r31, 0x14;

end:
  mtlr r31;
  lwz r31, 8(r1);
  addi r1, r1, 0xC;
  mr r3, r29;
  blr;
    )
}
kmCall(0x807A1A54, AntiItemColCrash);

//Mii Outfit C Anti-Crash
kmWrite8(0x8089089D, 0x00000062);
kmWrite8(0x808908A9, 0x00000062);
kmWrite8(0x808908E5, 0x00000062);
kmWrite8(0x808908F1, 0x00000062);
kmWrite8(0x8089092D, 0x00000062);
kmWrite8(0x80890939, 0x00000062);

//Item Spam Anti-Freeze [???]
asmFunc ItemSpamAntiFreeze() {
    ASM (
        loc_0x0:
        lbz       r12, 0x1C(r27);
        add       r12, r30, r12;
        cmpwi     r12, 0xE0;
        blt+      loc_0x18;
        li        r0, 0;
        stb       r0, 0x19(r27);
        
        loc_0x18:
        lbz       r0, 0x19(r27);
    )
}
kmCall(0x8065BBD4, ItemSpamAntiFreeze);

//Allow All Vehicles in Battle Mode [Nameless, Scruffy]
kmWrite32(0x80553F98, 0x3880000A);
kmWrite32(0x8084FEF0, 0x48000044);
kmWrite32(0x80860A90, 0x38600000);

//Instant Voting Roulette Decide [Ro]
kmWrite32(0x80643BC4, 0x60000000);
kmWrite32(0x80643C2C, 0x60000000);

//No Disconnect on Countdown [_tZ]
kmWrite32(0x80655578, 0x60000000);

//Mushroom Glitch Fix [Vabold]
kmWrite8(0x807BA077, 0x00);

//Allow WFC on Wiimmfi Patched ISOs
kmWrite32(0x800EE3A0, 0x2C030000);
kmWrite32(0x800ECAAC, 0x7C7E1B78);

//Ultra Uncut [MrBean35000vr + Chadderz]
asmFunc GetUltraUncut() {
    ASM(
      nofralloc;
loc_0x0:
  lbz       r3, 0x1C(r29);
  cmplwi    r3, 0x1;
  ble+      loc_0x10;
  mr        r0, r30;

loc_0x10:
  cmplw     r30, r0;
  blr;
    )
}
kmCall(0x8053511C, GetUltraUncut);

//Anti Lag Start [Ro]
extern "C" void sInstance__8Racedata(void*);
asmFunc AntiLagStart(){
    ASM(
      nofralloc;
loc_0x0:
  lwz r12, sInstance__8Racedata@l(r30);
  lwz r12, 0xB70(r12);
  cmpwi r12, 0x7;
  blt- loc_0x14;
  li r3, 0x1;

loc_0x14:
  cmpwi r3, 0x0;
  blr;
  )
}
kmCall(0x80533430, AntiLagStart);
} //namespace Codes