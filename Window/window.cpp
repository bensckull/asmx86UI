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

/* --------------------------------------------------------------------------
 *  Modules
 * -------------------------------------------------------------------------- */

#include "window.h"

/*! Constructor
         *
         *  \Define Labels,Frames and Layouts
         *  \Define Widgets
         */ 

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{


    createActions();
    createMenus();
    
    

    upperBar = new QFrame;
    sideBar = new QFrame;

    sideItemA = new registerWidget();
    sideItemB = new variableWidget();

    contentStack = new QStackedWidget;

    contentPage1 = new QFrame;
    textEdit = new CodeEditor();
    page1WidgetB = new QLabel("widget B");
    page1WidgetC = new QLabel("widget C");
    page1WidgetD = new QLabel("widget D");

    centralWidget = new QWidget;

 
   
    sideBarLayout = new QVBoxLayout;
    page1GridLayout = new QGridLayout;
    centralLayout = new QGridLayout;
    
    /*!Connect the pieces
         *  \Setup the upperbar
         *  \Setup the sidebar
	 *  \Setup the content stacked widget
         *  \Setup the main elements into the central layout
         */ 
  
    sideBarLayout->addWidget(sideItemA);
    sideBarLayout->addWidget(sideItemB);
    sideBarLayout->addStretch();
    sideBar->setLayout(sideBarLayout);
    sideBar->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

   
    page1GridLayout->addWidget(textEdit, 0, 0, 3, 1);
    page1GridLayout->addWidget(page1WidgetB, 0, 1, 1, 1);
    page1GridLayout->addWidget(page1WidgetC, 1, 1, 2, 1);
    page1GridLayout->addWidget(page1WidgetD, 3, 0, 1, 2);
    contentPage1->setLayout(page1GridLayout);

    contentStack->addWidget(contentPage1);
    contentStack->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    
    centralLayout->addWidget(upperBar, 0, 0, 1, 2);
    centralLayout->addWidget(sideBar, 1, 0, 1, 1);
    centralLayout->addWidget(contentStack, 1, 1, 1, 1);
    centralWidget->setLayout(centralLayout);
    setCentralWidget(centralWidget);

    /*Color and border*/
    setStyleSheet("QWidget {"
                  "border: 1px solid black;"
                  "color: black"
                  "}");

    resize(1024,768);
}

MainWindow::~MainWindow()
{

}

/*!Create a new file*/
void MainWindow::newFile()
{
 
    QString txt = textEdit->toPlainText();   
    if (!txt.isEmpty()){
        
       
 QMessageBox msgBox;
 msgBox.setText("Le document a été modifié.");
 msgBox.setInformativeText("Voulez-vous enregistrer les changements ?");
 msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
 msgBox.setDefaultButton(QMessageBox::Save);
 int ret = msgBox.exec();

  switch (ret) {
   case QMessageBox::Save:
      save();
       break;

   case QMessageBox::Discard:
      textEdit->setPlainText("" );

       break;
   case QMessageBox::Cancel:

       break;
 }
        
    }
   
}

/*!Open a file*/
void MainWindow::open()
{
   QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
         tr("Text Files (*.nasm)"));

     if (fileName != "") {

        
         QFile file(fileName);
         
         if (!file.open(QIODevice::ReadOnly)) {
             QMessageBox::critical(this, tr("Error"),
                 tr("Could not open file"));
             return;
         }
      

         parser = new  AsmParser(fileName.toStdString());
        
         QString contents = file.readAll().constData();
         textEdit->setPlainText(contents);
         
         QString debugS = textEdit->toPlainText();


         qDebug().nospace() << "::" << qPrintable(debugS) << "::";
         QApplication::processEvents();
         file.close();
     }
   
}
 /*!Save a file*/
void MainWindow::save()
{
 
 QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "",
             tr("Text Files (*.nasm)"));
 
    if (fileName != "") {
     if (!fileName.contains(".nasm")){
            fileName +=".nasm";
        }
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            // error message
        } else {
            QTextStream stream(&file);
            stream << textEdit->toPlainText();
            stream.flush();
            file.close();

        }
    }
}

