//https://leetcode.com/problems/path-with-maximum-minimum-value/
//do it tomorrow


/*

class Solution:
    def maximumMinimumPath(self, matrix: List[List[int]]) -> int:
        de = ((1,0),(0,1),(-1,0),(0,-1))
        rl, cl = len(matrix), len(matrix[0])
        q = [(-matrix[0][0],0,0)]
        memo = [[1 for _ in range(cl)] for _ in range(rl)]
        while q:
            t, x, y = heapq.heappop(q)
            if x == rl - 1 and y == cl - 1:
                return -t
            for d in de:
                nx = x + d[0]
                ny = y + d[1]
                if 0 <= nx < rl and 0 <= ny < cl and memo[nx][ny]:
                    memo[nx][ny] = 0
                    heapq.heappush(q, (max(t, -matrix[nx][ny]), nx, ny)) 
*/



class Solution {
    struct Cell {
        Cell( int row, int col, int val )
        :   row( row ),
            col( col ),
            val( val )
        {}
        
        bool operator==( const Cell & rhs ) const {
            return row == rhs.row && col == rhs.col;
        }

        int row;
        int col;
        int val;
    };
    
    struct CellHash {
        size_t operator()( const Cell & cell ) const {
            return cell.row * 17 + cell.col * 31;
        }
    };
    
    struct CellCmp {
        size_t operator()( const Cell & lhs, const Cell & rhs ) const {
            return lhs.val < rhs.val; // less
        }
    };
    
    std::array< std::pair< int, int >, 4 > DIRS = { {
        {  -1,  0  },
        {   1,  0  },
        {   0, -1  },
        {   0,  1  }        
    } };
    
public:
    int maximumMinimumPath( const std::vector< std::vector< int > > & A ) {
        if( A.empty() || A.front().empty() ) {
            return -1;
        }
        
        int rows = A.size();
        int cols = A.front().size();
        
        Cell start( 0, 0, A.front().front() );
        Cell end( rows - 1, cols - 1, A.back().back() );
        std::unordered_set< Cell, CellHash > visited( { start } );
        std::priority_queue< Cell, std::vector< Cell >, CellCmp > queue;
        queue.push( start );
        
        while( !queue.empty() ) {
            Cell cell = queue.top();
            queue.pop();

            if( cell == end ) {
                return std::min( end.val, cell.val );
            }

            for( const auto & dir : DIRS ) {
                int r = cell.row + dir.first;
                int c = cell.col + dir.second;
                if( r < 0 || r >= rows || c < 0 || c >= cols ) {
                    continue;
                }

                Cell next( r, c, std::min( cell.val, A[ r ][ c ] ) );
                if( visited.find( next ) != visited.end() ) {
                    continue;
                }

                visited.insert( next );
                queue.push( next );
            }
        }
        return -1;
    }
}
                    
                    
                    
                    
                    
                    
                    
