/*
 *MIT License
 *
 *Copyright (c) 2023 Azerothcore
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy
 *of this software and associated documentation files (the "Software"), to deal
 *in the Software without restriction, including without limitation the rights
 *to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *copies of the Software, and to permit persons to whom the Software is
 *furnished to do so, subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all
 *copies or substantial portions of the Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *SOFTWARE.
 *
 * Skip Death Knight Module
 * Original Module From Single Player Project Consolidated Skip Module
 * Rewritten for TC 335 By Single Player Project Developer MDic
 * Original Concept from conanhun513
 * Assistance and Review by JinnaiX
 * Modified for Azerothcore
 */

#include "AccountMgr.h"
#include "ScriptMgr.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Config.h"
#include "Common.h"
#include "Chat.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "SharedDefines.h"
#include "World.h"
#include "WorldSession.h"

constexpr auto YESSKIPDK = 1;

void Azerothcore_skip_deathknight_HandleSkip(Player* player)
{

    // these are all the starter quests that award talent points, quest items, or spells
    int STARTER_QUESTS[33] = { 12593, 12619, 12842, 12848, 12636, 12641, 12657, 12678, 12679, 12680, 12687, 12698, 12701, 12706, 12716, 12719, 12720, 12722, 12724, 12725, 12727, 12733, -1, 12751, 12754, 12755, 12756, 12757, 12779, 12801, 13165, 13166 };

    int specialSurpriseQuestId = -1;
    switch (player->getRace())
    {
    case RACE_TAUREN:
        specialSurpriseQuestId = 12739;
        break;
    case RACE_HUMAN:
        specialSurpriseQuestId = 12742;
        break;
    case RACE_NIGHTELF:
        specialSurpriseQuestId = 12743;
        break;
    case RACE_DWARF:
        specialSurpriseQuestId = 12744;
        break;
    case RACE_GNOME:
        specialSurpriseQuestId = 12745;
        break;
    case RACE_DRAENEI:
        specialSurpriseQuestId = 12746;
        break;
    case RACE_BLOODELF:
        specialSurpriseQuestId = 12747;
        break;
    case RACE_ORC:
        specialSurpriseQuestId = 12748;
        break;
    case RACE_TROLL:
        specialSurpriseQuestId = 12749;
        break;
    case RACE_UNDEAD_PLAYER:
        specialSurpriseQuestId = 12750;
        break;
    }

    STARTER_QUESTS[22] = specialSurpriseQuestId;
    STARTER_QUESTS[32] = player->GetTeamId() == TEAM_ALLIANCE ? 13188 : 13189;

    for (int questId : STARTER_QUESTS)
    {
        if (player->GetQuestStatus(questId) == QUEST_STATUS_NONE)
        {
            player->AddQuest(sObjectMgr->GetQuestTemplate(questId), nullptr);
            player->RewardQuest(sObjectMgr->GetQuestTemplate(questId), 0, player, false);
        }
    }

    int DKL = sConfigMgr->GetOption<float>("Skip.Deathknight.Start.Level", 1);
    if (player->getLevel() <= DKL)
    {
        //GiveLevel updates character properties more thoroughly than SetLevel
        player->GiveLevel(DKL);
    }

    //All Player Items rewarded by quests (And starting truffles) holding there here in case needed later
    //int STARTER_QUEST_ITEMS[31] = { 34652, 34655, 34659, 34650, 34653, 34649, 34651, 34656, 34648, 34657, 34658, 38147, 38707, 38662, 38671, 39320, 39208, 38674, 38666, 38669, 38668, 38672, 38670, 38667, 38665, 40483, 38675, 38665, 38661, 38633, 41751 };

    // Purges items from players
    for (uint8 b = INVENTORY_SLOT_ITEM_START; b < INVENTORY_SLOT_ITEM_END; b++)
    {
        player->DestroyItem(INVENTORY_SLOT_BAG_0, b, true);
    }
    for (uint8 c = INVENTORY_SLOT_BAG_START; c < INVENTORY_SLOT_BAG_END; c++)
    {
        for (uint8 i = 0; i < MAX_BAG_SIZE; i++)
        {
            player->DestroyItem(c, i, true);
        }
    }

    player->AddItem(6948, true); //Hearthstone

    //Remove Riding Skill
    player->SetSkill(762, 0, 0, 0);

    //Remove Horse Mount
    player->removeSpell(48778, 255, true);

    // Remove DK Starting Spells minus blood strike and death gate
    int STARTER_DK_SPELLS[5] = { 47541, 45462, 45477, 49576, 48266 };

    for (int DKSpell : STARTER_DK_SPELLS)
    {
        player->removeSpell(DKSpell, 255, true);
    }


    //Don't need to save all players, just current
    player->SaveToDB(false, false);

    //Teleport player to their proper starting zone based on their race
    switch (player->getRace())
    {
    case RACE_TAUREN:
        player->TeleportTo(1, -2917.58f, -257.98f, 52.9968f, 0.00f);
        break;
    case RACE_HUMAN:
        player->TeleportTo(0, -8949.95f, -132.493f, 83.5312f, 0.00f);
        break;
    case RACE_NIGHTELF:
        player->TeleportTo(1, 10311.3f, 832.463f, 1326.41f, 5.69632f);
        break;
    case RACE_DWARF:
        player->TeleportTo(0, -6240.32f, 331.033f, 382.758f, 6.17716f);
        break;
    case RACE_GNOME:
        player->TeleportTo(0, -6240.32f, 331.033f, 382.758f, 0.00f);
        break;
    case RACE_DRAENEI:
        player->TeleportTo(530, -3961.64f, -13931.2f, 100.615f, 2.08364f);
        break;
    case RACE_BLOODELF:
        player->TeleportTo(530, 10349.6f, -6357.29f, 33.4026f, 5.31605f);
        break;
    case RACE_ORC:
        player->TeleportTo(1, -618.518f, -4251.67f, 38.718f, 0.00f);
        break;
    case RACE_TROLL:
        player->TeleportTo(1, -618.518f, -4251.67f, 38.718f, 0.00f);
        break;
    case RACE_UNDEAD_PLAYER:
        player->TeleportTo(0, 1676.71f, 1678.31f, 121.67f, 2.70526f);
        break;
    }
}

