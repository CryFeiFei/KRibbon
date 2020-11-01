#include "kparserui.h"
#include "kcommand/kcmdfactory.h"
#include "kcommand/kcmdtabstart.h"

#include "kribbonwidget/kribbontab.h"
#include "kribbonwidget/kribbonpushbutton.h"

#include <QDebug>

#define REGISTER_CMD(classname) \
//KCmdObjectFactory::registerClass<classname>()

#define REGISTER_Widget(classname) \
//KCmdObjectFactory::registerWidget<classname>()

static void RegisterCmd()
{
	REGISTER_CMD(KCmdTabStart);
	{
		REGISTER_CMD(KCmdStart);
		REGISTER_CMD(KCmdOpen);
		REGISTER_CMD(KCmdClose);
	}

	REGISTER_Widget(KRibbonPushButton);
	REGISTER_Widget(KRibbonTab);
}

KParserUI::KParserUI(QString xmlPath, QObject *parent) : QObject(parent)
{
	RegisterCmd();

	ParserXML();

	KCmdStart* object = (KCmdStart*)KCmdObjectFactory::createObject("KCmdStart", this);
	qDebug()<<object<<endl;

	KCmdStart* object1 = (KCmdStart*)KCmdObjectFactory::createObject("KCmdStart", this);
	qDebug()<<object1<<endl;
}

void KParserUI::ParserXML()
{

}
