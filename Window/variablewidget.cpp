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

#include "variablewidget.h"


/*! Constructor
         *
         *  \Define Label and QVBoxLayout 
         */ 
variableWidget::variableWidget(QWidget *parent) : QWidget(parent)

{
    QLabel *title = new QLabel("VARIABLES");
    title->adjustSize();
    title->setStyleSheet("QLabel {color : white;background-color: darkgrey;padding: 1px;border-style: solid;border: 2px solid gray;border-radius: 8px;}");
    setFixedSize(300,170);


    /*Class lines up widgets vertically*/
    yVbox = new QVBoxLayout(this);
    yVbox->addWidget(title);
}

         
         
/*remove*/
void remove(QLayout* layout)
{
    QLayoutItem* child;
    while(layout->count()!=0)
    {
        child = layout->takeAt(0);
        if(child->layout() != 0)
        {
            remove(child->layout());
        }
        else if(child->widget() != 0)
        {
            delete child->widget();
        }

        delete child;
    }
}

/*Define Labels and Editable Fields*/
void variableWidget::addVar(const std::string &name , const std::string &val){
    QLabel *var1label = new QLabel(QString::fromStdString(name));
    
    
    QLineEdit *var1edit = new QLineEdit(QString::fromStdString(val));
    var1edit->adjustSize();
    
    QHBoxLayout *var1Hbox = new QHBoxLayout();
    var1Hbox->addWidget(var1label);
    var1Hbox->addWidget(var1edit);
    
    var1edit->setStyleSheet("QLineEdit {padding: 1px;border-style: solid;border: 2px solid gray;border-radius: 8px;}");
    var1label->setStyleSheet("QLabel {color :rgb(255,50,0); }");
    yVbox->addLayout(var1Hbox);

}

void variableWidget::clear() {
    remove(yVbox);
}
    

