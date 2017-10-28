#ifndef VARIABLEWIDGET_H
#define VARIABLEWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QLabel>
#include <QGridLayout>



class variableWidget : public QWidget
{

    Q_OBJECT
public:
    explicit variableWidget(QWidget *parent = 0);

private:
    QTextEdit *var1edit;
    QTextEdit *var2edit;
    QLabel *var1label;
    QLabel *var2label;



};

#endif // VARIABLEWIDGET_H
