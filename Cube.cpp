#include "Cube.h"

Cube::Cube() {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                data_[i][j][k] = i;
            }
        }
    }
}

void Cube::rotate(char direction, int rotationCnt) {
    rotationCnt = ((rotationCnt % 4) + 4) % 4;
    Cube newCube = *this;
    switch (direction) {
        case 'R':
            for (int k = 0; k < rotationCnt; ++k) {
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        newCube.data_[2][i][j] = this->data_[2][2 - j][i];
                    }
                    newCube.data_[0][i][2] = this->data_[5][i][2];
                    newCube.data_[1][i][2] = this->data_[0][i][2];
                    newCube.data_[4][i][0] = this->data_[1][2 - i][2];
                    newCube.data_[5][i][2] = this->data_[4][2 - i][0];
                }
                *this = newCube;
            }
            break;

        case 'L':
            for (int k = 0; k < rotationCnt; ++k) {
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        newCube.data_[3][i][j] = this->data_[3][2 - j][i];
                    }
                    newCube.data_[0][i][0] = this->data_[1][i][0];
                    newCube.data_[1][i][0] = this->data_[4][2 - i][2];
                    newCube.data_[4][i][2] = this->data_[5][2 - i][0];
                    newCube.data_[5][i][0] = this->data_[0][i][0];
                }
                *this = newCube;
            }
            break;

        case 'U':
            for (int k = 0; k < rotationCnt; ++k) {
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        newCube.data_[1][i][j] = this->data_[1][2 - j][i];
                    }
                    newCube.data_[0][0][i] = this->data_[2][0][i];
                    newCube.data_[2][0][i] = this->data_[4][0][i];
                    newCube.data_[3][0][i] = this->data_[0][0][i];
                    newCube.data_[4][0][i] = this->data_[3][0][i];
                }
                *this = newCube;
            }
            break;

        case 'D':
            for (int k = 0; k < rotationCnt; ++k) {
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        newCube.data_[5][i][j] = this->data_[5][2 - j][i];
                    }
                    newCube.data_[0][2][i] = this->data_[3][2][i];
                    newCube.data_[2][2][i] = this->data_[0][2][i];
                    newCube.data_[3][2][i] = this->data_[4][2][i];
                    newCube.data_[4][2][i] = this->data_[2][2][i];
                }
                *this = newCube;
            }
            break;

        case 'F':
            for (int k = 0; k < rotationCnt; ++k) {
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        newCube.data_[0][i][j] = this->data_[0][2 - j][i];
                    }
                    newCube.data_[1][2][i] = this->data_[3][2 - i][2];
                    newCube.data_[2][i][0] = this->data_[1][2][i];
                    newCube.data_[3][i][2] = this->data_[5][0][i];
                    newCube.data_[5][0][i] = this->data_[2][2 - i][0];
                }
                *this = newCube;
            }
            break;

        case 'B':
            for (int k = 0; k < rotationCnt; ++k) {
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        newCube.data_[4][i][j] = this->data_[4][2 - j][i];
                    }
                    newCube.data_[1][0][i] = this->data_[2][i][2];
                    newCube.data_[2][i][2] = this->data_[5][2][2 - i];
                    newCube.data_[3][i][0] = this->data_[1][0][2 - i];
                    newCube.data_[5][2][i] = this->data_[3][i][0];
                }
                *this = newCube;
            }
            break;

        case 'M':
            for (int k = 0; k < rotationCnt; ++k) {
                for (int i = 0; i < 3; ++i) {
                    newCube.data_[0][i][1] = this->data_[1][i][1];
                    newCube.data_[1][i][1] = this->data_[4][2 - i][1];
                    newCube.data_[4][i][1] = this->data_[5][2 - i][1];
                    newCube.data_[5][i][1] = this->data_[0][i][1];
                }
                *this = newCube;
            }
            break;

        case 'E':
            for (int k = 0; k < rotationCnt; ++k) {
                for (int i = 0; i < 3; ++i) {
                    newCube.data_[0][1][i] = this->data_[3][1][i];
                    newCube.data_[2][1][i] = this->data_[0][1][i];
                    newCube.data_[3][1][i] = this->data_[4][1][i];
                    newCube.data_[4][1][i] = this->data_[2][1][i];
                }
                *this = newCube;
            }
            break;

        case 'S':
            for (int k = 0; k < rotationCnt; ++k) {
                for (int i = 0; i < 3; ++i) {
                    newCube.data_[1][1][i] = this->data_[3][2 - i][1];
                    newCube.data_[2][i][1] = this->data_[1][1][i];
                    newCube.data_[3][i][1] = this->data_[5][1][i];
                    newCube.data_[5][1][i] = this->data_[2][2 - i][1];
                }
                *this = newCube;
            }
            break;

        case 'u':
            for (int k = 0; k < rotationCnt; ++k) {
                newCube.rotate('U', 1);
                newCube.rotate('E', -1);
                *this = newCube;
            }
            break;

        case 'd':
            for (int k = 0; k < rotationCnt; ++k) {
                newCube.rotate('E', 1);
                newCube.rotate('D', 1);
                *this = newCube;
            }
            break;

        case 'r':
            for (int k = 0; k < rotationCnt; ++k) {
                newCube.rotate('R', 1);
                newCube.rotate('M', -1);
                *this = newCube;
            }
            break;

        case 'l':
            for (int k = 0; k < rotationCnt; ++k) {
                newCube.rotate('L', 1);
                newCube.rotate('M', 1);
                *this = newCube;
            }
            break;

        case 'f':
            for (int k = 0; k < rotationCnt; ++k) {
                newCube.rotate('F', 1);
                newCube.rotate('S', 1);
                *this = newCube;
            }
            break;

        case 'b':
            for (int k = 0; k < rotationCnt; ++k) {
                newCube.rotate('B', 1);
                newCube.rotate('S', -1);
                *this = newCube;
            }
            break;

        case 'x':
            for (int k = 0; k < rotationCnt; ++k) {
                newCube.rotate('L', -1);
                newCube.rotate('r', 1);
                *this = newCube;
            }
            break;

        case 'y':
            for (int k = 0; k < rotationCnt; ++k) {
                newCube.rotate('u', 1);
                newCube.rotate('D', -1);
                *this = newCube;
            }
            break;

        case 'z':
            for (int k = 0; k < rotationCnt; ++k) {
                newCube.rotate('f', 1);
                newCube.rotate('B', -1);
                *this = newCube;
            }
            break;

        default:
            std::cout << "Unknown command: " << direction << "\n\n";
            break;
    }
}

