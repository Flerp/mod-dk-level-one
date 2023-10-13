-- no previous scriptname
UPDATE `creature_template` SET `npcflag`=3, `ScriptName`='npc_ac_skip_lich' WHERE `entry`=25462;


-- update quest XP rewards to 0 for DK starting quests
UPDATE `quest_template` SET `RewardXPDifficulty`=0 WHERE `ID` IN (12593, 12619, 12842, 12848, 12636, 12641, 12657, 12678, 12679, 12680, 12687, 12698, 12701, 12706, 12716, 12719, 12720, 12722, 12724, 12725, 12727, 12733, 12751, 12754, 12755, 12756, 12757, 12779, 12801, 13165, 13166, 12750, 12749, 12748, 12747, 12746, 12745, 12744, 12743, 12742, 12739, 13188, 13189);