#ifndef KCOMMAND_H
#define KCOMMAND_H

#include <QObject>



class KCommand : public QObject
{
	Q_OBJECT
public:
	explicit KCommand(QObject *parent = nullptr);

signals:

};

#endif // KCOMMAND_H
