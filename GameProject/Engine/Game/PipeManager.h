#ifndef PIPEMANAGER
#define PIPEMANAGER
#include <vector>
#include "Pipe.h"
#include "Engine\Engine.h"
#include "Engine\Game\Player.h"
using namespace std;
class PipeManager
{
public:
	PipeManager();
	void Initialize();//��ʼ��
	void Update(); //ÿִ֡��
	void GenerateNewPos(Pipe* p); //λ�ñ仯
	void Render();
	bool CheckColision(Player* p);
	void ReSet();
	~PipeManager();

private:
	vector<Pipe*> pipes;
};
#endif