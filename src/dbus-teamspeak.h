// -*- mode: c; indent-tabs-mode: nil; -*-
/// File: src/dbus-teamspeak.h
//
/// License:
// Copyright © 2015 Remy Goldschmidt <taktoa@gmail.com>
//
// This file is part of dbus-teamspeak.
//
// dbus-teamspeak is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// dbus-teamspeak is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with dbus-teamspeak. If not, see <http://www.gnu.org/licenses/>.
//
/// Author:     Remy Goldschmidt <taktoa@gmail.com>
/// Maintainer: Remy Goldschmidt <taktoa@gmail.com>
//
/// Homepage:   https://github.com/taktoa/dbus-teamspeak
//
/// Commentary:
//+/ TeamSpeak 3 DBUS plugin header file
//
/// Code:

#ifndef DBUS_TEAMSPEAK_H
#define DBUS_TEAMSPEAK_H

/* Customizable functions */
bool dbus_teamspeak_initialize();
void dbus_teamspeak_shutdown();

/* Required functions */
const char* ts3plugin_name();
const char* ts3plugin_version();
int ts3plugin_apiVersion();
const char* ts3plugin_author();
const char* ts3plugin_description();
void ts3plugin_setFunctionPointers(const struct TS3Functions funcs);
int ts3plugin_init();
void ts3plugin_shutdown();

/* Optional functions */
int ts3plugin_offersConfigure();
void ts3plugin_configure(void* handle,
                         void* qParentWidget);
void ts3plugin_registerPluginID(const char* ID);
const char* ts3plugin_commandKeyword();
int ts3plugin_processCommand(uint64 scHandlerID,
                             const char* command);
void ts3plugin_currentServerConnectionChanged(uint64 scHandlerID);
const char* ts3plugin_infoTitle();
void ts3plugin_infoData(uint64 scHandlerID,
                        uint64 ID,
                        enum PluginItemType type,
                        char** data);
void ts3plugin_freeMemory(void* data);
int ts3plugin_requestAutoload();
void ts3plugin_initMenus(struct PluginMenuItem*** menuItems,
                         char** menuIcon);
void ts3plugin_initHotkeys(struct PluginHotkey*** hotkeys);

/* ClientLib */
void ts3plugin_onConnectStatusChangeEvent(uint64 scHandlerID,
                                          int newStatus,
                                          unsigned int errorNumber);
void ts3plugin_onNewChannelEvent(uint64 scHandlerID,
                                 uint64 channelID,
                                 uint64 channelParentID);
void ts3plugin_onNewChannelCreatedEvent(uint64 scHandlerID,
                                        uint64 channelID,
                                        uint64 channelParentID,
                                        anyID invokerID,
                                        const char* invokerName,
                                        const char* invokerUID);
void ts3plugin_onDelChannelEvent(uint64 scHandlerID,
                                 uint64 channelID,
                                 anyID invokerID,
                                 const char* invokerName,
                                 const char* invokerUID);
void ts3plugin_onChannelMoveEvent(uint64 scHandlerID,
                                  uint64 channelID,
                                  uint64 newChannelParentID,
                                  anyID invokerID,
                                  const char* invokerName,
                                  const char* invokerUID);
void ts3plugin_onUpdateChannelEvent(uint64 scHandlerID,
                                    uint64 channelID);
void ts3plugin_onUpdateChannelEditedEvent(uint64 scHandlerID,
                                          uint64 channelID,
                                          anyID invokerID,
                                          const char* invokerName,
                                          const char* invokerUID);
void ts3plugin_onUpdateClientEvent(uint64 scHandlerID,
                                   anyID clientID,
                                   anyID invokerID,
                                   const char* invokerName,
                                   const char* invokerUID);
void ts3plugin_onClientMoveEvent(uint64 scHandlerID,
                                 anyID clientID,
                                 uint64 oldChannelID,
                                 uint64 newChannelID,
                                 int visibility,
                                 const char* moveMessage);
