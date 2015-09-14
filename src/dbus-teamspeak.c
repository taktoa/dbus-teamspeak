// -*- mode: c; indent-tabs-mode: nil; -*-
/// File: src/dbus-teamspeak.c
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
//+/ TeamSpeak 3 DBUS plugin
//
/// Code:

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "public_errors.h"
#include "public_errors_rare.h"
#include "public_definitions.h"
#include "public_rare_definitions.h"
#include "ts3_functions.h"
#include "dbus-teamspeak.h"

static struct TS3Functions ts3Functions;

#define PLUGIN_API_VERSION 20

#define PATH_BUFSIZE 512
#define COMMAND_BUFSIZE 128
#define INFODATA_BUFSIZE 128
#define SERVERINFO_BUFSIZE 256
#define CHANNELINFO_BUFSIZE 512
#define RETURNCODE_BUFSIZE 128


// -----------------------------------------------------------------------------
// --------------------------- Customizable functions --------------------------
// -----------------------------------------------------------------------------


// Initialization
bool dbus_teamspeak_initialize() {
    printf("PLUGIN: init\n");

    // Here's an example of how to query application, resource
    // and configuration paths from client
    char appPath[PATH_BUFSIZE];
    char resourcesPath[PATH_BUFSIZE];
    char configPath[PATH_BUFSIZE];
    char pluginPath[PATH_BUFSIZE];

    ts3Functions.getAppPath(appPath, PATH_BUFSIZE);
    ts3Functions.getResourcesPath(resourcesPath, PATH_BUFSIZE);
    ts3Functions.getConfigPath(configPath, PATH_BUFSIZE);
    ts3Functions.getPluginPath(pluginPath, PATH_BUFSIZE);

    printf("PLUGIN:\n");
    printf("* Application path: %s\n", appPath);
    printf("* Resources   path: %s\n", resourcesPath);
    printf("* Config      path: %s\n", configPath);
    printf("* Plugin      path: %s\n", pluginPath);

    return true;
}

// Cleanup
void dbus_teamspeak_shutdown() {
    printf("PLUGIN: shutdown\n");
}


// -----------------------------------------------------------------------------
// ----------------------------- Required functions ----------------------------
// -----------------------------------------------------------------------------


// If any of these required functions is not implemented,
// TS3 will refuse to load the plugin

// Unique name identifying this plugin
const char* ts3plugin_name() {
    return "Test Plugin";
}

// Plugin version
const char* ts3plugin_version() {
    return "1.2";
}

// Plugin API version.
// Must be the same as the client's API major version,
// otherwise the plugin will fail to load.
int ts3plugin_apiVersion() {
    return PLUGIN_API_VERSION;
}

// Plugin author
const char* ts3plugin_author() {
    return "TeamSpeak Systems GmbH";
}

// Plugin description
const char* ts3plugin_description() {
    return "This is a demo plugin.";
}

// Set TeamSpeak 3 callback functions
void ts3plugin_setFunctionPointers(const struct TS3Functions funcs) {
    ts3Functions = funcs;
}

// Custom code called right after loading the plugin.
// Returns 0 on success, 1 on failure.
// If the function returns 1 on failure, the plugin will be unloaded again.
int ts3plugin_init() {
    bool success = dbus_teamspeak_initialize();
    return (success ? 0 : 1);
}


// Custom code called right before the plugin is unloaded
void ts3plugin_shutdown() {
    dbus_teamspeak_shutdown();
}


// -----------------------------------------------------------------------------
// ----------------------------- Optional functions ----------------------------
// -----------------------------------------------------------------------------


void ts3plugin_currentServerConnectionChanged(uint64 scHandlerID) {
}

const char* ts3plugin_infoTitle() {
    return "Test plugin info";
}

void ts3plugin_onConnectStatusChangeEvent(uint64 scHandlerID,
                                          int newStatus,
                                          unsigned int errorNumber) {
}

void ts3plugin_onNewChannelEvent(uint64 scHandlerID,
                                 uint64 channelID,
                                 uint64 channelParentID) {
}

void ts3plugin_onNewChannelCreatedEvent(uint64 scHandlerID,
                                        uint64 channelID,
                                        uint64 channelParentID,
                                        anyID invokerID,
                                        const char* invokerName,
                                        const char* invokerUID) {
}

