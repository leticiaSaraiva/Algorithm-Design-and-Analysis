#include "mainwindowcontroller.hpp"
#include "aluno/closestpoints.hpp"
#include "ui_mainwindow.h"

#include <QShortcut>
#include <QGraphicsEllipseItem>

const QPen   MainWindowController::pointNoContour{Qt::NoPen};
const QPen   MainWindowController::pointContour{Qt::black, 3};
const QBrush MainWindowController::pointNoFill{Qt::NoBrush};
const QBrush MainWindowController::pointFill{Qt::red};
const qreal  MainWindowController::pointWidth{10};

MainWindowController::MainWindowController(MainWindow &mainWindow, QObject *parent)
    : QObject{parent}
    , mainWindow{mainWindow}
    , dialogAbout{new AboutDialog{&mainWindow}}
{
    auto ui = mainWindow.ui;

    ui->graphicsView->setScene(&scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing, true);

    connect(ui->actionAdd, &QAction::toggled,
            ui->graphicsView, &QxdGraphicsView::insertionMode);

    connect(
                ui->actionAbout,
                SIGNAL(triggered()),
                dialogAbout,
                SLOT(exec())
                );

    connect(ui->actionNew, &QAction::triggered, this, [this, ui]{
        scene.clear();

        ui->actionAdd->setEnabled(true);
    });

    connect(ui->actionSolve, &QAction::triggered, this, [this, ui]{
        ui->actionAdd->setChecked(false);
        ui->actionAdd->setEnabled(false);

        std::vector<QPointF> allPoints = getAllPoints();

        if(allPoints.size() >= 2) {
            std::pair<QPointF, QPointF> result =
                    ClosestPointsSolver::solveFor(std::move(allPoints));

            highlightPoint(result.first);
            highlightPoint(result.second);
        }
    });
}

std::vector<QPointF> MainWindowController::getAllPoints() const
{
    const auto allItems = scene.items();
    std::vector<QPointF> allPoints;

    allPoints.reserve(static_cast<size_t>(allItems.size()));

    for(QGraphicsItem *item : allItems) {
        allPoints.push_back(item->pos());
    }

    return allPoints;
}

void MainWindowController::highlightPoint(const QPointF &point)
{
    QGraphicsEllipseItem *item = qgraphicsitem_cast<QGraphicsEllipseItem*>(
                scene.itemAt(point, mainWindow.ui->graphicsView->transform())
                );

    if(item) {
        item->setPen(MainWindowController::pointContour);
        item->setBrush(MainWindowController::pointNoFill);
    }
}
