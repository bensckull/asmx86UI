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

#include "registerwidget.h"

/*! Constructor
         *
         *  \Define Labels and Editable Fields
         *  \Make all the Editable Field Disabled 
         */ 

registerWidget::registerWidget(QWidget *parent) : QWidget(parent)
{
    QLabel *title = new QLabel("REGISTRES");
    title->adjustSize();
    title->setStyleSheet("QLabel {color : white;background-color: darkgrey;padding: 1px;border-style: solid;border: 2px solid gray;border-radius: 8px;}");
    setFixedSize(300,160);

    /*!QVBoxLayout Class lines up widgets vertically*/
    grandLayout = new QVBoxLayout(this);
    grandLayout->addWidget(title);
}


/*remove*/
void clearRegister(QLayout* layout)
{
    QLayoutItem* child;
    while(layout->count()!=0)
    {
        child = layout->takeAt(0);
        if(child->layout() != 0)
        {
            clearRegister(child->layout());
        }
        else if(child->widget() != 0)
        {
            delete child->widget();
        }

        delete child;
    }
}



void registerWidget::clear() {
    clearRegister(grandLayout);
}

 
void registerWidget::setRegister(vector <AsmRegister*> registers, string content) {


    QFormLayout *layoutf1 = new QFormLayout;
    QFormLayout *layoutf2 = new QFormLayout;

    for(unsigned int i=0; i< registers.size(); i++) {
    
        if(content.find(registers[i]->get_label())==std::string::npos)
            continue;
        QLabel *eaxLabel = new QLabel(QString::fromStdString(registers[i]->get_label()));
        QLineEdit *eaxEdit = new QLineEdit(QString::fromStdString(std::to_string(registers[i]->get_value())));
        eaxEdit->setStyleSheet("QLineEdit {padding: 1px;border-style: solid;border: 2px solid gray;border-radius: 8px;}");
        eaxLabel->setStyleSheet("QLabel {color : green; }");
        if(registers[i]->get_label().find("x")!=std::string::npos) {
            layoutf1->addRow(eaxLabel,eaxEdit);
            
        } else {
            layoutf2->addRow(eaxLabel,eaxEdit);
        }
    }
    
    QHBoxLayout *genLay = new QHBoxLayout();
    genLay->addLayout(layoutf1);
    genLay->addLayout(layoutf2);
    grandLayout->addLayout(genLay);
}

