#include <PulsarSystem.hpp>
#include <MarioKartWii/Objects/Collidable/Itembox/Itembox.hpp>

namespace Pulsar {
    void ItemBoxRespawn(Objects::Itembox* itembox) {
        itembox->respawnTime = 30;
        itembox->isActive = 0;
    }
    kmCall(0x80828EDC, ItemBoxRespawn);
}