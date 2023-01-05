#pragma once

#include<string>
#include<list>
#include<iomanip>
#include<winnls.h>

#include"Data/GameData.hpp"

class Utils {
public:
	Utils() {
		if (nChineseOS < 0) {
			nChineseOS = isChineseLanguageOS();
		}
	}

	/// <summary>
	/// ����ַ���������̨,���û��ָ���ڶ���������Ĭ�������һ���ַ���������
	/// </summary>
	/// <param name="eng">Ӣ���ַ���</param>
	/// <param name="cn">�����ַ���</param>
	void print(std::string eng, std::string cn = "") {
		if (cn == "") {
			std::cout << eng;
		}
		else {
			if (this->nChineseOS) {
				std::cout << cn;
			}
			else {
				std::cout << eng;
			}
		}
	}

	/// <summary>
	/// �������Ļ�Ӣ���ַ���
	/// </summary>
	/// <param name="eng"></param>
	/// <param name="cn"></param>
	/// <returns></returns>
	std::string str(std::string eng, std::string cn) {
		return (this->nChineseOS) ? cn : eng;
	}

	/// <summary>
	/// ��鵱ǰϵͳ�Ƿ�ʹ������
	/// </summary>
	/// <returns>�Ƿ�ʹ������</returns>
	static bool isChineseLanguageOS() {
		try {
			std::string locale = __CheckLocale();
			if (locale.find("zh") != std::string::npos || locale.find("CN") != std::string::npos) {
				//���� 
				return true;
			}
			return false;
		}
		catch (...) {
			return false;
		}
	}

	/// <summary>
	/// �رտ�������ģʽ��ֹ����ס
	/// Disable quick-edit in console in case that user input stuck the program
	/// </summary>
	static void disableQuickEdit() {
		//ʹ����̨�޷����룬��ֹ��Ϊ�������ס����
		DWORD prev_mode;
		HANDLE hStidin = GetStdHandle(STD_INPUT_HANDLE);
		GetConsoleMode(hStidin, &prev_mode);
		SetConsoleMode(hStidin, ENABLE_EXTENDED_FLAGS);
	}

