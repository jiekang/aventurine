/*
    Aventurine Alpha
    Copyright (C) 2014  Jie Kang

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef FILEREADER_H
#define FILEREADER_H

#include<iostream>

#include "storage.h"
#include "atomiccounter.h"

class FileReader
{
    public:
        FileReader(Storage* storage, AtomicCounter* stopSignal, char* fileName);
        void startReaderThread();

    private:
        const std::string regex = "BM:((ENTRY)|(EXIT)):.*:.*";

        MethodData parseLineToMethodData(std::string line);
        void parseLine(std::string line);
        bool shouldContinueReading();
        void readFile();

        Storage* storage;
        AtomicCounter* stopSignal;
        char* fileName;
};

#endif // FILEREADER_H