std::ostream& printColor(std::ostream& os, const int& color) {
    switch(color) {
        case 5:
            fmt::print(fmt::bg(fmt::color::gold),"  ");
            break;
        case 1:
            fmt::print(fmt::bg(fmt::color::white),"  ");
            break;
        case 4:
            fmt::print(fmt::bg(fmt::color::blue),"  ");
            break;
        case 0:
            fmt::print(fmt::bg(fmt::color::green),"  ");
            break;
        case 2:
            fmt::print(fmt::bg(fmt::color::fire_brick),"  ");
            break;
        case 3:
            fmt::print(fmt::bg(fmt::color::orange_red),"  ");
            break;
        default:
            break;
    }
    return os;
}

std::ostream& writeCubeToConsole(std::ostream& os, const Cube& cube) {
    for (int i = 0; i < 3; ++i) {
        std::cout << std::setfill(' ') << std::setw(8) << ' ';
        for (int j = 0; j < 3; ++j) {
            printColor(os, cube.data_[1][i][j]);
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    for (int k = 0; k < 3; ++k) {
        for (int faceNum: {3, 0, 2, 4}) {
            for (int i = 0; i < 3; ++i) {
                printColor(os, cube.data_[faceNum][k][i]);
            }
            std::cout << "  ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    for (int i = 0; i < 3; ++i) {
        std::cout << std::setfill(' ') << std::setw(8) << ' ';
        for (int j = 0; j < 3; ++j) {
            printColor(os, cube.data_[5][i][j]);
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    return os;
}

std::ostream& writeCubeToFile(std::ostream& os, const Cube& cube) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 6; ++j) {
            for (int k = 0; k < 3; ++k) {
                os << cube.data_[j][i][k] << ' ';
            }
        }
        os << '\n';
    }
    return os;
}

std::ostream& operator<< (std::ostream& os, const Cube& cube) {
    if (&os == &std::cout) {
        return writeCubeToConsole(os, cube);
    }
    return writeCubeToFile(os, cube);
}

std::istream &operator>>(std::istream &os, Cube &cube) {
    if (&os == &std::cin) {
        throw std::logic_error("read from cin is unsupported");
    }
    int cnt = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 6; ++j) {
            for (int k = 0; k < 3; ++k) {
                os >> cube.data_[j][i][k];
                ++cnt;
                if (cube.data_[j][i][k] > 5 || cube.data_[j][i][k] < 0)
                    throw std::runtime_error("Wrong file format");
            }
        }
    }
    if (cnt < 54)
        throw std::runtime_error("Not enough data");
    return os;
}

std::string Cube::orient() {
    std::string result;

    while (data_[0][1][1] != 0 && data_[0][1][1] != 1) {
        rotate('y', 1);
        result += "y ";
    }

    if (data_[0][1][1] == 1) {
        rotate('x', 1);
        result += "x ";
    }

    while (data_[1][1][1] != 1) {
        rotate('z', 1);
        result += "z ";
    }

    while (data_[0][1][1] != 0) {
        rotate('y', 1);
        result += "y ";
    }
    return result;
}

