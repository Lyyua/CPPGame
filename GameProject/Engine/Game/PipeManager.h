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
	void Initialize();//初始化
	void Update(); //每帧执行
	void GenerateNewPos(Pipe* p); //位置变化
	void Render();
	bool CheckColision(Player* p);
	void ReSet();
	~PipeManager();

private:
	vector<Pipe*> pipes;
};
#endif