#pragma once
#include "ProjectPool.h"
#include "Project.h"

typedef ProjectPool<Project, 100> POOL;

//���������Ӧ��Ҳ��һ������
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