void ts3plugin_onDelChannelEvent(uint64 scHandlerID,
                                 uint64 channelID,
                                 anyID invokerID,
                                 const char* invokerName,
                                 const char* invokerUID) {
}

void ts3plugin_onChannelMoveEvent(uint64 scHandlerID,
                                  uint64 channelID,
                                  uint64 newChannelParentID,
                                  anyID invokerID,
                                  const char* invokerName,
                                  const char* invokerUID) {
}

void ts3plugin_onUpdateChannelEvent(uint64 scHandlerID,
                                    uint64 channelID) {
}

void ts3plugin_onUpdateChannelEditedEvent(uint64 scHandlerID,
                                          uint64 channelID,
                                          anyID invokerID,
                                          const char* invokerName,
                                          const char* invokerUID) {
}

void ts3plugin_onUpdateClientEvent(uint64 scHandlerID,
                                   anyID clientID,
                                   anyID invokerID,
                                   const char* invokerName,
                                   const char* invokerUID) {
}

void ts3plugin_onClientMoveEvent(uint64 scHandlerID,
                                 anyID clientID,
                                 uint64 oldChannelID,
                                 uint64 newChannelID,
                                 int visibility,
                                 const char* moveMessage) {
}

void ts3plugin_onClientMoveSubscriptionEvent(uint64 scHandlerID,
                                             anyID clientID,
                                             uint64 oldChannelID,
                                             uint64 newChannelID,
                                             int visibility) {
}

void ts3plugin_onClientMoveTimeoutEvent(uint64 scHandlerID,
                                        anyID clientID,
                                        uint64 oldChannelID,
                                        uint64 newChannelID,
                                        int visibility,
                                        const char* timeoutMessage) {
}

void ts3plugin_onClientMoveMovedEvent(uint64 scHandlerID,
                                      anyID clientID,
                                      uint64 oldChannelID,
                                      uint64 newChannelID,
                                      int visibility,
                                      anyID moverID,
                                      const char* moverName,
                                      const char* moverUID,
                                      const char* moveMessage) {
}

void ts3plugin_onClientKickFromChannelEvent(uint64 scHandlerID,
                                            anyID clientID,
                                            uint64 oldChannelID,
                                            uint64 newChannelID,
                                            int visibility,
                                            anyID kickerID,
                                            const char* kickerName,
                                            const char* kickerUID,
                                            const char* kickMessage) {
}

void ts3plugin_onClientKickFromServerEvent(uint64 scHandlerID,
                                           anyID clientID,
                                           uint64 oldChannelID,
                                           uint64 newChannelID,
                                           int visibility,
                                           anyID kickerID,
                                           const char* kickerName,
                                           const char* kickerUID,
                                           const char* kickMessage) {
}

void ts3plugin_onClientIDsEvent(uint64 scHandlerID,
                                const char* clientUID,
                                anyID clientID,
                                const char* clientName) {
}

void ts3plugin_onClientIDsFinishedEvent(uint64 scHandlerID) {
}

void ts3plugin_onServerEditedEvent(uint64 scHandlerID,
                                   anyID editerID,
                                   const char* editerName,
                                   const char* editerUID) {
}

void ts3plugin_onServerUpdatedEvent(uint64 scHandlerID) {
}

int ts3plugin_onServerErrorEvent(uint64 scHandlerID,
                                 const char* errorMessage,
                                 unsigned int error,
                                 const char* returnCode,
                                 const char* extraMessage) {
    if(returnCode) {
        // A plugin could now check the returnCode with previously
        // (when calling a function) remembered returnCodes and
        // react accordingly.
        // In case of using a a plugin return code, the plugin can return:
        // 0: Client will continue handling this error (print to chat tab)
        // 1: Client will ignore this error, the plugin has handled it
        return 1;
    }
    // If no plugin return code was used,
    // the return value of this function is ignored.
    return 0;
}

void ts3plugin_onServerStopEvent(uint64 scHandlerID,
                                 const char* shutdownMessage) {
}

int ts3plugin_onTextMessageEvent(uint64 scHandlerID,
                                 anyID targetMode,
                                 anyID toID,
                                 anyID fromID,
                                 const char* fromName,
                                 const char* fromUID,
                                 const char* message,
                                 int ffIgnored) {
    // 0 = handle normally
    // 1 = client will ignore the text message
    return 0;
}

void ts3plugin_onTalkStatusChangeEvent(uint64 scHandlerID,
                                       int status,
                                       int isReceivedWhisper,
                                       anyID clientID) {
}

