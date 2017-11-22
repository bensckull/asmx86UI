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
         *  \Define Labels and Editable Fields
         *  \Make all the Editable Field Disabled 
         */ 

variableWidget::variableWidget(QWidget *parent) : QWidget(parent)
{
    QLabel *title = new QLabel("Variables");
    title->adjustSize();

    setFixedSize(300,110);

    var1edit = new QTextEdit;
    var1edit->adjustSize();
    



    var2edit = new QTextEdit;
    var2edit->adjustSize();
    



    var1label = new QLabel("VAR1");
    var2label = new QLabel("VAR2");
    
    /*!Class lines up widgets horizontally*/
    QHBoxLayout *var1Hbox = new QHBoxLayout();
    var1Hbox->addWidget(var1label);
    var1Hbox->addWidget(var1edit);

    QHBoxLayout *var2Hbox = new QHBoxLayout();
    var2Hbox->addWidget(var2label);
    var2Hbox->addWidget(var2edit);

    /*Class lines up widgets vertically*/
    QVBoxLayout *yVbox = new QVBoxLayout(this);
    yVbox->addWidget(title);
    yVbox->addLayout(var1Hbox);
    yVbox->addLayout(var2Hbox);

}

