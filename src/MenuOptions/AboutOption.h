/*

This file is part of TinyWatchy.
Copyright 2023, Michał Szczepaniak <m.szczepaniak.000@gmail.com>

TinyWatchy is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

TinyWatchy is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with TinyWatchy. If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef TINYWATCHY_ABOUTOPTION_H
#define TINYWATCHY_ABOUTOPTION_H

#include <esp_attr.h>
#include "AbstractOption.h"
#include "Watchy/bma.h"
#include "ArduinoNvs.h"

class AboutOption : public AbstractOption {
public:
    AboutOption(BMA423* accelerometer);

    std::string getTitle() override { return "About"; };
    std::string getDescription() override;
    void onNextButtonPressed() override;
    void onPrevButtonPressed() override;
    bool onSelectButtonPressed() override;
    void onBackButtonPressed() override;

private:
    RTC_DATA_ATTR static uint8_t _option;
    BMA423* _accelerometer;
    ArduinoNvs _nvs;
    static const uint8_t MAX_OPTION;
};

#endif //TINYWATCHY_ABOUTOPTION_H