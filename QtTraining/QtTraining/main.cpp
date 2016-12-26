#include <QtCore/QCoreApplication>
#include "Common.h"


int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	MainTask* mainTask = new MainTask(&a);
	QObject::connect(mainTask, &MainTask::Finished, &QCoreApplication::quit);

	QTimer::singleShot(0, mainTask, SLOT(RunTask()));

	int ret = a.exec();


	getchar();

	return ret;
}