void Cube::rotateByStream(std::stringstream &ss) {
    if (ss.eof())
        throw std::logic_error("Rotations expected");
    std::string rotation;
    while (ss >> rotation) {
        if (rotation == "R") {
            rotate('R', 1);
        } else if (rotation == "R'") {
            rotate('R', -1);
        } else if (rotation == "R2") {
            rotate('R', 2);
        } else if (rotation == "L") {
            rotate('L', 1);
        } else if (rotation == "L'") {
            rotate('L', -1);
        } else if (rotation == "L2") {
            rotate('L', 2);
        } else if (rotation == "U") {
            rotate('U', 1);
        } else if (rotation == "U'") {
            rotate('U', -1);
        } else if (rotation == "U2") {
            rotate('U', 2);
        } else if (rotation == "D") {
            rotate('D', 1);
        } else if (rotation == "D'") {
            rotate('D', -1);
        } else if (rotation == "D2") {
            rotate('D', 2);
        } else if (rotation == "F") {
            rotate('F', 1);
        } else if (rotation == "F'") {
            rotate('F', -1);
        } else if (rotation == "F2") {
            rotate('F', 2);
        } else if (rotation == "B") {
            rotate('B', 1);
        } else if (rotation == "B'") {
            rotate('B', -1);
        } else if (rotation == "B2") {
            rotate('B', 2);
        } else if (rotation == "u" || rotation == "Uw") {
            rotate('u', 1);
        } else if (rotation == "u'" || rotation == "Uw'") {
            rotate('u', -1);
        } else if (rotation == "u2" || rotation == "Uw2") {
            rotate('u', 2);
        } else if (rotation == "d" || rotation == "Dw") {
            rotate('d', 1);
        } else if (rotation == "d'" || rotation == "Dw'") {
            rotate('d', -1);
        } else if (rotation == "d2" || rotation == "Dw2") {
            rotate('d', 2);
        } else if (rotation == "r" || rotation == "Rw") {
            rotate('r', 1);
        } else if (rotation == "r'" || rotation == "Rw'") {
            rotate('r', -1);
        } else if (rotation == "r2" || rotation == "Rw2") {
            rotate('r', 2);
        } else if (rotation == "l" || rotation == "Lw") {
            rotate('l', 1);
        } else if (rotation == "l'" || rotation == "Lw'") {
            rotate('l', -1);
        } else if (rotation == "l2" || rotation == "Lw2") {
            rotate('l', 2);
        } else if (rotation == "f" || rotation == "Fw") {
            rotate('f', 1);
        } else if (rotation == "f'" || rotation == "Fw'") {
            rotate('f', -1);
        } else if (rotation == "f2" || rotation == "Fw2") {
            rotate('f', 2);
        } else if (rotation == "b" || rotation == "Bw") {
            rotate('b', 1);
        } else if (rotation == "b'" || rotation == "Bw'") {
            rotate('b', -1);
        } else if (rotation == "b2" || rotation == "Bw2") {
            rotate('b', 2);
        } else if (rotation == "x") {
            rotate('x', 1);
        } else if (rotation == "x'") {
            rotate('x', -1);
        } else if (rotation == "x2") {
            rotate('x', 2);
        } else if (rotation == "y") {
            rotate('y', 1);
        } else if (rotation == "y'") {
            rotate('y', -1);
        } else if (rotation == "y2") {
            rotate('y', 2);
        } else if (rotation == "z") {
            rotate('z', 1);
        } else if (rotation == "z'") {
            rotate('z', -1);
        } else if (rotation == "z2") {
            rotate('z', 2);
        } else if (rotation == "M") {
            rotate('M', 1);
        } else if (rotation == "M'") {
            rotate('M', -1);
        } else if (rotation == "M2") {
            rotate('M', 2);
        } else if (rotation == "E") {
            rotate('E', 1);
        } else if (rotation == "E'") {
            rotate('E', -1);
        } else if (rotation == "E2") {
            rotate('E', 2);
        } else if (rotation == "S") {
            rotate('S', 1);
        } else if (rotation == "S'") {
            rotate('S', -1);
        } else if (rotation == "S2") {
            rotate('S', 2);
        } else {
            std::cerr << "Unknown move: " << rotation << ", rotation stopped\n";
            break;
        }
    }
}

std::string Cube::check() {
    Cube tmpCube = *this;
    if (tmpCube.solve() == "-1")
        return "Cube is invalid";
    else
        return "Cube is valid";
}

void Cube::randomize(size_t length) {
    const std::string moves = "RLUDFBudrlfbxyzMES";
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(0, moves.size() - 1);

    std::string result;

    for (size_t i = 0; i < length; ++i) {
        result += moves[distribution(generator)];
        result += " ";
    }
    std::stringstream res(result);
    rotateByStream(res);
    std::cout << "Generated scramble " << result << "\n\n";
}

void Cube::reset() {
    *this = Cube();
}

void Cube::save(const std::string& path) {
    std::fstream file;
    file.open(path, std::fstream::out);
    file << *this;
    file.close();
}

void Cube::load(const std::string& path) {
    std::fstream file;
    file.open(path, std::fstream::in);
    file >> *this;
    file.close();
}