void ts3plugin_onClientMoveSubscriptionEvent(uint64 scHandlerID,
                                             anyID clientID,
                                             uint64 oldChannelID,
                                             uint64 newChannelID,
                                             int visibility);
void ts3plugin_onClientMoveTimeoutEvent(uint64 scHandlerID,
                                        anyID clientID,
                                        uint64 oldChannelID,
                                        uint64 newChannelID,
                                        int visibility,
                                        const char* timeoutMessage);
void ts3plugin_onClientMoveMovedEvent(uint64 scHandlerID,
                                      anyID clientID,
                                      uint64 oldChannelID,
                                      uint64 newChannelID,
                                      int visibility,
                                      anyID moverID,
                                      const char* moverName,
                                      const char* moverUID,
                                      const char* moveMessage);
void ts3plugin_onClientKickFromChannelEvent(uint64 scHandlerID,
                                            anyID clientID,
                                            uint64 oldChannelID,
                                            uint64 newChannelID,
                                            int visibility,
                                            anyID kickerID,
                                            const char* kickerName,
                                            const char* kickerUID,
                                            const char* kickMessage);
void ts3plugin_onClientKickFromServerEvent(uint64 scHandlerID,
                                           anyID clientID,
                                           uint64 oldChannelID,
                                           uint64 newChannelID,
                                           int visibility,
                                           anyID kickerID,
                                           const char* kickerName,
                                           const char* kickerUID,
                                           const char* kickMessage);
void ts3plugin_onClientIDsEvent(uint64 scHandlerID,
                                const char* clientUID,
                                anyID clientID,
                                const char* clientName);
void ts3plugin_onClientIDsFinishedEvent(uint64 scHandlerID);
void ts3plugin_onServerEditedEvent(uint64 scHandlerID,
                                   anyID editerID,
                                   const char* editerName,
                                   const char* editerUID);
void ts3plugin_onServerUpdatedEvent(uint64 scHandlerID);
int  ts3plugin_onServerErrorEvent(uint64 scHandlerID,
                                  const char* errorMessage,
                                  unsigned int error,
                                  const char* returnCode,
                                  const char* extraMessage);
void ts3plugin_onServerStopEvent(uint64 scHandlerID,
                                 const char* shutdownMessage);
int  ts3plugin_onTextMessageEvent(uint64 scHandlerID,
                                  anyID targetMode,
                                  anyID toID,
                                  anyID fromID,
                                  const char* fromName,
                                  const char* fromUID,
                                  const char* message,
                                  int ffIgnored);
void ts3plugin_onTalkStatusChangeEvent(uint64 scHandlerID,
                                       int status,
                                       int isReceivedWhisper,
                                       anyID clientID);
void ts3plugin_onConnectionInfoEvent(uint64 scHandlerID,
                                     anyID clientID);
void ts3plugin_onServerConnectionInfoEvent(uint64 scHandlerID);
void ts3plugin_onChannelSubscribeEvent(uint64 scHandlerID,
                                       uint64 channelID);
void ts3plugin_onChannelSubscribeFinishedEvent(uint64 scHandlerID);
void ts3plugin_onChannelUnsubscribeEvent(uint64 scHandlerID,
                                         uint64 channelID);
void ts3plugin_onChannelUnsubscribeFinishedEvent(uint64 scHandlerID);
void ts3plugin_onChannelDescriptionUpdateEvent(uint64 scHandlerID,
                                               uint64 channelID);
void ts3plugin_onChannelPasswordChangedEvent(uint64 scHandlerID,
                                             uint64 channelID);
void ts3plugin_onPlaybackShutdownCompleteEvent(uint64 scHandlerID);
void ts3plugin_onSoundDeviceListChangedEvent(const char* modeID,
                                             int playOrCap);
void ts3plugin_onEditPlaybackVoiceDataEvent(uint64 scHandlerID,
                                            anyID clientID,
                                            short* samples,
                                            int sampleCount,
                                            int channels);
