#include "kcommand.h"


KCommand::KCommand(QObject *parent, QObject *host) :
	QObject(parent)
	, m_host(host)
{

}
