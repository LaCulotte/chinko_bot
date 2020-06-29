cmake_minimum_required(VERSION 3.0)

project(chinko_bot)

add_subdirectory(std_bot)

set(CMAKE_BUILD_TYPE Debug)

set(SRCS
    base64/base64.cpp
    chinko_bot/types/NetworkTypeHandler.cpp
    chinko_bot/types/connection/authentification/GameServerInfo.cpp
    chinko_bot/types/connection/gameServerConnection/AbstractCharacterInformation.cpp
    chinko_bot/types/connection/gameServerConnection/CharacterBaseInformations.cpp
    chinko_bot/types/connection/gameServerConnection/CharacterBasicMinimalInformations.cpp
    chinko_bot/types/connection/gameServerConnection/CharacterMinimalInformations.cpp
    chinko_bot/types/connection/gameServerConnection/CharacterMinimalPlusLookInformations.cpp
    chinko_bot/types/connection/gameServerConnection/CharacterHardcoreOrEpicInformations.cpp
    chinko_bot/types/connection/gameServerConnection/EntityLook.cpp
    chinko_bot/types/game/inventory/items/ObjectItem.cpp
    chinko_bot/types/game/inventory/items/SpellItem.cpp
    chinko_bot/types/game/inventory/items/effects/ObjectEffect.cpp
    chinko_bot/types/game/inventory/items/effects/ObjectEffectCreature.cpp
    chinko_bot/types/game/inventory/items/effects/ObjectEffectDate.cpp
    chinko_bot/types/game/inventory/items/effects/ObjectEffectDice.cpp
    chinko_bot/types/game/inventory/items/effects/ObjectEffectInteger.cpp
    chinko_bot/types/game/inventory/items/effects/ObjectEffectLadder.cpp
    chinko_bot/types/game/inventory/items/effects/ObjectEffectMinMax.cpp
    chinko_bot/types/game/inventory/items/effects/ObjectEffectMount.cpp
    chinko_bot/types/game/inventory/items/effects/ObjectEffectString.cpp
    chinko_bot/types/game/roleplay/job/JobExperience.cpp
    chinko_bot/types/game/shortcut/Shortcut.cpp
    chinko_bot/types/game/shortcut/ShortcutEmote.cpp
    chinko_bot/types/game/shortcut/ShortcutObject.cpp
    chinko_bot/types/game/shortcut/ShortcutObjectIdolsPreset.cpp
    chinko_bot/types/game/shortcut/ShortcutObjectItem.cpp
    chinko_bot/types/game/shortcut/ShortcutObjectPreset.cpp
    chinko_bot/types/game/shortcut/ShortcutSmiley.cpp
    chinko_bot/types/game/shortcut/ShortcutSpell.cpp
    chinko_bot/messages/UnknownDofusMessage.cpp
    chinko_bot/messages/DofusMessageTypeHandler.cpp
    chinko_bot/messages/game/shortcut/ShortcutBarContentMessage.cpp
    chinko_bot/messages/game/inventory/InventoryContentMessage.cpp
    chinko_bot/messages/game/inventory/InventoryWeightMessage.cpp
    chinko_bot/messages/game/inventory/spells/SpellListMessage.cpp
    chinko_bot/messages/game/roleplay/job/JobExperienceMultiUpdateMessage.cpp
    chinko_bot/messages/game/roleplay/almanach/AlmanachCalendarDateMessage.cpp
    chinko_bot/messages/game/queue/QueueStatusMessage.cpp
    chinko_bot/messages/game/basic/SequenceNumberMessage.cpp
    chinko_bot/messages/game/character/stats/CharacterExperienceGainMessage.cpp
    chinko_bot/messages/connection/authentification/HelloConnectMessage.cpp
    chinko_bot/messages/connection/authentification/ProtocolRequiredMessage.cpp
    chinko_bot/messages/connection/authentification/IdentificationMessage.cpp
    chinko_bot/messages/connection/authentification/IdentificationSuccessMessage.cpp
    chinko_bot/messages/connection/authentification/ClientKeyMessage.cpp
    chinko_bot/messages/connection/authentification/LoginQueueStatusMessage.cpp
    chinko_bot/messages/connection/authentification/SelectedServerDataMessage.cpp
    chinko_bot/messages/connection/authentification/SelectedServerDataExtendedMessage.cpp
    chinko_bot/messages/connection/gameServerConnection/AuthentificationTicketMessage.cpp
    chinko_bot/messages/connection/gameServerConnection/RawDataMessage.cpp
    chinko_bot/messages/connection/gameServerConnection/BasicCharactersListMessage.cpp
    chinko_bot/messages/connection/gameServerConnection/CharactersListMessage.cpp
    chinko_bot/messages/connection/gameServerConnection/CharacterSelectedSuccessMessage.cpp
    chinko_bot/messages/connection/gameServerConnection/CharacterSelectionMessage.cpp
    chinko_bot/messages/connection/gameServerConnection/CheckIntegrityMessage.cpp
    chinko_bot/connections/DofusClientConnection.cpp
    chinko_bot/units/dofusBotUnit/DofusBotUnit.cpp
    chinko_bot/units/dofusBotUnit/frames/basic/BasicDofusBotFrame.cpp
    chinko_bot/units/dofusBotUnit/frames/game/queue/QueueFrame.cpp
    chinko_bot/units/dofusBotUnit/frames/connection/AuthentificationFrame.cpp
    chinko_bot/units/dofusBotUnit/frames/connection/GameServerConnectionFrame.cpp
    chinko_bot/units/dofusBotUnit/frames/characterSelection/CharacterSelectionFrame.cpp
    chinko_bot/units/APIUnit/frames/TerminalPromptFrame.cpp
    chinko_bot/managers/connection/AuthentificationManager.cpp
    main.cpp
)

add_executable(chinko_bot ${SRCS})

target_include_directories(chinko_bot PUBLIC ./base64)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/types)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/informationContainers/gameServer)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/types/connection/authentification)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/types/connection/gameServerConnection)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/types/game/shortcut)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/types/game/inventory/items)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/types/game/inventory/items/effects)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/types/game/roleplay/job)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/connections)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/managers/connection)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/messages)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/messages/game/queue)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/messages/game/shortcut)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/messages/game/inventory)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/messages/game/inventory/spells)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/messages/game/roleplay/job)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/messages/game/roleplay/almanach)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/messages/game/basic)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/messages/game/character/stats)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/messages/connection/authentification)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/messages/connection/gameServerConnection)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/units/dofusBotUnit)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/units/dofusBotUnit/frames/basic)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/units/dofusBotUnit/frames/game/queue)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/units/dofusBotUnit/frames/connection)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/units/dofusBotUnit/frames/characterSelection)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/units/dofusBotUnit/messages)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/units/APIUnit)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/units/APIUnit/frames)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/units/APIUnit/messages)


target_link_libraries(chinko_bot pthread)
target_link_libraries(chinko_bot stdc++fs)
target_link_libraries(chinko_bot crypto)

target_link_libraries(chinko_bot std_bot)


set_property(TARGET chinko_bot PROPERTY CXX_STANDARD 20)