#include <iostream>
#include <algorithm>
using namespace std;
int _count;
// Move, i.e. target coordinates (indices) on 8x8 board.
class Move
{
public:
	Move() : _x(0), _y(0)
	{}

	Move(int x, int y) : _x(x), _y(y)
	{}

	bool operator<(const Move& other)
	{
		const int arrCenterDistance[64] = { // char is sufficient as well, also unsigned
			3, 3, 3, 3, 3, 3, 3, 3,
			3, 2, 2, 2, 2, 2, 2, 3,
			3, 2, 1, 1, 1, 1, 2, 3,
			3, 2, 1, 0, 0, 1, 2, 3,
			3, 2, 1, 0, 0, 1, 2, 3,
			3, 2, 1, 1, 1, 1, 2, 3,
			3, 2, 2, 2, 2, 2, 2, 3,
			3, 3, 3, 3, 3, 3, 3, 3
		};
		int pos1 = _y * 8 + _x;
		int value = arrCenterDistance[pos1];
		int pos2 = other._y * 8 + other._x;
		int othervalue = arrCenterDistance[pos2];

		return value < othervalue;
	}

private:

	int _x;
	int _y;

	friend class Position;
};

// 8x8 board. Each square is marked either unvisited (0) or visited (1).
// Number of visited squares is kept track of.
class Position
{
public:

	// CTOR: Clear the position.
	Position()
	{
		for (int x = 0; x < 8; ++x)
			for (int y = 0; y < 8; ++y)
				_board[x][y] = 0;

		_nof_visited = 0;
	}

	// Execute a move on the position.
	void make_move(const Move& m)
	{
		_board[m._x][m._y] = 1;
		_nof_visited++;
	}

	// Undo a move.
	void undo_move(const Move& m)
	{
		_board[m._x][m._y] = 0;
		_nof_visited--;
	}

	// Move generator. Returns number of legal moves.
	int generate_moves
	(
		Move* moves,	// Array for storing legal moves 
		int x,			// Knight's current x-coord
		int y			// Knight's current y-coord
	) const
	{
		int nof_moves = 0;

		// Coordinate changes for a knight.
		const int coord_deltas[8][2] =
		{
			{-1, 2}, {-1, -2}, {1, 2}, {1, -2},
			{-2, 1}, {-2, -1}, {2, 1}, {2, -1}
		};

		// Try each (x, y) coordinate deltas.
		for (int d = 0; d < 8; ++d)
		{
			int dx = coord_deltas[d][0];
			int dy = coord_deltas[d][1];

			int new_x = x + dx;
			int new_y = y + dy;

			if (new_x < 0 || new_x > 7 || new_y < 0 || new_y > 7 || _board[new_x][new_y] == 1)
				continue;

			moves[nof_moves] = Move(new_x, new_y);
			nof_moves++;
		}

		return nof_moves;
	}

	// Find a route recursively using backtracking.
	// Return 1 if a route can be found, 0 otherwise.
	// Print each square on the found route.
	bool find_route
	(
		int x,			// Knight's current x-coord
		int y,			// Knight's current y-coord	
		int depth
	)
	{
		depth++;
		_count++;
		// Kanta tapaus 1: ratkaisu löytyi
		if (_nof_visited == 64)
			return true;

		// Selvitetään askleeet
		Move moves[8]{};
		int nof_moves = generate_moves(moves, x, y);

		if (nof_moves > 0)
		{
			sort(&moves[0], &moves[nof_moves]);
		}

		// Rekursioaskeleet
		for (int i = 0; i < nof_moves; i++)
		{
			Move m = moves[i];
			make_move(m);
			if (find_route(m._x, m._y, depth) == true)
			{
				cout << "Move " << depth << ": " << m._x << " " << m._y << "\n";
				return true;
			}

			undo_move(m);
		}

		// Rekusiotapaus: ratkaisua ei löytynyt
		return false;
	}

private:
	int _board[8][8]; // 1 = visited, 0 = not visited; [0][0] = bot-lft
	int _nof_visited;

};

int main()
{
	Position pos;
	Move move(0, 0);
	pos.make_move(move);

	bool nof_moves = pos.find_route(0, 0, 0);
	cout << _count;

	return 0;
}
