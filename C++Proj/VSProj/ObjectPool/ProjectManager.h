#pragma once
#include "ProjectPool.h"
#include "Project.h"

typedef ProjectPool<Project, 100> POOL;

//对象管理器应当也是一个单例
class ProjectManager
{
	static ProjectManager* getManagerInstance()
	{
		return managerPtr;
	}

private:
	static ProjectManager* managerPtr;
	ProjectManager() {}
	ProjectManager(const ProjectManager& manager){}
	

};

