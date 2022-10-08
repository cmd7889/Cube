#pragma once
#include <array>
#include <iostream>
#define FMT_HEADER_ONLY
#include "fmt/core.h"
#include "fmt/format.h"
#include "fmt/color.h"
#include <iomanip>
#include <random>
#include <fstream>

using std::array;

class Cube {
private:
    array <array <array <int, 3>, 3>, 6 > data_;
    friend std::ostream& writeCubeToConsole(std::ostream& os, const Cube& cube);
    friend std::ostream& writeCubeToFile(std::ostream& os, const Cube& cube);
    friend std::ostream& printColor(std::ostream& os, const int& color);
public:
    Cube();
    ~Cube() = default;
    Cube(Cube const &) = default;
    void rotate(char direction, int rotationCnt);
    void rotateByStream(std::stringstream& ss);
    std::string orient();
    friend std::ostream& operator<< (std::ostream& os, const Cube& cube);
    friend std::istream& operator>> (std::istream& os, Cube& cube);
    std::string solve();
    std::string check();
    void randomize(size_t length = 40);
    void save(const std::string& path);
    void load(const std::string& path);
    void reset();
};

