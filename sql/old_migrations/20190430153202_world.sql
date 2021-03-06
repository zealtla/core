DROP PROCEDURE IF EXISTS add_migration;
delimiter ??
CREATE PROCEDURE `add_migration`()
BEGIN
DECLARE v INT DEFAULT 1;
SET v = (SELECT COUNT(*) FROM `migrations` WHERE `id`='20190430153202');
IF v=0 THEN
INSERT INTO `migrations` VALUES ('20190430153202');
-- Add your query below.


UPDATE `creature` SET `position_x` = -11152.5, `position_y` = 552.716, `position_z` = 55.8919, `orientation` = 5.50239, `MovementType` = 0 WHERE `guid` = 66988;
UPDATE `creature` SET `position_x` = -11151.1, `position_y` = 551.26, `position_z` = 55.8923, `orientation` = 2.36865 WHERE `guid` = 66991;

DELETE FROM `creature_movement` WHERE `id` IN (66988, 66991);
INSERT INTO `creature_movement` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `waittime`, `script_id`) VALUES
(66991, 1, -11151.1, 551.26, 55.8923, 2.36865, 26000, 705201),
(66991, 2, -11140.5, 543.668, 56.3212, 0, 0, 0),
(66991, 3, -11142.6, 541.549, 55.92, 0, 0, 0),
(66991, 4, -11146, 536.9, 53.7638, 0, 0, 0),
(66991, 5, -11147, 534.896, 52.495, 0, 0, 0),
(66991, 6, -11147.6, 532.728, 52.4694, 0, 0, 0),
(66991, 7, -11147.6, 535.236, 52.5826, 0, 0, 0),
(66991, 8, -11145.2, 538.529, 54.7388, 0, 0, 0),
(66991, 9, -11141.9, 543.463, 56.2928, 0, 0, 0),
(66991, 10, -11139.4, 542.983, 56.6356, 0, 0, 0),
(66991, 11, -11138.4, 539.196, 57.9116, 0, 0, 0),
(66991, 12, -11138.3, 535.496, 59.8756, 0, 0, 0),
(66991, 13, -11137.9, 539.928, 57.7232, 0, 0, 0),
(66991, 14, -11139.9, 543.434, 56.4715, 0, 0, 0),
(66991, 15, -11149.7, 550.018, 55.9364, 0, 0, 0),
(66991, 16, -11140.5, 543.668, 56.3212, 0, 0, 0),
(66991, 17, -11142.6, 541.549, 55.92, 0, 0, 0),
(66991, 18, -11146, 536.9, 53.7638, 0, 0, 0),
(66991, 19, -11147, 534.896, 52.495, 0, 0, 0),
(66991, 20, -11147.6, 532.728, 52.4694, 0, 0, 0),
(66991, 21, -11147.6, 535.236, 52.5826, 0, 0, 0),
(66991, 22, -11145.2, 538.529, 54.7388, 0, 0, 0),
(66991, 23, -11141.9, 543.463, 56.2928, 0, 0, 0),
(66991, 24, -11139.4, 542.983, 56.6356, 0, 0, 0),
(66991, 25, -11138.4, 539.196, 57.9116, 0, 0, 0),
(66991, 26, -11138.3, 535.496, 59.8756, 0, 0, 0),
(66991, 27, -11137.9, 539.928, 57.7232, 0, 0, 0),
(66991, 28, -11139.9, 543.434, 56.4715, 0, 0, 0),
(66991, 29, -11149.7, 550.018, 55.9364, 0, 0, 0),
(66991, 30, -11151.1, 551.26, 55.8923, 2.36865, 2000, 0);

DELETE FROM `creature_movement_special` WHERE `id` = 66988;
INSERT INTO `creature_movement_special` (`id`, `point`, `position_x`, `position_y`, `position_z`, `script_id`) VALUES
(66988, 1, -11149.1, 554.466, 55.8049, 0),
(66988, 2, -11144.7, 556.683, 55.1371, 0),
(66988, 3, -11140.4, 556.894, 53.8734, 0),
(66988, 4, -11136, 554.83, 52.5735, 0),
(66988, 5, -11131.7, 549.872, 50.3729, 0),
(66988, 6, -11130.7, 546.131, 49.4701, 0),
(66988, 7, -11131.7, 549.872, 50.3729, 0),
(66988, 8, -11136, 554.83, 52.5735, 0),
(66988, 9, -11140.4, 556.894, 53.8734, 0),
(66988, 10, -11144.7, 556.683, 55.1371, 0),
(66988, 11, -11149.1, 554.466, 55.8049, 0),
(66988, 12, -11152.3, 552.681, 55.8918, 0),
(66988, 13, -11149.1, 554.466, 55.8049, 0),
(66988, 14, -11144.7, 556.683, 55.1371, 0),
(66988, 15, -11140.4, 556.894, 53.8734, 0),
(66988, 16, -11136, 554.83, 52.5735, 0),
(66988, 17, -11131.7, 549.872, 50.3729, 0),
(66988, 18, -11130.7, 546.131, 49.4701, 0),
(66988, 19, -11131.7, 549.872, 50.3729, 0),
(66988, 20, -11136, 554.83, 52.5735, 0),
(66988, 21, -11140.4, 556.894, 53.8734, 0),
(66988, 22, -11144.7, 556.683, 55.1371, 0),
(66988, 23, -11149.1, 554.466, 55.8049, 0),
(66988, 24, -11152.5, 552.716, 55.8919, 705202);

DELETE FROM `creature_movement_scripts` WHERE `id` IN (705201, 705202);
INSERT INTO `creature_movement_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `datalong3`, `datalong4`, `target_param1`, `target_param2`, `target_type`, `data_flags`, `dataint`, `dataint2`, `dataint3`, `dataint4`, `x`, `y`, `z`, `o`, `condition_id`, `comments`) VALUES
(705201, 2, 0, 0, 0, 0, 0, 66988, 0, 9, 2, 3126, 0, 0, 0, 0, 0, 0, 0, 0, "Defias Tower Patroller - Say Text (Defias Tower Patroller)"),
(705201, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3127, 0, 0, 0, 0, 0, 0, 0, 0, "Defias Tower Patroller - Say Text"),
(705201, 8, 0, 0, 0, 0, 0, 66988, 0, 9, 2, 3128, 0, 0, 0, 0, 0, 0, 0, 0, "Defias Tower Patroller - Say Text (Defias Tower Patroller)"),
(705201, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3129, 0, 0, 0, 0, 0, 0, 0, 0, "Defias Tower Patroller - Say Text"),
(705201, 20, 0, 0, 0, 0, 0, 66988, 0, 9, 2, 3130, 0, 0, 0, 0, 0, 0, 0, 0, "Defias Tower Patroller - Say Text (Defias Tower Patroller)"),
(705201, 25, 60, 3, 1, 0, 0, 66988, 0, 9, 2, 0, 66988, 0, 0, 0, 0, 0, 0, 0, "Defias Tower Patroller - Start Waypoints (Defias Tower Patroller)"),
(705202, 1, 35, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5.50239, 0, "Defias Tower Patroller - Set Orientation");

UPDATE `broadcast_text` SET `EmoteId0` = 1 WHERE `ID` IN (3126, 3130);
UPDATE `broadcast_text` SET `EmoteId0` = 6 WHERE `ID` IN (3127, 3128);
UPDATE `broadcast_text` SET `EmoteId0` = 274 WHERE `ID` = 3129;


-- End of migration.
END IF;
END??
delimiter ; 
CALL add_migration();
DROP PROCEDURE IF EXISTS add_migration;