void ts3plugin_onConnectionInfoEvent(uint64 scHandlerID,
                                     anyID clientID) {
}

void ts3plugin_onServerConnectionInfoEvent(uint64 scHandlerID) {
}

void ts3plugin_onChannelSubscribeEvent(uint64 scHandlerID,
                                       uint64 channelID) {
}

void ts3plugin_onChannelSubscribeFinishedEvent(uint64 scHandlerID) {
}

void ts3plugin_onChannelUnsubscribeEvent(uint64 scHandlerID,
                                         uint64 channelID) {
}

void ts3plugin_onChannelUnsubscribeFinishedEvent(uint64 scHandlerID) {
}

void ts3plugin_onChannelDescriptionUpdateEvent(uint64 scHandlerID,
                                               uint64 channelID) {
}

void ts3plugin_onChannelPasswordChangedEvent(uint64 scHandlerID,
                                             uint64 channelID) {
}

void ts3plugin_onPlaybackShutdownCompleteEvent(uint64 scHandlerID) {
}

void ts3plugin_onSoundDeviceListChangedEvent(const char* modeID,
                                             int playOrCap) {
}

void ts3plugin_onEditPlaybackVoiceDataEvent(uint64 scHandlerID,
                                            anyID clientID,
                                            short* samples,
                                            int sampleCount,
                                            int channels) {
}

void ts3plugin_onEditPostProcessVoiceDataEvent(uint64 scHandlerID,
                                               anyID clientID,
                                               short* samples,
                                               int sampleCount,
                                               int channels,
                                               const unsigned int* spkArray,
                                               unsigned int* fillMask) {
}

void ts3plugin_onEditMixedPlaybackVoiceDataEvent(uint64 scHandlerID,
                                                 short* samples,
                                                 int sampleCount,
                                                 int channels,
                                                 const unsigned int* spkArray,
                                                 unsigned int* fillMask) {
}

void ts3plugin_onEditCapturedVoiceDataEvent(uint64 scHandlerID,
                                            short* samples,
                                            int sampleCount,
                                            int channels,
                                            int* edited) {
}

void ts3plugin_onCustom3dRolloffCalculationClientEvent(uint64 scHandlerID,
                                                       anyID clientID,
                                                       float distance,
                                                       float* volume) {
}

void ts3plugin_onCustom3dRolloffCalculationWaveEvent(uint64 scHandlerID,
                                                     uint64 waveHandle,
                                                     float distance,
                                                     float* volume) {
}

void ts3plugin_onUserLoggingMessageEvent(const char* logMessage,
                                         int logLevel,
                                         const char* logChannel,
                                         uint64 logID,
                                         const char* logTime,
                                         const char* completeLogString) {
}

void ts3plugin_onClientBanFromServerEvent(uint64 scHandlerID,
                                          anyID clientID,
                                          uint64 oldChannelID,
                                          uint64 newChannelID,
                                          int visibility,
                                          anyID kickerID,
                                          const char* kickerName,
                                          const char* kickerUID,
                                          uint64 time,
                                          const char* kickMessage) {
}

int ts3plugin_onClientPokeEvent(uint64 scHandlerID,
                                anyID fromClientID,
                                const char* pokerName,
                                const char* pokerUID,
                                const char* message,
                                int ffIgnored) {
    // 0 = handle normally
    // 1 = client will ignore the poke
    return 0;
}

void ts3plugin_onClientSelfVariableUpdateEvent(uint64 scHandlerID,
                                               int flag,
                                               const char* oldValue,
                                               const char* newValue) {
}

void ts3plugin_onFileListEvent(uint64 scHandlerID,
                               uint64 channelID,
                               const char* path,
                               const char* name,
                               uint64 size,
                               uint64 datetime,
                               int type,
                               uint64 incompletesize,
                               const char* returnCode) {
}

void ts3plugin_onFileListFinishedEvent(uint64 scHandlerID,
                                       uint64 channelID,
                                       const char* path) {
}

void ts3plugin_onFileInfoEvent(uint64 scHandlerID,
                               uint64 channelID,
                               const char* name,
                               uint64 size,
                               uint64 datetime) {
}

void ts3plugin_onServerGroupListEvent(uint64 scHandlerID,
                                      uint64 serverGroupID,
                                      const char* name,
                                      int type,
                                      int iconID,
                                      int saveDB) {
}

