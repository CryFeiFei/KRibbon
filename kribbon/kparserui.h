#ifndef KPARSERUI_H
#define KPARSERUI_H

#include <QObject>

class KParserUI : public QObject
{
	Q_OBJECT
public:
	explicit KParserUI(QString xmlPath, QObject *parent = nullptr);

signals:



};

#endif // KPARSERUI_H