void ts3plugin_onEditPostProcessVoiceDataEvent(uint64 scHandlerID,
                                               anyID clientID,
                                               short* samples,
                                               int sampleCount,
                                               int channels,
                                               const unsigned int* spkArray,
                                               unsigned int* fillMask);
void ts3plugin_onEditMixedPlaybackVoiceDataEvent(uint64 scHandlerID,
                                                 short* samples,
                                                 int sampleCount,
                                                 int channels,
                                                 const unsigned int* spkArray,
                                                 unsigned int* fillMask);
void ts3plugin_onEditCapturedVoiceDataEvent(uint64 scHandlerID,
                                            short* samples,
                                            int sampleCount,
                                            int channels,
                                            int* edited);
void ts3plugin_onCustom3dRolloffCalculationClientEvent(uint64 scHandlerID,
                                                       anyID clientID,
                                                       float distance,
                                                       float* volume);
void ts3plugin_onCustom3dRolloffCalculationWaveEvent(uint64 scHandlerID,
                                                     uint64 waveHandle,
                                                     float distance,
                                                     float* volume);
void ts3plugin_onUserLoggingMessageEvent(const char* logMessage,
                                         int logLevel,
                                         const char* logChannel,
                                         uint64 logID,
                                         const char* logTime,
                                         const char* completeLogString);

/* Clientlib rare */
void ts3plugin_onClientBanFromServerEvent(uint64 scHandlerID,
                                          anyID clientID,
                                          uint64 oldChannelID,
                                          uint64 newChannelID,
                                          int visibility,
                                          anyID kickerID,
                                          const char* kickerName,
                                          const char* kickerUID,
                                          uint64 time,
                                          const char* kickMessage);
int  ts3plugin_onClientPokeEvent(uint64 scHandlerID,
                                 anyID fromClientID,
                                 const char* pokerName,
                                 const char* pokerUID,
                                 const char* message,
                                 int ffIgnored);
void ts3plugin_onClientSelfVariableUpdateEvent(uint64 scHandlerID,
                                               int flag,
                                               const char* oldValue,
                                               const char* newValue);
void ts3plugin_onFileListEvent(uint64 scHandlerID,
                               uint64 channelID,
                               const char* path,
                               const char* name,
                               uint64 size,
                               uint64 datetime,
                               int type,
                               uint64 incompletesize,
                               const char* returnCode);
void ts3plugin_onFileListFinishedEvent(uint64 scHandlerID,
                                       uint64 channelID,
                                       const char* path);
void ts3plugin_onFileInfoEvent(uint64 scHandlerID,
                               uint64 channelID,
                               const char* name,
                               uint64 size,
                               uint64 datetime);
void ts3plugin_onServerGroupListEvent(uint64 scHandlerID,
                                      uint64 serverGroupID,
                                      const char* name,
                                      int type,
                                      int iconID,
                                      int saveDB);
void ts3plugin_onServerGroupListFinishedEvent(uint64 scHandlerID);
void ts3plugin_onServerGroupByClientIDEvent(uint64 scHandlerID,
                                            const char* name,
                                            uint64 serverGroupList,
                                            uint64 clientDBID);
void ts3plugin_onServerGroupPermListEvent(uint64 scHandlerID,
                                          uint64 serverGroupID,
                                          unsigned int permissionID,
                                          int permissionValue,
                                          int permissionNegated,
                                          int permissionSkip);
void ts3plugin_onServerGroupPermListFinishedEvent(uint64 scHandlerID,
                                                  uint64 serverGroupID);
void ts3plugin_onServerGroupClientListEvent(uint64 scHandlerID,
                                            uint64 serverGroupID,
                                            uint64 clientDBID,
                                            const char* clientName,
                                            const char* clientUID);
