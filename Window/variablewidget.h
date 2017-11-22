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



#ifndef VARIABLEWIDGET_H
#define VARIABLEWIDGET_H

/* --------------------------------------------------------------------------
 *  Modules
 * -------------------------------------------------------------------------- */

#include <QWidget>
#include <QTextEdit>
#include <QLabel>
#include <QGridLayout>

/* --------------------------------------------------------------------------
 *  Class
 * -------------------------------------------------------------------------- */

class variableWidget : public QWidget
{

    Q_OBJECT
public:
 /*! Constructor
         *
         *  \Parameter with a default value
         */ 
    explicit variableWidget(QWidget *parent = 0);


private:
    /*!Editable Fields*/
    QTextEdit *var1edit;
    QTextEdit *var2edit;
    
    /*!Labels*/
    QLabel *var1label;
    QLabel *var2label;



};

#endif // VARIABLEWIDGET_H
