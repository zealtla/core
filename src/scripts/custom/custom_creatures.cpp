/* Copyright (C) 2009 - 2010 ScriptDevZero <http://github.com/scriptdevzero/scriptdevzero>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "scriptPCH.h"
#include "custom.h"
#include "ScriptedAI.h"
#include <ctime>
#pragma execution_character_set("UTF-8")

// TELEPORT NPC

bool GossipHello_TeleportNPC(Player *player, Creature *_Creature)   
{
	if (player->IsInCombat())
	{
		_Creature->MonsterWhisper("战斗中无法使用！",player);
		return false;
	}

    // HORDE
    if (player->GetTeam() == HORDE)
    {        
        player->ADD_GOSSIP_ITEM(5, "主城"               , GOSSIP_SENDER_MAIN, 1);
        player->ADD_GOSSIP_ITEM(5, "人物出生地"       , GOSSIP_SENDER_MAIN, 3);
        player->ADD_GOSSIP_ITEM(5, "五人副本"            , GOSSIP_SENDER_MAIN, 5);       
        player->ADD_GOSSIP_ITEM(5, "荆棘谷竞技场" , GOSSIP_SENDER_MAIN, 4015);
		player->ADD_GOSSIP_ITEM(5, "中立城市", GOSSIP_SENDER_MAIN, 6010);
		player->ADD_GOSSIP_ITEM(0, "去玩家主城|cffFF0000加基森|r", GOSSIP_SENDER_MAIN, 6020);

        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
    }
    // ALLIANCE
    else
    {       
        player->ADD_GOSSIP_ITEM(5, "主城"               , GOSSIP_SENDER_MAIN, 2);
        player->ADD_GOSSIP_ITEM(5, "人物出生地"       , GOSSIP_SENDER_MAIN, 4);
        player->ADD_GOSSIP_ITEM(5, "五人副本"            , GOSSIP_SENDER_MAIN, 5);       
        player->ADD_GOSSIP_ITEM(5, "荆棘谷竞技场" , GOSSIP_SENDER_MAIN, 4015);
        player->ADD_GOSSIP_ITEM(5, "中立城市"     , GOSSIP_SENDER_MAIN, 6010);
		player->ADD_GOSSIP_ITEM(0, "去玩家主城|cffFF0000加基森|r", GOSSIP_SENDER_MAIN, 6020);
        
        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
    }
    return true;
}

void SendDefaultMenu_TeleportNPC(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case 1: // Cities [HORDE]
            player->ADD_GOSSIP_ITEM(5, "奥格瑞玛"             , GOSSIP_SENDER_MAIN, 20);
            player->ADD_GOSSIP_ITEM(5, "幽暗城"             , GOSSIP_SENDER_MAIN, 21);
            player->ADD_GOSSIP_ITEM(5, "雷霆崖"          , GOSSIP_SENDER_MAIN, 22);
            //player->ADD_GOSSIP_ITEM(5, "Goldshire (Stormwind)" , GOSSIP_SENDER_MAIN, 4018);
            player->ADD_GOSSIP_ITEM(5, "<-[主菜单]"                  , GOSSIP_SENDER_MAIN, 100);

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        case 2: // Cities [ALLIANCE]
            player->ADD_GOSSIP_ITEM(5, "暴风城"        , GOSSIP_SENDER_MAIN, 23);
            player->ADD_GOSSIP_ITEM(5, "铁炉堡"             , GOSSIP_SENDER_MAIN, 24);
            player->ADD_GOSSIP_ITEM(5, "达纳苏斯"             , GOSSIP_SENDER_MAIN, 25);
            //player->ADD_GOSSIP_ITEM(5, "Razor Hill(Orgrimmar)" , GOSSIP_SENDER_MAIN, 4017);
            player->ADD_GOSSIP_ITEM(5, "<-[主菜单]"                  , GOSSIP_SENDER_MAIN, 100);

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
		case 3: // Starting Places [HORDE]
			player->ADD_GOSSIP_ITEM(5, "灰影墓穴", GOSSIP_SENDER_MAIN, 40);
			player->ADD_GOSSIP_ITEM(5, "试炼谷", GOSSIP_SENDER_MAIN, 41);
			player->ADD_GOSSIP_ITEM(5, "纳拉其营地", GOSSIP_SENDER_MAIN, 42);
			player->ADD_GOSSIP_ITEM(5, "<-[主菜单]", GOSSIP_SENDER_MAIN, 100);

			player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
			break;
		case 4: // Starting Places [ALLIANCE]
			player->ADD_GOSSIP_ITEM(5, "北郡山谷", GOSSIP_SENDER_MAIN, 43);
			player->ADD_GOSSIP_ITEM(5, "寒脊山谷", GOSSIP_SENDER_MAIN, 44);
			player->ADD_GOSSIP_ITEM(5, "幽影谷", GOSSIP_SENDER_MAIN, 45);
			player->ADD_GOSSIP_ITEM(5, "<-[主菜单]", GOSSIP_SENDER_MAIN, 100);

			player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
			break;
		case 5: // Instances [PAGE 1]
			player->ADD_GOSSIP_ITEM(5, "哀嚎洞穴", GOSSIP_SENDER_MAIN, 1249);
			player->ADD_GOSSIP_ITEM(5, "死亡矿井", GOSSIP_SENDER_MAIN, 1250);
			player->ADD_GOSSIP_ITEM(5, "暴风城监狱", GOSSIP_SENDER_MAIN, 1267);
			player->ADD_GOSSIP_ITEM(5, "影牙城堡", GOSSIP_SENDER_MAIN, 1251);
			player->ADD_GOSSIP_ITEM(5, "黑暗深渊", GOSSIP_SENDER_MAIN, 1252);
			player->ADD_GOSSIP_ITEM(5, "剃刀沼泽", GOSSIP_SENDER_MAIN, 1254);
			player->ADD_GOSSIP_ITEM(5, "剃刀高地", GOSSIP_SENDER_MAIN, 1256);
			player->ADD_GOSSIP_ITEM(5, "血色修道院", GOSSIP_SENDER_MAIN, 1257);
			player->ADD_GOSSIP_ITEM(7, "[下一页] ->", GOSSIP_SENDER_MAIN, 5551);
			player->ADD_GOSSIP_ITEM(5, "<-[主菜单]", GOSSIP_SENDER_MAIN, 100);

			player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
			break;
		case 5551: // Instances [PAGE 2]
			player->ADD_GOSSIP_ITEM(5, "奥达曼", GOSSIP_SENDER_MAIN, 1258);
			player->ADD_GOSSIP_ITEM(5, "祖尔法拉克", GOSSIP_SENDER_MAIN, 1259);
			player->ADD_GOSSIP_ITEM(5, "玛拉顿", GOSSIP_SENDER_MAIN, 1260);
			player->ADD_GOSSIP_ITEM(5, "阿塔哈卡神庙", GOSSIP_SENDER_MAIN, 1261);
			player->ADD_GOSSIP_ITEM(5, "黑石深渊", GOSSIP_SENDER_MAIN, 1262);
			player->ADD_GOSSIP_ITEM(5, "厄运之槌", GOSSIP_SENDER_MAIN, 1263);
			player->ADD_GOSSIP_ITEM(5, "黑石塔", GOSSIP_SENDER_MAIN, 1264);
			player->ADD_GOSSIP_ITEM(5, "斯坦索姆", GOSSIP_SENDER_MAIN, 1265);
			player->ADD_GOSSIP_ITEM(5, "通灵学院", GOSSIP_SENDER_MAIN, 1266);
			player->ADD_GOSSIP_ITEM(7, "<- [上一页]", GOSSIP_SENDER_MAIN, 5550);
			player->ADD_GOSSIP_ITEM(5, "<-[主菜单]", GOSSIP_SENDER_MAIN, 100);

			player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
			break;
		case 5550: // Instances [PAGE 1]
			player->ADD_GOSSIP_ITEM(5, "哀嚎洞穴", GOSSIP_SENDER_MAIN, 1249);
			player->ADD_GOSSIP_ITEM(5, "死亡矿井", GOSSIP_SENDER_MAIN, 1250);
			player->ADD_GOSSIP_ITEM(5, "暴风城监狱", GOSSIP_SENDER_MAIN, 1267);
			player->ADD_GOSSIP_ITEM(5, "影牙城堡", GOSSIP_SENDER_MAIN, 1251);
			player->ADD_GOSSIP_ITEM(5, "黑暗深渊", GOSSIP_SENDER_MAIN, 1252);
			player->ADD_GOSSIP_ITEM(5, "剃刀沼泽", GOSSIP_SENDER_MAIN, 1254);
			player->ADD_GOSSIP_ITEM(5, "剃刀高地", GOSSIP_SENDER_MAIN, 1256);
			player->ADD_GOSSIP_ITEM(5, "血色修道院", GOSSIP_SENDER_MAIN, 1257);
			player->ADD_GOSSIP_ITEM(7, "[下一页] ->", GOSSIP_SENDER_MAIN, 5551);
			player->ADD_GOSSIP_ITEM(5, "<-[主菜单]", GOSSIP_SENDER_MAIN, 100);

			player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
			break;		
        case 6010: // 中立城市
            player->ADD_GOSSIP_ITEM(5, "加基森" , GOSSIP_SENDER_MAIN, 601);
            player->ADD_GOSSIP_ITEM(5, "棘齿城" , GOSSIP_SENDER_MAIN, 602);
            player->ADD_GOSSIP_ITEM(5, "藏宝海湾" , GOSSIP_SENDER_MAIN, 603);
            
            player->ADD_GOSSIP_ITEM(5, "<-[主菜单]"                  , GOSSIP_SENDER_MAIN, 100);

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
            break;
        
// ----### CITIES ###----

// ### HORDE ###

        case 20: // Orgrimmar
            player->CLOSE_GOSSIP_MENU();
			player->TeleportTo(1, 1603.084f, -4397.858f, 9.389f, 1.65f);
            break;
        case 21: // Undercity
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, 1584.2829f, 240.1435f, -52.1530f, 6.279f);
            break;
        case 22: // Thunderbluff
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -1272.703735f, 116.886490f, 131.016861f, 0.0f);
            break;

// ### ALLIANCE ###

        case 23: // Stormwind
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -8828.231445f, 627.927490f, 94.055664f, 0.0f);
            break;
        case 24: // Ironforge
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -4917.0f, -955.0f, 502.0f, 0.0f);
            break;
        case 25: // Darnassus
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, 9948.2343f, 2482.8879f, 1316.2127f, 1.6077f);
            break;

// ----### STARTING PLACES ####----

// ### HORDE ###
        case 40: // Shadow Grave
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, 1663.517f, 1678.187744f, 120.5303f, 0.0f);
            break;
        case 41: // Valley of Trials
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -602.1253f, -4262.4208f, 38.956341f, 0.0f);
            break;
        case 42: // Camp Narache
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -2914.16992f, -266.061798f, 53.658211f, 0.0f);
            break;

// ### ALLIANCE ###

        case 43: // Nortshire Valley
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -8943.133789f, -132.934921f, 83.704269f, 0.0f);
            break;
        case 44: // Coldridge Valley
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -6231.106445f, 332.270477f, 383.153931f, 0.0f);
            break;
        case 45: // Shadowglen
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, 10329.918945f, 833.500305f, 1326.260620f, 0.0f);
            break;

// ----### INSTANCES ###----

        

// ---### ZONES ###---        
        case 4015:// Gurubashi
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -13261.3f, 168.294f, 35.0792f, 1.00688f);
            break;
        case 4017:// Razor Hill
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, 315.721f, -4743.4f, 10.4867f, 0.0f);
            break;
        case 4018:// Goldshire
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -9464.0f, 62.0f, 56.0f, 0.0f);
            break;
        case 1249://teleport player to the Wailing Caverns
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -722.53f, -2226.30f, 16.94f, 2.71f);
            break;
        case 1250://teleport player to the Deadmines
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -11212.04f, 1658.58f, 25.67f, 1.45f);
            break;
        case 1251://teleport player to Shadowfang Keep
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -254.47f, 1524.68f, 76.89f, 1.56f);
            break;
        case 1252://teleport player to Blackfathom Deeps
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, 4254.58f, 664.74f, -29.04f, 1.97f);
            break;
        case 1254://teleport player to Razorfen Kraul
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -4484.04f, -1739.40f, 86.47f, 1.23f);
            break;
        case 1256://teleport player to Razorfen Downs
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -4645.08f, -2470.85f, 85.53f, 4.39f);
            break;
        case 1257://teleport player to the Scarlet Monastery
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, 2843.89f, -693.74f, 139.32f, 5.11f);
            break;
        case 1258://teleport player to Uldaman
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -6119.70f, -2957.30f, 204.11f, 0.03f);
            break;
        case 1259://teleport player to Zul'Farrak
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -6839.39f, -2911.03f, 8.87f, 0.41f);
            break;
        case 1260://teleport player to Maraudon
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -1433.33f, 2955.34f, 96.21f, 4.82f);
            break;
        case 1261://teleport player to the Sunken Temple
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -10346.92f, -3851.90f, -43.41f, 6.09f);
            break;
        case 1262://teleport player to Blackrock Depths
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -7301.03f, -913.19f, 165.37f, 0.08f);
            break;
        case 1263://teleport player to Dire Maul
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -3982.47f, 1127.79f, 161.02f, 0.05f);
            break;
        case 1264://teleport player to Blackrock Spire
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -7535.43f, -1212.04f, 285.45f, 5.29f);
            break;
        case 1265://teleport player to Stratholme
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, 3263.54f, -3379.46f, 143.59f, 0.00f);
            break;
        case 1266://teleport player to Scholomance
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, 1219.01f, -2604.66f, 85.61f, 0.50f);
            break;        
		//中立城市
		case 601:
			player->CLOSE_GOSSIP_MENU();
			player->TeleportTo(1, -7172.2626f, -3768.9331f, 8.634f, 2.26f);
			break;
		case 602: //棘齿城 -943.935 -3715.49 11.8385 1 棘齿城
			player->CLOSE_GOSSIP_MENU();
			player->TeleportTo(1, -981.5548f, -3795.7236f, 5.3121f, 0.941f);
			break;
		case 603: //-14406.6 419.353 22.3907 0 藏宝海湾
			player->CLOSE_GOSSIP_MENU();
			player->TeleportTo(0, -14291.8466f, 542.2787f, 8.837f, 4.349f);
			break;
		case 6020:
			player->CLOSE_GOSSIP_MENU();
			player->TeleportTo(1, -7172.2626f, -3768.9331f, 8.634f, 2.26f);
			break;
        case 100: // Main Menu          
			 // HORDE
			if (player->GetTeam() == HORDE)
			{
				// player->ADD_GOSSIP_ITEM(5, "PreTBC Mall"          , GOSSIP_SENDER_MAIN, 74);
				player->ADD_GOSSIP_ITEM(5, "主城", GOSSIP_SENDER_MAIN, 1);
				player->ADD_GOSSIP_ITEM(5, "人物出生地", GOSSIP_SENDER_MAIN, 3);
				player->ADD_GOSSIP_ITEM(5, "五人副本", GOSSIP_SENDER_MAIN, 5);				
				player->ADD_GOSSIP_ITEM(5, "荆棘谷竞技场", GOSSIP_SENDER_MAIN, 4015);
				player->ADD_GOSSIP_ITEM(5, "中立城市", GOSSIP_SENDER_MAIN, 6010);
				player->ADD_GOSSIP_ITEM(0, "去玩家主城|cffFF0000加基森|r", GOSSIP_SENDER_MAIN, 6020);

				player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
			}
			// ALLIANCE
			else
			{
				//player->ADD_GOSSIP_ITEM(5, "PreTBC Mall"          , GOSSIP_SENDER_MAIN, 74);
				player->ADD_GOSSIP_ITEM(5, "主城", GOSSIP_SENDER_MAIN, 2);
				player->ADD_GOSSIP_ITEM(5, "人物出生地", GOSSIP_SENDER_MAIN, 4);
				player->ADD_GOSSIP_ITEM(5, "五人副本", GOSSIP_SENDER_MAIN, 5);				
				player->ADD_GOSSIP_ITEM(5, "荆棘谷竞技场", GOSSIP_SENDER_MAIN, 4015);
				player->ADD_GOSSIP_ITEM(5, "中立城市", GOSSIP_SENDER_MAIN, 6010);
				player->ADD_GOSSIP_ITEM(0, "去玩家主城|cffFF0000加基森|r", GOSSIP_SENDER_MAIN, 6020);

				player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
			}
			break;
    }
}
bool GossipSelect_TeleportNPC(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    // Main menu
    if (sender == GOSSIP_SENDER_MAIN)
        SendDefaultMenu_TeleportNPC(player, _Creature, action);

    return true;
}

enum Enchants
{
    WEP2H_SUPERIOR_IMPACT = 20,
    WEP2H_AGILITY,
    WEP_CRUSADER,
    WEP1H_AGILITY,
    WEP_SPELLPOWER,
    WEP_HEAL,
    OFFHAND_SPIRIT,
    OFFHAND_STAM,
    OFFHAND_FROSTRES,
    CHEST_STATS,
    CLOAK_DODGE,
    CLOAK_SUB,
    CLOAK_ARMOR,
    CLOAK_AGILITY,
    BRACER_STAM,
    BRACER_STR,
    BRACER_HEAL,
    BRACER_INT,
    GLOVES_AGI,
    GLOVES_FIRE,
    GLOVES_FROST,
    GLOVES_SHADOW,
    GLOVES_HEALING,
    BOOTS_AGI,
    BOOTS_SPEED,
    BOOTS_STAM,
};

void Enchant(Player* player, Item* item, uint32 enchantid)
{
    if (!item)
    {
        player->GetSession()->SendNotification("You must first equip the item you are trying to enchant.");
        return;
    }

    if (!enchantid)
    {
        player->GetSession()->SendNotification("Something went wrong.");
        return;
    }

    item->ClearEnchantment(PERM_ENCHANTMENT_SLOT);
    item->SetEnchantment(PERM_ENCHANTMENT_SLOT, enchantid, 0, 0);
    player->GetSession()->SendNotification("%s succesfully enchanted", item->GetProto()->Name1);
}

bool GossipHello_EnchantNPC(Player* player, Creature* creature)
{

    player->ADD_GOSSIP_ITEM(5, "Chest", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_CHEST);
    player->ADD_GOSSIP_ITEM(5, "Cloak", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_BACK);
    player->ADD_GOSSIP_ITEM(5, "Bracers", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_WRISTS);
    player->ADD_GOSSIP_ITEM(5, "Gloves", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_HANDS);
    player->ADD_GOSSIP_ITEM(5, "Boots", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_FEET);
    player->ADD_GOSSIP_ITEM(5, "Mainhand", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_MAINHAND);
    player->ADD_GOSSIP_ITEM(5, "Offhand", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_OFFHAND);

    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
    return true;
}
bool GossipSelect_EnchantNPC(Player* player, Creature* creature, uint32 sender, uint32 action)
{
    if (sender != GOSSIP_SENDER_MAIN)
        return true;

    if (action < 20)
    {
        switch (action)
        {
        case EQUIPMENT_SLOT_CHEST:
            player->ADD_GOSSIP_ITEM(5, "Greater Stats", GOSSIP_SENDER_MAIN, CHEST_STATS);
            break;
        case EQUIPMENT_SLOT_BACK:
            player->ADD_GOSSIP_ITEM(5, "Agility", GOSSIP_SENDER_MAIN, CLOAK_AGILITY);
            player->ADD_GOSSIP_ITEM(5, "Armor", GOSSIP_SENDER_MAIN, CLOAK_ARMOR);
            player->ADD_GOSSIP_ITEM(5, "Dodge", GOSSIP_SENDER_MAIN, CLOAK_DODGE);
            player->ADD_GOSSIP_ITEM(5, "Subtlety", GOSSIP_SENDER_MAIN, CLOAK_SUB);
        break;
        case EQUIPMENT_SLOT_WRISTS:
            player->ADD_GOSSIP_ITEM(5, "Stamina", GOSSIP_SENDER_MAIN, BRACER_STAM);
            player->ADD_GOSSIP_ITEM(5, "Strength", GOSSIP_SENDER_MAIN, BRACER_STR);
            player->ADD_GOSSIP_ITEM(5, "Healing", GOSSIP_SENDER_MAIN, BRACER_HEAL);
            player->ADD_GOSSIP_ITEM(5, "Intellect", GOSSIP_SENDER_MAIN, BRACER_INT);
            break;
        case EQUIPMENT_SLOT_HANDS:
            player->ADD_GOSSIP_ITEM(5, "Agility", GOSSIP_SENDER_MAIN, GLOVES_AGI);
            player->ADD_GOSSIP_ITEM(5, "Fire Power", GOSSIP_SENDER_MAIN, GLOVES_FIRE);
            player->ADD_GOSSIP_ITEM(5, "Frost Power", GOSSIP_SENDER_MAIN, GLOVES_FROST);
            player->ADD_GOSSIP_ITEM(5, "Shadow Power", GOSSIP_SENDER_MAIN, GLOVES_SHADOW);
            player->ADD_GOSSIP_ITEM(5, "Healing", GOSSIP_SENDER_MAIN, GLOVES_HEALING);
            break;
        case EQUIPMENT_SLOT_FEET:
            player->ADD_GOSSIP_ITEM(5, "Stamina", GOSSIP_SENDER_MAIN, BOOTS_STAM);
            player->ADD_GOSSIP_ITEM(5, "Minor Speed", GOSSIP_SENDER_MAIN, BOOTS_SPEED);
            player->ADD_GOSSIP_ITEM(5, "Agility", GOSSIP_SENDER_MAIN, BOOTS_AGI);
            break;
        case EQUIPMENT_SLOT_MAINHAND:
            player->ADD_GOSSIP_ITEM(5, "Crusader", GOSSIP_SENDER_MAIN, WEP_CRUSADER);
            player->ADD_GOSSIP_ITEM(5, "1H Agility", GOSSIP_SENDER_MAIN, WEP1H_AGILITY);
            player->ADD_GOSSIP_ITEM(5, "2H Agility", GOSSIP_SENDER_MAIN, WEP2H_AGILITY);
            player->ADD_GOSSIP_ITEM(5, "Spellpower", GOSSIP_SENDER_MAIN, WEP_SPELLPOWER);
            player->ADD_GOSSIP_ITEM(5, "Healing", GOSSIP_SENDER_MAIN, WEP_HEAL);
            break;
        case EQUIPMENT_SLOT_OFFHAND:
            player->ADD_GOSSIP_ITEM(5, "Spirit", GOSSIP_SENDER_MAIN, OFFHAND_SPIRIT);
            player->ADD_GOSSIP_ITEM(5, "Stamina", GOSSIP_SENDER_MAIN, OFFHAND_STAM);
            player->ADD_GOSSIP_ITEM(5, "Frost Resistance", GOSSIP_SENDER_MAIN, OFFHAND_FROSTRES);
            break;
        }
        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
    }
    else
    {
        Item* item = nullptr;
        uint32 id = 0;
        switch (action)
        {
            case WEP2H_SUPERIOR_IMPACT:
            case WEP2H_AGILITY:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
                if (item && (action == WEP2H_AGILITY || action == WEP2H_SUPERIOR_IMPACT))
                {
                    if (item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_AXE2 && item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_MACE2
                        && item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_SWORD2 && item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_POLEARM
                        && item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_STAFF)
                    {
                        player->GetSession()->SendNotification("Requires 2 handed weapon");
                        player->CLOSE_GOSSIP_MENU();
                        return true;
                    }
                }
                if (action == WEP2H_SUPERIOR_IMPACT)
                    id = 1896;
                else if (action == WEP2H_AGILITY)
                    id = 2646;
                break;

            case WEP_CRUSADER:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
                id = 1900;
                break;
            case WEP1H_AGILITY:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
                id = 2564;
                break;
            case WEP_SPELLPOWER:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
                id = 2504;
                break;
            case WEP_HEAL:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
                id = 2505;
                break;

            case OFFHAND_SPIRIT:
            case OFFHAND_STAM:
            case OFFHAND_FROSTRES:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
                if (item && item->GetProto()->SubClass != ITEM_SUBCLASS_ARMOR_SHIELD)
                {
                    player->GetSession()->SendNotification("Requires Shield");
                    player->CLOSE_GOSSIP_MENU();
                    return true;
                }
                if (action == OFFHAND_SPIRIT)
                    id = 1890;
                else if (action == OFFHAND_FROSTRES)
                    id = 926;
                else if (action == OFFHAND_STAM)
                    id = 929;
                break;
            case CHEST_STATS:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST);
                id = 1891;
                break;
            case CLOAK_DODGE:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
                id = 2622;
                break;
            case CLOAK_SUB:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
                id = 2621;
                break;
            case CLOAK_ARMOR:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
                id = 1889;
                break;
            case CLOAK_AGILITY:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
                id = 849;
                break;
            case BRACER_STAM:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
                id = 1886;
                break;
            case BRACER_STR:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
                id = 1885;
                break;
            case BRACER_HEAL:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
                id = 2566;
                break;
            case BRACER_INT:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
                id = 1883;
                break;
            case GLOVES_AGI:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
                id = 2564;
                break;
            case GLOVES_FIRE:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
                id = 2616;
                break;
            case GLOVES_FROST:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
                id = 2615;
                break;
            case GLOVES_SHADOW:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
                id = 2614;
                break;
            case GLOVES_HEALING:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
                id = 2617;
                break;
            case BOOTS_AGI:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET);
                id = 904;
                break;
            case BOOTS_SPEED:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET);
                id = 911;
                break;
            case BOOTS_STAM:
                item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET);
                id = 929;
                break;
        }
        Enchant(player, item, id);
        player->CLOSE_GOSSIP_MENU();
    }
    return true;
}



void LearnSkillRecipesHelper(Player *player, uint32 skill_id)
{
    uint32 classmask = player->GetClassMask();

    for (uint32 j = 0; j < sObjectMgr.GetMaxSkillLineAbilityId(); ++j)
    {
        SkillLineAbilityEntry const *skillLine = sObjectMgr.GetSkillLineAbility(j);
        if (!skillLine)
            continue;

        // wrong skill
        if (skillLine->skillId != skill_id)
            continue;

        // not high rank
        if (skillLine->forward_spellid)
            continue;

        // skip racial skills
        if (skillLine->racemask != 0)
            continue;

        // skip wrong class skills
        if (skillLine->classmask && (skillLine->classmask & classmask) == 0)
            continue;

        SpellEntry const* spellEntry = sSpellMgr.GetSpellEntry(skillLine->spellId);
        if (!spellEntry || !SpellMgr::IsSpellValid(spellEntry, player, false))
            continue;

        player->LearnSpell(skillLine->spellId, false);
    }
}
bool LearnAllRecipesInProfession(Player *pPlayer, SkillType skill)
{
    ChatHandler handler(pPlayer->GetSession());
    char* skill_name;

    SkillLineEntry const *SkillInfo = sSkillLineStore.LookupEntry(skill);
    skill_name = SkillInfo->name[sWorld.GetDefaultDbcLocale()];

    if (!SkillInfo)
    {
        sLog.outError("Profession NPC: received non-valid skill ID");
        return false;
    }

    pPlayer->SetSkill(SkillInfo->id, 300, 300);
    LearnSkillRecipesHelper(pPlayer, SkillInfo->id);
    pPlayer->GetSession()->SendNotification("All recipes for %s learned", skill_name);
    return true;
}

bool GossipHello_ProfessionNPC(Player* player, Creature* creature)
{

    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Alchemy",              GOSSIP_SENDER_MAIN, 1);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Blacksmithing",        GOSSIP_SENDER_MAIN, 2);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Leatherworking",       GOSSIP_SENDER_MAIN, 3);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Tailoring",            GOSSIP_SENDER_MAIN, 4);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Engineering",          GOSSIP_SENDER_MAIN, 5);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Enchanting",           GOSSIP_SENDER_MAIN, 6);
    //player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Jewelcrafting",      GOSSIP_SENDER_MAIN, 7);
    //player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Inscription",        GOSSIP_SENDER_MAIN, 8);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Herbalism",            GOSSIP_SENDER_MAIN, 9);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Skinning",             GOSSIP_SENDER_MAIN, 10);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Mining",               GOSSIP_SENDER_MAIN, 11);

    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "First Aid",            GOSSIP_SENDER_MAIN, 12);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Fishing",              GOSSIP_SENDER_MAIN, 13);
    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Cooking",              GOSSIP_SENDER_MAIN, 14);

    player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());

    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
    return true;
}
void CompleteLearnProfession(Player *pPlayer, Creature *pCreature, SkillType skill)
{
    if (pPlayer->GetFreePrimaryProfessionPoints() == 0 && !(skill == SKILL_COOKING || skill == SKILL_FIRST_AID))
    {
        pPlayer->GetSession()->SendNotification("You already know two primary professions.");
    }
    else
    {
        if (!LearnAllRecipesInProfession(pPlayer, skill))
            pPlayer->GetSession()->SendNotification("Internal error.");
    }
}
bool GossipSelect_ProfessionNPC(Player* player, Creature* creature, uint32 sender, uint32 action)
{
    switch (action)
    {
    case 1:
        if (!player->HasSkill(SKILL_ALCHEMY))
            CompleteLearnProfession(player, creature, SKILL_ALCHEMY);
        break;
    case 2:
        if (!player->HasSkill(SKILL_BLACKSMITHING))
            CompleteLearnProfession(player, creature, SKILL_BLACKSMITHING);
        break;
    case 3:
        if (!player->HasSkill(SKILL_LEATHERWORKING))
            CompleteLearnProfession(player, creature, SKILL_LEATHERWORKING);
        break;
    case 4:
        if (!player->HasSkill(SKILL_TAILORING))
            CompleteLearnProfession(player, creature, SKILL_TAILORING);
        break;
    case 5:
        if (!player->HasSkill(SKILL_ENGINEERING))
            CompleteLearnProfession(player, creature, SKILL_ENGINEERING);
        break;
    case 6:
        if (!player->HasSkill(SKILL_ENCHANTING))
            CompleteLearnProfession(player, creature, SKILL_ENCHANTING);
        break;
    case 7:
    case 8:
        break;
    case 9:
        if (!player->HasSkill(SKILL_HERBALISM))
            CompleteLearnProfession(player, creature, SKILL_HERBALISM);
        break;
    case 10:
        if (!player->HasSkill(SKILL_SKINNING))
            CompleteLearnProfession(player, creature, SKILL_SKINNING);
        break;
    case 11:
        if (!player->HasSkill(SKILL_MINING))
            CompleteLearnProfession(player, creature, SKILL_MINING);
        break;
    case 12:
        if (!player->HasSkill(SKILL_FIRST_AID))
            CompleteLearnProfession(player, creature, SKILL_FIRST_AID);
        break;
    case 13:
        if (!player->HasSkill(SKILL_FISHING))
            CompleteLearnProfession(player, creature, SKILL_FISHING);
        break;
    case 14:
        if (!player->HasSkill(SKILL_COOKING))
            CompleteLearnProfession(player, creature, SKILL_COOKING);
        break;
    }

    player->CLOSE_GOSSIP_MENU();
    return true;
}

//多职业训练师
bool GossipHello_ClassTrainer(Player* player, Creature* pCreature)
{
	if (player->GetTeam() == ALLIANCE)
	{
		player->ADD_GOSSIP_ITEM(5, "战士", GOSSIP_SENDER_MAIN, 1);
		player->ADD_GOSSIP_ITEM(5, "法师", GOSSIP_SENDER_MAIN, 2);
		player->ADD_GOSSIP_ITEM(5, "盗贼", GOSSIP_SENDER_MAIN, 3);
		player->ADD_GOSSIP_ITEM(5, "猎人", GOSSIP_SENDER_MAIN, 4);
		player->ADD_GOSSIP_ITEM(5, "术士", GOSSIP_SENDER_MAIN, 5);
		player->ADD_GOSSIP_ITEM(5, "牧师", GOSSIP_SENDER_MAIN, 6);
		player->ADD_GOSSIP_ITEM(5, "圣骑士", GOSSIP_SENDER_MAIN, 7);
		player->ADD_GOSSIP_ITEM(5, "德鲁伊", GOSSIP_SENDER_MAIN, 8);
		player->ADD_GOSSIP_ITEM(5, "学习职业任务技能", GOSSIP_SENDER_MAIN, 10);
		player->ADD_GOSSIP_ITEM(5, "重置天赋  |cff0000FF费用：20金币|r", GOSSIP_SENDER_MAIN, 11);
		//player->ADD_GOSSIP_ITEM(5, "猎人宝宝忠诚度秒满", GOSSIP_SENDER_MAIN, 12);
		//player->ADD_GOSSIP_ITEM(5, "|cffB22222开通双天赋|r", GOSSIP_SENDER_MAIN, 13);

		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
	}
	else
	{
		player->ADD_GOSSIP_ITEM(5, "战士", GOSSIP_SENDER_MAIN, 1);
		player->ADD_GOSSIP_ITEM(5, "法师", GOSSIP_SENDER_MAIN, 2);
		player->ADD_GOSSIP_ITEM(5, "盗贼", GOSSIP_SENDER_MAIN, 3);
		player->ADD_GOSSIP_ITEM(5, "猎人", GOSSIP_SENDER_MAIN, 4);
		player->ADD_GOSSIP_ITEM(5, "术士", GOSSIP_SENDER_MAIN, 5);
		player->ADD_GOSSIP_ITEM(5, "牧师", GOSSIP_SENDER_MAIN, 6);
		player->ADD_GOSSIP_ITEM(5, "萨满", GOSSIP_SENDER_MAIN, 9);
		player->ADD_GOSSIP_ITEM(5, "德鲁伊", GOSSIP_SENDER_MAIN, 8);
		player->ADD_GOSSIP_ITEM(5, "学习职业任务技能", GOSSIP_SENDER_MAIN, 10);
		player->ADD_GOSSIP_ITEM(5, "重置天赋  |cff0000FF费用：20金币|r", GOSSIP_SENDER_MAIN, 11);
		//player->ADD_GOSSIP_ITEM(5, "猎人宝宝忠诚度秒满", GOSSIP_SENDER_MAIN, 12);
		//player->ADD_GOSSIP_ITEM(5, "|cffB22222开通双天赋|r", GOSSIP_SENDER_MAIN, 13);

		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
	}
	return true;
}

void SendDefaultMenu_ClassTrainer(Player* player, Creature* _creature, uint32 action)
{
	bool can_learn_primary_prof = player->GetFreePrimaryProfessionPoints() > 0;

	if (player->GetTeam() == ALLIANCE)
	{
		switch (action)
		{
		case 1: //战士
			player->PlayerTalkClass->ClearMenus();
			player->PlayerTalkClass->SendGossipMenu(4985, _creature->GetGUID()); //战士
			player->GetSession()->SendTrainerList_(_creature->GetGUID(), 914);
			break;
		case 2: //法师
			player->PlayerTalkClass->ClearMenus();
			player->PlayerTalkClass->SendGossipMenu(328, _creature->GetGUID()); //法师
			player->GetSession()->SendTrainerList_(_creature->GetGUID(), 5145);
			break;
		case 3: //盗贼
			player->PlayerTalkClass->ClearMenus();
			player->PlayerTalkClass->SendGossipMenu(4797, _creature->GetGUID()); //盗贼
			player->GetSession()->SendTrainerList_(_creature->GetGUID(), 918);
			break;
		case 4: //猎人
			player->PlayerTalkClass->ClearMenus();
			player->PlayerTalkClass->SendGossipMenu(10090, _creature->GetGUID()); //猎人
			player->GetSession()->SendTrainerList_(_creature->GetGUID(), 5115);
			break;
		case 5: //术士
			player->PlayerTalkClass->ClearMenus();
			player->PlayerTalkClass->SendGossipMenu(5836, _creature->GetGUID()); //术士
			player->GetSession()->SendTrainerList_(_creature->GetGUID(), 461);
			break;
		case 6: //牧师
			player->PlayerTalkClass->ClearMenus();
			player->PlayerTalkClass->SendGossipMenu(4436, _creature->GetGUID()); //牧师
			player->GetSession()->SendTrainerList_(_creature->GetGUID(), 11401);
			break;
		case 7: //圣骑
			player->PlayerTalkClass->ClearMenus();
			player->PlayerTalkClass->SendGossipMenu(1635, _creature->GetGUID()); //圣骑
			player->GetSession()->SendTrainerList_(_creature->GetGUID(), 928);
			break;
		case 8: //德鲁伊
			player->PlayerTalkClass->ClearMenus();
			player->PlayerTalkClass->SendGossipMenu(4913, _creature->GetGUID()); //德鲁伊
			player->GetSession()->SendTrainerList_(_creature->GetGUID(), 5504);
			break;
		case 10: //学习职业技能
			if (can_learn_primary_prof)
			{
				uint8 _class = player->GetClass();
				switch (_class)
				{
				case 1: //战士
					player->LearnSpell(71, false);
					player->LearnSpell(7386, false);
					player->LearnSpell(355, false);
					player->LearnSpell(2458, false);
					player->LearnSpell(20252, false);
					player->CLOSE_GOSSIP_MENU();
					break;
				case 4: //盗贼
					player->LearnSpell(2995, false);
					player->CLOSE_GOSSIP_MENU();
					break;
				case 3: //猎人
					player->LearnSpell(1579, false);
					player->LearnSpell(5149, false);
					player->LearnSpell(6991, false);
					player->LearnSpell(982, false);
					player->LearnSpell(2641, false);
					player->CLOSE_GOSSIP_MENU();
					break;
				case 9: //术士
					player->LearnSpell(688, false);
					player->LearnSpell(697, false);
					player->LearnSpell(691, false);
					player->LearnSpell(712, false);
					player->CLOSE_GOSSIP_MENU();
					break;
				case 5: //牧师
					player->CLOSE_GOSSIP_MENU();
					break;
				case 8:
					player->CLOSE_GOSSIP_MENU();
					break;
				case 2: //圣骑
					player->LearnSpell(7329, false);
					player->LearnSpell(5503, false);
					player->CLOSE_GOSSIP_MENU();
					break;
				case 11: //德鲁伊
					player->LearnQuestRewardedSpells(sObjectMgr.GetQuestTemplate(6001));
					player->LearnQuestRewardedSpells(sObjectMgr.GetQuestTemplate(5921));
					player->LearnQuestRewardedSpells(sObjectMgr.GetQuestTemplate(6125));
					player->LearnQuestRewardedSpells(sObjectMgr.GetQuestTemplate(5061));
					player->CLOSE_GOSSIP_MENU();
					break;
				}
			}

			break;
		case 11: //重置天赋  |cff0000FF费用：20金币|r
			if (player->GetMoney() < 200000)
			{
				player->GetSession()->SendNotification("你没有足够的金币重置天赋！");
				player->CLOSE_GOSSIP_MENU();
				break;
			}

			player->ResetTalents(true);
			player->ModifyMoney(int32(-200000));
			_creature->MonsterWhisper("|cff1E90FF重置天赋成功，扣除费用20金币。|r",player);
			player->CLOSE_GOSSIP_MENU();
			break;		
		//case 13: //双天赋
		//	if (player->getLevel() <= 10)
		//	{

		//		player->GetSession()->SendNotification("等级太低无法使用此功能！");
		//		player->CLOSE_GOSSIP_MENU();
		//		return;
		//	}

		//	if (player->IsDualSpecArrive())
		//	{

		//		player->GetSession()->SendNotification("你已经开通过双天赋功能了！");
		//		player->CLOSE_GOSSIP_MENU();
		//		return;
		//	}

		//	player->SetDualSpecArriveDate(YEAR);
		//	player->m_bIsDualSpecArrive = true;
		//	player->GetSession()->SendNotification("恭喜，你开通了双天赋功能!");
		//	player->CLOSE_GOSSIP_MENU();
		//	break;
		}
	}
	else
	{
		switch (action)
		{
		case 1: //战士
			player->PlayerTalkClass->ClearMenus();
			player->PlayerTalkClass->SendGossipMenu(4985, _creature->GetGUID()); //战士
			player->GetSession()->SendTrainerList_(_creature->GetGUID(), 3353);
			break;
		case 2: //法师
			player->PlayerTalkClass->ClearMenus();
			player->PlayerTalkClass->SendGossipMenu(328, _creature->GetGUID()); //法师
			player->GetSession()->SendTrainerList_(_creature->GetGUID(), 5882);
			break;
		case 3: //盗贼
			player->PlayerTalkClass->ClearMenus();
			player->PlayerTalkClass->SendGossipMenu(4797, _creature->GetGUID()); //盗贼
			player->GetSession()->SendTrainerList_(_creature->GetGUID(), 3401);
			break;
		case 4: //猎人
			player->PlayerTalkClass->ClearMenus();
			player->PlayerTalkClass->SendGossipMenu(10090, _creature->GetGUID()); //猎人
			player->GetSession()->SendTrainerList_(_creature->GetGUID(), 3352);
			break;
		case 5: //术士
			player->PlayerTalkClass->ClearMenus();
			player->PlayerTalkClass->SendGossipMenu(5836, _creature->GetGUID()); //术士
			player->GetSession()->SendTrainerList_(_creature->GetGUID(), 4563);
			break;
		case 6: //牧师
			player->PlayerTalkClass->ClearMenus();
			player->PlayerTalkClass->SendGossipMenu(4436, _creature->GetGUID()); //牧师
			player->GetSession()->SendTrainerList_(_creature->GetGUID(), 3046);
			break;
		case 9: //萨满
			player->PlayerTalkClass->ClearMenus();
			player->PlayerTalkClass->SendGossipMenu(5003, _creature->GetGUID()); //萨满
			player->GetSession()->SendTrainerList_(_creature->GetGUID(), 3344);
			break;
		case 8: //德鲁伊
			player->PlayerTalkClass->ClearMenus();
			player->PlayerTalkClass->SendGossipMenu(4913, _creature->GetGUID()); //德鲁伊
			player->GetSession()->SendTrainerList_(_creature->GetGUID(), 3034);
			break;
		case 10: //学习职业技能
			if (can_learn_primary_prof)
			{
				uint8 _class = player->GetClass();
				switch (_class)
				{
				case 1: //战士
					player->LearnSpell(71, false);
					player->LearnSpell(7386, false);
					player->LearnSpell(355, false);
					player->LearnSpell(2458, false);
					player->LearnSpell(20252, false);
					player->CLOSE_GOSSIP_MENU();
					break;
				case 4: //盗贼
					player->LearnSpell(2995, false);
					player->CLOSE_GOSSIP_MENU();
					break;
				case 3: //猎人
					player->LearnSpell(1579, false);
					player->LearnSpell(5149, false);
					player->LearnSpell(6991, false);
					player->LearnSpell(982, false);
					player->LearnSpell(2641, false);
					player->CLOSE_GOSSIP_MENU();
					break;
				case 9: //术士
					player->LearnSpell(688, false);
					player->LearnSpell(697, false);
					player->LearnSpell(691, false);
					player->LearnSpell(712, false);
					player->CLOSE_GOSSIP_MENU();
					break;
				case 5: //牧师	
					player->CLOSE_GOSSIP_MENU();
					break;
				case 7: //萨满
					player->LearnSpell(3599, false);
					player->LearnSpell(8071, false);
					player->LearnSpell(5394, false);
					player->CLOSE_GOSSIP_MENU();
					break;
				case 8:
					player->CLOSE_GOSSIP_MENU();
					break;
				case 11: //德鲁伊
					player->LearnQuestRewardedSpells(sObjectMgr.GetQuestTemplate(6002));
					player->LearnQuestRewardedSpells(sObjectMgr.GetQuestTemplate(31));
					player->LearnQuestRewardedSpells(sObjectMgr.GetQuestTemplate(5922));
					player->LearnQuestRewardedSpells(sObjectMgr.GetQuestTemplate(6130));
					player->CLOSE_GOSSIP_MENU();
					break;
				}
			}

			break;
		case 11: //重置天赋  |cff0000FF费用：20金币|r
			if (player->GetMoney() < 200000)
			{
				player->GetSession()->SendNotification("你没有足够的金币重置天赋！");
				player->CLOSE_GOSSIP_MENU();
				break;
			}

			player->ResetTalents(true);
			player->ModifyMoney(int32(-200000));
			_creature->MonsterWhisper("|cff1E90FF重置天赋成功，扣除费用20金币。|r", player);
			player->CLOSE_GOSSIP_MENU();
			break;
		//case 13: //双天赋
		//	if (player->getLevel() <= 10)
		//	{
		//		player->GetSession()->SendNotification("等级太低无法使用此功能！");
		//		player->CLOSE_GOSSIP_MENU();
		//		return;
		//	}

		//	if (player->IsDualSpecArrive())
		//	{
		//		player->GetSession()->SendNotification("你已经开通过双天赋功能了！");
		//		player->CLOSE_GOSSIP_MENU();
		//		return;
		//	}

		//	player->SetDualSpecArriveDate(YEAR);
		//	player->m_bIsDualSpecArrive = true;
		//	player->GetSession()->SendNotification("恭喜，你开通了双天赋功能!");
		//	player->CLOSE_GOSSIP_MENU();
		//	break;
		}
	}

}

bool GossipSelect_ClassTrainer(Player *player, Creature *_creature, uint32 sender, uint32 action)
{
	if (sender == GOSSIP_SENDER_MAIN)
		SendDefaultMenu_ClassTrainer(player, _creature, action);

	return true;
}

struct npc_training_dummyAI : ScriptedAI
{
    explicit npc_training_dummyAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        npc_training_dummyAI::Reset();
    }

    uint32 m_uiCombatTimer;
    std::unordered_map<ObjectGuid, time_t> attackers;

    void Reset() override
    {
        m_uiCombatTimer = 15000;
        attackers.clear();
    }

    void AttackStart(Unit* /*pWho*/) override {}

    void Aggro(Unit* pWho) override
    {
        SetCombatMovement(false);
    }

    void AddAttackerToList(Unit* pWho)
    {
        auto itr = attackers.find(pWho->GetObjectGuid());
        if (itr != attackers.end())
        {
            itr->second = std::time(nullptr);
        }
        else
        {
            attackers.emplace(pWho->GetObjectGuid(), std::time(nullptr));
        }
    }

    void DamageTaken(Unit* pWho, uint32& /*uiDamage*/) override
    {
        if (pWho)
            AddAttackerToList(pWho);
    }

    void SpellHit(Unit* pWho, const SpellEntry* /*pSpell*/) override
    {
        if (pWho)
            AddAttackerToList(pWho);
    }

    void UpdateAI(const uint32 diff) override
    {
        if (m_creature->IsInCombat())
        {
            if (m_uiCombatTimer <= diff)
            {
                for (auto itr = attackers.begin(); itr != attackers.end();)
                {
                    Unit* pAttacker = m_creature->GetMap()->GetUnit(itr->first);

                    if (!pAttacker || !pAttacker->IsInWorld())
                    {
                        itr = attackers.erase(itr);
                        continue;
                    }
                    if (itr->second + 10 < std::time(nullptr))
                    {
                        m_creature->_removeAttacker(pAttacker);
                        m_creature->GetThreatManager().modifyThreatPercent(pAttacker, -101.0f);
                        itr = attackers.erase(itr);
                        continue;
                    }
                    ++itr;
                }

                if (m_creature->GetThreatManager().isThreatListEmpty())
                    EnterEvadeMode();

                m_uiCombatTimer = 15000;
            }
            else
                m_uiCombatTimer -= diff;
        }
    }
};

