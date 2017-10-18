#pragma once

#include <QWidget>
#include<QToolBar>


#ifndef WINDOW_H
#define WINDOW_H

// créer la fenêtre principale de l'application
#include <QMainWindow>
#include <QTextEdit>


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
// créer les différentes actions, 
//ajouter les actions aux menus et insérer les menus dans la barre de menus de notre fenêtre principale.
private:
    void createActions();
    void createMenus();
    QTextEdit *textEdit;
    //déclaration des menus et actions
    
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *helpMenu;
    QMenu *ExecMenu;
    QAction *newAct;
    QAction *openAct;
    QAction *saveAct;
    QAction *exitAct;

   
};

#endif