void ts3plugin_onServerGroupListFinishedEvent(uint64 scHandlerID) {
}

void ts3plugin_onServerGroupByClientIDEvent(uint64 scHandlerID,
                                            const char* name,
                                            uint64 serverGroupList,
                                            uint64 clientDBID) {
}

void ts3plugin_onServerGroupPermListEvent(uint64 scHandlerID,
                                          uint64 serverGroupID,
                                          unsigned int permissionID,
                                          int permissionValue,
                                          int permissionNegated,
                                          int permissionSkip) {
}

void ts3plugin_onServerGroupPermListFinishedEvent(uint64 scHandlerID,
                                                  uint64 serverGroupID) {
}

void ts3plugin_onServerGroupClientListEvent(uint64 scHandlerID,
                                            uint64 serverGroupID,
                                            uint64 clientDBID,
                                            const char* clientNID,
                                            const char* clientUID) {
}

void ts3plugin_onChannelGroupListEvent(uint64 scHandlerID,
                                       uint64 channelGroupID,
                                       const char* name,
                                       int type,
                                       int iconID,
                                       int saveDB) {
}

void ts3plugin_onChannelGroupListFinishedEvent(uint64 scHandlerID) {
}

void ts3plugin_onChannelGroupPermListEvent(uint64 scHandlerID,
                                           uint64 channelGroupID,
                                           unsigned int permissionID,
                                           int permissionValue,
                                           int permissionNegated,
                                           int permissionSkip) {
}

void ts3plugin_onChannelGroupPermListFinishedEvent(uint64 scHandlerID,
                                                   uint64 channelGroupID) {
}

void ts3plugin_onChannelPermListEvent(uint64 scHandlerID,
                                      uint64 channelID,
                                      unsigned int permissionID,
                                      int permissionValue,
                                      int permissionNegated,
                                      int permissionSkip) {
}

void ts3plugin_onChannelPermListFinishedEvent(uint64 scHandlerID,
                                              uint64 channelID) {
}

void ts3plugin_onClientPermListEvent(uint64 scHandlerID,
                                     uint64 clientDBID,
                                     unsigned int permissionID,
                                     int permissionValue,
                                     int permissionNegated,
                                     int permissionSkip) {
}

void ts3plugin_onClientPermListFinishedEvent(uint64 scHandlerID,
                                             uint64 clientDBID) {
}

void ts3plugin_onChannelClientPermListEvent(uint64 scHandlerID,
                                            uint64 channelID,
                                            uint64 clientDBID,
                                            unsigned int permissionID,
                                            int permissionValue,
                                            int permissionNegated,
                                            int permissionSkip) {
}

void ts3plugin_onChannelClientPermListFinishedEvent(uint64 scHandlerID,
                                                    uint64 channelID,
                                                    uint64 clientDBID) {
}

void ts3plugin_onClientChannelGroupChangedEvent(uint64 scHandlerID,
                                                uint64 channelGroupID,
                                                uint64 channelID,
                                                anyID clientID,
                                                anyID invokerClientID,
                                                const char* invokerName,
                                                const char* invokerUID) {
}

int ts3plugin_onServerPermissionErrorEvent(uint64 scHandlerID,
                                           const char* errorMessage,
                                           unsigned int error,
                                           const char* returnCode,
                                           unsigned int failedPermissionID) {
    return 0;  // See onServerErrorEvent for return code description
}

void ts3plugin_onPermissionListGroupEndIDEvent(uint64 scHandlerID,
                                               unsigned int groupEndID) {
}

void ts3plugin_onPermissionListEvent(uint64 scHandlerID,
                                     unsigned int permissionID,
                                     const char* permissionName,
                                     const char* permissionDescription) {
}

void ts3plugin_onPermissionListFinishedEvent(uint64 scHandlerID) {
}

void ts3plugin_onPermissionOverviewEvent(uint64 scHandlerID,
                                         uint64 clientDBID,
                                         uint64 channelID,
                                         int overviewType,
                                         uint64 overviewID1,
                                         uint64 overviewID2,
                                         unsigned int permissionID,
                                         int permissionValue,
                                         int permissionNegated,
                                         int permissionSkip) {
}

void ts3plugin_onPermissionOverviewFinishedEvent(uint64 scHandlerID) {
}