CreatureAI* GetAI_npc_training_dummy(Creature* pCreature)
{
    return new npc_training_dummyAI(pCreature);
}

struct npc_summon_debugAI : ScriptedAI
{
    uint32 m_maxSummonCount = 200;
    uint32 m_summonCount = 0;
    Creature *m_summons[200];

    npc_summon_debugAI(Creature *pCreature) : ScriptedAI(pCreature)
    {
        m_summonCount = 0;
        for (uint32 i = 0; i < m_maxSummonCount; ++i)
            m_summons[i] = nullptr;

        Reset();
    }

    void Reset() override
    {
        m_summonCount = 0;
        for (uint32 i = 0; i < m_maxSummonCount; ++i)
        {
            if (m_summons[i])
                ((TemporarySummon*)m_summons[i])->UnSummon();

            m_summons[i] = nullptr;
        }
    }


    void JustDied(Unit* /* killer */) override
    {
        Reset();
    }

    void UpdateAI(const uint32 diff) override
    {
        if (!m_creature->GetVictim())
            return;

        if (m_summonCount >= m_maxSummonCount)
            return;

        m_summons[m_summonCount++] = m_creature->SummonCreature(12458, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 0);
    }
};

CreatureAI* GetAI_custom_summon_debug(Creature *creature)
{
    return new npc_summon_debugAI(creature);
}

