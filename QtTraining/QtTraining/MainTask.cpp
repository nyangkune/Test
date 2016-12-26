#include "MainTask.h"

MainTask::MainTask(QObject* parent) : QObject(parent){}

MainTask::MainTask(){}

MainTask::~MainTask(){}

void MainTask::RunTask()
{
	if (!Initialize())
	{
		emit Finished();
		return;
	}

}


bool MainTask::Initialize()
{
	CODETRAINING()->Initialize();



	return true;
}