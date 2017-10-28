#include "variablewidget.h"

variableWidget::variableWidget(QWidget *parent) : QWidget(parent)
{
    QLabel *title = new QLabel("Variables");
    title->adjustSize();

    setFixedSize(350,110);

    var1edit = new QTextEdit;
    var1edit->adjustSize();
    var2edit = new QTextEdit;
    var2edit->adjustSize();
    var1label = new QLabel("VAR1");
    var2label = new QLabel("VAR2");


    QHBoxLayout *var1Hbox = new QHBoxLayout();
    var1Hbox->addWidget(var1label);
    var1Hbox->addWidget(var1edit);

    QHBoxLayout *var2Hbox = new QHBoxLayout();
    var2Hbox->addWidget(var2label);
    var2Hbox->addWidget(var2edit);


    QVBoxLayout *yVbox = new QVBoxLayout(this);
    yVbox->addWidget(title);
    yVbox->addLayout(var1Hbox);
    yVbox->addLayout(var2Hbox);

}

