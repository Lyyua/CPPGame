#include <iostream>
#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Engine\Game\GameManager.h"
using namespace std;

//��ں���
int main()
{
	/*char c1[5] = "game";
	char c3[6] = "g2ame";
	const char* c2 = "game";*/
	//char* c3 = "game";//��C++�����ǻᱨ��ġ�

	//cout << &c2 <<"\t"<< &c1 << endl;
	cout << "Begin Run" << endl;
	GameManager gm;
	gm.Start();
	return 0;
}