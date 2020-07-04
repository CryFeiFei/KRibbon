#ifndef KCMDFACTORY_H
#define KCMDFACTORY_H

#include <QByteArray>
#include <QMetaObject>
#include <QHash>

#include "kcommand/kcmdtabstart.h"


class KCmdObjectFactory
{
public:
	template<typename T>
	static void registerClass()
	{
		instance().insert(T::staticMetaObject.className(), &constructorHelper<T> );
	}

	static QObject* createObject(const QByteArray& className, QObject* parent = NULL )
	{
		Constructor constructor = instance().value(className);
		if ( constructor == NULL )
			return NULL;

		return (*constructor)(parent);
	}

private:
	typedef QObject*(*Constructor)(QObject* parent );

	template<typename T>
	static QObject* constructorHelper(QObject* parent)
	{
		return new T(parent);
	}

	static QHash<QByteArray, Constructor>& instance()
	{
		static QHash<QByteArray, Constructor> instance;
		return instance;
	}
};

#endif // KCMDFACTORY_H
