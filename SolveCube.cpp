#include "SolveCube.h"



int mainColor(char sticker) {
    switch (sticker) {
        case 'A':
        case 'B':
        case 'C':
        case 'D':
            return 1;

        case 'E':
        case 'F':
        case 'G':
        case 'H':
            return 3;

        case 'I':
        case 'J':
        case 'K':
        case 'L':
            return 0;

        case 'M':
        case 'N':
        case 'O':
        case 'P':
            return 2;

        case 'Q':
        case 'R':
        case 'S':
        case 'T':
            return 4;

        case 'U':
        case 'V':
        case 'W':
        case 'X':
            return 5;

        default:
            throw std::logic_error("Error in determining main color");
    }
}


int additionalColorEdge(char sticker) {
    switch (sticker) {
        case 'A':
        case 'H':
        case 'N':
        case 'W':
            return 4;

        case 'D':
        case 'L':
        case 'R':
        case 'X':
            return 3;

        case 'B':
        case 'J':
        case 'T':
        case 'V':
            return 2;

        case 'C':
        case 'F':
        case 'P':
        case 'U':
            return 0;

        case 'E':
        case 'I':
        case 'M':
        case 'Q':
            return 1;

        case 'G':
        case 'K':
        case 'O':
        case 'S':
            return 5;

        default:
            throw std::logic_error("Error in determining additional color");
    }
}

char adjEdge(char edge) {
    switch (edge) {
        case 'A':
            return 'Q';
        case 'C':
            return 'I';
        case 'D':
            return 'E';

        case 'E':
            return 'D';
        case 'F':
            return 'L';
        case 'G':
            return 'X';
        case 'H':
            return 'R';

        case 'I':
            return 'C';
        case 'J':
            return 'P';
        case 'K':
            return 'U';
        case 'L':
            return 'F';

        case 'N':
            return 'T';
        case 'O':
            return 'V';
        case 'P':
            return 'J';

        case 'Q':
            return 'A';
        case 'R':
            return 'H';
        case 'S':
            return 'W';
        case 'T':
            return 'N';

        case 'U':
            return 'K';
        case 'V':
            return 'O';
        case 'W':
            return 'S';
        case 'X':
            return 'G';

        default:
            throw std::logic_error("-1");
    }
}

std::string edgeSetupMoves(char edge) {
    switch (edge) {
        case 'A':
            return "l2 D' l2 ";
        case 'H':
            return "d L' ";
        case 'N':
            return "d L ";
        case 'W':
            return "D L2 ";

        case 'D':
            return " ";
        case 'L':
            return "L' ";
        case 'R':
            return "L ";
        case 'X':
            return "L2 ";

        case 'B':
            return " ";
        case 'J':
            return "d2 L ";
        case 'T':
            return "d2 L' ";
        case 'V':
            return "D2 L2 ";

        case 'C':
            return "l2 D l2 ";
        case 'F':
            return "d' L ";
        case 'P':
            return "d' L' ";
        case 'U':
            return "D' L2 ";

        case 'E':
            return "L d' L ";
        case 'I':
            return "l D' L2 ";
        case 'M':
            return " ";
        case 'Q':
            return "l' D L2 ";

        case 'G':
            return "L' d' L ";
        case 'K':
            return "l D L2 ";
        case 'O':
            return "D' l D L2 ";
        case 'S':
            return "l' D' L2 ";

        default:
            throw std::logic_error("Error in determining additional color");
    }
}

std::string edgeSwap() {
    return "R U R' U' R' F R2 U' R' U' R U R' F' ";
}

