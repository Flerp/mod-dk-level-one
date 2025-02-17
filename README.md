# ![logo](https://raw.githubusercontent.com/azerothcore/azerothcore.github.io/master/images/logo-github.png) AzerothCore

## mod-dk-level-one

## Description

- A fork of https://github.com/azerothcore/mod-skip-dk-starting-area for people who want DKs to act as any other class, starting at level 1.
- This module performs the following:

1. Skips the DK Starting Zone
2. Create stat distribution from level 1-54 for DKs
3. Teleports characters to their proper starting zone
4. NYE - Modify and create new spell ranks for some DK Spells/Abilities, to keep them balanced with other classes as they level
5. NYE - Removes the riding skill and the DK mount (Learnable at level 40 from trainers)
6. NYE - Removes Flight Path learned locations

## How to use ingame

1. Enable in conf
2. Go into conf and set any features you want to enable or modify
3. Make a Death Knight and login.

## Notice

Due to the uniquiness of the module you will get this message on the worldconsole, but nothing is broken. It is due to the npc not exactly having a gossip menu in the database, the script handles the gossip menu because of the additional locales.
![image](https://user-images.githubusercontent.com/16887899/152654078-7b94c62c-a5e8-42ed-96ed-39ffaacf38b1.png)

Please add the adjustment to the conf to have that error message not show up:
```
#    Creatures.CustomIDs
#        Description: The list of custom creatures with gossip dialogues hardcoded in core,
#                     divided by "," without spaces.
#                     It is implied that you do not use for these NPC dialogs data from "gossip_menu" table.
#                     Server will skip these IDs during the definitions validation process.
#        Example:     Creatures.CustomIDs = "190010,55005,999991,25462,98888" - Npcs for Transmog, Guild-zone, 1v1-arena modules
#                                                                               Skip Dk Module, Racial Trait Swap Modules
#        Default:     ""

Creatures.CustomIDs = "190010,55005,999991,25462,98888"
```

## Requirements

- Latest AzerothCore Wotlk commit [de13bf4](https://github.com/azerothcore/azerothcore-wotlk/commit/de13bf426e162ee10cbd5470cec74122d1d4afa0) or newer

## Installation

1. Simply place the module under the `modules` directory of your AzerothCore source. 
2. Re-run CMake and rebuild the AzerothCore source.
3. Run Sql on world from https://github.com/Flerp/mod-dk-level-one/tree/master/sql/world on to the world db.

## Edit module configuration (optional)

If you need to change the module configuration, go to your server configuration folder (where your worldserver or worldserver.exe is), copy SkipDKModule.conf.dist to SkipDKModule.conf and edit that new file.

### Credits ###
------------------------------------------------------------------------------------------------------------------
- [acidmanifesto (MDic)](https://github.com/acidmanifesto/TC-Custom-Scripts/tree/main/335%20TC/Official%20Trinitycore%20Custom%20Scripts/Official%20Merged/Skip%20Death%20Knight%20Starter%20Area%20Module)
- [Jinnaix](https://github.com/Jinnaix) For Translations assistance and sql formatting.
- AzerothCore: [repository](https://github.com/azerothcore) - [website](http://azerothcore.org/) - [discord chat community](https://discord.gg/PaqQRkd)
-
