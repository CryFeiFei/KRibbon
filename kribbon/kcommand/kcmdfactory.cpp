#include "kcmdfactory.h"
#include "kcommand.h"

static QMap<QString, KCommandFactoryBase*> &CommandFactoryItems()
{
	static QMap<QString, KCommandFactoryBase*> map;
	return map;
}


KCommandFactoryBase::KCommandFactoryBase(const QString &className) : m_className(className)
{

}

QString KCommandFactoryBase::className()
{
	return m_className;
}


//--------------------------


void KCmdFactory::regiserCommand(KCommandFactoryBase *item)
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

