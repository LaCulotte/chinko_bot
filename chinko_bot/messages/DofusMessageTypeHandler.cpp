#include "DofusMessageTypeHandler.h"
#include "DofusMessageTypesIncludes.h"

DofusMessageTypeHandler::DofusMessageTypeHandler(){
    // Inits the map : message's id -> message builder
    id_to_builder[ProtocolRequired::protocolId]                         = make_shared<ProtocolRequired>;
    id_to_builder[HelloConnectMessage::protocolId]                      = make_shared<HelloConnectMessage>;
    id_to_builder[IdentificationMessage::protocolId]                    = make_shared<IdentificationMessage>;
    id_to_builder[IdentificationSuccessMessage::protocolId]             = make_shared<IdentificationSuccessMessage>;
	id_to_builder[IdentificationFailedMessage::protocolId]	            = make_shared<IdentificationFailedMessage>;
	id_to_builder[IdentificationFailedForBadVersionMessage::protocolId]	= make_shared<IdentificationFailedForBadVersionMessage>;
    id_to_builder[ClientKeyMessage::protocolId]                         = make_shared<ClientKeyMessage>;
    id_to_builder[CredentialsAcknowledgementMessage::protocolId]        = make_shared<CredentialsAcknowledgementMessage>;
    id_to_builder[LoginQueueStatusMessage::protocolId]                  = make_shared<LoginQueueStatusMessage>;
    id_to_builder[ServersListMessage::protocolId]                       = make_shared<ServersListMessage>;
    id_to_builder[SelectedServerDataMessage::protocolId]                = make_shared<SelectedServerDataMessage>;
    id_to_builder[SelectedServerDataExtendedMessage::protocolId]        = make_shared<SelectedServerDataExtendedMessage>;

    id_to_builder[HelloGameMessage::protocolId]                         = make_shared<HelloGameMessage>;
    id_to_builder[AuthenticationTicketMessage::protocolId]              = make_shared<AuthenticationTicketMessage>;
    id_to_builder[RawDataMessage::protocolId]                           = make_shared<RawDataMessage>;
    id_to_builder[CheckIntegrityMessage::protocolId]                    = make_shared<CheckIntegrityMessage>;
    id_to_builder[AuthenticationTicketAcceptedMessage::protocolId]      = make_shared<AuthenticationTicketAcceptedMessage>;
    id_to_builder[CharactersListRequestMessage::protocolId]             = make_shared<CharactersListRequestMessage>;
    id_to_builder[BasicCharactersListMessage::protocolId]               = make_shared<BasicCharactersListMessage>;
    id_to_builder[CharactersListMessage::protocolId]                    = make_shared<CharactersListMessage>;
    id_to_builder[CharacterSelectionMessage::protocolId]                = make_shared<CharacterSelectionMessage>;
    id_to_builder[QueueStatusMessage::protocolId]                       = make_shared<QueueStatusMessage>;
    id_to_builder[CharacterSelectedSuccessMessage::protocolId]          = make_shared<CharacterSelectedSuccessMessage>;
    id_to_builder[CharacterSelectedErrorMessage::protocolId]            = make_shared<CharacterSelectedErrorMessage>;
    id_to_builder[CharacterLoadingCompleteMessage::protocolId]          = make_shared<CharacterLoadingCompleteMessage>;

    id_to_builder[InventoryContentMessage::protocolId]              = make_shared<InventoryContentMessage>;
    id_to_builder[InventoryWeightMessage::protocolId]               = make_shared<InventoryWeightMessage>;
    id_to_builder[ShortcutBarContentMessage::protocolId]            = make_shared<ShortcutBarContentMessage>;
    id_to_builder[JobExperienceMultiUpdateMessage::protocolId]      = make_shared<JobExperienceMultiUpdateMessage>;
    id_to_builder[SequenceNumberRequestMessage::protocolId]         = make_shared<SequenceNumberRequestMessage>;
    id_to_builder[SequenceNumberMessage::protocolId]                = make_shared<SequenceNumberMessage>;
    id_to_builder[AlmanachCalendarDateMessage::protocolId]          = make_shared<AlmanachCalendarDateMessage>;
    id_to_builder[CharacterExperienceGainMessage::protocolId]       = make_shared<CharacterExperienceGainMessage>;
    id_to_builder[SpellListMessage::protocolId]                     = make_shared<SpellListMessage>;

    id_to_builder[GameContextCreateRequestMessage::protocolId]      = make_shared<GameContextCreateRequestMessage>;
    id_to_builder[GameContextCreateMessage::protocolId]             = make_shared<GameContextCreateMessage>;
    id_to_builder[GameContextDestroyMessage::protocolId]    = make_shared<GameContextDestroyMessage>;
    id_to_builder[CurrentMapMessage::protocolId]                    = make_shared<CurrentMapMessage>;

    id_to_builder[MapComplementaryInformationsDataMessage::protocolId]	= make_shared<MapComplementaryInformationsDataMessage>;
    id_to_builder[GameMapMovementMessage::protocolId]                   = make_shared<GameMapMovementMessage>;
    id_to_builder[StatedElementUpdatedMessage::protocolId]              = make_shared<StatedElementUpdatedMessage>;
    id_to_builder[InteractiveElementUpdatedMessage::protocolId]         = make_shared<InteractiveElementUpdatedMessage>;
    id_to_builder[InteractiveUsedMessage::protocolId]                   = make_shared<InteractiveUsedMessage>;
    id_to_builder[GameContextRemoveElementMessage::protocolId]          = make_shared<GameContextRemoveElementMessage>;
    id_to_builder[GameRolePlayShowActorMessage::protocolId]             = make_shared<GameRolePlayShowActorMessage>;
    id_to_builder[GameMapChangeOrientationMessage::protocolId]          = make_shared<GameMapChangeOrientationMessage>;
    id_to_builder[SetCharacterRestrictionsMessage::protocolId]          = make_shared<SetCharacterRestrictionsMessage>;
    id_to_builder[GameMapNoMovementMessage::protocolId]                 = make_shared<GameMapNoMovementMessage>;
	id_to_builder[GameEntitiesDispositionMessage::protocolId]       	= make_shared<GameEntitiesDispositionMessage>;

    id_to_builder[InteractiveUseRequestMessage::protocolId]     = make_shared<InteractiveUseRequestMessage>;
    id_to_builder[InteractiveUseEndedMessage::protocolId]       = make_shared<InteractiveUseEndedMessage>;

    id_to_builder[ChatAbstractServerMessage::protocolId]    = make_shared<ChatAbstractServerMessage>;
    id_to_builder[ChatServerMessage::protocolId]            = make_shared<ChatServerMessage>;

	id_to_builder[GameRolePlayPlayerFightFriendlyRequestedMessage::protocolId]	= make_shared<GameRolePlayPlayerFightFriendlyRequestedMessage>;
	id_to_builder[GameFightShowFighterMessage::protocolId]	                    = make_shared<GameFightShowFighterMessage>;
    id_to_builder[GameFightUpdateTeamMessage::protocolId]                       = make_shared<GameFightUpdateTeamMessage>;
    id_to_builder[FighterStatsListMessage::protocolId]                          = make_shared<FighterStatsListMessage>;

	id_to_builder[GameFightStartingMessage::protocolId]             = make_shared<GameFightStartingMessage>;
	id_to_builder[GameFightJoinMessage::protocolId]	                = make_shared<GameFightJoinMessage>;
	id_to_builder[GameFightHumanReadyStateMessage::protocolId]	    = make_shared<GameFightHumanReadyStateMessage>;

	id_to_builder[GameFightStartMessage::protocolId]        	    = make_shared<GameFightStartMessage>;
	id_to_builder[GameFightTurnReadyRequestMessage::protocolId]	    = make_shared<GameFightTurnReadyRequestMessage>;
	id_to_builder[GameFightNewRoundMessage::protocolId]	            = make_shared<GameFightNewRoundMessage>;
	id_to_builder[GameFightSynchronizeMessage::protocolId]	        = make_shared<GameFightSynchronizeMessage>;
	id_to_builder[GameFightTurnListMessage::protocolId]	            = make_shared<GameFightTurnListMessage>;
    id_to_builder[GameFightTurnStartMessage::protocolId]            = make_shared<GameFightTurnStartMessage>;

    id_to_builder[GameFightRefreshFighterMessage::protocolId]                   = make_shared<GameFightRefreshFighterMessage>;
    id_to_builder[AbstractGameActionMessage::protocolId]                        = make_shared<AbstractGameActionMessage>;
    id_to_builder[AbstractGameActionFightTargetedAbilityMessage::protocolId]    = make_shared<AbstractGameActionFightTargetedAbilityMessage>;
    id_to_builder[GameActionFightCloseCombatMessage::protocolId]                = make_shared<GameActionFightCloseCombatMessage>;
    id_to_builder[GameActionFightSpellCastMessage::protocolId]                  = make_shared<GameActionFightSpellCastMessage>;
    id_to_builder[GameActionFightNoSpellCastMessage::protocolId]                  = make_shared<GameActionFightNoSpellCastMessage>;
    id_to_builder[GameActionFightPointsVariationMessage::protocolId]            = make_shared<GameActionFightPointsVariationMessage>;
    id_to_builder[GameActionFightLifeAndShieldPointsLostMessage::protocolId]    = make_shared<GameActionFightLifeAndShieldPointsLostMessage>;
    id_to_builder[GameActionFightLifePointsLostMessage::protocolId]             = make_shared<GameActionFightLifePointsLostMessage>;
    id_to_builder[GameActionFightLifePointsGainMessage::protocolId]             = make_shared<GameActionFightLifePointsGainMessage>;
    id_to_builder[GameActionFightTeleportOnSameMapMessage::protocolId]          = make_shared<GameActionFightTeleportOnSameMapMessage>;
    id_to_builder[GameActionFightExchangePositionsMessage::protocolId]          = make_shared<GameActionFightExchangePositionsMessage>;
    id_to_builder[GameActionFightSlideMessage::protocolId]                      = make_shared<GameActionFightSlideMessage>;
    id_to_builder[GameActionFightMarkCellsMessage::protocolId]                  = make_shared<GameActionFightMarkCellsMessage>;
    id_to_builder[GameActionFightUnmarkCellsMessage::protocolId]                = make_shared<GameActionFightUnmarkCellsMessage>;
    id_to_builder[GameActionFightDeathMessage::protocolId]                      = make_shared<GameActionFightDeathMessage>;
    id_to_builder[GameActionFightKillMessage::protocolId]                       = make_shared<GameActionFightKillMessage>;

    id_to_builder[SequenceEndMessage::protocolId]                       = make_shared<SequenceEndMessage>;
    
    id_to_builder[UnknownDofusMessage::protocolId]                  = make_shared<UnknownDofusMessage>;
}

sp<Message> DofusMessageTypeHandler::generateMessageById(int id) {

    // Finds asked message's builder
    auto builderIt = id_to_builder.find(id);

    if(builderIt != id_to_builder.end() && builderIt->second) {
        // Message id was found and its builder is valid
        
        // Builds and returns the right message
        return builderIt->second();
    } else {
        // Message id was not found or the builder is not valid

        // Builds default message for debug
        return make_shared<UnknownDofusMessage>(id);
    }
}