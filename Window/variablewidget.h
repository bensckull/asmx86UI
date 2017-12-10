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
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <string>
using namespace std;
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
     
    /*add variable*/
    void addVar(const std::string &name , const std::string &val);
    void clear();
private:
    /*!Editable Fields*/
    QVBoxLayout *yVbox;
    
    

};

#endif // VARIABLEWIDGET_H
