#ifndef KCMDFACTORY_H
#define KCMDFACTORY_H

#include <QByteArray>
#include <QMetaObject>
#include <QHash>
#include <QMap>

#ifdef QT_DEBUG
#include <QDebug>
#endif

#include "kcommand/kcmdtabstart.h"

#include "kxmainwindow.h"


class KCommandFactoryItemBase;

class KCmdFactory
{
public:
	static void regiserCommand(KCommandFactoryItemBase* item);
	static KCommand* createCommand(const QString& className, QObject* parent, QObject* host);
};


class KCommandFactoryItemBase
{
public:
	KCommandFactoryItemBase(const QString& className);
	virtual KCommand* createCommand(QObject* parent, QObject* host) = 0;
	QString className();
private:
	QString m_className;
};

template<typename T, typename _HOST>
class KCmdFactoryItem : public KCommandFactoryItemBase
{
public:
	KCmdFactoryItem(const QString& className, const QString& host) :
		KCommandFactoryItemBase(className)
	  , m_hostName(host)
	{
		KCmdFactory::regiserCommand(this);
	}
	KCommand* createCommand(QObject* parent, QObject* host)
	{
		if (_HOST* hostClass = qobject_cast<_HOST*>(host))
		{
			return new T(parent, host);
		}
		qDebug()<<"---------------creat faile"<<endl;
		return nullptr;
	}
	
private:
	QString m_hostName;
};


#define KRB_REGISTER_COMMAND(classname, host) \
KCmdFactoryItem<classname, host> gs_cmd_##classname(#classname, #host)

//------------------------
// widget

class KWidgetFactoryItemBase;

class KWidgetFactory
{
public:
	static void regiserWidget(KWidgetFactoryItemBase* item);
	static QWidget* createWdiget(const QString& className, QWidget* parent);
};

class KWidgetFactoryItemBase
{
public:
	KWidgetFactoryItemBase(const QString& className);
	virtual QWidget* createWidget(QWidget* parent = nullptr) = 0;
	QString className();
private:
	QString m_className;
};

template<typename T>
class KWidgetFactoryItem : public KWidgetFactoryItemBase
{
public:
	KWidgetFactoryItem(const QString& className) :
		KWidgetFactoryItemBase(className)
	{
		KWidgetFactory::regiserWidget(this);
	}

	QWidget* createWidget(QWidget* parent = nullptr)
	{
		return new T(parent);
	}
};

#define KRB_REGISTER_Widget(classname) \
KWidgetFactoryItem<classname> gs_widget_##classname(#classname)

//----------------------------------------------------

//class KCmdWidgetFactory
//{
//public:
//	static void regiserWidget(QWidget* widget);
//	static QWidget* createWidget(const QString& className, QObject* parent);

//};

//class KCmdObjectFactory
//{
//public:
//	template<typename T>
//	static void registerClass()
//	{
//		instance().insert(T::staticMetaObject.className(), &constructorHelper<T> );
//	}

//	static QObject* createObject(const QByteArray& className, QObject* parent = NULL )
//	{
//		Constructor constructor = instance().value(className);
//		if (!constructor)
//			return NULL;

//		return (*constructor)(parent);
//	}

//	//register widget
//	template<typename T1>
//	static void registerWidget()
//	{
//		instanceWidget().insert(T1::staticMetaObject.className(), &constructorHelperWidget<T1> );
//	}

//	static QWidget* createWidget(const QByteArray& className, QWidget* parent = NULL )
//	{
//		ConstructorWidget constructorWidget = instanceWidget().value(className);
//		if (!constructorWidget)
//			return NULL;

//		return (*constructorWidget)(parent);
//	}

//private:
//	//object
//	typedef QObject*(*Constructor)(QObject* parent);
//	template<typename T>
//	static QObject* constructorHelper(QObject* parent)
//	{
//		return new T(parent);
//	}

//	static QHash<QByteArray, Constructor>& instance()
//	{
//		static QHash<QByteArray, Constructor> instance;
//		return instance;
//	}

////	typedef QWidget*(*ConstructorWidget)(QWidget* parent);
//	using ConstructorWidget = QWidget*()(QWidget* parent);
//	template<typename T1>
//	static QWidget* constructorHelperWidget(QWidget* parent)
//	{
//		return new T1(parent);
//	}

//	static QHash<QByteArray, ConstructorWidget>& instanceWidget()
//	{
//		static QHash<QByteArray, ConstructorWidget> instanceWidget;
//		return instanceWidget;
//	}
//};

#endif // KCMDFACTORY_H
