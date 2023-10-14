-- no previous scriptname
UPDATE `creature_template` SET `npcflag`=3, `ScriptName`='npc_ac_skip_lich' WHERE `entry`=25462;


-- update quest XP rewards to 0 for DK starting quests
UPDATE `quest_template` SET `RewardXPDifficulty`=0 WHERE `ID` IN (12593, 12619, 12842, 12848, 12636, 12641, 12657, 12678, 12679, 12680, 12687, 12698, 12701, 12706, 12716, 12719, 12720, 12722, 12724, 12725, 12727, 12733, 12751, 12754, 12755, 12756, 12757, 12779, 12801, 13165, 13166, 12750, 12749, 12748, 12747, 12746, 12745, 12744, 12743, 12742, 12739, 13188, 13189);

-- DK Stat Distribution for sub level 55
INSERT INTO `player_class_stats` VALUES
(6,1,20,0,25,25,25,29,20),
(6,2,29,0,26,26,26,29,20),
(6,3,38,0,27,27,27,29,20),
(6,4,47,0,28,28,28,29,20),
(6,5,56,0,29,29,29,29,21),
(6,6,65,0,30,30,30,29,21),
(6,7,74,0,31,31,31,29,21),
(6,8,83,0,32,32,32,29,21),
(6,9,92,0,33,33,33,29,21),
(6,10,97,0,34,34,34,29,21),
(6,11,103,0,35,35,35,29,22),
(6,12,109,0,36,36,36,29,22),
(6,13,118,0,37,37,37,29,22),
(6,14,128,0,38,38,38,29,23),
(6,15,139,0,39,39,39,29,23),
(6,16,151,0,40,40,40,29,23),
(6,17,154,0,41,41,41,29,24),
(6,18,168,0,42,42,42,29,24),
(6,19,183,0,43,43,43,29,24),
(6,20,199,0,44,44,44,29,25),
(6,21,206,0,45,45,45,29,25),
(6,22,224,0,46,46,46,29,25),
(6,23,243,0,47,47,47,29,26),
(6,24,253,0,48,48,48,29,26),
(6,25,274,0,49,49,49,29,27),
(6,26,296,0,50,50,50,29,27),
(6,27,309,0,52,51,51,29,28),
(6,28,333,0,54,52,52,29,28),
(6,29,348,0,56,53,53,29,29),
(6,30,374,0,58,54,54,29,29),
(6,31,401,0,60,55,55,29,30),
(6,32,419,0,62,56,56,29,30),
(6,33,448,0,64,57,57,29,31),
(6,34,468,0,66,58,58,29,31),
(6,35,499,0,68,59,59,29,32),
(6,36,521,0,70,60,60,29,32),
(6,37,545,0,72,61,63,29,33),
(6,38,581,0,74,62,65,29,33),
(6,39,609,0,76,63,67,29,34),
(6,40,649,0,78,64,69,29,34),
(6,41,681,0,80,65,71,29,35),
(6,42,715,0,82,66,73,29,35),
(6,43,761,0,84,67,75,29,36),
(6,44,799,0,86,68,77,29,36),
(6,45,839,0,88,69,79,29,37),
(6,46,881,0,90,70,81,29,37),
(6,47,935,0,92,71,83,29,38),
(6,48,981,0,94,72,85,29,38),
(6,49,1029,0,96,73,87,29,39),
(6,50,1079,0,98,73,89,29,39),
(6,51,1131,0,100,73,91,29,40),
(6,52,1185,0,102,73,93,29,40),
(6,53,1241,0,104,73,95,29,41),
(6,54,1299,0,106,73,97,29,41);