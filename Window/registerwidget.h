#ifndef REGISTERWIDGET_H
#define REGISTERWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QLabel>
#include <QGridLayout>

class registerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit registerWidget(QWidget *parent = 0);

private:
    QTextEdit *eaxEdit;
    QTextEdit *ebxEdit;
    QTextEdit *ecxEdit;
    QTextEdit *edxEdit;
    QTextEdit *espEdit;
    QTextEdit *eipEdit;
    QTextEdit *ebpEdit;
    QLabel *eaxLabel;
    QLabel *ebxLabel;
    QLabel *ecxLabel;
    QLabel *edxLabel;
    QLabel *espLabel;
    QLabel *eipLabel;
    QLabel *ebpLabel;


};

#endif // REGISTERWIDGET_H
