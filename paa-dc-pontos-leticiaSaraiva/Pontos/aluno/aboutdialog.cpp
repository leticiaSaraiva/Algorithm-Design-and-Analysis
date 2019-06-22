/************************************************************************
 **
 **  @file   aboutdialog.cpp
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


#include "aboutdialog.hpp"
#include "ui_aboutdialog.h"

#include <sstream>

AboutDialog::AboutDialog(QWidget *parent)
    : QDialog{parent}
    , ui{new Ui::AboutDialog}
{
    ui->setupUi(this);
    setupInterface();

    setModal(true);
    setWindowModality(Qt::ApplicationModal);
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void
AboutDialog::setupInterface()
{
    std::stringstream aboutText;

    aboutText << u8"<html><body><h2>Sobre</h2><p>Este programa foi desenvolvido como "
                 u8"trabalho prático para a disciplina " << course;
    aboutText << u8" da Universidade Federal do Ceará, <i>Campus</i> Quixadá, no semestre ";
    aboutText << semester << u8".</p>";
    aboutText << u8"<p>Os seguintes professores estiveram envolvidos: <ul>"
                 u8"<li>Arthur Araruna &lt;<a href=\"mailto:ararunaufc@gmail.com\">ararunaufc@gmail.com</a>&gt;"
                 u8"</ul></p>"
                 u8"<p>Os seguintes alunos fazem parte da equipe que gerou esta versão em específico:<ul>";

    std::string authorName, authorEmail;

    for(auto &author : authors) {
        std::tie(authorName, authorEmail) = author;

        aboutText << u8"<li>" << authorName << u8" &lt;<a href=\"mailto:" << authorEmail << u8"\">";
        aboutText << authorEmail << u8"</a>&gt;</li>";
    }

    aboutText << u8"</ul><h2>Licença</h2><p>Este projeto é um software livre: você pode redistribuir e/ou "
                 u8"modificar seu código sob os termos da GNU General Public License, publicada pela "
                 u8"Free Software Foundation, na versão 3 ou (sob seu critério) qualquer versão posterior.</p>"
                 u8"Este projeto foi distribuído na esperança de ser útil, porém SEM NENHUMA GARANTIA. "
                 u8"Veja a GNU General Public License para maiores detalhes.</p>"
                 u8"</body></html>";

    ui->textBrowserAuthors->setHtml(QString::fromStdString(aboutText.str()));
}