void ts3plugin_onChannelGroupListEvent(uint64 scHandlerID,
                                       uint64 channelGroupID,
                                       const char* name,
                                       int type,
                                       int iconID,
                                       int saveDB);
void ts3plugin_onChannelGroupListFinishedEvent(uint64 scHandlerID);
void ts3plugin_onChannelGroupPermListEvent(uint64 scHandlerID,
                                           uint64 channelGroupID,
                                           unsigned int permissionID,
                                           int permissionValue,
                                           int permissionNegated,
                                           int permissionSkip);
void ts3plugin_onChannelGroupPermListFinishedEvent(uint64 scHandlerID,
                                                   uint64 channelGroupID);
void ts3plugin_onChannelPermListEvent(uint64 scHandlerID,
                                      uint64 channelID,
                                      unsigned int permissionID,
                                      int permissionValue,
                                      int permissionNegated,
                                      int permissionSkip);
void ts3plugin_onChannelPermListFinishedEvent(uint64 scHandlerID,
                                              uint64 channelID);
void ts3plugin_onClientPermListEvent(uint64 scHandlerID,
                                     uint64 clientDBID,
                                     unsigned int permissionID,
                                     int permissionValue,
                                     int permissionNegated,
                                     int permissionSkip);
void ts3plugin_onClientPermListFinishedEvent(uint64 scHandlerID,
                                             uint64 clientDBID);
void ts3plugin_onChannelClientPermListEvent(uint64 scHandlerID,
                                            uint64 channelID,
                                            uint64 clientDBID,
                                            unsigned int permissionID,
                                            int permissionValue,
                                            int permissionNegated,
                                            int permissionSkip);
void ts3plugin_onChannelClientPermListFinishedEvent(uint64 scHandlerID,
                                                    uint64 channelID,
                                                    uint64 clientDBID);
void ts3plugin_onClientChannelGroupChangedEvent(uint64 scHandlerID,
                                                uint64 channelGroupID,
                                                uint64 channelID,
                                                anyID clientID,
                                                anyID invokerClientID,
                                                const char* invokerName,
                                                const char* invokerUID);
int  ts3plugin_onServerPermissionErrorEvent(uint64 scHandlerID,
                                            const char* errorMessage,
                                            unsigned int error,
                                            const char* returnCode,
                                            unsigned int failedPermissionID);
void ts3plugin_onPermissionListGroupEndIDEvent(uint64 scHandlerID,
                                               unsigned int groupEndID);
void ts3plugin_onPermissionListEvent(uint64 scHandlerID,
                                     unsigned int permissionID,
                                     const char* permissionName,
                                     const char* permissionDescription);
void ts3plugin_onPermissionListFinishedEvent(uint64 scHandlerID);
void ts3plugin_onPermissionOverviewEvent(uint64 scHandlerID,
                                         uint64 clientDBID,
                                         uint64 channelID,
                                         int overviewType,
                                         uint64 overviewID1,
                                         uint64 overviewID2,
                                         unsigned int permissionID,
                                         int permissionValue,
                                         int permissionNegated,
                                         int permissionSkip);
void ts3plugin_onPermissionOverviewFinishedEvent(uint64 scHandlerID);
void ts3plugin_onServerGroupClientAddedEvent(uint64 scHandlerID,
                                             anyID clientID,
                                             const char* clientName,
                                             const char* clientUID,
                                             uint64 serverGroupID,
                                             anyID invokerClientID,
                                             const char* invokerName,
                                             const char* invokerUID);
void ts3plugin_onServerGroupClientDeletedEvent(uint64 scHandlerID,
                                               anyID clientID,
                                               const char* clientName,
                                               const char* clientUID,
                                               uint64 serverGroupID,
                                               anyID invokerClientID,
                                               const char* invokerName,
                                               const char* invokerUID);
void ts3plugin_onClientNeededPermissionsEvent(uint64 scHandlerID,
                                              unsigned int permissionID,
                                              int permissionValue);
