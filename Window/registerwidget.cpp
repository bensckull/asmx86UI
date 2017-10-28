#include "registerwidget.h"

registerWidget::registerWidget(QWidget *parent) : QWidget(parent)
{
QLabel *title = new QLabel("Registres");
title->adjustSize();

setFixedSize(350,200);

eaxEdit = new QTextEdit;
ebxEdit = new QTextEdit;
ecxEdit = new QTextEdit;
edxEdit = new QTextEdit;
espEdit = new QTextEdit;
eipEdit = new QTextEdit;
ebpEdit = new QTextEdit;

eaxEdit->setDisabled(true);

eaxLabel = new QLabel("EAX");
ebxLabel = new QLabel("EBX");
ecxLabel = new QLabel("ECX");
edxLabel = new QLabel("EDX");
espLabel = new QLabel("ESP");
eipLabel = new QLabel("EI P");
ebpLabel = new QLabel("EBP");
QLabel *vide = new QLabel;

QHBoxLayout *eaxHbox = new QHBoxLayout();
eaxHbox->addWidget(eaxLabel);
eaxHbox->addWidget(eaxEdit);

QHBoxLayout *ebxHbox = new QHBoxLayout();
ebxHbox->addWidget(ebxLabel);
ebxHbox->addWidget(ebxEdit);

QHBoxLayout *ecxHbox = new QHBoxLayout();
ecxHbox->addWidget(ecxLabel);
ecxHbox->addWidget(ecxEdit);

QHBoxLayout *edxHbox = new QHBoxLayout();
edxHbox->addWidget(edxLabel);
edxHbox->addWidget(edxEdit);

QHBoxLayout *ebpHbox = new QHBoxLayout();
ebpHbox->addWidget(ebpLabel);
ebpHbox->addWidget(ebpEdit);

QHBoxLayout *espHbox = new QHBoxLayout();
espHbox->addWidget(espLabel);
espHbox->addWidget(espEdit);

QHBoxLayout *eipHbox = new QHBoxLayout();
eipHbox->addWidget(eipLabel);
eipHbox->addWidget(eipEdit);

QVBoxLayout *xVbox = new QVBoxLayout();
xVbox->addLayout(eaxHbox);
xVbox->addLayout(ebxHbox);
xVbox->addLayout(ecxHbox);
xVbox->addLayout(edxHbox);

QVBoxLayout *sVbox = new QVBoxLayout();
sVbox->addLayout(espHbox);
sVbox->addLayout(ebpHbox);
sVbox->addLayout(eipHbox);
sVbox->addWidget(vide);

QHBoxLayout *genLay = new QHBoxLayout();
genLay->addLayout(xVbox);
genLay->addLayout(sVbox);

QVBoxLayout *grandLayout = new QVBoxLayout(this);
grandLayout->addWidget(title);
grandLayout->addLayout(genLay);
}