std::string edgeSetupMovesBack(char edge) {
    switch (edge) {
        case 'A':
            return "l2 D l2 ";
        case 'H':
            return "L d' ";
        case 'N':
            return "L' d' ";
        case 'W':
            return "L2 D' ";

        case 'D':
            return " ";
        case 'L':
            return "L ";
        case 'R':
            return "L' ";
        case 'X':
            return "L2 ";

        case 'B':
            return " ";
        case 'J':
            return "L' d2 ";
        case 'T':
            return "L d2 ";
        case 'V':
            return "L2 D2 ";

        case 'C':
            return "l2 D' l2 ";
        case 'F':
            return "L' d ";
        case 'P':
            return "L d ";
        case 'U':
            return "L2 D ";

        case 'E':
            return "L' d L' ";
        case 'I':
            return "L2 D l' ";
        case 'M':
            return " ";
        case 'Q':
            return "L2 D' l ";

        case 'G':
            return "L' d L ";
        case 'K':
            return "L2 D' l' ";
        case 'O':
            return "L2 D' l' D ";
        case 'S':
            return "L2 D l ";

        default:
            throw std::logic_error("Error in determining additional color");
    }
}

/*
std::string solveParity() {
    return "R U' R' U' R U R D R' U' R D' R' U2 R' U' ";
}*/

std::tuple <int, int> additionalColorCorner(char sticker) {
    switch (sticker) {
        case 'A':
            return {3, 4};
        case 'B':
            return {4, 2};
        case 'C':
            return {2, 0};
        case 'D':
            return {0, 3};

        case 'E':
            return {4, 1};
        case 'F':
            return {1, 0};
        case 'G':
            return {0, 5};
        case 'H':
            return {5, 4};

        case 'I':
            return {3, 1};
        case 'J':
            return {1, 2};
        case 'K':
            return {2, 5};
        case 'L':
            return {5, 3};

        case 'M':
            return {0, 1};
        case 'N':
            return {1, 4};
        case 'O':
            return {4, 5};
        case 'P':
            return {5, 0};

        case 'Q':
            return {2, 1};
        case 'R':
            return {1, 3};
        case 'S':
            return {3, 5};
        case 'T':
            return {5, 2};

        case 'U':
            return {3, 0};
        case 'V':
            return {0, 2};
        case 'W':
            return {2, 4};
        case 'X':
            return {4, 3};

        default:
            throw std::logic_error("-1");
    }
}

std::tuple <char, char> adjCorner(char corner) {
    switch (corner) {
        case 'A':
            return {'E', 'R'};
        case 'B':
            return {'Q', 'N'};
        case 'C':
            return {'M', 'J'};
        case 'D':
            return {'I', 'F'};

        case 'E':
            return {'R', 'A'};
        case 'F':
            return {'D', 'I'};
        case 'G':
            return {'L', 'U'};
        case 'H':
            return {'X', 'S'};

        case 'I':
            return {'F', 'D'};
        case 'J':
            return {'C', 'M'};
        case 'K':
            return {'P', 'V'};
        case 'L':
            return {'U', 'G'};

        case 'M':
            return {'J', 'C'};
        case 'N':
            return {'B', 'Q'};
        case 'O':
            return {'T', 'W'};
        case 'P':
            return {'V', 'K'};

        case 'Q':
            return {'N', 'B'};
        case 'R':
            return {'A', 'E'};
        case 'S':
            return {'H', 'X'};
        case 'T':
            return {'W', 'O'};

        case 'U':
            return {'G', 'L'};
        case 'V':
            return {'K', 'P'};
        case 'W':
            return {'O', 'T'};
        case 'X':
            return {'S', 'H'};

        default:
            throw std::logic_error("-1");
    }
}

std::string cornerSetupMoves(char corner) {
    switch (corner) {
        case 'A':
            return " ";
        case 'H':
            return "D' R ";
        case 'N':
            return "R' F ";
        case 'W':
            return "D' ";

        case 'D':
            return "F2 ";
        case 'L':
            return "F2 R' ";
        case 'R':
            return " ";
        case 'X':
            return "D2 ";

        case 'B':
            return "R2 ";
        case 'J':
            return "R' ";
        case 'T':
            return "R ";
        case 'V':
            return " ";

        case 'C':
            return "F2 D ";
        case 'F':
            return "F' D ";
        case 'P':
            return "R F ";
        case 'U':
            return "D ";

        case 'E':
            return " ";
        case 'I':
            return "F R' ";
        case 'M':
            return "F ";
        case 'Q':
            return "R D' ";

        case 'G':
            return "F' ";
        case 'K':
            return "F' R' ";
        case 'O':
            return "R2 F ";
        case 'S':
            return "D F' ";

        default:
            throw std::logic_error("Error in determining additional color");
    }
}