void ts3plugin_onClientNeededPermissionsFinishedEvent(uint64 scHandlerID);
void ts3plugin_onFileTransferStatusEvent(anyID transferID,
                                         unsigned int status,
                                         const char* statusMessage,
                                         uint64 remotefileSize,
                                         uint64 scHandlerID);
void ts3plugin_onClientChatClosedEvent(uint64 scHandlerID,
                                       anyID clientID,
                                       const char* clientUID);
void ts3plugin_onClientChatComposingEvent(uint64 scHandlerID,
                                          anyID clientID,
                                          const char* clientUID);
void ts3plugin_onServerLogEvent(uint64 scHandlerID,
                                const char* logMsg);
void ts3plugin_onServerLogFinishedEvent(uint64 scHandlerID,
                                        uint64 lastPos,
                                        uint64 fileSize);
void ts3plugin_onMessageListEvent(uint64 scHandlerID,
                                  uint64 messageID,
                                  const char* fromClientUID,
                                  const char* subject,
                                  uint64 timestamp,
                                  int flagRead);
void ts3plugin_onMessageGetEvent(uint64 scHandlerID,
                                 uint64 messageID,
                                 const char* fromClientUID,
                                 const char* subject,
                                 const char* message,
                                 uint64 timestamp);
void ts3plugin_onClientDBIDfromUIDEvent(uint64 scHandlerID,
                                        const char* clientUID,
                                        uint64 clientDBID);
void ts3plugin_onClientNamefromUIDEvent(uint64 scHandlerID,
                                        const char* clientUID,
                                        uint64 clientDBID,
                                        const char* clientName);
void ts3plugin_onClientNamefromDBIDEvent(uint64 scHandlerID,
                                         const char* clientUID,
                                         uint64 clientDBID,
                                         const char* clientName);
void ts3plugin_onComplainListEvent(uint64 scHandlerID,
                                   uint64 targetClientDBID,
                                   const char* targetClientName,
                                   uint64 fromClientDBID,
                                   const char* fromClientName,
                                   const char* complainReason,
                                   uint64 timestamp);
void ts3plugin_onBanListEvent(uint64 scHandlerID,
                              uint64 banID,
                              const char* IP,
                              const char* name,
                              const char* UID,
                              uint64 creationTime,
                              uint64 durationTime,
                              const char* invokerName,
                              uint64 invokerClDBID,
                              const char* invokerUID,
                              const char* reason,
                              int numberOfEnforcements,
                              const char* lastName);
void ts3plugin_onClientServerQueryLoginPasswordEvent(uint64 scHandlerID,
                                                     const char* loginPassword);
void ts3plugin_onPluginCommandEvent(uint64 scHandlerID,
                                    const char* pluginName,
                                    const char* pluginCommand);
void ts3plugin_onIncomingClientQueryEvent(uint64 scHandlerID,
                                          const char* commandText);
void ts3plugin_onServerTemporaryPasswordListEvent(uint64 scHandlerID,
                                                  const char* clientName,
                                                  const char* clientUID,
                                                  const char* description,
                                                  const char* password,
                                                  uint64 timestampStart,
                                                  uint64 timestampEnd,
                                                  uint64 targetChannelID,
                                                  const char* targetChannelPW);

/* Client UI callbacks */
void ts3plugin_onAvatarUpdated(uint64 scHandlerID,
                               anyID clientID,
                               const char* avatarPath);
void ts3plugin_onMenuItemEvent(uint64 scHandlerID,
                               enum PluginMenuType type,
                               int menuItemID,
                               uint64 selectedItemID);
void ts3plugin_onHotkeyEvent(const char* keyword);
void ts3plugin_onHotkeyRecordedEvent(const char* keyword,
                                     const char* key);
void ts3plugin_onClientDisplayNameChanged(uint64 scHandlerID,
                                          anyID clientID,
                                          const char* displayName,
                                          const char* clientUID);
#endif
