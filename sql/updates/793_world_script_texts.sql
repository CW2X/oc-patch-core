DELETE FROM `script_texts` WHERE `entry` IN (-1600369,-1600368,-1600367,-1600366,-1600365,-1600410);
INSERT INTO `script_texts` VALUES ('-1600369', 'Finally, free at last... I must be going now, thanks for helping me escape. I can get back to Freewind Post by myself.', null, null, null, null, null, null, null, null, '0', '0', '1', '0', 'lakota SAY_LAKO_END');
INSERT INTO `script_texts` VALUES ('-1600368', 'More Grimtotems are coming this way!', null, null, null, null, null, null, null, null, '0', '0', '1', '0', 'lakota SAY_LAKO_MORE');
INSERT INTO `script_texts` VALUES ('-1600367', 'Here they come.', null, null, null, null, null, null, null, null, '0', '0', '1', '0', 'lakota SAY_LAKO_HERE_COME');
INSERT INTO `script_texts` VALUES ('-1600366', 'Look out, the Grimtotem are upon us!', null, null, null, null, null, null, null, null, '0', '0', '1', '0', 'lakota SAY_LAKO_LOOK_OUT');
INSERT INTO `script_texts` VALUES ('-1600365', 'Be on guard... Arnak has some strange power over the Grimtotem... they will not be happy to see me escape.', null, null, null, null, null, null, null, null, '0', '0', '1', '0', 'lakota SAY_LAKO_START');
INSERT INTO `script_texts` VALUES ('-1600410', 'Here they come! Defend yourself!', null, null, null, null, null, null, null, null, '0', '0', '1', '5', 'kanati SAY_KAN_START');

UPDATE `quest_template` SET `SpecialFlags` = '2' WHERE `entry` = '4904';
UPDATE `quest_template` SET `SpecialFlags` = '2' WHERE `entry` = '4966';
UPDATE `creature_template` SET `ScriptName` = 'npc_kanati' WHERE `entry` = '10638';
UPDATE `creature_template` SET `ScriptName` = 'npc_lakota_windsong' WHERE `entry` = '10646';
UPDATE `creature_template` SET `ScriptName` = 'npc_enraged_panther' WHERE `entry` = '10992';
UPDATE `gameobject_template` SET `ScriptName` = 'go_panther_cage' WHERE `entry` = '176195';
