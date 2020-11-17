#include "kcmdfactory.h"
#include "kcommand.h"

static QMap<QString, KCommandFactoryItemBase*> &CommandFactoryItems()
{
	static QMap<QString, KCommandFactoryItemBase*> map;
	return map;
}


KCommandFactoryItemBase::KCommandFactoryItemBase(const QString &className) : m_className(className)
{

}

QString KCommandFactoryItemBase::className()
{
	return m_className;
}


//--------------------------


void KCmdFactory::regiserCommand(KCommandFactoryItemBase *item)
{
	CommandFactoryItems()[item->className()] = item;
}

KCommand* KCmdFactory::createCommand(const QString &className, QObject *parent, QObject *host)
{
	auto itemFactory = CommandFactoryItems().find(className);
	if (itemFactory != CommandFactoryItems().end())
	{
		auto p = (*itemFactory)->createCommand(parent, host);
		return p;
	}

	return NULL;
}

//--------------------------------------------------
// widget

static QMap<QString, KWidgetFactoryItemBase*> &WidgetFactoryItems()
{
	static QMap<QString, KWidgetFactoryItemBase*> map;
	return map;
}

KWidgetFactoryItemBase::KWidgetFactoryItemBase(const QString &className) : m_className(className)
{

}

QString KWidgetFactoryItemBase::className()
{
	return m_className;
}


void KWidgetFactory::regiserWidget(KWidgetFactoryItemBase *item)
{
	WidgetFactoryItems()[item->className()] = item;
}

QWidget *KWidgetFactory::createWdiget(const QString &className, QWidget *parent)
{
	auto itemFactory = WidgetFactoryItems().find(className);
	if (itemFactory != WidgetFactoryItems().end())
	{
		auto p = (*itemFactory)->createWidget(parent);
		return p;
	}

	return NULL;
}


