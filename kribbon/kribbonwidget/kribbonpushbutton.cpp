#include "kribbonpushbutton.h"
#include <QMetaObject>
#include "../kcommand/kcmdfactory.h"
KRibbonPushButton::KRibbonPushButton(QWidget *parent) : QPushButton(parent)
{

}


KRB_REGISTER_Widget(KRibbonPushButton);