std::string cornerSwap() {
    return "R U' R' U' R U R' F' R U R' U' R' F R ";
}

std::string cornerSetupMovesBack(char corner) {
    switch (corner) {
        case 'A':
            return " ";
        case 'H':
            return "R' D ";
        case 'N':
            return "F' R ";
        case 'W':
            return "D ";

        case 'D':
            return "F2 ";
        case 'L':
            return "R F2 ";
        case 'R':
            return " ";
        case 'X':
            return "D2 ";

        case 'B':
            return "R2 ";
        case 'J':
            return "R ";
        case 'T':
            return "R' ";
        case 'V':
            return " ";

        case 'C':
            return "D' F2 ";
        case 'F':
            return "D' F ";
        case 'P':
            return "F' R' ";
        case 'U':
            return "D' ";

        case 'E':
            return " ";
        case 'I':
            return "R F' ";
        case 'M':
            return "F' ";
        case 'Q':
            return "D R' ";

        case 'G':
            return "F ";
        case 'K':
            return "R F ";
        case 'O':
            return "F' R2 ";
        case 'S':
            return "F D' ";

        default:
            throw std::logic_error("Error in determining additional color");
    }
}


std::string Cube::solve() {

    std::string move;
    std::string result;
    std::stringstream ss;

    result = orient();

    const int front = data_[0][1][1];
    const int up = data_[1][1][1];
    const int right = data_[2][1][1];
    const int left = data_[3][1][1];
    const int back = data_[4][1][1];
    const int down = data_[5][1][1];

    Cube tmpCube = *this;

    std::map <std::pair <int, int>, char > edgesLettersSolved {
        {{up,    back},  'A'},
        {{up,    left},  'D'},
        {{up,    right}, 'B'},
        {{up,    front}, 'C'},

        {{left,  up},    'E'},
        {{left,  back},  'H'},
        {{left,  front}, 'F'},
        {{left,  down},  'G'},

        {{front, up},    'I'},
        {{front, left},  'L'},
        {{front, right}, 'J'},
        {{front, down},  'K'},

        {{right, up},    'M'},
        {{right, front}, 'P'},
        {{right, back},  'N'},
        {{right, down},  'O'},

        {{back,  up},    'Q'},
        {{back,  right}, 'T'},
        {{back,  left},  'R'},
        {{back,  down},  'S'},

        {{down,  front}, 'U'},
        {{down,  left},  'X'},
        {{down,  right}, 'V'},
        {{down,  back},  'W'},
    };

    std::map <char, std::pair <int, int> > lettersToEdges {
        {'A', {data_[1][0][1], data_[4][0][1]}},
        {'D', {data_[1][1][0], data_[3][0][1]}},
        {'B', {data_[1][1][2], data_[2][0][1]}},
        {'C', {data_[1][2][1], data_[0][0][1]}},

        {'E', {data_[3][0][1], data_[1][1][0]}},
        {'H', {data_[3][1][0], data_[4][1][2]}},
        {'F', {data_[3][1][2], data_[0][1][0]}},
        {'G', {data_[3][2][1], data_[5][1][0]}},

        {'I', {data_[0][0][1], data_[1][2][1]}},
        {'L', {data_[0][1][0], data_[3][1][2]}},
        {'J', {data_[0][1][2], data_[2][1][0]}},
        {'K', {data_[0][2][1], data_[5][0][1]}},

        {'M', {data_[2][0][1], data_[1][1][2]}},
        {'P', {data_[2][1][0], data_[0][1][2]}},
        {'N', {data_[2][1][2], data_[4][1][0]}},
        {'O', {data_[2][2][1], data_[5][1][2]}},

        {'Q', {data_[4][0][1], data_[1][0][1]}},
        {'T', {data_[4][1][0], data_[2][1][2]}},
        {'R', {data_[4][1][2], data_[3][1][0]}},
        {'S', {data_[4][2][1], data_[5][2][1]}},

        {'U', {data_[5][0][1], data_[0][2][1]}},
        {'X', {data_[5][1][0], data_[3][2][1]}},
        {'V', {data_[5][1][2], data_[2][2][1]}},
        {'W', {data_[5][2][1], data_[4][2][1]}},
    };


    for (int k = 0; k < 3; ++k) {
        for (auto edge : {'A', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X'}) {
            if (lettersToEdges[edge].first != mainColor(edge) || lettersToEdges[edge].second != additionalColorEdge(edge)) {
                move = edgeSetupMoves(edge);
                result += move;
                ss = std::stringstream(move);
                tmpCube.rotateByStream(ss);

                move = edgeSwap();
                result += move;
                ss = std::stringstream(move);
                tmpCube.rotateByStream(ss);

                move = edgeSetupMovesBack(edge);
                result += move;
                ss = std::stringstream(move);
                tmpCube.rotateByStream(ss);

                std::swap(lettersToEdges[edge], lettersToEdges['B']);
                std::swap(lettersToEdges[adjEdge(edge)], lettersToEdges['M']);

                char destEdge = edgesLettersSolved[std::make_pair(lettersToEdges['B'].first, lettersToEdges['B'].second)];
                char destEdgeAdj = edgesLettersSolved[std::make_pair(lettersToEdges['B'].second, lettersToEdges['B'].first)];
                if (destEdge == 0 || destEdgeAdj == 0)
                    return "-1";
                if (destEdge != 'B' && destEdge != 'M') {
                    move = edgeSetupMoves(destEdge);
                    result += move;
                    ss = std::stringstream(move);
                    tmpCube.rotateByStream(ss);

                    move = edgeSwap();
                    result += move;
                    ss = std::stringstream(move);
                    tmpCube.rotateByStream(ss);

                    move = edgeSetupMovesBack(destEdge);
                    result += move;
                    ss = std::stringstream(move);
                    tmpCube.rotateByStream(ss);

                    std::swap(lettersToEdges[destEdge], lettersToEdges['B']);
                    std::swap(lettersToEdges[destEdgeAdj], lettersToEdges['M']);
                }
            }
        }
    }
    if (lettersToEdges['B'].first != mainColor('B') || lettersToEdges['B'].second != additionalColorEdge('B'))
        return "-1";

    *this = tmpCube;

    std::map <std::tuple <int, int, int>, char> cornersLettersSolved {
        {{up,    left,  back},  'A'},
        {{up,    back,  right}, 'B'},
        {{up,    right, front}, 'C'},
        {{up,    front, left},  'D'},

        {{left,  back,  up},    'E'},
        {{left,  up,    front}, 'F'},
        {{left,  front, down},  'G'},
        {{left,  down,  back},  'H'},

        {{front, left,  up},    'I'},
        {{front, up,    right}, 'J'},
        {{front, right, down},  'K'},
        {{front, down,  left},  'L'},

        {{right, front, up},    'M'},
        {{right, up,    back},  'N'},
        {{right, back,  down},  'O'},
        {{right, down,  front}, 'P'},

        {{back,  right, up},    'Q'},
        {{back,  up,    left},  'R'},
        {{back,  left,  down},  'S'},
        {{back,  down,  right}, 'T'},

        {{down,  left,  front}, 'U'},
        {{down,  front, right}, 'V'},
        {{down,  right, back},  'W'},
        {{down,  back,  left},  'X'},

    };

    std::map <char, std::tuple <int, int, int> > lettersToCorners {
        {'A', {data_[1][0][0], data_[3][0][0], data_[4][0][2]}},
        {'B', {data_[1][0][2], data_[4][0][0], data_[2][0][2]}},
        {'C', {data_[1][2][2], data_[2][0][0], data_[0][0][2]}},
        {'D', {data_[1][2][0], data_[0][0][0], data_[3][0][2]}},

        {'E', {data_[3][0][0], data_[4][0][2], data_[1][0][0]}},
        {'F', {data_[3][0][2], data_[1][2][0], data_[0][0][0]}},
        {'G', {data_[3][2][2], data_[0][2][0], data_[5][0][0]}},
        {'H', {data_[3][2][0], data_[5][2][0], data_[4][2][2]}},

        {'I', {data_[0][0][0], data_[3][0][2], data_[1][2][0]}},
        {'J', {data_[0][0][2], data_[1][2][2], data_[2][0][0]}},
        {'K', {data_[0][2][2], data_[2][2][0], data_[5][0][2]}},
        {'L', {data_[0][2][0], data_[5][0][0], data_[3][2][2]}},

        {'M', {data_[2][0][0], data_[0][0][2], data_[1][2][2]}},
        {'N', {data_[2][0][2], data_[1][0][2], data_[4][0][0]}},
        {'O', {data_[2][2][2], data_[4][2][0], data_[5][2][2]}},
        {'P', {data_[2][2][0], data_[5][0][2], data_[0][2][2]}},

        {'Q', {data_[4][0][0], data_[2][0][2], data_[1][0][2]}},
        {'R', {data_[4][0][2], data_[1][0][0], data_[3][0][0]}},
        {'S', {data_[4][2][2], data_[3][2][0], data_[5][2][0]}},
        {'T', {data_[4][2][0], data_[5][2][2], data_[2][2][2]}},

        {'U', {data_[5][0][0], data_[3][2][2], data_[0][2][0]}},
        {'V', {data_[5][0][2], data_[0][2][2], data_[2][2][0]}},
        {'W', {data_[5][2][2], data_[2][2][2], data_[4][2][0]}},
        {'X', {data_[5][2][0], data_[4][2][2], data_[3][2][0]}},
    };

    for (int k = 0; k < 10; ++k) {
        for (auto corner : {'B', 'C', 'D', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'S', 'T', 'U', 'V', 'W', 'X'}) {
            if (lettersToCorners[corner] != std::tuple_cat(std::make_tuple(mainColor(corner)), additionalColorCorner(corner))) {
                move = cornerSetupMoves(corner);
                result += move;
                ss = std::stringstream(move);
                tmpCube.rotateByStream(ss);

                move = cornerSwap();
                result += move;
                ss = std::stringstream(move);
                tmpCube.rotateByStream(ss);

                move = cornerSetupMovesBack(corner);
                result += move;
                ss = std::stringstream(move);
                tmpCube.rotateByStream(ss);

                std::swap(lettersToCorners[corner], lettersToCorners['E']);
                std::swap(lettersToCorners[std::get<0>(adjCorner(corner))], lettersToCorners['R']);
                std::swap(lettersToCorners[std::get<1>(adjCorner(corner))], lettersToCorners['A']);

                char destCorner = cornersLettersSolved[lettersToCorners['E']];
                char destCornerAdjLeft = cornersLettersSolved[lettersToCorners['R']];
                char destCornerAdjRight = cornersLettersSolved[lettersToCorners['A']];
                if (destCorner == 0 || destCornerAdjLeft == 0 || destCornerAdjRight == 0)
                    return "-1";
                if (destCorner != 'E' && destCorner != 'R' && destCorner != 'A') {
                    move = cornerSetupMoves(destCorner);
                    result += move;
                    ss = std::stringstream(move);
                    tmpCube.rotateByStream(ss);

                    move = cornerSwap();
                    result += move;
                    ss = std::stringstream(move);
                    tmpCube.rotateByStream(ss);

                    move = cornerSetupMovesBack(destCorner);
                    result += move;
                    ss = std::stringstream(move);
                    tmpCube.rotateByStream(ss);

                    std::swap(lettersToCorners[destCorner], lettersToCorners['E']);
                    std::swap(lettersToCorners[destCornerAdjLeft], lettersToCorners['R']);
                    std::swap(lettersToCorners[destCornerAdjRight], lettersToCorners['A']);
                }
            }
        }
    }
    if (std::get<0>(lettersToCorners['E']) != left || std::get<0>(lettersToCorners['R']) != back || std::get<0>(lettersToCorners['A']) != up)
        return "-1";

    *this = tmpCube;
    if (result.empty())
        return "Cube is already solved";
    return result;
}