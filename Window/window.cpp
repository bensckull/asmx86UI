#include "window.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{


    createActions();
    createMenus();
    

    upperBar = new QFrame;
    sideBar = new QFrame;
    sideItemA = new QLabel("Item A");
    sideItemB = new QLabel("Item B");

    contentStack = new QStackedWidget;

    contentPage1 = new QFrame;
    textEdit = new QTextEdit();
    page1WidgetB = new QLabel("widget B");
    page1WidgetC = new QLabel("widget C");
    page1WidgetD = new QLabel("widget D");

    centralWidget = new QWidget;

    //Les layouts nécessaires :
    sideBarLayout = new QVBoxLayout;
    page1GridLayout = new QGridLayout;
    centralLayout = new QGridLayout;

    //Connectons des pièces

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

    resize(1024,768);
}

MainWindow::~MainWindow()
{

}

void MainWindow::newFile()
{
 
    QString txt = textEdit->toPlainText();   
    if (!txt.isEmpty()){
        save();
    }
    else 
        textEdit->setText("");  
       
}

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
         QString contents = file.readAll().constData();
         textEdit->setPlainText(contents);
         
         QString debugS = textEdit->toPlainText();


         qDebug().nospace() << "::" << qPrintable(debugS) << "::";
         QApplication::processEvents();
         file.close();
     }
   
}

void MainWindow::save()
{
 
 QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "",
             tr("Text Files (*.nasm)"));
 
    if (fileName != "") {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            // error message
        } else {
            QTextStream stream(&file);
            stream << textEdit->toPlainText();
            stream.flush();
            /*QMessageBox::critical(this, tr("Error"),
            tr("Le fichier doit être impérativement sous forme *.nasm"));*/
            file.close();

        }
    }
}


void MainWindow::cut(){
      textEdit->cut();

}
void MainWindow::copy(){
      textEdit->copy();
}
void MainWindow::paste(){
      textEdit->paste();
}
//Création des Actions
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
    editMenu->addAction(cutAct);
    editMenu->addAction(copyAct);
    editMenu->addAction(pasteAct);   

    ExecMenu = menuBar()->addMenu(tr("&Execution"));
    helpMenu = menuBar()->addMenu(tr("&Help"));
   

}