void AddSC_custom_creatures()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "custom_teleport_npc";
    newscript->pGossipHello = &GossipHello_TeleportNPC;
    newscript->pGossipSelect = &GossipSelect_TeleportNPC;
    newscript->RegisterSelf(false);

    newscript = new Script;
    newscript->Name = "custom_enchant_npc";
    newscript->pGossipHello = &GossipHello_EnchantNPC;
    newscript->pGossipSelect = &GossipSelect_EnchantNPC;
    newscript->RegisterSelf(false);

    newscript = new Script;
    newscript->Name = "custom_professions_npc";
    newscript->pGossipHello = &GossipHello_ProfessionNPC;
    newscript->pGossipSelect = &GossipSelect_ProfessionNPC;
    newscript->RegisterSelf(false);

    newscript = new Script;
    newscript->Name = "custom_npc_training_dummy";
    newscript->GetAI = &GetAI_npc_training_dummy;
    newscript->RegisterSelf(false);

    newscript = new Script;
    newscript->Name = "custom_npc_summon_debugAI";
    newscript->GetAI = &GetAI_custom_summon_debug;
    newscript->RegisterSelf(false);

	newscript = new Script;
	newscript->Name = "custom_classtrainer_npc";
	newscript->pGossipHello = &GossipHello_ClassTrainer;
	newscript->pGossipSelect = &GossipSelect_ClassTrainer;
	newscript->RegisterSelf(false);
}