/*!Cut the contents of the file*/
void MainWindow::cut(){
      textEdit->cut();

}
/*!Copy the contents of the file*/
void MainWindow::copy(){
      textEdit->copy();
}
/*!Paste the contents of a file*/
void MainWindow::paste(){
      textEdit->paste();
}
/*!Undo(previous)*/
void MainWindow::undo(){
      textEdit->undo();
}
/*!Redo(next)*/
void MainWindow::redo(){
      textEdit->redo();
}

 /*!Create Actions
         *  \Connect slots to signals
         *  \Add Actions to the toolbar
         *  \Add Icon
	 */

void MainWindow::createActions()
{
    
    QToolBar *fileToolBar = addToolBar(tr("File"));
    
    const QIcon newIcon = QIcon::fromTheme("document-new", QIcon("new.png"));
    newAct = new QAction(newIcon,tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    newAct->setToolTip("Texte d'aide");
    connect(newAct, &QAction::triggered, this, &MainWindow::newFile);
    fileToolBar->addAction(newAct);

    const QIcon openIcon = QIcon::fromTheme("document-open",QIcon("cut.png"));
    openAct = new QAction(openIcon,tr("&Open"), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));
    fileToolBar->addAction(openAct);

    const QIcon saveIcon = QIcon::fromTheme("document-save", QIcon("save.png"));
    saveAct = new QAction(saveIcon,tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the document to disk"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));
    fileToolBar->addAction(saveAct);

    const QIcon exitIcon = QIcon::fromTheme("application-exit");
    exitAct = new QAction(exitIcon ,tr("&Exit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, &QAction::triggered, this, &QWidget::close);
   
    fileToolBar->addSeparator();
    fileToolBar->addSeparator();    

    const QIcon cutIcon = QIcon::fromTheme("edit-cut", QIcon("cut.png"));
    cutAct = new QAction(cutIcon,tr("Cu&t"), this);
    cutAct->setShortcuts(QKeySequence::Cut);
    cutAct->setStatusTip(tr("Cut the current selection's contents to the""clipboard"));
    connect(cutAct, SIGNAL(triggered()), this, SLOT(cut()));
    fileToolBar->addAction(cutAct);
    

    const QIcon copyIcon = QIcon::fromTheme("edit-copy", QIcon("copy.png"));
    copyAct = new QAction(copyIcon,tr("&Copy"), this);    
    copyAct->setShortcuts(QKeySequence::Copy);
    copyAct->setStatusTip(tr("Copy the current selection's contents to the ""clipboard"));
    connect(copyAct, SIGNAL(triggered()), this, SLOT(copy()));
    fileToolBar->addAction(copyAct);

    const QIcon pasteIcon = QIcon::fromTheme("edit-paste", QIcon("paste.png"));
    pasteAct = new QAction(pasteIcon,tr("&Paste"), this);
    pasteAct->setShortcuts(QKeySequence::Paste);
    pasteAct->setStatusTip(tr("Paste the clipboard's contents into the current ""selection"));
    connect(pasteAct, SIGNAL(triggered()), this, SLOT(paste()));
    fileToolBar->addAction(pasteAct);

    const QIcon undoIcon = QIcon::fromTheme("edit-undo", QIcon("undo.png"));
    undoAct = new QAction(undoIcon,tr("&Undo"), this);
    undoAct->setShortcuts(QKeySequence::Undo);
    undoAct->setStatusTip(tr("Previous"));
    connect(undoAct, SIGNAL(triggered()), this, SLOT(undo()));
    fileToolBar->addAction(undoAct);

    

    const QIcon redoIcon = QIcon::fromTheme("edit-redo", QIcon("redo.png"));
    redoAct = new QAction(redoIcon,tr("&Redo"), this);
    redoAct->setShortcuts(QKeySequence::Redo);
    redoAct->setStatusTip(tr("Next"));
    connect(redoAct, SIGNAL(triggered()), this, SLOT(redo()));
    fileToolBar->addAction(redoAct);

}

/*!Create Menus
         *  \Add Actions to the Menu
         *
	 */


void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(exitAct);    
  

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(cutAct);
    editMenu->addAction(copyAct);
    editMenu->addAction(pasteAct);   

    ExecMenu = menuBar()->addMenu(tr("&Execution"));
    helpMenu = menuBar()->addMenu(tr("&Help"));
   

}



