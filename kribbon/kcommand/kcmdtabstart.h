#ifndef KCMDTABSTART_H
#define KCMDTABSTART_H

#include <QObject>
#include <QPushButton>
#include "kcommand.h"
#include "kcmdfactory.h"

class KxMainWindow;

//<KRibbonPushButton cmd="KCmdStart" text="start" />
//<KRibbonPushButton cmd="KCmdOpen" text="open" />
//<KRibbonPushButton cmd="KCmdClose" text="close" />

class KCmdStart : public KCommand
{
	Q_OBJECT
public:
	KCmdStart(QObject *parent = nullptr, QObject* host = nullptr);

signals:

};

class KCmdOpen : public KCommand
{
	Q_OBJECT
public:
	explicit KCmdOpen(QObject *parent = nullptr);

signals:

};

class KCmdClose : public KCommand
{
	Q_OBJECT
public:
	explicit KCmdClose(QObject *parent = nullptr);

signals:
};

class KCmdTabStart : public KCommand
{
	Q_OBJECT
public:
	explicit KCmdTabStart(QObject *parent = nullptr);


signals:

};

#endif // KCMDTABSTART_H
