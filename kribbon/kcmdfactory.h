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
		if (!constructor)
			return NULL;

		return (*constructor)(parent);
	}

	//register widget
	template<typename T1>
	static void registerWidget()
	{
		instanceWidget().insert(T1::staticMetaObject.className(), &constructorHelperWidget<T1> );
	}

	static QWidget* createWidget(const QByteArray& className, QWidget* parent = NULL )
	{
		ConstructorWidget constructorWidget = instanceWidget().value(className);
		if (!constructorWidget)
			return NULL;

		return (*constructorWidget)(parent);
	}

private:
	//object
	typedef QObject*(*Constructor)(QObject* parent);
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

	typedef QWidget*(*ConstructorWidget)(QWidget* parent);
	template<typename T1>
	static QWidget* constructorHelperWidget(QWidget* parent)
	{
		return new T1(parent);
	}

	static QHash<QByteArray, ConstructorWidget>& instanceWidget()
	{
		static QHash<QByteArray, ConstructorWidget> instanceWidget;
		return instanceWidget;
	}
};

#endif // KCMDFACTORY_H
