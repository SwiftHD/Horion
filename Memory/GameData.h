#pragma once

#include "../SDK/CClientInstance.h"
#include "../SDK/CGameMode.h"
#include "../SDK/CChestBlockActor.h"
#include "../Utils/TextFormat.h"
#include "SlimMem.h"


class GameData {
private:
	C_ClientInstance* clientInstance;
	C_LocalPlayer* localPlayer;
	C_GameMode* gameMode;
	C_ChestBlockActor* ChestBlock;
	const SlimUtils::SlimModule* gameModule;
	SlimUtils::SlimMem* slimMem;
	static void retrieveClientInstance();
public:
	static bool isKeyDown(int key);
	static bool isKeyPressed(int key);
	static void updateGameData(C_GameMode* gameMode);
	static void initGameData(const SlimUtils::SlimModule* gameModule, SlimUtils::SlimMem* slimMem);
	static void Chest_tick(C_ChestBlockActor * ChestBlock2);

	C_ClientInstance* getClientInstance() { return clientInstance; };
	C_LocalPlayer* getLocalPlayer() {
		localPlayer = clientInstance->getLocalPlayer();
		if (localPlayer == nullptr)
			gameMode = nullptr;
		return localPlayer;
	};
	const SlimUtils::SlimModule* getModule() {
		return gameModule;
	};
	const SlimUtils::SlimMem* getSlimMem() {
		return slimMem;
	};
	C_GameMode* getCGameMode() { return gameMode; };
	C_ChestBlockActor* getCChestBlock() { return ChestBlock; };
};


extern GameData g_Data;