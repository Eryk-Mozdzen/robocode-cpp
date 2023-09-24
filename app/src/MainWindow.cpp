#include <QGridLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QFileInfo>
#include <QDebug>

#include "MainWindow.h"

MainWindow::ImportedRobot::ImportedRobot(const QString path) : name{QFileInfo(path).baseName()}, factory{path.toStdString()} {

}

MainWindow::MainWindow(QWidget *parent) : QWidget{parent} {
    setFixedSize(640, 480);

    QGridLayout *layout = new QGridLayout(this);

    {
        QPushButton *import = new QPushButton("Import Robot", this);

        layout->addWidget(import, 0, 0);

        connect(import, &QPushButton::clicked, [this]() {
            const QString path = QFileDialog::getOpenFileName(this, "Import Robot", "", "Dynamic Linked Libraries (*.so)");

            if(!path.isEmpty()) {
                imports.emplace_back(path);
            }
        });
    }

    {
        QPushButton *spawn = new QPushButton("Spawn Robots", this);

        layout->addWidget(spawn, 1, 0);

        connect(spawn, &QPushButton::clicked, [this]() {
            for(const ImportedRobot &robot : imports) {
                robots.push_back(robot.factory.create());
            }
        });
    }

    {
        QPushButton *clear = new QPushButton("Clear Robots", this);

        layout->addWidget(clear, 2, 0);

        connect(clear, &QPushButton::clicked, [this]() {
            robots.clear();
            imports.clear();
        });
    }

}
