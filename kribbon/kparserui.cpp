#include "kparserui.h"
#include "kcmdfactory.h"
#include "kcommand/kcmdtabstart.h"

#define REGISTER_CMD(classname) \
KCmdObjectFactory::registerClass<classname>()

static void RegisterCmd()
{
	REGISTER_CMD(KCmdTabStart);
	{
		REGISTER_CMD(KCmdStart);
		REGISTER_CMD(KCmdOpen);
		REGISTER_CMD(KCmdClose);
	}
}

KParserUI::KParserUI(QString xmlPath, QObject *parent) : QObject(parent)
{
	RegisterCmd();

//	KCmdStart* object = (KCmdStart*)KCmdObjectFactory::createObject("KCmdStart", this);
}
