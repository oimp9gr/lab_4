#pragma once

using namespace std;

#include <vector>
#include <string>
#include <stdexcept>

enum class PieceType {
    KING,
    KNIGHT,
    ROOK
};

class ChessPiece {
public:
    ChessPiece(PieceType piece_type, string coordinates) : type_(piece_type) {
        const auto&[coord1, coord2] = ParseCoordinates(coordinates);
        coord1_ = coord1;
        coord2_ = coord2;
    }

    vector<string> GetPossibleMoves() {
        vector<string> possible_moves;
        switch (type_) {
            case PieceType::KING: {
                possible_moves = GetKingMoves();
                break;
            }
            case PieceType::KNIGHT: {
                possible_moves = GetKnightMoves();
                break;
            }
            case PieceType::ROOK: {
                possible_moves = GetRookMoves();
                break;
            }
        }
        return possible_moves;
    }

    bool TryMove(string coordinates) {
        try {
            Move(coordinates);
            return true;
        } catch (std::invalid_argument e) {
            return false;
        }
    }

    void Move(string coordinates) {
        for (const string& coord : GetPossibleMoves()) {
            if (coord == coordinates) {
                const auto & [coord1, coord2] = ParseCoordinates(coordinates);
                coord1_ = coord1;
                coord2_ = coord2;
                return;
            }
        }
        throw invalid_argument("");
    }

    string GetCoordinates() {
        return fromNumberCoordToLetters(coord1_, coord2_);
    }

private:
    vector<string> GetKnightMoves() {
        vector<string> moves;
        for (int i = -2; i <= 2; ++i) {
            for (int j = -2; j <= 2; ++j) {
                if ((abs(i) == 1 && abs(j) == 2) || (abs(i) == 2 && abs(j) == 1)) {
                    int coord1 = coord1_ + i;
                    int coord2 = coord2_ + j;
                    if (coord1 >= 0 && coord1 <= 7 && coord2 >= 0 && coord2 <= 7) {
                        moves.push_back(fromNumberCoordToLetters(coord1, coord2));
                    }
                }
            }
        }
        return moves;
    }

    vector<string> GetRookMoves() {
        vector<string> moves;
        for (int i: {-1, 0, 1}) {
            for (int j: {-1, 0, 1}) {
                if (abs(i) == abs(j)) continue;
                int coord1 = coord1_;
                int coord2 = coord2_;
                while (coord1 >= 0 && coord1 <= 7 && coord2 >= 0 && coord2 <= 7) {
                    coord1 += i;
                    coord2 += j;
                    if (coord1 >= 0 && coord1 <= 7 && coord2 >= 0 && coord2 <= 7) {
                        moves.push_back(fromNumberCoordToLetters(coord1, coord2));
                    }
                }
            }
        }
        return moves;
    }

    vector<string> GetKingMoves() {
        vector<string> moves;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) continue;
                int coord1 = coord1_ + i;
                int coord2 = coord2_ + j;
                if (coord1 > 7 || coord1 + i < 0 || coord2 > 7 || coord2 < 0) continue;
                moves.push_back(fromNumberCoordToLetters(coord1, coord2));
            }
        }
        return moves;
    }

    string fromNumberCoordToLetters(int coord1, int coord2) {
        return string(1, 'A' + coord1) + to_string(coord2 + 1);
    }

    std::pair<int, int> ParseCoordinates(std::string coordinates) {
        return {coordinates[0] - 'A', coordinates[1] - '1'};
    }

    PieceType type_;
    int coord1_;
    int coord2_;
};