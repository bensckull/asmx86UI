#include "window.h"

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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{




QToolBar *toolbar = new QToolBar();

textEdit = new QTextEdit();



createActions();
createMenus();


QFrame *upperBar = new QFrame;
QFrame *sideBar = new QFrame;
QLabel *sideItemA = new QLabel("Item A");
QLabel *sideItemB = new QLabel("Item B");

QStackedWidget *contentStack = new QStackedWidget;

QFrame *contentPage1 = new QFrame;
QTextEdit *textEdit = new QTextEdit();
QLabel *page1WidgetB = new QLabel("widget B");
QLabel *page1WidgetC = new QLabel("widget C");
QLabel *page1WidgetD = new QLabel("widget D");

QWidget *centralWidget = new QWidget;

//Les layouts nécessaires :
QHBoxLayout *upperBarLayout = new QHBoxLayout;
QVBoxLayout *sideBarLayout = new QVBoxLayout;
QGridLayout *page1GridLayout = new QGridLayout;
QGridLayout *centralLayout = new QGridLayout;

//Connectons des pièces

/* Installation de la barre supérieure */
upperBarLayout->addWidget(toolbar, 1, Qt::AlignLeft);
upperBar->setLayout(upperBarLayout);
upperBar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

/* Installation de la barre latérale */
sideBarLayout->addWidget(sideItemA);
sideBarLayout->addWidget(sideItemB);
sideBarLayout->addStretch();
sideBar->setLayout(sideBarLayout);
sideBar->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

/* configuration du widget de contenu empilé */
page1GridLayout->addWidget(textEdit, 0, 0, 3, 1);
page1GridLayout->addWidget(page1WidgetB, 0, 1, 1, 1);
page1GridLayout->addWidget(page1WidgetC, 1, 1, 2, 1);
page1GridLayout->addWidget(page1WidgetD, 3, 0, 1, 2);
contentPage1->setLayout(page1GridLayout);

contentStack->addWidget(contentPage1);
contentStack->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

/* installation des principaux éléments (layout centrale)*/
centralLayout->addWidget(upperBar, 0, 0, 1, 2);
centralLayout->addWidget(sideBar, 1, 0, 1, 1);
centralLayout->addWidget(contentStack, 1, 1, 1, 1);
centralWidget->setLayout(centralLayout);
setCentralWidget(centralWidget);

/* couleur et border*/
setStyleSheet("QWidget {"
              "border: 1px solid black;"
              "color: black"
              "}");
}

MainWindow::~MainWindow()
{

}

void MainWindow::newFile()
{
 
QString txt = textEdit->toPlainText();   
if (!txt.isEmpty())

{
save();
}
else 
textEdit->setText("");  
   
}

void MainWindow::open()
{
       QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
             tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));
 
         if (fileName != "") {
             QFile file(fileName);
             if (!file.open(QIODevice::ReadOnly)) {
                 QMessageBox::critical(this, tr("Error"),
                     tr("Could not open file"));
                 return;
             }
             QString contents = file.readAll().constData();
             textEdit->setPlainText(contents);
             file.close();
         }
   
}

void MainWindow::save()
{
 
 QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "",
             tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));
 
         if (fileName != "") {
             QFile file(fileName);
             if (!file.open(QIODevice::WriteOnly)) {
                 // error message
             } else {
                 QTextStream stream(&file);
                 stream << textEdit->toPlainText();
                 stream.flush();
                 /*QMessageBox::critical(this, tr("Error"),
                     tr("Le fichier doit être impérativement sous forme *.txt,*.cpp ou *.h"));*/
                 file.close();
                 
             }
         }

}


//Création des Actions
void MainWindow::createActions()
{
  
    newAct = new QAction(tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    newAct->setToolTip("Texte d'aide");
    connect(newAct, &QAction::triggered, this, &MainWindow::newFile);


    openAct = new QAction(tr("&Open"), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));


    saveAct = new QAction(tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the document to disk"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));


    exitAct = new QAction(tr("&Exit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, &QAction::triggered, this, &QWidget::close);
    

}


// Création des menus
void MainWindow::createMenus()
{
   
    
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(exitAct);    


    editMenu = menuBar()->addMenu(tr("&Edit"));
    ExecMenu = menuBar()->addMenu(tr("&Execution"));
    helpMenu = menuBar()->addMenu(tr("&Help"));
   

}