void ts3plugin_onServerGroupClientAddedEvent(uint64 scHandlerID,
                                             anyID clientID,
                                             const char* clientName,
                                             const char* clientUID,
                                             uint64 serverGroupID,
                                             anyID invokerClientID,
                                             const char* invokerName,
                                             const char* invokerUID) {
}

void ts3plugin_onServerGroupClientDeletedEvent(uint64 scHandlerID,
                                               anyID clientID,
                                               const char* clientName,
                                               const char* clientUID,
                                               uint64 serverGroupID,
                                               anyID invokerClientID,
                                               const char* invokerName,
                                               const char* invokerUID) {
}

void ts3plugin_onClientNeededPermissionsEvent(uint64 scHandlerID,
                                              unsigned int permissionID,
                                              int permissionValue) {
}

void ts3plugin_onClientNeededPermissionsFinishedEvent(uint64 scHandlerID) {
}

void ts3plugin_onFileTransferStatusEvent(anyID transferID,
                                         unsigned int status,
                                         const char* statusMessage,
                                         uint64 remotefileSize,
                                         uint64 scHandlerID) {
}

void ts3plugin_onClientChatClosedEvent(uint64 scHandlerID,
                                       anyID clientID,
                                       const char* clientUID) {
}

void ts3plugin_onClientChatComposingEvent(uint64 scHandlerID,
                                          anyID clientID,
                                          const char* clientUID) {
}

void ts3plugin_onServerLogEvent(uint64 scHandlerID,
                                const char* logMsg) {
}

void ts3plugin_onServerLogFinishedEvent(uint64 scHandlerID,
                                        uint64 lastPos,
                                        uint64 fileSize) {
}

void ts3plugin_onMessageListEvent(uint64 scHandlerID,
                                  uint64 messageID,
                                  const char* fromClientUID,
                                  const char* subject,
                                  uint64 timestamp,
                                  int flagRead) {
}

void ts3plugin_onMessageGetEvent(uint64 scHandlerID,
                                 uint64 messageID,
                                 const char* fromClientUID,
                                 const char* subject,
                                 const char* message,
                                 uint64 timestamp) {
}

void ts3plugin_onClientDBIDfromUIDEvent(uint64 scHandlerID,
                                        const char* clientUID,
                                        uint64 clientDBID) {
}

void ts3plugin_onClientNamefromUIDEvent(uint64 scHandlerID,
                                        const char* clientUID,
                                        uint64 clientDBID,
                                        const char* clientName) {
}

void ts3plugin_onClientNamefromDBIDEvent(uint64 scHandlerID,
                                         const char* clientUID,
                                         uint64 clientDBID,
                                         const char* clientName) {
}

void ts3plugin_onComplainListEvent(uint64 scHandlerID,
                                   uint64 targetClientDBID,
                                   const char* targetClientName,
                                   uint64 fromClientDBID,
                                   const char* fromClientName,
                                   const char* complainReason,
                                   uint64 timestamp) {
}

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
                              const char* lastName) {
}

void ts3plugin_onClientServerQueryLoginPasswordEvent(uint64 scHandlerID,
                                                     const char* loginPW) {
}

void ts3plugin_onPluginCommandEvent(uint64 scHandlerID,
                                    const char* pluginName,
                                    const char* pluginCommand) {
    printf("ON PLUGIN COMMAND: %s %s\n", pluginName, pluginCommand);
}

void ts3plugin_onIncomingClientQueryEvent(uint64 scHandlerID,
                                          const char* commandText) {
}

void ts3plugin_onServerTemporaryPasswordListEvent(uint64 scHandlerID,
                                                  const char* clientNickname,
                                                  const char* clientUID,
                                                  const char* description,
                                                  const char* password,
                                                  uint64 timestampStart,
                                                  uint64 timestampEnd,
                                                  uint64 targetChannelID,
                                                  const char* targetChannelPW) {
}

// Called by client when an avatar image is added to or deleted from the cache.
// This callback can be called spontaneously or in response to getAvatar().
// If avatarPath is NULL, the avatar got deleted.
// If not NULL, avatarPath contains the path to the avatar file in the cache.
void ts3plugin_onAvatarUpdated(uint64 scHandlerID,
                               anyID clientID,
                               const char* avatarPath) {
}

// Called when client custom nickname changed
void ts3plugin_onClientDisplayNameChanged(uint64 scHandlerID,
                                          anyID clientID,
                                          const char* displayName,
                                          const char* clientUID) {
}
