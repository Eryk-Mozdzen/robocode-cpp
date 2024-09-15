#pragma once

#include <vector>
#include <QWidget>

#include "RobotFactory.h"

class MainWindow : public QWidget {
    struct ImportedRobot {
        QString name;
        RobotFactory factory;

        ImportedRobot(const QString path);
    };

    std::vector<ImportedRobot> imports;

    std::vector<std::unique_ptr<robocode::Robot>> robots;

public:
    MainWindow(QWidget *parent = nullptr);
};
