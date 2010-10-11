 /* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: Shadowfang_Keep
SD%Complete: 75
SDComment: npc_shadowfang_prisoner using escortAI for movement to door. Might need additional code in case being attacked. Add proper texts/say().
SDCategory: Shadowfang Keep
EndScriptData */

/* ContentData
npc_shadowfang_prisoner
EndContentData */

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"
#include "shadowfang_keep.h"

/*######
## npc_shadowfang_prisoner
######*/

#define SAY_FREE                -1033000
#define GOSSIP_ITEM_DOOR        "Thanks, I'll follow you to the door."

struct npc_shadowfang_prisonerAI : public npc_escortAI
{
    npc_shadowfang_prisonerAI(Creature *c) : npc_escortAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance *pInstance;

    void WaypointReached(uint32 i)
    {
        if (pInstance && i == 6)
        {
            me->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
            DoScriptText(SAY_FREE, me);
            pInstance->SetData(TYPE_FREE_NPC, DONE);
        }
    }

    void Reset() {}
    void EnterCombat(Unit* who) {}
};

CreatureAI* GetAI_npc_shadowfang_prisoner(Creature* pCreature)
{
    npc_shadowfang_prisonerAI* prisonerAI = new npc_shadowfang_prisonerAI(pCreature);

    uint32 eCreature = pCreature->GetEntry();

    if (eCreature == 3849)                                    //adamant
        prisonerAI->AddWaypoint(0, -254.47f, 2117.48f, 81.17f);
    if (eCreature == 3850)                                    //ashcrombe
        prisonerAI->AddWaypoint(0, -252.35f, 2126.71f, 81.17f);

    prisonerAI->AddWaypoint(1, -253.63f, 2131.27f, 81.28f);
    prisonerAI->AddWaypoint(2, -249.66f, 2142.45f, 87.01f);
    prisonerAI->AddWaypoint(3, -248.08f, 2143.68f, 87.01f);
    prisonerAI->AddWaypoint(4, -238.87f, 2139.93f, 87.01f);
    prisonerAI->AddWaypoint(5, -235.47f, 2149.18f, 90.59f);
    prisonerAI->AddWaypoint(6, -239.89f, 2156.06f, 90.62f, 20000);

    return (CreatureAI*)prisonerAI;
}

bool GossipHello_npc_shadowfang_prisoner(Player *player, Creature* pCreature)
{
    ScriptedInstance* pInstance = (pCreature->GetInstanceData());

    if (!pInstance)
        return false;

    if (pInstance->GetData(TYPE_FREE_NPC) != DONE && pInstance->GetData(TYPE_RETHILGORE) == DONE)
        player->ADD_GOSSIP_ITEM(0, GOSSIP_ITEM_DOOR, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    player->SEND_GOSSIP_MENU(player->GetGossipTextId(pCreature), pCreature->GetGUID());

    return true;
}

bool GossipSelect_npc_shadowfang_prisoner(Player *player, Creature* pCreature, uint32 sender, uint32 action)
{
    if (action == GOSSIP_ACTION_INFO_DEF+1)
    {
        player->CLOSE_GOSSIP_MENU();

        if (npc_escortAI* pEscortAI = CAST_AI(npc_shadowfang_prisonerAI, pCreature->AI()))
            pEscortAI->Start(false, false);
    }
    return true;
}

/*######
## AddSC
######*/

void AddSC_shadowfang_keep()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_shadowfang_prisoner";
    newscript->pGossipHello =  &GossipHello_npc_shadowfang_prisoner;
    newscript->pGossipSelect = &GossipSelect_npc_shadowfang_prisoner;
    newscript->GetAI = &GetAI_npc_shadowfang_prisoner;
    newscript->RegisterSelf();
}

