#include "kcmdtabstart.h"


KCmdStart::KCmdStart(QObject *parent,  QObject* host) : KCommand(parent)
{
	setObjectName("KCmdStart");
}
REGISTER_COMMAND(KCmdStart, KxMainWindow);

KCmdOpen::KCmdOpen(QObject *parent) : KCommand(parent)
{

}

KCmdClose::KCmdClose(QObject *parent) : KCommand(parent)
{

}

KCmdTabStart::KCmdTabStart(QObject *parent) : KCommand(parent)
{

}
