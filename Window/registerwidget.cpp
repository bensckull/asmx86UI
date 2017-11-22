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
QLabel *title = new QLabel("Registres");
title->adjustSize();

setFixedSize(300,190);

eaxEdit = new QTextEdit;
ebxEdit = new QTextEdit;
ecxEdit = new QTextEdit;
edxEdit = new QTextEdit;
ebpEdit = new QTextEdit;
espEdit = new QTextEdit;
esiEdit = new QTextEdit;
ediEdit = new QTextEdit;







eaxLabel = new QLabel("EAX");
ebxLabel = new QLabel("EBX");
ecxLabel = new QLabel("ECX");
edxLabel = new QLabel("EDX");
ebpLabel = new QLabel("EBP");
espLabel = new QLabel("ESP");
esiLabel = new QLabel("ESI");
ediLabel = new QLabel("EDI");

QFormLayout *layoutf1 = new QFormLayout;
     layoutf1->addRow(eaxLabel,eaxEdit);
     layoutf1->addRow(ebxLabel,ebxEdit);
     layoutf1->addRow(ecxLabel,ecxEdit);
     layoutf1->addRow(edxLabel,edxEdit);


QFormLayout *layoutf2 = new QFormLayout;
     layoutf2->addRow(ebpLabel,ebpEdit);
     layoutf2->addRow(espLabel,espEdit);
     layoutf2->addRow(esiLabel,esiEdit);
     layoutf2->addRow(ediLabel,ediEdit);


   
/*!QHBoxLayout Class lines up widgets horizontally*/
QHBoxLayout *genLay = new QHBoxLayout();
genLay->addLayout(layoutf1);
genLay->addLayout(layoutf2);

/*!QVBoxLayout Class lines up widgets vertically*/
QVBoxLayout *grandLayout = new QVBoxLayout(this);
grandLayout->addWidget(title);
grandLayout->addLayout(genLay);
}