	const char* getRoleName(int id) {
		//�������Ľ�ɫ��
		if (this->nChineseOS) {
			switch (id)
			{
			case gameRoleId::None:
				return("��");
				break;
			case gameRoleId::Goose:
				return("��");
				break;
			case gameRoleId::Duck:
				return("Ѽ��");
				break;
			case gameRoleId::Dodo:
				return("������");
				break;
			case gameRoleId::Bounty:
				return("�ͽ�");
				break;
			case gameRoleId::Mechanic:
				//����ʹ�ùܵ�(�ý�ɫ�ѱ��������Ƴ�)
				return("Mechanic");
				break;
			case gameRoleId::Technician:
				//�����������ͼ�Ͽ����ƻ��Ĵ�Լλ��(�ý�ɫ�ѱ��������Ƴ�)
				return("Technician");
				break;
			case gameRoleId::Medium:
				return("ͨ��");
				break;
			case gameRoleId::Vigilante:
				return("����ʹ��");
				break;
			case gameRoleId::Cannibal:
				return("ʳ��Ѽ");
				break;
			case gameRoleId::Morphling:
				return("������(Ѽ��)");
				break;
			case gameRoleId::Sheriff:
				return("����");
				break;
			case gameRoleId::Silencer:
				return("������(Ѽ��)");
				break;
			case gameRoleId::Canadian:
				return("���ô��");
				break;
			case gameRoleId::LoverDuck:
				return("����(Ѽ��)");
				break;
			case gameRoleId::LoverGoose:
				return("����(��)");
				break;
			case gameRoleId::Vulture:
				return("ͺ��");
				break;
			case gameRoleId::Professional:
				return("רҵɱ��(Ѽ��)");
				break;
			case gameRoleId::Spy:
				return("���(Ѽ��)");
				break;
			case gameRoleId::Mimic:
				return("ģ����");
				break;
			case gameRoleId::Detective:
				return("��̽");
				break;
			case gameRoleId::Pigeon:
				return("����");
				break;
			case gameRoleId::Birdwatcher:
				return("������");
				break;
			case gameRoleId::Assassin:
				return("�̿�(Ѽ��)");
				break;
			case gameRoleId::Falcon:
				return("��ӥ");
				break;
			case gameRoleId::Hitman:
				return("��Ӷɱ��(Ѽ��)");
				break;
			case gameRoleId::Bodyguard:
				return("���ڶ�");
				break;
			case gameRoleId::Snitch:
				return("������(Ѽ��)");
				break;
			case gameRoleId::Politician:
				return("���μ�");
				break;
			case gameRoleId::Locksmith:
				return("����");
				break;
			case gameRoleId::Mortician:
				return("����Ա");
				break;
			case gameRoleId::Celebrity:
				return("����");
				break;
			case gameRoleId::Party:
				return("�ɶԿ�(Ѽ��)");
				break;
			case gameRoleId::Demolitionist:
				return("��ը��(Ѽ��)");
				break;
			case gameRoleId::DuelingDodo:
				return("����������");
				break;
			case gameRoleId::GHGoose:
				return("���Զ졿��");
				break;
			case gameRoleId::GHDuck:
				return("���Զ졿Ѽ��");
				break;
			case gameRoleId::GHBounty:
				//��������Ǳ���һ��������������������Ի�ý���(�ý�ɫ�ѱ��������Ƴ�)
				return("���Զ졿�ͽ��");
				break;
			case gameRoleId::HNSGoose:
				return("��HNS����");
				break;
			case gameRoleId::HNSDuck:
				return("��HNS��Ѽ��");
				break;
			case gameRoleId::HNSBounty:
				return("��HNS���ͽ��");
				break;
			case gameRoleId::DNDDuck:
				return("�������͡�Ѽ��");
				break;
			case gameRoleId::DNDFalcon:
				return("�������͡���ӥ");
				break;
			case gameRoleId::DNDVulture:
				return("�������͡�ͺ��");
				break;
			case gameRoleId::DNDMorphling:
				return("�������͡�����Ѽ");
				break;
			case gameRoleId::FPGoose:
				return("FPGoose");
				break;
			case gameRoleId::ExploreGoose:
				return("ExploreGoose");
				break;
			case gameRoleId::TTVampire:
				return("��TT����Ѫ��");
				break;
			case gameRoleId::TTPeasant:
				return("��TT������");
				break;
			case gameRoleId::TTThrall:
				return("��TT����ū");
				break;
			case gameRoleId::Spectator:
				return("Spectator");
				break;
			case gameRoleId::IdentityThief:
				return("�������");
				break;
			case gameRoleId::Adventurer:
				return("ð�ռ�");
				break;
			case gameRoleId::Avenger:
				return("������");
				break;
			case gameRoleId::Ninja:
				return("����(Ѽ��)");
				break;
			case gameRoleId::Undertaker:
				return("ɥ����");
				break;
			case gameRoleId::Snoop:
				//���������ڵ�ͼ��һЩ�ط�(�ý�ɫ�ѱ��������Ƴ�)
				return("Snoop");
				break;
			case gameRoleId::Esper:
				return("��������");
				break;
			case gameRoleId::Invisibility:
				return("������");
				break;
			case gameRoleId::Astral:
				return("�ǽ�����");
				break;
			case gameRoleId::Pelican:
				return("����");
				break;
			case gameRoleId::TTEThrall:
				return("��TTE����ū");
				break;
			case gameRoleId::TTMummy:
				return("��TT��ľ����");
				break;
			case gameRoleId::SerialKiller:
				return("����ɱ��(Ѽ��)");
				break;
			case gameRoleId::Engineer:
				return("����ʦ");
				break;
			case gameRoleId::Warlock:
				return("��ʿ(Ѽ��)");
				break;
			case gameRoleId::StreetUrchin:
				return("���˶�ͯ");
				break;
			case gameRoleId::Tracker:
				return("׷����");
				break;
			default:
				return("��");
				break;
			}
		}
		else {
			switch (id)
			{
			case gameRoleId::None:
				return("None");
				break;
			case gameRoleId::Goose:
				return("Goose");
				break;
			case gameRoleId::Duck:
				return("Duck");
				break;
			case gameRoleId::Dodo:
				return("Dodo");
				break;
			case gameRoleId::Bounty:
				return("Bounty");
				break;
			case gameRoleId::Mechanic:
				return("Mechanic");
				break;
			case gameRoleId::Technician:
				return("Technician");
				break;
			case gameRoleId::Medium:
				return("Medium");
				break;
			case gameRoleId::Vigilante:
				return("Vigilante");
				break;
			case gameRoleId::Cannibal:
				return("Cannibal");
				break;
			case gameRoleId::Morphling:
				return("Morphling");
				break;
			case gameRoleId::Sheriff:
				return("Sheriff");
				break;
			case gameRoleId::Silencer:
				return("Silencer");
				break;
			case gameRoleId::Canadian:
				return("Canadian");
				break;
			case gameRoleId::LoverDuck:
				return("LoverDuck");
				break;
			case gameRoleId::LoverGoose:
				return("LoverGoose");
				break;
			case gameRoleId::Vulture:
				return("Vulture");
				break;
			case gameRoleId::Professional:
				return("Professional");
				break;
			case gameRoleId::Spy:
				return("Spy");
				break;
			case gameRoleId::Mimic:
				return("Mimic");
				break;
			case gameRoleId::Detective:
				return("Detective");
				break;
			case gameRoleId::Pigeon:
				return("Pigeon");
				break;
			case gameRoleId::Birdwatcher:
				return("Birdwatcher");
				break;
			case gameRoleId::Assassin:
				return("Assassin");
				break;
			case gameRoleId::Falcon:
				return("Falcon");
				break;
			case gameRoleId::Hitman:
				return("Hitman");
				break;
			case gameRoleId::Bodyguard:
				return("Bodyguard");
				break;
			case gameRoleId::Snitch:
				return("Snitch");
				break;
			case gameRoleId::Politician:
				return("Politician");
				break;
			case gameRoleId::Locksmith:
				return("Locksmith");
				break;
			case gameRoleId::Mortician:
				return("Mortician");
				break;
			case gameRoleId::Celebrity:
				return("Celebrity");
				break;
			case gameRoleId::Party:
				return("Party");
				break;
			case gameRoleId::Demolitionist:
				return("Demolitionist");
				break;
			case gameRoleId::DuelingDodo:
				return("DuelingDodo");
				break;
			case gameRoleId::GHGoose:
				return("GHGoose");
				break;
			case gameRoleId::GHDuck:
				return("GHDuck");
				break;
			case gameRoleId::GHBounty:
				return("GHBounty");
				break;
			case gameRoleId::HNSGoose:
				return("HNSGoose");
				break;
			case gameRoleId::HNSDuck:
				return("HNSDuck");
				break;
			case gameRoleId::HNSBounty:
				return("HNSBounty");
				break;
			case gameRoleId::DNDDuck:
				return("DNDDuck");
				break;
			case gameRoleId::DNDFalcon:
				return("DNDFalcon");
				break;
			case gameRoleId::DNDVulture:
				return("DNDVulture");
				break;
			case gameRoleId::DNDMorphling:
				return("DNDMorphling");
				break;
			case gameRoleId::FPGoose:
				return("FPGoose");
				break;
			case gameRoleId::ExploreGoose:
				return("ExploreGoose");
				break;
			case gameRoleId::TTVampire:
				return("TTVampire");
				break;
			case gameRoleId::TTPeasant:
				return("TTPeasant");
				break;
			case gameRoleId::TTThrall:
				return("TTThrall");
				break;
			case gameRoleId::Spectator:
				return("Spectator");
				break;
			case gameRoleId::IdentityThief:
				return("IdentityThief");
				break;
			case gameRoleId::Adventurer:
				return("Adventurer");
				break;
			case gameRoleId::Avenger:
				return("Avenger");
				break;
			case gameRoleId::Ninja:
				return("Ninja");
				break;
			case gameRoleId::Undertaker:
				return("Undertaker");
				break;
			case gameRoleId::Snoop:
				return("Snoop");
				break;
			case gameRoleId::Esper:
				return("Esper");
				break;
			case gameRoleId::Invisibility:
				return("Invisibility");
				break;
			case gameRoleId::Astral:
				return("Astral");
				break;
			case gameRoleId::Pelican:
				return("Pelican");
				break;
			case gameRoleId::TTEThrall:
				return("TTEThrall");
				break;
			case gameRoleId::TTMummy:
				return("TTMummy");
				break;
			case gameRoleId::SerialKiller:
				return("SerialKiller");
				break;
			case gameRoleId::Engineer:
				return("Engineer");
				break;
			case gameRoleId::Warlock:
				return("Warlock");
				break;
			case gameRoleId::StreetUrchin:
				return("StreetUrchin");
				break;
			case gameRoleId::Tracker:
				return("Tracker");
				break;
			default:
				return("None");
				break;
			}
		}
	}

private:
	//��ǰ����ϵͳ�Ƿ�Ϊ����
	//1 if current OS's language is Chinese
	int nChineseOS = -1;

	static std::string __CheckLocale()
	{
		//LCID ʵ����unsignedlong���ͣ����Կ���ͨ��LCID�������Ƚ���ʲô����
		LCID lcid = GetThreadLocale();
		wchar_t name[LOCALE_NAME_MAX_LENGTH];
		if (LCIDToLocaleName(lcid, name, LOCALE_NAME_MAX_LENGTH, 0) == 0) {
			// "Get locale name error"
			return "";
		}
		std::wstring ws(name);
		std::string str(ws.begin(), ws.end());
		return str;
	}
};