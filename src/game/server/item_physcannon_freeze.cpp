//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: Handling for the suit batteries.
//
// $NoKeywords: $
//=============================================================================//

#include "cbase.h"
#include "hl2_player.h"
#include "basecombatweapon.h"
#include "gamerules.h"
#include "items.h"
#include "engine/IEngineSound.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

class CItemPhyscannonFreeze : public CItem
{
public:
	DECLARE_CLASS(CItemPhyscannonFreeze, CItem);

	void Spawn(void)
	{
		Precache();
		SetModel("models/gravgun_crystal/gravgun_crystal.mdl");
		BaseClass::Spawn();
	}
	void Precache(void)
	{
		PrecacheModel("models/gravgun_crystal/gravgun_crystal.mdl");
		PrecacheScriptSound("SuitRecharge.Start");
	}
	bool MyTouch(CBasePlayer *pPlayer)
	{
		CHL2_Player *pHL2Player = dynamic_cast<CHL2_Player *>(pPlayer);
		return (pHL2Player && pHL2Player->EquipGGFreezeModule());
	}
};

LINK_ENTITY_TO_CLASS(item_physcannon_freeze, CItemPhyscannonFreeze);
PRECACHE_REGISTER(item_physcannon_freeze);

