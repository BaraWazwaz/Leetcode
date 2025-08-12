class Solution {
private:

    // data structures
    set<pair<int,int>> placable;
    vector<set<char>> rowHas, columnHas, squareHas;

    int limited(int x, int y) {
        return max({
            rowHas[x].size(), 
            columnHas[y].size(), 
            squareHas[x / 3 * 3 + y / 3].size()
        });
    }

    // recursive function
    bool recur(vector<vector<char>>& board) {

        if (placable.empty())
            return true;
        
        auto it = placable.begin();
        for (auto iter = placable.begin(); iter != placable.end(); ++iter) 
            if (
                limited(it->first, it->second) < 
                limited(iter->first, iter->second)
            )
                it = iter;
        
        auto [x, y] = *it;
        placable.erase(it);

        for (char choice = '1'; choice <= '9'; ++choice) {
            int s = x / 3 * 3 + y / 3;
            auto itr = rowHas[x].find(choice);
            auto itc = columnHas[y].find(choice);
            auto its = squareHas[s].find(choice);
            if (
                itr == rowHas[x].end() && 
                itc == columnHas[y].end() && 
                its == squareHas[s].end()
            ) {
                rowHas[x].insert(choice);
                columnHas[y].insert(choice);
                squareHas[s].insert(choice);

                board[x][y] = choice;
                if (recur(board))
                    return true;
                board[x][y] = '.';

                rowHas[x].erase(choice);
                columnHas[y].erase(choice);
                squareHas[s].erase(choice);
            }
        }

        placable.insert({x, y});
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        placable.clear();
        columnHas.assign(9, {});
        rowHas.assign(9, {});
        squareHas.assign(9, {});
        for (int x = 0; x < 9; ++x)
            for (int y = 0; y < 9; ++y) {
                if (board[x][y] == '.') {
                    placable.insert({x, y});
                } else {
                    rowHas[x].insert(board[x][y]);
                    columnHas[y].insert(board[x][y]);
                    squareHas[x / 3 * 3 + y / 3].insert(board[x][y]);
                }
            }
        recur(board);
    }
};