#include "PipeManager.h"


PipeManager::PipeManager()
{

}

void PipeManager::Initialize()
{
	Pipe::Initialize();

	for (int i = 0; i < 2; i++)
	{
		Pipe* p = new Pipe(Engine::SCREEN_WIDTH*i / 2);
		p->RandHeight();
		pipes.push_back(p);
	}
}

void PipeManager::Update()
{
	for (int i = 0; i < pipes.size(); i++)
	{
		pipes[i]->MoveBack();
		//check out bound
		if (pipes[i]->CheckIfOut())
		{
			//Generate new pos
			GenerateNewPos(pipes[i]);
		}
		pipes[i]->GetTopRD().Update();
		pipes[i]->GetBotRd().Update();
	}
}

bool PipeManager::CheckColision(Player* p)
{
	bool isColision = false;
	for (int i = 0; i < pipes.size(); i++)
	{
		isColision = Rigdbody::IsColliding(p->GetRigdbody(), pipes[i]->GetTopRD()) ||
			Rigdbody::IsColliding(p->GetRigdbody(), pipes[i]->GetBotRd());
		if (isColision)
		{
			cout << "·¢ÉúÅö×²£¡£¡£¡£¡£¡£¡£¡" << endl;
			return isColision;
		}
	}
	return isColision;
}

void PipeManager::ReSet()
{
	for (int i = 0; i < pipes.size(); i++)
	{
		pipes[i]->RandHeight(Engine::SCREEN_WIDTH*i / 2);
	}
}

void PipeManager::Render()
{
	for (int i = 0; i < pipes.size(); i++)
	{
		pipes[i]->Render();
	}
}

void PipeManager::GenerateNewPos(Pipe* p)
{
	p->RandHeight(Engine::SCREEN_WIDTH);
}

PipeManager::~PipeManager()
{
	for (int i = 0; i < pipes.size(); i++)
	{
		delete pipes[i];
	}
}