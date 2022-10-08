#pragma once
#include "Cube.h"
#include <map>
#include <tuple>

int mainColor(char sticker);

int additionalColorEdge(char sticker);
char adjEdge(char edge);
std::string edgeSetupMoves(char edge);
std::string edgeSwap();
std::string edgeSetupMovesBack(char edge);

std::tuple <int, int> additionalColorCorner(char sticker);
std::tuple <char, char> adjCorner(char corner);
std::string cornerSetupMoves(char corner);
std::string cornerSwap();
std::string cornerSetupMovesBack(char corner);

