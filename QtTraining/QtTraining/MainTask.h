#pragma once
#include "Common.h"

class MainTask : public QObject
{
		Q_OBJECT
public:
	MainTask(QObject* parent = 0);
	MainTask();
	virtual ~MainTask();

	bool Initialize();

public slots:
	void RunTask();

signals:
	void Finished();



};

