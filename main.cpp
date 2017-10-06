#include <QApplication>
#include "window.h"

int main(int argc, char *argv[]) {
    
  QApplication app(argc, argv);  

 MainWindow window;

  window.setWindowTitle("Interpréteur ASMX86");
  window.show();

  return app.exec();
}