class AzerothCore_skip_deathknight_announce : public PlayerScript
{
public:
    AzerothCore_skip_deathknight_announce() : PlayerScript("AzerothCore_skip_deathknight_announce") { }

    void OnLogin(Player* Player)
    {
        if (sConfigMgr->GetOption<bool>("Skip.Deathknight.Starter.Announce.enable", true) && (sConfigMgr->GetOption<bool>("Skip.Deathknight.Starter.Enable", true) || sConfigMgr->GetOption<bool>("Skip.Deathknight.Optional.Enable", true)))
        {
            ChatHandler(Player->GetSession()).SendSysMessage("This server is running the |cff4CFF00Level 1 DK |rmodule.");
        }
    }
};

class AzerothCore_skip_deathknight : public PlayerScript
{
public:
    AzerothCore_skip_deathknight() : PlayerScript("AzerothCore_skip_deathknight") { }

    void OnFirstLogin(Player* player)
    {
        if (player->GetAreaId() == 4342)
        {
            //These changes make it so user mistakes in the configuration file don't cause this to run 2x
            if ((sConfigMgr->GetOption<bool>("Skip.Deathknight.Starter.Enable", true) && player->GetSession()->GetSecurity() == SEC_PLAYER)
                || (sConfigMgr->GetOption<bool>("GM.Skip.Deathknight.Starter.Enable", true) && player->GetSession()->GetSecurity() >= SEC_MODERATOR))
            {
                Azerothcore_skip_deathknight_HandleSkip(player);
            }
        }
    }
};

#define LOCALE_LICHKING_0 "I wish to skip the Death Knight starter questline."
#define LOCALE_LICHKING_1 "죽음의 기사 스타터 퀘스트 라인을 건너뛰고 싶습니다."
#define LOCALE_LICHKING_2 "Je souhaite sauter la série de quêtes de démarrage du Chevalier de la mort."
#define LOCALE_LICHKING_3 "Ich möchte die Todesritter-Starter-Questreihe überspringen."
#define LOCALE_LICHKING_4 "我想跳過死亡騎士新手任務線。"
#define LOCALE_LICHKING_5 "我想跳過死亡騎士新手任務線。"
#define LOCALE_LICHKING_6 "Deseo saltarme la línea de misiones de inicio del Caballero de la Muerte."
#define LOCALE_LICHKING_7 "Deseo saltarme la línea de misiones de inicio del Caballero de la Muerte."
#define LOCALE_LICHKING_8 "Я хочу пропустить начальную цепочку заданий Рыцаря Смерти."

class Azerothcore_optional_deathknight_skip : public CreatureScript
{
public:
    Azerothcore_optional_deathknight_skip() : CreatureScript("npc_ac_skip_lich") { }

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            if (creature->IsQuestGiver())
            {
                player->PrepareQuestMenu(creature->GetGUID());
            }

            if (sConfigMgr->GetOption<bool>("Skip.Deathknight.Optional.Enable", true))
            {
                char const* localizedEntry;
                switch (player->GetSession()->GetSessionDbcLocale())
                {
                case LOCALE_koKR: localizedEntry = LOCALE_LICHKING_1; break;
                case LOCALE_frFR: localizedEntry = LOCALE_LICHKING_2; break;
                case LOCALE_deDE: localizedEntry = LOCALE_LICHKING_3; break;
                case LOCALE_zhCN: localizedEntry = LOCALE_LICHKING_4; break;
                case LOCALE_zhTW: localizedEntry = LOCALE_LICHKING_5; break;
                case LOCALE_esES: localizedEntry = LOCALE_LICHKING_6; break;
                case LOCALE_esMX: localizedEntry = LOCALE_LICHKING_7; break;
                case LOCALE_ruRU: localizedEntry = LOCALE_LICHKING_8; break;
                case LOCALE_enUS: localizedEntry = LOCALE_LICHKING_0; break;
                default: localizedEntry = LOCALE_LICHKING_0;
                }
                AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, localizedEntry, GOSSIP_SENDER_MAIN, YESSKIPDK, "Are you sure you want to skip the starting zone?", 0, false);
            }
            player->TalkedToCreature(creature->GetEntry(), creature->GetGUID());
            SendGossipMenuFor(player, player->GetGossipTextId(creature), creature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*menuId*/, uint32 gossipListId) override
        {
            switch (gossipListId)
            {
                case YESSKIPDK:
                    Azerothcore_skip_deathknight_HandleSkip(player);
                    CloseGossipMenuFor(player);
                    break;
            }
            return true;
        }
};

void AddSkipDKScripts()
{
    new AzerothCore_skip_deathknight_announce;
    new AzerothCore_skip_deathknight;
    new Azerothcore_optional_deathknight_skip;
}
