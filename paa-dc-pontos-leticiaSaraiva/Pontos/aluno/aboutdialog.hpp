/************************************************************************
 **
 **  @file   aboutdialog.hpp
 **  @date   2018-7-5
 **  @author Arthur Rodrigues Araruna <ararunaufc(at)gmail.com>
 **
 **  @brief
 **
 **  @copyright
 **  This source code is part of an educational project, associated with
 **  a undergraduate course or extension project, that is hosted at
 **  Universidade Federal do Ceará, Campus Quixadá.
 **  Copyright (C) 2018 UFC Quixadá, All Rights Reserved.
 **
 **  This project is free software: you can redistribute it and/or modify
 **  it under the terms of the GNU General Public License as published by
 **  the Free Software Foundation, either version 3 of the License, or
 **  (at your option) any later version.
 **
 **  This project is distributed in the hope that it will be useful,
 **  but WITHOUT ANY WARRANTY; without even the implied warranty of
 **  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **  GNU General Public License for more details.
 **
 **  You should have received a copy of the GNU General Public License
 **  along with the source code of this project. If not, see
 **  <http://www.gnu.org/licenses/>.
 **
 *************************************************************************/


#ifndef ABOUTDIALOG_HPP
#define ABOUTDIALOG_HPP

#include <QDialog>
#include <QString>

#include <memory>
#include <string>

namespace Ui {
class AboutDialog;
}

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget *parent = Q_NULLPTR);
    ~AboutDialog();

    AboutDialog(AboutDialog &) = delete;
    void operator=(AboutDialog const &x) = delete;

private:
    Ui::AboutDialog *ui;

    //----------------- Preencher -----------------

    const std::string course{u8"Projeto e Análise de Algoritmos (QXD0041)"};
    const std::string semester{"2018.2"};

    // Lista de nomes e emails dos autores (equipe)
    // **OBS**: Na parte de nomes, iniciar com `u8"` é importante por conta da acentuação
    const std::vector<std::tuple<const std::string, const std::string>> authors{
        {u8"Letícia Saraiva Chaves", "leticiasaraiva@alu.ufc.br"}
    };

    //---------------------------------------------

    void setupInterface();
};

#endif // ABOUTDIALOG_HPP
