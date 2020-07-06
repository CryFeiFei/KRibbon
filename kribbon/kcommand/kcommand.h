#ifndef KCOMMAND_H
#define KCOMMAND_H

#include <QObject>



class KCommand : public QObject
{
	Q_OBJECT
public:
	explicit KCommand(QObject *parent = nullptr);

	//ui parser
public:
	void setWidgetClassName(const QString&);
	QString widgetClassName() const;

signals:


private:
	QString m_widgetClassName;
};

#endif // KCOMMAND_H
