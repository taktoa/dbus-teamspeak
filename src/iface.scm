(define iface-signals
  '((onConnectStatusChangeEvent
     (t scHandlerID)
     (i newStatus)
     (u errorNumber))

    (onNewChannelEvent
     (t scHandlerID)
     (t channelID)
     (t channelParentID))

    (onNewChannelCreatedEvent
     (t scHandlerID)
     (t channelID)
     (t channelParentID)
     (q invokerID)
     (s invokerName)
     (s invokerUID))

    (onDelChannelEvent
     (t scHandlerID)
     (t channelID)
     (q invokerID)
     (s invokerName)
     (s invokerUID))

    (onChannelMoveEvent
     (t scHandlerID)
     (t channelID)
     (t newChannelParentID)
     (q invokerID)
     (s invokerName)
     (s invokerUID))

    (onUpdateChannelEvent
     (t scHandlerID)
     (t channelID))

    (onUpdateChannelEditedEvent
     (t scHandlerID)
     (t channelID)
     (q invokerID)
     (s invokerName)
     (s invokerUID))

    (onUpdateClientEvent
     (t scHandlerID)
     (q clientID)
     (q invokerID)
     (s invokerName)
     (s invokerUID))

    (onClientMoveEvent
     (t scHandlerID)
     (q clientID)
     (t oldChannelID)
     (t newChannelID)
     (i visibility)
     (s moveMessage))

    (onClientMoveSubscriptionEvent
     (t scHandlerID)
     (q clientID)
     (t oldChannelID)
     (t newChannelID)
     (i visibility))

    (onClientMoveTimeoutEvent
     (t scHandlerID)
     (q clientID)
     (t oldChannelID)
     (t newChannelID)
     (i visibility)
     (s timeoutMessage))

    (onClientMoveMovedEvent
     (t scHandlerID)
     (q clientID)
     (t oldChannelID)
     (t newChannelID)
     (i visibility)
     (q moverID)
     (s moverName)
     (s moverUID)
     (s moveMessage))

    (onClientKickFromChannelEvent
     (t scHandlerID)
     (q clientID)
     (t oldChannelID)
     (t newChannelID)
     (i visibility)
     (q kickerID)
     (s kickerName)
     (s kickerUID)
     (s kickMessage))

    (onClientKickFromServerEvent
     (t scHandlerID)
     (q clientID)
     (t oldChannelID)
     (t newChannelID)
     (i visibility)
     (q kickerID)
     (s kickerName)
     (s kickerUID)
     (s kickMessage))

    (onClientIDsEvent
     (t scHandlerID)
     (s clientUID)
     (q clientID)
     (s clientName))

    (onClientIDsFinishedEvent
     (t scHandlerID))

    (onServerEditedEvent
     (t scHandlerID)
     (q editerID)
     (s editerName)
     (s editerUID))

    (onServerUpdatedEvent
     (t scHandlerID))

    (onServerErrorEvent
     (t scHandlerID)
     (s errorMessage)
     (u error)
     (s returnCode)
     (s extraMessage))

    (onServerStopEvent
     (t scHandlerID)
     (s shutdownMessage))

    (onTextMessageEvent
     (t scHandlerID)
     (q targetMode)
     (q toID)
     (q fromID)
     (s fromName)
     (s fromUID)
     (s message)
     (i ffIgnored))

    (onTalkStatusChangeEvent
     (t scHandlerID)
     (i status)
     (i isReceivedWhisper)
     (q clientID))

    (onConnectionInfoEvent
     (t scHandlerID)
     (q clientID))

    (onServerConnectionInfoEvent
     (t scHandlerID))

    (onChannelSubscribeEvent
     (t scHandlerID)
     (t channelID))

    (onChannelSubscribeFinishedEvent
     (t scHandlerID))

    (onChannelUnsubscribeEvent
     (t scHandlerID)
     (t channelID))

    (onChannelUnsubscribeFinishedEvent
     (t scHandlerID))

    (onChannelDescriptionUpdateEvent
     (t scHandlerID)
     (t channelID))

    (onChannelPasswordChangedEvent
     (t scHandlerID)
     (t channelID))

    (onPlaybackShutdownCompleteEvent
     (t scHandlerID))

    (onSoundDeviceListChangedEvent
     (s modeID)
     (i playOrCap))

    (onEditPlaybackVoiceDataEvent
     (t scHandlerID)
     (q clientID)
     (an samples)
     (i sampleCount)
     (i channels))

    (onEditPostProcessVoiceDataEvent
     (t scHandlerID)
     (q clientID)
     (an samples)
     (i sampleCount)
     (i channels)
     (ai spkArray))

    (onEditCapturedVoiceDataEvent
     (t scHandlerID)
     (an samples)
     (i sampleCount)
     (i channels))

    (onUserLoggingMessageEvent
     (s logMessage)
     (i logLevel)
     (s logChannel)
     (t logID)
     (s logTime)
     (s completeLogString))

    (onClientBanFromServerEvent
     (t scHandlerID)
     (q clientID)
     (t oldChannelID)
     (t newChannelID)
     (i visibility)
     (q kickerID)
     (s kickerName)
     (s kickerUID)
     (t time)
     (s kickMessage))

    (onClientPokeEvent
     (t scHandlerID)
     (q fromClientID)
     (s pokerName)
     (s pokerUID)
     (s message)
     (i ffIgnored))

    (onClientSelfVariableUpdateEvent
     (t scHandlerID)
     (i flag)
     (s oldValue)
     (s newValue))

    (onFileListEvent
     (t scHandlerID)
     (t channelID)
     (s path)
     (s name)
     (t size)
     (t datetime)
     (i type)
     (t incompletesize)
     (s returnCode))

    (onFileListFinishedEvent
     (t scHandlerID)
     (t channelID)
     (s path))

    (onFileInfoEvent
     (t scHandlerID)
     (t channelID)
     (s name)
     (t size)
     (t datetime))

    (onServerGroupListEvent
     (t scHandlerID)
     (t serverGroupID)
     (s name)
     (i type)
     (i iconID)
     (i saveDB))

    (onServerGroupListFinishedEvent
     (t scHandlerID))

    (onServerGroupByClientIDEvent
     (t scHandlerID)
     (s name)
     (t serverGroupList)
     (t clientDBID))

    (onServerGroupPermListEvent
     (t scHandlerID)
     (t serverGroupID)
     (u permissionID)
     (i permissionValue)
     (i permissionNegated)
     (i permissionSkip))

    (onServerGroupPermListFinishedEvent
     (t scHandlerID)
     (t serverGroupID))

    (onServerGroupClientListEvent
     (t scHandlerID)
     (t serverGroupID)
     (t clientDBID)
     (s clientName)
     (s clientUID))

    (onChannelGroupListEvent
     (t scHandlerID)
     (t channelGroupID)
     (s name)
     (i type)
     (i iconID)
     (i saveDB))

    (onChannelGroupListFinishedEvent
     (t scHandlerID))

    (onChannelGroupPermListEvent
     (t scHandlerID)
     (t channelGroupID)
     (u permissionID)
     (i permissionValue)
     (i permissionNegated)
     (i permissionSkip))

    (onChannelGroupPermListFinishedEvent
     (t scHandlerID)
     (t channelGroupID))

    (onChannelPermListEvent
     (t scHandlerID)
     (t channelID)
     (u permissionID)
     (i permissionValue)
     (i permissionNegated)
     (i permissionSkip))

    (onChannelPermListFinishedEvent
     (t scHandlerID)
     (t channelID))

    (onClientPermListEvent
     (t scHandlerID)
     (t clientDBID)
     (u permissionID)
     (i permissionValue)
     (i permissionNegated)
     (i permissionSkip))

    (onClientPermListFinishedEvent
     (t scHandlerID)
     (t clientDBID))

    (onChannelClientPermListEvent
     (t scHandlerID)
     (t channelID)
     (t clientDBID)
     (u permissionID)
     (i permissionValue)
     (i permissionNegated)
     (i permissionSkip))

    (onChannelClientPermListFinishedEvent
     (t scHandlerID)
     (t channelID)
     (t clientDBID))

    (onClientChannelGroupChangedEvent
     (t scHandlerID)
     (t channelGroupID)
     (t channelID)
     (q clientID)
     (q invokerClientID)
     (s invokerName)
     (s invokerUID))

    (onServerPermissionErrorEvent
     (t scHandlerID)
     (s errorMessage)
     (u error)
     (s returnCode)
     (u failedPermissionID))

    (onPermissionListGroupEndIDEvent
     (t scHandlerID)
     (u groupEndID))

    (onPermissionListEvent
     (t scHandlerID)
     (u permissionID)
     (s permissionName)
     (s permissionDescription))

    (onPermissionListFinishedEvent
     (t scHandlerID))

    (onPermissionOverviewEvent
     (t scHandlerID)
     (t clientDBID)
     (t channelID)
     (i overviewType)
     (t overviewID1)
     (t overviewID2)
     (u permissionID)
     (i permissionValue)
     (i permissionNegated)
     (i permissionSkip))

    (onPermissionOverviewFinishedEvent
     (t scHandlerID))

    (onServerGroupClientAddedEvent
     (t scHandlerID)
     (q clientID)
     (s clientName)
     (s clientUID)
     (t serverGroupID)
     (q invokerClientID)
     (s invokerName)
     (s invokerUID))

    (onServerGroupClientDeletedEvent
     (t scHandlerID)
     (q clientID)
     (s clientName)
     (s clientUID)
     (t serverGroupID)
     (q invokerClientID)
     (s invokerName)
     (s invokerUID))

    (onClientNeededPermissionsEvent
     (t scHandlerID)
     (u permissionID)
     (i permissionValue))

    (onClientNeededPermissionsFinishedEvent
     (t scHandlerID))

    (onFileTransferStatusEvent
     (q transferID)
     (u status)
     (s statusMessage)
     (t remotefileSize)
     (t scHandlerID))

    (onClientChatClosedEvent
     (t scHandlerID)
     (q clientID)
     (s clientUID))

    (onClientChatComposingEvent
     (t scHandlerID)
     (q clientID)
     (s clientUID))

    (onServerLogEvent
     (t scHandlerID)
     (s logMsg))

    (onServerLogFinishedEvent
     (t scHandlerID)
     (t lastPos)
     (t fileSize))

    (onMessageListEvent
     (t scHandlerID)
     (t messageID)
     (s fromClientUID)
     (s subject)
     (t timestamp)
     (i flagRead))

    (onMessageGetEvent
     (t scHandlerID)
     (t messageID)
     (s fromClientUID)
     (s subject)
     (s message)
     (t timestamp))

    (onClientDBIDfromUIDEvent
     (t scHandlerID)
     (s clientUID)
     (t clientDBID))

    (onClientNamefromUIDEvent
     (t scHandlerID)
     (s clientUID)
     (t clientDBID)
     (s clientName))

    (onClientNamefromDBIDEvent
     (t scHandlerID)
     (s clientUID)
     (t clientDBID)
     (s clientName))

    (onComplainListEvent
     (t scHandlerID)
     (t targetClientDBID)
     (s targetClientName)
     (t fromClientDBID)
     (s fromClientName)
     (s complainReason)
     (t timestamp))

    (onBanListEvent
     (t scHandlerID)
     (t banID)
     (s IP)
     (s name)
     (s UID)
     (t creationTime)
     (t durationTime)
     (s invokerName)
     (t invokerClDBID)
     (s invokerUID)
     (s reason)
     (i numberOfEnforcements)
     (s lastName))

    (onClientServerQueryLoginPasswordEvent
     (t scHandlerID)
     (s loginPassword))

    (onPluginCommandEvent
     (t scHandlerID)
     (s pluginName)
     (s pluginCommand))

    (onIncomingClientQueryEvent
     (t scHandlerID)
     (s commandText))

    (onServerTemporaryPasswordListEvent
     (t scHandlerID)
     (s clientName)
     (s clientUID)
     (s description)
     (s password)
     (t timestampStart)
     (t timestampEnd)
     (t targetChannelID)
     (s targetChannelPW))

    (onAvatarUpdated
     (t scHandlerID)
     (q clientID)
     (s avatarPath))

    (onMenuItemEvent
     (t scHandlerID)
     (enum PluginMenuType type)
     (i menuItemID)
     (t selectedItemID))

    (onHotkeyEvent
     (s keyword))

    (onHotkeyRecordedEvent
     (s keyword)
     (s key))

    (onClientDisplayNameChanged
     (t scHandlerID)
     (q clientID)
     (s displayName)
     (s clientUID))))
