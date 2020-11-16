#include "kcmdtabstart.h"


KCmdStart::KCmdStart(QObject *parent,  QObject* host) : KCommand(parent)
{
	setObjectName("KCmdStart");
}
KRB_REGISTER_COMMAND(KCmdStart, KxMainWindow);

KRibbonPushButton::KRibbonPushButton(QObject *parent)
{
	setObjectName("KRibbonPushButton");
}
KRB_REGISTER_Widget(KRibbonPushButton);


KCmdOpen::KCmdOpen(QObject *parent) : KCommand(parent)
{

}

KCmdClose::KCmdClose(QObject *parent) : KCommand(parent)
{

}

KCmdTabStart::KCmdTabStart(QObject *parent) : KCommand(parent)
{

}
