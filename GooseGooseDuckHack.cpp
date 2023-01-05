#pragma once

#include<list>
#include<thread>
#include <stdlib.h>

#include "client.hpp"
#include"./Class/DataUpdater.hpp"
#include "utils.hpp"
#include"./Class/PlayerController.hpp"


int main()
{
	//��ʼ��������
	Utils utils;

	//�رտ��ٱ༭
	//Disable the quick-edit mode
	utils.disableQuickEdit();

	//��ʼ��RPM������
	Memory memory;
	Client client(memory);
	DataUpdater dataUpdater(memory);

	std::list<PlayerController> playerControllers;
	for (int i = 0; i < 16; i++) {
		PlayerController playerController(memory);
		playerControllers.push_back(playerController);
	}

	//���PID
	if (memory.pID != NULL) {
		utils.print("Goose Goose Duck hack running...", "��Ѽɱ����������...");
		std::cout << std::endl;
		std::cout << "test:" << sizeof(int);

		//�������ݸ����߳�
		std::thread playerControllerUpdater(&DataUpdater::playerControllerUpdater, &dataUpdater, &playerControllers);

		//ѭ����ӡ����
		while (true) {
			if (dataUpdater.validPlayersNum > 0) {
				//clear console
				system("cls");
				//��ʼ��ӡ
				PlayerController::printAllPlayersInfo(playerControllers, &utils);
			}			
				Sleep(1000);
		}
	}
	else {
		utils.print("Not detected game, closing now... Please try again and run the game before starting the hack.", "δ��⵽��Ϸ�����ڹر�......����������Ϸ�ٴ򿪸ø�����");
		std::cout << std::endl;
		utils.print("If your have launched game but still see this message, it may because you ran the game (or steam) with Administrator privilege. In that case, you must run the hack with Administrator privilege too.",
			"��������Ϸ�Ѿ��򿪵���һֱ��������Ϣ���֣��ܿ��������Թ���ԱȨ����������Ϸ��Steam����ô����Ҫͬ��ʹ�ù���ԱȨ�������иø�����");
       
	}
}
