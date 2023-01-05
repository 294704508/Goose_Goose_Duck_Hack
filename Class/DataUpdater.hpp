#pragma once

#include<list>

#include"../memory.hpp"
#include"PlayerController.hpp"

/// <summary>
/// Thread functions that update data.
/// </summary>
class DataUpdater {
public:
	DataUpdater(Memory memory) {
		this->memory = &memory;
	}

	int validPlayersNum = 0;

	/// <summary>
	/// ���������Ϣ���̺߳���
	/// Thread that keeps updating data of PlayerControllers using RPM
	/// </summary>
	/// <param name="playerControllers"></param>
	void playerControllerUpdater(std::list<PlayerController> *playerControllers) {
		validPlayersNum = 0;

		while (true) {
			updatePlayerController(playerControllers);
			Sleep(1000);
		}
	}
private:
	Memory* memory;

	/// <summary>
	/// �������PlayerController��Ϣ
	/// </summary>
	/// <param name="playerIndex">��ҵ���������ΧΪ[0,15],��indexΪ0ʱΪLocalPlayer</param>
	/// <param name="playerController">Ҫ���µ�PlayerController</param>
	void updatePlayerController(std::list<PlayerController>* playerControllers) {
		int validPlayers = 0;

		//��������PlayerController
		std::list<PlayerController>::iterator iterator = playerControllers->begin();
		for (int i = 0; iterator != playerControllers->end(); ++iterator, ++i) {
			std::vector<int64_t> offsets = Offsets::GameAssembly::playerControllerByIndex(i);
			int64_t playerControllerAddr = memory->FindPointer( memory->gameAssemblyBaseAddress, offsets);

			//���������Ϣ
			bool isPlayerValid = playerControllerAddr != NULL;

			//��Ч�����Ϣ����ȡ�ڴ沢����
			if (isPlayerValid) {
				(*iterator).update(playerControllerAddr);
				//�����������
				(*iterator).updatePosition(playerControllerAddr);

				validPlayers++;
			}
			else {
				//��Ч�����Ϣ����û����������
				if ((*iterator).valid) {
					(*iterator).markAsInvalidPlayer();
					(*iterator).reset();

					//Local player not valid, no need to read further data
					if (i == 0) {
						return;
					}
				}
				else {
					//��Ч�����Ϣ�������ù�����
				}
			}
		}

		//������Ч�����Ϣ
		this->validPlayersNum = validPlayers;
	}
};