#pragma once

#ifndef WINDOW_H
#define WINDOW_H

// créer la fenêtre principale de l'application

#include <QMainWindow>
#include <QTextEdit>
#include <QWidget>
#include <QToolBar>
#include <QLineEdit>
#include <QBoxLayout>
#include <QLabel>
#include <QStackedWidget>
#include <QMenuBar>
#include <QTextEdit>
#include <QFile>
#include <QDebug>
#include <QString>
#include <QTextStream>
#include <QMenu>
#include <QFileDialog>
#include <QMessageBox>
#include <QtDebug>
#include <QIcon>
#include <QApplication>


//#include "../asmx86/parser/parser.hpp"

class QAction;
class QLabel;
class QFrame;
class QMenu;



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //communication entre objets
private slots:
    void newFile();
    void open();
    void save();
    void cut();
    void copy();
    void paste();
// créer les différentes actions, 
//ajouter les actions aux menus et insérer les menus dans la barre de menus de notre fenêtre principale.
private:
    void createActions();
    void createMenus();
    QTextEdit *textEdit;
    bool maybeSave();    

    //déclaration des menus et actions
    
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *helpMenu;
    QMenu *ExecMenu;
    QAction *newAct;
    QAction *openAct;
    QAction *saveAct;
    QAction *exitAct;
    QAction *cutAct;    
    QAction *copyAct;
    QAction *pasteAct;

  

    QFrame *upperBar;
    QFrame *sideBar;
    QLabel *sideItemA;
    QLabel *sideItemB;

    QStackedWidget *contentStack;

    QFrame *contentPage1;
    QLabel *page1WidgetB;
    QLabel *page1WidgetC;
    QLabel *page1WidgetD;
     

    QWidget *centralWidget;

    //Les layouts nécessaires :
    QHBoxLayout *upperBarLayout;
    QVBoxLayout *sideBarLayout;
    QGridLayout *page1GridLayout;
    QGridLayout *centralLayout;

    //AsmParser *parser;

   
};

#endif
