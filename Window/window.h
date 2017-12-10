/* --------------------------------------------------------------------------
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * -------------------------------------------------------------------------- */

/*! variablewidget.h
 *
 *  \author YassineAi <yassine.soudane@gmail.com>
 *  \version 1.0
 *  \date october 2017
 */

#pragma once

#ifndef WINDOW_H
#define WINDOW_H

/* --------------------------------------------------------------------------
 *  Modules
 * -------------------------------------------------------------------------- */

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
#include <QFormLayout>
#include <QApplication>
#include "codeeditor.h"
#include "registerwidget.h"
#include "variablewidget.h"
#include <iostream>
#include <fstream> 
#include "../asmx86/engine/engine.hpp"
using namespace std;
/* --------------------------------------------------------------------------
 *  Class
 * -------------------------------------------------------------------------- */

class QAction;
class QLabel;
class QFrame;
class QMenu;


class MainWindow : public QMainWindow 
{
    Q_OBJECT

public:
   /*! Constructor
         *
         *  \Parameter with a default value
         */ 
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

 /*!Communication between objects */
private slots:
    void newFile();
    void open();
    void save();
    void cut();
    void copy();
    void paste();
    void undo();
    void redo();
    void execution();

/*Creating Actions and Menus*/ 
        
private:
    void createActions();
    void createMenus();
    CodeEditor *textEdit_haut;
     
  
  
    

 /*!Menus and Actions */
    
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
    QAction *undoAct;
    QAction *redoAct;
    QAction *execAct;

    

    QFrame *upperBar;
    QFrame *sideBar;
    registerWidget *sideItemA;
    variableWidget *sideItemB;
    QLabel *sideItemC;
    QStackedWidget *contentStack;

    QFrame *contentPage1;
    QTextEdit   *textEdit_bas;
     

    QWidget *centralWidget;

    /*!The needed Layouts*/

    QHBoxLayout *upperBarLayout;
    QGridLayout *sideBarLayout;
    QGridLayout *page1GridLayout;
    QGridLayout *centralLayout;
    
    /*!Engine*/
    AsmEngine *engine;

   
};

#endif
